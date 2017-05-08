// ChromaLinkPage.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "ChromaLinkPage.h"
#include "afxdialogex.h"
#include "HealthAmmoManaDlg.h"
#include "AlertDlg.h"


// CChromaLinkPage dialog

IMPLEMENT_DYNAMIC(CChromaLinkPage, CPropertyPage)

CChromaLinkPage::CChromaLinkPage()
    : CPropertyPage(CChromaLinkPage::IDD)
{

}

CChromaLinkPage::~CChromaLinkPage()
{
}

void CChromaLinkPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChromaLinkPage, CPropertyPage)
    ON_BN_CLICKED(IDC_BUTTON_LOADING_ANIMATION, &CChromaLinkPage::OnBnClickedButtonLoadingAnimation)
    ON_BN_CLICKED(IDC_BUTTON_HEALTH_AMMO_MANA, &CChromaLinkPage::OnBnClickedButtonHealthAmmoMana)
    ON_BN_CLICKED(IDC_BUTTON_ALERTS, &CChromaLinkPage::OnBnClickedButtonAlerts)
    ON_BN_CLICKED(IDC_BUTTON_DAMAGE_TAKEN, &CChromaLinkPage::OnBnClickedButtonDamageTaken)
END_MESSAGE_MAP()


// CChromaLinkPage message handlers


void CChromaLinkPage::OnBnClickedButtonLoadingAnimation()
{
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frames[11] = {};

        ChromaSDK::ChromaLink::CUSTOM_EFFECT_TYPE Effect = {};

        g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_CUSTOM, &Effect, &Frames[0]);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frames[0], 500);

        for(int i = 0; i < ChromaSDK::ChromaLink::MAX_LEDS; i++)
        {
            Effect.Color[i] = ORANGE;

            g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_CUSTOM, &Effect, &Frames[i+1]);

            g_ChromaSDKImpl.AddToGroup(EffectId, Frames[i+1], 80);
        }
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
}


void CChromaLinkPage::OnBnClickedButtonHealthAmmoMana()
{
    CHealthAmmoManaDlg dlg(this);
    dlg.DoModal();
}


void CChromaLinkPage::OnBnClickedButtonAlerts()
{
    CAlertDlg dlg(this);
    dlg.DoModal();
}


void CChromaLinkPage::OnBnClickedButtonDamageTaken()
{
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;

        ChromaSDK::ChromaLink::STATIC_EFFECT_TYPE Static = {};
        Static.Color = RED;

        g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_STATIC, &Static, &Frame1);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 50);

        g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_NONE, NULL, &Frame2);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 50);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
}
