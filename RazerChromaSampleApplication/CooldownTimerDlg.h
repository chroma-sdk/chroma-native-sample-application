#pragma once

#include "ChromaSDKImpl.h"
#include "afxcmn.h"

// CCooldownTimerDlg dialog

class CCooldownTimerDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CCooldownTimerDlg)

public:
    CCooldownTimerDlg(CWnd* pParent = NULL);   // standard constructor
    virtual ~CCooldownTimerDlg();

// Dialog Data
    enum { IDD = IDD_DIALOG_COOLDOWN_TIMER };

private:
    CChromaSDKImpl m_ChromaSDKImpl;
    CWnd* m_pParent;
    UINT m_DeviceType;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    CSliderCtrl m_Timer;
};
