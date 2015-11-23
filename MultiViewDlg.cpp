
// MultiViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiView.h"
#include "MultiViewDlg.h"
#include "afxdialogex.h"
#include "global.h"
#include "TimeMeasure.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//Mat pImageBuf_map_mat0;
//Mat pImageBuf_map_mat_dstmap0;
//Mat pImageBuf_map_mat_dstmap_weight0;
//Mat roi_pImageBuf_map_mat_dstmap0;
//Mat roi_pImageBuf_map_mat_dstmap_weight0;
//
//Mat pImageBuf_map_mat1;
//Mat pImageBuf_map_mat_dstmap1;
//Mat pImageBuf_map_mat_dstmap_weight1;
//Mat roi_pImageBuf_map_mat_dstmap1;
//Mat roi_pImageBuf_map_mat_dstmap_weight1;
//
//Mat pImageBuf_map_mat2;
//Mat pImageBuf_map_mat_dstmap2;
//Mat pImageBuf_map_mat_dstmap_weight2;
//Mat roi_pImageBuf_map_mat_dstmap2;
//Mat roi_pImageBuf_map_mat_dstmap_weight2;
//
//Mat pImageBuf_map_mat3;
//Mat pImageBuf_map_mat_dstmap3;
//Mat pImageBuf_map_mat_dstmap_weight3;
//Mat roi_pImageBuf_map_mat_dstmap3;
//Mat roi_pImageBuf_map_mat_dstmap_weight3;
//
//Mat pImageBuf_map_mat4;
//Mat pImageBuf_map_mat_dstmap4;
//Mat pImageBuf_map_mat_dstmap_weight4;
//Mat roi_pImageBuf_map_mat_dstmap4;
//Mat roi_pImageBuf_map_mat_dstmap_weight4;
//
//Mat pImageBuf_map_mat5;
//Mat pImageBuf_map_mat_dstmap5;
//Mat pImageBuf_map_mat_dstmap_weight5;
//Mat roi_pImageBuf_map_mat_dstmap5;
//Mat roi_pImageBuf_map_mat_dstmap_weight5;
//
//Mat pImageBuf_map_mat6;
//Mat pImageBuf_map_mat_dstmap6;
//Mat pImageBuf_map_mat_dstmap_weight6;
//Mat roi_pImageBuf_map_mat_dstmap6;
//Mat roi_pImageBuf_map_mat_dstmap_weight6;
//
//Mat pImageBuf_map_mat7;
//Mat pImageBuf_map_mat_dstmap7;
//Mat pImageBuf_map_mat_dstmap_weight7;
//Mat roi_pImageBuf_map_mat_dstmap7;
//Mat roi_pImageBuf_map_mat_dstmap_weight7;

//Mat cvImageBuf0=cvCreateImage(cvSize(1280,960),8,3);//初始化矩阵头 可行！
//Mat cvImageBuf1=cvCreateImage(cvSize(1280,960),8,3);
//Mat cvImageBuf2=cvCreateImage(cvSize(1280,960),8,3);
//Mat cvImageBuf3=cvCreateImage(cvSize(1280,960),8,3);
//Mat cvImageBuf4=cvCreateImage(cvSize(1280,960),8,3);
//Mat cvImageBuf5=cvCreateImage(cvSize(1280,960),8,3);
//Mat cvImageBuf6=cvCreateImage(cvSize(1280,960),8,3);
//Mat cvImageBuf7=cvCreateImage(cvSize(1280,960),8,3);




//Mat cvImageBuf_final0=cvCreateImage(cvSize(1920,1080),8,3);
//Mat cvImageBuf_final1=cvCreateImage(cvSize(1920,1080),8,3);
//Mat cvImageBuf_final2=cvCreateImage(cvSize(1920,1080),8,3);
//Mat cvImageBuf_final3=cvCreateImage(cvSize(1920,1080),8,3);
//Mat cvImageBuf_final4=cvCreateImage(cvSize(1920,1080),8,3);
//Mat cvImageBuf_final5=cvCreateImage(cvSize(1920,1080),8,3);
//Mat cvImageBuf_final6=cvCreateImage(cvSize(1920,1080),8,3);
//Mat cvImageBuf_final7=cvCreateImage(cvSize(1920,1080),8,3);

