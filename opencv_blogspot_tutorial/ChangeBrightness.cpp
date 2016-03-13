//Change Brightness of Image or Video 
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
    Mat imgH = img + Scalar(75, 75, 75); //increase the brightness by 75 units
    //img.convertTo(imgH, -1, 1, 75); //equivalent
    Mat imgL = img + Scalar(-75, -75, -75); //decrease the brightness by 75 units
    //img.convertTo(imgL, -1, 1, -75); //equivalent
    namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    namedWindow("High Brightness", CV_WINDOW_AUTOSIZE);
    namedWindow("Low Brightness", CV_WINDOW_AUTOSIZE);
    imshow("Original Image", img);
    imshow("High Brightness", imgH);
    imshow("Low Brightness", imgL);
    waitKey(0);
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
    namedWindow("Original Video",CV_WINDOW_AUTOSIZE); //create a window called "Original Video"
    namedWindow("Brightness Increased",CV_WINDOW_AUTOSIZE); //create a window called "Brightness Increased"
    namedWindow("Brightness Decreased",CV_WINDOW_AUTOSIZE); //create a window called "Brightness Decreased"
    while(1)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video
        if (!bSuccess) //if not success, break loop
        {
        	cout << "Cannot read the frame from video file" << endl;
            break;
        }
        Mat imgH = frame + Scalar(50, 50, 50); //increase the brightness by 75 units
        Mat imgL = frame + Scalar(-50, -50, -50); //decrease the brightness by 75 units
        imshow("Original Video", frame); //show the frame in "Original Video" window
        imshow("Brightness Increased", imgH); //show the frame of which brightness increased
        imshow("Brightness Decreased", imgL); //show the frame of which brightness decreased
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