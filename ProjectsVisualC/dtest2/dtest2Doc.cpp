// dtest2Doc.cpp : implementation of the CDtest2Doc class
//

#include "stdafx.h"
#include "dtest2.h"

#include "dtest2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDtest2Doc

IMPLEMENT_DYNCREATE(CDtest2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDtest2Doc, CDocument)
	//{{AFX_MSG_MAP(CDtest2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDtest2Doc construction/destruction

CDtest2Doc::CDtest2Doc()
{
	// TODO: add one-time construction code here

}

CDtest2Doc::~CDtest2Doc()
{
}

BOOL CDtest2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDtest2Doc serialization

void CDtest2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDtest2Doc diagnostics

#ifdef _DEBUG
void CDtest2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDtest2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDtest2Doc commands
