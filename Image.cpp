/*
 * Image.cpp
 *
 *      Author: Jithesh Vijayakumar
 */

#include "Image.h"

#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

Image::Image(string window, string path) {
	base_image = imread(path, CV_LOAD_IMAGE_UNCHANGED);
	zoomed_images.push_back(base_image);

	this->window = window;

	zoom_level = 0;
	max_zoom_level = -1;
}

void Image::zoom_in() {
	int width = zoomed_images[zoom_level].size().width;
	int height = zoomed_images[zoom_level].size().height;
	if (width > 1 && height > 1) {
		if (zoom_level > max_zoom_level) {
			Mat zoomed_image(zoomed_images[zoom_level], Rect(width/4., height/4., width/2., height/2.));
			zoomed_images.push_back(zoomed_image);
			max_zoom_level++;
		}
		imshow(window, zoomed_images[++zoom_level]);
	}
}

void Image::zoom_out() {
	if (zoom_level > 0) 
		imshow(window, zoomed_images[--zoom_level]);
}

Mat Image::get_base_image() {
	return base_image;
}

bool Image::empty() {
	return base_image.empty();
}
