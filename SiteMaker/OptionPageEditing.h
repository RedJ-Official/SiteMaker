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
	void SaveOptions(COptions& options) const;
	void LoadOptions(const COptions& options);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_LARGE };
#endif

protected:
	BOOL bAtomicSelection;
	BOOL bAutoURLDetectMode;
	SHORT nCSSEditingLevel;
	BOOL bDisableEditFocusUI;
	BOOL bIE5PasteMode;
	BOOL bLiveResize;
	BOOL bMultiSelect;
	BOOL bRespectVisInDesigner;
	BOOL bSilent;

protected:
	afx_msg void OnCheckChange();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
