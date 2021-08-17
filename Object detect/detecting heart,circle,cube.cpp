////     ||| Open Source Computer Vision Library |||     \\\\  


//Header files of opencv

#include <opencv2/imgcodecs.hpp>      // To read and write images(imgcodecs)
#include <opencv2/highgui.hpp>        // To operate high level Graphics User Interface (GUI)(highgui)
#include <opencv2/imgproc.hpp>        // for processing an image (imgproc)
#include <iostream>                   // for c++ (input output stream)

using namespace cv;               // for using opencv library functions directly
using namespace std;              //  ..  ..    c++ standard    ..        ..        ..





Mat imgGray, imgBlur, imgCanny, imgDil;
string objectType;
// now we need use different function to contours the image

void getContours(Mat imgDil, Mat img)
{


	vector<vector<Point>> contours;  // contours will be a vector and inside that vector we are gonna use another vector and inside that vector the points will be stored
	vector<Vec4i> hierarchy;         // it is a vector but it has 4 intiger inside of it and opencv has a builtin function for that (Vec4i)

	//Now we need to find the contours by using findContours function , contours is the outputarray of arrays which contains the contours value
	//hierarchy is the mode where we aproximate our image by using RETR_EXTERNAL which just detect the outer contours
	// CHAIN_APPROX_SIMPLE is a point detector where its just detect the points like rect. has 4 points, tri. has 3 points

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	// Now we will be able to find the contours so we need to print them down .. at this point we need to draw contours by using the opencv function drawcContours

	//drawContours(img, contours, -1, Scalar(255, 0, 255), 5);
	vector <vector<Point>> conPoly(contours.size());          // here we declare the conPoly array and also its size to store the Polygoan values

	vector<Rect> boundRect(contours.size());           // here we declare the boundRect value as a vector for storing the values of rectangle

	// loop through all the contours to find the extra object and for filtering it
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		/*if (area > 7401)
		{
			drawContours(img, contours, i, Scalar(255, 0, 255), 5);     */    // filteration done*/

			// for getting the perimeter or the curves, corner of rect and other shapes or object

		float peri = arcLength(contours[i], true);


		// now we need to defaine the number of curves or corner points this Polygone has like 4->rect


		approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);



		cout << conPoly[i].size() << endl;

		//this function(boundingRect) is for coordinates of bounding rect 



		boundRect[i] = boundingRect(conPoly[i]);            // storing the values in boundrect vector

		rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 125, 255), 4);  // here we use rectsngle to draw one outside of objects tl is top left, br is bottom right corner

		// now its time to actually detect an object and display them on img 
		// so at first we need to use variable which will store the values of conPoly[i] in integer

		int objectdet = (int)conPoly[i].size();                           // converted in interger value

		if (objectdet == 4) {
			// for finding the square

			float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
			if (aspRatio > 0.95 && aspRatio < 1.05)
			{
				objectType = "Square";
			}
			else                       // rectangle
			{
				objectType = "Rectangle";
			}

		}

		else if (objectdet == 3) { objectType = "Triangle"; }

		else if (objectdet == 10) { objectType = "Heart"; }

		else if (objectdet == 8) { objectType = "Circle"; }



		drawContours(img, conPoly, i, Scalar(255, 0, 255), 5);


		putText(img, objectType, { boundRect[i].x, boundRect[i].y - 6 }, FONT_HERSHEY_SIMPLEX, 0.70, Scalar(0, 20, 0), 2);



	}













}



void main()
{

	string path = "Resources/picture.jpg";
	Mat img = imread(path);

	cvtColor(img, imgGray, COLOR_BGR2GRAY);   // changing the color
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 5, 0);     // Bluring the image
	Canny(imgBlur, imgCanny, 34, 76);                // finding the edges

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);                // for better look at the edges 


	getContours(imgDil, img);


	//Displaying

	imshow(" Shapes ", img);



	waitKey(0);


}