// AlertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "AlertDlg.h"
#include "afxdialogex.h"


// CAlertDlg dialog

IMPLEMENT_DYNAMIC(CAlertDlg, CDialogEx)

CAlertDlg::CAlertDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CAlertDlg::IDD, pParent)
{
    m_pParent = pParent;
    m_DeviceType = 0;
}

CAlertDlg::~CAlertDlg()
{
}

void CAlertDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BOOL CAlertDlg::OnInitDialog()
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

    m_ChromaSDKImpl.ResetEffects(m_DeviceType);

    return Result;
}

BEGIN_MESSAGE_MAP(CAlertDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_POSITIVE_ALERT, &CAlertDlg::OnBnClickedButtonPositiveAlert)
    ON_BN_CLICKED(IDC_BUTTON_NEGATIVE_ALERT, &CAlertDlg::OnBnClickedButtonNegativeAlert)
END_MESSAGE_MAP()


// CAlertDlg message handlers


void CAlertDlg::OnBnClickedButtonPositiveAlert()
{
    m_ChromaSDKImpl.ShowAlert(m_DeviceType, GREEN);
}


void CAlertDlg::OnBnClickedButtonNegativeAlert()
{
    m_ChromaSDKImpl.ShowAlert(m_DeviceType, RED);
}

