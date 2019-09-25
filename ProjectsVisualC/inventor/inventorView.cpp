// inventorView.cpp : implementation of the CInventorView class
//

#include "stdafx.h"
#include "inventor.h"

#include "inventorDoc.h"
#include "inventorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInventorView

IMPLEMENT_DYNCREATE(CInventorView, CView)

BEGIN_MESSAGE_MAP(CInventorView, CView)
	//{{AFX_MSG_MAP(CInventorView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInventorView construction/destruction

CInventorView::CInventorView()
{
	// TODO: add construction code here

}

CInventorView::~CInventorView()
{
}

BOOL CInventorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CInventorView drawing

void CInventorView::OnDraw(CDC* pDC)
{
	CInventorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CInventorView printing

BOOL CInventorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CInventorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CInventorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CInventorView diagnostics

#ifdef _DEBUG
void CInventorView::AssertValid() const
{
	CView::AssertValid();
}

void CInventorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CInventorDoc* CInventorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInventorDoc)));
	return (CInventorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInventorView message handlers
