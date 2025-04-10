#pragma once
#ifndef CORNEER_H
#define CORNER_H

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

struct CornerResult {
    vector<Point> corners;  
    Mat marked_img;
};

CornerResult corner(const Mat& I, double C, double T_angle, double sig,
    double H, double L, double Endpoint, int Gap_size);

#endif // !CORNEER_H
