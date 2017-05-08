#pragma once


// CChromaLinkPage dialog

class CChromaLinkPage : public CPropertyPage
{
    DECLARE_DYNAMIC(CChromaLinkPage)

public:
    CChromaLinkPage();
    virtual ~CChromaLinkPage();

// Dialog Data
    enum { IDD = IDD_CHROMALINK_PAGE };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonLoadingAnimation();
    afx_msg void OnBnClickedButtonHealthAmmoMana();
    afx_msg void OnBnClickedButtonAlerts();
    afx_msg void OnBnClickedButtonDamageTaken();
};
