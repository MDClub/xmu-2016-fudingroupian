#ifndef PROCESSFACE_H
#define PROCESSFACE_H

#include <QtWidgets/QMainWindow>
#include "ui_processface.h"
#include<iostream>
#include<qlabel.h>
#include<qimage.h>
#include<qtimer.h>
#include<opencv2\opencv.hpp>
#include<opencv2\highgui.hpp>
#include"VideoEffects.h"

using namespace std;
using namespace cv;

class ProcessFace : public QMainWindow
{
	Q_OBJECT

public:
	ProcessFace(QWidget *parent = 0);
	~ProcessFace();

private:
	Ui::ProcessFaceClass ui;
	Mat image_frame;    //每一帧原始图片
	Mat image_result;  //结果图片
	VideoCapture camera;  //获取摄像头图像
	QTimer *m_timer;   //计时操作
	int effect_num;//效果序号，0：原始效果，1：素描效果，2：卡通效果，3：戴帽子的效果，4：戴假发的效果，5：人脸美容效果，6：凸透镜效果，7：凹透镜效果，8：双眼冒桃心效果    
private slots:
	void startClicked(); //打开摄像头响应
	void readFrame();   //时间到读取一帧放入窗口
	void sketchClicked(); //素描效果按钮
	void cartoonClicked(); //卡通效果按钮
	void addHatClicked(); //戴帽子的效果
	void addWigClicked(); //戴假发的效果
	void beautifyFaceClicked(); //人脸美容效果
	void maxFrameClicked(); //凸透镜效果
	void minFrameClicked(); //凹透镜效果
	void eyesZoomClicked(); //双眼冒桃心效果
	void closeClicked();   //关闭摄像头响应
};


#endif // PROCESSFACE_H
