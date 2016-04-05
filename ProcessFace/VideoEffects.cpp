#include "VideoEffects.h"


#include "VideoEffects.h"


//素描
void sketch(Mat srcImg, Mat &resultImg)
{
	//转成灰度图
	Mat gray;
	cvtColor(srcImg, gray, CV_BGR2GRAY);

	//中值滤波:去除噪声，让边缘锐化
	const int MEDIAN_BLUR_FILTER_SIZE = 7;
	medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE);

	//拉普拉斯边缘滤波
	Mat edges;
	const int LAPLACIAN_FILTER_SIZE = 5;
	Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE);

	//二值化
	Mat mask;
	const int EDGES_THRESHOLD = 80;
	threshold(edges, mask, EDGES_THRESHOLD, 255, THRESH_BINARY_INV);
	mask.convertTo(resultImg, CV_8UC3);
	//mask.copyTo(resultImg);
	//imshow("Cartoonifier", resultImg);
	//waitKey(3);
}

//卡通
void cartoon(Mat srcImg, Mat &resultImg)
{
	Size sizeSrc = srcImg.size();

	//降低分辨率，提高运行效率
	Size smallSize;
	smallSize.width = sizeSrc.width / 6;
	smallSize.height = sizeSrc.height / 6;
	Mat smallImg = Mat(smallSize, CV_8UC3);
	resize(srcImg, smallImg, smallSize, 0, 0, INTER_LINEAR);


	//双边滤波
	Mat temp = Mat(smallSize, CV_8UC3);
	int repetitions = 3; //执行双边滤波次数
	for (int i = 0; i < repetitions; ++i)
	{
		int ksize = 15;  //滤波核大小 9
		double sigmaColor = 50;  //9
		double sigmaSpace = 50;  //7
		bilateralFilter(smallImg, temp, ksize, sigmaColor, sigmaSpace);
		bilateralFilter(temp, smallImg, ksize, sigmaColor, sigmaSpace);
	}


	//还原图像分辨率
	Mat bigImg;
	resize(smallImg, bigImg, sizeSrc, 0, 0, INTER_LINEAR);
	resultImg.setTo(0);

	//保持边缘
	Mat gray;
	cvtColor(srcImg, gray, CV_BGR2GRAY);
	const int MEDIAN_BLUR_FILTER_SIZE = 7;
	medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE);
	Mat edges;
	const int LAPLACIAN_FILTER_SIZE = 5;
	Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE);
	Mat mask;
	const int EDGES_THRESHOLD = 80;
	threshold(edges, mask, EDGES_THRESHOLD, 255, THRESH_BINARY_INV);
	bigImg.copyTo(resultImg, mask);
	/*Mat mask2 = -1*mask+255;
	srcImg.copyTo(resultImg, mask2);*/
	//bigImg.copyTo(resultImg);
}

//怪物
//void monster(Mat srcImg, Mat &resultImg)
//{
//	Size sizeSrc = srcImg.size();
//
//	//降低分辨率，提高运行效率
//	Size smallSize;
//	smallSize.width = sizeSrc.width / 6;
//	smallSize.height = sizeSrc.height / 6;
//	Mat smallImg = Mat(smallSize, CV_8UC3);
//	resize(srcImg, smallImg, smallSize, 0, 0, INTER_LINEAR);
//
//	Mat temp = Mat(smallSize, CV_8UC3);
//	int repetitions = 7; //执行双边滤波次数
//	for (int i = 0; i < repetitions; ++i)
//	{
//		int ksize = 15; //滤波核大小
//		double sigmaColor = 50;
//		double sigmaSpace = 50;
//		bilateralFilter(smallImg, temp, ksize, sigmaColor, sigmaSpace);
//		bilateralFilter(temp, smallImg, ksize, sigmaColor, sigmaSpace);
//	}
//
//	Mat bigImg;
//	resize(smallImg, bigImg, sizeSrc, 0, 0, INTER_LINEAR);
//	resultImg.setTo(0);
//
//	//灰度化
//	Mat gray;
//	cvtColor(srcImg, gray, CV_BGR2GRAY);
//
//	//中值滤波去噪
//	const int MEDIAN_BLUR_FILTER_SIZE = 7;
//	medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE);
//
//	Mat edgesX, edgesY;
//	Scharr(gray, edgesX, CV_8U, 1, 0);
//	Scharr(gray, edgesY, CV_8U, 0, 1);
//	edgesX = edgesX + edgesY;
//	const int EVIL_EDGE_THRESHOLD = 10;
//	Mat mask;
//	threshold(edgesX, mask, EVIL_EDGE_THRESHOLD, 255, THRESH_BINARY_INV);
//	medianBlur(mask, mask, 3);
//
//	bigImg.copyTo(resultImg, mask);
//}


