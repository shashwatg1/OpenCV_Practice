//  Rotate Image & Video using Trackbar
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int iAngle = 180;
int iScale = 50;
int iBorderMode = 0;
Mat imgOriginal ;
int iImageCenterY = 0;
int iImageCenterX = 0;
void CallbackForTrackBar(int, void*)
{
	Mat matRotation = getRotationMatrix2D(Point(iImageCenterX, iImageCenterY),(iAngle-180),iScale/50.0);
	// Rotate the image
	Mat imgRotated;
	warpAffine( imgOriginal, imgRotated, matRotation, imgOriginal.size(), INTER_LINEAR, iBorderMode, Scalar() );
	imshow( "Rotated Image", imgRotated );
}
int image()
{
	// Load the image
	imgOriginal = imread( "/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/car.jpg", 1 );
	iImageCenterY = imgOriginal.rows / 2;
	iImageCenterX = imgOriginal.cols / 2;
	//show the original image
	namedWindow( "Original Image", CV_WINDOW_AUTOSIZE );
	imshow( "Original Image", imgOriginal );
	//create the "Rotated Image" window and 3 trackbars in it
	namedWindow( "Rotated Image", CV_WINDOW_AUTOSIZE );
	createTrackbar("Angle", "Rotated Image", &iAngle, 360, CallbackForTrackBar);
	createTrackbar("Scale", "Rotated Image", &iScale, 100, CallbackForTrackBar);
	createTrackbar("Border Mode", "Rotated Image", &iBorderMode, 5, CallbackForTrackBar);
	int iDummy = 0;
	CallbackForTrackBar(iDummy, &iDummy);
	waitKey(0);
	return 0;
}
int video()
{
	// open the video file for reading
	VideoCapture cap("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/TestVideo.avi"); 
	// if not success, exit program
	if ( !cap.isOpened() )  
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}
	namedWindow("Original Video", CV_WINDOW_AUTOSIZE); 
	namedWindow( "Rotated Video", CV_WINDOW_AUTOSIZE );
	int iAngle = 180;
	createTrackbar("Angle", "Rotated Video", &iAngle, 360);
	while (true)
	{
		Mat matOriginalFrame;
		// read a new frame from video
		bool bSuccess = cap.read(matOriginalFrame); 
		//if not success, break loop
		if (!bSuccess) 
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}
		imshow("Original Video", matOriginalFrame);
		//get the affine transformation matrix
		Mat matRotation = getRotationMatrix2D( Point(matOriginalFrame.cols / 2, matOriginalFrame.rows / 2), (iAngle - 180), 1 ); 
		// Rotate the image
		Mat matRotatedFrame;
		warpAffine( matOriginalFrame, matRotatedFrame, matRotation, matOriginalFrame.size() );
		imshow( "Rotated Video", matRotatedFrame );
		//wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		if (waitKey(30) == 27) 
		{
			cout << "esc key is pressed by user" << endl; 
			break; 
		}
	}
	return 0;
}
int main()
{
	int choice=0;
	cout << "Image -> press 1, Video -> press 2\n";
	cin >> choice;
	switch(choice)
	{
		case 1:
		image();
		break;
		case 2:
		video();
		break;
		default:
		cout << "Incorrect input";
	}
}