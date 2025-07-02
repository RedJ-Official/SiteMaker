
// SiteMakerView.h : interface of the CSiteMakerView class
//

#pragma once


class CSiteMakerView : public CHtmlEditView
{
protected: // create from serialization only
	CSiteMakerView() noexcept;
	DECLARE_DYNCREATE(CSiteMakerView)

// Attributes
public:
	CSiteMakerDoc* GetDocument() const;
	int m_nNavigationsLeft = 2;

// Operations
public:
	virtual void OnBeforeNavigate2(LPCTSTR lpszURL, DWORD nFlags, LPCTSTR lpszTargetFrameName, CByteArray& caPostedData, LPCTSTR lpszHeaders, BOOL* pbCancel);
	virtual void OnNavigateComplete2(LPCTSTR strURL);

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL CreateControlSite(COleControlContainer* pContainer, COleControlSite** ppSite, UINT nID, REFCLSID clsid);

// Implementation
public:
	virtual ~CSiteMakerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_DHTMLEDITING_CMDMAP(CSiteMakerView)
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SiteMakerView.cpp
inline CSiteMakerDoc* CSiteMakerView::GetDocument() const
   { return reinterpret_cast<CSiteMakerDoc*>(m_pDocument); }
#endif

