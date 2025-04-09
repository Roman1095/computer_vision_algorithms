#include "fast_corner_detect_9.h"

std::vector<cv::Point> fast_corner_detect_9(const cv::Mat& im, int threshold) {

    int xsize = im.cols;
    int ysize = im.rows;
    std::vector<cv::Point> corners; 
    int nc = 0; //Для подсчета углов
   

    for (int x = 4; x < xsize - 3; ++x) {

        for (int y = 4; y < ysize - 3; ++y) {

            int cb = im.at<uchar>(y, x) + threshold; 
            int c_b = im.at<uchar>(y, x) - threshold; 

            // Проверка условий
            if (im.at<uchar>(y + 0, x + 3) > cb) {
                if (im.at<uchar>(y + (-3), x + 1) > cb) {
                    if (im.at<uchar>(y + 2, x + 2) > cb) {//64
                        if (im.at<uchar>(y + (-2), x + (-2)) > cb) {
                            if (im.at<uchar>(y + (-1), x + 3) > cb) {
                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                    if (im.at<uchar>(y + (-2), x + 2) > cb) {
                                        if (im.at<uchar>(y - 3, x + 0) > cb) {
                                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                
                                            }
                                            else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                continue; 
                                            }
                                            else {
                                                if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                       
                                                    }
                                                    else {
                                                        continue; 
                                                    }
                                                }
                                                else {
                                                    continue; 
                                                }
                                            }
                                        }
                                        else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                            continue; 
                                        }
                                        else {
                                            if (im.at<uchar>(y + 3, x + (-1)) > cb) {
                                                if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {

                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else if (im.at<uchar>(y + (-2), x + 2) < c_b) {
                                        continue;
                                    }
                                    else {//101
                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                            if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                        if (im.at<uchar>(y + 3, x + 1) > cb) {

                                                        }
                                                        else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                            continue;
                                                        }
                                                        else {
                                                            if (im.at<uchar>(y - 1, x - 3) > cb) {
                                                                if (im.at<uchar>(y - 3, x - 1) > cb) {

                                                                }
                                                                else {
                                                                    continue;
                                                                }
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }

                                                    }
                                                    else if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                        continue;
                                                    }
                                                    else { //121
                                                        if (im.at<uchar>(y - 1, x - 3) > cb) {
                                                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                                if (im.at<uchar>(y + 0, x - 3) > cb) {

                                                                }
                                                                else {
                                                                    continue;
                                                                }
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else if (im.at<uchar>(y + 1, x + 3) < c_b) { continue; }
                                else {
                                    if (im.at<uchar>(y + 0, x - 3) > cb) {
                                        if (im.at<uchar>(y - 1, x - 3) > cb) {
                                            if (im.at<uchar>(y - 2, x + 2) > cb) {
                                                if (im.at<uchar>(y - 3, x + 0) > cb) {

                                                }
                                                else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    continue;
                                                }
                                                else { //154
                                                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                        if (im.at<uchar>(y + 1, x - 3) > cb) {

                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                    if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                        if (im.at<uchar>(y + 2, x - 2) > cb) {

                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        //180
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            //187
                            else if (im.at<uchar>(y - 1, x + 3) < c_b) { continue; }
                            else {// 189
                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                            if (im.at<uchar>(y + 3, x - 1) > cb) { //193
                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                    if (im.at<uchar>(y + 1, x + 3) > cb) {

                                                    }
                                                    else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                        continue;
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y + 1, x - 3) > cb) {

                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 1, x - 3) > cb) {

                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else if (im.at<uchar>(y + 3, x - 1) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y - 2, x + 2) > cb) {
                                                    if (im.at<uchar>(y - 1, x - 3) > cb) {
                                                        if (im.at<uchar>(y - 3, x - 1) > cb) {

                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }

                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }

                        }
                        // 238 - 346 

                        //238
                        else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                            if (im.at<uchar>(y + 3, x - 1) > cb) {
                                if (im.at<uchar>(y - 1, x + 3) > cb) {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        if (im.at<uchar>(y - 2, x + 2) > cb) {
                                            if (im.at<uchar>(y + 3, x + 1) > cb) {
                                            
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                            continue;
                                        }
                                        else {
                                            if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                    continue;
                                }
                                else {
                                    if (im.at<uchar>(y + 0, x - 3) > cb) {
                                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else if (im.at<uchar>(y + 3, x - 1) < c_b) {
                                if (im.at<uchar>(y - 3, x - 1) > cb) {
                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                        if (im.at<uchar>(y - 2, x + 2) > cb) {
                                            if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                    if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                            if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y - 3, x + 0) > cb) {
                                    if (im.at<uchar>(y + 3, x + 0) > cb) {
                                        if (im.at<uchar>(y - 2, x + 2) > cb) {
                                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                        continue;
                                    }
                                    else {
                                        if (im.at<uchar>(y - 3, x - 1) > cb) {
                                            if (im.at<uchar>(y - 2, x + 2) > cb) {
                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }                       
                        //346
                        else { //348 - 457

                            if (im.at<uchar>(y + 3, x + 1) > cb) {
                                if (im.at<uchar>(y - 1, x + 3) > cb) {
                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                                            if (im.at<uchar>(y - 2, x + 2) > cb) {
                                                if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                    
                                                }
                                                else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                            if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                    continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                if (im.at<uchar>(y - 2, x + 2) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                    
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                        if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else if (im.at<uchar>(y + 3, x - 1) < c_b) {
                                            continue;
                                        }
                                        else {
                                            if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                    if (im.at<uchar>(y - 2, x + 2) > cb) {
                                                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                        
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                }
                                else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                    continue;
                                }
                                else {
                                    if (im.at<uchar>(y + 0, x - 3) > cb) {
                                        if (im.at<uchar>(y + 2, x - 2) > cb) {
                                            if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                    
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                        }

                    }
                    else if (im.at<uchar>(y + 2, x + 2) < c_b) { //462
                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                            
                            if (im.at<uchar>(y + 0, x - 3) > cb) {
                                if (im.at<uchar>(y - 1, x - 3) > cb) {
                                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                                        if (im.at<uchar>(y - 2, x + 2) > cb) {
                                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y + 0, x - 3) < c_b) {

                                if (im.at<uchar>(y - 1, x - 3) > cb) {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }

                            }

                            else {

                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                    if (im.at<uchar>(y - 1, x - 3) > cb) {
                                        if (im.at<uchar>(y - 1, x + 3) > cb) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }

                            }

                        }
                        else if (im.at<uchar>(y - 2, x - 2) < c_b) { //513

                            if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                        if (im.at<uchar>(y + 3, x - 1) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }

                        }
                        else { //542

                            if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 3, x - 1) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                if (im.at<uchar>(y - 2, x + 2) > cb) {
                                                    if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                        if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                        
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }

                        }
                    }
                    else {

                        if (im.at<uchar>(y - 1, x - 3) > cb) { //577
                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                if (im.at<uchar>(y - 2, x - 2) > cb) {
                                    if (im.at<uchar>(y - 2, x + 2) > cb) {
                                        if (im.at<uchar>(y - 3, x + 0) > cb) {
                                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                   
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                    if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                            continue;
                                        }
                                        else {
                                            if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                    if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                        continue;
                                    }
                                    else {
                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                            if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                    if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                        if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y + 1, x + 3) < c_b) {

                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }

                            }
                            else {//655
                                if (im.at<uchar>(y + 0, x - 3) > cb) {

                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                        if (im.at<uchar>(y - 2, x + 2) > cb) {
                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                    if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                        
                                                    }
                                                    else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                        continue;
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                            if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                            continue;
                                        }
                                        else {
                                            if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                    if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                            if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                                
                                                            }
                                                            else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                                continue;
                                                            }
                                                            else {
                                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                                    
                                                                }
                                                                else {
                                                                    continue;
                                                                }
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else if (im.at<uchar>(y - 1, x - 3) < c_b) { //725
                            
                            if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                    if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                            if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                    if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else {
                            continue;
                        }
                    }
                }
                //758
                else if (im.at<uchar>(y - 3, x + 1) < c_b) {

                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                if (im.at<uchar>(y + 3, x + 0) > cb) {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                        continue;
                                    }
                                    else {
                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                            if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                    if (im.at<uchar>(y + 3, x + 0) > cb) {
                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        //843
                        else if (im.at<uchar>(y + 1, x - 3) < c_b) {
                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                if (im.at<uchar>(y - 2, x + 2) > cb) {
                                
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }

                        else {

                            if (im.at<uchar>(y - 2, x + 2) > cb) {
                                if (im.at<uchar>(y - 1, x - 3) > cb) {
                                    if (im.at<uchar>(y - 3, x + 0) > cb || im.at<uchar>(y - 3, x + 0) < c_b) {
                                        continue;
                                    }
                                    else {
                                        if (im.at<uchar>(y - 1, x + 3) > cb) {
                                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 3, x + 0) > cb) {
                                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                                            if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {
                                continue;
                            }

                        }

                    }
                    else if (im.at<uchar>(y + 2, x - 2) < c_b) { // 899
                        
                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                            if (im.at<uchar>(y + 3, x - 1) > cb) {
                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y + 3, x - 1) < c_b) {//910
                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                    if (im.at<uchar>(y - 2, x - 2) > cb) {
                                        continue;
                                    }
                                    else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                    continue;
                                                }
                                                else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    
                                                }
                                                else {
                                                    if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                    if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }

                            }
                            else { //950
                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                    if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                        if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                            if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                    if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }

                        }
                        else {
                            continue;
                        }
                    }
                    //979
                    else {

                        if (im.at<uchar>(y - 1, x + 3) < c_b) {
                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                        if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                               
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else {
                            continue;
                        }
                    }
                }
                else { //1005

                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                if (im.at<uchar>(y + 1, x - 3) > cb) {
                                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                    
                                                }
                                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                    if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                            continue;
                                                        }
                                                        else {
                                                            if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                            continue;
                                        }
                                        else {
                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                        if (im.at<uchar>(y - 1, x - 3) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                        continue;
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                            if (im.at<uchar>(y - 1, x - 3) > cb) {
                                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                                    
                                                                }
                                                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                                    continue;
                                                                }
                                                                else {
                                                                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                                        
                                                                    }
                                                                    else {
                                                                        continue;
                                                                    }
                                                                }
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y - 2, x + 2) > cb) {
                                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                if (im.at<uchar>(y + 0, x - 3) < c_b) {

                                }
                                else {
                                    continue;
                                }
                            }
                            else {

                                if (im.at<uchar>(y + 0, x - 3) > cb) {//1120
                                    if (im.at<uchar>(y + 1, x - 3) > cb) {
                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                        
                                                    }
                                                    else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                        continue;
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                            if (im.at<uchar>(y - 1, x - 3) > cb) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                        continue;
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else {
                            continue;
                        }
                    }
                    else if (im.at<uchar>(y + 2, x - 2) < c_b) {//1180

                        if (im.at<uchar>(y + 3, x + 0) < c_b) {
                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                        continue;
                                    }
                                    else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                            continue;
                                        }
                                        else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                    if (im.at<uchar>(y + 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                    if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                            if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                    if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                        if (im.at<uchar>(y + 3, x - 1) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                    if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                        if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                    if (im.at<uchar>(y + 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else {
                            continue;
                        }
                    }
                    else {
                        continue;
                    }
                }
            }
            // 1283
            else if (im.at<uchar>(y + 0, x + 3) < c_b) {

                if (im.at<uchar>(y + 3, x - 1) > cb) {
                    if (im.at<uchar>(y - 1, x - 3) > cb) {
                        if (im.at<uchar>(y - 3, x - 1) > cb) {
                            if (im.at<uchar>(y + 1, x - 3) > cb) {
                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                    if (im.at<uchar>(y + 0, x - 3) > cb) {
                                        if (im.at<uchar>(y + 2, x - 2) > cb) {
                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                            continue;
                                        }
                                        else {
                                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                    if (im.at<uchar>(y - 3, x + 1) > cb) {
                                        if (im.at<uchar>(y + 0, x - 3) > cb) {
                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                        continue;
                                    }
                                    else {
                                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                                            if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y - 3, x + 1) > cb) {
                                        if (im.at<uchar>(y + 0, x - 3) > cb) {
                                            if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                        continue;
                                    }
                                    else {
                                        if (im.at<uchar>(y - 3, x + 0) > cb) {
                                            if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                            if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                        if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                            if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                    if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                        if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                            if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {
                                if (im.at<uchar>(y - 2, x - 2) > cb) {
                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                            if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else {
                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                if (im.at<uchar>(y - 2, x - 2) > cb) {
                                    if (im.at<uchar>(y + 0, x - 3) > cb) {
                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                            if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                            if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                    if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                    }
                    //1552
                    else if (im.at<uchar>(y - 1, x - 3) < c_b) {

                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                            if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                    if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                        if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                            if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                if (im.at<uchar>(y - 1, x + 3) > cb) {
                                    continue;
                                }
                                else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                        if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 2, x + 2) > cb || im.at<uchar>(y + 2, x + 2) < c_b) {
                                            continue;
                                        }
                                        else {
                                            if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else {
                            if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                    }
                    else {
                        if (im.at<uchar>(y + 2, x + 2) < c_b) {
                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                continue;
                            }
                            else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                    if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                        if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                    if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                        continue;
                                    }
                                    else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                        if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                            if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }

                        }
                        else {
                            continue;
                        }
                    }
                }
                //1712
                else if (im.at<uchar>(y + 3, x - 1) < c_b) {

                    if (im.at<uchar>(y - 2, x + 2) > cb) {
                        if (im.at<uchar>(y + 0, x - 3) > cb) {
                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                if (im.at<uchar>(y + 1, x - 3) > cb) {
                                    if (im.at<uchar>(y - 3, x + 1) > cb) {
                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                if (im.at<uchar>(y + 1, x - 3) > cb) {
                                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                                        if (im.at<uchar>(y - 1, x - 3) > cb) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y + 2, x - 2) > cb) {
                                    if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else if (im.at<uchar>(y + 0, x - 3) < c_b) {
                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                continue;
                            }
                            else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        continue;
                                    }
                                    else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                        if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y - 3, x - 1) < c_b) {

                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else {
                            if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                    
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                    }
                    //1805
                    else if (im.at<uchar>(y - 2, x + 2) < c_b) {
                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                            if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                            if (im.at<uchar>(y - 1, x + 1) > cb) {
                                continue;
                            }
                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                if (im.at<uchar>(y - 3, x + 1) > cb) {
                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                            continue;
                                        }
                                        else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                
                                            }
                                            else {
                                                if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                            if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {//1905

                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                
                                            }
                                            else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                    continue;
                                                }
                                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                        continue;
                                                    }
                                                    else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                        if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                        if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else {//1957

                            if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y - 3, x + 0) > cb) {
                                            continue;
                                        }
                                        else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                    continue;
                                                }
                                                else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                    if (im.at<uchar>(y - 3, x + 1) > cb) {
                                                        continue;
                                                    }
                                                    else if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                               
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else {
                                                    if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                    continue;
                                                }
                                                else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                        if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                            if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                                if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                                    
                                                                }
                                                                else {
                                                                    continue;
                                                                }
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                    }
                    //2031
                    else {
                        if (im.at<uchar>(y + 1, x - 3) < c_b) {
                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                if (im.at<uchar>(y + 2, x + 2) > cb) {
                                    continue;
                                }
                                else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                                            continue;
                                        }
                                        else if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                    continue;
                                                }
                                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                    
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                        if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                            if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                    if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                            if (im.at<uchar>(y - 3, x + 1) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                    if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                        if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                            continue;
                                                        }
                                                        else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                            if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                                    if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                                        
                                                                    }
                                                                    else {
                                                                        continue;
                                                                    }
                                                                }
                                                                else {
                                                                    continue;
                                                                }
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {
                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                        continue;
                                    }
                                    else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                        if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                    continue;
                                                }
                                                else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        continue;
                                                    }
                                                    else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                           
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                            if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                                continue;
                                                            }
                                                            else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                                
                                                            }
                                                            else {
                                                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                                    
                                                                }
                                                                else {
                                                                    continue;
                                                                }
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                            if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        continue;
                                                    }
                                                    else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                        if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                            if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                                continue;
                                                            }
                                                            else if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                                
                                                            }
                                                            else {
                                                                if (im.at<uchar>(y + 1, x + 3) > cb || im.at<uchar>(y + 1, x + 3) < c_b) {
                                                                    continue;
                                                                }
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y - 3, x + 1) > cb) {
                                                            continue;
                                                        }
                                                        else if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                                if (im.at<uchar>(y + 1, x + 3) > cb || im.at<uchar>(y + 1, x + 3) < c_b) {
                                                                    continue;
                                                                }
                                                                else {
                                                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                                        
                                                                    }
                                                                    else {
                                                                        continue;
                                                                    }
                                                                }
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }

                        }
                        else {
                            continue;
                        }
                    }
                }
                // 2267
                else {

                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                        if (im.at<uchar>(y - 2, x + 2) > cb) {
                            if (im.at<uchar>(y + 2, x - 2) > cb) {
                                if (im.at<uchar>(y - 1, x - 3) > cb) {
                                    if (im.at<uchar>(y - 2, x - 2) > cb) {
                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                            if (im.at<uchar>(y - 3, x + 1) > cb) {
                                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                if (im.at<uchar>(y + 1, x - 3) > cb) {
                                    if (im.at<uchar>(y - 1, x + 3) > cb) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y - 1, x + 3) > cb) {
                                    if (im.at<uchar>(y + 1, x - 3) > cb) {
                                        if (im.at<uchar>(y - 1, x - 3) > cb) {
                                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                if (im.at<uchar>(y + 0, x - 3) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else {
                            continue;
                        }
                    }
                    else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                        if (im.at<uchar>(y + 2, x + 2) > cb) {
                            if (im.at<uchar>(y + 0, x - 3) > cb) {
                                if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                    if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                    if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                        if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        //2379
                        else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                            if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                    if (im.at<uchar>(y + 1, x - 3) > cb) {
                                        continue;
                                    }
                                    else if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                        if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        continue;
                                    }
                                    else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                        if (im.at<uchar>(y - 3, x - 1) > cb) {
                                            
                                        }
                                        else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                            if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                    continue;
                                                }
                                                else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                    
                                                }
                                                else {
                                                    if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                        if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                    if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                            if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 1, x + 3) > cb) {
                                            continue;
                                        }
                                        else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                        if (im.at<uchar>(y + 3, x + 0) > cb || im.at<uchar>(y + 3, x + 0) < c_b) {
                                                            continue;
                                                        }
                                                        else {
                                                            if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                    if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                        if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                            continue;
                                                        }
                                                        else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                                if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                                    
                                                                }
                                                                else {
                                                                    continue;
                                                                }
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else {
                            if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                    if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                        if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                    if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                        if (im.at<uchar>(y - 1, x + 3) > cb) {
                                            continue;
                                        }
                                        else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                    if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {//2583
                                    if (im.at<uchar>(y + 0, x - 3) < c_b) {
                                        if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                            if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                    if (im.at<uchar>(y - 1, x + 3) > cb) {
                                                        continue;
                                                    }
                                                    else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                                        if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {
                                continue;
                            }
                        }
                    }
                    else {
                        continue;
                    }
                }
            }
            else {//2622

                if (im.at<uchar>(y + 0, x - 3) > cb) {
                    if (im.at<uchar>(y - 3, x + 1) > cb) {
                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                            if (im.at<uchar>(y - 1, x - 3) > cb) {
                                if (im.at<uchar>(y + 2, x - 2) > cb) {
                                    if (im.at<uchar>(y - 2, x + 2) > cb) {
                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                    
                                                }
                                                else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                            continue;
                                        }
                                        else {
                                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                        if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                    }
                                    else if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                                            if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                
                                            }
                                            else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                        
                                                    }
                                                    else if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                        continue;
                                                    }
                                                    else {
                                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                            if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                                
                                                            }
                                                            else {
                                                                continue;
                                                            }
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                }
                                                else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                    continue;
                                                }
                                                else {
                                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                continue;
                                            }
                                            else {
                                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                                    if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                        if (im.at<uchar>(y - 1, x + 3) > cb) {
                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                            
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y - 1, x + 3) > cb) {
                                        if (im.at<uchar>(y - 2, x + 2) > cb) {
                                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                    if (im.at<uchar>(y - 3, x + 0) > cb) {
                                                    
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else {
                            continue;
                        }
                    }
                    //2784
                    else if (im.at<uchar>(y - 3, x + 1) < c_b) {

                        if (im.at<uchar>(y + 2, x + 2) > cb) {
                            if (im.at<uchar>(y - 1, x - 3) > cb) {
                                if (im.at<uchar>(y + 3, x - 1) > cb) {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                            if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                        continue;
                                    }
                                    else {
                                        if (im.at<uchar>(y - 2, x - 2) > cb) {
                                            if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                            if (im.at<uchar>(y + 3, x + 1) > cb) {
                                if (im.at<uchar>(y - 3, x - 1) > cb) {
                                    
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else {
                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                if (im.at<uchar>(y + 3, x + 1) > cb) {
                                    if (im.at<uchar>(y + 3, x + 0) > cb) {
                                        
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }

                    }
                    //2854
                    else {
                        if (im.at<uchar>(y + 3, x + 0) > cb) {
                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                if (im.at<uchar>(y + 2, x - 2) > cb) {
                                    if (im.at<uchar>(y + 3, x + 1) > cb) {
                                        if (im.at<uchar>(y + 1, x - 3) > cb) {
                                            if (im.at<uchar>(y - 1, x - 3) > cb) {
                                                if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                       
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                        continue;
                                    }
                                    else {
                                        if (im.at<uchar>(y - 3, x + 0) > cb) {
                                            if (im.at<uchar>(y - 1, x - 3) > cb) {
                                                if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                        if (im.at<uchar>(y - 3, x - 1) > cb) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                if (im.at<uchar>(y - 1, x - 3) > cb) {
                                    if (im.at<uchar>(y + 1, x + 3) > cb) {
                                        if (im.at<uchar>(y + 3, x - 1) > cb) {
                                            if (im.at<uchar>(y + 2, x - 2) > cb) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                    if (im.at<uchar>(y - 1, x - 3) > cb) {
                                        if (im.at<uchar>(y + 2, x - 2) > cb) {
                                            if (im.at<uchar>(y + 2, x + 2) > cb) {
                                                if (im.at<uchar>(y + 1, x - 3) > cb) {
                                                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                                        
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else {
                            continue;
                        }
                    }
                }
                else if (im.at<uchar>(y + 0, x - 3) < c_b) {//2965
                    if (im.at<uchar>(y + 3, x - 1) > cb) {
                        if (im.at<uchar>(y - 1, x + 3) > cb) {
                            continue;
                        }
                        else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                    if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                        if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else {
                            if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                    if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                        if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                continue;
                            }
                        }
                    }
                    //3020
                    else if (im.at<uchar>(y + 3, x - 1) < c_b) {
                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                            if (im.at<uchar>(y - 3, x - 1) > cb) {
                                if (im.at<uchar>(y + 1, x + 3) > cb) {
                                    continue;
                                }
                                else if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                    if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                    continue;
                                                }
                                                /*else {

                                                }*/
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                    if (im.at<uchar>(y + 2, x - 2) > cb) {
                                        continue;
                                    }
                                    else if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 3, x + 1) > cb) {
                                            if (im.at<uchar>(y - 3, x + 1) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                
                                            }
                                            else {
                                                if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                    
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y - 2, x - 2) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y + 3, x + 0) > cb) {
                                                    continue;
                                                }
                                                else if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                    
                                                }
                                                else {
                                                    if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                        if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                                    if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                        else {
                                            if (im.at<uchar>(y - 3, x + 1) > cb) {
                                                continue;
                                            }
                                            else if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                    if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                    if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                        if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y - 2, x + 2) < c_b) {
                                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                        if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if (im.at<uchar>(y + 2, x + 2) < c_b) {
                                    if (im.at<uchar>(y - 2, x - 2) > cb) {
                                        if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                        
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                            if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                    if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                    
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        if (im.at<uchar>(y + 1, x + 3) < c_b) {
                                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                                if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                                    if (im.at<uchar>(y + 3, x + 1) < c_b) {
                                                        if (im.at<uchar>(y + 3, x + 0) < c_b) {
                                                        
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                        else {
                            continue;
                        }
                    }
                    else {//3207
                        if (im.at<uchar>(y - 2, x + 2) < c_b) {
                            if (im.at<uchar>(y + 1, x - 3) < c_b) {
                                if (im.at<uchar>(y - 1, x + 3) > cb) {
                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                            
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else if (im.at<uchar>(y - 1, x + 3) < c_b) {
                                    if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                        if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                            if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                    if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                        
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                                else {
                                    if (im.at<uchar>(y + 2, x - 2) < c_b) {
                                        if (im.at<uchar>(y - 3, x + 1) < c_b) {
                                            if (im.at<uchar>(y - 1, x - 3) < c_b) {
                                                if (im.at<uchar>(y - 3, x - 1) < c_b) {
                                                    if (im.at<uchar>(y - 2, x - 2) < c_b) {
                                                        if (im.at<uchar>(y - 3, x + 0) < c_b) {
                                                            
                                                        }
                                                        else {
                                                            continue;
                                                        }
                                                    }
                                                    else {
                                                        continue;
                                                    }
                                                }
                                                else {
                                                    continue;
                                                }
                                            }
                                            else {
                                                continue;
                                            }
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                            else {
                                continue;
                            }
                        }
                        else {
                            continue;
                        }
                    }
                }
                else {
                    continue;
                }
            }
            //nc = nc + 1;
            if (nc >= corners.size()) {
                corners.resize(corners.size() * 2); 
            }

            corners.emplace_back(x, y);

            //corners[nc] = cv::Point(x, y);
            nc = nc + 1;
        }

    }
    corners.resize(nc);

 
    return corners;
}