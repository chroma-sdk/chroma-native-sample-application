
// RazerChromaSampleApplication.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "RazerChromaSampleApplication.h"
#include "SampleApplicationPropertySheet.h"
#include "KeyboardPage.h"
#include "MousematPage.h"
#include "MicePage.h"
#include "HeadsetPage.h"
#include "KeypadPage.h"
#include "ChromaLinkPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRazerChromaSampleApplicationApp

BEGIN_MESSAGE_MAP(CRazerChromaSampleApplicationApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CRazerChromaSampleApplicationApp construction

CRazerChromaSampleApplicationApp::CRazerChromaSampleApplicationApp()
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}


// The one and only CRazerChromaSampleApplicationApp object

CRazerChromaSampleApplicationApp theApp;


// CRazerChromaSampleApplicationApp initialization

BOOL CRazerChromaSampleApplicationApp::InitInstance()
{
    // InitCommonControlsEx() is required on Windows XP if an application
    // manifest specifies use of ComCtl32.dll version 6 or later to enable
    // visual styles.  Otherwise, any window creation will fail.
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    // Set this to include all the common control classes you want to use
    // in your application.
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();

    AfxEnableControlContainer();

    // Create the shell manager, in case the dialog contains
    // any shell tree view or shell list view controls.
    CShellManager *pShellManager = new CShellManager;

    // Standard initialization
    // If you are not using these features and wish to reduce the size
    // of your final executable, you should remove from the following
    // the specific initialization routines you do not need
    // Change the registry key under which our settings are stored
    // TODO: You should modify this string to be something appropriate
    // such as the name of your company or organization
    SetRegistryKey(_T("Local AppWizard-Generated Applications"));

    CSampleApplicationPropertySheet dlg(_T("Razer Chroma SDK Sample Application"));

    dlg.m_psh.dwFlags &= ~PSH_HASHELP;
    dlg.m_psh.dwFlags |= PSH_NOAPPLYNOW;

    CKeyboardPage KeyboardPage;
    KeyboardPage.m_psp.dwFlags &= ~PSP_HASHELP | PSP_USETITLE;
    KeyboardPage.m_psp.pszTitle = _T("Keyboards");

    CMousematPage MousematPage;
    MousematPage.m_psp.dwFlags &= ~PSP_HASHELP | PSP_USETITLE;
    MousematPage.m_psp.pszTitle = _T("Mousemats");

    CMicePage MicePage;
    MicePage.m_psp.dwFlags &= ~PSP_HASHELP | PSP_USETITLE;
    MicePage.m_psp.pszTitle = _T("Mice");

    CHeadsetPage HeadsetPage;
    HeadsetPage.m_psp.dwFlags &= ~PSP_HASHELP | PSP_USETITLE;
    HeadsetPage.m_psp.pszTitle = _T("Headsets");

    CKeypadPage KeypadPage;
    KeypadPage.m_psp.dwFlags &= ~PSP_HASHELP | PSP_USETITLE;
    KeypadPage.m_psp.pszTitle = _T("Keypads");

    CChromaLinkPage ChromaLinkPage;
    ChromaLinkPage.m_psp.dwFlags &= ~PSP_HASHELP | PSP_USETITLE;
    ChromaLinkPage.m_psp.pszTitle = _T("Chroma Linked Devices");

    dlg.AddPage(&KeyboardPage);
    dlg.AddPage(&MousematPage);
    dlg.AddPage(&MicePage);
    dlg.AddPage(&HeadsetPage);
    dlg.AddPage(&KeypadPage);
    dlg.AddPage(&ChromaLinkPage);

    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with OK
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with Cancel
    }

    // Delete the shell manager created above.
    if (pShellManager != NULL)
    {
        delete pShellManager;
    }

    // Since the dialog has been closed, return FALSE so that we exit the
    //  application, rather than start the application's message pump.
    return FALSE;
}

