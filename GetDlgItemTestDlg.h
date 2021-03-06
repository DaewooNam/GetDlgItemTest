
// GetDlgItemTestDlg.h: 헤더 파일
//

#pragma once

enum DLGTYPE{
	
	//첫페이지
	DT_ST_L_NAME, DT_BTN_START, DT_EIDT_NAME, DT_MAX1, 
	
	//두번째 페이지
	DT_ST_NAME=0,DT_ST_QUSEST, DT_RA_ANSWER1, DT_RA_ANSWER2, DT_RA_ANSWER3, DT_RA_ANSWER4,DT_BTN_NEXT, DT_MAX2
};


enum PAGETYPE { PT_LOGIN, PT_QUEST1,PT_MAX };





// CGetDlgItemTestDlg 대화 상자
class CGetDlgItemTestDlg : public CDialogEx
{


public:
	CWnd * m_DlgCtrl[PT_MAX][DT_MAX2];
	PAGETYPE m_enPageType;
	void TestFunc(void); // 빠른 정의 만들기 가능
	

// 생성입니다.
public:
	CGetDlgItemTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GETDLGITEMTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditName();
	afx_msg void OnBnClickedBtnStart();

	
	
};
