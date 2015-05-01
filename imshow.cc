// From _Learning OpenCV, 2e_
#include <iostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[] )
{
    if( argc < 2 ) {
        return EXIT_FAILURE;
    }

    Mat img = imread(argv[1],-1);
    if( img.empty() ) {
        return EXIT_FAILURE;
    }

    namedWindow("Example1", WINDOW_AUTOSIZE );
    imshow("Example1",img);
    waitKey(0);
    destroyWindow("Example1");
}

