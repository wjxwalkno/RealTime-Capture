// TimeMeasure.cpp: implementation of the TimeMeasure class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "TimeMeasure.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
string TimeMeasure::mTitle ;
clock_t TimeMeasure::mBeginTime ;
int TimeMeasure::mTimeSlot ;
FILE* TimeMeasure::mOut=0 ;
//bool TimeMeasure::bOpen =false;
TimeMeasure::TimeMeasure()
{

}

TimeMeasure::~TimeMeasure()
{
	
}
void TimeMeasure::MeasureBegin(string &str) 
{
	TimeMeasure::mTitle=str ;//���ü�ʱ����
	TimeMeasure::mBeginTime=clock() ;//��ȡʱ��

}
int TimeMeasure::MeasureEnd()
{
	TimeMeasure::mTimeSlot=(int)(clock()-mBeginTime) ;
	try{
		TimeMeasure::mOut=fopen("TimeMeasure.log","a+") ;
		fseek(TimeMeasure::mOut,0,SEEK_END) ;//�ƶ����ļ���β
	}catch(...){
		cout<<"�ļ����쳣��"<<endl ;
	}
	char sTmp[256] ;
	memset(sTmp,'\0',256) ;
	sprintf(sTmp,"%s:%d ms!\r\n",TimeMeasure::mTitle.data(),TimeMeasure::mTimeSlot) ;

	try{
		fwrite(sTmp,strlen(sTmp),1,TimeMeasure::mOut) ;
	}catch(...){
		cout<<"�ļ���ȡ�쳣��"<<endl ;
	}
	fflush(TimeMeasure::mOut) ;
	fclose(TimeMeasure::mOut) ;
	return TimeMeasure::mTimeSlot ;
}