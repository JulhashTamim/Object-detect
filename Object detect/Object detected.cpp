////     ||| Open Source Computer Vision Library |||     \\\\  


//Header files of opencv

#include <opencv2/imgcodecs.hpp>     
#include <opencv2/highgui.hpp>        
#include <opencv2/imgproc.hpp>        
#include <iostream>                  

using namespace cv;
using namespace std;





Mat imgGray, imgBlur, imgCanny, imgDil;

string objectType;


void getContours(Mat imgDil, Mat img)
{


	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;



	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);




	vector <vector<Point>> conPoly(contours.size());

	vector<Rect> boundRect(contours.size());


	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;




		float peri = arcLength(contours[i], true);



		approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);



		cout << conPoly[i].size() << endl;


		boundRect[i] = boundingRect(conPoly[i]);

		rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 125, 255), 4);




		int objectdet = (int)conPoly[i].size();

		if (objectdet == 11) { objectType = "Strawberry"; }





		else if (objectdet == 6) { objectType = "Cube"; }

		else if (objectdet == 5) { objectType = "Bow"; }

		else if (objectdet == 10) { objectType = "Heart"; }

		else if (objectdet == 4) { objectType = "Ice-Cream"; }




		//drawContours(img, conPoly, i, Scalar(255, 0, 255), 5);  // if i wanna see the contours


		putText(img, objectType, { boundRect[i].x, boundRect[i].y - 6 }, FONT_HERSHEY_SIMPLEX, 0.70, Scalar(0, 20, 0), 2);



	}












}





void main()
{

	string path = "Resources/pic.jpg";
	Mat img = imread(path);

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 5, 0);
	Canny(imgBlur, imgCanny, 34, 76);


	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);


	getContours(imgDil, img);


	//Displaying

	imshow(" Objects ", img);





	waitKey(0);


}