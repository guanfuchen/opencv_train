#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat dst_img;
    Mat src_img = imread("./data/lena.jpg");
    cvtColor(src_img, dst_img, COLOR_BGR2GRAY);
    cout << "src_img.size:" << src_img.size() << endl;
    cout << "src_img.channels:" << src_img.channels() << endl;
    cout << "dst_img.size:" << dst_img.size() << endl;
    cout << "dst_img.channels:" << dst_img.channels() << endl;
    cout << "src_img.at<Vec3b>(0, 0):" << src_img.at<Vec3b>(0, 0) << endl;
    cout << "int(dst_img.at<uchar>(0, 0)):" << int(dst_img.at<uchar>(0, 0)) << endl;
    return 0;
}
