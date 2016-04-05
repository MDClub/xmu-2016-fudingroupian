#include "processface.h"

ProcessFace::ProcessFace(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_timer = new QTimer(this);
	effect_num = 0;
	ui.labelResultImage->setText(" ");
	connect(m_timer, SIGNAL(timeout()), this, SLOT(readFrame()));
	//connect(m_timer_sumiao, SIGNAL(timeout()), this, SLOT(readFrameSumiao()));
}

void ProcessFace::startClicked() //打开摄像头按钮响应
{
	camera.open(0);
	if (!camera.isOpened())
	{
		cerr << "Could not access the camera or vedio" << endl;
		exit(1);
	}
	if (m_timer->isActive())
	{
		m_timer->stop();
		ui.labelResultImage->setText(" ");
	}
	effect_num= 0;
	m_timer->start(1);
}

void ProcessFace::readFrame() //从摄像头读取图片
{
	camera >> image_frame; //从摄像头读取一帧

	if (effect_num == 1)    //effect_num=1显示素描效果
	{
		sketch(image_frame, image_result); //调用素描效果处理函数
	}
	if (effect_num == 2)  //effect_num=2显示卡通效果
	{
		cartoon(image_frame, image_result);	
	}
	if (effect_num == 3)  //effect_num=3显示戴帽子效果
	{
		addHat(image_frame, image_result);
	}
	if (effect_num == 4)  //effect_num=4显示戴假发效果
	{
		addWig(image_frame, image_result);
	}
	if (effect_num == 5)  //effect_num=5显示人脸美容效果
	{
		beautifyFace(image_frame, image_result);
	}
	if (effect_num == 6)  //effect_num=6显示凸透镜效果
	{
		MaxFrame(image_frame, image_result);
	}
	if (effect_num == 7)  //effect_num=7显示凹透镜效果
	{
		MinFrame(image_frame, image_result);
	}
	if (effect_num == 8)  //effect_num=8显示双眼冒桃心效果
	{
		eyesZoom(image_frame, image_result);
	}
	cvtColor(image_frame, image_frame, CV_RGB2RGBA);   //图像在QT显示前，必须转化成QImage格式，将RGBA格式转化成RGB 
	QImage img_original = QImage((const unsigned char*)(image_frame.data), image_frame.cols, image_frame.rows, QImage::Format_RGB32);
	ui.labelOriImage->setPixmap(QPixmap::fromImage(img_original));

	if (effect_num != 0) //effect_num不为0，转换并显示处理结果图像
	{
		QImage img_result = cvMat2QImage(image_result);  //将Mat转换为QImage
		ui.labelResultImage->setPixmap(QPixmap::fromImage(img_result));
	}
}

void ProcessFace::sketchClicked() //素描效果按钮响应
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 1;
	m_timer->start(1);

}

void ProcessFace::cartoonClicked()  //卡通效果响应
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 2;
	m_timer->start(1);
}

void ProcessFace::addHatClicked() //戴帽子的效果响应
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 3;
	m_timer->start(1);
}

void ProcessFace::addWigClicked() //戴假发的效果响应
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 4;
	m_timer->start(1);
}

void ProcessFace::beautifyFaceClicked() //人脸美容的效果响应
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 5;
	m_timer->start(1);
}

void ProcessFace::maxFrameClicked() //凸透镜的效果响应
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 6;
	m_timer->start(1);
}

void ProcessFace::minFrameClicked() //凹透镜的效果响应
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 7;
	m_timer->start(1);
}

void ProcessFace::eyesZoomClicked() //双眼冒桃心的效果响应
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 8;
	m_timer->start(1);
}

void ProcessFace::closeClicked() //关闭摄像头按钮响应
{
	if (camera.isOpened())
	{
		camera.release();
		if (m_timer->isActive())
			m_timer->stop();
		ui.labelResultImage->setText(" ");
		ui.labelOriImage->setText(" ");

	}
}

ProcessFace::~ProcessFace()
{
	
}
