// DlgSettings.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSettings dialog

class CDlgSettings : public CDialog
{
// Construction
public:
	CDlgSettings(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSettings)
	enum { IDD = IDD_SETTINGS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSettings)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSettings)
	afx_msg void OnBallstick();
	afx_msg void OnCpk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
