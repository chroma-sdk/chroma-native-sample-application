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
END_MESSAGE_MAP()


// CCooldownTimerDlg message handlers

void CCooldownTimerDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    UpdateData();

    m_ChromaSDKImpl.ShowGauge(m_DeviceType, m_Timer.GetPos());

    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
