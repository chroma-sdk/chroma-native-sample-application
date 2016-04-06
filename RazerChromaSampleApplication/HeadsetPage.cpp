// HeadsetPage.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "HeadsetPage.h"
#include "afxdialogex.h"
#include "HealthAmmoManaDlg.h"
#include "AlertDlg.h"

// CHeadsetPage dialog

IMPLEMENT_DYNAMIC(CHeadsetPage, CPropertyPage)

CHeadsetPage::CHeadsetPage()
    : CPropertyPage(CHeadsetPage::IDD)
{

}

CHeadsetPage::~CHeadsetPage()
{
}

void CHeadsetPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHeadsetPage, CPropertyPage)
    ON_BN_CLICKED(IDC_BUTTON_HEALTH_AMMO_MANA, &CHeadsetPage::OnBnClickedButtonHealthAmmoMana)
    ON_BN_CLICKED(IDC_BUTTON_ALERTS, &CHeadsetPage::OnBnClickedButtonAlerts)
    ON_BN_CLICKED(IDC_BUTTON_DAMAGE_TAKEN, &CHeadsetPage::OnBnClickedButtonDamageTaken)
END_MESSAGE_MAP()


// CHeadsetPage message handlers


void CHeadsetPage::OnBnClickedButtonHealthAmmoMana()
{
    CHealthAmmoManaDlg dlg(this);
    dlg.DoModal();
}


void CHeadsetPage::OnBnClickedButtonAlerts()
{
    CAlertDlg dlg(this);
    dlg.DoModal();
}


void CHeadsetPage::OnBnClickedButtonDamageTaken()
{
    m_ChromaSDKImpl.ShowColor(4, RED);
    Sleep(50);
    m_ChromaSDKImpl.ResetEffects(4);
}
