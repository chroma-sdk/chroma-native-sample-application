// TutorialDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "TutorialDlg.h"
#include "afxdialogex.h"

using namespace ChromaSDK;

RZEFFECTID g_EffectId_W = GUID_NULL;
RZEFFECTID g_EffectId_A = GUID_NULL;
RZEFFECTID g_EffectId_S = GUID_NULL;
RZEFFECTID g_EffectId_D = GUID_NULL;

// CTutorialDlg dialog

IMPLEMENT_DYNAMIC(CTutorialDlg, CDialogEx)

CTutorialDlg::CTutorialDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CTutorialDlg::IDD, pParent)
{
    m_pParent = pParent;
    m_DeviceType = 0;
}

CTutorialDlg::~CTutorialDlg()
{
}

void CTutorialDlg::OnWKeyUp()
{
    g_ChromaSDKImpl.StopEffectImpl(g_EffectId_W);

    RZEFFECTID Frame1 = GUID_NULL;
    RZEFFECTID Frame2 = GUID_NULL;

    g_ChromaSDKImpl.CreateEffectGroup(&g_EffectId_A, TRUE);

    if(m_DeviceType == 1)
    {
        ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE CustomKey = {};

        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_W)][LOBYTE(ChromaSDK::Keyboard::RZKEY_W)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_A)][LOBYTE(ChromaSDK::Keyboard::RZKEY_A)] = 0x01000000 | BLACK;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &CustomKey, &Frame1);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_A, Frame1, 500);

        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_W)][LOBYTE(ChromaSDK::Keyboard::RZKEY_W)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_A)][LOBYTE(ChromaSDK::Keyboard::RZKEY_A)] = 0x01000000 | WHITE;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &CustomKey, &Frame2);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_A, Frame2, 500);
    }
    else if(m_DeviceType == 5)
    {
        ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE CustomKey = {};

        CustomKey.Color[1][2] = WHITE;
        CustomKey.Color[2][1] = BLACK;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &CustomKey, &Frame1);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_A, Frame1, 500);

        CustomKey.Color[1][2] = WHITE;
        CustomKey.Color[2][1] = WHITE;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &CustomKey, &Frame2);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_A, Frame2, 500);
    }

    g_ChromaSDKImpl.SetEffectImpl(g_EffectId_A);

    GetDlgItem(IDC_STATIC_TUTORIAL)->SetWindowTextW(_T("Press 'A' to stafe left"));

}

void CTutorialDlg::OnAKeyUp()
{
    g_ChromaSDKImpl.StopEffectImpl(g_EffectId_A);

    RZEFFECTID Frame1 = GUID_NULL;
    RZEFFECTID Frame2 = GUID_NULL;

    g_ChromaSDKImpl.CreateEffectGroup(&g_EffectId_S, TRUE);

    if(m_DeviceType == 1)
    {
        ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE CustomKey = {};

        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_W)][LOBYTE(ChromaSDK::Keyboard::RZKEY_W)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_A)][LOBYTE(ChromaSDK::Keyboard::RZKEY_A)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_S)][LOBYTE(ChromaSDK::Keyboard::RZKEY_S)] = 0x01000000 | BLACK;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &CustomKey, &Frame1);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_S, Frame1, 500);

        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_W)][LOBYTE(ChromaSDK::Keyboard::RZKEY_W)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_A)][LOBYTE(ChromaSDK::Keyboard::RZKEY_A)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_S)][LOBYTE(ChromaSDK::Keyboard::RZKEY_S)] = 0x01000000 | WHITE;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &CustomKey, &Frame2);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_S, Frame2, 500);
    }
    else if(m_DeviceType == 5)
    {
        ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE CustomKey = {};

        CustomKey.Color[1][2] = WHITE;
        CustomKey.Color[2][1] = WHITE;
        CustomKey.Color[2][2] = BLACK;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &CustomKey, &Frame1);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_S, Frame1, 500);

        CustomKey.Color[1][2] = WHITE;
        CustomKey.Color[2][1] = WHITE;
        CustomKey.Color[2][2] = WHITE;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &CustomKey, &Frame2);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_S, Frame2, 500);
    }

    g_ChromaSDKImpl.SetEffectImpl(g_EffectId_S);

    GetDlgItem(IDC_STATIC_TUTORIAL)->SetWindowTextW(_T("Press 'S' to move backwards"));
}