//--------------------------------------------------------------------------


//检测目标
void detectObjectsCustom(const Mat &img, CascadeClassifier &cascade, vector<Rect> &objects, int scaledWidth, int flags, Size minFeatureSize, float searchScaleFactor, int minNeighbors)
{
	// 转成灰度图
	Mat gray;
	if (img.channels() == 3) {
		cvtColor(img, gray, CV_BGR2GRAY);
	}
	else if (img.channels() == 4) {
		cvtColor(img, gray, CV_BGRA2GRAY);
	}
	else {

		gray = img;
	}


	Mat inputImg;
	float scale = img.cols / (float)scaledWidth;  //缩小比例
	if (img.cols > scaledWidth) {
		// 缩小图像，但是保持宽高比例不变。
		int scaledHeight = cvRound(img.rows / scale);
		resize(gray, inputImg, Size(scaledWidth, scaledHeight));
	}
	else {

		inputImg = gray;
	}

	// 直方图均衡化处理.
	Mat equalizedImg;
	equalizeHist(inputImg, equalizedImg);

	//检测目标.
	cascade.detectMultiScale(equalizedImg, objects, searchScaleFactor, minNeighbors, flags, minFeatureSize);

	// 还原图片尺寸.
	if (img.cols > scaledWidth) {
		for (int i = 0; i < (int)objects.size(); i++) {
			objects[i].x = cvRound(objects[i].x * scale);
			objects[i].y = cvRound(objects[i].y * scale);
			objects[i].width = cvRound(objects[i].width * scale);
			objects[i].height = cvRound(objects[i].height * scale);
		}
	}

	// 确保目标在图片里面，出边界的地方截断。
	for (int i = 0; i < (int)objects.size(); i++) {
		if (objects[i].x < 0)
			objects[i].x = 0;
		if (objects[i].y < 0)
			objects[i].y = 0;
		if (objects[i].x + objects[i].width > img.cols)
			objects[i].x = img.cols - objects[i].width;
		if (objects[i].y + objects[i].height > img.rows)
			objects[i].y = img.rows - objects[i].height;
	}


}


//检测最大的一个人脸
void detectLargestObject(const Mat &img, CascadeClassifier &cascade, Rect &largestObject, int scaledWidth)
{
	//只检测最大的一个目标
	int flags = CASCADE_FIND_BIGGEST_OBJECT;// | CASCADE_DO_ROUGH_SEARCH;
	// Smallest object size.
	Size minFeatureSize = Size(20, 20);
	// 
	float searchScaleFactor = 1.1f;

	// 越大检测出的目标越准确，但是漏检的可能性也大。
	int minNeighbors = 3;

	// 检测目标
	vector<Rect> objects;
	detectObjectsCustom(img, cascade, objects, scaledWidth, flags, minFeatureSize, searchScaleFactor, minNeighbors);
	if (objects.size() > 0) {

		largestObject = (Rect)objects.at(0);
	}
	else {

		largestObject = Rect(-1, -1, -1, -1);
	}
}

