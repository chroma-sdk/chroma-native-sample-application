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

using namespace ChromaSDK::Keyboard;

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
    static RZEFFECTID EffectId = GUID_NULL;

    if(EffectId == GUID_NULL)
    {
        RZEFFECTID Frame0 = GUID_NULL;
        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;
        RZEFFECTID Frame3 = GUID_NULL;
        RZEFFECTID Frame4 = GUID_NULL;
        RZEFFECTID Frame5 = GUID_NULL;
        RZEFFECTID Frame6 = GUID_NULL;
        RZEFFECTID Frame7 = GUID_NULL;

        ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE Effect = {};

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_NONE, NULL, &Frame0);

        for(UINT r=0; r<ChromaSDK::Keyboard::MAX_ROW; r++)
        {
            for(UINT c=0; c<3; c++)
            {
                Effect.Color[r][c] = ORANGE;
            }
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame1);

        for(UINT r=0; r<ChromaSDK::Keyboard::MAX_ROW; r++)
        {
            for(UINT c=0; c<6; c++)
            {
                Effect.Color[r][c] = ORANGE;
            }
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame2);

        for(UINT r=0; r<ChromaSDK::Keyboard::MAX_ROW; r++)
        {
            for(UINT c=0; c<9; c++)
            {
                Effect.Color[r][c] = ORANGE;
            }
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame3);

        for(UINT r=0; r<ChromaSDK::Keyboard::MAX_ROW; r++)
        {
            for(UINT c=0; c<12; c++)
            {
                Effect.Color[r][c] = ORANGE;
            }
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame4);

        for(UINT r=0; r<ChromaSDK::Keyboard::MAX_ROW; r++)
        {
            for(UINT c=0; c<15; c++)
            {
                Effect.Color[r][c] = ORANGE;
            }
        }

        Effect.Color[HIBYTE(RZLED_LOGO)][LOBYTE(RZLED_LOGO)] = ORANGE;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame5);

        for(UINT r=0; r<ChromaSDK::Keyboard::MAX_ROW; r++)
        {
            for(UINT c=0; c<18; c++)
            {
                Effect.Color[r][c] = ORANGE;
            }
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM, &Effect, &Frame6);

        ChromaSDK::Keyboard::STATIC_EFFECT_TYPE StaticEffect = {};
        StaticEffect.Color = ORANGE;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_STATIC, &StaticEffect, &Frame7);

        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame0, 500);
        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 100);
        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 100);
        g_ChromaSDKImpl.AddToGroup(EffectId, Frame3, 100);
        g_ChromaSDKImpl.AddToGroup(EffectId, Frame4, 100);
        g_ChromaSDKImpl.AddToGroup(EffectId, Frame5, 100);
        g_ChromaSDKImpl.AddToGroup(EffectId, Frame6, 100);
        g_ChromaSDKImpl.AddToGroup(EffectId, Frame7, 100);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
}

void CKeyboardPage::OnBnClickedButtonTutorial()
{
    CTutorialDlg dlg(this);
    dlg.DoModal();
}

