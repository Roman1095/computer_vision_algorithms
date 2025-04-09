

#include "get_corner.h"
#include "curve_tanget.h"


vector<Point> get_corner(
    const vector<vector<Point>>& curves,
    const vector<Point>& curve_start,
    const vector<Point>& curve_end,
    const vector<string>& curve_mode,
    int curve_num,
    double sig,
    bool Endpoint,
    double C,
    double T_angle) {

    vector<Point> cout;
    const double GaussianDieOff = 0.0001;
    int width = 0;

    double ssq = sig * sig;
    for (int pw = 1; pw <= 30; ++pw) {
        if (exp(-pw * pw / (2 * ssq)) > GaussianDieOff) width = pw;
    }
    if (width == 0) width = 1;

    vector<double> t, gau;
    for (int i = -width; i <= width; ++i) t.push_back(i);
    double sum_gau = 0.0;
    for (auto& ti : t) {
        double val = exp(-ti * ti / (2 * ssq)) / (2 * M_PI * ssq);
        gau.push_back(val);
        sum_gau += val;
    }
    for (auto& g : gau) g /= sum_gau;

    for (int i = 0; i < curve_num; ++i) {
        const auto& curve = curves[i];
        int L = curve.size();
        if (L <= width) continue;

        vector<Point> ext_curve;
        if (curve_mode[i] == "loop") {
            for (int j = L - width; j < L; ++j) ext_curve.push_back(curve[j]);
            ext_curve.insert(ext_curve.end(), curve.begin(), curve.end());
            for (int j = 0; j < width; ++j) ext_curve.push_back(curve[j]);
        }
        else {
            for (int j = width - 1; j >= 0; --j) {
                Point p = { 2 * curve[0].x - curve[j + 1].x,
                          2 * curve[0].y - curve[j + 1].y };
                ext_curve.push_back(p);
            }
            ext_curve.insert(ext_curve.end(), curve.begin(), curve.end());
            for (int j = L - 2; j >= L - width - 1; --j) {
                Point p = { 2 * curve.back().x - curve[j].x,
                          2 * curve.back().y - curve[j].y };
                ext_curve.push_back(p);
            }
        }

        vector<Point> smoothed(ext_curve.size() + gau.size() - 1, {0,0});
        for (size_t n = 0; n < smoothed.size(); ++n) {
            for (size_t k = 0; k < gau.size(); ++k) {
                if (n >= k && (n - k) < ext_curve.size()) {
                    smoothed[n].x += ext_curve[n - k].x * gau[k];
                    smoothed[n].y += ext_curve[n - k].y * gau[k];
                }
            }
        }



        vector<Point> valid(smoothed.begin() + width, smoothed.end() - width);
        vector<double> Xu, Yu, Xuu, Yuu;
        for (size_t j = 0; j < valid.size(); ++j) {
            double dx = (j == valid.size() - 1) ? valid[j].x - valid[j - 1].x :
                (j == 0) ? valid[1].x - valid[0].x :
                (valid[j + 1].x - valid[j - 1].x) / 2;
            double dy = (j == valid.size() - 1) ? valid[j].y - valid[j - 1].y :
                (j == 0) ? valid[1].y - valid[0].y :
                (valid[j + 1].y - valid[j - 1].y) / 2;
            Xu.push_back(dx);
            Yu.push_back(dy);
        }

        vector<double> K;
        for (size_t j = 0; j < Xu.size(); ++j) {
            double ddx = (j == Xu.size() - 1) ? Xu[j] - Xu[j - 1] :
                (j == 0) ? Xu[1] - Xu[0] : (Xu[j + 1] - Xu[j - 1]) / 2;
            double ddy = (j == Yu.size() - 1) ? Yu[j] - Yu[j - 1] :
                (j == 0) ? Yu[1] - Yu[0] : (Yu[j + 1] - Yu[j - 1]) / 2;
            double denominator = pow(Xu[j] * Xu[j] + Yu[j] * Yu[j], 1.5);
            K.push_back(denominator != 0 ? abs((Xu[j] * ddy - ddx * Yu[j]) / denominator) : 0);
        }

        vector<int> extremum;
        int search = 1;
        for (size_t j = 0; j < K.size() - 1; ++j) {
            if ((K[j + 1] - K[j]) * search > 0) {
                extremum.push_back(j);
                search *= -1;
            }
        }

        vector<int> filtered;
        for (size_t j = 1; j < extremum.size(); j += 2) {
            int start = extremum[j - 1];
            int end = j + 1 < extremum.size() ? extremum[j + 1] : K.size() - 1;
            double avg = 0.0;
            for (int k = start; k <= end; ++k) avg += K[k];
            avg /= (end - start + 1);
            if (K[extremum[j]] >= C * avg) filtered.push_back(extremum[j]);
        }

        vector<int> final_corners;
        for (auto ex : filtered) {
            vector<Point> segment;
            int start = max(0, ex - width);
            int end = min((int)valid.size() - 1, ex + width);
            segment.assign(valid.begin() + start, valid.begin() + end + 1);

            vector<Point2d> segment2d;
            for (const auto& p : segment) {
                segment2d.emplace_back(p.x, p.y);
            }

            double angle = curve_tangent(segment2d, ex - start);
            if (angle <= T_angle || angle >= 360 - T_angle) {
                final_corners.push_back(ex - width);
            }
        }

        for (auto idx : final_corners) {
            if (idx >= 0 && idx < L)
            {
                cv::Point temp(curve[idx].y, curve[idx].x);
                cout.push_back(temp);
                //cout.push_back(curve[idx]);
                //std::cout << curve[idx].x << " " << curve[idx].y << std::endl;
            }
        }
    }

    if (Endpoint) {
        for (int i = 0; i < curve_num; ++i) {
            if (curve_mode[i] != "line") continue;

            auto dist = [](Point a, Point b) {
                return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
            };

            bool add_start = true, add_end = true;
            for (auto& p : cout) {
                if (dist(p, curve_start[i]) < 25) add_start = false;
                if (dist(p, curve_end[i]) < 25) add_end = false;
            }

            if (add_start) cout.push_back(curve_start[i]);
            if (add_end) cout.push_back(curve_end[i]);
        }
    }

    return cout;
}



