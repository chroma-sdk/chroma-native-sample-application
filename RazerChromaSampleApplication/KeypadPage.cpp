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
    static RZEFFECTID OrbweaverEffectId = GUID_NULL;
    static RZEFFECTID TartarusEffectId = GUID_NULL;

    if(IsEqualGUID(OrbweaverEffectId, GUID_NULL))
    {
        // Create Effect for Obrweaver
        g_ChromaSDKImpl.CreateEffectGroup(&OrbweaverEffectId);

        RZEFFECTID Frame0 = GUID_NULL;
        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;
        RZEFFECTID Frame3 = GUID_NULL;
        RZEFFECTID Frame4 = GUID_NULL;
        RZEFFECTID Frame5 = GUID_NULL;

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::ORBWEAVER_CHROMA, ChromaSDK::CHROMA_NONE, NULL, &Frame0);

        g_ChromaSDKImpl.AddToGroup(OrbweaverEffectId, Frame0, 500);

        ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

        for(UINT r=0; r<ChromaSDK::Keypad::MAX_ROW; r++)
        {
            Effect.Color[r][0] = ORANGE;
        }

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::ORBWEAVER_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame1);

        g_ChromaSDKImpl.AddToGroup(OrbweaverEffectId, Frame1, 100);

        for(UINT r=0; r<ChromaSDK::Keypad::MAX_ROW; r++)
        {
            Effect.Color[r][1] = ORANGE;
        }

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::ORBWEAVER_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame2);

        g_ChromaSDKImpl.AddToGroup(OrbweaverEffectId, Frame2, 100);

        for(UINT r=0; r<ChromaSDK::Keypad::MAX_ROW; r++)
        {
            Effect.Color[r][2] = ORANGE;
        }

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::ORBWEAVER_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame3);

        g_ChromaSDKImpl.AddToGroup(OrbweaverEffectId, Frame3, 100);

        for(UINT r=0; r<ChromaSDK::Keypad::MAX_ROW; r++)
        {
            Effect.Color[r][3] = ORANGE;
        }

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::ORBWEAVER_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame4);

        g_ChromaSDKImpl.AddToGroup(OrbweaverEffectId, Frame4, 100);

        for(UINT r=0; r<ChromaSDK::Keypad::MAX_ROW; r++)
        {
            Effect.Color[r][4] = ORANGE;
        }

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::ORBWEAVER_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame5);

        g_ChromaSDKImpl.AddToGroup(OrbweaverEffectId, Frame5, 100);
    }

    if(IsEqualGUID(TartarusEffectId, GUID_NULL))
    {
        // Create Effect for Tartarus
        g_ChromaSDKImpl.CreateEffectGroup(&TartarusEffectId);

        RZEFFECTID Frame0 = GUID_NULL;
        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;
        RZEFFECTID Frame3 = GUID_NULL;
        RZEFFECTID Frame4 = GUID_NULL;
        RZEFFECTID Frame5 = GUID_NULL;

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::TARTARUS_CHROMA, ChromaSDK::CHROMA_NONE, NULL, &Frame0);

        g_ChromaSDKImpl.AddToGroup(TartarusEffectId, Frame0, 500);

        ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

        Effect.Color[0][0] = RGB((255.0/100.0*0.2),((165.0/100.0)*0.2),00);     // Orange with 20% brightness

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::TARTARUS_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame1);

        g_ChromaSDKImpl.AddToGroup(TartarusEffectId, Frame1, 100);

        Effect.Color[0][0] = RGB((255.0/100.0*0.4),((165.0/100.0)*0.4),00);     // Orange with 40% brightness

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::TARTARUS_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame2);

        g_ChromaSDKImpl.AddToGroup(TartarusEffectId, Frame2, 100);

        Effect.Color[0][0] = RGB((255.0/100.0*0.6),((165.0/100.0)*0.6),00);     // Orange with 60% brightness

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::TARTARUS_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame3);

        g_ChromaSDKImpl.AddToGroup(TartarusEffectId, Frame3, 100);

        Effect.Color[0][0] = RGB((255.0/100.0*0.8),((165.0/100.0)*0.8),00);     // Orange with 80% brightness

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::TARTARUS_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame4);

        g_ChromaSDKImpl.AddToGroup(TartarusEffectId, Frame4, 100);

        Effect.Color[0][0] = ORANGE;                                            // Orange with 100% brightness

        g_ChromaSDKImpl.CreateEffectImpl(ChromaSDK::TARTARUS_CHROMA, ChromaSDK::CHROMA_CUSTOM, &Effect, &Frame5);

        g_ChromaSDKImpl.AddToGroup(TartarusEffectId, Frame5, 100);
    }

    g_ChromaSDKImpl.SetEffectImpl(OrbweaverEffectId);
    g_ChromaSDKImpl.SetEffectImpl(TartarusEffectId);
}

