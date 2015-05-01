/* Convert an image into three planes of CIELab
 * 
 * davep 17-Jan-2013
 *
 */
#include <iostream>
#include <string>
#include <array>
#include <iterator>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main( int argc, char *argv[] )
{
    if( argc < 2 ) {
        return EXIT_FAILURE;
    }

    Mat img = imread(argv[1],-1);
    if( img.empty() ) {
        return EXIT_FAILURE;
    }

    Mat img_lab;

    cvtColor( img, img_lab, CV_LBGR2Lab);

    Mat Lab[3];
    split( img_lab, Lab );

    array<string,3> filename { { "L.png", "a.png", "b.png" } };
    auto fname_iter = filename.begin();
    for( int i=0 ; i<3 ; i++ ) {
        cout << Lab[i].rows << " " << Lab[i].cols << "\n";
        imwrite( *fname_iter, Lab[i]);
        cout << "wrote " << *fname_iter << "\n";
        ++fname_iter;
    }
}

