#include "mark.h"

Mat mark(const Mat& img, int x, int y, int w) {
    Mat img1 = img.clone();
    int half_w = w / 2;

    int x_start = std::max(0, x - half_w);
    int x_end = std::min(img.rows, x + half_w + 1);
    int y_start = std::max(0, y - half_w);
    int y_end = std::min(img.cols, y + half_w + 1);

    int inner_x_start = x_start + 1;
    int inner_x_end = x_end - 1;
    int inner_y_start = y_start + 1;
    int inner_y_end = y_end - 1;

    if (img.type() == CV_8U) { 
        img1(Rect(y_start, x_start, y_end - y_start, x_end - x_start)) =
            (img1(Rect(y_start, x_start, y_end - y_start, x_end - x_start)) < 128) * 255;

        if (inner_x_end > inner_x_start && inner_y_end > inner_y_start) {
            img(Rect(inner_y_start, inner_x_start,
                inner_y_end - inner_y_start,
                inner_x_end - inner_x_start))
                .copyTo(img1(Rect(inner_y_start, inner_x_start,
                    inner_y_end - inner_y_start,
                    inner_x_end - inner_x_start)));
        }
    }
    else if (img.type() == CV_8UC3) { 
        img1(Rect(y_start, x_start, y_end - y_start, x_end - x_start)) = Vec3b(255, 255, 255);

        if (inner_x_end > inner_x_start && inner_y_end > inner_y_start) {
            img(Rect(inner_y_start, inner_x_start,
                inner_y_end - inner_y_start,
                inner_x_end - inner_x_start))
                .copyTo(img1(Rect(inner_y_start, inner_x_start,
                    inner_y_end - inner_y_start,
                    inner_x_end - inner_x_start)));
        }
    }

    return img1;
}