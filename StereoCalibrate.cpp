#include "stdafx.h"
#include <iostream>

#include "StereoCalibrate.h"
using namespace std;

CStereoCalibrate::CStereoCalibrate()
{
	Initial();
}
CStereoCalibrate::~CStereoCalibrate()
{

}

//参数初始化
void CStereoCalibrate::Initial()
{
	//left_intrinsic = cvCreateMat(3,3,CV_64FC1);
	//left_distortion = cvCreateMat(5,1,CV_64FC1);
	//left_translation_vector_1 = cvCreateMat(3,1,CV_64FC1);
	//right_intrinsic = cvCreateMat(3,3,CV_64FC1);
	//right_distortion = cvCreateMat(5,1,CV_64FC1);
	//right_translation_vector_1 = cvCreateMat(3,1,CV_64FC1);


	left_rotation_matrix = cvCreateMat(3,3,CV_64FC1);

	right_rotation_matrix = cvCreateMat(3,3,CV_64FC1);

	object_points2 = cvCreateMat(successes_ideal*board_n,3,CV_32FC1);
	image_points2  = cvCreateMat(successes_ideal*board_n,2,CV_32FC1);
	point_counts2  = cvCreateMat(successes_ideal,1,CV_32SC1);
	intrinsic_matrix = cvCreateMat(3,3,CV_64FC1);
	distortion_coeffs = cvCreateMat(5,1,CV_64FC1);
	rotation_vectors = cvCreateMat(successes_ideal,3,CV_64FC1);
	translation_vectors = cvCreateMat(successes_ideal,3,CV_64FC1);

	H[0] = cvCreateMat(3, 3, CV_64FC1);
	H[1] = cvCreateMat(3, 3, CV_64FC1);
	

	board_sz = cvSize( board_w, board_h );
	corners = new CvPoint2D32f[ board_n ];//一张图片的理论角点数目 board_n
	successes = 0;
	n_boards = 6;              
	num_of_file_name = 0;
	num_of_param_name = 1;
	image = 0;
	gray_image = 0;
	fptr=NULL;
}
//标定+校正处理
BYTE  * CStereoCalibrate::SCProcessing(int numCamera,PBYTE sourceImage)
{
	BYTE  *m_pImageBufferFinal=new BYTE [1920*1080*3];
	memset(m_pImageBufferFinal,0,1920*1080*3);

	cv::Mat cvImageBuf = cvCreateImage(cvSize(1920,1080),8,3);
	
	int num = numCamera - 1;
	int orig_height = 960;
	int new_height = 1080;
	int orig_width = 1280;
	int new_width = 1920;

    double t[3][3]={    H[num]->data.db[0]  ,     H[num]->data.db[1]    ,  H[num]->data.db[2],
		H[num]->data.db[3]     ,  H[num]->data.db[4]      ,  H[num]->data.db[5],
		H[num]->data.db[6] , H[num]->data.db[7]    , H[num]->data.db[8]};

    cv::Mat t_warp(3,3,CV_64FC1,t);

    cv::Mat t_warp_inv=t_warp.inv();
	double t_inv[3][3]={t_warp_inv.at<double>(0,0),t_warp_inv.at<double>(0,1),t_warp_inv.at<double>(0,2),
		t_warp_inv.at<double>(1,0),t_warp_inv.at<double>(1,1),t_warp_inv.at<double>(1,2),
		t_warp_inv.at<double>(2,0),t_warp_inv.at<double>(2,1),t_warp_inv.at<double>(2,2)};

	int x = 0;
	int y = 0;
	int z = 0;

	for(int i = 0;i < 1920;i++)
		for(int j = 0;j < 1080;j++)
		{
			//roi_to[i*1920+j][0]=j*1140/1920.0;
			//roi_to[i*1920+j][1]=i*860/1080.0;
			////70+roi_to[i*1920+j][0]代替了j    (50+roi_to[i*1920+j][1])代替i
			//map_0[0][i*1920+j][0]=((70+roi_to[i*1920+j][0])*t_inv[0][0]+(50+roi_to[i*1920+j][1])*t_inv[0][1]+t_inv[0][2])/((70+roi_to[i*1920+j][0])*t_inv[2][0]+(50+roi_to[i*1920+j][1])*t_inv[2][1]+t_inv[2][2]);//
			//map_0[0][i*1920+j][1]=((70+roi_to[i*1920+j][0])*t_inv[1][0]+(50+roi_to[i*1920+j][1])*t_inv[1][1]+t_inv[1][2])/((70+roi_to[i*1920+j][0])*t_inv[2][0]+(50+roi_to[i*1920+j][1])*t_inv[2][1]+t_inv[2][2]);
			x = (i * t_inv[0][0] + j * t_inv[0][1] + t_inv[0][2])/(i * t_inv[2][0]+j * t_inv[2][1] + t_inv[2][2]);
			y = (i * t_inv[1][0] + j * t_inv[1][1] + t_inv[1][2])/(i * t_inv[2][0]+j * t_inv[2][1] + t_inv[2][2]);

			if ((x < 1920) && (x >= 0) && (y < 1080) && (y >= 0))
			{
				m_pImageBufferFinal[((new_height - j - 1) * new_width + i) * 3 + 0] = sourceImage[(y * new_width + x) * 3 + 0];
				m_pImageBufferFinal[((new_height - j - 1) * new_width + i) * 3 + 1] = sourceImage[(y * new_width + x) * 3 + 1];
				m_pImageBufferFinal[((new_height - j - 1) * new_width + i) * 3 + 2] = sourceImage[(y * new_width + x) * 3 + 2];
			}	

		}

	/*float g_a,g_b,g_c,g_d,g_e,g_f;
	float j_new,i_new;
	
	for(int i=0;i<1080;i++)
	{
		int n = 1080-i-1;

		for(int j=0;j<1920;j++)
		{		
			j_new=map_0[num&7][i*1920+j][0];
			i_new=map_0[num&7][i*1920+j][1];
			g_b=sourceImage[((int(i_new)+1)*1280+(int(j_new)+1))*3+2];
			g_a=sourceImage[((int(i_new)+1)*1280+int(j_new))*3+2];
			g_d=sourceImage[(int(i_new)*1280+(int(j_new)+1))*3+2];
			g_c=sourceImage[(int(i_new)*1280+int(j_new))*3+2];
			g_e=(j_new-int(j_new))*(g_b-g_a)+g_a;
			g_f=(j_new-int(j_new))*(g_d-g_c)+g_c;
			m_pImageBufferFinal[(n*1920+j)*3+2] = (i_new-int(i_new))*(g_e-g_f)+g_f;num++;

			j_new=map_0[num&7][i*1920+j][0];
			i_new=map_0[num&7][i*1920+j][1];
			g_b=sourceImage[((int(i_new)+1)*1280+(int(j_new)+1))*3+1];
			g_a=sourceImage[((int(i_new)+1)*1280+int(j_new))*3+1];
			g_d=sourceImage[(int(i_new)*1280+(int(j_new)+1))*3+1];
			g_c=sourceImage[(int(i_new)*1280+int(j_new))*3+1];
			g_e=(j_new-int(j_new))*(g_b-g_a)+g_a;
			g_f=(j_new-int(j_new))*(g_d-g_c)+g_c;
			m_pImageBufferFinal[(n*1920+j)*3+1] = (i_new-int(i_new))*(g_e-g_f)+g_f;num++;

			j_new=map_0[num&7][i*1920+j][0];
			i_new=map_0[num&7][i*1920+j][1];
			g_b=sourceImage[((int(i_new)+1)*1280+(int(j_new)+1))*3+0];
			g_a=sourceImage[((int(i_new)+1)*1280+int(j_new))*3+0];
			g_d=sourceImage[(int(i_new)*1280+(int(j_new)+1))*3+0];
			g_c=sourceImage[(int(i_new)*1280+int(j_new))*3+0];
			g_e=(j_new-int(j_new))*(g_b-g_a)+g_a;
			g_f=(j_new-int(j_new))*(g_d-g_c)+g_c;
			m_pImageBufferFinal[(n*1920+j)*3+0] = (i_new-int(i_new))*(g_e-g_f)+g_f;num++;
		}
	}*/

	return m_pImageBufferFinal;

}
//标定过程
void CStereoCalibrate::Calibrate()
{
	/*******************************************************两相机分别标定***********************************************/
	for(int i_bigloop=0;i_bigloop<camera_num;i_bigloop++)
	{	
		image_points   = cvCreateMat(n_boards*board_n,2,CV_32FC1);//channel is 1
		object_points  = cvCreateMat(n_boards*board_n,3,CV_32FC1);
		point_counts   = cvCreateMat(n_boards,1,CV_32SC1);

		for( int frame=0; frame<n_boards; frame++ ) 
		{
			//fscanf(fptr,"%s ",names);
			char names[256];
			sprintf(names,"%s%d%s%d%s","camera",i_bigloop,"_",frame+1,".bmp");
			if(image)
			{
				cvReleaseImage(&image);
				image = 0;
			}

			image = cvLoadImage( names);
			if(gray_image == 0  && image) 
				gray_image = cvCreateImage(cvGetSize(image),8,1);
			if(!image)
				printf("null image\n");

			int found = cvFindChessboardCorners(image,board_sz,corners,&corner_count, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);//Get Subpixel accuracy on those corners
			cvCvtColor(image, gray_image, CV_BGR2GRAY);//RGB Image转换成了灰度图
			cvFindCornerSubPix(gray_image, corners, corner_count, 
				cvSize(11,11),cvSize(-1,-1), cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

			if( corner_count == board_n ) 
			{
				step = successes*board_n;
				for( int i=step, j=0; j<board_n; ++i,++j ) 
				{
					CV_MAT_ELEM(*image_points, float,i,0) = corners[j].x;
					CV_MAT_ELEM(*image_points, float,i,1) = corners[j].y;
					CV_MAT_ELEM(*object_points,float,i,0) = j/board_w*corner_width;//(0,0)(0,1)(0,2)......
					CV_MAT_ELEM(*object_points,float,i,1) = j%board_w*corner_width;
					CV_MAT_ELEM(*object_points,float,i,2) = 0.0f;
				}
				CV_MAT_ELEM(*point_counts, int,successes,0) = board_n;		
				successes++;//increase step 
			}
		}	
		//TRANSFER THE POINTS INTO THE CORRECT SIZE MATRICES
		for(int i = 0; i<successes*board_n; ++i)
		{
			CV_MAT_ELEM(*image_points2, float,i,0) 	=	CV_MAT_ELEM(*image_points, float,i,0);
			CV_MAT_ELEM(*image_points2, float,i,1) 	= 	CV_MAT_ELEM(*image_points, float,i,1);
			CV_MAT_ELEM(*object_points2,float,i,0) = CV_MAT_ELEM(*object_points,float,i,0) ;
			CV_MAT_ELEM(*object_points2,float,i,1) = CV_MAT_ELEM(*object_points,float,i,1) ;
			CV_MAT_ELEM(*object_points2,float,i,2) = CV_MAT_ELEM(*object_points,float,i,2) ;

		} 
		for(int i=0; i<successes; ++i)
		{
			CV_MAT_ELEM(*point_counts2,int,i, 0) = CV_MAT_ELEM(*point_counts, int,i,0);
		}
		// Initialize the intrinsic matrix such that the two focal
		// lengths have a ratio of 1.0
		//
		CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0f;
		CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0f;

		double err_calib = cvCalibrateCamera2(object_points2,image_points2,point_counts2,cvGetSize( image ),intrinsic_matrix,distortion_coeffs,rotation_vectors,translation_vectors,0);//CV_CALIB_FIX_ASPECT_RATIO
		printf("平均像素误差:%f\n",err_calib);

		SaveMatrix(num_of_param_name,intrinsic_matrix,distortion_coeffs,translation_vectors,rotation_vectors);

		num_of_file_name++;
		num_of_param_name++;
		//n_boards=0;
		successes = 0;		
	}
	ReleaseAll();
	/*********************************************************标定结束*************************************************************/	
}

void CStereoCalibrate::ReleaseAll()
{
	cvReleaseMat(&intrinsic_matrix);
	cvReleaseMat(&distortion_coeffs);
	cvReleaseMat(&translation_vectors);
	cvReleaseMat(&rotation_vectors);
	cvReleaseMat(&object_points);
	cvReleaseMat(&image_points);
	cvReleaseMat(&point_counts);
}

//保存标定后的矩阵，并存放在.xml文件中
void CStereoCalibrate::SaveMatrix(int n,const CvMat *intrinsic_matrix, const CvMat *distortion_coeffs, const CvMat *translation_vectors, const CvMat *rotation_vectors)
{
	CvMat *intrinsic = 0;
	CvMat *distortion = 0;
	CvMat *translation_vector = 0;
	CvMat *rotation_vector = 0;	

	char tempFilename0[256];
	char tempFilename1[256];
	char tempFilename2[256];
	char tempFilename3[256];

	sprintf(tempFilename0, "Intrinsics%d.xml",n);
	sprintf(tempFilename1, "Distortion%d.xml",n);
	sprintf(tempFilename2, "translation_vectors%d.xml",n);
	sprintf(tempFilename3, "rotation_vectors%d.xml",n);

	cvSave(tempFilename0,intrinsic_matrix);
	cvSave(tempFilename1,distortion_coeffs);
	cvSave(tempFilename2,translation_vectors);
	cvSave(tempFilename3,rotation_vectors);

	intrinsic = (CvMat*)cvLoad(tempFilename0);
	distortion = (CvMat*)cvLoad(tempFilename1);
	translation_vector = (CvMat*)cvLoad(tempFilename2);
	rotation_vector = (CvMat*)cvLoad(tempFilename3);
}

//读取本地文件中的棋盘格标定板图片
void CStereoCalibrate::ChessimageRead(char *temp1,int num_file_name)
{
	//sprintf(tempFilename, "chessboards%d.txt",num_of_file_name);     //输入图片文件在chessboards0.txt和chessboards1.txt中
	char temp0[256]="chessboards";
	char temp2[10]=".txt";
	sprintf(tempFilename,"%s%s%d%s",temp1,temp0,num_of_file_name,temp2);
	fptr = fopen(tempFilename,"r");
		//COUNT THE NUMBER OF IMAGES:
	while(fscanf(fptr,"%s ",names)==1)
	{
			n_boards++;
	}
	rewind(fptr);
}
//获取标定参数
void CStereoCalibrate::GetMatrix()
{
	/*********************************************************标定参数输出*************************************************************/
	left_intrinsic = (CvMat*)cvLoad("Intrinsics1.xml");
	left_distortion = (CvMat*)cvLoad("Distortion1.xml");
	CvMat *left_translation_vector = (CvMat*)cvLoad("translation_vectors1.xml");
	CvMat *left_rotation_vector = (CvMat*)cvLoad("rotation_vectors1.xml");

	right_intrinsic = (CvMat*)cvLoad("Intrinsics2.xml");
	right_distortion = (CvMat*)cvLoad("Distortion2.xml");
	CvMat *right_translation_vector = (CvMat*)cvLoad("translation_vectors2.xml");
	CvMat *right_rotation_vector = (CvMat*)cvLoad("rotation_vectors2.xml");


	left_rotation_matrix  = cvCreateMat(3,3,CV_64FC1);
	left_translation_vector_1  = cvCreateMat(3,1,CV_64FC1);
	CvMat* left_rotation_vector_1  = cvCreateMat(1,3,CV_64FC1);

	right_rotation_matrix   = cvCreateMat(3,3,CV_64FC1);
	right_translation_vector_1  = cvCreateMat(3,1,CV_64FC1);
	CvMat* right_rotation_vector_1  = cvCreateMat(1,3,CV_64FC1);

	cvGetRow(left_translation_vector,left_translation_vector_1,0);//key 从0开始
	cvGetRow(left_rotation_vector,left_rotation_vector_1,0);
	cvRodrigues2(left_rotation_vector_1,left_rotation_matrix);

	cvGetRow(right_translation_vector,right_translation_vector_1,0);
	cvGetRow(right_rotation_vector,right_rotation_vector_1,0);
	cvRodrigues2(right_rotation_vector_1,right_rotation_matrix);
	//以下这些参数作为预校准的输入，内参，旋转矩阵，平移矩阵
	/*cout<<"左相机内参:"<<endl;
	cout<<left_intrinsic->data.fl[0]<<"		";cout<<left_intrinsic->data.fl[1]<<"		";cout<<left_intrinsic->data.fl[2]<<endl;
	cout<<left_intrinsic->data.fl[3]<<"		";cout<<left_intrinsic->data.fl[4]<<"		";cout<<left_intrinsic->data.fl[5]<<endl;
	cout<<left_intrinsic->data.fl[6]<<"		";cout<<left_intrinsic->data.fl[7]<<"		";cout<<left_intrinsic->data.fl[8]<<endl;
	cout<<"右相机内参:"<<endl;
	cout<<right_intrinsic->data.fl[0]<<"		";cout<<right_intrinsic->data.fl[1]<<"		";cout<<right_intrinsic->data.fl[2]<<endl;
	cout<<right_intrinsic->data.fl[3]<<"		";cout<<right_intrinsic->data.fl[4]<<"		";cout<<right_intrinsic->data.fl[5]<<endl;
	cout<<right_intrinsic->data.fl[6]<<"		";cout<<right_intrinsic->data.fl[7]<<"		";cout<<right_intrinsic->data.fl[8]<<endl;
	cout<<"左相机旋转矩阵："<<endl;
	cout<<left_rotation_matrix->data.db[0]<<"		";cout<<left_rotation_matrix->data.db[1]<<"		";cout<<left_rotation_matrix->data.db[2]<<endl;
	cout<<left_rotation_matrix->data.db[3]<<"		";cout<<left_rotation_matrix->data.db[4]<<"		";cout<<left_rotation_matrix->data.db[5]<<endl;
	cout<<left_rotation_matrix->data.db[6]<<"		";cout<<left_rotation_matrix->data.db[7]<<"		";cout<<left_rotation_matrix->data.db[8]<<endl;
	cout<<"右相机旋转矩阵："<<endl;
	cout<<right_rotation_matrix->data.db[0]<<"		";cout<<right_rotation_matrix->data.db[1]<<"		";cout<<right_rotation_matrix->data.db[2]<<endl;
	cout<<right_rotation_matrix->data.db[3]<<"		";cout<<right_rotation_matrix->data.db[4]<<"		";cout<<right_rotation_matrix->data.db[5]<<endl;
	cout<<right_rotation_matrix->data.db[6]<<"		";cout<<right_rotation_matrix->data.db[7]<<"		";cout<<right_rotation_matrix->data.db[8]<<endl;
	cout<<"左相机平移矩阵:"<<endl;
	cout<<left_translation_vector_1->data.db[0]<<"		";cout<<left_translation_vector_1->data.db[1]<<"		";cout<<left_translation_vector_1->data.db[2]<<endl;
	cout<<"右相机平移矩阵:"<<endl;
	cout<<right_translation_vector_1->data.db[0]<<"		";cout<<right_translation_vector_1->data.db[1]<<"		";cout<<right_translation_vector_1->data.db[2]<<endl;*/
	/****************************************************************************************************************************************************/

}

//极线校正，H为校正前后单应性矩阵的过渡矩阵 即Po *H= Pn
void CStereoCalibrate::Rectify()
{
	double Po1_1[3][4] = { left_rotation_matrix->data.db[0], left_rotation_matrix->data.db[1], left_rotation_matrix->data.db[2], left_translation_vector_1->data.db[0],
		                   left_rotation_matrix->data.db[3], left_rotation_matrix->data.db[4], left_rotation_matrix->data.db[5], left_translation_vector_1->data.db[1],
		                   left_rotation_matrix->data.db[6], left_rotation_matrix->data.db[7], left_rotation_matrix->data.db[8], left_translation_vector_1->data.db[2]
	                     };
	
	CvMat* Po1_1_1  = cvCreateMat(3, 4, CV_64FC1);
	cvInitMatHeader(Po1_1_1, 3, 4, CV_64FC1, Po1_1);
	
	CvMat* Po1 = cvCreateMat(3, 4, CV_64FC1);
	cvMatMul(left_intrinsic, Po1_1_1, Po1);

	double Po2_1[3][4] = { right_rotation_matrix->data.db[0], right_rotation_matrix->data.db[1], right_rotation_matrix->data.db[2], right_translation_vector_1->data.db[0],
                     right_rotation_matrix->data.db[3], right_rotation_matrix->data.db[4], right_rotation_matrix->data.db[5], right_translation_vector_1->data.db[1],
                     right_rotation_matrix->data.db[6], right_rotation_matrix->data.db[7], right_rotation_matrix->data.db[8], right_translation_vector_1->data.db[2]

	                };
	CvMat* Po2_1_1 = cvCreateMat(3, 4, CV_64FC1);
	CvMat* Po2 = cvCreateMat(3, 4, CV_64FC1);
	cvInitMatHeader(Po2_1_1, 3, 4, CV_64FC1, Po2_1);
	cvMatMul(right_intrinsic, Po2_1_1, Po2);
	
	CvMat* Po1_1_3=cvCreateMat(3, 3, CV_64FC1);
	
	double Po1_1_3a[3][3] = { Po1->data.db[0], Po1->data.db[1], Po1->data.db[2],
		Po1->data.db[4], Po1->data.db[5], Po1->data.db[6],
		Po1->data.db[8], Po1->data.db[9], Po1->data.db[10]
	};
	
	cvInitMatHeader(Po1_1_3, 3, 3, CV_64FC1, Po1_1_3a);	
	CvMat* Po1_4 = cvCreateMat(3, 1, CV_64FC1);
	double Po1_4a[3][1] = { Po1->data.db[3], 
		Po1->data.db[7],
		Po1->data.db[11]
	};
	cvInitMatHeader(Po1_4, 3, 1, CV_64FC1, Po1_4a);
	
	cvInvert(Po1_1_3, Po1_1_3, CV_LU);//求逆
	CvMat* c1 = cvCreateMat(3, 1, CV_64FC1);
	cvMatMul(Po1_1_3, Po1_4, c1);
	cvConvertScale(c1, c1, -1, 0);
	
	CvMat* Po2_1_3 = cvCreateMat(3, 3, CV_64FC1);	
	double Po2_1_3a[3][3] = { Po2->data.db[0], Po2->data.db[1], Po2->data.db[2],
		Po2->data.db[4], Po2->data.db[5], Po2->data.db[6],
		Po2->data.db[8], Po2->data.db[9], Po2->data.db[10]
	};
	cvInitMatHeader(Po2_1_3, 3, 3, CV_64FC1, Po2_1_3a);
	CvMat* Po2_4 = cvCreateMat(3, 1, CV_64FC1);
	double Po2_4a[3][1] = { Po2->data.db[3],
		Po2->data.db[7],
		Po2->data.db[11]
	};
	cvInitMatHeader(Po2_4, 3, 1, CV_64FC1, Po2_4a);
	
	cvInvert(Po2_1_3, Po2_1_3, CV_LU);
	CvMat* c2 = cvCreateMat(3, 1, CV_64FC1);
	cvMatMul(Po2_1_3, Po2_4, c2);
	cvConvertScale(c2, c2, -1, 0);
	
	CvMat* v1 = cvCreateMat(3, 1, CV_64FC1);
	cvSub(c1, c2, v1, NULL);
	
	CvMat* v2 = cvCreateMat(3, 1, CV_64FC1);
	CvMat* left_rotation_matrix_2 = cvCreateMat(3, 1, CV_64FC1);
	left_rotation_matrix_2 = cvGetRow(left_rotation_matrix, left_rotation_matrix_2, 2);
	
	cvTranspose(left_rotation_matrix_2, v2);
	cvCrossProduct(v2,v1, v2);
	

	CvMat* v3 = cvCreateMat(3, 1, CV_64FC1);
	cvCrossProduct(v1, v2, v3);
	
	CvMat*  v1_1=cvCreateMat(1, 3, CV_64FC1);
	CvMat* v2_1 = cvCreateMat(1, 3, CV_64FC1);
	CvMat* v3_1 = cvCreateMat(1, 3, CV_64FC1);
	cvTranspose(v1, v1_1);
	cvTranspose(v2, v2_1);
	cvTranspose(v3, v3_1);
	
	cvConvertScale(v1_1, v1_1, 1.0 / cvNorm(v1), 0);
	cvConvertScale(v2_1, v2_1, 1.0 / cvNorm(v2), 0);
	cvConvertScale(v3_1, v3_1, 1.0 / cvNorm(v3), 0);
	double R_1[3][3] = { v1_1->data.db[0], v1_1->data.db[1], v1_1->data.db[2],
		                 v2_1->data.db[0], v2_1->data.db[1], v2_1->data.db[2],
		                 v3_1->data.db[0], v3_1->data.db[1], v3_1->data.db[2]};
	CvMat* R = cvCreateMat(3, 3, CV_64FC1);
	cvInitMatHeader(R, 3, 3, CV_64FC1,R_1, CV_AUTOSTEP);
	
	CvMat* A = cvCreateMat(3, 3, CV_64FC1);
	cvAdd(left_intrinsic, right_intrinsic, A, NULL);
	cvConvertScale(A, A, 0.5, 0);
	

	cvmSet(A, 0, 1, 0);/*A->data.db[2] = 0;*/
	
	CvMat* R1_1 = cvCreateMat(3, 1, CV_64FC1);
	cvMatMul(R, c1, R1_1);
	cvConvertScale(R1_1, R1_1, -1, 0);
	double Pn1_1[3][4] = { R->data.db[0], R->data.db[1], R->data.db[2], R1_1->data.db[0],
		R->data.db[3], R->data.db[4], R->data.db[5], R1_1->data.db[1],
		R->data.db[6], R->data.db[7], R->data.db[8], R1_1->data.db[2]
	};
	CvMat* Pn1_1_1 = cvCreateMat(3, 4, CV_64FC1);
	cvInitMatHeader(Pn1_1_1, 3, 4, CV_64FC1, Pn1_1);
	CvMat* Pn1 = cvCreateMat(3, 4, CV_64FC1);
	cvMatMul(A, Pn1_1_1, Pn1);
	

	CvMat* R2_1 = cvCreateMat(3, 1, CV_64FC1);
	cvMatMul(R, c2, R2_1);
	cvConvertScale(R2_1, R2_1, -1, 0);
	double Pn2_1[3][4] = { R->data.db[0], R->data.db[1], R->data.db[2], R2_1->data.db[0],
		                   R->data.db[3], R->data.db[4], R->data.db[5], R2_1->data.db[1],
		                   R->data.db[6], R->data.db[7], R->data.db[8], R2_1->data.db[2]};
	CvMat* Pn2_1_1 = cvCreateMat(3, 4, CV_64FC1);
	cvInitMatHeader(Pn2_1_1, 3, 4, CV_64FC1, Pn2_1);
	CvMat* Pn2 = cvCreateMat(3, 4, CV_64FC1);
	cvMatMul(A, Pn2_1_1, Pn2);
	
	CvMat* T1 = cvCreateMat(3, 3, CV_64FC1);
	CvMat* Pn1_2 = cvCreateMat(3, 3, CV_64FC1);
	
	double Pn1_2a[3][3] = { Pn1->data.db[0], Pn1->data.db[1], Pn1->data.db[2],
		Pn1->data.db[4], Pn1->data.db[5], Pn1->data.db[6],
		Pn1->data.db[8], Pn1->data.db[9], Pn1->data.db[10]
	};

	cvInitMatHeader(Pn1_2, 3, 3, CV_64FC1, Pn1_2a);
	cvMatMul(Pn1_2, Po1_1_3, T1);
	
	CvMat* T2 = cvCreateMat(3, 3, CV_64FC1);
	CvMat* Pn2_2 = cvCreateMat(3, 3, CV_64FC1);
	CvMat* Po2_inv = cvCreateMat(3, 3, CV_64FC1);
	double Pn2_2a[3][3] = { Pn2->data.db[0], Pn2->data.db[1], Pn2->data.db[2],
		Pn2->data.db[4], Pn2->data.db[5], Pn2->data.db[6],
		Pn2->data.db[8], Pn2->data.db[9], Pn2->data.db[10]
	};

	cvInitMatHeader(Pn2_2, 3, 3, CV_64FC1, Pn2_2a);
	cvMatMul(Pn2_2, Po2_1_3, T2);
	
	CvMat* Po1_pinv = cvCreateMat(4, 3, CV_64FC1);
	//CvMat* H1 = cvCreateMat(3, 3, CV_64FC1);
	cvInvert(Po1, Po1_pinv, CV_SVD);
	cvMatMul(Pn1, Po1_pinv, H[0]);
	
	CvMat* Po2_pinv = cvCreateMat(4, 3, CV_64FC1);
	//CvMat* H2 = cvCreateMat(3, 3, CV_64FC1);
	cvInvert(Po2, Po2_pinv, CV_SVD);
	cvMatMul(Pn2, Po2_pinv, H[1]);
	/*cout << H[1]->data.db[0] << "		"; cout << H[1]->data.db[1] << "		"; cout << H[1]->data.db[2] << endl;
	cout << H[1]->data.db[3] << "		"; cout << H[1]->data.db[4] << "		"; cout << H[1]->data.db[5] << endl;
	cout << H[1]->data.db[6] << "		"; cout << H[1]->data.db[7] << "		"; cout << H[1]->data.db[8] << endl;
	cout << endl;	*/
}