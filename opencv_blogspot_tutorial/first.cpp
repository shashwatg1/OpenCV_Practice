//Read Image from File and Display Also create and Blank Image and Display
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
     Mat img = imread("/home/shashwat/OpenCVPrac/opencv_blogspot_tutorial/image.jpg", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "image.jpg" and store it in 'img'
     //The above line loads an image into the Mat img
     //We can also create a blank image by the below syntax
     Mat img2(500, 1000, CV_8UC3, Scalar(0,0, 100)); //create an image ( 3 channels, 8 bit image depth, 500 high, 1000 wide, (0, 0, 100) assigned for Blue, Green and Red plane respectively. )

     if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image1 cannot be loaded..!!" << endl;
          //system("pause"); //wait for a key press
          return -1;
     }

     namedWindow("MyWindow1", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow1"
     imshow("MyWindow1", img); //display the image which is stored in the 'img' in the "MyWindow1" window

     if (img2.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image2 cannot be loaded..!!" << endl;
          //system("pause"); //wait for a key press
          return -1;
     }

     namedWindow("MyWindow2", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow2"
     imshow("MyWindow2", img2); //display the image which is stored in the 'img' in the "MyWindow2" window

     waitKey(0); //wait infinite time for a keypress

     destroyWindow("MyWindow1"); //destroy the window with the name, "MyWindow1"
     destroyWindow("MyWindow2"); //destroy the window with the name, "MyWindow2"

     return 0;
}