#pragma once
#include <windows.h>

#include "FlyCapture2.h"
#include "Error.h"
#include "FlyCapture2Defs.h"

#include "FlyCapture2GUI.h"
#include <opencv2/opencv.hpp>

using namespace FlyCapture2;
using namespace cv;

class CBinocularCamera
{
public:
	PGRGuid guid[8];
	
	bool isOpen;
	bool isStart;

	unsigned int numCameras;
	Image image[8];
	//PBYTE pImageBuf[8];
	BYTE  *m_pImageBufferFinal;
	Camera** ppCameras;

	Image convertedImage[8];
	PBYTE pImageBuf[8];
	
	bool m_bCapture ;


public:

	CBinocularCamera();
	~CBinocularCamera();

	virtual BOOL InitBCSystem();
	virtual BOOL StopBCSystem();

protected:

private:
	Mat ConverData(int num,Camera** pCamera,Mat pFinalImage,Image* pImage,Image* pConvertedImage);  //FlyCapture2::Camera**  -> cv::Mat

private:
	BusManager busMgr;

};

