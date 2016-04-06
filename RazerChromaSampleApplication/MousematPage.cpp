// MousematPage.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "MousematPage.h"
#include "afxdialogex.h"
#include "HealthAmmoManaDlg.h"
#include "AlertDlg.h"
#include "CooldownTimerDlg.h"


// CMousematPage dialog

IMPLEMENT_DYNAMIC(CMousematPage, CPropertyPage)

CMousematPage::CMousematPage()
    : CPropertyPage(CMousematPage::IDD)
{

}

CMousematPage::~CMousematPage()
{
}

void CMousematPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMousematPage, CPropertyPage)
    ON_BN_CLICKED(IDC_BUTTON_LOADING_ANIMATION, &CMousematPage::OnBnClickedButtonLoadingAnimation)
    ON_BN_CLICKED(IDC_BUTTON_HEALTH_AMMO_MANA, &CMousematPage::OnBnClickedButtonHealthAmmoMana)
    ON_BN_CLICKED(IDC_BUTTON_ALERTS, &CMousematPage::OnBnClickedButtonAlerts)
    ON_BN_CLICKED(IDC_BUTTON_COOLDOWN_TIMER, &CMousematPage::OnBnClickedButtonCooldownTimer)
    ON_BN_CLICKED(IDC_BUTTON_DAMAGE_TAKEN, &CMousematPage::OnBnClickedButtonDamageTaken)
END_MESSAGE_MAP()


// CMousematPage message handlers


void CMousematPage::OnBnClickedButtonLoadingAnimation()
{
    m_ChromaSDKImpl.PlayLoadingAnimation(2);
}


void CMousematPage::OnBnClickedButtonHealthAmmoMana()
{
    CHealthAmmoManaDlg dlg(this);
    dlg.DoModal();
}


void CMousematPage::OnBnClickedButtonAlerts()
{
    CAlertDlg dlg(this);
    dlg.DoModal();
}


void CMousematPage::OnBnClickedButtonCooldownTimer()
{
    CCooldownTimerDlg dlg(this);
    dlg.DoModal();
}


void CMousematPage::OnBnClickedButtonDamageTaken()
{
    m_ChromaSDKImpl.ShowDamageEffect(2);
}
