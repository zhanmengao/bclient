#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img = cv::imread("browser.png");
	imwrite("browser.icon", img);
}