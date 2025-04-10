#include "corner.h"
#include "extract_curve.h"
#include "get_corner.h" 

CornerResult corner(const Mat& I, double C, double T_angle, double sig,
    double H, double L, double Endpoint, int Gap_size)
{
    CornerResult result;

    Mat gray;
    if (I.channels() == 3) {
        cvtColor(I, gray, COLOR_BGR2GRAY);
    }
    else {
        gray = I.clone();
    }

    Mat BW;
    Canny(gray, BW, L * 255, H * 255);

    CurveData curve_data = extract_curve(BW, Gap_size);

    vector<vector<Point>> curves = curve_data.curves;
    vector<Point> curve_start = curve_data.curve_start;
    vector<Point> curve_end = curve_data.curve_end;
    vector<String> curve_mode = curve_data.curve_mode;
    int curve_num = curve_data.cur_num;

    result.corners = get_corner(curves,
        curve_start,
        curve_end,
        curve_mode, 
        curve_num,
        sig,
        Endpoint,   
        C,
        T_angle);

    cvtColor(gray, result.marked_img, COLOR_GRAY2BGR);
    for (const auto& corner : result.corners) {
        circle(result.marked_img, corner, 5, Scalar(0, 0, 255), 2);
    }

    return result;
}