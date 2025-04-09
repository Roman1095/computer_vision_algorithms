

#include "curve_tanget.h"

double curve_tangent(const vector<Point2d>& cur, int center) {
    vector<double> directions(2);
    const double EPS = 1e-8;

    for (int i = 0; i < 2; ++i) {
        vector<Point2d> segment;
        if (i == 0) {
            segment.insert(segment.end(), cur.rend() - center - 1, cur.rend());
        }
        else {
            segment.insert(segment.end(), cur.begin() + center, cur.end());
        }

        int L = segment.size();
        if (L < 2) {
            directions[i] = 0.0;
            continue;
        }

        Point2d p1, p2, p3;
        if (L > 3) {
            if (norm(segment.front() - segment.back()) > EPS) {
                int M = L / 2;
                p1 = segment[0];
                p2 = segment[M];
                p3 = segment.back();
            }
            else {
                int M1 = L / 3;
                int M2 = 2 * L / 3;
                p1 = segment[0];
                p2 = segment[M1];
                p3 = segment[M2];
            }

            double collinear_test = (p1.x - p2.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p1.y - p2.y);
            if (abs(collinear_test) < EPS) {
                Vec2d vec = p3 - p1;
                directions[i] = fastAtan2(vec[1], vec[0]);
            }
            else {
                double denominator = ((p1.y - p2.y) * (p1.x - p3.x) - (p1.y - p3.y) * (p1.x - p2.x));
                if (abs(denominator) < EPS) {
                    directions[i] = fastAtan2(p3.y - p1.y, p3.x - p1.x);
                    continue;
                }

                double x0 = 0.5 * ((p3.x * p3.x - p2.x * p2.x + p3.y * p3.y - p2.y * p2.y) * (p1.y - p2.y)
                    - (p2.x * p2.x - p1.x * p1.x + p2.y * p2.y - p1.y * p1.y) * (p1.y - p3.y)) / denominator;

                double y0 = 0.5 * ((p2.x * p2.x - p1.x * p1.x + p2.y * p2.y - p1.y * p1.y) * (p1.x - p3.x)
                    - (p3.x * p3.x - p2.x * p2.x + p3.y * p3.y - p2.y * p2.y) * (p1.x - p2.x)) / denominator;

                Vec2d radius_vec(p1.x - x0, p1.y - y0);
                double radius_dir = fastAtan2(radius_vec[1], radius_vec[0]);

                Vec2d adj_vec(p2.x - p1.x, p2.y - p1.y);
                double adj_dir = fastAtan2(adj_vec[1], adj_vec[0]);

                double sign = sin(adj_dir * CV_PI / 180 - radius_dir * CV_PI / 180) > 0 ? 1.0 : -1.0;
                directions[i] = radius_dir + sign * 90.0;
            }
        }
        else {
            Vec2d vec = segment.back() - segment.front();
            directions[i] = fastAtan2(vec[1], vec[0]);
        }

        directions[i] = fmod(directions[i] + 360.0, 360.0);
    }

    double angle_diff = abs(directions[0] - directions[1]);
    return min(angle_diff, 360.0 - angle_diff);
}


//Оптимизация, прироста нет

/*
#include "curve_tanget.h"
#include <cmath>


namespace {
    constexpr double EPS = 1e-8;
    constexpr double PI_180 = CV_PI / 180.0;
    thread_local cv::Vec4d coeff_cache; 
}

double curve_tangent_optimized(const std::vector<cv::Point2d>& cur, int center) {
    double directions[2] = { 0.0, 0.0 };
    const int directions_count = 2;

    
    const double eps_sq = EPS * EPS;
    const int curve_size = static_cast<int>(cur.size());

    
    for (int i = 0; i < directions_count; ++i) {
        const bool reverse = (i == 0);
        const int start_idx = reverse ? std::max(0, center - 1) : center;
        const int end_idx = reverse ? 0 : curve_size - 1;
        const int step = reverse ? -1 : 1;

        
        if (curve_size < 2 || start_idx == end_idx) {
            directions[i] = 0.0;
            continue;
        }

        
        const cv::Point2d& p1 = reverse ? cur[center] : cur[start_idx];
        const cv::Point2d& p3 = reverse ? cur[0] : cur[end_idx];

        
        if (curve_size > 3) {
            const int mid_idx = reverse ?
                center - (center - start_idx) / 2 :
                start_idx + (end_idx - start_idx) / 2;

            const cv::Point2d& p2 = cur[mid_idx];
            const double dx1 = p2.x - p1.x;
            const double dy1 = p2.y - p1.y;
            const double dx2 = p3.x - p1.x;
            const double dy2 = p3.y - p1.y;

            
            const double cross = dx1 * dy2 - dx2 * dy1;

            if (std::abs(cross) < eps_sq) {
                
                const cv::Vec2d vec = p3 - p1;
                directions[i] = cv::fastAtan2(vec[1], vec[0]);
                continue;
            }

            
            const double A = p2.x * p2.x + p2.y * p2.y - p1.x * p1.x - p1.y * p1.y;
            const double B = p3.x * p3.x + p3.y * p3.y - p1.x * p1.x - p1.y * p1.y;
            const double denominator = 2.0 * (dx1 * dy2 - dx2 * dy1);

            if (std::abs(denominator) < EPS) {
                directions[i] = cv::fastAtan2(p3.y - p1.y, p3.x - p1.x);
                continue;
            }

            const double x0 = (A * dy2 - B * dy1) / denominator;
            const double y0 = (B * dx1 - A * dx2) / denominator;

            
            const double rx = p1.x - x0;
            const double ry = p1.y - y0;
            const double radius_dir = cv::fastAtan2(ry, rx);

            
            const double adj_dir = cv::fastAtan2(dy1, dx1);

            
            const double angle_diff = (adj_dir - radius_dir) * PI_180;
            const double sign = std::sin(angle_diff) > 0 ? 1.0 : -1.0;
            directions[i] = radius_dir + sign * 90.0;
        }
        else {
            
            const cv::Vec2d vec = p3 - p1;
            directions[i] = cv::fastAtan2(vec[1], vec[0]);
        }

        
        directions[i] = std::fmod(directions[i] + 360.0, 360.0);
    }

    
    const double angle_diff = std::abs(directions[0] - directions[1]);
    return std::min(angle_diff, 360.0 - angle_diff);
}*/