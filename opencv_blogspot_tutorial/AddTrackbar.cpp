//Add Trackbar with and without Callback Function (without callback function is the commented part in the main)
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat src;
void MyCallbackForBrightness(int iValueForBrightness, void *userData)
{
     Mat dst;
     int iValueForContrast = *( static_cast<int*>(userData) );
     //Calculating brightness and contrast value
     int iBrightness = iValueForBrightness - 50;
     double dContrast = iValueForContrast / 50.0;
     //Calculated contrast and brightness value
     //adjust the brightness and contrast
     src.convertTo(dst, -1, dContrast, iBrightness); 
     //show the brightness and contrast adjusted image
     imshow("My Window", dst);
}
void MyCallbackForContrast(int iValueForContrast, void *userData)
{
     Mat dst;
     int iValueForBrightness = *( static_cast<int*>(userData) );
     //Calculating brightness and contrast value
     int iBrightness = iValueForBrightness - 50;
     double dContrast = iValueForContrast / 50.0;
     //Calculated contrast and brightness value
     //adjust the brightness and contrast
     src.convertTo(dst, -1, dContrast, iBrightness); 
     //show the brightness and contrast adjusted image
     imshow("My Window", dst);
}
int main( int argc, char** argv )
{
	// Read original image 
	src = imread("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/car.jpg");
	//if fail to read the image
	if (!src.data) 
	{ 
		cout << "Error loading the image" << endl;
		return -1; 
	}
	// Create a window
	namedWindow("My Window", 1);
	//Create trackbar to change brightness and contrast
	int iValueForBrightness = 50;
    int iValueForContrast = 50;
    /*The Below section is when we dont use callback function and make use of an infinite loop to continuously update the trackbar values
	createTrackbar("Brightness", "My Window", &iValueForBrightness, 100);
	createTrackbar("Contrast", "My Window", &iValueForContrast, 100);
	while (true)
	{
		//Change the brightness and contrast of the image 
		Mat dst;
		int iBrightness  = iValueForBrightness - 50;
		double dContrast = iValueForContrast / 50.0;
		src.convertTo(dst, -1, dContrast, iBrightness); 
		//show the brightness and contrast adjusted image
		imshow("My Window", dst);
		// Wait until user press some key for 50ms
		int iKey = waitKey(50);
		//if user press 'ESC' key
		if (iKey == 27)
			break;
	}
	return 0;*/
	//This Section is the one with Trackbar Callback function
    //Create track bar to change brightness
    createTrackbar("Brightness", "My Window", &iValueForBrightness, 100, MyCallbackForBrightness, &iValueForContrast);
    //Create track bar to change contrast
    createTrackbar("Contrast", "My Window", &iValueForContrast, 100, MyCallbackForContrast, &iValueForBrightness);  
    imshow("My Window", src);
    // Wait until user press some key
    waitKey(0);
    return 0;
}