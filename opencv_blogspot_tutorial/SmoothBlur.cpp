/* Smooth / Blur Images
1.  Homogeneous Smoothing
2.  Gaussian Smoothing
3.  Median Smoothing
4.  Bilateral Smoothing */
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int homogeneous()
{
	//create 2 empty windows
	namedWindow( "Original Image" , CV_WINDOW_AUTOSIZE );
	namedWindow( "Smoothed Image" , CV_WINDOW_AUTOSIZE );
	// Load an image from file
	Mat src = imread("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/Blur-Image.png", 1);
	//show the loaded image
	imshow("Original Image", src);
	Mat dst;
	for (int i = 1; i < 31; i = i + 2)
	{ 
		//smooth the image in the "src" and save it to "dst"
		blur( src, dst, Size( i, i ) );
		//show the blurred image with the text
		imshow( "Smoothed Image", dst );
		//wait for a key press infinitely
		int c = waitKey(0);
		//if the "esc" key is pressed during the wait, return
		if (c == 27)
		return 0;
	}
	//wait for a key press infinitely
	waitKey(0);
	return 0;
}
int gaussian()
{
	//create 2 empty windows
	namedWindow( "Original Image" , CV_WINDOW_AUTOSIZE );
	namedWindow( "Smoothed Image" , CV_WINDOW_AUTOSIZE );
	// Load an image from file
	Mat src = imread( "/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/Blur-Image.png", CV_LOAD_IMAGE_UNCHANGED );
	//show the loaded image
	imshow( "Original Image", src );
	Mat dst;
	for ( int i = 1; i  <  31; i = i + 2 )
	{
		//smooth the image using Gaussian kernel in the "src" and save it to "dst"
		GaussianBlur(src, dst, Size( i, i ), 0, 0 );
		//show the blurred image with the text
		imshow( "Smoothed Image", dst );
		//wait for a key press infinitely
		int c = waitKey(0);
		//if the "esc" key is pressed during the wait, return
		if (c == 27)
			return 0;
	}
	//wait for a key press infinitely
	waitKey(0);
	return 0;
}
int median()
{
	//create 2 empty windows
	namedWindow( "Original Image" , CV_WINDOW_AUTOSIZE );
	namedWindow( "Smoothed Image" , CV_WINDOW_AUTOSIZE );
	// Load an image from file
	Mat src = imread( "/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/Blur-Image.png", CV_LOAD_IMAGE_UNCHANGED );
	//show the loaded image
	imshow( "Original Image", src );
	Mat dst;
	for ( int i = 1; i  <  31; i = i + 2 )
	{
		//smooth the image using Median kernel in the "src" and save it to "dst"
		medianBlur( src, dst, i );
		//show the blurred image with the text
		imshow( "Smoothed Image", dst );
		//wait for a key press infinitely
		int c = waitKey(0);
		//if the "esc" key is pressed during the wait, return
		if (c == 27)
			return 0;
	}
	//wait for a key press infinitely
	waitKey(0);
	return 0;
}
int bilateral()
{
	//create 2 empty windows
	namedWindow( "Original Image" , CV_WINDOW_AUTOSIZE );
	namedWindow( "Smoothed Image" , CV_WINDOW_AUTOSIZE );
	// Load an image from file
	Mat src = imread( "/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/Blur-Image.png", CV_LOAD_IMAGE_UNCHANGED );
	//show the loaded image
	imshow( "Original Image", src );
	Mat dst;
	for ( int i = 1; i  <  31; i = i + 2 )
	{ 
		//smooth the image using Bilateral filter in the "src" and save it to "dst"
		bilateralFilter( src, dst, i, i, i);
		//show the blurred image with the text
		imshow( "Smoothed Image", dst );
		//wait for a key press infinitely
		int c = waitKey(0);
		//if the "esc" key is pressed during the wait, return
		if (c == 27)
			return 0;
	}
	waitKey(0);
	return 0;
}
int main()
{
	int choice=0;
	cout << "Homogeneous -> 1, Gaussian -> 2, Median -> 3, Bilateral -> 4\n";
	cin >> choice;
	switch(choice)
	{
		case 1:
		homogeneous();
		break;
		case 2:
		gaussian();
		break;
		case 3:
		median();
		break;
		case 4:
		bilateral();
		break;
		default:
		cout << "Incorrect input";
	}
}