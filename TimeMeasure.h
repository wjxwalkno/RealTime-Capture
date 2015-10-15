// TimeMeasure.h: interface for the TimeMeasure class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMEMEASURE_H__3C66B7ED_3280_438D_9362_339FB068F5A3__INCLUDED_)
#define AFX_TIMEMEASURE_H__3C66B7ED_3280_438D_9362_339FB068F5A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std ;
class TimeMeasure  
{
	
public:
	TimeMeasure();
	static void MeasureBegin(string &str) ;
	static int MeasureEnd() ;

	virtual ~TimeMeasure();
	
private:
	static string mTitle ;//记录测量内容
	static clock_t mBeginTime ;//记录开始时间
	static int mTimeSlot ;//记录时间间隔
	static FILE* mOut ;
//	static bool bOpen ;
};

#endif // !defined(AFX_TIMEMEASURE_H__3C66B7ED_3280_438D_9362_339FB068F5A3__INCLUDED_)