void detectManyObjects(const Mat &img, CascadeClassifier &cascade, vector<Rect> &objects, int scaledWidth)
{
	// 检测全部目标
	int flags = CASCADE_SCALE_IMAGE;

	// 最小目标尺寸
	Size minFeatureSize = Size(20, 20);

	float searchScaleFactor = 1.1f;

	//精度
	int minNeighbors = 4;

	// 检测目标
	detectObjectsCustom(img, cascade, objects, scaledWidth, flags, minFeatureSize, searchScaleFactor, minNeighbors);
}



//人脸美容
void beautifyFace(Mat srcImg, Mat &resultImg)
{
	CascadeClassifier faceDetector;
	//faceDetector.load("lbpcascade_frontalface.xml");
	//faceDetector.load("haarcascade_frontalface_alt_tree.xml");
	//faceDetector.load("haarcascade_frontalface_alt2.xml");
	faceDetector.load("haarcascade_frontalface_alt.xml");
	Rect faceRect;
	int scaleWidth = 320;
	detectLargestObject(srcImg, faceDetector, faceRect, scaleWidth);
	srcImg.copyTo(resultImg);

	//static int num = 0; //测试是否找到人脸
	//num++;//just for test

	if (faceRect.width >0)
	{

		//cout << "find "<<num<<" face" << endl; //just for test

		Mat facetemp;
		srcImg(faceRect).copyTo(facetemp);
		Mat temp;
		int repetitions = 1; //执行双边滤波次数
		for (int i = 0; i < repetitions; ++i)
		{
			int ksize = 15; //滤波核大小 9
			double sigmaColor = 40;
			double sigmaSpace = 40;
			bilateralFilter(facetemp, temp, ksize, sigmaColor, sigmaSpace);
			bilateralFilter(temp, facetemp, ksize, sigmaColor, sigmaSpace);
		}

		Mat edgeTemp;
		srcImg(faceRect).copyTo(edgeTemp);

		////保持边缘
		Mat gray;
		cvtColor(edgeTemp, gray, CV_BGR2GRAY);

		const int MEDIAN_BLUR_FILTER_SIZE = 7;
		medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE);

		Mat edges;
		const int LAPLACIAN_FILTER_SIZE = 5;
		Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE);

		Mat mask;
		const int EDGES_THRESHOLD = 80;
		threshold(edges, mask, EDGES_THRESHOLD, 255, THRESH_BINARY_INV);

		//对mask取反
		Mat mask2 = -1 * mask + 255;

		edgeTemp.copyTo(facetemp, mask2);
		facetemp.copyTo(resultImg(faceRect));
	}//end if
}

//检测双眼
void detectBothEyes(const Mat &face, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2, Rect &leftEyeRect, Rect &rightEyeRect)
{
	// 不检测脸部的边缘部分，因为那里一般是头发或者耳朵。并且这样做可以提高速度。
	/*
	// 2splits.xml  的参数
	const float EYE_SX = 0.12f;
	const float EYE_SY = 0.17f;
	const float EYE_SW = 0.37f;
	const float EYE_SH = 0.36f;
	*/
	/*
	// mcs.xml 的参数
	const float EYE_SX = 0.10f;
	const float EYE_SY = 0.19f;
	const float EYE_SW = 0.40f;
	const float EYE_SH = 0.36f;
	*/

	//  eye.xml 或者 eyeglasses.xml 的参数 
	const float EYE_SX = 0.16f;  //x轴坐标比例
	const float EYE_SY = 0.26f;  //y轴坐标比例
	const float EYE_SW = 0.30f;  //宽度比例
	const float EYE_SH = 0.28f;  //高度比例

	int leftX = cvRound(face.cols * EYE_SX);
	int topY = cvRound(face.rows * EYE_SY);
	int widthX = cvRound(face.cols * EYE_SW);
	int heightY = cvRound(face.rows * EYE_SH);
	int rightX = cvRound(face.cols * (1.0 - EYE_SX - EYE_SW));  // 右眼开始检测的部位

	Mat topLeftOfFace = face(Rect(leftX, topY, widthX, heightY)); //左眼检测区域
	Mat topRightOfFace = face(Rect(rightX, topY, widthX, heightY)); //右眼检测区域
	//Rect leftEyeRect, rightEyeRect;


	//分别检测左右眼
	detectLargestObject(topLeftOfFace, eyeCascade1, leftEyeRect, topLeftOfFace.cols);
	detectLargestObject(topRightOfFace, eyeCascade1, rightEyeRect, topRightOfFace.cols);
	//cout << "detect eyes" << endl;
	//If the eye was not detected, try a different cascade classifier.
	/*if (leftEyeRect.width <= 0 && !eyeCascade2.empty()) {
	cout << "begin detect  glass eyes" << endl;
	detectLargestObject(topLeftOfFace, eyeCascade2, leftEyeRect, topLeftOfFace.cols);
	cout << "end detect  glass eyes" << endl;
	}

	if (rightEyeRect.width <= 0 && !eyeCascade2.empty()) {
	detectLargestObject(topRightOfFace, eyeCascade2, rightEyeRect, topRightOfFace.cols);
	}*/

	//调整左右眼睛的坐标
	if (leftEyeRect.width > 0) {
		leftEyeRect.x += leftX;
		leftEyeRect.y += topY;
		//leftEye = Point(leftEyeRect.x + leftEyeRect.width / 2, leftEyeRect.y + leftEyeRect.height / 2);
	}


	if (rightEyeRect.width > 0) {
		rightEyeRect.x += rightX;
		rightEyeRect.y += topY;
		//rightEye = Point(rightEyeRect.x + rightEyeRect.width / 2, rightEyeRect.y + rightEyeRect.height / 2);
	}

}

