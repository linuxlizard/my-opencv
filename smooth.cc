// From _Learning OpenCV, 2e_
#include <iostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>

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

    cv::imshow("Example2-in",img);

    cv::Mat img_out;
    cv::GaussianBlur(img,img_out,cv::Size(5,5),3,3);
    cv::GaussianBlur(img_out,img_out,cv::Size(5,5),3,3);

    cv::imshow("Example2-out",img_out);

    cv::waitKey(0);
    cv::destroyWindow("Example1");
}

