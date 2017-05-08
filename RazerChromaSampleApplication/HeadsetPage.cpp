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
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;

        ChromaSDK::Headset::STATIC_EFFECT_TYPE Static = {};

        Static.Color = RED;

        g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_STATIC, &Static, &Frame1);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 50);

        g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_NONE, NULL, &Frame2);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 50);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
}
