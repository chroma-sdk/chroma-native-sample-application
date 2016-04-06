#pragma once

#include "ChromaSDKImpl.h"

// CAmbientEffectDlg dialog

class CAmbientEffectDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CAmbientEffectDlg)

public:
    CAmbientEffectDlg(CWnd* pParent = NULL);   // standard constructor
    virtual ~CAmbientEffectDlg();

// Dialog Data
    enum { IDD = IDD_DIALOG_AMBIENT_EFFECT };

private:
    CWnd* m_pParent;
    UINT m_DeviceType;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();

private:
    CChromaSDKImpl m_ChromaSDKImpl;

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonAmbientEffectStart();
    afx_msg void OnBnClickedButtonAmbientEffectStop();
    afx_msg void OnDestroy();
};
