#include <iostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[] )
{
    cv::namedWindow("Camera", cv::WINDOW_AUTOSIZE );
    cv::VideoCapture cap;
    cap.open(0);

    if( !cap.isOpened() ) {
        std::cerr << "failed to open camera\n";
        return EXIT_FAILURE;
    }

    cv::Mat frame;
    cv::Mat img_gray, img_canny;

    while(1) {
        cap >> frame;
        if( !frame.data ) {
            break;
        }
        cv::cvtColor( frame, img_gray, cv::COLOR_BGR2GRAY );
//        cv::GaussianBlur(img_gray,img_gray,cv::Size(5,5),3,3);
//        cv::Canny(img_gray,img_canny,10,100,3,true);

//        cv::imshow("Camera",img_canny);
        cv::imshow("Camera",frame);
        if( cv::waitKey(33) >=0 ) {
            cv::imwrite("camera.png",frame);
            break;
        }
    }
}

