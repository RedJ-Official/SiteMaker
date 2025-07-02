#include "pch.h"
#include "SiteMakerDocHostUIHandler.h"

CSiteMakerDocHostUIHandler::CSiteMakerDocHostUIHandler()
    : m_refCount(1)
{
}

HRESULT CSiteMakerDocHostUIHandler::QueryInterface(REFIID riid, void** ppvObject)
{
    if (riid == IID_IDocHostUIHandler || riid == IID_IUnknown)
    {
        *ppvObject = this;
        AddRef();
        return S_OK;
    }
    *ppvObject = nullptr;
    return E_NOINTERFACE;
}

ULONG CSiteMakerDocHostUIHandler::AddRef()
{
    return ++m_refCount;
}

ULONG CSiteMakerDocHostUIHandler::Release()
{
    ULONG res = --m_refCount;
    if (res == 0)
        delete this;
    return res;
}

HRESULT CSiteMakerDocHostUIHandler::TranslateAccelerator(LPMSG lpMsg, const GUID* pguidCmdGroup, DWORD nCmdID)
{
    // Detect Ctrl+[A-Z] or Ctrl+[0-9]
    if (lpMsg->message != WM_CHAR && ((lpMsg->wParam >= 'A' && lpMsg->wParam <= 'Z') || (lpMsg->wParam >= '0' && lpMsg->wParam <= '9')) && GetKeyState(VK_CONTROL) & 0x8000)
    {
        // Suppress shortcut key
        return S_OK;
    }
    return S_FALSE;
}
