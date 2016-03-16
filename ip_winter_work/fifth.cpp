#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <typeinfo>
#include "opencv/cv.h" 
using namespace cv;
using namespace std;
Mat image;
//Conversion to binary, There are Three methods
void CallbackForTrackBar(int thres, void*)
{
    Mat modified(image.rows,image.cols,CV_8UC1); //see it has only one Channel
    for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            if(image.at<uchar>(i,j)<=thres)
                modified.at<uchar>(i,j) = 0;
            else
                modified.at<uchar>(i,j) = 255;
        }
    }
    imshow("modified image",modified);
}
int main(int argc, char* argv[])
{
    image = imread("/home/shashwat/OpenCVPrac/ip_winter_work/image.jpg",0); //see this is grayscale
    //Mat modified(image.rows,image.cols,CV_8UC1); //see it has only one Channel
    int thres;
    namedWindow("Control");
    //createTrackbar("Threshold", "Control", &thres, 255);
    createTrackbar("Threshold", "Control", &thres, 255, CallbackForTrackBar);
    imshow("original image",image);
    /*
    while(1)
    {
        for(int i=0;i<image.rows;i++)
        {
            for(int j=0;j<image.cols;j++)
            {
                if(image.at<uchar>(i,j)<=thres)
                    modified.at<uchar>(i,j) = 0;
                else
                    modified.at<uchar>(i,j) = 255;
            }
        }
        imshow("modified image",modified);
        char c = waitKey(33);//waits for 33 ms then proceeds.
                            //do you know how much time between two frames
                            //our eyes differenciate
        if(c=='q')//if you press q it will exit
            break;
    } */
    waitKey(0);
    return 0;
}
