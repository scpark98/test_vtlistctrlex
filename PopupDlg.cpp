// PopupDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "test_vtlistctrlex.h"
#include "PopupDlg.h"
#include "afxdialogex.h"

#include "../../Common/RandomText.h"

// CPopupDlg 대화 상자

IMPLEMENT_DYNAMIC(CPopupDlg, CDialogEx)

CPopupDlg::CPopupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_POPUP, pParent)
{

}

CPopupDlg::~CPopupDlg()
{
}

void CPopupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
}


BEGIN_MESSAGE_MAP(CPopupDlg, CDialogEx)
END_MESSAGE_MAP()


// CPopupDlg 메시지 처리기


BOOL CPopupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	init_list();

	int i, index;

	for (i = 0; i < 100; i++)
	{
		index = m_list.add_item(i2S(i));
		m_list.set_text(index, list_name, RandomText::GetName());
		//m_list.set_text_color(index, 0, RGB(index, index, index));//random19937(RGB(0,0,0), RGB(255,255,255)));
		m_list.set_text(index, list_slogan, RandomText::GetSlogan());
		//m_list.set_text_color(index, index, RGB(indexi, 0, 0));//random19937(RGB(0,0,0), RGB(255,255,255)));
		m_list.set_text(index, list_score, i2S(random19937(0, 100)));
		//m_list.set_text_color(index, 2, RGB(0, 0, 255-index));//random19937(RGB(0,0,0), RGB(255,255,255)));
		m_list.set_text(index, list_memo, RandomText::GetName());
	}

	m_list.set_item_color(10, 1, red, blue);
	m_list.set_item_color(3, 0, deeppink, dodgerblue);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CPopupDlg::init_list()
{
	m_list.set_font_size(12);// theApp.GetProfileInt(_T("file list"), _T("font size"), 9));
	m_list.set_font_name(_T("맑은 고딕"));

	m_list.set_headings(_T("No,50;Name,150;Slogan,200;Score,100;Memo,200"));
	m_list.set_header_height(24);
	m_list.set_line_height(20);// theApp.GetProfileInt(_T("list name"), _T("line height"), 30));
	//m_list.set_color_theme(CVtListCtrlEx::color_theme_dark_gray);
	m_list.set_color_theme(CVtListCtrlEx::color_theme_light_blue);
	m_list.load_column_width(&theApp, _T("list name"));
	//m_list.set_column_text_align(0, HDF_CENTER);
	//m_list.set_column_text_align(0, HDF_CENTER);
	//m_list.set_column_text_align(1, HDF_CENTER);
	//m_list.set_column_text_align(2, HDF_CENTER);
	/*
	m_list.set_header_text_align(0, HDF_CENTER);
	m_list.set_header_text_align(1, HDF_CENTER);
	m_list.set_header_text_align(2, HDF_CENTER);
	m_list.set_header_text_align(3, HDF_LEFT);
	*/
	m_list.set_column_data_type(list_no, CVtListCtrlEx::column_data_type_numeric);
	m_list.set_column_data_type(list_score, CVtListCtrlEx::column_data_type_percentage_grid);
	m_list.allow_edit(true);
	m_list.allow_one_click_edit(true);
}
