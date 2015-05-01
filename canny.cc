// From _Learning OpenCV, 2e_
#include <iostream>
#include <cstdlib>
//#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char *argv[] )
{
    if( argc < 2 ) {
        return EXIT_FAILURE;
    }

    cv::Mat img = cv::imread(argv[1],-1);
    if( img.empty() ) {
        return EXIT_FAILURE;
    }

    cv::namedWindow("Example2-in", cv::WINDOW_AUTOSIZE );
    cv::namedWindow("Example2-out", cv::WINDOW_AUTOSIZE );

    cv::Mat img_gray, img_canny;

    if( 1 ) {
        img.copyTo(img_gray);
    }
    else {
        cv::cvtColor( img, img_gray, cv::COLOR_BGR2GRAY );
    }

    cv::GaussianBlur(img_gray,img_gray,cv::Size(5,5),3,3);
    cv::imshow("Example2-in",img_gray);

//    cv::Mat img_pyr, img_pyr2;
//    cv::pyrDown(img_gray,img_pyr);
//    cv::pyrDown(img_pyr,img_pyr2);

//    cv::Canny(img_pyr,img_canny,10,100,3,true);
    cv::Canny(img_gray,img_canny,10,100,3,true);
    cv::imshow("Example2-out",img_canny);

    cv::imwrite("canny.png",img_canny);

    cv::waitKey(0);
    cv::destroyWindow("Example1");
}

