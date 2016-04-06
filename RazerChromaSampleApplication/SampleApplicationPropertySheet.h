#pragma once

#include "ChromaSDKImpl.h"

// CSampleApplicationPropertySheet

class CSampleApplicationPropertySheet : public CPropertySheet
{
    DECLARE_DYNAMIC(CSampleApplicationPropertySheet)

public:
    CSampleApplicationPropertySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
    CSampleApplicationPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

    virtual ~CSampleApplicationPropertySheet();
    virtual BOOL OnInitDialog();

protected:
    DECLARE_MESSAGE_MAP()

    afx_msg void OnDestroy();

private:
    CChromaSDKImpl m_ChromaSDKImpl;
};


