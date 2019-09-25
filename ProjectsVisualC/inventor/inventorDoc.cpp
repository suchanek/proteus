// inventorDoc.cpp : implementation of the CInventorDoc class
//

#include "stdafx.h"
#include "inventor.h"

#include "inventorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInventorDoc

IMPLEMENT_DYNCREATE(CInventorDoc, CDocument)

BEGIN_MESSAGE_MAP(CInventorDoc, CDocument)
	//{{AFX_MSG_MAP(CInventorDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInventorDoc construction/destruction

CInventorDoc::CInventorDoc()
{
	// TODO: add one-time construction code here

}

CInventorDoc::~CInventorDoc()
{
}

BOOL CInventorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CInventorDoc serialization

void CInventorDoc::Serialize(CArchive& ar)
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
// CInventorDoc diagnostics

#ifdef _DEBUG
void CInventorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInventorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInventorDoc commands
