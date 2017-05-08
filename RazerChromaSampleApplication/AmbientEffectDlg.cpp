// AmbientEffectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "AmbientEffectDlg.h"
#include "afxdialogex.h"

HANDLE g_hThread = NULL;

DWORD WINAPI _CreateAmbientFx1(LPVOID lpParameter)
{
    UINT DeviceType = (UINT)lpParameter;

    // Get the device context of the screen
    HDC hScreenDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
    // and a device context to put it in
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);

    // Get width and height of primary display
    int width = GetDeviceCaps(hScreenDC, HORZRES);
    int height = GetDeviceCaps(hScreenDC, VERTRES);

    // Capture an image from the primary display
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);

    while(TRUE)
    {
        HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemoryDC, hBitmap);

        // Specify the resize mode.
        ::SetStretchBltMode(hMemoryDC, HALFTONE);

        // Copy and resize the image to a memory buffer
        if(DeviceType == 1)
        {
            StretchBlt(hMemoryDC, 0, 0, ChromaSDK::Keyboard::MAX_COLUMN, ChromaSDK::Keyboard::MAX_ROW, 
                    hScreenDC, 0, height, width, -height, 
                    SRCCOPY);
        }
        else if(DeviceType == 5)
        {
            StretchBlt(hMemoryDC, 0, 0, ChromaSDK::Keypad::MAX_COLUMN, ChromaSDK::Keypad::MAX_ROW, 
                    hScreenDC, 0, height, width, -height, 
                    SRCCOPY);
        }

        BITMAP bm;
        ::GetObject(hBitmap, sizeof(bm), &bm);

        BITMAPINFOHEADER bmi = {0};
        bmi.biSize = sizeof(BITMAPINFOHEADER);
        bmi.biPlanes = bm.bmPlanes;
        bmi.biBitCount = bm.bmBitsPixel;

        if(DeviceType == 1)
        {
            bmi.biWidth = ChromaSDK::Keyboard::MAX_COLUMN;
            bmi.biHeight = ChromaSDK::Keyboard::MAX_ROW;
        }
        else if(DeviceType == 5)
        {
            bmi.biWidth = ChromaSDK::Keypad::MAX_COLUMN;
            bmi.biHeight = ChromaSDK::Keypad::MAX_ROW;
        }

        bmi.biCompression = BI_RGB;
        bmi.biSizeImage = 0;

        BYTE *pBits = NULL;
        pBits = (BYTE*)malloc(4 * bmi.biWidth * bmi.biHeight);
        ZeroMemory(pBits, (4 * bmi.biWidth * bmi.biHeight));

        if(DeviceType == 1)
        {
            ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Effect = {};
            for(UINT i=0; i<ChromaSDK::Keyboard::MAX_ROW; i++)
            {
                // Get ths RGB bits for each row
                ::GetDIBits(hMemoryDC, hBitmap, i, 1, pBits, (BITMAPINFO*)&bmi, DIB_RGB_COLORS);

                COLORREF *pColor = (COLORREF*)pBits;

                for(UINT j=0; j<ChromaSDK::Keyboard::MAX_COLUMN; j++)
                {
                    // Fill up the array
                    Effect.Color[i][j] = RGB(GetBValue(*pColor), GetGValue(*pColor), GetRValue(*pColor));
                    pColor++;
                }
            }

            // Set the effect
            g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, NULL);
        }
        else if(DeviceType == 5)
        {
            ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};
            for(UINT i=0; i<ChromaSDK::Keypad::MAX_ROW; i++)
            {
                // Get ths RGB bits for each row
                ::GetDIBits(hMemoryDC, hBitmap, i, 1, pBits, (BITMAPINFO*)&bmi, DIB_RGB_COLORS);

                COLORREF *pColor = (COLORREF*)pBits;

                for(UINT j=0; j<ChromaSDK::Keypad::MAX_COLUMN; j++)
                {
                    // Fill up the array
                    Effect.Color[i][j] = RGB(GetBValue(*pColor), GetGValue(*pColor), GetRValue(*pColor));
                    pColor++;
                }
            }

            // Set the effect
            g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, NULL);
        }

        free(pBits);

        Sleep(5);
    }

    // Clean up
    DeleteDC(hMemoryDC);
    DeleteDC(hScreenDC);

    return 0;
}

// CAmbientEffectDlg dialog

IMPLEMENT_DYNAMIC(CAmbientEffectDlg, CDialogEx)

CAmbientEffectDlg::CAmbientEffectDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CAmbientEffectDlg::IDD, pParent)
{
    m_pParent = pParent;
    m_DeviceType = 0;
}

CAmbientEffectDlg::~CAmbientEffectDlg()
{
}

void CAmbientEffectDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BOOL CAmbientEffectDlg::OnInitDialog()
{
    BOOL Result = CDialogEx::OnInitDialog();

    CPropertyPage* pPage = (CPropertyPage*)m_pParent;
    PROPSHEETPAGE PageInfo = pPage->GetPSP();

    if(_tcsicmp(PageInfo.pszTitle, _T("Keyboards")) == 0)
    {
        m_DeviceType = 1;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Keypads")) == 0)
    {
        m_DeviceType = 5;
    }

    return Result;
}

BEGIN_MESSAGE_MAP(CAmbientEffectDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_AMBIENT_EFFECT_START, &CAmbientEffectDlg::OnBnClickedButtonAmbientEffectStart)
    ON_BN_CLICKED(IDC_BUTTON_AMBIENT_EFFECT_STOP, &CAmbientEffectDlg::OnBnClickedButtonAmbientEffectStop)
    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CAmbientEffectDlg message handlers


void CAmbientEffectDlg::OnBnClickedButtonAmbientEffectStart()
{
    if(g_hThread == NULL)
    {
        g_hThread = CreateThread(NULL, 0, _CreateAmbientFx1, (LPVOID)m_DeviceType, 0, NULL);
    }
    else
    {
        ResumeThread(g_hThread);
    }
}


void CAmbientEffectDlg::OnBnClickedButtonAmbientEffectStop()
{
    if(g_hThread != NULL)
    {
        SuspendThread(g_hThread);
    }

    switch(m_DeviceType)
    {
    case 1: // Keyboard
        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_NONE, NULL);
        break;
    case 2: // Mousemats
        g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_NONE, NULL);
        break;
    case 3: // Mice
        g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_NONE, NULL);
        break;
    case 4: // Headsets
        g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_NONE, NULL);
        break;
    case 5: // Keypads
        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_NONE, NULL);
        break;
    }
}

void CAmbientEffectDlg::OnDestroy()
{
    CDialogEx::OnDestroy();

    if(g_hThread)
    {
        TerminateThread(g_hThread, 0);

        CloseHandle(g_hThread);
        g_hThread = NULL;
    }

    switch(m_DeviceType)
    {
    case 1: // Keyboard
        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_NONE, NULL);
        break;
    case 2: // Mousemats
        g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_NONE, NULL);
        break;
    case 3: // Mice
        g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_NONE, NULL);
        break;
    case 4: // Headsets
        g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_NONE, NULL);
        break;
    case 5: // Keypads
        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_NONE, NULL);
        break;
    }
}
