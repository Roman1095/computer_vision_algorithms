#pragma once
#ifndef GET_CORNER
#define GET_CORNER
#define M_PI 3.14

#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>

using namespace cv;
using namespace std;

vector<Point> get_corner(
    const vector<vector<Point>>& curves,
    const vector<Point>& curve_start,
    const vector<Point>& curve_end,
    const vector<string>& curve_mode, // string גלוסעמ String
    int curve_num,
    double sig,
    bool Endpoint,
    double C,
    double T_angle);

#endif // !GET_CORNER
