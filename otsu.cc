#include <iostream>
#include <cstdlib>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

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

    cout << "channels=" << img.channels() << "\n";

    Mat img_gray, img_bw;

    if( img.channels()==1 ) {
        img.copyTo(img_gray);
    }
    else {
        cvtColor( img, img_gray, COLOR_BGR2GRAY );
    }

    // https://stackoverflow.com/questions/17141535/how-to-use-the-otsu-threshold-in-opencv 

    threshold(img_gray, img_bw, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    imwrite("otsu.png",img_bw);
}

