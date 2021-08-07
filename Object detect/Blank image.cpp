////     ||| Open Source Computer Vision Library |||     \\\\  



//Header files of opencv

#include <opencv2/imgcodecs.hpp>      // To read and write images(imgcodecs)
#include <opencv2/highgui.hpp>        // To operate high level Graphics User Interface (GUI)(highgui)
#include <opencv2/imgproc.hpp>        // for processing an image (imgproc)
#include <iostream>                   // for c++ (input output stream)

using namespace cv;               // for using opencv library functions directly
using namespace std;            //  ..  ..    c++ standard    ..        ..       



								  // Drawing shapes and writting Text on Image \\




// Blank image
void main()
{

	Mat image(400, 400, CV_8UC3, Scalar(200, 200, 200));  // Here we create an blank image where (width,height,
														  // Here CV_8UC3 we declare the type of our image which is in 8 bite unsigned(U) and its channel are 3 BGR colors
														   // Here scalar is for giving our image some kind of color (blue,green,red)(MAX 255)

	circle(image, Point(200, 200), 170, Scalar(125, 0, 125), FILLED);   // Here we need to draw a circle in this image Filled means inside part of this circle filled

	Rect img(50, 150, 302, 100);
	rectangle(image, img, Scalar(137, 255, 255), FILLED);            // Here we use to draw a rectangle

	line(image, Point(50, 270), Point(350, 270), Scalar(125, 255, 255), 3);       // Here we draw a line

	putText(image, "Why so serious?!!", Point(80, 210), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(0, 0, 0), 1);




	imshow("Blank image", image);




	waitKey(0);          //Adding a delay ( 0 -> infinity delay )



}