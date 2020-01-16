#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

Mat rotate(Mat src, double angle)
{
    Mat dst;
    Point2f pt(src.cols/2., src.rows/2.);    
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(src, dst, r, Size(src.cols, src.rows));
    return dst;
}

int main(){
	std::cout << "Captura desde WebCam0\n";
	VideoCapture cap(0);
	if(!cap.isOpened()){
		std::cout << "Webcam0 error!!!\n";
		return -1;
	}
	std::cout << "Webcam0 open!!!\n";
	Mat frame;
	cap >> frame;

	Mat img_rotated;
    	//img_rotated = rotate(frame, 180);
	flip(rotate(frame,180), img_rotated, 1);

	Mat img_edge;
	Canny(img_rotated, img_edge, 40, 200);
	imwrite("cap.jpg", img_edge);

	return 0;
}
