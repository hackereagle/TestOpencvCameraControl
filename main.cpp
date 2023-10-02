#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char** argv)
{
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		std::cout << "Cannot open camera" << std::endl;
		return EXIT_FAILURE;
	}

	cv::Mat frame;
	cv::Mat gray;
	bool ret = false;
	std::string winTitle = "Webcam";
	cv::namedWindow(winTitle);
	while (true) {
		ret = cap.read(frame); // cap >> fraem;
		if (!ret) {
			std::cout << "Cannot receive frame (stream end?)! Exiting ..." << std::endl;
			break;
		}

		// cv::imshow(winTitle, frame);
		cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
		cv::imshow(winTitle, gray);

		if (cv::waitKey(1) == 'q') {
			break;
		}
	}
	return EXIT_SUCCESS;
}