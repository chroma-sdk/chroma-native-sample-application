#pragma once

#include "ChromaSDKImpl.h"

// CHealthAmmoManaDlg dialog

class CHealthAmmoManaDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CHealthAmmoManaDlg)

public:
    CHealthAmmoManaDlg(CWnd* pParent = NULL);   // standard constructor
    virtual ~CHealthAmmoManaDlg();

// Dialog Data
    enum { IDD = IDD_DIALOG_HEALTH_AMMO_MANA };

private:
    CChromaSDKImpl m_ChromaSDKImpl;
    CWnd* m_pParent;
    UINT m_DeviceType;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

public:
    CSliderCtrl m_Health;
    CSliderCtrl m_AmmoMana;
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnDestroy();
};
