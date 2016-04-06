#pragma once

#include "ChromaSDKImpl.h"

// CTutorialDlg dialog

class CTutorialDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CTutorialDlg)

public:
    CTutorialDlg(CWnd* pParent = NULL);   // standard constructor
    virtual ~CTutorialDlg();

// Dialog Data
    enum { IDD = IDD_DIALOG_TUTORIAL };

private:
    CWnd* m_pParent;
    UINT m_DeviceType;

private:
    CChromaSDKImpl m_ChromaSDKImpl;
    void OnWKeyUp();
    void OnAKeyUp();
    void OnSKeyUp();
    void OnDKeyUp();

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();
    virtual BOOL PreTranslateMessage(MSG* pMsg);

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnDestroy();

};

