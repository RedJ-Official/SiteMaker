
// SiteMakerView.cpp : implementation of the CSiteMakerView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SiteMaker.h"
#endif

#include "SiteMakerDoc.h"
#include "SiteMakerView.h"
#include "SiteMakerDocHostUIHandler.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSiteMakerView

IMPLEMENT_DYNCREATE(CSiteMakerView, CHtmlEditView)

BEGIN_MESSAGE_MAP(CSiteMakerView, CHtmlEditView)
END_MESSAGE_MAP()

BEGIN_DHTMLEDITING_CMDMAP(CSiteMakerView)
	// Printing commands
	DHTMLEDITING_CMD_ENTRY(ID_FILE_PRINT, IDM_PRINT)
	DHTMLEDITING_CMD_ENTRY(ID_FILE_PRINT_PREVIEW, IDM_PRINTPREVIEW)
	DHTMLEDITING_CMD_ENTRY(ID_FILE_PAGE_SETUP, IDM_PAGESETUP)
	// Editing commands
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_UNDO, IDM_UNDO)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_REDO, IDM_REDO)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_COPY, IDM_COPY)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_CUT, IDM_CUT)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_PASTE, IDM_PASTE)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_CLEAR, IDM_DELETE)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_SELECT_ALL, IDM_SELECTALL)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_FIND, IDM_FIND)
	// Formatting commands
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_CHAR_BOLD, IDM_BOLD, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_CHAR_ITALIC, IDM_ITALIC, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_CHAR_UNDERLINE, IDM_UNDERLINE, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_CHAR_STRIKETHROUGH, IDM_STRIKETHROUGH, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_CHAR_SUPERSCRIPT, IDM_SUPERSCRIPT, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_CHAR_SUBSCRIPT, IDM_SUBSCRIPT, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY(ID_FORMAT_FONT, IDM_FONT)
	DHTMLEDITING_CMD_ENTRY(ID_FORMAT_REMOVE, IDM_REMOVEFORMAT)
	DHTMLEDITING_CMD_ENTRY(ID_LINK_HYPER, IDM_HYPERLINK)
	DHTMLEDITING_CMD_ENTRY(ID_LINK_UN, IDM_UNLINK)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_PARA_LEFT, IDM_JUSTIFYLEFT, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_PARA_CENTER, IDM_JUSTIFYCENTER, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_PARA_RIGHT, IDM_JUSTIFYRIGHT, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_PARA_NONE, IDM_JUSTIFYNONE, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_PARA_ULIST, IDM_UNORDERLIST, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_PARA_OLIST, IDM_ORDERLIST, AFX_UI_ELEMTYPE_CHECBOX)
	DHTMLEDITING_CMD_ENTRY(ID_PARA_INDENT, IDM_INDENT)
	DHTMLEDITING_CMD_ENTRY(ID_PARA_OUTDENT, IDM_OUTDENT)
	DHTMLEDITING_CMD_ENTRY(ID_INSERT_PARAGRAPH, IDM_PARAGRAPH)
	DHTMLEDITING_CMD_ENTRY(ID_INSERT_IMAGE, IDM_IMAGE)
	DHTMLEDITING_CMD_ENTRY(ID_INSERT_HR, IDM_HORIZONTALLINE)
	DHTMLEDITING_CMD_ENTRY(ID_INSERT_OBJECT, IDM_INSERTOBJECT)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_MODE_EDIT, IDM_EDITMODE, AFX_UI_ELEMTYPE_RADIO)
	DHTMLEDITING_CMD_ENTRY_TYPE(ID_MODE_VIEW, IDM_BROWSEMODE, AFX_UI_ELEMTYPE_RADIO)
END_DHTMLEDITING_CMDMAP()
// CSiteMakerView construction/destruction

CSiteMakerView::CSiteMakerView() noexcept
{
	// TODO: add construction code here

}

CSiteMakerView::~CSiteMakerView()
{
}

BOOL CSiteMakerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlEditView::PreCreateWindow(cs);
}

BOOL CSiteMakerView::CreateControlSite(COleControlContainer* pContainer, COleControlSite** ppSite, UINT nID, REFCLSID clsid)
{
	if (!CHtmlEditView::CreateControlSite(pContainer, ppSite, nID, clsid))
	{
		return FALSE;
	}

	

	return TRUE;
}


// CSiteMakerView diagnostics

#ifdef _DEBUG
void CSiteMakerView::AssertValid() const
{
	CHtmlEditView::AssertValid();
}

void CSiteMakerView::Dump(CDumpContext& dc) const
{
	CHtmlEditView::Dump(dc);
}

CSiteMakerDoc* CSiteMakerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSiteMakerDoc)));
	return (CSiteMakerDoc*)m_pDocument;
}
#endif //_DEBUG


// CSiteMakerView event handlers

void CSiteMakerView::OnBeforeNavigate2(LPCTSTR lpszURL, DWORD nFlags, LPCTSTR lpszTargetFrameName, CByteArray& caPostedData, LPCTSTR lpszHeaders, BOOL* pbCancel)
{
	if (m_nNavigationsLeft > 0)
	{
		m_nNavigationsLeft--;
		CHtmlEditView::OnBeforeNavigate2(lpszURL, nFlags, lpszTargetFrameName, caPostedData, lpszHeaders, pbCancel);
	}
	else
	{
		*pbCancel = TRUE;
	}
}

void CSiteMakerView::OnNavigateComplete2(LPCTSTR strURL)
{
	CHtmlEditView::OnNavigateComplete2(strURL);
	if (m_nNavigationsLeft == 1)
	{
		if (m_pBrowserApp)
		{
			CComPtr<IDispatch> spDispDoc;
			HRESULT hr = m_pBrowserApp->get_Document(&spDispDoc);
			if (SUCCEEDED(hr) && spDispDoc)
			{
				CComQIPtr<IHTMLDocument2> spHTMLDoc = spDispDoc;
				if (spHTMLDoc)
				{
					CComQIPtr<ICustomDoc> spCustomDoc = spHTMLDoc;
					if (spCustomDoc)
					{
						spCustomDoc->SetUIHandler(new CSiteMakerDocHostUIHandler());
					}
				}
			}
		}
	}
}


// CSiteMakerView message handlers
