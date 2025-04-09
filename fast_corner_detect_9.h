#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>

std::vector<cv::Point> fast_corner_detect_9(const cv::Mat& image, int threshold);