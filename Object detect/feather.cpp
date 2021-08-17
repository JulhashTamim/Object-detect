////     ||| Open Source Computer Vision Library |||     \\\\  


//Header files of opencv

#include <opencv2/imgcodecs.hpp>      // To read and write images(imgcodecs)
#include <opencv2/highgui.hpp>        // To operate high level Graphics User Interface (GUI)(highgui)
#include <opencv2/imgproc.hpp>        // for processing an image (imgproc)
#include <iostream>                   // for c++ (input output stream)

using namespace cv;               // for using opencv library functions directly
using namespace std;              //  ..  ..    c++ standard    ..        ..        ..



								   //    COLOR DETECTION     \\

Mat imgHSV, lower, upper, mask;
int huemin = 101; int satmin = 31; int valmin = 248;                   // here lower limit for hue,saturation and value is 0
int huemax = 146; int satmax = 191; int valmax = 255;        // for hue max value is 180, and others like saturation value is 256




void main()
{

	string path = "Resources/purp. feather.jpg";
	Mat image = imread(path);

	cvtColor(image, imgHSV, COLOR_BGR2HSV);                 //Changing the color into HSV why is that? because in HSV it is easier to find the desired color


								  //   Now for finding the exact range we need to use a trackbar inside of a window  \\ which will track the hue,satand val we can change the values in realtime


	namedWindow("Trackbar", (1000, 600));                      // openning an window with the size of 1000w,600h


	// Creating Trackbars of hue, sat, val with max 179 and 255

	createTrackbar("Hue Min", "Trackbar", &huemin, 179);
	createTrackbar("Hue Max", "Trackbar", &huemax, 179);
	createTrackbar("Saturation Min", "Trackbar", &satmin, 255);
	createTrackbar("Saturation Max", "Trackbar", &satmax, 255);
	createTrackbar("Value Min", "Trackbar", &valmin, 255);
	createTrackbar("Value Max", "Trackbar", &valmax, 255);





	while (true)                                    // while we want to use tracker we must use after while otherwise maybe it won't work
	{

		Scalar lower(huemin, satmin, valmin);           // we use this to find lower limit range of an image

		Scalar upper(huemax, satmax, valmax);           // we use this to find upper limit range of an image


		inRange(imgHSV, lower, upper, mask);             // Genrally the color doesn't have only one color it can be drawn by mixed color so for better prospect we use range




		//Displaying

		imshow(" Feather ", image);

		imshow(" Feather HSV ", imgHSV);

		imshow(" Feather detected", mask);





		waitKey(1);

	}


}