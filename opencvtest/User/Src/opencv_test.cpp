#include "main.h"

void DisplayPicture(void)
{
	IplImage* img = cvLoadImage("lena.png");
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);      //建立并命名窗口
	cvShowImage("Example1", img);                       //在窗口显示图片
	cvWaitKey(0);
	cvReleaseImage(&img);                           //释放图片
	cvDestroyWindow("Example1");                        //释放窗口
}

void AVI_Video(void)
{
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture("toy_plane_liftoff.avi");
	IplImage* frame;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("Example2", frame);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}
