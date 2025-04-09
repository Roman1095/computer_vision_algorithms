#pragma once
#ifndef MARK_H
#define MARK_H

#include <opencv2/opencv.hpp>

using namespace cv;

Mat mark(const Mat& img, int x, int y, int w);

#endif // !MARK_H
