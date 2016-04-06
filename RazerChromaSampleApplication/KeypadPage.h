#pragma once

#include "ChromaSDKImpl.h"

// CKeypadPage dialog

class CKeypadPage : public CPropertyPage
{
    DECLARE_DYNAMIC(CKeypadPage)

public:
    CKeypadPage();
    virtual ~CKeypadPage();

// Dialog Data
    enum { IDD = IDD_KEYPAD_PAGE };

private:
    CChromaSDKImpl m_ChromaSDKImpl;

private:
    void ShowButtons(UINT DeviceType);

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonLoadingAnimation();
    afx_msg void OnBnClickedButtonTutorial();
    afx_msg void OnBnClickedButtonActiveKeys();
    afx_msg void OnBnClickedButtonHealthAmmoMana();
    afx_msg void OnBnClickedButtonAlerts();
    afx_msg void OnBnClickedButtonCooldownTimer();
    afx_msg void OnBnClickedButtonAmbientEffect();
    afx_msg void OnBnClickedButtonDamageTaken();
    afx_msg void OnBnClickedRadioOrbweaver();
    afx_msg void OnBnClickedRadioTartarus();
};
