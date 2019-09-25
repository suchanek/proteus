// proteusDoc.cpp : implementation of the CProteusDoc class
//

#include "stdafx.h"
#include "proteus.h"

#include "proteusDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProteusDoc

IMPLEMENT_DYNCREATE(CProteusDoc, CDocument)

BEGIN_MESSAGE_MAP(CProteusDoc, CDocument)
	//{{AFX_MSG_MAP(CProteusDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProteusDoc construction/destruction

CProteusDoc::CProteusDoc()
{
	// TODO: add one-time construction code here

}

CProteusDoc::~CProteusDoc()
{
}

BOOL CProteusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CProteusDoc serialization

void CProteusDoc::Serialize(CArchive& ar)
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
// CProteusDoc diagnostics

#ifdef _DEBUG
void CProteusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProteusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProteusDoc commands
