#pragma once

#include "ChromaSDKImpl.h"

// CHeadsetPage dialog

class CHeadsetPage : public CPropertyPage
{
    DECLARE_DYNAMIC(CHeadsetPage)

public:
    CHeadsetPage();
    virtual ~CHeadsetPage();

private:
    CChromaSDKImpl m_ChromaSDKImpl;

// Dialog Data
    enum { IDD = IDD_HEADSET_PAGE };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonHealthAmmoMana();
    afx_msg void OnBnClickedButtonAlerts();
    afx_msg void OnBnClickedButtonDamageTaken();
};
