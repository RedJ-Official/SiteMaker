// OptionPageEditing.cpp : implementation file
//

#include "pch.h"
#include "SiteMaker.h"
#include "afxdialogex.h"
#include "OptionPageEditing.h"


// COptionPageEditing dialog

IMPLEMENT_DYNAMIC(COptionPageEditing, CMFCPropertyPage)

COptionPageEditing::COptionPageEditing()
	: CMFCPropertyPage(IDD_PROPPAGE_EDITING, IDS_CAPTION_EDITING)
	, m_bAtomicSelection(FALSE)
	, m_bAutoURLDetectMode(FALSE)
	, m_nCSSEditingLevel(0)
	, m_bDisableEditFocusUI(FALSE)
	, m_bIE5PasteMode(FALSE)
	, m_bLiveResize(FALSE)
	, m_bMultiSelect(FALSE)
	, m_bRespectVisInDesign(FALSE)
	, m_bSilent(FALSE)
	, m_b2DPosition(FALSE)
{
}

COptionPageEditing::~COptionPageEditing()
{
}

void COptionPageEditing::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_2DPOS, m_b2DPosition);
	DDX_Check(pDX, IDC_CHECK_ATOMICSEL, m_bAtomicSelection);
	DDX_Check(pDX, IDC_CHECK_AUTOURL, m_bAutoURLDetectMode);
	DDX_Check(pDX, IDC_CHECK_DISABLEEDITFOCUSUI, m_bDisableEditFocusUI);
	DDX_Check(pDX, IDC_CHECK_IE5PASTE, m_bIE5PasteMode);
	DDX_Check(pDX, IDC_CHECK_LIVERESIZE, m_bLiveResize);
	DDX_Check(pDX, IDC_CHECK_MULTISEL, m_bMultiSelect);
	DDX_Check(pDX, IDC_CHECK_RESPECTVIS, m_bRespectVisInDesign);
	DDX_Check(pDX, IDC_CHECK_SILENT, m_bSilent);
	DDX_CBIndex(pDX, IDC_COMBO_CSSEDITLEVEL, m_nCSSEditingLevel);
}

void COptionPageEditing::SaveOptions(Options& options) const
{
	options.b2DPosition = m_b2DPosition;
	options.bAtomicSelection = m_bAtomicSelection;
	options.bAutoURLDetectMode = m_bAutoURLDetectMode;
	options.nCSSEditingLevel = m_nCSSEditingLevel;
	options.bDisableEditFocusUI = m_bDisableEditFocusUI;
	options.bIE5PasteMode = m_bIE5PasteMode;
	options.bLiveResize = m_bLiveResize;
	options.bMultiSelect = m_bMultiSelect;
	options.bRespectVisInDesign = m_bRespectVisInDesign;
	options.bSilent = m_bSilent;
}

void COptionPageEditing::LoadOptions(const Options& options)
{
	m_b2DPosition = options.b2DPosition;
	m_bAtomicSelection = options.bAtomicSelection;
	m_bAutoURLDetectMode = options.bAutoURLDetectMode;
	m_nCSSEditingLevel = options.nCSSEditingLevel;
	m_bDisableEditFocusUI = options.bDisableEditFocusUI;
	m_bIE5PasteMode = options.bIE5PasteMode;
	m_bLiveResize = options.bLiveResize;
	m_bMultiSelect = options.bMultiSelect;
	m_bRespectVisInDesign = options.bRespectVisInDesign;
	m_bSilent = options.bSilent;
}


BEGIN_MESSAGE_MAP(COptionPageEditing, CMFCPropertyPage)
	ON_BN_CLICKED(IDC_CHECK_2DPOS, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_ATOMICSEL, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_AUTOURL, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_DISABLEEDITFOCUSUI, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_IE5PASTE, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_LIVERESIZE, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_MULTISEL, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_RESPECTVIS, &OnCheckChange)
	ON_BN_CLICKED(IDC_CHECK_SILENT, &OnCheckChange)
	ON_CBN_SELCHANGE(IDC_COMBO_CSSEDITLEVEL, &OnCheckChange)
END_MESSAGE_MAP()

// COptionPageEditing message handlers

void COptionPageEditing::OnCheckChange()
{
	SetModified();
}