//给眼睛加桃心
void eyesZoom(Mat srcImg, Mat &resultImg)
{
	srcImg.copyTo(resultImg);

	//检测最大的一个人脸
	CascadeClassifier faceDetector;
	faceDetector.load("haarcascade_frontalface_alt.xml");
	Rect faceRect;
	int scaleWidth = 320;
	detectLargestObject(srcImg, faceDetector, faceRect, scaleWidth);

	//cout << faceRect.width << endl; //just for test

	if (faceRect.width > 0)
	{
		//检测双眼
		CascadeClassifier eyeCascade1;
		eyeCascade1.load("haarcascade_eye.xml");

		CascadeClassifier eyeCascade2;
		eyeCascade2.load("haarcascade_eye_tree_eyeglasses.xml");

		Mat faceImg = resultImg(faceRect);
		Mat gray;
		cvtColor(faceImg, gray, CV_BGR2GRAY);

		//cout << "done gray" << endl; //just for test

		Rect leftEyeRect, rightEyeRect;
		detectBothEyes(gray, eyeCascade1, eyeCascade2, leftEyeRect, rightEyeRect);

		//cout << leftEyeRect.width << endl;//just for test
		if (leftEyeRect.width > 0)
		{
			//读入桃心图片
			Mat love = imread("love.png", -1);
			Mat loveResized;

			//调整桃心大小以适应眼睛
			resize(love, loveResized, Size(leftEyeRect.width*1.5, leftEyeRect.height*1.5), 0, 0, INTER_LANCZOS4);

			//将桃心加到对应位置上
			mapToMat(loveResized, resultImg, faceRect.x + leftEyeRect.x - 0.2*leftEyeRect.width, faceRect.y + leftEyeRect.y - 0.2*leftEyeRect.height);
		}
		if (rightEyeRect.width > 0)
		{
			//读入桃心图片
			Mat love = imread("love.png", -1);
			Mat loveResized;

			//调整桃心大小以适应眼睛
			resize(love, loveResized, Size(rightEyeRect.width*1.5, rightEyeRect.height*1.5), 0, 0, INTER_LANCZOS4);

			//将桃心加到对应位置上
			mapToMat(loveResized, resultImg, faceRect.x + rightEyeRect.x - 0.2*rightEyeRect.width, faceRect.y + rightEyeRect.y - 0.2*rightEyeRect.height);
		}

	}
}

