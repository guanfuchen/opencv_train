#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

inline bool exists_file (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char** argv )
{
    string image_path = "../../data/lena.jpg";
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        if(exists_file(image_path)) {
            cout << "loading..." << endl;
        } else {
            return -1;
        }
    } else {
        image_path = argv[1];
    }
    Mat image;
    image = imread( image_path, 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    Size size = Size();
    cout << size << endl;
    Mat image_gray;
    Mat image_gray_fpt;
    float sig_diff;
    float sigma = 1.6f;
    float SIFT_INIT_SIGMA = 0.5f;
    cvtColor(image, image_gray, COLOR_BGR2GRAY);
    image_gray.convertTo(image_gray_fpt, DataType<float>::type, 1, 0);
    sig_diff = sqrtf( max(sigma * sigma - SIFT_INIT_SIGMA * SIFT_INIT_SIGMA, 0.01f) );
    GaussianBlur(image_gray_fpt, image_gray_fpt, Size(), sig_diff, sig_diff);
    int image_gray_fpt_rows = image_gray_fpt.rows;
    int image_gray_fpt_cols = image_gray_fpt.cols;
    cout << "image_gray_fpt_rows:" << image_gray_fpt_rows << ",image_gray_fpt_cols:" << image_gray_fpt_cols << endl;
    int image_gray_rows = image_gray.rows;
    int image_gray_cols = image_gray.cols;
    cout << "image_gray_rows:" << image_gray_rows << ",image_gray_cols:" << image_gray_cols << endl;

    // 矩阵相关操作
    Mat A = Mat::ones(2, 3, CV_32FC1);
    Mat B = Mat::ones(3, 2, CV_32FC1);
    Mat C = A*B;
    cout << "C:" << C << endl;
    Mat A_dot = Mat::ones(1, 3, CV_32FC1);
    Mat B_dot = Mat::ones(1, 3, CV_32FC1);
    double C_dot = A_dot.dot(B_dot);
    cout << "C_dot:" << C_dot << endl;

    Mat A_mul = Mat::ones(1, 3, CV_32FC1);
    Mat B_mul = Mat::ones(1, 3, CV_32FC1);
    Mat C_mul = A_mul.mul(B_mul);
    cout << "C_mul:" << C_mul << endl;
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}







