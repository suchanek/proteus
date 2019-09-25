// myclass.cpp : implementation file
//

#include "stdafx.h"
#include "inventor.h"
#include "myclass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// myclass dialog


myclass::myclass(CWnd* pParent /*=NULL*/)
	: CDialog(myclass::IDD, pParent)
{
	//{{AFX_DATA_INIT(myclass)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void myclass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(myclass)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(myclass, CDialog)
	//{{AFX_MSG_MAP(myclass)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// myclass message handlers
