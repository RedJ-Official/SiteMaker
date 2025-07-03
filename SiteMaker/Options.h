#pragma once

#include "pch.h"
#include "framework.h"

class COptions
{
public:
	COptions();

public:
	BOOL bAtomicSelection;
	BOOL bAutoURLDetectMode;
	SHORT nCSSEditingLevel;
	BOOL bDisableEditFocusUI;
	BOOL bIE5PasteMode;
	BOOL bLiveResize;
	BOOL bMultiSelect;
	BOOL bRespectVisInDesigner;
	BOOL bShowAlignedSiteTags;
	BOOL bShowAllTags;
	BOOL bShowAreaTags;
	BOOL bShowBRTags;
	BOOL bShowCommentTags;
	BOOL bShowMiscTags;
	BOOL bShowScriptTags;
	BOOL bShowStyleTags;
	BOOL bShowUnknownTags;
	BOOL bSilent;
};

