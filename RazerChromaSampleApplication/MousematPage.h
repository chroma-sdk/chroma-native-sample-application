#pragma once

#include "ChromaSDKImpl.h"


// CMousematPage dialog

class CMousematPage : public CPropertyPage
{
    DECLARE_DYNAMIC(CMousematPage)

public:
    CMousematPage();
    virtual ~CMousematPage();

// Dialog Data
    enum { IDD = IDD_MOUSEMAT_PAGE };

private:
    CChromaSDKImpl m_ChromaSDKImpl;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonLoadingAnimation();
    afx_msg void OnBnClickedButtonHealthAmmoMana();
    afx_msg void OnBnClickedButtonAlerts();
    afx_msg void OnBnClickedButtonCooldownTimer();
    afx_msg void OnBnClickedButtonDamageTaken();
};
