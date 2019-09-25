// DlgSettings.cpp : implementation file
//

#include "stdafx.h"
#include "dtest2.h"
#include "DlgSettings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSettings dialog


CDlgSettings::CDlgSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSettings::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSettings)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSettings)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSettings, CDialog)
	//{{AFX_MSG_MAP(CDlgSettings)
	ON_BN_CLICKED(IDC_BALLSTICK, OnBallstick)
	ON_BN_CLICKED(IDC_CPK, OnCpk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSettings message handlers

void CDlgSettings::OnBallstick() 
{
	// TODO: Add your control notification handler code here
	
}

void CDlgSettings::OnCpk() 
{
	// TODO: Add your control notification handler code here
	
}
