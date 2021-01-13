#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat rotate(Mat src, double angle) {

    Mat dst;

    Point2f pt(src.cols / 2., src.rows / 2.);

    // creating Mat object for stroing after rotation         
    Mat r = getRotationMatrix2D(pt, angle, 1.0);

    double abs_cos = abs(r.at<double>(0, 0));
    double abs_sin = abs(r.at<double>(0, 1));
    double height = src.size().height;
    double width = src.size().width;

    int boundW = (int)(height * abs_sin + width * abs_cos);
    int boundH = (int)(height * abs_cos + width * abs_sin);

    r.at<double>(0, 2) += boundW / 2 - width / 2;
    r.at<double>(1, 2) += boundH / 2 - height / 2;

    warpAffine(src, dst, r, Size(boundW, boundH));

    return dst;
}



int main()
{

    Mat src = imread("image.png");

    Mat dst;

    int angle;
    cout << "Enter the angle at which you want to rotate: ";
    cin >> angle;

    dst = rotate(src, angle);

    imshow("src", src);

    imshow("dst", dst);

    waitKey(0);
    return 0;
}