#include "pch.h"
#include "OptionSheet.h"
#include "resource.h"

COptionSheet::COptionSheet(CWnd* pParentWnd, UINT iSelectPage)
	: CMFCPropertySheet(IDS_CAPTION_OPTIONS, pParentWnd, iSelectPage)
	, m_pageEditing()
{
	AddPage(&m_pageEditing);
}

void COptionSheet::SaveOptions(COptions& options) const
{
	m_pageEditing.SaveOptions(options);
}

void COptionSheet::LoadOptions(const COptions& options)
{
	m_pageEditing.LoadOptions(options);
}


BEGIN_MESSAGE_MAP(COptionSheet, CMFCPropertySheet)
	ON_COMMAND(ID_APPLY_NOW, &OnApply)
END_MESSAGE_MAP()

void COptionSheet::OnApply()
{
	
}
