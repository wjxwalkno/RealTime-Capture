#include "StdAfx.h"
#include "DibShow.h"
/************************************************************************/
/* �������������캯��������Ĭ�Ͽ�߲�����ʼ��Dib                                                                     */
/************************************************************************/
CDibShow::CDibShow(void)
{
	m_HDib=NULL ;
	m_Hdc=NULL ;
	InitDib() ;
}
/************************************************************************/
/*  �������������캯��������ָ���Ŀ�߳�ʼ��Dib                                                                     */
/* �����������Ҫ��ʾ��Ƶ��bmp��Ϣ
/************************************************************************/
CDibShow::CDibShow(int nWidth,int nHeight)
{
	m_HDib=NULL ;

	m_Hdc=NULL ;
	InitDib(nWidth,nHeight) ;
}
CDibShow::~CDibShow(void)
{
	CloseDib() ;
}
/************************************************************************/
/*���������� ��ʼ��DIB�Լ�����ʾ��ص���Ϣ                                                                     */
/*����ֵ����ʼ���ɹ��������棻���򷵻ؼ�
/************************************************************************/
bool CDibShow::InitDib(int nWidth,int nHeight)
{
	CloseDib();//���ͷ���Դ��
	m_HDib=::DrawDibOpen() ;
	m_BmpInfoHeader.biBitCount=24 ;
	m_BmpInfoHeader.biClrImportant=0 ;
	m_BmpInfoHeader.biClrUsed=0 ;
	m_BmpInfoHeader.biCompression=0 ;
	m_BmpInfoHeader.biHeight=nHeight ;
	m_BmpInfoHeader.biPlanes=1 ;
	m_BmpInfoHeader.biSize=sizeof(m_BmpInfoHeader) ;
	m_BmpInfoHeader.biSizeImage=0;//m_Step*m_Height ;
	m_BmpInfoHeader.biWidth=nWidth ;
	m_BmpInfoHeader.biXPelsPerMeter=0 ;
	m_BmpInfoHeader.biYPelsPerMeter=0 ;
	if(!m_HDib)
	{
		return true ;
	}
	return false ;
}
/************************************************************************/
/*�����������ͷ�Dib��Դ                                                                      */
/************************************************************************/
void CDibShow::CloseDib()
{
	if(m_HDib!=NULL)
	{
		::DrawDibEnd(m_HDib);
		::DrawDibClose(m_HDib);
	}
}
/************************************************************************/
/* ��������������ͼ��Դ�Ŀ�͸�                                                                     */
/*���������nWidth��ͼ��Ŀ�nHeight��ͼ��ĸ� 
/************************************************************************/
void CDibShow::SetVideoInfo(int nWidth,int nHeight)
{
	m_BmpInfoHeader.biHeight=nHeight ;
	m_BmpInfoHeader.biWidth=nWidth ;
}
/************************************************************************/
/* ����������ͼ����Ĭ�ϵĴ�������������ʾ                                                                    */
/*���������pBuffer��ָ��ͼ�����ݵ�buffer��ָ��
/************************************************************************/
void CDibShow::ShowVideo(void *pBuffer,int nStartX,int nStartY)
{
	if (pBuffer==NULL)
	{
		return  ;
	}
	if ((m_HDib!=NULL)&&(m_Hdc!=NULL))
	{//��Ƶ��Ĭ�ϵĴ�����������ʾ
		::DrawDibDraw(m_HDib,m_Hdc,nStartX,nStartY,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,&m_BmpInfoHeader,pBuffer,
			0,0,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,DDF_SAME_HDC) ;
	}
}
/************************************************************************/
/* ����������ͼ����Ĭ�ϵĴ����ϰ���ָ���Ĵ�С��ʾ                                                                    */
/*���������pBuffer��ָ��ͼ�����ݵ�buffer��ָ�룻nShowWidth����ʾͼ��Ŀ�nShowHeight����ʾͼ��ĸߣ�
*ע�⣺���ߺͿ���ͼ��ԭʼ��С��һ���ǣ���ʾ��ͼ����������
************************************************************************/
void CDibShow::ShowVideo(void *pBuffer,int nShowWidth,int nShowHeight,int nStartX,int nStartY)
{
	if (pBuffer==NULL)
	{
		return  ;
	}
	if ((m_HDib!=NULL)&&(m_Hdc!=NULL))
	{//��Ƶ��Ĭ�ϵĴ����ϰ��ո����Ŀ�͸���ʾ
		::DrawDibDraw(m_HDib,m_Hdc,nStartX,nStartY,nShowWidth,nShowHeight,&m_BmpInfoHeader,pBuffer,
			0,0,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,DDF_SAME_HDC) ;
	}
}
/************************************************************************/
/* ����������ͼ����ָ���Ĵ�������������ʾ                                                                    */
/*���������pBuffer��ָ��ͼ�����ݵ�buffer��ָ��
/************************************************************************/
void CDibShow::ShowVideo(void *pBuffer,HDC hDc,int nStartX,int nStartY)
{
	if (pBuffer==NULL)
	{
		return ;
	}
	if ((m_HDib!=NULL)&&(hDc!=NULL))
	{//��ָ���Ĵ����ϰ���ԭʼ��С��ʾ
		::DrawDibDraw(m_HDib,m_Hdc,nStartX,nStartY,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,&m_BmpInfoHeader,pBuffer,
			0,0,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,DDF_SAME_HDC) ;
	}
}
/************************************************************************/
/* ����������ͼ����ָ���Ĵ�������������ʾ                                                                    */
/*���������pBuffer��ָ��ͼ�����ݵ�buffer��ָ�룻nShowWidth����ʾͼ��Ŀ�nShowHeight����ʾͼ��ĸߣ�
/*ע�⣺���ߺͿ���ͼ��ԭʼ��С��һ���ǣ���ʾ��ͼ����������
/************************************************************************/
void CDibShow::ShowVideo(void *pBuffer,HDC hDc,int nShowWidth,int nShowHeight,int nStartX,int nStartY)
{
	if (pBuffer==NULL)
	{
		return ;
	}
	if ((m_HDib!=NULL)&&(hDc!=NULL))
	{//��ָ���Ĵ����ϰ���ָ���Ĵ�С��ʾ
		::DrawDibDraw(m_HDib,m_Hdc,nStartX,nStartY,nShowWidth,nShowHeight,&m_BmpInfoHeader,pBuffer,
			0,0,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,DDF_SAME_HDC) ;
	}
}