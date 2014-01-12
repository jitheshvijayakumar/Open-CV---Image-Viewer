/*
 * imageview.cpp
 *
 *      Author: Jithesh Vijayakumar
 */

#include <iostream>
#include <vector>
#include <cv.h>
#include <highgui.h>
#include "Image.h"

using namespace std;
using namespace cv;

const string WINDOW = "OpenCV Image Viewer - (c) Jithesh Vijayakumar";	
const int FIRST_IMAGE_NUM = 0;
const int LAST_IMAGE_NUM = 7;

int current_image_num = 0;

const int ESCAPE_KEY = 27;
const int SPACEBAR_KEY = 32;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

vector<Image> images;

void on_click(int event, int x, int y, int flags, void* param) 
{

	if (event == CV_EVENT_LBUTTONDOWN)
		images[(--current_image_num)++].zoom_in();
	else if (event == CV_EVENT_RBUTTONDOWN)
		images[(--current_image_num)++].zoom_out();
}

string intToStr(int num) 
{
    ostringstream out;
    out << num;
    return out.str();
}

int main() 
{
	for (int i = FIRST_IMAGE_NUM; i <= LAST_IMAGE_NUM; i++) {
		string path = "/home/jithesh/myworks/opencvviewer/pics/test/" + intToStr(i) + ".jpg";
		images.push_back(Image(WINDOW, path));
		if (images[i].empty()) {
			cout << "ERROR: No Image Files Found" << endl;
			return -1;
		}
	}

	namedWindow(WINDOW, CV_WINDOW_NORMAL);
	resizeWindow(WINDOW, WINDOW_WIDTH, WINDOW_HEIGHT);
	imshow(WINDOW, images[current_image_num++].get_base_image());

	setMouseCallback(WINDOW, on_click);

	while (true) {
		int key = waitKey(10);
		if (key == ESCAPE_KEY) {
			return 0;
		} else if (key == SPACEBAR_KEY) {
			if (current_image_num == LAST_IMAGE_NUM + 1)
				current_image_num = FIRST_IMAGE_NUM;
			imshow(WINDOW, images[current_image_num].get_base_image());
			current_image_num++;
		}
	}
}




