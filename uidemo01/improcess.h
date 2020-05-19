#ifndef IMPROCESS_H
#define IMPROCESS_H

#include<opencv2/opencv.hpp>

void imgConvert(const cv::Mat& img, float* dst);

void imgResize(float* src, float* dst,int srcWidth,int srcHeight,int dstWidth,int dstHeight);

void resizeInner(float *src, float* dst,int srcWidth,int srcHeight,int dstWidth,int dstHeight);

#endif // IMPROCESS_H
