////     ||| Open Source Computer Vision Library |||     \\\\  



//Header files of opencv

#include <opencv2/imgcodecs.hpp>      // To read and write images(imgcodecs)
#include <opencv2/highgui.hpp>        // To operate high level Graphics User Interface (GUI)(highgui)
#include <opencv2/imgproc.hpp>        // for processing an image (imgproc)
#include <iostream>                   // for c++ (input output stream)

using namespace cv;               // for using opencv library functions directly
using namespace std;              //  ..  ..    c++ standard    ..        ..        ..

void main()
{

	string path = "Resources/Alone.jpg";      //Its defines the path of our image

	Mat img = imread(path);                       // for reading image from this path



									 //     || BASIC FUNCTIONS ||    \\

					// cvtColor(), GaussianBlur(), Canny(), dilate(), erode() \\

	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;         // Taking varriables

	cvtColor(img, imgGray, COLOR_BGR2GRAY);    // cvtColor -> Convertion of color function 
													   // COLOR_BGR -> Color of blue green red to gray 
	GaussianBlur(img, imgBlur, Size(3, 3), 5, 0);   // GaussianBlur -> bluring an image Size(wid,heig),sigmaX,sigmaY//

	Canny(img, imgCanny, 34, 76);        // for detecting the edges here 34 and 76 are threshold wshich means
										 // to make an image easiar to analyze, convert color to binary image(black and white) 

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); //Create a dilate where we can change the dilations by changing size
	dilate(imgCanny, imgDil, kernel);    // dilate function -> for finding better display of edges

	//here for erosion we can write or use kernel variable again and also can change the effect
	// As I already written it before so I will just move to the function 
	erode(imgDil, imgErode, kernel);    // for dicreasing the effects of dilation (oppozite reaction(haha))

	imshow("Alone", img);						// for displaying the image

	imshow("Alone gray", imgGray);              // for displaying the gray image 
	imshow("Alone Blur", imgBlur);             // for displaying the blur image
	imshow("Alone Canny", imgCanny);           // for displaying the edges
	imshow("Alone Dilation", imgDil);          // for displaying the dilation
	imshow("Alone Erode", imgErode);             // for displaying the Erode




	waitKey(0);          //Adding a delay ( 0 -> infinity delay )






}
