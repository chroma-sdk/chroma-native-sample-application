// KeypadPage.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "KeypadPage.h"
#include "afxdialogex.h"
#include "TutorialDlg.h"
#include "HealthAmmoManaDlg.h"
#include "AlertDlg.h"
#include "CooldownTimerDlg.h"
#include "AmbientEffectDlg.h"


#define ORBWEAVER_DEVICE        1
#define TARTARUS_DEVICE         2


// CKeypadPage dialog

IMPLEMENT_DYNAMIC(CKeypadPage, CPropertyPage)

CKeypadPage::CKeypadPage()
    : CPropertyPage(CKeypadPage::IDD)
{

}

CKeypadPage::~CKeypadPage()
{
}

void CKeypadPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
}

BOOL CKeypadPage::OnInitDialog()
{
    BOOL Result = CPropertyPage::OnInitDialog();

    CheckDlgButton(IDC_RADIO_ORBWEAVER, BST_CHECKED);

    return Result;
}

BEGIN_MESSAGE_MAP(CKeypadPage, CPropertyPage)
    ON_BN_CLICKED(IDC_BUTTON_LOADING_ANIMATION, &CKeypadPage::OnBnClickedButtonLoadingAnimation)
    ON_BN_CLICKED(IDC_BUTTON_TUTORIAL, &CKeypadPage::OnBnClickedButtonTutorial)
    ON_BN_CLICKED(IDC_BUTTON_ACTIVE_KEYS, &CKeypadPage::OnBnClickedButtonActiveKeys)
    ON_BN_CLICKED(IDC_BUTTON_HEALTH_AMMO_MANA, &CKeypadPage::OnBnClickedButtonHealthAmmoMana)
    ON_BN_CLICKED(IDC_BUTTON_ALERTS, &CKeypadPage::OnBnClickedButtonAlerts)
    ON_BN_CLICKED(IDC_BUTTON_COOLDOWN_TIMER, &CKeypadPage::OnBnClickedButtonCooldownTimer)
    ON_BN_CLICKED(IDC_BUTTON_AMBIENT_EFFECT, &CKeypadPage::OnBnClickedButtonAmbientEffect)
    ON_BN_CLICKED(IDC_BUTTON_DAMAGE_TAKEN, &CKeypadPage::OnBnClickedButtonDamageTaken)
    ON_BN_CLICKED(IDC_RADIO_ORBWEAVER, &CKeypadPage::OnBnClickedRadioOrbweaver)
    ON_BN_CLICKED(IDC_RADIO_TARTARUS, &CKeypadPage::OnBnClickedRadioTartarus)
END_MESSAGE_MAP()