//double t1[3][3]={ 1.0016  ,-3.586e-014   ,   -15.371,
//	1.4268e-016   ,    1.0023    ,   9.4066,
//	1.3959e-018 , 6.0986e-017     ,       1};
//double t2[3][3]={ 1.0023  , -0.0066926    ,  -16.929,
//	0.0068534   ,    1.0019    ,  -16.796,
//	2.7631e-006 ,-1.3154e-006 ,     0.98248};
//
//double t3[3][3]={ 1.0027   , -0.029453    ,  -2.0986,
//	0.026023    ,   1.0028     ,  -51.46,
//	1.8776e-006, -1.2075e-006    ,   0.9713};
//
//double t4[3][3]={ 1.0071   , -0.018759   ,   -3.5613,
//	0.02028   ,    1.0031   ,   -11.467,
//	1.236e-005 , 1.6685e-006     , 0.94963};
//
//double t5[3][3]={1.005  , -0.0035634   ,    -27.72,
//	0.012141   ,    1.0001      , -47.05,
//	2.0395e-005 , 8.6645e-006   ,    0.9282};
//
//double t6[3][3]={  0.99863  ,  -0.018861   ,    3.6446,
//	0.023552   ,    1.0023     , -59.184,
//	1.3371e-005 , 1.0464e-005  ,    0.91951};
//
//double t7[3][3]={   1.012   , -0.011926    ,  -11.894,
//	0.026002 ,      1.0074     ,  -18.57,
//	3.0926e-005 , 1.3988e-005   ,   0.89551};
//
//double t8[3][3]={  1.0115  ,  0.0044347    ,  -43.811,
//	0.017563     ,  1.0102    ,  -25.991,
//	3.6225e-005 , 2.3181e-005    ,  0.87488};
//////////////////////////////////////////////////////////////camera4 ref
//double t1[3][3]={
//	1.0007 , 7.8854e-014     , -16.023,
//	1.6337e-015   ,    1.0018   ,    13.919,
//	1.1133e-017 ,   -4.7e-017     ,       1};
//
//
//double t2[3][3]={
//	1.0006  ,  -0.010536     , -3.0161,
//	0.0057741   ,   0.99719   ,    3.8645,
//	1.5313e-006 , -6.5668e-006    ,   1.0018};
//
//
//double t3[3][3]={
//	1.0014  ,  -0.034288    ,    12.49,
//	0.024523    ,  0.99725    ,  -29.391,
//	-6.4706e-007, -1.1634e-005   ,    1.0067};
//
//
//double t4[3][3]={
//	1.005  ,  -0.024596     ,  17.628,
//	0.017418   ,   0.99596    ,   18.679,
//	7.162e-006 ,-1.1901e-005   ,    1.0015};
//
//
//double t5[3][3]={
//	0.99997  ,  -0.011733   ,    1.4503,
//	0.0070971  ,    0.98924    ,   -7.462,
//	1.1074e-005, -9.8486e-006    ,   0.9978};
//
//
//double t6[3][3]={
//	0.99451 ,   -0.030398   ,    40.094,
//	0.016043   ,   0.98936   ,   -10.273,
//	2.5786e-007 ,-1.4483e-005   ,    1.0088};
//
//
//double t7[3][3]={
//	1.0061  ,  -0.024065   ,    30.399,
//	0.016135   ,   0.99372   ,      37.4,
//	1.3156e-005 ,-1.3345e-005   ,   0.99959};
//
//
//double t8[3][3]={
//	1.0025 ,  -0.0094169    ,   6.0561,
//	0.0040194   ,   0.99444   ,    38.951,
//	1.173e-005 , -7.931e-006   ,   0.99677};
//////////////////////////////////////////////////////////////camera4
double t1[3][3]={
	0.99615 ,    0.024416      , -25.57,
	-0.017492  ,     1.0067  ,     10.407,
	-7.4133e-006,  1.1508e-005  ,     0.9997};
	/*double t2[3][3]={
	0.99655    , 0.013917   ,   -13.315,
	-0.011715  ,     1.0025   ,  -0.71592,
	-5.8079e-006 , 5.0602e-006  ,     1.0009};*/
	double t2[3][3]={
		0.99655    , 0.013917   ,   -9.315,
		-0.011715  ,     1.0025   ,  -0.71592,
		-5.8079e-006 , 5.0602e-006  ,     1.0009};
		double t3[3][3]={
			0.99829  , -0.0096489    ,  0.87771,
			0.0071645    ,   1.0032    ,  -35.261,
			-7.7411e-006 , 2.6477e-007     ,   1.005};
			double t4[3][3]={
				1.002, -1.7866e-013   ,     6.875,
				5.395e-016     ,   1.002     ,  12.173,
				1.1736e-017, -1.7889e-018    ,        1};
				double t5[3][3]={
					0.99708    , 0.012657    ,  -10.162,
					-0.01019   ,   0.99517   ,   -14.653,
					3.8888e-006 , 1.9619e-006  ,    0.99571};
					double t6[3][3]={
						0.99238  , -0.0058817     ,  27.902,
						-0.00083917   ,   0.99585     , -19.079,
						-6.6688e-006 , -2.443e-006   ,     1.006};
					/*	double t7[3][3]={
							1.0042 ,  0.00052367     ,  19.277,
							-0.00083257      , 1.0003      ,  28.28,
							6.222e-006 ,-1.2214e-006   ,   0.99711};*/
						double t7[3][3]={
							1.0042 ,  0.00052367     ,  4.0,
							-0.00083257      , 1.0003      ,  28.28,
							6.222e-006 ,-1.2214e-006   ,   0.99711};
							double t8[3][3]={
								1.0007  ,   0.015082      , -5.137,
								-0.012704   ,    1.0009    ,   29.449,
								4.7951e-006 , 4.1587e-006  ,    0.99414};



 /////////////////////////////////////////////////////////
 // CAboutDlg dialog used for App About

 class CAboutDlg : public CDialogEx
 {
 public:
	 CAboutDlg();

	 // Dialog Data
	 enum { IDD = IDD_ABOUTBOX };

 protected:
	 virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	 // Implementation
 protected:
	 DECLARE_MESSAGE_MAP()
 };

 CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
 {
 }

 void CAboutDlg::DoDataExchange(CDataExchange* pDX)
 {
	 CDialogEx::DoDataExchange(pDX);
 }

 BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
 END_MESSAGE_MAP()


 // CMultiViewDlg dialog




