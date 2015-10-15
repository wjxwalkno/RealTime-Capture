#include "stdafx.h"
#include "BinocularCamera.h"

CBinocularCamera::CBinocularCamera()
{
	m_pImageBufferFinal = new BYTE [1920*1080*3];
	ppCameras = new Camera * [numCameras];
}
CBinocularCamera::~CBinocularCamera()
{

}

BOOL CBinocularCamera::InitBCSystem()
{
	// Camera** ppCameras = new Camera*[8];
	if(isOpen == false)
	{

		isOpen = true;
		Error   error;

		error = busMgr.GetNumOfCameras(&numCameras);
		for ( unsigned int i = 0; i < numCameras; i++)
		{
			ppCameras[i] = new Camera();

			error = busMgr.GetCameraFromIndex( i, guid+i );
			error = ppCameras[i]->Connect(guid+i);// Connect to a camera

			//error = ppCameras[i]->WriteRegister(0x80C,0x820003FF); //��ʼ��red gain = max and blue gain = 0 �˷��Զ���ƽ��ƫ�����ƫ��
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
				isOpen = false;
				//::MessageBox(NULL, _T("����CAM��GUI contextʧ�ܣ�"), _T("����"), MB_ICONWARNING | MB_OK);
				return FALSE;
			}
			//error = ppCameras[i]->SetVideoModeAndFrameRate(	VIDEOMODE_1280x960RGB, FRAMERATE_30 );
			
		}

		return TRUE;
	}

	if(isOpen == true)
	{
		//::MessageBox(NULL, _T("��ʼ�������ɣ�"), _T("����"), MB_ICONWARNING | MB_OK);
		return TRUE;
	}
}

BOOL CBinocularCamera::StopBCSystem()
{
	Error   error;
	//TerminateThread(hThread,4);

	m_bCapture = false;
	//Sleep(10);
	if (isStart == true)
	{
		isStart = false;
		for (int i = 0;i < numCameras;i++)
		{
			error = ppCameras[i]->StopCapture(); //��bug!!!!!!!!
			error = ppCameras[i]->Disconnect();
			if (error != PGRERROR_OK)
			{
				//::MessageBox(NULL, _T("���ֹͣ��������"), _T("����"), MB_ICONWARNING | MB_OK);
				isStart = true;
				return FALSE;
			}
		}

	}

	return TRUE;
}

Mat CBinocularCamera::ConverData(int num,Camera** pCamera,Mat pFinalImage,Image* pImage,Image* pConvertedImage)
{
	pCamera[num]->RetrieveBuffer( &pImage[num]) ;
	pImage[num].Convert( PIXEL_FORMAT_BGR, &pConvertedImage[num] );
	pFinalImage.data = (uchar*)(pConvertedImage[num].GetData());
	return pFinalImage;
}