void CKeyboardPage::OnBnClickedButtonActiveKeys()
{
    //UINT VKeys[13] = { 
    //                    {0x41},             // W
    //                    {0x57},             // A
    //                    {0x53},             // S
    //                    {0x44},             // D
    //                    {VK_LCONTROL},      // Left Control
    //                    {VK_LSHIFT},        // Left Shift
    //                    {VK_SPACE},         // Spacebar
    //                    {VK_ESCAPE},        // Esc
    //                    {VK_RETURN},        // Enter
    //                    {VK_UP},            // Up
    //                    {VK_DOWN},          // Down
    //                    {VK_LEFT},          // Left
    //                    {VK_RIGHT},         // Right
    //                };

    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frame0;
        RZEFFECTID Frame1;
        RZEFFECTID Frame2;
        RZEFFECTID Frame3;
        RZEFFECTID Frame4;
        RZEFFECTID Frame5;
        RZEFFECTID Frame6;
        RZEFFECTID Frame7;
        RZEFFECTID Frame8;
        RZEFFECTID Frame9;
        RZEFFECTID Frame10;

        ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE Keys = {};

        Keys.Key[HIBYTE(RZKEY_W)][LOBYTE(RZKEY_W)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_A)][LOBYTE(RZKEY_A)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_S)][LOBYTE(RZKEY_S)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_D)][LOBYTE(RZKEY_D)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_LCTRL)][LOBYTE(RZKEY_LCTRL)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_LSHIFT)][LOBYTE(RZKEY_LSHIFT)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_SPACE)][LOBYTE(RZKEY_SPACE)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_ESC)][LOBYTE(RZKEY_ESC)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_UP)][LOBYTE(RZKEY_UP)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_DOWN)][LOBYTE(RZKEY_DOWN)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_LEFT)][LOBYTE(RZKEY_LEFT)] = 0x01000000 | GREEN;
        Keys.Key[HIBYTE(RZKEY_RIGHT)][LOBYTE(RZKEY_RIGHT)] = 0x01000000 | GREEN;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Keys, &Frame0);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame0, 50);

        // Frame 1
        ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE Effect = {};
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame1);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 50);

        // Frame 2
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        for(int i=0; i<MAX_COLUMN; i++)
        {
            if(i != 20)
            {
                Effect.Color[0][i] = RGB(0.3 * GetRValue(ORANGE),
                                            0.3 * GetGValue(ORANGE),
                                            0.3 * GetBValue(ORANGE));
            }
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[1][i] = ORANGE;
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame2);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 50);

        // Frame 3
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        for(int i=0; i<MAX_COLUMN; i++)
        {
            if(i != 20)
            {
                Effect.Color[0][i] = RGB(0.1 * GetRValue(ORANGE),
                                            0.1 * GetGValue(ORANGE),
                                            0.1 * GetBValue(ORANGE));
            }
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[1][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[2][i] = ORANGE;
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame3);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame3, 80);

        // Frame 4
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[1][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[2][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[3][i] = ORANGE;
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame4);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame4, 80);

        // Frame 5
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[2][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[3][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[4][i] = ORANGE;
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame5);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame5, 80);

        // Frame 6
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[3][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[4][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[5][i] = ORANGE;
        }

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame6);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame6, 80);

        // Frame 7
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[4][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[5][i] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));
        }

        Effect.Color[0][20] = ORANGE;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame7);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame7, 80);

        // Frame 8
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        for(int i=0; i<MAX_COLUMN; i++)
        {
            Effect.Color[5][i] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));
        }

        Effect.Color[0][20] = RGB(0.3 * GetRValue(ORANGE),
                                        0.3 * GetGValue(ORANGE),
                                        0.3 * GetBValue(ORANGE));;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame8);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame8, 80);

        // Frame 9
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        Effect.Color[0][20] = RGB(0.1 * GetRValue(ORANGE),
                                        0.1 * GetGValue(ORANGE),
                                        0.1 * GetBValue(ORANGE));;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame9);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame9, 80);

        // Frame 10
        memcpy_s(&Effect, sizeof(Effect), &Keys, sizeof(Keys));

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(CHROMA_CUSTOM_KEY, &Effect, &Frame10);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame10, 80);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);

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
    static RZEFFECTID EffectId = GUID_NULL;
    if(IsEqualGUID(EffectId, GUID_NULL))
    {
        g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

        RZEFFECTID Frame1 = GUID_NULL;
        RZEFFECTID Frame2 = GUID_NULL;

        ChromaSDK::Keyboard::STATIC_EFFECT_TYPE Static = {};
        Static.Color = RED;

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_STATIC, &Static, &Frame1);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 50);

        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_NONE, NULL, &Frame2);

        g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 50);
    }

    g_ChromaSDKImpl.SetEffectImpl(EffectId);
}
