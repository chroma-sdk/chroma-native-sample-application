// AmbientEffectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "AmbientEffectDlg.h"
#include "afxdialogex.h"

HANDLE g_hThread = NULL;

DWORD WINAPI _CreateAmbientFx1(LPVOID lpParameter)
{
    UINT DeiveType = (UINT)lpParameter;

    CChromaSDKImpl* pChromaSDK = (CChromaSDKImpl*)lpParameter;

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
        if(DeiveType == 1)
        {
            StretchBlt(hMemoryDC, 0, 0, ChromaSDK::Keyboard::MAX_COLUMN, ChromaSDK::Keyboard::MAX_ROW, 
                    hScreenDC, 0, height, width, -height, 
                    SRCCOPY);
        }
        else if(DeiveType == 5)
        {
            StretchBlt(hMemoryDC, 0, 0, ChromaSDK::Keypad::MAX_COLUMN, ChromaSDK::Keypad::MAX_ROW, 
                    hScreenDC, 0, height, width, -height, 
                    SRCCOPY);
        }

        // Select the bitmap into the device context.
        hBitmap = (HBITMAP)SelectObject(hMemoryDC, hOldBitmap);

        // Display the image
        pChromaSDK->ShowBitmap(DeiveType, hBitmap);

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
    else if(_tcsicmp(PageInfo.pszTitle, _T("Mousemats")) == 0)
    {
        m_DeviceType = 2;
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

    m_ChromaSDKImpl.ResetEffects(m_DeviceType);
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

    m_ChromaSDKImpl.ResetEffects(m_DeviceType);
}
