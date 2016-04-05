#ifndef _VIDEOEFFECTS_H_
#define _VIDEOEFFECTS_H_

#include<iostream>
#include "opencv2/opencv.hpp"
#include<qimage.h>
#include<qdebug.h>

#include<vector>

using namespace cv;
using namespace std;


//����
void sketch(Mat srcImg, Mat &resultImg);

//��ͨ
void cartoon(Mat srcImg, Mat &resultImg);

//����
//void monster(Mat srcImg, Mat &resultImg);
//void monster(Mat srcImg, Mat &resultImg);
void detectObjectsCustom(const Mat &img, CascadeClassifier &cascade, vector<Rect> &objects, int scaledWidth, int flags, Size minFeatureSize, float searchScaleFactor, int minNeighbors);//���Ŀ��
void detectLargestObject(const Mat &img, CascadeClassifier &cascade, Rect &largestObject, int scaledWidth);//�������һ������
void detectManyObjects(const Mat &img, CascadeClassifier &cascade, vector<Rect> &objects, int scaledWidth);

//��������
void beautifyFace(Mat srcImg, Mat &resultImg);
void mapToMat(const Mat &srcAlpha, Mat &dest, int x, int y);

//��ñ��
void addHat(Mat srcImg, Mat &resultImg);

//�ٷ�
void addWig(Mat srcImg, Mat &resultImg);

//������ ͹͸��Ч��
void MaxFrame(Mat  srcImg, Mat &resultImg);

//������ ��͸��Ч��
void MinFrame(Mat  srcImg, Mat &resultImg);

//���۾�������
void eyesZoom(Mat srcImg, Mat &resultImg);
void detectBothEyes(const Mat &face, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2, Rect &leftEyeRect, Rect &rightEyeRect);//���˫��

QImage cvMat2QImage(const cv::Mat& mat); //Matת��ΪQImage
cv::Mat QImage2cvMat(QImage image);  //QImageת��ΪMat
#endif