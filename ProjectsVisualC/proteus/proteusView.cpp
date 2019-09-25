// proteusView.cpp : implementation of the CProteusView class
//

#include "stdafx.h"
#include "proteus.h"

#include "proteusDoc.h"
#include "proteusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProteusView

IMPLEMENT_DYNCREATE(CProteusView, CView)

BEGIN_MESSAGE_MAP(CProteusView, CView)
	//{{AFX_MSG_MAP(CProteusView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProteusView construction/destruction

CProteusView::CProteusView()
{
	// TODO: add construction code here

}

CProteusView::~CProteusView()
{
}

BOOL CProteusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProteusView drawing

void CProteusView::OnDraw(CDC* pDC)
{
	CProteusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CProteusView printing

BOOL CProteusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProteusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProteusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CProteusView diagnostics

#ifdef _DEBUG
void CProteusView::AssertValid() const
{
	CView::AssertValid();
}

void CProteusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProteusDoc* CProteusView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProteusDoc)));
	return (CProteusDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProteusView message handlers
