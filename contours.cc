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

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
//    findContours( img_bw, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE, Point(0, 0) );
    findContours( img_bw, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );

    /// Draw contours
    Mat drawing = Mat::zeros( img_bw.size(), CV_8UC3 );
    RNG rng(12345);
    cout << "countours size=" << contours.size() << "\n";
    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        cout << hierarchy[i] << "\n";
        double area = contourArea( contours[i] );
        cout << "area="<<area<<"\n";
        if( area > 100 && area < 1000 ) {
            drawContours( drawing, contours, (int)i, color, 2, 8, hierarchy, 0, Point() );
        }
    }

    imwrite("contours.png",drawing);
}

