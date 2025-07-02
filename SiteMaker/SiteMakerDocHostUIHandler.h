#pragma once
#include <afxhtml.h>

class CSiteMakerDocHostUIHandler :
    public IDocHostUIHandler
{
public:
    CSiteMakerDocHostUIHandler();

    // IUnknown
    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObject) override;
    STDMETHOD_(ULONG, AddRef)() override;
    STDMETHOD_(ULONG, Release)() override;

    // IDocHostUIHandler methods
    STDMETHOD(TranslateAccelerator)(LPMSG lpMsg, const GUID* pguidCmdGroup, DWORD nCmdID) override;

    // Other methods must be implemented or stubbed (return S_OK/E_NOTIMPL)
    STDMETHOD(ShowContextMenu)(DWORD, POINT*, IUnknown*, IDispatch*) { return E_NOTIMPL; }
    STDMETHOD(GetHostInfo)(DOCHOSTUIINFO*) { return E_NOTIMPL; }
    STDMETHOD(ShowUI)(DWORD, IOleInPlaceActiveObject*, IOleCommandTarget*, IOleInPlaceFrame*, IOleInPlaceUIWindow*) { return E_NOTIMPL; }
    STDMETHOD(HideUI)() { return S_OK; }
    STDMETHOD(UpdateUI)() { return S_OK; }
    STDMETHOD(EnableModeless)(BOOL) { return S_OK; }
    STDMETHOD(OnDocWindowActivate)(BOOL) { return S_OK; }
    STDMETHOD(OnFrameWindowActivate)(BOOL) { return S_OK; }
    STDMETHOD(ResizeBorder)(LPCRECT, IOleInPlaceUIWindow*, BOOL) { return S_OK; }
    STDMETHOD(GetOptionKeyPath)(LPOLESTR*, DWORD) { return E_NOTIMPL; }
    STDMETHOD(GetDropTarget)(IDropTarget*, IDropTarget**) { return E_NOTIMPL; }
    STDMETHOD(GetExternal)(IDispatch**) { return E_NOTIMPL; }
    STDMETHOD(TranslateUrl)(DWORD, OLECHAR*, OLECHAR**) { return E_NOTIMPL; }
    STDMETHOD(FilterDataObject)(IDataObject*, IDataObject**) { return E_NOTIMPL; }

private:
    ULONG m_refCount;
};

