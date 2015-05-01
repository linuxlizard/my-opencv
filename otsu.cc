#include <iostream>
#include <cstdlib>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[] )
{
    if( argc < 2 ) {
        return EXIT_FAILURE;
    }

    cv::Mat img = cv::imread(argv[1],-1);
    if( img.empty() ) {
        return EXIT_FAILURE;
    }

    cv::Mat img_gray, img_bw;

    cv::cvtColor( img, img_gray, cv::COLOR_BGR2GRAY );

    // https://stackoverflow.com/questions/17141535/how-to-use-the-otsu-threshold-in-opencv 

    cv::threshold(img_gray, img_bw, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    cv::imwrite("otsu.png",img_bw);
}

