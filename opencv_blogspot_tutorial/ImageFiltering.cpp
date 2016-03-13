//Eroding, Dilating, Inverting
#include <cv.h>
#include <highgui.h>
int main()
{
        //display the original image
        IplImage* img = cvLoadImage("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/car.jpg");
        cvNamedWindow("MyWindow");
        cvShowImage("MyWindow", img);
        //erode and display the eroded image
        cvErode(img, img, 0, 2);
        cvNamedWindow("Eroded");
        cvShowImage("Eroded", img);
        //put original image into img again
        //img = cvLoadImage("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/car.jpg");
        //dilate and display the dilated image
        cvDilate(img, img, 0, 2);
        cvNamedWindow("Dilated");
        cvShowImage("Dilated", img);
        //put original image into img again
        img = cvLoadImage("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/car.jpg");
        //invert and display the inverted image
        cvNot(img, img);
        cvNamedWindow("Inverted");
        cvShowImage("Inverted", img);

        cvWaitKey(0);
        //cleaning up
        cvDestroyWindow("MyWindow");
        cvDestroyWindow("Dilated");
        cvDestroyWindow("Eroded");
        cvDestroyWindow("Inverted");
        cvReleaseImage(&img);
        return 0;
}