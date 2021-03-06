
// GetDlgItemTestDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "GetDlgItemTest.h"
#include "GetDlgItemTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


struct DUMPRECT
{
	RECT rc;
	CWnd* pWindow;


};

enum DUMPTYPE { DPT_NAME, DPT_QUEST, DPT_ANSWER1, DPT_ANSWER2, DPT_ANSWER3, DPT_ANSWER4, DPT_NEXTBTN, DPT_MAX };

DUMPRECT g_DumpRectInfo[DPT_MAX];


char* g_pszQuest[5] = { "1.다음중 언어가 아닌것을 고르시오.",
"MFC","C++","C#","JAVA" };


CString g_strApply;





// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGetDlgItemTestDlg 대화 상자



void CGetDlgItemTestDlg::TestFunc(void)
{
	int aa = 0;
	aa++;

}

CGetDlgItemTestDlg::CGetDlgItemTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GETDLGITEMTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	
}

void CGetDlgItemTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGetDlgItemTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_NAME, &CGetDlgItemTestDlg::OnEnChangeEditName)
	ON_BN_CLICKED(IDC_BTN_START, &CGetDlgItemTestDlg::OnBnClickedBtnStart)
	
END_MESSAGE_MAP()


// CGetDlgItemTestDlg 메시지 처리기

BOOL CGetDlgItemTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	RECT rc;


	this ->GetClientRect(&rc); // this 값은 자기 클래스 주소

	TRACE("DlgRec(%d,%d,%d,%d)\n",rc.left,rc.top,rc.right,rc.bottom);

	SetWindowPos(NULL, 0, 0, rc.right / 2, rc.bottom / 2, SWP_SHOWWINDOW);// window 위치 및 크기 조절 가능


	// 모든 컨트롤 주소 저장
	/*
	for (int i = 0; i < DT_MAX1; i++)
	{
		m_DlgCtrl[i] = GetDlgItem(IDC_BTN_START + i);


	}
	*/	

	//초기화 하는 방법

	/*
	for (int j=0;j<PT_MAX;j++)
	{
		for (int i = 0; i < DT_MAX2; i++)
		{
			m_DlgCtrl[j][i] = NULL;

		}


	}
	*/
	
	/*
	//memset(C or C++) & zero memory(WIndow)
	*/
	//memset(m_DlgCtrl,0,sizeof(CWnd*)*PT_MAX*DT_MAX2);//memory overflow 주의 
	if (m_enPageType != PT_LOGIN) // 예외 처리 
	{
		AfxMessageBox("로그인 페이지가 아닙니다. ");
	}
	
	
	ZeroMemory(m_DlgCtrl,14);
	


	int nIdIndex = IDC_ST_L_NAME;

	for (int j = 0; j < PT_MAX; j++)
	{

		TestFunc();
		for (int i = 0; i < DT_MAX2; i++)
		{
			m_DlgCtrl[j][i] = GetDlgItem(nIdIndex);
			nIdIndex++;

			if (m_DlgCtrl[j][i] == NULL)
				break;
			else
				m_DlgCtrl[j][i]->ShowWindow(SW_HIDE);

		}

	}

	for (int i = 0; i < DT_MAX2; i++)
	{
		if (m_DlgCtrl[m_enPageType][i])
			m_DlgCtrl[m_enPageType][i]->ShowWindow(SW_SHOW);
	}


																		  
																		  
	// 버튼 비활성화
	//CButton
	
	/* 부모 값만 사용 가능
	
	CWnd* pbtn = GetDlgItem(IDC_BTN_START); //
	pbtn->EnableWindow(false);
	pbtn->SetWIndowtext
	*/
	
	
	// 부모 값 & 자식 값 사용 가능
	/*
	CButton* pBtn = (CButton*) GetDlgItem(IDC_BTN_START);// GetDlgItem 부모 주소를 반환하기 때문에 안되게 된다. 되게 할려면 Down Casting 값을 해주게 된다. 버튼이라는 값이 확실해야함
	pBtn->EnableWindow(false);
	pBtn->SetWindowText("응시자 입력");
	*/


	//enum 함수 사용해서 저장
	/*
	m_DlgCtrl[DT_BTN_START]->EnableWindow(false);
	m_DlgCtrl[DT_BTN_START]->SetWindowText("응시자 입력");
	*/

	m_DlgCtrl[m_enPageType][DT_BTN_START]->EnableWindow(false);
	m_DlgCtrl[m_enPageType][DT_BTN_START]->SetWindowText("응시자 입력");
	
	//덤프셋팅
	
	for (int i = 0; i < DPT_MAX; i++)
	{
		g_DumpRectInfo[i].pWindow = GetDlgItem(IDC_STD_QUEST +i);

		RECT rc;
		
		if (g_DumpRectInfo[i].pWindow)
		{
			g_DumpRectInfo[i].pWindow->GetWindowRect(&rc);
			g_DumpRectInfo[i].pWindow->ShowWindow(SW_HIDE);			
			ScreenToClient(&rc);

		
			g_DumpRectInfo[i].rc = rc;

		}

	}
	

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGetDlgItemTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGetDlgItemTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGetDlgItemTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGetDlgItemTestDlg::OnEnChangeEditName()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//모든 ID 값들에 변수들을 할당 하지 않고 ID 값만을 이용해서 control 가능



	//TRACE("OnEnChangeEditName()\n");

	/* 반복적으로 GetDlgItem 값을 만들어줌
	CWnd* pBtn = GetDlgItem(IDC_BTN_START);
	CWnd* pEdit = GetDlgItem(IDC_EDIT_NAME);

	
	CString str;
	pEdit->GetWindowText(str);
	
	if (str.IsEmpty())
	{
		pBtn->EnableWindow(false);
		pBtn->SetWindowText("응시자 입력");
	}
	else
	{
		pBtn->EnableWindow(true);
		pBtn->SetWindowText("시작");

	}
	*/

	//enum 함수를 사용
	
	if (m_enPageType != PT_LOGIN) // 예외 처리 
	{
		AfxMessageBox("로그인 페이지가 아닙니다. ");
	}



	
	m_DlgCtrl[m_enPageType][DT_EIDT_NAME]->GetWindowText(g_strApply);
	

	if (g_strApply.IsEmpty())
	{
		m_DlgCtrl[m_enPageType][DT_BTN_START]->EnableWindow(false);
		m_DlgCtrl[m_enPageType][DT_BTN_START]->SetWindowText("응시자 입력");
	}
	else
	{
		m_DlgCtrl[m_enPageType][DT_BTN_START]->EnableWindow(true);
		m_DlgCtrl[m_enPageType][DT_BTN_START]->SetWindowText("시작");

	}

	


	

}


