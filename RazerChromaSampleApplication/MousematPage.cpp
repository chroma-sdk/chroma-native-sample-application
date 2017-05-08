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
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frames[16];

        g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_NONE, NULL, &Frames[0]);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frames[0], 500);

        ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE Effect = {};

        for(int i=0; i<ChromaSDK::Mousepad::MAX_LEDS; i++)
        {
            Effect.Color[ChromaSDK::Mousepad::MAX_LEDS-1-i] = ORANGE;

            g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_CUSTOM, &Effect, &Frames[i+1]);

            g_ChromaSDKImpl.AddToGroup(EffectId, Frames[i+1], 50);
        }
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
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
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;

        ChromaSDK::Mousepad::STATIC_EFFECT_TYPE Static = {};
        Static.Color = RED;

        g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_STATIC, &Static, &Frame1);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 50);

        g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_NONE, NULL, &Frame2);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 50);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
}
