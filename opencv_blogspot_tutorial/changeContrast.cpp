//Change Contrast of Image or Video 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int image()
{
    Mat img = imread("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/car.jpg", CV_LOAD_IMAGE_COLOR);
    if (img.empty())
    {
    	cout << "Image cannot be loaded..!!" << endl;
        return -1;
    }
    Mat imgH;
    img.convertTo(imgH, -1, 2, 0); //increase the contrast (double)
    Mat imgL;
    img.convertTo(imgL, -1, 0.5, 0); //decrease the contrast (halve)
    //create windows
    namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    namedWindow("High Contrast", CV_WINDOW_AUTOSIZE);
    namedWindow("Low Contrast", CV_WINDOW_AUTOSIZE);
    //show the image
    imshow("Original Image", img);
    imshow("High Contrast", imgH);
    imshow("Low Contrast", imgL);
    waitKey(0); //wait for key press
    destroyAllWindows(); //destroy all open windows
    return 0;
}
int video()
{
    VideoCapture cap("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/Elon Musk.MP4"); // open the video file for reading
    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video file" << endl;
        return -1;
    }
    //create windows
    namedWindow("Original Video",CV_WINDOW_AUTOSIZE); 
    namedWindow("Contrast Increased",CV_WINDOW_AUTOSIZE); 
    namedWindow("Contrast Decreased",CV_WINDOW_AUTOSIZE); 
    while (1)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video
        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read the frame from video file" << endl;
            break;
        }
        Mat imgH;
        frame.convertTo(imgH, -1, 2, 0); //increase the contrast (double)
        Mat imgL;
        frame.convertTo(imgL, -1, 0.5, 0); //decrease the contrast (halve)
        //show the image
        imshow("Original Video", frame); 
        imshow("Contrast Increased", imgH); 
        imshow("Contrast Decreased", imgL); 
        if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
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