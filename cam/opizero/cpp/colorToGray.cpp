#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	std::cout << "Captura desde WebCam0 y conversión a grises\n";
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
	imwrite("cap.jpg",img_gray);

	return 0;
}
