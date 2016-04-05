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

void ProcessFace::startClicked() //������ͷ��ť��Ӧ
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

void ProcessFace::readFrame() //������ͷ��ȡͼƬ
{
	camera >> image_frame; //������ͷ��ȡһ֡

	if (effect_num == 1)    //effect_num=1��ʾ����Ч��
	{
		sketch(image_frame, image_result); //��������Ч��������
	}
	if (effect_num == 2)  //effect_num=2��ʾ��ͨЧ��
	{
		cartoon(image_frame, image_result);	
	}
	if (effect_num == 3)  //effect_num=3��ʾ��ñ��Ч��
	{
		addHat(image_frame, image_result);
	}
	if (effect_num == 4)  //effect_num=4��ʾ���ٷ�Ч��
	{
		addWig(image_frame, image_result);
	}
	if (effect_num == 5)  //effect_num=5��ʾ��������Ч��
	{
		beautifyFace(image_frame, image_result);
	}
	if (effect_num == 6)  //effect_num=6��ʾ͹͸��Ч��
	{
		MaxFrame(image_frame, image_result);
	}
	if (effect_num == 7)  //effect_num=7��ʾ��͸��Ч��
	{
		MinFrame(image_frame, image_result);
	}
	if (effect_num == 8)  //effect_num=8��ʾ˫��ð����Ч��
	{
		eyesZoom(image_frame, image_result);
	}
	cvtColor(image_frame, image_frame, CV_RGB2RGBA);   //ͼ����QT��ʾǰ������ת����QImage��ʽ����RGBA��ʽת����RGB 
	QImage img_original = QImage((const unsigned char*)(image_frame.data), image_frame.cols, image_frame.rows, QImage::Format_RGB32);
	ui.labelOriImage->setPixmap(QPixmap::fromImage(img_original));

	if (effect_num != 0) //effect_num��Ϊ0��ת������ʾ������ͼ��
	{
		QImage img_result = cvMat2QImage(image_result);  //��Matת��ΪQImage
		ui.labelResultImage->setPixmap(QPixmap::fromImage(img_result));
	}
}

void ProcessFace::sketchClicked() //����Ч����ť��Ӧ
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 1;
	m_timer->start(1);

}

void ProcessFace::cartoonClicked()  //��ͨЧ����Ӧ
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 2;
	m_timer->start(1);
}

void ProcessFace::addHatClicked() //��ñ�ӵ�Ч����Ӧ
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 3;
	m_timer->start(1);
}

void ProcessFace::addWigClicked() //���ٷ���Ч����Ӧ
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 4;
	m_timer->start(1);
}

void ProcessFace::beautifyFaceClicked() //�������ݵ�Ч����Ӧ
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 5;
	m_timer->start(1);
}

void ProcessFace::maxFrameClicked() //͹͸����Ч����Ӧ
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 6;
	m_timer->start(1);
}

void ProcessFace::minFrameClicked() //��͸����Ч����Ӧ
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 7;
	m_timer->start(1);
}

void ProcessFace::eyesZoomClicked() //˫��ð���ĵ�Ч����Ӧ
{
	if (m_timer->isActive())
		m_timer->stop();
	effect_num = 8;
	m_timer->start(1);
}

void ProcessFace::closeClicked() //�ر�����ͷ��ť��Ӧ
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
