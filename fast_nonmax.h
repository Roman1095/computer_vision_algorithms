#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>

std::vector<cv::Point> fast_nonmax(const cv::Mat& im, int barrier, const std::vector<cv::Point>& corners);