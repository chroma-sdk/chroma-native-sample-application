// HealthAmmoManaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "HealthAmmoManaDlg.h"
#include "afxdialogex.h"


// CHealthAmmoManaDlg dialog

IMPLEMENT_DYNAMIC(CHealthAmmoManaDlg, CDialogEx)

CHealthAmmoManaDlg::CHealthAmmoManaDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CHealthAmmoManaDlg::IDD, pParent)
{
    m_pParent = pParent;
    m_DeviceType = 0;
}

CHealthAmmoManaDlg::~CHealthAmmoManaDlg()
{
}

void CHealthAmmoManaDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SLIDER_HEALTH, m_Health);
    DDX_Control(pDX, IDC_SLIDER_AMMO_MANA, m_AmmoMana);
}

BOOL CHealthAmmoManaDlg::OnInitDialog()
{
    BOOL Result = CDialogEx::OnInitDialog();

    m_Health.SetRange(0, 100);
    m_AmmoMana.SetRange(0, 100);

    CPropertyPage* pPage = (CPropertyPage*)m_pParent;
    PROPSHEETPAGE PageInfo = pPage->GetPSP();

    if(_tcsicmp(PageInfo.pszTitle, _T("Keyboards")) == 0)
    {
        m_DeviceType = 1;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Mousemats")) == 0)
    {
        m_DeviceType = 2;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Mice")) == 0)
    {
        m_DeviceType = 3;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Headsets")) == 0)
    {
        m_DeviceType = 4;
    }
    else if(_tcsicmp(PageInfo.pszTitle, _T("Keypads")) == 0)
    {
        m_DeviceType = 5;
    }

    UpdateData(TRUE);

    UINT Hp = m_Health.GetPos();
    UINT Ammo = m_AmmoMana.GetPos();

    m_ChromaSDKImpl.ShowLevel(m_DeviceType, Hp, Ammo);

    return Result;
}

BEGIN_MESSAGE_MAP(CHealthAmmoManaDlg, CDialogEx)
    ON_WM_HSCROLL()
    ON_WM_CLOSE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()


// CHealthAmmoManaDlg message handlers
void CHealthAmmoManaDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    UpdateData(TRUE);

    UINT Hp = m_Health.GetPos();
    UINT Ammo = m_AmmoMana.GetPos();

    m_ChromaSDKImpl.ShowLevel(m_DeviceType, Hp, Ammo);

    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CHealthAmmoManaDlg::OnDestroy()
{
    CDialogEx::OnDestroy();

    m_ChromaSDKImpl.ResetEffects(m_DeviceType);
}
