#include "fast_nonmax.h"


std::vector<cv::Point> fast_nonmax(const cv::Mat& im, int barrier, const std::vector<cv::Point>& corners) {
    int ysize = im.rows;
    int xsize = im.cols;

    std::vector<cv::Point> dir = {
        {0, 3}, {1, 3}, {2, 2}, {3, 1},
        {3, 0}, {3, -1}, {2, -2}, {1, -3},
        {0, -3}, {-1, -3}, {-2, -2}, {-3, -1},
        {-3, 0}, {-3, 1}, {-2, 2}, {-1, 3}
    };

    std::vector<int> centres;
    for (const auto& corner : corners) {
        centres.push_back(corner.y + corner.x * ysize);
    }

    cv::Mat scores = cv::Mat::zeros(im.size(), CV_32F);

    for (int i = 0; i < centres.size(); ++i) {
        int centre = centres[i];
        int y = centre % ysize;
        int x = centre / ysize;

        float pos = 0, neg = 0;
        for (const auto& d : dir) {
            int ny = y + d.y;
            int nx = x + d.x;

            if (nx >= 0 && nx < xsize && ny >= 0 && ny < ysize) {
                float p1 = im.at<float>(ny, nx) - (im.at<float>(y, x) + barrier);
                pos += p1 * (p1 > 0);

                float n1 = im.at<float>(y, x) - barrier - im.at<float>(ny, nx);
                neg += n1 * (n1 > 0);
            }
        }

        scores.at<float>(y, x) = std::max(pos, neg);
    }

    std::vector<int> cs(centres.size(), 0);

    int up = -1;
    int down = 1;
    int left = -ysize;
    int right = ysize;

    for (int i = 0; i < centres.size(); ++i) {
        int p = centres[i];
        int y = p % ysize;
        int x = p / ysize;

        std::vector<int> square = {
            p + up, p + down, p + left, p + right,
            p + up + left, p + up + right, p + down + left, p + down + right
        };

        bool is_maxima = true;
        for (int s : square) {
            int sy = s % ysize;
            int sx = s / ysize;

            if (sx >= 0 && sx < xsize && sy >= 0 && sy < ysize) {
                if (scores.at<float>(y, x) < scores.at<float>(sy, sx)) {
                    is_maxima = false;
                    break;
                }
            }
        }

        cs[i] = is_maxima ? 1 : 0;
    }

    std::vector<cv::Point> maximas;
    for (int i = 0; i < centres.size(); ++i) {
        if (cs[i]) {
            int y = centres[i] % ysize;
            int x = centres[i] / ysize;
            maximas.emplace_back(x, y);
        }
    }

    return maximas;
}