CMultiViewDlg::CMultiViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMultiViewDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bFullScreen=FALSE ;

	//BinocularCamera = new CBinocularCamera();
	//BinocularCamera->isOpen = false;
	//BinocularCamera->isStart = true;

	StereoCalibrate = new CStereoCalibrate();

	is_open = false;
	is_start = false;
	doSC = false;
	isQuited = false;
	finishSC = false;
	is3DMode = false;
	finishCaptureVideo = true;
	flag_quit = 1;

	showLineWindow = false;


}
void CMultiViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMultiViewDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_QUIT, &CMultiViewDlg::OnBnClickedBtnQuit)
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BTN_INITSYSTEM, &CMultiViewDlg::OnBnClickedBtnInitsystem)
	ON_BN_CLICKED(IDC_BTN_STOP, &CMultiViewDlg::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_BTN_START, &CMultiViewDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_GRAP, &CMultiViewDlg::OnBnClickedBtnGrap)
	ON_BN_CLICKED(IDC_BTN_OUT, &CMultiViewDlg::OnBnClickedBtnOut)
	ON_BN_CLICKED(IDC_BTN_SC, &CMultiViewDlg::OnBnClickedBtnSc)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_GUIDEDLINE, &CMultiViewDlg::OnBnClickedGuidedline)
	ON_BN_CLICKED(IDC_2DOR3D, &CMultiViewDlg::OnBnClicked2dor3d)
	ON_BN_CLICKED(IDC_CAPTUREVIDEO, &CMultiViewDlg::OnBnClickedCapturevideo)
END_MESSAGE_MAP()
// CMultiViewDlg message handlers

