#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;
RNG rng(12345);

int main(){
	std::cout << "WebCam0 detección de bordes mejorada\n";
	VideoCapture cap(0);
	if(!cap.isOpened()){
		std::cout << "Webcam0 error!!!\n";
		return -1;
	}
	std::cout << "Webcam0 open!!!\n";
	Mat frame;
	cap >> frame;

	Mat img_gray;

	cvtColor(frame, img_gray, COLOR_RGB2GRAY);

    Mat img_blur;

    GaussianBlur(img_gray, img_blur, Size (5, 5),0,0);

    Mat img_edge;
    //200 800 black background phillips cam
    Canny(img_gray, img_edge, 100, 400);

    //find contours
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours( img_edge, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0) );
    std::cout << "Contornos detectados: " << contours.size() << endl;
    /// Draw contours
    Mat drawing = Mat::zeros( img_edge.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
        {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
        }



	imwrite("cap.jpg",drawing);

	return 0;
}
