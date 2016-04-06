// TutorialDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "TutorialDlg.h"
#include "afxdialogex.h"


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
    KillTimer(1);

    UINT VKeys = {0x57};    // W
    m_ChromaSDKImpl.ShowKeys(m_DeviceType, 1, &VKeys, WHITE);

    GetDlgItem(IDC_STATIC_TUTORIAL)->SetWindowTextW(_T("Press 'A' to stafe left"));
    SetTimer(2, 500, NULL);
}

void CTutorialDlg::OnAKeyUp()
{
    KillTimer(2);

    UINT VKeys [2] = { {0x57}, {0x41} };    // W, A
    m_ChromaSDKImpl.ShowKeys(m_DeviceType, 2, VKeys, WHITE);

    GetDlgItem(IDC_STATIC_TUTORIAL)->SetWindowTextW(_T("Press 'S' to move backwards"));
    SetTimer(3, 500, NULL);
}

void CTutorialDlg::OnSKeyUp()
{
    KillTimer(3);

    UINT VKeys [3] = { {0x41}, {0x57}, {0x53} };    // W, A, S
    m_ChromaSDKImpl.ShowKeys(m_DeviceType, 3, VKeys, WHITE);

    GetDlgItem(IDC_STATIC_TUTORIAL)->SetWindowTextW(_T("Press 'D' to strafe right"));
    SetTimer(4, 500, NULL);
}

void CTutorialDlg::OnDKeyUp()
{
    KillTimer(4);

    UINT VKeys [4] = { {0x41}, {0x57}, {0x53}, {0x44} };    // W, A, S, D
    m_ChromaSDKImpl.ShowKeys(m_DeviceType, 4, VKeys, WHITE);

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
        else if(_tcsicmp(PageInfo.pszTitle, _T("Keypads")) == 0)
        {
            m_DeviceType = 5;
        }

        SetTimer(1, 500, NULL);
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
    ON_WM_TIMER()
    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CTutorialDlg message handlers

void CTutorialDlg::OnTimer(UINT_PTR nIDEvent)
{
    CPropertyPage* pPage = (CPropertyPage*)m_pParent;
    PROPSHEETPAGE PageInfo = pPage->GetPSP();

    if(nIDEvent == 1)
    {
        UINT VKey = 0x57;       // W
        static BOOL Blink = TRUE;
        if(Blink == TRUE)
        {
            m_ChromaSDKImpl.ShowKeys(m_DeviceType, 1, &VKey, WHITE);
            Blink = FALSE;
        }
        else
        {
            m_ChromaSDKImpl.ShowKeys(m_DeviceType, 0, NULL, WHITE);
            Blink = TRUE;
        }
    }
    else if(nIDEvent == 2)
    {
        UINT VKeys [2] = { {0x57}, {0x41} };    // W, A
        static BOOL Blink = TRUE;
        if(Blink == TRUE)
        {
            m_ChromaSDKImpl.ShowKeys(m_DeviceType, 2, VKeys, WHITE);
            Blink = FALSE;
        }
        else
        {
            m_ChromaSDKImpl.ShowKeys(m_DeviceType, 1, VKeys, WHITE);
            Blink = TRUE;
        }
    }
    else if(nIDEvent == 3)
    {
        UINT VKeys [3] = { {0x41}, {0x57}, {0x53} };    // W, A, S
        static BOOL Blink = TRUE;
        if(Blink == TRUE)
        {
            m_ChromaSDKImpl.ShowKeys(m_DeviceType, 3, VKeys, WHITE);
            Blink = FALSE;
        }
        else
        {
            m_ChromaSDKImpl.ShowKeys(m_DeviceType, 2, VKeys, WHITE);
            Blink = TRUE;
        }
    }
    else if(nIDEvent == 4)
    {
        UINT VKeys [4] = { {0x41}, {0x57}, {0x53}, {0x44} };    // W, A, S, D
        static BOOL Blink = TRUE;
        if(Blink == TRUE)
        {
            m_ChromaSDKImpl.ShowKeys(m_DeviceType, 4, VKeys, WHITE);
            Blink = FALSE;
        }
        else
        {
            m_ChromaSDKImpl.ShowKeys(m_DeviceType, 3, VKeys, WHITE);
            Blink = TRUE;
        }
    }

    CDialogEx::OnTimer(nIDEvent);
}


void CTutorialDlg::OnDestroy()
{
    CDialogEx::OnDestroy();

    KillTimer(1);
    KillTimer(2);
    KillTimer(3);
    KillTimer(4);

    m_ChromaSDKImpl.ResetEffects(m_DeviceType);
}
