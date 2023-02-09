#pragma once

#include "../../Common/CListCtrl/CVtListCtrlEx/VtListCtrlEx.h"

// CPopupDlg 대화 상자

class CPopupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPopupDlg)

public:
	CPopupDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPopupDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POPUP };
#endif

	enum list_column
	{
		list_no = 0,
		list_name,
		list_slogan,
		list_score,
		list_memo,
	};
	void init_list();


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CVtListCtrlEx m_list;
	virtual BOOL OnInitDialog();
};
