#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {

	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("C:/Users/HS/Desktop/1.jpg", 1);
	if (srcMat.empty()) return -1;

	float angle = -10, scale = 1;

	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);

	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	cv::imshow("1", srcMat);
	cv::imshow("2", dstMat);
	cv::waitKey(0);
}