BOOL CMultiViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	GetDlgItem(IDC_LINE)->ShowWindow(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiViewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMultiViewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMultiViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMultiViewDlg::OnBnClickedBtnQuit()
{
	// TODO: Add your control notification handler code here
	ResetEvent(g_hEvent);
	//ResetEvent(g_hEvent0);
	//ResetEvent(g_hEvent1);
	isQuited = true;
	m_bCaptureThread0 = false;
	m_bCaptureThread1 = false;
	doSC = false;
	finishSC = false;
	is3DMode = false;
	//m_bCapture = false;
	//SetEvent(g_hEvent);
	//SetEvent(g_hEvent0);
	//SetEvent(g_hEvent1);

	//for ( unsigned int i = 0; i < numCameras; i++ )	
	//	ppCameras[i] = 0;


	//CDialog::OnCancel();
}


void CMultiViewDlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default





	CDialogEx::OnRButtonDblClk(nFlags, point);
}


void CMultiViewDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//	m_bFullScreen=!m_bFullScreen ;
	//if(m_bFullScreen)
	//{
	//	GetDlgItem(IDC_BTN_INITSYSTEM)->ShowWindow(SW_HIDE) ;
	//	GetDlgItem(IDC_BTN_START)->ShowWindow(SW_HIDE) ;
	//	GetDlgItem(IDC_BTN_GRAP)->ShowWindow(SW_HIDE) ;
	//	GetDlgItem(IDC_BTN_QUIT)->ShowWindow(SW_HIDE) ;
	//	GetDlgItem(IDC_BTN_STOP)->ShowWindow(SW_HIDE) ;
	//	ShowWindow(SW_SHOWMAXIMIZED) ;
	//}
	//else
	//{
	//	GetDlgItem(IDC_BTN_INITSYSTEM)->ShowWindow(SW_SHOW) ;
	//	GetDlgItem(IDC_BTN_START)->ShowWindow(SW_SHOW) ;
	//	GetDlgItem(IDC_BTN_GRAP)->ShowWindow(SW_SHOW) ;
	//	GetDlgItem(IDC_BTN_QUIT)->ShowWindow(SW_SHOW) ;
	//	GetDlgItem(IDC_BTN_STOP)->ShowWindow(SW_SHOW) ;
	//	ShowWindow(SW_SHOWNORMAL) ;
	//}
	//CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CMultiViewDlg::OnBnClickedBtnInitsystem()
{
	// TODO: Add your control notification handler code here
	flag_quit = 1;

	for(int i=0;i<numCameras ;i++)
	{
		pImageBuf[i]=new BYTE [1920*1080*3];
		memset(pImageBuf[i], 0x0, 1920*1080*3);
	}

	//pImageBuf[2],pImageBuf[3]存储校正后的图像
	pImageBuf[2]=new BYTE [1920*1080*3];
	memset(pImageBuf[2], 0x0, 1920*1080*3);
	pImageBuf[3]=new BYTE [1920*1080*3];
	memset(pImageBuf[3], 0x0, 1920*1080*3);
	pSideBySideImage = new BYTE[3840*1080*3];
	memset(pSideBySideImage, 0x0, 1920*1080*3);

	if(is_open == false)
	{

		is_open = true;

		Error   error;	
		error = busMgr.GetNumOfCameras(&numCameras);
		numCameras = 2;

		for ( unsigned int i = 0; i < numCameras; i++)
		{
			
			ppCameras[i] = new Camera();

			
			error = busMgr.GetCameraFromIndex( i, guid+i );
            error = ppCameras[i]->Connect(guid+i);// Connect to a camera

			//error = ppCameras[i]->WriteRegister(0x80C,0x820003FF); //初始化red gain = max and blue gain = 0 克服自动白平衡偏红或者偏蓝
			//error = ppCameras[i]->WriteRegister(0x80C,0x83000000);//auto white balance
			//error = ppCameras[i]->WriteRegister(0x81C,0x83000000);//auto shutter
			//error = ppCameras[i]->WriteRegister(0x820,0x83000000);//auto gain
			//error = ppCameras[i]->WriteRegister(0x804,0x83000000);//auto exposure

			error = ppCameras[i]->WriteRegister(0x80C,0x86200200);//one push auto white  balance  init = 512
			error = ppCameras[i]->WriteRegister(0x81C,0x86000000);//one push auto shutter
			error = ppCameras[i]->WriteRegister(0x820,0x86000000);//one push auto gain
			error = ppCameras[i]->WriteRegister(0x804,0x86000000);//one push auto exposure




			if (error != PGRERROR_OK)
			{
				is_open=false;
				::MessageBox(NULL, _T("连接CAM或GUI context失败！"), _T("警告"), MB_ICONWARNING | MB_OK);
				
			}
			//error = ppCameras[i]->SetVideoModeAndFrameRate(	VIDEOMODE_1280x960RGB, FRAMERATE_30 );

		}
		
		
	}
	
	if(is_open == true)
	{
		::MessageBox(NULL, _T("初始化相机完成！"), _T("警告"), MB_ICONWARNING | MB_OK);
	}
}

