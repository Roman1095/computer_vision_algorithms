#pragma once
#ifndef CURVE_TANGET
#define CURVE_TANGET

#include <opencv2/opencv.hpp>
#include <cmath>

using namespace cv;
using namespace std;

double curve_tangent(const vector<Point2d>& cur, int center);

#endif // !CURVE_TANGET