// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// polyline-chessView.cpp : CpolylinechessView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "polyline-chess.h"
#endif

#include "polyline-chessDoc.h"
#include "polyline-chessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpolylinechessView

IMPLEMENT_DYNCREATE(CpolylinechessView, CView)

BEGIN_MESSAGE_MAP(CpolylinechessView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CpolylinechessView ����/����

CpolylinechessView::CpolylinechessView()
{
	// TODO:  �ڴ˴���ӹ������

}

CpolylinechessView::~CpolylinechessView()
{
}

BOOL CpolylinechessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CpolylinechessView ����

void CpolylinechessView::OnDraw(CDC* /*pDC*/)
{
	CpolylinechessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CpolylinechessView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CpolylinechessView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CpolylinechessView ���

#ifdef _DEBUG
void CpolylinechessView::AssertValid() const
{
	CView::AssertValid();
}

void CpolylinechessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CpolylinechessDoc* CpolylinechessView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CpolylinechessDoc)));
	return (CpolylinechessDoc*)m_pDocument;
}
#endif //_DEBUG


// CpolylinechessView ��Ϣ�������
