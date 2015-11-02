#ifndef STEREOCALIBRATE_H
#define STEREOCALIBRATE_H

#include <opencv2/opencv.hpp>
#include "global-SC.h"
class CStereoCalibrate
{

public:
	CStereoCalibrate();
	~CStereoCalibrate();

	/**标定过程
	 * @param temp1:txt文件所在路径
	 */
	void Calibrate();

	//获取标定参数
	void GetMatrix();
	void Rectify();

	//源图像进行校正变换
	void SCProcessing(int numCamera,PBYTE sourceImage,PBYTE targetImage);


private:

	//参数初始化
	void Initial();
	void ReleaseAll();



	//保存标定后的矩阵，并存放在.xml文件中
	void SaveMatrix(int n,const CvMat *intrinsic_matrix, const CvMat *distortion_coeffs, const CvMat *translation_vectors, const CvMat *rotation_vectors);

	//读取本地文件中的棋盘格标定板图片
	void ChessimageRead(char tempFilename[],int num_file_name);

public:
	CvMat *left_intrinsic;
	CvMat *left_distortion;
	CvMat *left_translation_vector_1;
	CvMat *right_intrinsic;
	CvMat *right_distortion;
	CvMat *right_translation_vector_1;
	CvMat *left_rotation_matrix;
	CvMat *right_rotation_matrix;

private:
	CvMat* object_points2;
	CvMat* image_points2;
	CvMat* point_counts2;
	CvMat* intrinsic_matrix;
	CvMat* distortion_coeffs;
	CvMat* rotation_vectors;
	CvMat* translation_vectors ;
	CvMat* image_points;//channel is 1
	CvMat* object_points;
	CvMat* point_counts;

	//BYTE * m_pImageBufferFinal[2];
	CvMat* H[2];
	float map_0[8][1920*1080][2];
	double roi_to[1920*1080][2];
	//double t[3][3];


	CvSize board_sz;
	CvPoint2D32f* corners;//一张图片的理论角点数目 board_n
	int corner_count;
	int successes;
	int step;
	int n_board; //总图片数
	int n_boards;              
	int num_of_file_name;
	int num_of_param_name;
	char tempFilename[256];
	FILE *fptr;
	char names[2048];
	IplImage* image;
	IplImage* gray_image;
};
	
#endif

//使用例子：
//int main()
//{
//	CStereoCalibrate* stereo=new CStereoCalibrate();
//	stereo->Calibrate("C:\\Users\\Administrator\\Desktop\\中航项目\\StereoCalibration\\StereoCalibration\\StereoCalibration\\StereoCalibration\\");
//
//	stereo->GetMatrix();
//
//
//
//}