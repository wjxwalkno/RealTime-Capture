
// MultiViewDlg.h : header file
//

#pragma once
#include <windows.h>
#include "DibShow.h"
#include <opencv2/opencv.hpp>
#include "FlyCapture2.h"
#include "Error.h"
#include "FlyCapture2Defs.h"

#include "FlyCapture2GUI.h"
#include "StereoCalibrate.h"
//#include "BinocularCamera.h"

using namespace FlyCapture2;
using namespace cv;
// CMultiViewDlg dialog
class CMultiViewDlg : public CDialogEx
{
// Construction
public:
	CMultiViewDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL m_bFullScreen ;
// Dialog Data
	enum { IDD = IDD_MULTIVIEW_DIALOG };
	PGRGuid guid[8];
	
	//FlyCaptureVideoMode ImageFormat;//��Ƶ��ʽ
	//FlyCaptureImage   m_imageRaw[8]; //������
	//FlyCaptureImage   m_imageProcessed[8];//ת���������
	//int m_cameraInfo[8];//������к�
	//CameraGUIContext m_guicontext;

	int flag_quit; //flag_quit = 1 ʱ��Ϊδʵʱ��ʾͼ������״̬��flag_quit = 3 ʱ��Ϊʵʱ��ʾͼ������״̬��flag_quit = 3 ʱ��Ϊ�������߳��Ѿ���ȫ�˳�״̬��

	bool is_start;
	bool is_open;
	bool doSC;
	bool finishSC;
	bool showLineWindow;

	bool isQuited;
	bool m_bCapture ;
	bool m_bCaptureThread0;
	bool m_bCaptureThread1;
	//Mat pImageBuf_map_mat0;
	HANDLE hThread;
	HANDLE hThread0;
	HANDLE hThread1;
	HANDLE hThread2;

	HANDLE g_hEvent;
	HANDLE g_hEvent0;
	HANDLE g_hEvent1;
	HANDLE g_hEvent2;

	CvMat T1_cv;
	CvMat T2_cv;
	CvMat T3_cv;
	CvMat T4_cv;
	CvMat T5_cv;
	CvMat T6_cv;
	CvMat T7_cv;
	CvMat T8_cv;

	void StartCapture() ;
	void StopCapture() ;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnQuit();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBtnInitsystem();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnGrap();

private:

public:
	//CBinocularCamera* BinocularCamera;

	CStereoCalibrate* StereoCalibrate;

	void StopSystem();
	
	
	afx_msg void OnBnClickedBtnOut();
	afx_msg void OnBnClickedBtnSc();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedGuidedline();
};