void CTutorialDlg::OnSKeyUp()
{
    g_ChromaSDKImpl.StopEffectImpl(g_EffectId_S);

    RZEFFECTID Frame1 = GUID_NULL;
    RZEFFECTID Frame2 = GUID_NULL;

    g_ChromaSDKImpl.CreateEffectGroup(&g_EffectId_D, TRUE);

    if(m_DeviceType == 1)
    {
        ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE CustomKey = {};

        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_W)][LOBYTE(ChromaSDK::Keyboard::RZKEY_W)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_A)][LOBYTE(ChromaSDK::Keyboard::RZKEY_A)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_S)][LOBYTE(ChromaSDK::Keyboard::RZKEY_S)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_D)][LOBYTE(ChromaSDK::Keyboard::RZKEY_D)] = 0x01000000 | BLACK;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &CustomKey, &Frame1);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_D, Frame1, 500);

        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_W)][LOBYTE(ChromaSDK::Keyboard::RZKEY_W)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_A)][LOBYTE(ChromaSDK::Keyboard::RZKEY_A)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_S)][LOBYTE(ChromaSDK::Keyboard::RZKEY_S)] = 0x01000000 | WHITE;
        CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_D)][LOBYTE(ChromaSDK::Keyboard::RZKEY_D)] = 0x01000000 | WHITE;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &CustomKey, &Frame2);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_D, Frame2, 500);
    }
    else if(m_DeviceType == 5)
    {
        ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE CustomKey = {};

        CustomKey.Color[1][2] = WHITE;
        CustomKey.Color[2][1] = WHITE;
        CustomKey.Color[2][2] = WHITE;
        CustomKey.Color[2][3] = BLACK;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &CustomKey, &Frame1);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_D, Frame1, 500);

        CustomKey.Color[1][2] = WHITE;
        CustomKey.Color[2][1] = WHITE;
        CustomKey.Color[2][2] = WHITE;
        CustomKey.Color[2][3] = WHITE;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &CustomKey, &Frame2);

        g_ChromaSDKImpl.AddToGroup(g_EffectId_D, Frame2, 500);
    }

    g_ChromaSDKImpl.SetEffectImpl(g_EffectId_D);

    GetDlgItem(IDC_STATIC_TUTORIAL)->SetWindowTextW(_T("Press 'D' to strafe right"));
}

void CTutorialDlg::OnDKeyUp()
{
    g_ChromaSDKImpl.StopEffectImpl(g_EffectId_D);

    GetDlgItem(IDC_STATIC_TUTORIAL)->SetWindowTextW(_T("Ok! You are ready to go!"));
}

void CTutorialDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BOOL CTutorialDlg::OnInitDialog()
{
    BOOL Result = CDialogEx::OnInitDialog();
    if(Result == TRUE)
    {
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
        else if(_tcsicmp(PageInfo.pszTitle, _T("Mice")) == 0)
        {
            m_DeviceType = 3;
        }
        else if(_tcsicmp(PageInfo.pszTitle, _T("Headsets")) == 0)
        {
            m_DeviceType = 4;
        }
        else if(_tcsicmp(PageInfo.pszTitle, _T("Keypads")) == 0)
        {
            m_DeviceType = 5;
        }

        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;

        g_ChromaSDKImpl.CreateEffectGroup(&g_EffectId_W, TRUE);

        if(m_DeviceType == 1)
        {
            ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE CustomKey = {};

            CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_W)][LOBYTE(ChromaSDK::Keyboard::RZKEY_W)] = 0x01000000 | BLACK;

            g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &CustomKey, &Frame1);

            g_ChromaSDKImpl.AddToGroup(g_EffectId_W, Frame1, 500);

            CustomKey.Key[HIBYTE(ChromaSDK::Keyboard::RZKEY_W)][LOBYTE(ChromaSDK::Keyboard::RZKEY_W)] = 0x01000000 | WHITE;

            g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &CustomKey, &Frame2);

            g_ChromaSDKImpl.AddToGroup(g_EffectId_W, Frame2, 500);
        }
        else if(m_DeviceType == 5)
        {
            ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE CustomKey = {};

            CustomKey.Color[1][2] = BLACK;

            g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &CustomKey, &Frame1);

            g_ChromaSDKImpl.AddToGroup(g_EffectId_W, Frame1, 500);

            CustomKey.Color[1][2] = WHITE;

            g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &CustomKey, &Frame2);

            g_ChromaSDKImpl.AddToGroup(g_EffectId_W, Frame2, 500);
        }

        g_ChromaSDKImpl.SetEffectImpl(g_EffectId_W);
    }

    return Result;
}

BOOL CTutorialDlg::PreTranslateMessage(MSG* pMsg)
{
    if(pMsg->message == WM_KEYUP)
    {
        if(pMsg->wParam == 0x57)
        {
            OnWKeyUp();
        }
        else if(pMsg->wParam == 0x41)
        {
            OnAKeyUp();
        }
        else if(pMsg->wParam == 0x53)
        {
            OnSKeyUp();
        }
        else if(pMsg->wParam == 0x44)
        {
            OnDKeyUp();
        }
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}


BEGIN_MESSAGE_MAP(CTutorialDlg, CDialogEx)
    ON_WM_DESTROY()
END_MESSAGE_MAP()

void CTutorialDlg::OnDestroy()
{
    CDialogEx::OnDestroy();

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
