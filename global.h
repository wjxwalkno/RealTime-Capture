#pragma once

#include <windows.h>

#include "DibShow.h"

#include "FlyCapture2.h"
#include "Error.h"
#include "FlyCapture2Defs.h"

#include "FlyCapture2GUI.h"
#include <opencv2/opencv.hpp>

using namespace FlyCapture2;
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



unsigned int numCameras = 2;
BusManager busMgr;
Image image[8];
//PBYTE pImageBuf[8];
BYTE  *m_pImageBufferFinal=new BYTE [1920*1080*3];
Camera** ppCameras = new Camera*[numCameras];
int j_num = 1;
Image convertedImage[8];
Error  error;
float pImageBuf_map0[1280*960][2]={0.0};
float pImageBuf_map1[1280*960][2]={0.0};
float pImageBuf_map2[1280*960][2]={0.0};
float pImageBuf_map3[1280*960][2]={0.0};
float pImageBuf_map4[1280*960][2]={0.0};
float pImageBuf_map5[1280*960][2]={0.0};
float pImageBuf_map6[1280*960][2]={0.0};
float pImageBuf_map7[1280*960][2]={0.0};

float pImageBuf_map0_inv[1280*960][2]={0.0};//xyy
float pImageBuf_map1_inv[1280*960][2]={0.0};
float pImageBuf_map2_inv[1280*960][2]={0.0};
float pImageBuf_map3_inv[1280*960][2]={0.0};
float pImageBuf_map4_inv[1280*960][2]={0.0};
float pImageBuf_map5_inv[1280*960][2]={0.0};
float pImageBuf_map6_inv[1280*960][2]={0.0};
float pImageBuf_map7_inv[1280*960][2]={0.0};


int image_mix_thread1_done;
int image_mix_thread2_done;
int image_mix_thread3_done;
int image_mix_thread4_done;
int image_mix_thread5_done;
int image_mix_thread6_done;
int image_mix_thread7_done;
int image_mix_thread8_done;
int image_mix_thread9_done;
int image_mix_thread10_done;
int grab0=0;
int grab1=0;
int grab2=0;
int grab3=0;
int grab4=0;
int grab5=0;
int grab6=0;
int grab7=0;
PBYTE pImageBuf[8];
const int x_start=24;
const int y_start=40;
const int x_off=1140;
const int y_off=880;
const int remap_param=CV_INTER_LINEAR;
const int resize_param=CV_INTER_LINEAR;






