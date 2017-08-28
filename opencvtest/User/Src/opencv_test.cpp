#include "main.h"

void DisplayPicture(void)
{
	IplImage* img = cvLoadImage("lena.png");
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);      //��������������
	cvShowImage("Example1", img);                       //�ڴ�����ʾͼƬ
	cvWaitKey(0);
	cvReleaseImage(&img);                           //�ͷ�ͼƬ
	cvDestroyWindow("Example1");                        //�ͷŴ���
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
