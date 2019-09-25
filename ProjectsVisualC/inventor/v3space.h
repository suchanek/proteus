#ifndef __V3SPACE_H__
#define __V3SPACE_H__

// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CV3Space wrapper class

class CV3Space : public CWnd
{
protected:
	DECLARE_DYNCREATE(CV3Space)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x232ab9b5, 0xb045, 0x11ce, { 0x88, 0x22, 0x0, 0x40, 0x5, 0x15, 0x41, 0x24 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	BOOL GetAutoClipping();
	void SetAutoClipping(BOOL);
	long GetBufferingType();
	void SetBufferingType(long);
	BOOL GetDetailSeekOn();
	void SetDetailSeekOn(BOOL);
	long GetFeedbackSize();
	void SetFeedbackSize(long);
	BOOL GetFeedbackVisibility();
	void SetFeedbackVisibility(BOOL);
	BOOL GetHeadlightOn();
	void SetHeadlightOn(BOOL);
	BOOL GetPopupMenuEnabled();
	void SetPopupMenuEnabled(BOOL);
	float GetSeekTime();
	void SetSeekTime(float);
	BOOL GetViewingOn();
	void SetViewingOn(BOOL);
	long GetInteractiveDrawStyle();
	void SetInteractiveDrawStyle(long);
	long GetStillDrawStyle();
	void SetStillDrawStyle(long);
	long GetViewerType();
	void SetViewerType(long);
	CString GetWwwDdeServiceName();
	void SetWwwDdeServiceName(LPCTSTR);
	BOOL GetDecorationOn();
	void SetDecorationOn(BOOL);
	BOOL GetWwwEnable();
	void SetWwwEnable(BOOL);
	BOOL GetUrlPickEnable();
	void SetUrlPickEnable(BOOL);
	BOOL GetSelectionEnable();
	void SetSelectionEnable(BOOL);
	BOOL GetRememberLastFile();
	void SetRememberLastFile(BOOL);
	CString GetLastFileName();
	void SetLastFileName(LPCTSTR);
	CString GetStartFileName();
	void SetStartFileName(LPCTSTR);
	BOOL GetSerializeSceneGraph();
	void SetSerializeSceneGraph(BOOL);
	CString GetText3d();
	void SetText3d(LPCTSTR);
	float GetText3dRotationX();
	void SetText3dRotationX(float);
	float GetText3dRotationY();
	void SetText3dRotationY(float);
	float GetText3dRotationZ();
	void SetText3dRotationZ(float);
	BOOL GetText3dEnable();
	void SetText3dEnable(BOOL);
	BOOL GetText3dSpinEnable();
	void SetText3dSpinEnable(BOOL);
	float GetText3dRed();
	void SetText3dRed(float);
	float GetText3dGreen();
	void SetText3dGreen(float);
	float GetText3dBlue();
	void SetText3dBlue(float);
	float GetText3dSpeedX();
	void SetText3dSpeedX(float);
	float GetText3dSpeedY();
	void SetText3dSpeedY(float);
	float GetText3dSpeedZ();
	void SetText3dSpeedZ(float);
	long GetText3dParts();
	void SetText3dParts(long);
	long GetText3dJustification();
	void SetText3dJustification(long);
	float GetText3dComplexity();
	void SetText3dComplexity(float);
	CString GetText3dFontName();
	void SetText3dFontName(LPCTSTR);
	float GetText3dFontSize();
	void SetText3dFontSize(float);
	BOOL GetFog();
	void SetFog(BOOL);
	BOOL GetAntiAliasing();
	void SetAntiAliasing(BOOL);
	long GetTransparencyType();
	void SetTransparencyType(long);
	long GetSelectionMethod();
	void SetSelectionMethod(long);
	long GetManipulatorType();
	void SetManipulatorType(long);
	long GetLastFileType();
	void SetLastFileType(long);
	float GetDxfAmbientScaleR();
	void SetDxfAmbientScaleR(float);
	float GetDxfAmbientScaleG();
	void SetDxfAmbientScaleG(float);
	float GetDxfAmbientScaleB();
	void SetDxfAmbientScaleB(float);
	float GetDxfEmissiveScaleR();
	void SetDxfEmissiveScaleR(float);
	float GetDxfEmissiveScaleG();
	void SetDxfEmissiveScaleG(float);
	float GetDxfEmissiveScaleB();
	void SetDxfEmissiveScaleB(float);
	float GetDxfSpecularR();
	void SetDxfSpecularR(float);
	float GetDxfSpecularG();
	void SetDxfSpecularG(float);
	float GetDxfSpecularB();
	void SetDxfSpecularB(float);
	long GetDxfVertexOrdering();
	void SetDxfVertexOrdering(long);
	long GetDxfShapeType();
	void SetDxfShapeType(long);
	long GetDxfFaceType();
	void SetDxfFaceType(long);
	float GetDxfCreaseAngle();
	void SetDxfCreaseAngle(float);
	BOOL GetDragDropEnable();
	void SetDragDropEnable(BOOL);
	BOOL GetExtendedPopupEnable();
	void SetExtendedPopupEnable(BOOL);
	BOOL GetNotifyUrlPicked();
	void SetNotifyUrlPicked(BOOL);
	BOOL GetNotifyContainerUrlPicked();
	void SetNotifyContainerUrlPicked(BOOL);
	BOOL GetNotifyUpdatePickUrlName();
	void SetNotifyUpdatePickUrlName(BOOL);
	CString GetHtmlKey();
	void SetHtmlKey(LPCTSTR);
	CString GetUrl();
	void SetUrl(LPCTSTR);
	BOOL GetUrlLoadAsync();
	void SetUrlLoadAsync(BOOL);
	float GetBgColorRed();
	void SetBgColorRed(float);
	float GetBgColorGreen();
	void SetBgColorGreen(float);
	float GetBgColorBlue();
	void SetBgColorBlue(float);
	BOOL GetDollyCameraSmooth();
	void SetDollyCameraSmooth(BOOL);

// Operations
public:
	void EditAmbientLight();
	void EditBackgroundColor();
	void EditCameras();
	void EditLights();
	void EditLightColor(long lLightId);
	void EditSelectionMaterial();
	void EditSelectionColor();
	BOOL ImportFile();
	BOOL OpenFile();
	void SelectViewer();
	BOOL copyCamera(LPDISPATCH nDstId, LPDISPATCH nSrcId);
	long createDirectLight(LPCTSTR lpszLightName);
	long createPointLight(LPCTSTR lpszLightName);
	long createSpotLight(LPCTSTR lpszLightName);
	BOOL deleteCamera(LPDISPATCH nCameraId);
	void deleteSceneGraph();
	void deleteLight(long lLightId);
	void editCopy();
	void editCut();
	void editDelete();
	void editSelectAll();
	void editPaste();
	long getFeedbackSize();
	long getBufferingType();
	long getFirstLight();
	void getLightColor(long lLightId, float* lpfRed, float* lpfGreen, float* lpdBlue);
	void getLightIntensity(long lLightId, float* lpfIntensity);
	CString getLightName(long lLightId);
	long getLightId(LPCTSTR lpszLightName);
	void getLightDirection(long lLightId, float* lpfX, float* lpfY, float* lpfZ);
	float getLightDropOffRate(long lLightId);
	void getLightLocation(long lLightId, float* lpfX, float* lpfY, float* lpfZ);
	long getLightType(long lLightId);
	long getNextLight(long lLightId);
	long getNumCameras();
	long getNumSelected();
	float getSeekTime();
	long getViewerType();
	void hideAllLights();
	BOOL importSceneGraph(LPCTSTR lpszFileName);
	BOOL isAutoClipping();
	BOOL isDecorating();
	BOOL isDetailSeek();
	BOOL isFeedbackVisible();
	BOOL isHeadlight();
	BOOL isLightOn(long nLightId);
	BOOL isPopupMenuEnabled();
	BOOL isViewing();
	BOOL isWWWEnable();
	BOOL isUrlPickEnable();
	BOOL isSelectionEnable();
	BOOL readSceneGraph(LPCTSTR lpszFileName);
	void resetToHomePositon();
	void SaveFile();
	void saveHomePosition();
	void saveSceneGraph(LPCTSTR fileName, BOOL bVrmlHeader);
	void SelectViewpoint();
	void setAutoClipping(BOOL onOrOff);
	void setCurrentCamera(LPDISPATCH lCameraId);
	void setLightColor(long lLightId, float fRed, float fGreen, float fBlue);
	void setLightIntensity(long lLightId, float fIntensity);
	void setLightName(long lLightId, LPCTSTR lpszLightName);
	void setLightDirection(long lLightId, float fX, float fY, float fZ);
	void setLightLocation(long lLightId, float fX, float fY, float fZ);
	void setLightDropOffRate(long lLightId, float fDropRate);
	void setDetailSeek(BOOL onOrOff);
	void setHeadlight(BOOL onOrOff);
	void setSeekTime(float seconds);
	void setViewing(BOOL onOrOff);
	void setBufferingType(long lBufferType);
	void setCenterballManip();
	void setHandleboxManip();
	void setJackManip();
	void setNoneManip();
	void setReplaceAllManip();
	void setTabboxManip();
	void setTrackballManip();
	void setFeedbackSize(long lFeedbackSize);
	void setExaminerViewer();
	void setFlyViewer();
	void setWalkViewer();
	void setPlaneViewer();
	void setTransformBoxManip();
	void setFog(BOOL nOnOff);
	void setAntialiasing(BOOL nOnOff);
	void setTransparencyType(long lTranType);
	void setViewerType(long lViewerType);
	void setSelectionMethod(long lSelectMethod);
	void setWWWEnable(BOOL bEnable);
	void setUrlPickEnable(BOOL bEnable);
	void setSelectionEnable(BOOL bEnable);
	void showAllLights();
	void stopAnimating();
	void turnOnLight(long lLightId);
	void turnOffLight(long lLightId);
	BOOL validateLightId(long lLightId);
	void viewAll();
	void setInteractiveDrawStyle(long lDrawStyle);
	long getInteractiveDrawStyle();
	void setStillDrawStyle(long lDrawStyle);
	long getStillDrawStyle();
	void setFeedbackVisibility(BOOL nVisible);
	void setPopupMenuEnabled(BOOL nEnabled);
	void EditHeadlight();
	void viewSelection();
	void serializeControl(VARIANT* pArchive);
	BOOL readSceneGraphEx(LPCTSTR lpszFileName, long nFileType);
	BOOL importSceneGraphEx(LPCTSTR lpszFileName, long nFileType);
	BOOL serializeSceneGraphEx(VARIANT* pArchive, BOOL bVrmlHeader);
	BOOL isValidFile(LPCTSTR lpszFileName);
	BOOL isValidFileEx(VARIANT* pArchive);
	void EditDxfProperties();
	void EditSceneGraph();
	void sgeHighlightSelection();
	LPDISPATCH getSceneRoot();
	LPDISPATCH GetIDispatch();
	LPDISPATCH CreateIDispatchObject(LPCTSTR progID);
	LPDISPATCH getCameraIDispatch(long nCameraId);
	LPDISPATCH getLightManipIDispatch(long nLightId);
	void setDecorations(BOOL onOrOff);
	void stopDollyCamera();
	BOOL isDollyCamera();
	void dollyCamera(LPDISPATCH nCameraId, double interval, BOOL dollyCameraComplete);
	void SoDBSetDelaySensorTimeout(double timeout);
	BOOL Play(LPCTSTR fileName, long options);
	LPDISPATCH getViewportRegion();
	LPDISPATCH getEntireSceneGraph();
	CString getRegistryDataPath();
	LPDISPATCH createPerspectiveCamera(LPCTSTR lpszCameraName);
	LPDISPATCH getCurrentCamera();
	LPDISPATCH createOrthographicCamera(LPCTSTR lpszCameraName);
	BOOL setCameraByIndex(long index);
	void setSceneRoot(LPDISPATCH root);
	BOOL setRegistryDataPath(LPCTSTR newPath);
	LPDISPATCH SoDBGetGlobalField(LPCTSTR fieldName);
	void setGLRenderAction(LPDISPATCH boxHighlightRenderAction);
	LPDISPATCH getGLRenderAction();
	void AboutBox();
};

#endif // __V3SPACE_H__