void CKeypadPage::ShowButtons(UINT DeviceType)
{
    static CRect TutorialButtonRect;
    if(TutorialButtonRect.IsRectEmpty())
    {
        GetDlgItem(IDC_BUTTON_TUTORIAL)->GetWindowRect(TutorialButtonRect);
        ScreenToClient(TutorialButtonRect);
    }

    static CRect ActiveKeysButtonRect;
    if(ActiveKeysButtonRect.IsRectEmpty())
    {
        GetDlgItem(IDC_BUTTON_ACTIVE_KEYS)->GetWindowRect(ActiveKeysButtonRect);
        ScreenToClient(ActiveKeysButtonRect);
    }

    static CRect AlertsButtonRect;
    if(AlertsButtonRect.IsRectEmpty())
    {
        GetDlgItem(IDC_BUTTON_ALERTS)->GetWindowRect(AlertsButtonRect);
        ScreenToClient(AlertsButtonRect);
    }

    static CRect DamageTakenButtonRect;
    if(DamageTakenButtonRect.IsRectEmpty())
    {
        GetDlgItem(IDC_BUTTON_DAMAGE_TAKEN)->GetWindowRect(DamageTakenButtonRect);
        ScreenToClient(DamageTakenButtonRect);
    }

    if(DeviceType == ORBWEAVER_DEVICE)
    {
        GetDlgItem(IDC_BUTTON_TUTORIAL)->ShowWindow(TRUE);
        GetDlgItem(IDC_BUTTON_ACTIVE_KEYS)->ShowWindow(TRUE);
        GetDlgItem(IDC_BUTTON_COOLDOWN_TIMER)->ShowWindow(TRUE);
        GetDlgItem(IDC_BUTTON_AMBIENT_EFFECT)->ShowWindow(TRUE);

        GetDlgItem(IDC_BUTTON_ALERTS)->MoveWindow(AlertsButtonRect.left, 
                                                    AlertsButtonRect.top, 
                                                    AlertsButtonRect.Width(), 
                                                    AlertsButtonRect.Height());

        GetDlgItem(IDC_BUTTON_DAMAGE_TAKEN)->MoveWindow(DamageTakenButtonRect.left, 
                                                        DamageTakenButtonRect.top, 
                                                        DamageTakenButtonRect.Width(), 
                                                        DamageTakenButtonRect.Height());

    }
    else if(DeviceType == TARTARUS_DEVICE)
    {
        GetDlgItem(IDC_BUTTON_TUTORIAL)->ShowWindow(FALSE);
        GetDlgItem(IDC_BUTTON_ACTIVE_KEYS)->ShowWindow(FALSE);
        GetDlgItem(IDC_BUTTON_COOLDOWN_TIMER)->ShowWindow(FALSE);
        GetDlgItem(IDC_BUTTON_AMBIENT_EFFECT)->ShowWindow(FALSE);

        GetDlgItem(IDC_BUTTON_ALERTS)->MoveWindow(TutorialButtonRect.left, 
                                                    TutorialButtonRect.top, 
                                                    TutorialButtonRect.Width(), 
                                                    TutorialButtonRect.Height());

        GetDlgItem(IDC_BUTTON_DAMAGE_TAKEN)->MoveWindow(ActiveKeysButtonRect.left, 
                                                        ActiveKeysButtonRect.top, 
                                                        ActiveKeysButtonRect.Width(), 
                                                        ActiveKeysButtonRect.Height());
    }
}

// CKeypadPage message handlers


void CKeypadPage::OnBnClickedButtonLoadingAnimation()
{
    m_ChromaSDKImpl.PlayLoadingAnimation(5);
}

void CKeypadPage::OnBnClickedButtonTutorial()
{
    CTutorialDlg dlg(this);
    dlg.DoModal();
}

void CKeypadPage::OnBnClickedButtonActiveKeys()
{
    UINT VKeys[4] = { {0x41}, {0x57}, {0x53}, {0x44} };     // W,A,S,D
    m_ChromaSDKImpl.ShowKeys(5, 4, VKeys, RGB(0,255,0));
}

void CKeypadPage::OnBnClickedButtonHealthAmmoMana()
{
    CHealthAmmoManaDlg dlg(this);
    dlg.DoModal();
}

void CKeypadPage::OnBnClickedButtonAlerts()
{
    CAlertDlg dlg(this);
    dlg.DoModal();
}

void CKeypadPage::OnBnClickedButtonCooldownTimer()
{
    CCooldownTimerDlg dlg(this);
    dlg.DoModal();
}

void CKeypadPage::OnBnClickedButtonAmbientEffect()
{
    CAmbientEffectDlg dlg(this);
    dlg.DoModal();
}

void CKeypadPage::OnBnClickedButtonDamageTaken()
{
    m_ChromaSDKImpl.ShowColor(5, RED);
    Sleep(50);
    m_ChromaSDKImpl.ResetEffects(5);
}

void CKeypadPage::OnBnClickedRadioOrbweaver()
{
    ShowButtons(ORBWEAVER_DEVICE);
}

void CKeypadPage::OnBnClickedRadioTartarus()
{
    ShowButtons(TARTARUS_DEVICE);
}
