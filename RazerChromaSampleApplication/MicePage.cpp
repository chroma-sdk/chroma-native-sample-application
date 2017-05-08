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
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frames[11] = {};

        ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE2 Effect = {};

        g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_CUSTOM2, &Effect, &Frames[0]);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frames[0], 500);

        for(int i = 0; i < ChromaSDK::Mouse::MAX_ROW; i++)
        {
            for(int j = 0; j < ChromaSDK::Mouse::MAX_COLUMN; j++)
            {
                Effect.Color[ChromaSDK::Mouse::MAX_ROW - 1 - i][j] = ORANGE;
            }

            g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_CUSTOM2, &Effect, &Frames[i+1]);

            g_ChromaSDKImpl.AddToGroup(EffectId, Frames[i+1], 50);
        }
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
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
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;

        ChromaSDK::Mouse::STATIC_EFFECT_TYPE Static = {};

        Static.LEDId = ChromaSDK::Mouse::RZLED_ALL;
        Static.Color = RED;

        g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_STATIC, &Static, &Frame1);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 50);

        g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_NONE, NULL, &Frame2);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 50);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
}
