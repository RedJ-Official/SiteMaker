
// SiteMaker.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "SiteMaker.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "SiteMakerDoc.h"
#include "SiteMakerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSiteMakerApp

BEGIN_MESSAGE_MAP(CSiteMakerApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CSiteMakerApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CSiteMakerApp construction

CSiteMakerApp::CSiteMakerApp() noexcept
{
	m_bHiColorIcons = TRUE;


	m_nAppLook = 0;
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("RedJ.SiteMaker.2"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CSiteMakerApp object

CSiteMakerApp theApp;


// CSiteMakerApp initialization

BOOL CSiteMakerApp::InitInstance()
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

	CWinAppEx::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("RedJ"));
	LoadStdProfileSettings(10);  // Load standard INI file options (including MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_SiteMakerTYPE,
		RUNTIME_CLASS(CSiteMakerDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CSiteMakerView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CSiteMakerApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CSiteMakerApp message handlers

void CSiteMakerApp::OnOptionsChanged()
{

}


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	afx_msg void OnNMClickSyslinkHomepage(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_HOMEPAGE, &CAboutDlg::OnNMClickSyslinkHomepage)
	ON_NOTIFY(NM_RETURN, IDC_SYSLINK_HOMEPAGE, &CAboutDlg::OnNMClickSyslinkHomepage)
END_MESSAGE_MAP()

void CAboutDlg::OnNMClickSyslinkHomepage(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLINK* pNMLink = (NMLINK*)pNMHDR;
	ShellExecute(NULL, _T("open"), pNMLink->item.szUrl, NULL, NULL, SW_SHOW);
	*pResult = 0;
}

// App command to run the dialog
void CSiteMakerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CSiteMakerApp customization load/save methods

void CSiteMakerApp::PreLoadState()
{
}

void CSiteMakerApp::LoadCustomState()
{
	m_options.b2DPosition = GetInt(_T("2DPosition"), m_options.b2DPosition);
	m_options.bAtomicSelection = GetInt(_T("AtomicSelection"), m_options.bAtomicSelection);
	m_options.bAutoURLDetectMode = GetInt(_T("AutoURLDetectMode"), m_options.bAutoURLDetectMode);
	m_options.nCSSEditingLevel = GetInt(_T("CSSEditingLevel"), m_options.nCSSEditingLevel);
	m_options.bDisableEditFocusUI = GetInt(_T("DisableEditFocusUI"), m_options.bDisableEditFocusUI);
	m_options.bIE5PasteMode = GetInt(_T("IE5PasteMode"), m_options.bIE5PasteMode);
	m_options.bLiveResize = GetInt(_T("LiveResize"), m_options.bLiveResize);
	m_options.bMultiSelect = GetInt(_T("MultiSelect"), m_options.bMultiSelect);
	m_options.bRespectVisInDesign = GetInt(_T("RespectVisInDesign"), m_options.bRespectVisInDesign);
	m_options.bSilent = GetInt(_T("Silent"), m_options.bSilent);
}

void CSiteMakerApp::SaveCustomState()
{
	WriteInt(_T("2DPosition"), m_options.b2DPosition);
	WriteInt(_T("AtomicSelection"), m_options.bAtomicSelection);
	WriteInt(_T("AutoURLDetectMode"), m_options.bAutoURLDetectMode);
	WriteInt(_T("CSSEditingLevel"), m_options.nCSSEditingLevel);
	WriteInt(_T("DisableEditFocusUI"), m_options.bDisableEditFocusUI);
	WriteInt(_T("IE5PasteMode"), m_options.bIE5PasteMode);
	WriteInt(_T("LiveResize"), m_options.bLiveResize);
	WriteInt(_T("MultiSelect"), m_options.bMultiSelect);
	WriteInt(_T("RespectVisInDesign"), m_options.bRespectVisInDesign);
	WriteInt(_T("Silent"), m_options.bSilent);
}

// CSiteMakerApp message handlers



