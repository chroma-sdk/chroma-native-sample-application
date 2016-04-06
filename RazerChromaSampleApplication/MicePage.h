#pragma once

#include "ChromaSDKImpl.h"

// CMicePage dialog

class CMicePage : public CPropertyPage
{
    DECLARE_DYNAMIC(CMicePage)

public:
    CMicePage();
    virtual ~CMicePage();

// Dialog Data
    enum { IDD = IDD_MICE_PAGE };

private:
    CChromaSDKImpl m_ChromaSDKImpl;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonLoadingAnimation();
    afx_msg void OnBnClickedButtonHealthAmmoMana();
    afx_msg void OnBnClickedButtonAlerts();
    afx_msg void OnBnClickedButtonDamageTaken();
};
