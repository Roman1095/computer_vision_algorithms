#include "extract_curve.h"

CurveData extract_curve(const Mat& BW, int Gap_size) {
    CurveData result;
    const int L = BW.rows;
    const int W = BW.cols;

    Mat BW1 = Mat::zeros(L + 2 * Gap_size, W + 2 * Gap_size, CV_8UC1);
    BW(Rect(0, 0, W, L)).copyTo(BW1(Rect(Gap_size, Gap_size, W, L)));

    Mat BW_edge = Mat::zeros(L, W, CV_8UC1);
    vector<Point> points;
    findNonZero(BW1, points);

    result.cur_num = 0;
    vector<vector<Point>>& curves = result.curves;
    vector<Point>& curve_start = result.curve_start;
    vector<Point>& curve_end = result.curve_end;
    vector<String>& curve_mode = result.curve_mode;

    while (!points.empty()) {
        Point point = points[0];
        vector<Point> cur;
        cur.push_back(point);
        BW1.at<uchar>(point) = 0;

        while (true) {
            Rect roi(point.x - Gap_size, point.y - Gap_size, 2 * Gap_size + 1, 2 * Gap_size + 1);
            roi = roi & Rect(0, 0, BW1.cols, BW1.rows);

            vector<Point> neighbors;
            findNonZero(BW1(roi), neighbors);

            if (neighbors.empty()) break;

            for (auto& p : neighbors) p += roi.tl();
            sort(neighbors.begin(), neighbors.end(), [point](const Point& a, const Point& b) {
                return norm(a - point) < norm(b - point);
                });

            point = neighbors[0];
            cur.push_back(point);
            BW1.at<uchar>(point) = 0;
        }

        point = cur[0];
        BW1.at<uchar>(point) = 0;
        while (true) {
            Rect roi(point.x - Gap_size, point.y - Gap_size, 2 * Gap_size + 1, 2 * Gap_size + 1);
            roi = roi & Rect(0, 0, BW1.cols, BW1.rows);

            vector<Point> neighbors;
            findNonZero(BW1(roi), neighbors);

            if (neighbors.empty()) break;

            for (auto& p : neighbors) p += roi.tl();
            sort(neighbors.begin(), neighbors.end(), [point](const Point& a, const Point& b) {
                return norm(a - point) < norm(b - point);
                });

            point = neighbors[0];
            cur.insert(cur.begin(), point);
            BW1.at<uchar>(point) = 0;
        }

        for (auto& p : cur) p -= Point(Gap_size, Gap_size);

        if (cur.size() > (L + W) / 25) {
            curves.push_back(cur);
            curve_start.push_back(cur.front());
            curve_end.push_back(cur.back());

            
            double dist = norm(cur.front() - cur.back());
            curve_mode.push_back(dist <= 5.656 ? "loop" : "line"); 

            
            for (const auto& p : cur) {
                BW_edge.at<uchar>(p) = 255;
            }

            result.cur_num++;
        }

        findNonZero(BW1, points);
    }

    imwrite("edge.jpg", ~BW_edge);

    return result;
}
