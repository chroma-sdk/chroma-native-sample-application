// HealthAmmoManaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "HealthAmmoManaDlg.h"
#include "afxdialogex.h"


// CHealthAmmoManaDlg dialog

IMPLEMENT_DYNAMIC(CHealthAmmoManaDlg, CDialogEx)

CHealthAmmoManaDlg::CHealthAmmoManaDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CHealthAmmoManaDlg::IDD, pParent)
{
    m_pParent = pParent;
    m_DeviceType = 0;
}

CHealthAmmoManaDlg::~CHealthAmmoManaDlg()
{
}

void CHealthAmmoManaDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_HEALTH, m_Health);
    DDX_Control(pDX, IDC_SLIDER_AMMO_MANA, m_AmmoMana);
}

BOOL CHealthAmmoManaDlg::OnInitDialog()
{
    BOOL Result = CDialogEx::OnInitDialog();

    m_Health.SetRange(0, 100);
    m_AmmoMana.SetRange(0, 100);

    CPropertyPage* pPage = (CPropertyPage*)m_pParent;
    PROPSHEETPAGE PageInfo = pPage->GetPSP();

    if(_tcsicmp(PageInfo.pszTitle, _T("Keyboards")) == 0)
    {
        m_DeviceType = 1;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Mousemats")) == 0)
    {
        m_DeviceType = 2;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Mice")) == 0)
    {
        m_DeviceType = 3;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Headsets")) == 0)
    {
        m_DeviceType = 4;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Keypads")) == 0)
    {
        m_DeviceType = 5;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Chroma Linked Devices")) == 0)
    {
        m_DeviceType = 6;
    }

    UpdateData(TRUE);

    UINT Hp = m_Health.GetPos();
    UINT Ammo = m_AmmoMana.GetPos();

    switch(m_DeviceType)
    {
    case 1: // Keyboard
        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_NONE, NULL);
        break;
    case 2: // Mousemats
        g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_NONE, NULL);
        break;
    case 3: // Mice
        g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_NONE, NULL);
        break;
    case 4: // Headsets
        g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_NONE, NULL);
        break;
    case 5: // Keypads
        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_NONE, NULL);
        break;
    case 6: // Chroma Linked devices
        g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_NONE, NULL);
        break;
    }

    return Result;
}

BEGIN_MESSAGE_MAP(CHealthAmmoManaDlg, CDialogEx)
    ON_WM_HSCROLL()
    ON_WM_CLOSE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CHealthAmmoManaDlg message handlers
void CHealthAmmoManaDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    UpdateData(TRUE);

    UINT Hp = m_Health.GetPos();
    UINT Ammo = m_AmmoMana.GetPos();

    switch(m_DeviceType)
    {
    case 1: // Keyboards
        {
            ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE Effect = {};

            // Function keys as health
            UINT RemainingHealth = UINT(Hp/100.0 * 12.0); // 12 function keys

            COLORREF HpColor = RGB((((12-RemainingHealth)/12.0)*255), ((RemainingHealth/12.0)*255), 0);

            UINT HpLevel = ChromaSDK::Keyboard::RZKEY_F1;
            for(UINT i=0; i<RemainingHealth; i++)
            {
                // F1 key starts from row 0, column 3 to column column 15
                Effect.Key[HIBYTE(HpLevel+i)][LOBYTE(HpLevel+i)] = 0x01000000 | HpColor;
            }

            // Number keys as ammo
            UINT RemainingAmmo = UINT(Ammo/100.0 * 10.0); // 10 number keys

            UINT AmmoLevel = ChromaSDK::Keyboard::RZKEY_1;
            for(UINT i=0; i<RemainingAmmo; i++)
            {
                // Number keys starts from row 1, column 2 to column 12
                Effect.Key[HIBYTE(AmmoLevel+i)][LOBYTE(AmmoLevel+i)] = 0x01000000 | YELLOW;
            }

            g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &Effect, NULL);
        }
        break;
    case 2: // Mousepads
        {
            ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE Effect = {};

            FLOAT RemainingHealth = FLOAT((FLOAT)Hp/100.0 * 5.0); // 5 LEDs on the left.

            COLORREF HpColor;
            if(RemainingHealth == 0.0)
            {
                HpColor = RED;

                Effect.Color[10] = HpColor;
                Effect.Color[11] = HpColor;
                Effect.Color[12] = HpColor;
                Effect.Color[13] = HpColor;
                Effect.Color[14] = HpColor;
            }
            else
            {
                HpColor = RGB((((5-RemainingHealth)/5.0)*255), ((RemainingHealth/5.0)*255), 0);

                for(UINT i=0; i<RemainingHealth; i++)
                {
                    // Display Hp on the left side of the mouse mat.
                    Effect.Color[10+i] = HpColor;
                }
            }

            // Number keys as ammo
            UINT RemainingAmmo = UINT(Ammo/100.0 * 5.0); // 5 LEDs on the right.

            for(UINT i=0; i<RemainingAmmo; i++)
            {
                // Display ammo/mana on the right side.
                Effect.Color[4-i] = YELLOW;
            }

            g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_CUSTOM, &Effect, NULL);
        }
        break;
    case 3: // Mice
        {
            ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE Effect = {};

            UINT RemainingHealth = UINT(Hp/100.0 * 7.0); // 7 LEDs on the left.

            COLORREF HpColor = RGB((((7-RemainingHealth)/7.0)*255), ((RemainingHealth/7.0)*255), 0);

            // Display Hp on the left side of the mouse.
            for(UINT i=0; i<RemainingHealth; i++)
            {
                Effect.Color[ChromaSDK::Mouse::RZLED_SIDE_STRIP7-i] = HpColor;
            }

            UINT RemainingAmmo = UINT(Ammo/100.0 * 7.0); // 7 LEDs on the right.

            // Display ammo/mana on the right side of the mouse.
            for(UINT i=0; i<RemainingAmmo; i++)
            {
                Effect.Color[ChromaSDK::Mouse::RZLED_SIDE_STRIP14-i] = YELLOW;
            }

            g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_CUSTOM, &Effect, NULL);
        }
        break;
    case 4: // Headsets
        {
            ChromaSDK::Headset::STATIC_EFFECT_TYPE Effect = {};
            Effect.Color = RGB((255 - ((Hp/100.0) * 255.0)), ((Hp/100.0) * 255.0), 0);

            g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_STATIC, &Effect, NULL);
        }
    case 5: // Keypads
        {
            ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE Effect = {};

            FLOAT RemainingHealth = FLOAT((FLOAT)Hp/100.0 * 5.0); // 5 keys.

            COLORREF HpColor = RGB((((5-RemainingHealth)/5.0)*255), ((RemainingHealth/5.0)*255), 0);

            // Display Hp on keypads.
            for(UINT i=0; i<RemainingHealth; i++)
            {
                Effect.Color[0][i] = HpColor;
            }

            UINT RemainingAmmo = UINT(Ammo/100.0 * 5.0); // 5 keys.

            // Display ammo/mana on the last row.
            for(UINT i=0; i<RemainingAmmo; i++)
            {
                Effect.Color[3][i] = YELLOW;
            }

            g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_CUSTOM, &Effect, NULL);
        }
        break;
    case 6: // Chroma Linked devices
        {
            ChromaSDK::ChromaLink::CUSTOM_EFFECT_TYPE Effect = {};

            FLOAT RemainingHealth = FLOAT((FLOAT)Hp/100.0 * 5.0); // 5 LEDs.

            COLORREF HpColor = RGB((((5-RemainingHealth)/5.0)*255), ((RemainingHealth/5.0)*255), 0);

            // Display Hp on keypads.
            for(UINT i=0; i<RemainingHealth; i++)
            {
                Effect.Color[i] = HpColor;
            }

            g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_CUSTOM, &Effect, NULL);
        }
        break;
    }

    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CHealthAmmoManaDlg::OnDestroy()
{
    CDialogEx::OnDestroy();

    switch(m_DeviceType)
    {
    case 1: // Keyboard
        g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_NONE, NULL);
        break;
    case 2: // Mousemats
        g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_NONE, NULL);
        break;
    case 3: // Mice
        g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_NONE, NULL);
        break;
    case 4: // Headsets
        g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_NONE, NULL);
        break;
    case 5: // Keypads
        g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_NONE, NULL);
        break;
    case 6: // Chroma Linked devices
        g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_NONE, NULL);
        break;
    }
}