//Оптимизированная функция (уменьшение времени работы на 6-7 секунд (с 37-38 до 31), страдает качество распознования углов в 10 раз)

/*
#include "get_corner.h"
#include "curve_tanget.h"
#include <omp.h>

vector<Point> get_corner(
    const vector<vector<Point>>& curves,
    const vector<Point>& curve_start,
    const vector<Point>& curve_end,
    const vector<string>& curve_mode,
    int curve_num,
    double sig,
    bool Endpoint,
    double C,
    double T_angle)
{
    vector<Point> corners;
    const double GaussianDieOff = 0.0001;

    
    static vector<double> gau_cache;
    static double cached_sig = -1.0;

    if (sig != cached_sig) {
        int width = 0;
        double ssq = sig * sig;
        for (int pw = 1; pw <= 30; ++pw) {
            if (exp(-pw * pw / (2 * ssq)) > GaussianDieOff) width = pw;
        }
        width = max(width, 1);

        vector<double> t(2 * width + 1);
        vector<double> new_gau(2 * width + 1);
        double sum_gau = 0.0;

        for (int i = -width; i <= width; ++i) {
            double val = exp(-i * i / (2 * ssq)) / (2 * M_PI * ssq);
            new_gau[i + width] = val;
            sum_gau += val;
        }

        for (auto& g : new_gau) g /= sum_gau;
        gau_cache.swap(new_gau);
        cached_sig = sig;
    }

    const auto& gau = gau_cache;
    const int width = (gau.size() - 1) / 2;

    
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < curve_num; ++i) {
        const auto& curve = curves[i];
        const int L = curve.size();
        if (L <= width * 2) continue;

        
        vector<Point> ext_curve;
        ext_curve.reserve(L + 2 * width);

        if (curve_mode[i] == "loop") {
            ext_curve.insert(ext_curve.end(), curve.end() - width, curve.end());
            ext_curve.insert(ext_curve.end(), curve.begin(), curve.end());
            ext_curve.insert(ext_curve.end(), curve.begin(), curve.begin() + width);
        }
        else {
            
            for (int j = 0; j < width; ++j) {
                int idx1 = width - j - 1;
                int idx2 = L - 2 - j;
                ext_curve.emplace_back(2 * curve[0].x - curve[idx1].x,
                    2 * curve[0].y - curve[idx1].y);
            }
            ext_curve.insert(ext_curve.end(), curve.begin(), curve.end());
            for (int j = 0; j < width; ++j) {
                int idx = L - 2 - j;
                ext_curve.emplace_back(2 * curve.back().x - curve[idx].x,
                    2 * curve.back().y - curve[idx].y);
            }
        }

        
        Mat ext_x(ext_curve.size(), 1, CV_64F);
        Mat ext_y(ext_curve.size(), 1, CV_64F);

        for (size_t j = 0; j < ext_curve.size(); ++j) {
            ext_x.at<double>(j) = ext_curve[j].x;
            ext_y.at<double>(j) = ext_curve[j].y;
        }

        Mat smooth_x, smooth_y;
        filter2D(ext_x, smooth_x, CV_64F, Mat(gau).t());
        filter2D(ext_y, smooth_y, CV_64F, Mat(gau).t());

        
        Mat dx, dy, dxx, dyy;
        Sobel(smooth_x, dx, CV_64F, 1, 0, 3);
        Sobel(smooth_y, dy, CV_64F, 1, 0, 3);
        Sobel(smooth_x, dxx, CV_64F, 2, 0, 3);
        Sobel(smooth_y, dyy, CV_64F, 2, 0, 3);

        vector<double> K(dx.rows);
        for (int j = 0; j < dx.rows; ++j) {
            const double xu = dx.at<double>(j);
            const double yu = dy.at<double>(j);
            const double xuu = dxx.at<double>(j);
            const double yuu = dyy.at<double>(j);

            const double denominator = pow(xu * xu + yu * yu, 1.5);
            K[j] = denominator > 1e-6 ? fabs(xu * yuu - xuu * yu) / denominator : 0;
        }

        
        vector<int> extremum;
        extremum.reserve(K.size() / 2);
        int state = 0; // 0: поиск минимума, 1: поиск максимума

        for (size_t j = 1; j < K.size(); ++j) {
            const double diff = K[j] - K[j - 1];

            if (state == 0 && diff > 0) {
                extremum.push_back(j - 1);
                state = 1;
            }
            else if (state == 1 && diff < 0) {
                extremum.push_back(j - 1);
                state = 0;
            }
        }

        
        vector<int> filtered;
        filtered.reserve(extremum.size() / 2);

        for (size_t j = 1; j < extremum.size(); j += 2) {
            const int center = extremum[j];
            const int window = width;

            double sum = 0.0;
            int count = 0;
            for (int k = max(0, center - window); k < min((int)K.size(), center + window); ++k) {
                sum += K[k];
                ++count;
            }

            if (count > 0 && K[center] > C * (sum / count)) {
                filtered.push_back(center);
            }
        }

        
        vector<Point> local_corners;
        for (int ex : filtered) {
            const int pos = ex - width;
            if (pos < 0 || pos >= L) continue;

            
            const int window = 5;
            const int start = max(0, ex - window);
            const int end = min((int)K.size(), ex + window);

            double max_val = 0.0;
            for (int k = start; k < end; ++k) {
                if (K[k] > max_val) max_val = K[k];
            }

            if (K[ex] < max_val * 0.9) continue;

            local_corners.push_back(curve[pos]);
        }

        
#pragma omp critical
        {
            corners.insert(corners.end(), local_corners.begin(), local_corners.end());
        }
    }

    
    if (Endpoint) {
        vector<Point> endpoints;
        for (int i = 0; i < curve_num; ++i) {
            if (curve_mode[i] != "line") continue;

            bool add_start = true;
            bool add_end = true;

            
            for (const auto& p : corners) {
                const int dx1 = p.x - curve_start[i].x;
                const int dy1 = p.y - curve_start[i].y;
                const int dx2 = p.x - curve_end[i].x;
                const int dy2 = p.y - curve_end[i].y;

                if (dx1 * dx1 + dy1 * dy1 < 25) add_start = false;
                if (dx2 * dx2 + dy2 * dy2 < 25) add_end = false;
            }

            if (add_start) endpoints.push_back(curve_start[i]);
            if (add_end) endpoints.push_back(curve_end[i]);
        }

        corners.reserve(corners.size() + endpoints.size());
        corners.insert(corners.end(), endpoints.begin(), endpoints.end());
    }

    return corners;
}*/