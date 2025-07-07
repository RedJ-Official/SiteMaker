#pragma once
#include "afxdialogex.h"

#include "Options.h"

// COptionPageEditing dialog

class COptionPageEditing : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(COptionPageEditing)

public:
	COptionPageEditing();   // standard constructor
	virtual ~COptionPageEditing();

public:
	void SaveOptions(Options& options) const;
	void LoadOptions(const Options& options);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_EDITING };
#endif

protected:
	BOOL m_b2DPosition;
	BOOL m_bAtomicSelection;
	BOOL m_bAutoURLDetectMode;
	INT m_nCSSEditingLevel;
	BOOL m_bDisableEditFocusUI;
	BOOL m_bIE5PasteMode;
	BOOL m_bLiveResize;
	BOOL m_bMultiSelect;
	BOOL m_bRespectVisInDesign;
	BOOL m_bSilent;

protected:
	afx_msg void OnCheckChange();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
