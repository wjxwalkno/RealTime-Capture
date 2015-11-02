#include "StdAfx.h"
#include "DibShow.h"
/************************************************************************/
/* 功能描述：构造函数，按照默认宽高参数初始化Dib                                                                     */
/************************************************************************/
CDibShow::CDibShow(void)
{
	m_HDib=NULL ;
	m_Hdc=NULL ;
	InitDib() ;
}
/************************************************************************/
/*  功能描述：构造函数，按照指定的宽高初始化Dib                                                                     */
/* 输入参数：将要显示视频的bmp信息
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
/*功能描述： 初始化DIB以及与显示相关的信息                                                                     */
/*返回值：初始化成功，返回真；否则返回假
/************************************************************************/
bool CDibShow::InitDib(int nWidth,int nHeight)
{
	CloseDib();//先释放资源；
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
/*功能描述：释放Dib资源                                                                      */
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
/* 功能描述：设置图像源的宽和高                                                                     */
/*输入参数：nWidth是图像的宽；nHeight是图像的高 
/************************************************************************/
void CDibShow::SetVideoInfo(int nWidth,int nHeight)
{
	m_BmpInfoHeader.biHeight=nHeight ;
	m_BmpInfoHeader.biWidth=nWidth ;
}
/************************************************************************/
/* 功能描述：图像在默认的窗口上无拉伸显示                                                                    */
/*输入参数：pBuffer是指向图像数据的buffer的指针
/************************************************************************/
void CDibShow::ShowVideo(void *pBuffer,int nStartX,int nStartY)
{
	if (pBuffer==NULL)
	{
		return  ;
	}
	if ((m_HDib!=NULL)&&(m_Hdc!=NULL))
	{//视频在默认的窗口无拉伸显示
		::DrawDibDraw(m_HDib,m_Hdc,nStartX,nStartY,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,&m_BmpInfoHeader,pBuffer,
			0,0,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,DDF_SAME_HDC) ;
	}
}
/************************************************************************/
/* 功能描述：图像在默认的窗口上按照指定的大小显示                                                                    */
/*输入参数：pBuffer是指向图像数据的buffer的指针；nShowWidth是显示图像的宽，nShowHeight是显示图像的高；
*注意：当高和宽与图像原始大小不一致是，显示的图像会出现拉伸
************************************************************************/
void CDibShow::ShowVideo(void *pBuffer,int nShowWidth,int nShowHeight,int nStartX,int nStartY)
{
	if (pBuffer==NULL)
	{
		return  ;
	}
	if ((m_HDib!=NULL)&&(m_Hdc!=NULL))
	{//视频在默认的窗口上按照给出的宽和高显示
		::DrawDibDraw(m_HDib,m_Hdc,nStartX,nStartY,nShowWidth,nShowHeight,&m_BmpInfoHeader,pBuffer,
			0,0,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,DDF_SAME_HDC) ;
	}
}
/************************************************************************/
/* 功能描述：图像在指定的窗口上无拉伸显示                                                                    */
/*输入参数：pBuffer是指向图像数据的buffer的指针
/************************************************************************/
void CDibShow::ShowVideo(void *pBuffer,HDC hDc,int nStartX,int nStartY)
{
	if (pBuffer==NULL)
	{
		return ;
	}
	if ((m_HDib!=NULL)&&(hDc!=NULL))
	{//在指定的窗口上按照原始大小显示
		::DrawDibDraw(m_HDib,m_Hdc,nStartX,nStartY,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,&m_BmpInfoHeader,pBuffer,
			0,0,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,DDF_SAME_HDC) ;
	}
}
/************************************************************************/
/* 功能描述：图像在指定的窗口上无拉伸显示                                                                    */
/*输入参数：pBuffer是指向图像数据的buffer的指针；nShowWidth是显示图像的宽，nShowHeight是显示图像的高；
/*注意：当高和宽与图像原始大小不一致是，显示的图像会出现拉伸
/************************************************************************/
void CDibShow::ShowVideo(void *pBuffer,HDC hDc,int nShowWidth,int nShowHeight,int nStartX,int nStartY)
{
	if (pBuffer==NULL)
	{
		return ;
	}
	if ((m_HDib!=NULL)&&(hDc!=NULL))
	{//在指定的窗口上按照指定的大小显示
		::DrawDibDraw(m_HDib,m_Hdc,nStartX,nStartY,nShowWidth,nShowHeight,&m_BmpInfoHeader,pBuffer,
			0,0,m_BmpInfoHeader.biWidth,m_BmpInfoHeader.biHeight,DDF_SAME_HDC) ;
	}
}