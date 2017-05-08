// CooldownTimerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "CooldownTimerDlg.h"
#include "afxdialogex.h"


// CCooldownTimerDlg dialog

IMPLEMENT_DYNAMIC(CCooldownTimerDlg, CDialogEx)

CCooldownTimerDlg::CCooldownTimerDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CCooldownTimerDlg::IDD, pParent)
{
    m_pParent = pParent;
    m_DeviceType = 0;
}

CCooldownTimerDlg::~CCooldownTimerDlg()
{
}

void CCooldownTimerDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_COOLDOWN, m_Timer);
}

BOOL CCooldownTimerDlg::OnInitDialog()
{
    BOOL Result = CDialogEx::OnInitDialog();

    CPropertyPage* pPage = (CPropertyPage*)m_pParent;
    PROPSHEETPAGE PageInfo = pPage->GetPSP();

    UINT DeviceTab = 0;
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
    else if(_tcsicmp(PageInfo.pszTitle, _T("Keypads")) == 0)
    {
        m_DeviceType = 5;
    }

    m_Timer.SetRange(0, 100);

    return Result;
}

BEGIN_MESSAGE_MAP(CCooldownTimerDlg, CDialogEx)
    ON_WM_HSCROLL()

    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CCooldownTimerDlg message handlers

void CCooldownTimerDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    UpdateData();

    //m_ChromaSDKImpl.ShowGauge(m_DeviceType, m_Timer.GetPos());
    switch(m_DeviceType)
    {
    case 1: // Keyboards
        {
            UINT Gauge = UINT(m_Timer.GetPos()/100.0 * 18.0);

            ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Effect = {};
            switch(Gauge)
            {
            case 0: 
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 1:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 2:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 3:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 4:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 5:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 6:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 7:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = BLACK;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 8:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = BLACK;
                break;
            case 9:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 10:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 11:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 12:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 13:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 14:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 15:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 16:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = GREY;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 17:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = GREY;
                break;
            case 18:
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD8)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD9)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD6)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD3)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD2)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD1)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD4)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD7)] = YELLOW;
                Effect.Color[HIBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)][LOBYTE(ChromaSDK::Keyboard::RZKEY_NUMPAD5)] = YELLOW;
                break;
            }

            g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, NULL);
        }
        break;
    case 2: // Mousemats
        {
            UINT Gauge = UINT(m_Timer.GetPos()/100.0 * 15.0);

            ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE Effect = {};

            for(UINT i=0; i<Gauge; i++)
            {
                Effect.Color[i] = RED;
            }

            g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_CUSTOM, &Effect, NULL);
        }
        break;
    case 5: // Keypads
        {
            ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

            UINT Gauge = UINT(m_Timer.GetPos()/100.0 * 14.0);

            switch(Gauge)
            {
            case 1: 
                Effect.Color[0][0] = YELLOW; 
                break;
            case 2: 
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                break;
            case 3:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                break;
            case 4:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                break;
            case 5:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                break;
            case 6:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                break;
            case 7:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                Effect.Color[2][4] = YELLOW;
                break;
            case 8:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                Effect.Color[2][4] = YELLOW;
                Effect.Color[3][4] = YELLOW;
                break;
            case 9:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                Effect.Color[2][4] = YELLOW;
                Effect.Color[3][4] = YELLOW;
                Effect.Color[3][3] = YELLOW;
                break;
            case 10:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                Effect.Color[2][4] = YELLOW;
                Effect.Color[3][4] = YELLOW;
                Effect.Color[3][3] = YELLOW;
                Effect.Color[3][2] = YELLOW;
                break;
            case 11:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                Effect.Color[2][4] = YELLOW;
                Effect.Color[3][4] = YELLOW;
                Effect.Color[3][3] = YELLOW;
                Effect.Color[3][2] = YELLOW;
                Effect.Color[3][1] = YELLOW;
                break;
            case 12:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                Effect.Color[2][4] = YELLOW;
                Effect.Color[3][4] = YELLOW;
                Effect.Color[3][3] = YELLOW;
                Effect.Color[3][2] = YELLOW;
                Effect.Color[3][1] = YELLOW;
                Effect.Color[3][0] = YELLOW;
                break;
            case 13:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                Effect.Color[2][4] = YELLOW;
                Effect.Color[3][4] = YELLOW;
                Effect.Color[3][3] = YELLOW;
                Effect.Color[3][2] = YELLOW;
                Effect.Color[3][1] = YELLOW;
                Effect.Color[3][0] = YELLOW;
                Effect.Color[2][0] = YELLOW;
                break;
            case 14:
                Effect.Color[0][0] = YELLOW; 
                Effect.Color[0][1] = YELLOW;
                Effect.Color[0][2] = YELLOW;
                Effect.Color[0][3] = YELLOW;
                Effect.Color[0][4] = YELLOW;
                Effect.Color[1][4] = YELLOW;
                Effect.Color[2][4] = YELLOW;
                Effect.Color[3][4] = YELLOW;
                Effect.Color[3][3] = YELLOW;
                Effect.Color[3][2] = YELLOW;
                Effect.Color[3][1] = YELLOW;
                Effect.Color[3][0] = YELLOW;
                Effect.Color[2][0] = YELLOW;
                Effect.Color[1][0] = YELLOW;
                break;
            }

            g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, NULL);
        }
        break;
    }

    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CCooldownTimerDlg::OnDestroy()
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
