// OptionPageEditing.cpp : implementation file
//

#include "pch.h"
#include "SiteMaker.h"
#include "afxdialogex.h"
#include "OptionPageEditing.h"


// COptionPageEditing dialog

IMPLEMENT_DYNAMIC(COptionPageEditing, CMFCPropertyPage)

COptionPageEditing::COptionPageEditing()
	: CMFCPropertyPage(IDD_PROPPAGE_LARGE, IDS_CAPTION_EDITING)
	, bAtomicSelection(FALSE)
	, bAutoURLDetectMode(FALSE)
	, nCSSEditingLevel(0)
	, bDisableEditFocusUI(FALSE)
	, bIE5PasteMode(FALSE)
	, bLiveResize(FALSE)
	, bMultiSelect(FALSE)
	, bRespectVisInDesigner(FALSE)
	, bSilent(FALSE)
{
}

COptionPageEditing::~COptionPageEditing()
{
}

void COptionPageEditing::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ATOMICSEL, bAtomicSelection);
	DDX_Check(pDX, IDC_CHECK_AUTOURL, bAutoURLDetectMode);
	DDX_Check(pDX, IDC_CHECK_DISABLEEDITFOCUSUI, bDisableEditFocusUI);
	DDX_Check(pDX, IDC_CHECK_IE5PASTE, bIE5PasteMode);
	DDX_Check(pDX, IDC_CHECK_LIVERESIZE, bLiveResize);
	DDX_Check(pDX, IDC_CHECK_MULTISEL, bMultiSelect);
	DDX_Check(pDX, IDC_CHECK_RESPECTVIS, bRespectVisInDesigner);
	DDX_Check(pDX, IDC_CHECK_SILENT, bSilent);
}

void COptionPageEditing::SaveOptions(COptions& options) const
{
	options.bAtomicSelection = bAtomicSelection;
	options.bAutoURLDetectMode = bAutoURLDetectMode;
	options.nCSSEditingLevel = nCSSEditingLevel;
	options.bDisableEditFocusUI = bDisableEditFocusUI;
	options.bIE5PasteMode = bIE5PasteMode;
	options.bLiveResize = bLiveResize;
	options.bMultiSelect = bMultiSelect;
	options.bRespectVisInDesigner = bRespectVisInDesigner;
	options.bSilent = bSilent;
}

void COptionPageEditing::LoadOptions(const COptions& options)
{
	bAtomicSelection = options.bAtomicSelection;
	bAutoURLDetectMode = options.bAutoURLDetectMode;
	nCSSEditingLevel = options.nCSSEditingLevel;
	bDisableEditFocusUI = options.bDisableEditFocusUI;
	bIE5PasteMode = options.bIE5PasteMode;
	bLiveResize = options.bLiveResize;
	bMultiSelect = options.bMultiSelect;
	bRespectVisInDesigner = options.bRespectVisInDesigner;
	bSilent = options.bSilent;
}


BEGIN_MESSAGE_MAP(COptionPageEditing, CMFCPropertyPage)
	ON_BN_CLICKED(IDC_CHECK_ATOMICSEL, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_AUTOURL, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_DISABLEEDITFOCUSUI, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_IE5PASTE, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_LIVERESIZE, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_MULTISEL, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_RESPECTVIS, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_SILENT, &OnCheckChange)
END_MESSAGE_MAP()

// COptionPageEditing message handlers

void COptionPageEditing::OnCheckChange()
{
	SetModified();
}