bool m_temp = true;
void CMultiViewDlg::OnBnClickedBtnStop()
{
	// TODO: Add your control notification handler code here
	
	if (m_temp)
	{
		flag_quit = 3;

		SetDlgItemText(IDC_BTN_STOP,_T("开始"));
		ResetEvent(g_hEvent);

	}
	else
	{
		SetDlgItemText(IDC_BTN_STOP,_T("暂停"));
		SetEvent(g_hEvent);
	}
	m_temp = !m_temp;

}

//显示图像线程
UINT CaptureThread(LPVOID pParam)
{	
	//for(int i=0;i<8;i++)
	//{
	//	pImageBuf[i]=new BYTE [1280*960*3];
	//	memset(pImageBuf[i], 0x0, 1280*960*3);
	//}
	CMultiViewDlg *pDlg=(CMultiViewDlg*) pParam ;
	/*Error  error;*/
	CDibShow *pDib=new CDibShow(1920,1080) ;
	CDC *pDc=pDlg->GetDlgItem(IDC_DISPLAYVIEW1)->GetDC();//pDlg->GetDC() ;
	pDib->SetHDC(pDc->m_hDC) ;


	/*Image convertedImage[8];*/
	//PBYTE pImageBuf[8];
	//BYTE  *m_pImageBufferFinal;

	//m_pImageBufferFinal=new BYTE [1920*1080*3];
	TimeMeasure::MeasureBegin(string("开始时间"));
	while (pDlg->m_bCapture)
	{
		WaitForSingleObject(pDlg->g_hEvent,INFINITE);

		if (!pDlg->isQuited)
		{
			if(grab0&&grab1)
			{

				CRect rect ;
				pDlg->GetDlgItem(IDC_DISPLAYVIEW1)->GetWindowRect(&rect);
				pDlg->ScreenToClient(&rect);

				if (!pDlg->finishCaptureVideo && pDlg->finishSC)
				{
					pDlg->StereoCalibrate->SynSideBySide(pImageBuf[2],pImageBuf[3],pSideBySideImage);
					pDlg->StereoCalibrate->SaveVideo(pSideBySideImage);
				}

				if (pDlg->m_bFullScreen)
				{
					//pDib->ShowVideo(m_pImageBufferFinal,rect.right-rect.left,rect.bottom-rect.top,0,0) ;

					TimeMeasure::MeasureEnd();
				}else
				{
					if (pDlg->is3DMode)
					{
						pDlg->StereoCalibrate->ThreeDDisplay(1,pImageBuf[0],pImageBuf[1]);
						if (pDlg->finishSC)
						{							
							pDlg->StereoCalibrate->ThreeDDisplay(1,pImageBuf[2],pImageBuf[3]);
							pDib->ShowVideo(pImageBuf[0],rect.Width()/2,rect.bottom-rect.top,0,0);				
							pDib->ShowVideo(pImageBuf[2],rect.Width()/2,rect.bottom-rect.top,rect.Width()/2,0);
						}
						else
						{
							pDib->ShowVideo(pImageBuf[0],rect.Width(),rect.bottom-rect.top,0,0);						
						}
					}
					else
					{
						if (pDlg->finishSC)
						{
							pDib->ShowVideo(pImageBuf[0],rect.Width()/4,rect.bottom-rect.top,0,0);
							pDib->ShowVideo(pImageBuf[1],rect.Width()/4,rect.bottom-rect.top,rect.Width()/4,0);
							pDib->ShowVideo(pImageBuf[2],rect.Width()/4,rect.bottom-rect.top,rect.Width()/2,0);
							pDib->ShowVideo(pImageBuf[3],rect.Width()/4,rect.bottom-rect.top,(rect.Width() * 3)/4,0);
						}
						else
						{
							pDib->ShowVideo(pImageBuf[0],rect.Width()/2,rect.bottom-rect.top,0,0);
							pDib->ShowVideo(pImageBuf[1],rect.Width()/2,rect.bottom-rect.top,rect.Width()/2,0);
						}
					}
									
					
					TimeMeasure::MeasureEnd();
				}

				

				grab0 = 0;
				grab1 = 0;
				SetEvent(pDlg->g_hEvent0);				
				SetEvent(pDlg->g_hEvent1);
				

			}
		}
		else
		{
			pDlg->m_bCapture = false;
			break;
		}	
		
	}
	//delete []m_pImageBufferFinal;

	//delete pDib;
	//pDlg->ReleaseDC(pDc);

	//pDlg->StopSystem();
	pDlg->flag_quit = 3;

	return 0 ;
}
//相机获取的图像数据进行转换为cv::Mat
Mat ConverData(int num,Camera** pCamera,Mat pFinalImage,Image* pImage,Image* pConvertedImage)
{
	pCamera[num]->RetrieveBuffer( &pImage[num]) ;
	pImage[num].Convert( PIXEL_FORMAT_BGR, &pConvertedImage[num] );
	pFinalImage.data = (uchar*)(pConvertedImage[num].GetData());

	return pFinalImage;
}
//对图像进行double angle 旋转角度
Mat Rotateimage(Mat pFinalImage,double angle)
{
	Point2f center = Point2f(pFinalImage.cols / 2, pFinalImage.rows / 2);  // 旋转中心

	double scale = 1.0; // 缩放尺度

	Mat rotateMat; 
	rotateMat = getRotationMatrix2D(center, angle, scale);

	Mat rotateImg;
	warpAffine(pFinalImage, rotateImg, rotateMat, pFinalImage.size());

	return rotateImg;
}
void CMultiViewDlg::StopSystem()
{
	Error   error;

	for (int i=0;i<numCameras;i++)
	{
		error=ppCameras[i]->StopCapture(); //有问题
		error=ppCameras[i]->Disconnect();
		if (error != PGRERROR_OK)
		{
				::MessageBox(NULL, _T("相机停止工作错误！"), _T("警告"), MB_ICONWARNING | MB_OK);
		}
		ppCameras[i] = 0;
	}
	
}
//获取摄像机1的图像数据
UINT CaptureThread0(LPVOID pParam)
{
	CMultiViewDlg *pDlg = (CMultiViewDlg*) pParam ;
	Mat cvImageBuf0 = cvCreateImage(cvSize(1280,960),8,3);//初始化矩阵头 可行！
	Mat cvImageTempBuf0 = cvCreateImage(cvSize(1280,960),8,3);
	Mat tt1;
	Mat cvImageBuf_final0 = cvCreateImage(cvSize(1920,1080),8,3);
	Mat cvImageBuf_tempfinal0=cvCreateImage(cvSize(1920,1080),8,3);
	PBYTE pTemp = new BYTE[1920 * 1080 * 3];
	while(pDlg->m_bCaptureThread0)
	{	
		WaitForSingleObject(pDlg->g_hEvent0,INFINITE);

		cvImageBuf0 = ConverData(0,ppCameras,cvImageBuf0,image,convertedImage);
		cvImageBuf0 = Rotateimage(cvImageBuf0,180);
		resize(cvImageBuf0,cvImageBuf_final0,cvSize(1920,1080),0.0,0.0,resize_param);
		
		pImageBuf[0] = (BYTE*)cvImageBuf_final0.data;//(BYTE*)cvImageBuf_final0.data;
	
		if (pDlg->finishSC)
			 pDlg->StereoCalibrate->SCProcessing(1,pImageBuf[0],pImageBuf[2]);

		grab0 = 1;

		ResetEvent(pDlg->g_hEvent0);
	
	}
	
	return 0;
}