void CKeypadPage::OnBnClickedButtonTutorial()
{
    CTutorialDlg dlg(this);
    dlg.DoModal();
}

void CKeypadPage::OnBnClickedButtonActiveKeys()
{
static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frame1;
        RZEFFECTID Frame2;
        RZEFFECTID Frame3;
        RZEFFECTID Frame4;
        RZEFFECTID Frame5;
        RZEFFECTID Frame6;
        RZEFFECTID Frame7;

        // Frame 1
        ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Custom = {};

        Custom.Color[1][2] = GREEN;
        Custom.Color[2][1] = GREEN;
        Custom.Color[2][2] = GREEN;
        Custom.Color[2][3] = GREEN;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Custom, &Frame1);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 50);

        // Frame 2
        ZeroMemory(&Custom, sizeof(Custom));

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[0][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[1][i] = ORANGE;
        }

        Custom.Color[1][2] = GREEN;
        Custom.Color[2][1] = GREEN;
        Custom.Color[2][2] = GREEN;
        Custom.Color[2][3] = GREEN;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Custom, &Frame2);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 50);

        // Frame 3
        ZeroMemory(&Custom, sizeof(Custom));

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[0][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[1][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[2][i] = ORANGE;
        }

        Custom.Color[1][2] = GREEN;
        Custom.Color[2][1] = GREEN;
        Custom.Color[2][2] = GREEN;
        Custom.Color[2][3] = GREEN;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Custom, &Frame3);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame3, 80);

        // Frame 4
        ZeroMemory(&Custom, sizeof(Custom));

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[1][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[2][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[3][i] = ORANGE;
        }

        Custom.Color[1][2] = GREEN;
        Custom.Color[2][1] = GREEN;
        Custom.Color[2][2] = GREEN;
        Custom.Color[2][3] = GREEN;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Custom, &Frame4);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame4, 80);

        // Frame 5
        ZeroMemory(&Custom, sizeof(Custom));

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[2][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[3][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        Custom.Color[1][2] = GREEN;
        Custom.Color[2][1] = GREEN;
        Custom.Color[2][2] = GREEN;
        Custom.Color[2][3] = GREEN;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Custom, &Frame5);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame5, 80);

        // Frame 6
        ZeroMemory(&Custom, sizeof(Custom));

        for(int i=0; i<ChromaSDK::Keypad::MAX_COLUMN; i++)
        {
            Custom.Color[3][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        Custom.Color[1][2] = GREEN;
        Custom.Color[2][1] = GREEN;
        Custom.Color[2][2] = GREEN;
        Custom.Color[2][3] = GREEN;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Custom, &Frame6);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame6, 80);

        // Frame 7
        ZeroMemory(&Custom, sizeof(Custom));

        Custom.Color[1][2] = GREEN;
        Custom.Color[2][1] = GREEN;
        Custom.Color[2][2] = GREEN;
        Custom.Color[2][3] = GREEN;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Custom, &Frame7);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame7, 80);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
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
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;

        ChromaSDK::Keypad::STATIC_EFFECT_TYPE Static = {};

        Static.Color = RED;

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_STATIC, &Static, &Frame1);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 50);

        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_NONE, NULL, &Frame2);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 50);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
}

void CKeypadPage::OnBnClickedRadioOrbweaver()
{
    ShowButtons(ORBWEAVER_DEVICE);
}

void CKeypadPage::OnBnClickedRadioTartarus()
{
    ShowButtons(TARTARUS_DEVICE);
}
