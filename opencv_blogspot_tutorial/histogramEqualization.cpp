//Histogram Equalization of Grayscale image and colour image
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, const char** argv )
{
    Mat img = imread("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/car.jpg", CV_LOAD_IMAGE_COLOR); //open and read the image
    if (img.empty())
    {
        cout << "Image cannot be loaded..!!" << endl;
        return -1;
    }
    Mat img_gray;
    cvtColor(img, img_gray, CV_BGR2GRAY); //change the color image to grayscale image
    Mat img_hist_gray;
    equalizeHist(img_gray, img_hist_gray); //equalize the histogram
    vector<Mat> channels; 
    Mat img_hist_colour;
    cvtColor(img, img_hist_colour, CV_BGR2YCrCb); //change the color image from BGR to YCrCb format
    split(img_hist_colour,channels); //split the image into channels
    equalizeHist(channels[0], channels[0]); //equalize histogram on the 1st channel (Y)
    merge(channels,img_hist_colour); //merge 3 channels including the modified 1st channel into one image
    cvtColor(img_hist_colour, img_hist_colour, CV_YCrCb2BGR); //change the color image from YCrCb to BGR format (to display image properly)
    //create windows
    namedWindow("Grayscale Image", CV_WINDOW_AUTOSIZE);
    namedWindow("Histogram Equalized Grayscale", CV_WINDOW_AUTOSIZE);
    namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    namedWindow("Histogram Equalized Original", CV_WINDOW_AUTOSIZE);
    //show the image
    imshow("Grayscale Image", img_gray);
    imshow("Histogram Equalized Grayscale", img_hist_gray);
    imshow("Original Image", img);
    imshow("Histogram Equalized Original", img_hist_colour);
    waitKey(0); //wait for key press
    destroyAllWindows(); //destroy all open windows
    return 0;
}