//获取摄像机2的图像数据
UINT CaptureThread1(LPVOID pParam)
{
	CMultiViewDlg *pDlg=(CMultiViewDlg*) pParam ;
	Mat cvImageBuf1 = cvCreateImage(cvSize(1280,960),8,3);
	Mat cvImageTempBuf1 = cvCreateImage(cvSize(1280,960),8,3);
	Mat tt2;
	Mat cvImageBuf_final1=cvCreateImage(cvSize(1920,1080),8,3);
	Mat cvImageBuf_tempfinal=cvCreateImage(cvSize(1920,1080),8,3);
	PBYTE pTemp = new BYTE[1920 * 1080 * 3];
	while(pDlg->m_bCaptureThread1)
	{		
		WaitForSingleObject(pDlg->g_hEvent1,INFINITE);

		cvImageBuf1 = ConverData(1,ppCameras,cvImageBuf1,image,convertedImage);
		cvImageBuf1 = Rotateimage(cvImageBuf1,180);
		resize(cvImageBuf1,cvImageBuf_final1,cvSize(1920,1080),0.0,0.0,resize_param);	

		pImageBuf[1]=(BYTE*)cvImageBuf_final1.data;
		
		if (pDlg->finishSC)
			 pDlg->StereoCalibrate->SCProcessing(2,pImageBuf[1],pImageBuf[3]);	

		grab1 = 1;

		ResetEvent(pDlg->g_hEvent1);
	}

	//pDlg->StopSystem(1);
	
	SetEvent(pDlg->g_hEvent);
	

	return 0;
}

