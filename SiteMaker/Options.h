#pragma once

#include "pch.h"
#include "framework.h"

class Options
{
public:
	Options();

public:
	BOOL b2DPosition = FALSE;
	BOOL bAtomicSelection = FALSE;
	BOOL bAutoURLDetectMode = TRUE;
	SHORT nCSSEditingLevel = 1;
	BOOL bDisableEditFocusUI = FALSE;
	BOOL bIE5PasteMode = FALSE;
	BOOL bLiveResize = TRUE;
	BOOL bMultiSelect = FALSE;
	BOOL bRespectVisInDesign = FALSE;
	BOOL bShowAlignedSiteTags = FALSE;
	BOOL bShowAllTags = FALSE;
	BOOL bShowAreaTags = FALSE;
	BOOL bShowBRTags = FALSE;
	BOOL bShowCommentTags = FALSE;
	BOOL bShowMiscTags = FALSE;
	BOOL bShowScriptTags = FALSE;
	BOOL bShowStyleTags = FALSE;
	BOOL bShowUnknownTags = FALSE;
	BOOL bSilent = FALSE;
};

