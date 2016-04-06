#pragma once

#include "ChromaSDKImpl.h"

// CAlertDlg dialog

class CAlertDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CAlertDlg)

public:
    CAlertDlg(CWnd* pParent = NULL);   // standard constructor
    virtual ~CAlertDlg();

// Dialog Data
    enum { IDD = IDD_DIALOG_ALERTS };

private:
    CChromaSDKImpl m_ChromaSDKImpl;
    CWnd* m_pParent;
    UINT m_DeviceType;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonPositiveAlert();
    afx_msg void OnBnClickedButtonNegativeAlert();
};