void CGetDlgItemTestDlg::OnBnClickedBtnStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	// 첫번째 페이지 숨김
	for (int i = 0; i < DT_MAX1; i++)
	{

		if (m_DlgCtrl[m_enPageType][i])
		{

			m_DlgCtrl[m_enPageType][i]->ShowWindow(SW_HIDE);
		}
	}
	
	//두번째 페이지 시작
	m_enPageType = PT_QUEST1;

	
	for (int i = 0; i < DT_MAX2; i++)
	{

		if (m_DlgCtrl[m_enPageType][i])
		{
			
			m_DlgCtrl[m_enPageType][i]->SetWindowPos(NULL,g_DumpRectInfo[i].rc.left, g_DumpRectInfo[i].rc.top,0,0,SWP_SHOWWINDOW|SWP_NOSIZE);

		}



		//m_DlgCtrl[m_enPageType][i]->ShowWindow(SW_SHOW);

	}
	

	
	m_DlgCtrl[1][1]->ShowWindow(SW_SHOW);



	//m_DlgCtrl[m_enPageType][DT_ST_NAME]->ShowWindow(SW_SHOW);

	
	/*
	m_DlgCtrl[m_enPageType][DT_ST_NAME] -> SetWindowText(g_strApply);
	for (int i = DT_ST_QUSEST; i < DT_RA_ANSWER4; i++)
	{

		m_DlgCtrl[m_enPageType][i]->SetWindowText(g_pszQuest[i- DT_ST_QUSEST]);


		TRACE("%s\n",g_pszQuest[i - DT_ST_QUSEST]);

	}
	*/

}




