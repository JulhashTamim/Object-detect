////     ||| Open Source Computer Vision Library |||     \\\\  



//Header files of opencv

#include <opencv2/imgcodecs.hpp>      // To read and write images(imgcodecs)
#include <opencv2/highgui.hpp>        // To operate high level Graphics User Interface (GUI)(highgui)
#include <opencv2/imgproc.hpp>        // for processing an image (imgproc)
#include <iostream>                   // for c++ (input output stream)

using namespace cv;               // for using opencv library functions directly
using namespace std;              //  ..  ..    c++ standard    ..        ..        ..


										//    Warp Image   \\
								  
									 //    Resize and Crop  \\
									 // Drawing shapes and writting Text on Image \\


float w = 250, h = 350;               // taking the width and height of a playing card





void main()
{

	string path = "Resources/card.jpg";
	Mat image = imread(path);










	Point2f source[4] = { {526,146},{772,192},{405,396},{676,458} };         // the selected objects all 4 point pixels

	Point2f destination[4] = { { 0.0f, 0.0f}, { w, 0.0f},{ 0.0f, h},{ w, h} };    // here we select the points where we want to put the object starting from 0.0

	Mat matrix, imgWarp;

	matrix = getPerspectiveTransform(source, destination);    // For Transform we need to use matrix

	warpPerspective(image, imgWarp, matrix, Point(w, h));       // for warping the image


	for (int i = 0; i < 4; i++)
	{
		circle(image, source[i], 15, Scalar(255, 240, 200), FILLED);
	}

	imshow("KING OF Spade", imgWarp);




	Point2f source2[4] = { {63,325},{339,277},{97,637},{401,573} };         // the selected objects all 4 point pixels

	Point2f destination2[4] = { { 0.0f, 0.0f}, { w, 0.0f},{ 0.0f, h},{ w, h} };    // here we select the points where we want to put the object starting from 0.0

	Mat matrix1, imgWarp1;

	matrix1 = getPerspectiveTransform(source2, destination2);    // For Transform we need to use matrix

	warpPerspective(image, imgWarp1, matrix1, Point(w, h));

	for (int i = 0; i < 4; i++)              // for showning the sources (4 points)
	{
		circle(image, source2[i], 15, Scalar(255, 0, 255), FILLED);   // with a circle
	}

	imshow("QUEEN OF Heart", imgWarp1);


	Point2f source3[4] = { {773,109},{1019,83},{843,357},{1117,331} };
	Point2f destination3[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	Mat matrix2, imgWarp2;

	matrix2 = getPerspectiveTransform(source3, destination3);

	warpPerspective(image, imgWarp2, matrix2, Point(w, h));


	for (int i = 0; i < 4; i++)              // for showning the sources (4 points)
	{
		circle(image, source3[i], 15, Scalar(0, 0, 0), FILLED);   // with a circle
	}

	imshow("JACK OF Clubs", imgWarp2);


	Point2f source4[4] = { {743,385},{1021,435},{647,709},{949,783} };
	Point2f destination4[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	Mat matrix3, imgWarp3;

	matrix3 = getPerspectiveTransform(source4, destination4);

	warpPerspective(image, imgWarp3, matrix3, Point(w, h));


	for (int i = 0; i < 4; i++)              // for showning the sources (4 points)
	{
		circle(image, source4[i], 15, Scalar(255, 255, 0), FILLED);   // with a circle
	}

	imshow("9 DIAMONDS", imgWarp3);



	imshow("Card", image);



	waitKey(0);          //Adding a delay ( 0 -> infinity delay )






}