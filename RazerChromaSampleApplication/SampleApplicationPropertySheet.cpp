// SampleApplicationPropertySheet.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "SampleApplicationPropertySheet.h"


// CSampleApplicationPropertySheet

IMPLEMENT_DYNAMIC(CSampleApplicationPropertySheet, CPropertySheet)

CSampleApplicationPropertySheet::CSampleApplicationPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
    :CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
    m_psh.dwFlags &= ~(PSH_HASHELP);
}

CSampleApplicationPropertySheet::CSampleApplicationPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
    :CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
    m_psh.dwFlags &= ~(PSH_HASHELP);
}

CSampleApplicationPropertySheet::~CSampleApplicationPropertySheet()
{
}

BOOL CSampleApplicationPropertySheet::OnInitDialog()
{
    m_ChromaSDKImpl.Initialize();

    return CPropertySheet::OnInitDialog();
}

BEGIN_MESSAGE_MAP(CSampleApplicationPropertySheet, CPropertySheet)
    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CSampleApplicationPropertySheet message handlers
void CSampleApplicationPropertySheet::OnDestroy()
{
    m_ChromaSDKImpl.UnInitialize();
}