//标定-校正操作
UINT CaptureThread2(LPVOID pParam)
{
	CMultiViewDlg *pDlg=(CMultiViewDlg*) pParam ;

	Mat cvImageBuf2 = cvCreateImage(cvSize(1280,960),8,3);
	Mat tt2;
	Mat cvImageBuf_final2=cvCreateImage(cvSize(1920,1080),8,3);

	char* tempPath;

	while(pDlg->doSC)
	{
		WaitForSingleObject(pDlg->g_hEvent2,INFINITE);

		pDlg->StereoCalibrate->Calibrate();
		pDlg->StereoCalibrate->GetMatrix();
		pDlg->StereoCalibrate->Rectify();
		
		pDlg->finishSC = true;
		
		ResetEvent(pDlg->g_hEvent2);
		
	}

	return 0;
}


void CMultiViewDlg::StartCapture()
{
	flag_quit = 2;

	m_bCapture = true ;
	m_bCaptureThread0 = true;
	m_bCaptureThread1 = true;
	doSC = true;

	g_hEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	g_hEvent0 = CreateEvent(NULL,TRUE,FALSE,NULL);
	g_hEvent1 = CreateEvent(NULL,TRUE,FALSE,NULL);
	g_hEvent2 = CreateEvent(NULL,TRUE,FALSE,NULL);
	
	hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CaptureThread,(void*)this,0,NULL);//主控线程

	hThread0=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CaptureThread0,(void*)this,0,NULL);
	hThread1=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CaptureThread1,(void*)this,0,NULL);
	hThread2=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)CaptureThread2,(void*)this,0,NULL);
	
	SetEvent(g_hEvent);
	SetEvent(g_hEvent0);
	SetEvent(g_hEvent1);

}
void CMultiViewDlg::OnBnClickedBtnStart()
{
	// TODO: Add your control notification handler code here
	flag_quit = 1;

	Error   error;
	if(is_open==false)
	{
		::MessageBox(NULL, _T("请初始化后再使用！"), _T("警告"), MB_ICONWARNING | MB_OK);
	}
	else
	{
		if(is_start==false)
		{
			for(int i=0;i<numCameras;i++)
			{
				error = ppCameras[i]->StartCapture();
				if (error != PGRERROR_OK)
				{
					::MessageBox(NULL, _T("开始CAM或GUI context失败！"), _T("警告"), MB_ICONWARNING | MB_OK);
				
				}
			}	
		}

		is_start=true;
		::MessageBox(NULL, _T("已经开启相机！"), _T("警告"), MB_ICONWARNING | MB_OK);

		StartCapture();
	}	
}
void CMultiViewDlg::OnBnClickedBtnGrap()
{
	// TODO: Add your control notification handler code here
	/*if (m_bCapture==true)
	{
		StopCapture();
	}*/
	Error   error;
	int i;
	
	if(is_start==true)
	{
		Image convertedImage;
		for(i=0;i<numCameras;i++)
		{
            error = ppCameras[i]->RetrieveBuffer( &image[i] );
			// Convert the raw image
			error = image[i].Convert( PIXEL_FORMAT_BGR, &convertedImage );//有问题
			
			char tempFilename[256];
			
			sprintf(tempFilename, "camera%d_%d.%s", i,j_num,"bmp");
			
			error = convertedImage.Save(tempFilename );//保存图像
			
		}
		::MessageBox(NULL, _T("已捕获图像！"), _T("警告"), MB_ICONWARNING | MB_OK);
		
		
		
		j_num++;
	}
	else
	{
		::MessageBox(NULL, _T("请开启相机！"), _T("警告"), MB_ICONWARNING | MB_OK);
	}
	
}


