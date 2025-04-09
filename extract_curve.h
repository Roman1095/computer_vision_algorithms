#pragma once
#ifndef EXTRACT_CURVE
#define EXTRACT_CURVE

#include <opencv2/opencv.hpp>
#include <vector>
#include <algorithm>

using namespace cv;
using namespace std;

struct CurveData {
    vector<vector<Point>> curves;
    vector<Point> curve_start;
    vector<Point> curve_end;
    vector<string> curve_mode; 
    int cur_num;
};

CurveData extract_curve(const Mat& BW, int Gap_size);

#endif // !EXTRACT_CURVE
