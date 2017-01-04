#include "opencv2\opencv.hpp"
#include "param.h"
#include <iostream>
#include <string>

int Input(std::string s){
	std::cout << s;
	int tmp;
	std::cin >> tmp;
	return tmp;
}

int main(){

	while (1){
		int input = Input("(-1:quit, 0~:cam):");
		if (input == -1)break;
		cv::VideoCapture cap(input);
		if (!cap.isOpened()){
			std::cout << "failed" << std::endl;
			continue;
		}
		cap.set(CV_CAP_PROP_FRAME_WIDTH, CamW);
		cap.set(CV_CAP_PROP_FRAME_HEIGHT, CamH);
		std::cout << "q:quit" << std::endl;
		while (1){
			cv::Mat frame;
			cap >> frame;
			cv::imshow("window", frame);
			int key = cv::waitKey(1);
			if (key == 'q')break;
		}
		cv::destroyAllWindows();
	}


	return 0;
}