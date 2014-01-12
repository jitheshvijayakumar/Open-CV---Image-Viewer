/*
 * Image.h
 *      Author: Jithesh Vijayakumar
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <cv.h>

using namespace std;
using namespace cv;

class Image {
private:
	Mat base_image;
    string window;
	vector<Mat> zoomed_images;
	
	int zoom_level;
	int max_zoom_level;
	
public:
	Image(string window, string path);
	Mat get_base_image();


	void zoom_in();
	void zoom_out();

	bool empty();
};

#endif
