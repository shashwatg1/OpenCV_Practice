// Detect Mouse Clicks and Moves 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
// This function will detect left clicks while pressing "CTRL", right clicks while pressing "SHIFT" and movements while pressing "ALT" key.
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if ( flags == (EVENT_FLAG_CTRLKEY + EVENT_FLAG_LBUTTON) )
		cout << "Left mouse button is clicked while pressing CTRL key - position (" << x << ", " << y << ")" << endl;
	else if ( flags == (EVENT_FLAG_RBUTTON + EVENT_FLAG_SHIFTKEY) )
		cout << "Right mouse button is clicked while pressing SHIFT key - position (" << x << ", " << y << ")" << endl;
	else if ( event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_ALTKEY)
		cout << "Mouse is moved over the window while pressing ALT key - position (" << x << ", " << y << ")" << endl;
}
/* This function simply detecs the mouse events and prints it with the x,y, coordinate. There is no key which needs to be pressed for this.
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if ( event == EVENT_LBUTTONDOWN )
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	else if  ( event == EVENT_RBUTTONDOWN )
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	else if  ( event == EVENT_MBUTTONDOWN )
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	else if ( event == EVENT_MOUSEMOVE )
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
}*/
int main(int argc, char** argv)
{
	// Read image from file 
	Mat img = imread("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/car.jpg");
	//if fail to read the image
	if (img.empty()) 
	{ 
		cout << "Error loading the image" << endl;
		return -1; 
	}
	//Create a window
	namedWindow("My Window", 1);
	//set the callback function for any mouse event
	setMouseCallback("My Window", CallBackFunc, NULL);
	//show the image
	imshow("My Window", img);
	//wait for a key press infinitely
	int c = waitKey(0);
	//if the "esc" key is pressed during the wait, return
	if (c == 27)
		return 0;
}