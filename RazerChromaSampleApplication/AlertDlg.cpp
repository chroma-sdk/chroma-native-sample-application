// AlertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "AlertDlg.h"
#include "afxdialogex.h"

// CAlertDlg dialog

IMPLEMENT_DYNAMIC(CAlertDlg, CDialogEx)

CAlertDlg::CAlertDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CAlertDlg::IDD, pParent)
{
    m_pParent = pParent;
    m_DeviceType = 0;
}

CAlertDlg::~CAlertDlg()
{
}

void CAlertDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BOOL CAlertDlg::OnInitDialog()
{
    BOOL Result = CDialogEx::OnInitDialog();

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

    return Result;
}

BEGIN_MESSAGE_MAP(CAlertDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_POSITIVE_ALERT, &CAlertDlg::OnBnClickedButtonPositiveAlert)
    ON_BN_CLICKED(IDC_BUTTON_NEGATIVE_ALERT, &CAlertDlg::OnBnClickedButtonNegativeAlert)
    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CAlertDlg message handlers


void CAlertDlg::OnBnClickedButtonPositiveAlert()
{
    switch(m_DeviceType)
    {
    case 1: // Keyboards
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Keyboard::STATIC_EFFECT_TYPE Static = {};
                Static.Color = GREEN;

                g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 2: // Mousemats
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Mousepad::STATIC_EFFECT_TYPE Static = {};
                Static.Color = GREEN;

                g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 3: // Mice
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Mouse::STATIC_EFFECT_TYPE Static = {};
                Static.LEDId = ChromaSDK::Mouse::RZLED_ALL;
                Static.Color = GREEN;

                g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 4: // Headsets
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Headset::STATIC_EFFECT_TYPE Static = {};
                Static.Color = GREEN;

                g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 5: // Keypads
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Keypad::STATIC_EFFECT_TYPE Static = {};
                Static.Color = GREEN;

                g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 6: // Chroma Linked devices
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::ChromaLink::STATIC_EFFECT_TYPE Static = {};
                Static.Color = GREEN;

                g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    }
}


void CAlertDlg::OnBnClickedButtonNegativeAlert()
{
    switch(m_DeviceType)
    {
    case 1: // Keyboards
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Keyboard::STATIC_EFFECT_TYPE Static = {};
                Static.Color = RED;

                g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 2: // Mousemats
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Mousepad::STATIC_EFFECT_TYPE Static = {};
                Static.Color = RED;

                g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 3: // Mice
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Mouse::STATIC_EFFECT_TYPE Static = {};
                Static.LEDId = ChromaSDK::Mouse::RZLED_ALL;
                Static.Color = RED;

                g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 4: // Headsets
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Headset::STATIC_EFFECT_TYPE Static = {};
                Static.Color = RED;

                g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateHeadsetEffectImpl(ChromaSDK::Headset::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 5: // Keypads
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::Keypad::STATIC_EFFECT_TYPE Static = {};
                Static.Color = RED;

                g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateKeypadEffectImpl(ChromaSDK::Keypad::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    case 6: // Chroma Linked devices
        {
            static RZEFFECTID EffectId = GUID_NULL;
            if(IsEqualGUID(EffectId , GUID_NULL))
            {
                g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

                RZEFFECTID Frame1;
                RZEFFECTID Frame2;

                ChromaSDK::ChromaLink::STATIC_EFFECT_TYPE Static = {};
                Static.Color = RED;

                g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_STATIC, &Static, &Frame1);

                g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_NONE, NULL, &Frame2);

                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs

                // Blink 3 times
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);
                g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);
            }

            g_ChromaSDKImpl.SetEffectImpl(EffectId);
        }
        break;
    }
}



void CAlertDlg::OnDestroy()
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
    case 6: // Chroma Linked devices.
        g_ChromaSDKImpl.CreateChromaLinkEffectImpl(ChromaSDK::ChromaLink::CHROMA_NONE, NULL);
        break;
    }
}
