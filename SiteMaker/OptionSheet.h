#pragma once
#include <afxpropertysheet.h>

#include "Options.h"
#include "OptionPageEditing.h"

class COptionSheet :
    public CMFCPropertySheet
{
// Construction
public:
    COptionSheet(CWnd* pParentWnd, UINT iSelectPage = 0U);

// Operations
public:
	void SaveOptions(COptions& options) const;
	void LoadOptions(const COptions& options);

// Attributes
public:
	COptionPageEditing m_pageEditing;

// Message Map
protected:
	afx_msg void OnApply();

	DECLARE_MESSAGE_MAP()
};