//区域替换
void mapToMat(const Mat &srcAlpha, Mat &dest, int x, int y)
{
	int nc = 3;
	int alpha = 0;

	for (int j = 0; j < srcAlpha.rows; j++)
	{
		for (int i = 0; i < srcAlpha.cols * 3; i += 3)
		{
			alpha = srcAlpha.ptr<uchar>(j)[i / 3 * 4 + 3];
			//alpha = 255-alpha;
			if (alpha != 0) //4通道图像的alpha判断
			{
				for (int k = 0; k < 3; k++)
				{
					// if (src1.ptr<uchar>(j)[i / nc*nc + k] != 0)
					if ((j + y < dest.rows) && (j + y >= 0) &&
						((i + x * 3) / 3 * 3 + k < dest.cols * 3) && ((i + x * 3) / 3 * 3 + k >= 0) &&
						(i / nc * 4 + k < srcAlpha.cols * 4) && (i / nc * 4 + k >= 0))
					{
						dest.ptr<uchar>(j + y)[(i + x*nc) / nc*nc + k] = srcAlpha.ptr<uchar>(j)[(i) / nc * 4 + k];
					}
				}
			}
		}
	}
}



//戴帽子
void addHat(Mat srcImg, Mat &resultImg)
{
	//检测最大的人脸
	CascadeClassifier faceDetector;
	faceDetector.load("haarcascade_frontalface_alt.xml");
	Rect faceRect;
	int scaleWidth = 320;
	detectLargestObject(srcImg, faceDetector, faceRect, scaleWidth);


	srcImg.copyTo(resultImg);
	if (faceRect.width > 0)
	{
		Mat hat = imread("hat2.png", -1); //读入帽子图片
		Mat hatResized;

		//调整帽子的尺寸以适应人脸
		resize(hat, hatResized, Size(faceRect.width*1.5, faceRect.height), 0, 0, INTER_LANCZOS4);

		/*Rect hatRect=faceRect;
		hatRect.y = faceRect.y - 0.8*faceRect.height;
		hatResized.copyTo(resultImg(hatRect));*/

		//将帽子加到人脸图像上。
		mapToMat(hatResized, resultImg, faceRect.x - 0.3*faceRect.width, faceRect.y - 0.8*faceRect.height);
	}
}


//假发
void addWig(Mat srcImg, Mat &resultImg)
{

	//检测最大的一个人脸
	CascadeClassifier faceDetector;
	faceDetector.load("haarcascade_frontalface_alt.xml");
	Rect faceRect;
	int scaleWidth = 320;
	detectLargestObject(srcImg, faceDetector, faceRect, scaleWidth);

	srcImg.copyTo(resultImg);

	if (faceRect.width > 0)
	{
		//读入假发图片
		Mat wig = imread("wig.png", -1);
		Mat wigResized;

		//调整假发的尺寸以适应人脸
		resize(wig, wigResized, Size(faceRect.width*2.5, faceRect.height*2.5), 0, 0, INTER_LANCZOS4);
		/*Rect hatRect=faceRect;
		hatRect.y = faceRect.y - 0.8*faceRect.height;
		hatResized.copyTo(resultImg(hatRect));*/

		//将假发加到图片相应位置
		mapToMat(wigResized, resultImg, faceRect.x - 0.8*faceRect.width, faceRect.y - 0.5*faceRect.height);
	}
}

