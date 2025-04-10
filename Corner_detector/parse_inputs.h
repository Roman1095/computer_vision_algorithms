#pragma once
#ifndef PARSE_INPUTS
#define PARSE_INPUTS

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

struct ParseResult {
    Mat I;
    double C;
    double T_angle;
    double sig;
    double H;
    double L;
    bool Endpoint;
    int Gap_size;
};

ParseResult parse_inputs(const vector<string>& args);

#endif // !PARSE_INPUTS
