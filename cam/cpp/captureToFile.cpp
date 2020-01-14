#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	std::cout << "Captura desde WebCam0\n";
	VideoCapture cap;
	if(!cap.isOpened()){
		std::cout << "Webcam0 error!!!\n";
		return -1;
	}
	std::cout << "Webcam0 open!!!\n";
	return 0;
}
