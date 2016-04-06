// MicePage.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "MicePage.h"
#include "afxdialogex.h"
#include "HealthAmmoManaDlg.h"
#include "AlertDlg.h"


// CMicePage dialog

IMPLEMENT_DYNAMIC(CMicePage, CPropertyPage)

CMicePage::CMicePage()
    : CPropertyPage(CMicePage::IDD)
{

}

CMicePage::~CMicePage()
{
}

void CMicePage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMicePage, CPropertyPage)
    ON_BN_CLICKED(IDC_BUTTON_LOADING_ANIMATION, &CMicePage::OnBnClickedButtonLoadingAnimation)
    ON_BN_CLICKED(IDC_BUTTON_HEALTH_AMMO_MANA, &CMicePage::OnBnClickedButtonHealthAmmoMana)
    ON_BN_CLICKED(IDC_BUTTON_ALERTS, &CMicePage::OnBnClickedButtonAlerts)
    ON_BN_CLICKED(IDC_BUTTON_DAMAGE_TAKEN, &CMicePage::OnBnClickedButtonDamageTaken)
END_MESSAGE_MAP()


// CMicePage message handlers


void CMicePage::OnBnClickedButtonLoadingAnimation()
{
    m_ChromaSDKImpl.PlayLoadingAnimation(3);
}


void CMicePage::OnBnClickedButtonHealthAmmoMana()
{
    CHealthAmmoManaDlg dlg(this);
    dlg.DoModal();
}


void CMicePage::OnBnClickedButtonAlerts()
{
    CAlertDlg dlg(this);
    dlg.DoModal();
}


void CMicePage::OnBnClickedButtonDamageTaken()
{
    m_ChromaSDKImpl.ShowDamageEffect(3);
}
