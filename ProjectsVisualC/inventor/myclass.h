// myclass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// myclass dialog

class myclass : public CDialog
{
// Construction
public:
	myclass(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(myclass)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(myclass)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(myclass)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
