/*#include <iostream>
#include "fast_corner_detect_9.h"
#include "fast_nonmax.h"

int main() {
    
    cv::Mat img = cv::imread("D:\\opencv project\\FAST\\w.jpg", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cerr << "Could not read the image!" << std::endl;
        return 1;
    }

    
    cv::Mat im_float;
    img.convertTo(im_float, CV_32F);

    
    std::vector<cv::Point> cs = fast_corner_detect_9(img, 30); 

    
    std::vector<cv::Point> c = fast_nonmax(im_float, 30, cs);

    
    cv::Mat display_img;
    cv::cvtColor(img, display_img, cv::COLOR_GRAY2BGR); 

    
    for (const auto& p : cs) {
        cv::circle(display_img, p, 2, cv::Scalar(0, 0, 255), -1); 
    }

    for (const auto& p : c) {
        cv::circle(display_img, p, 2, cv::Scalar(0, 255, 0), -1); 
    }

    
    cv::putText(display_img, "Red: 9pt FAST", cv::Point(10, 20),
        cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255));
    cv::putText(display_img, "Green: Nonmax-suppressed", cv::Point(10, 40),
        cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0));

    
    cv::imshow("FAST Corner Detection", display_img);

    // Сохранение изображения
    cv::imwrite("D:\\opencv project\\FAST\\result.jpg", display_img);  // Укажите путь и имя файла по желанию

    cv::waitKey(0);

    return 0;
}*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include "fast_corner_detect_9.h"
#include "fast_nonmax.h"

int main() {
    
    cv::VideoCapture cap(0); 
    if (!cap.isOpened()) {
        std::cerr << "Could not open the video stream or file!" << std::endl;
        return -1;
    }

    
    cv::Mat frame, im_float;

    while (true) {
        
        cap >> frame;

        
        if (frame.empty()) {
            break;
        }

        
        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        gray.convertTo(im_float, CV_32F); 

        // Обнаружение углов
        std::vector<cv::Point> cs = fast_corner_detect_9(gray, 30);
        std::vector<cv::Point> c = fast_nonmax(im_float, 30, cs);

        
        for (const auto& p : cs) {
            cv::circle(frame, p, 2, cv::Scalar(0, 0, 255), -1); // Красный для всех углов
        }
        for (const auto& p : c) {
            cv::circle(frame, p, 2, cv::Scalar(0, 255, 0), -1); // Зеленый для не-максимумного подавления
        }

        
        cv::imshow("FAST Corner Detection", frame);

        
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    
    cap.release();
    cv::destroyAllWindows();

    return 0;
}

