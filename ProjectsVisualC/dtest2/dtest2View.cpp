// dtest2View.cpp : implementation of the CDtest2View class
//

#include "stdafx.h"
#include "dtest2.h"

#include "dtest2Doc.h"
#include "dtest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDtest2View

IMPLEMENT_DYNCREATE(CDtest2View, CView)

BEGIN_MESSAGE_MAP(CDtest2View, CView)
	//{{AFX_MSG_MAP(CDtest2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDtest2View construction/destruction

CDtest2View::CDtest2View()
{
	// TODO: add construction code here

}

CDtest2View::~CDtest2View()
{
}

BOOL CDtest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDtest2View drawing

void CDtest2View::OnDraw(CDC* pDC)
{
	CDtest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDtest2View printing

BOOL CDtest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDtest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDtest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDtest2View diagnostics

#ifdef _DEBUG
void CDtest2View::AssertValid() const
{
	CView::AssertValid();
}

void CDtest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDtest2Doc* CDtest2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDtest2Doc)));
	return (CDtest2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDtest2View message handlers