void CMultiViewDlg::OnBnClickedBtnOut()
{
	// TODO: Add your control notification handler code here
	
	if (isQuited)
	{
		StopSystem();
	}

	if (flag_quit == 1 || flag_quit == 3)
	{
		CDialogEx::OnCancel();
	}
	else if (flag_quit == 2)
	{
		::MessageBox(NULL, _T("请先点击“停止”按钮，再点击“退出”按钮"), _T("警告"), MB_ICONWARNING | MB_OK);
	}
	
}


void CMultiViewDlg::OnBnClickedBtnSc()
{
	// TODO: Add your control notification handler code here
//	if (6 == j_num)
		SetEvent(g_hEvent2);
}

//用于实现鼠标拖动标尺的变量
bool mouseLDown = false;
CPoint mousePoint;
CRect rect;

void CMultiViewDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	
	CPoint picContr;
	GetDlgItem(IDC_LINE)->GetWindowRect(&rect);
	ScreenToClient(&rect);//获得相对于主窗体的坐标
	
	if(rect.PtInRect(point) )   //鼠标是否在控件范围之内
	{
		mouseLDown = true;
		mousePoint.x = point.x;
		mousePoint.y = point.y;

	}
	


	picContr.x=rect.TopLeft().x;
	picContr.y=rect.TopLeft().y;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMultiViewDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CRect cRect;
	CPoint picContr;
	
	cRect = rect;

	if(mouseLDown)   //鼠标是否在控件范围之内
	{
		picContr.x = point.x - mousePoint.x;
		picContr.y = point.y - mousePoint.y;

		cRect.TopLeft().x = rect.TopLeft().x + picContr.x;
		cRect.TopLeft().y = rect.TopLeft().y + picContr.y;

		GetDlgItem(IDC_LINE)->SetWindowPos(NULL,cRect.TopLeft().x,cRect.TopLeft().y,0,0,SWP_NOZORDER | SWP_NOSIZE);
		
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CMultiViewDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	CPoint picContr;
	GetDlgItem(IDC_LINE)->GetWindowRect(&rect);
	ScreenToClient(&rect);//获得相对于主窗体的坐标

	if(rect.PtInRect(point) )   //鼠标是否在控件范围之内
	{
		mouseLDown = false;
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMultiViewDlg::OnBnClickedGuidedline()
{
	// TODO: Add your control notification handler code here

	if (showLineWindow)
	{
		GetDlgItem(IDC_LINE)->ShowWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_LINE)->ShowWindow(TRUE);
		GetDlgItem(IDC_LINE)->SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
		GetDlgItem(IDC_LINE)->BringWindowToTop();
		
	}
	
	showLineWindow = !showLineWindow;
}


void CMultiViewDlg::OnBnClicked2dor3d()
{
	// TODO: Add your control notification handler code here
	is3DMode = !is3DMode;
}


void CMultiViewDlg::OnBnClickedCapturevideo()
{
	// TODO: Add your control notification handler code here
	finishCaptureVideo = !finishCaptureVideo;

	if (finishCaptureVideo)
	{
		SetDlgItemText(IDC_CAPTUREVIDEO,_T("录制"));
	}
	else
	{
		SetDlgItemText(IDC_CAPTUREVIDEO,_T("结束录制"));

	}
	
}
