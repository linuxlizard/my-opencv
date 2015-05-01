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

    cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE );
    cv::imshow("Example1",img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");
}

