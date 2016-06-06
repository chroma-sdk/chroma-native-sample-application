// KeyboardPage.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "KeyboardPage.h"
#include "afxdialogex.h"
#include "TutorialDlg.h"
#include "HealthAmmoManaDlg.h"
#include "AlertDlg.h"
#include "CooldownTimerDlg.h"
#include "AmbientEffectDlg.h"


// CKeyboardPage dialog

IMPLEMENT_DYNAMIC(CKeyboardPage, CPropertyPage)

CKeyboardPage::CKeyboardPage()
    : CPropertyPage(CKeyboardPage::IDD)
{

}

CKeyboardPage::~CKeyboardPage()
{
}

void CKeyboardPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
}

BOOL CKeyboardPage::OnInitDialog()
{
    BOOL Result = CPropertyPage::OnInitDialog();

    return Result;
}

BEGIN_MESSAGE_MAP(CKeyboardPage, CPropertyPage)
    ON_WM_DESTROY()
    ON_BN_CLICKED(IDC_BUTTON_LOADING_ANIMATION, &CKeyboardPage::OnBnClickedButtonLoadingAnimation)
    ON_BN_CLICKED(IDC_BUTTON_TUTORIAL, &CKeyboardPage::OnBnClickedButtonTutorial)
    ON_BN_CLICKED(IDC_BUTTON_ACTIVE_KEYS, &CKeyboardPage::OnBnClickedButtonActiveKeys)
    ON_BN_CLICKED(IDC_BUTTON_HEALTH_AMMO_MANA, &CKeyboardPage::OnBnClickedButtonHealthAmmoMana)
    ON_BN_CLICKED(IDC_BUTTON_ALERTS, &CKeyboardPage::OnBnClickedButtonAlerts)
    ON_BN_CLICKED(IDC_BUTTON_COOLDOWN_TIMER, &CKeyboardPage::OnBnClickedButtonCooldownTimer)
    ON_BN_CLICKED(IDC_BUTTON_AMBIENT_EFFECT, &CKeyboardPage::OnBnClickedButtonAmbientEffect)
    ON_BN_CLICKED(IDC_BUTTON_DAMAGE_TAKEN, &CKeyboardPage::OnBnClickedButtonDamageTaken)
END_MESSAGE_MAP()


// CKeyboardPage message handlers

void CKeyboardPage::OnDestroy()
{
}

void CKeyboardPage::OnBnClickedButtonLoadingAnimation()
{
    m_ChromaSDKImpl.PlayLoadingAnimation(1);
}

void CKeyboardPage::OnBnClickedButtonTutorial()
{
    CTutorialDlg dlg(this);
    dlg.DoModal();
}

void CKeyboardPage::OnBnClickedButtonActiveKeys()
{
    UINT VKeys[13] = { 
                        {0x41},             // W
                        {0x57},             // A
                        {0x53},             // S
                        {0x44},             // D
                        {VK_LCONTROL},      // Left Control
                        {VK_LSHIFT},        // Left Shift
                        {VK_SPACE},         // Spacebar
                        {VK_ESCAPE},        // Esc
                        {VK_RETURN},        // Enter
                        {VK_UP},            // Up
                        {VK_DOWN},          // Down
                        {VK_LEFT},          // Left
                        {VK_RIGHT},         // Right
                    };

    m_ChromaSDKImpl.ShowKeys(1, 13, VKeys, RGB(0,255,0), TRUE);
}

void CKeyboardPage::OnBnClickedButtonHealthAmmoMana()
{
    CHealthAmmoManaDlg dlg(this);
    dlg.DoModal();
}

void CKeyboardPage::OnBnClickedButtonAlerts()
{
    CAlertDlg dlg(this);
    dlg.DoModal();
}

void CKeyboardPage::OnBnClickedButtonCooldownTimer()
{
    CCooldownTimerDlg dlg(this);
    dlg.DoModal();
}

void CKeyboardPage::OnBnClickedButtonAmbientEffect()
{
    CAmbientEffectDlg dlg(this);
    dlg.DoModal();
}

void CKeyboardPage::OnBnClickedButtonDamageTaken()
{
    m_ChromaSDKImpl.ShowColor(1, RED);
    Sleep(50);
    m_ChromaSDKImpl.ResetEffects(1);
}
