
// SiteMaker.h : main header file for the SiteMaker application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

#include "Options.h"

// CSiteMakerApp:
// See SiteMaker.cpp for the implementation of this class
//

class CSiteMakerApp : public CWinAppEx
{
public:
	CSiteMakerApp() noexcept;

public:
	virtual void OnOptionsChanged();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;
	Options m_options;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSiteMakerApp theApp;