//哈哈镜 凸透镜效果
void MaxFrame(Mat  srcImg, Mat &resultImg)
{
	srcImg.copyTo(resultImg);
	IplImage *frame;
	frame = &IplImage(resultImg);
	uchar* old_data = (uchar*)frame->imageData;
	uchar* new_data = new uchar[frame->widthStep * frame->height];

	//中心点
	int center_X = frame->width / 2;
	int center_Y = frame->height / 2;

	//半径
	int radius = 400;//400 for all
	/*if (frame->width > frame->height)
	radius = frame->width;
	else
	radius = frame->height;*/
	int newX = 0;
	int newY = 0;

	int real_radius = (int)(radius / 2.0);
	for (int i = 0; i < frame->width; i++)
	{
		for (int j = 0; j < frame->height; j++)
		{
			int tX = i - center_X;
			int tY = j - center_Y;

			int distance = (int)(tX * tX + tY * tY);
			if (distance < radius * radius)
			{
				newX = (int)((float)(tX) / 2.0);
				newY = (int)((float)(tY) / 2.0);

				newX = (int)(newX * (sqrt((double)distance) / real_radius));
				newX = (int)(newX * (sqrt((double)distance) / real_radius));

				newX = newX + center_X;
				newY = newY + center_Y;

				new_data[frame->widthStep * j + i * 3] = old_data[frame->widthStep * newY + newX * 3];
				new_data[frame->widthStep * j + i * 3 + 1] = old_data[frame->widthStep * newY + newX * 3 + 1];
				new_data[frame->widthStep * j + i * 3 + 2] = old_data[frame->widthStep * newY + newX * 3 + 2];
			}
			else
			{
				new_data[frame->widthStep * j + i * 3] = old_data[frame->widthStep * j + i * 3];
				new_data[frame->widthStep * j + i * 3 + 1] = old_data[frame->widthStep * j + i * 3 + 1];
				new_data[frame->widthStep * j + i * 3 + 2] = old_data[frame->widthStep * j + i * 3 + 2];
			}
		}
	}
	memcpy(old_data, new_data, sizeof(uchar) * frame->widthStep * frame->height);
	delete new_data;
}


//哈哈镜 凹透镜效果
void MinFrame(Mat  srcImg, Mat &resultImg)
{
	srcImg.copyTo(resultImg);
	IplImage *frame;
	frame = &IplImage(resultImg);
	uchar* old_data = (uchar*)frame->imageData;
	uchar* new_data = new uchar[frame->widthStep * frame->height];

	//中心点
	int center_X = frame->width / 2;
	int center_Y = frame->height / 2;

	int radius = 100;//半径
	double theta = 0;
	int newX = 0;
	int newY = 0;

	for (int i = 0; i < frame->width; i++)
	{
		for (int j = 0; j < frame->height; j++)
		{
			int tX = i - center_X;
			int tY = j - center_Y;

			theta = atan2((double)tY, (double)tX);
			radius = (int)sqrt((double)(tX * tX) + (double)(tY * tY));
			int newR = (int)(sqrt((double)radius) * 12);
			newX = center_X + (int)(newR * cos(theta));
			newY = center_Y + (int)(newR * sin(theta));

			if (!(newX > 0 && newX < frame->width))
			{
				newX = 0;
			}
			if (!(newY > 0 && newY < frame->height))
			{
				newY = 0;
			}

			new_data[frame->widthStep * j + i * 3] = old_data[frame->widthStep * newY + newX * 3];
			new_data[frame->widthStep * j + i * 3 + 1] = old_data[frame->widthStep * newY + newX * 3 + 1];
			new_data[frame->widthStep * j + i * 3 + 2] = old_data[frame->widthStep * newY + newX * 3 + 2];
		}
	}
	memcpy(old_data, new_data, sizeof(uchar) * frame->widthStep * frame->height);
	delete new_data;
}



//--------------------------------Mat格式与QImage格式的互相转换-----------------------------------------------
//mat转换为QImage
QImage cvMat2QImage(const cv::Mat& mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1  
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)  
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat  
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3  
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		qDebug() << "CV_8UC4";
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}
//QImage转换为Mat
cv::Mat QImage2cvMat(QImage image)
{
	cv::Mat mat;
	qDebug() << image.format();
	switch (image.format())
	{
	case QImage::Format_ARGB32:
	case QImage::Format_RGB32:
	case QImage::Format_ARGB32_Premultiplied:
		mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
		break;
	case QImage::Format_RGB888:
		mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
		cv::cvtColor(mat, mat, CV_BGR2RGB);
		break;
	case QImage::Format_Indexed8:
		mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
		break;
	}
	return mat;
}