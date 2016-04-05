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
	Mat image_frame;    //ÿһ֡ԭʼͼƬ
	Mat image_result;  //���ͼƬ
	VideoCapture camera;  //��ȡ����ͷͼ��
	QTimer *m_timer;   //��ʱ����
	int effect_num;//Ч����ţ�0��ԭʼЧ����1������Ч����2����ͨЧ����3����ñ�ӵ�Ч����4�����ٷ���Ч����5����������Ч����6��͹͸��Ч����7����͸��Ч����8��˫��ð����Ч��    
private slots:
	void startClicked(); //������ͷ��Ӧ
	void readFrame();   //ʱ�䵽��ȡһ֡���봰��
	void sketchClicked(); //����Ч����ť
	void cartoonClicked(); //��ͨЧ����ť
	void addHatClicked(); //��ñ�ӵ�Ч��
	void addWigClicked(); //���ٷ���Ч��
	void beautifyFaceClicked(); //��������Ч��
	void maxFrameClicked(); //͹͸��Ч��
	void minFrameClicked(); //��͸��Ч��
	void eyesZoomClicked(); //˫��ð����Ч��
	void closeClicked();   //�ر�����ͷ��Ӧ
};


#endif // PROCESSFACE_H
