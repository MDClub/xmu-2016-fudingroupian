#ifndef _VIDEOEFFECTS_H_
#define _VIDEOEFFECTS_H_

#include<iostream>
#include "opencv2/opencv.hpp"
#include<qimage.h>
#include<qdebug.h>

#include<vector>

using namespace cv;
using namespace std;


//素描
void sketch(Mat srcImg, Mat &resultImg);

//卡通
void cartoon(Mat srcImg, Mat &resultImg);

//怪物
//void monster(Mat srcImg, Mat &resultImg);
//void monster(Mat srcImg, Mat &resultImg);
void detectObjectsCustom(const Mat &img, CascadeClassifier &cascade, vector<Rect> &objects, int scaledWidth, int flags, Size minFeatureSize, float searchScaleFactor, int minNeighbors);//检测目标
void detectLargestObject(const Mat &img, CascadeClassifier &cascade, Rect &largestObject, int scaledWidth);//检测最大的一个人脸
void detectManyObjects(const Mat &img, CascadeClassifier &cascade, vector<Rect> &objects, int scaledWidth);

//人脸美容
void beautifyFace(Mat srcImg, Mat &resultImg);
void mapToMat(const Mat &srcAlpha, Mat &dest, int x, int y);

//戴帽子
void addHat(Mat srcImg, Mat &resultImg);

//假发
void addWig(Mat srcImg, Mat &resultImg);

//哈哈镜 凸透镜效果
void MaxFrame(Mat  srcImg, Mat &resultImg);

//哈哈镜 凹透镜效果
void MinFrame(Mat  srcImg, Mat &resultImg);

//给眼睛加桃心
void eyesZoom(Mat srcImg, Mat &resultImg);
void detectBothEyes(const Mat &face, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2, Rect &leftEyeRect, Rect &rightEyeRect);//检测双眼

QImage cvMat2QImage(const cv::Mat& mat); //Mat转换为QImage
cv::Mat QImage2cvMat(QImage image);  //QImage转换为Mat
#endif