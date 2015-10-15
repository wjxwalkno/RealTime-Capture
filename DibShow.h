#pragma once
#include "vfw.h"//Dib��Ƶ������Ҫ�õ��������
#pragma comment(lib,"Vfw32.lib ")
/************************************************************************/
/* ������������װһ����������ָ���Ĵ�������ʾԭʼRGBͼ������                                */
/*��    �ڣ�2011��3��26��
/*��    �ߣ�����
/************************************************************************/
class CDibShow
{
public:
	CDibShow(void);
	CDibShow(int nWidth=1920,int nHeight=1080) ;
	~CDibShow(void);
	void SetBmpInfo(BITMAPINFOHEADER &bmpInfo) {m_BmpInfoHeader=bmpInfo;};
	BITMAPINFOHEADER  GetBmpInfo() {return m_BmpInfoHeader;};
	void SetVideoInfo(int nWidth,int nHeight) ;
	void SetHDC(HDC hDc) {m_Hdc=hDc;};
	HDC GetHDC() {return m_Hdc;};
	void ShowVideo(void* pBuffer,int nStartX=0,int nStartY=0) ;
	void ShowVideo(void* pBuffer,int nWidth,int nHeight,int nStartX=0,int nStartY=0) ;
	void ShowVideo(void *pBuffer,HDC hDc,int nShowWidth,int nShowHeight,int nStartX=0,int nStartY=0) ;
	void ShowVideo(void* pBuffer,HDC hDc ,int nStartX=0,int nStartY=0) ;
private:
	HDRAWDIB m_HDib ;
	BITMAPINFOHEADER m_BmpInfoHeader ;
	HDC m_Hdc ;

	bool InitDib(int nWidth=1920,int nHeight=1080) ;
	//bool InitDib(int nWidth=1280,int nHeight=960) ;
	void CloseDib() ;
};
