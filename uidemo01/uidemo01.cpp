#pragma execution_character_set("utf-8")

#include "uidemo01.h"
#include "ui_uidemo01.h"
#include "iconhelper.h"
#include"pages.cpp"
#include <qstackedwidget.h>

#include<iostream>

#include<vector>
#include<QVector>
#include <iostream>
#include <string>
#include <map>

//Qt
#include <QMessageBox>
//#include <QVTKOPenGLWidget.h>
#include <qfileinfo.h>
#include <qtimer.h>
#include <qevent.h>
#include <QFileDialog>
#include <QSettings>
#include <set>
#include <QFile>

//C++
#define _USE_MATH_DEFINES
#include <math.h>

#define VTP_FILETYPE 1
#define MHAORMHD_FILETYPE 2
#define MHD_FILETYPE 2
using namespace std;



double m_RedColor[3] = { 1.0, 0.0, 0.0 };
double m_GreenColor[3] = { 0.0, 1.0, 0.0 };
double m_BlueColor[3] = { 0.0, 0.0, 1.0 };
int m_Extent[6] = { 0, 0, 0, 0, 0, 0 };//图像的范围
double m_Spacing[3] = { 0, 0, 0 };//像素间距
double m_Origen[3] = { 0, 0, 0 };//原点
double m_Center[3] = { 0, 0, 0 };//图像的中心位置
int VolumeExtent[6] = { 0, 0, 0, 0, 0, 0 };


UIDemo01::UIDemo01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIDemo01),
    m_Renderer(vtkSmartPointer<vtkRenderer>::New()) ,
    m_pMetaImageReader(nullptr),
    m_VolumeInteractor(vtkSmartPointer<vtkRenderWindowInteractor>::New()),
    m_PlaneCallback(nullptr),
    m_pPlaneX(vtkSmartPointer<vtkImagePlaneWidget>::New()),
    m_pPlaneY(vtkSmartPointer<vtkImagePlaneWidget>::New()),
    m_pPlaneZ(vtkSmartPointer<vtkImagePlaneWidget>::New()),
    m_pTimer(new QTimer),
    m_pImageReslice(vtkSmartPointer<vtkImageReslice>::New()),
    m_pRenderer_1(vtkSmartPointer<vtkRenderer>::New()),
    m_vQvtkWidget({ nullptr, nullptr, nullptr }),
    m_bThreePlaneOn(true),
    m_vPlaneWidget({ m_pPlaneZ, m_pPlaneX, m_pPlaneY }){
    ui->setupUi(this);
    this->initForm();
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(OpenImg()));
    connect(ui->openButton, &QPushButton::clicked, this, &UIDemo01::OnOpenButton2Clicked);
    connect(ui->ThreePlaneButton, &QPushButton::clicked, this, &UIDemo01::OnThreePlaneButtonClicked);
    m_Renderer->SetBackground(0.147, 0.229, 0.371);
    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(m_Renderer);
    //ui->qvtkWidget_4->GetRenderWindow()->RemoveRenderer(m_Renderer);

    ui->qvtkWidget_1->GetRenderWindow()->Render();
    ui->qvtkWidget_2->GetRenderWindow()->Render();
    ui->qvtkWidget_3->GetRenderWindow()->Render();
    ui->qvtkWidget_4->GetRenderWindow()->Render();

}

UIDemo01::~UIDemo01()
{
    delete ui;
}

bool UIDemo01::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        if (watched == ui->widgetTitle) {
            on_btnMenu_Max_clicked();
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);
}

void UIDemo01::initForm()
{
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    IconHelper::Instance()->setIcon(ui->labIco, QChar(0xf099), 30);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));

    //ui->widgetMenu->setVisible(false);
    ui->widgetTitle->installEventFilter(this);
    ui->widgetTitle->setProperty("form", "title");
    ui->widgetTop->setProperty("nav", "top");
    ui->labTitle->setText("基于神经计算棒的辅助诊断系统");
    ui->labTitle->setFont(QFont("Microsoft Yahei", 20));
    this->setWindowTitle(ui->labTitle->text());

    stackedWidget.setStyleSheet("QLabel{font:60pt;}");
    //stackedWidget.addWidget(page1);
    //stackedWidget.addWidget(page2);
    //stackedWidget.addWidget(page3);
    //stackedWidget.addWidget(page4);

    //单独设置指示器大小
    int addWidth = 20;
    int addHeight = 10;
    int rbtnWidth = 15;
    int ckWidth = 13;
    int scrWidth = 12;
    int borderWidth = 3;

    QStringList qss;
    qss.append(QString("QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{width:%1px;}").arg(addWidth));
    qss.append(QString("QComboBox::down-arrow,QDateEdit[calendarPopup=\"true\"]::down-arrow,QTimeEdit[calendarPopup=\"true\"]::down-arrow,"
                       "QDateTimeEdit[calendarPopup=\"true\"]::down-arrow{width:%1px;height:%1px;right:2px;}").arg(addHeight));
    qss.append(QString("QRadioButton::indicator{width:%1px;height:%1px;}").arg(rbtnWidth));
    qss.append(QString("QCheckBox::indicator,QGroupBox::indicator,QTreeWidget::indicator,QListWidget::indicator{width:%1px;height:%1px;}").arg(ckWidth));
    qss.append(QString("QScrollBar:horizontal{min-height:%1px;border-radius:%2px;}QScrollBar::handle:horizontal{border-radius:%2px;}"
                       "QScrollBar:vertical{min-width:%1px;border-radius:%2px;}QScrollBar::handle:vertical{border-radius:%2px;}").arg(scrWidth).arg(scrWidth / 2));
    qss.append(QString("QWidget#widget_top>QToolButton:pressed,QWidget#widget_top>QToolButton:hover,"
                       "QWidget#widget_top>QToolButton:checked,QWidget#widget_top>QLabel:hover{"
                       "border-width:0px 0px %1px 0px;}").arg(borderWidth));
    qss.append(QString("QWidget#widgetleft>QPushButton:checked,QWidget#widgetleft>QToolButton:checked,"
                       "QWidget#widgetleft>QPushButton:pressed,QWidget#widgetleft>QToolButton:pressed{"
                       "border-width:0px 0px 0px %1px;}").arg(borderWidth));
    this->setStyleSheet(qss.join(""));


    QSize icoSize(32, 32);
    int icoWidth = 85;

    //设置顶部导航按钮
    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }

    ui->btnMain->click();
}

void UIDemo01::buttonClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        if (btn == b) {
            btn->setChecked(true);
        } else {
            btn->setChecked(false);
        }
    }

    if (name == "主界面") {
       ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "图像前处理") {
       ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "yolo模型") {
       ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "3D重建") {
       ui->stackedWidget->setCurrentIndex(3);
    } else if (name == "用户退出") {
        exit(0);
    }
}

void UIDemo01::OpenImg()
{

    QString OpenFile, OpenFilePath;
    QImage image2;

    QImage* img=new QImage;

    OpenFile = QFileDialog::getOpenFileName(this,
        "please choose an image file",
        "",
        "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
    if (OpenFile != "")
    {
        if (image.load(OpenFile))
        {
            //仅仅只是导入之后的图片仍然是原来的大小，这个时候我们需要缩放
            ui->imagelabel->setPixmap(QPixmap::fromImage(image).scaled(ui->imagelabel->size()));
            img->load(OpenFile);
            ui->label2->setPixmap(QPixmap::fromImage(*Erosiontionrgb(img)).scaled(ui->label2->size()));
            ui->label_3->setPixmap(QPixmap::fromImage(*Dilationrgb(img)).scaled(ui->label_3->size()));
            ui->label_5->setPixmap(QPixmap::fromImage(*Opening(img)).scaled(ui->label_5->size()));
            ui->label_10->setPixmap(QPixmap::fromImage(*SideInner(img)).scaled(ui->label_10->size()));
            ui->label_12->setPixmap(QPixmap::fromImage(*SideOutter(img)).scaled(ui->label_12->size()));
            ui->label_8->setPixmap(QPixmap::fromImage(*Closing(img)).scaled(ui->label_8->size()));
            ui->label_16->setPixmap(QPixmap::fromImage(image).scaled(ui->label_16->size()));

            //run_yolo();
            image2.load("C:/Users/leling/Desktop/biyesheji/uidemo01/test.jpg");//自己添加训练后的图片path
            //ui->label_2->setPixmap(QPixmap::fromImage(image2).scaled(ui->label_2->size()));
            ui->textEdit->setText("hello\nworld");
        }

    }
    //显示所有的图片路径
    QFileInfo OpenFileInfo;
    OpenFileInfo = QFileInfo(OpenFile);
    OpenFilePath = OpenFileInfo.filePath();
    ui->path->setText(OpenFilePath);

}

void UIDemo01::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void UIDemo01::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
    }

    this->setProperty("canMove", max);
    max = !max;
}

void UIDemo01::on_btnMenu_Close_clicked()
{
    close();
}
//腐蚀模板是 膨胀模板是
QImage* UIDemo01::Erosiontiongary(QImage* image, int k)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[7][7] = {
        { 0,0,0,1,0,0,0 },
        { 0,1,1,1,1,1,0 },
        { 0,1,1,1,1,1,0 },
        { 1,1,1,1,1,1,1 },
        { 0,1,1,1,1,1,0 },
        { 0,1,1,1,1,1,0 },
        { 0,0,0,1,0,0,0 } };
    int sizeKernel = 7;
    QColor color;
    QColor Rcolor;
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int r = 0;
            int g = 0;
            int b = 0;
            int hr = 1;
            int hg = 1;
            int hb = 1;
            Rcolor = QColor(image->pixel(x, y));
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() < k && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j] && hr == 1)
                    {
                        hr = 0;
                    }
                    while (color.green() < k && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j] && hg == 1)
                    {
                        hg = 0;
                    }
                    while (color.blue() < k && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j] && hb == 1)
                    {
                        hb = 0;
                    }
                }
            }
            if (hr == 0)
            {
                r = 0;
            }
            else
            {
                r = color.red();
            }
            if (hg == 0)
            {
                g = 0;
            }
            else
            {
                g = color.green();
            }
            if (hb == 0)
            {
                b = 0;
            }
            else
            {
                b = color.blue();
            }

            newImage->setPixel(x, y, qRgb(r, g, b));
        }
    }
    return newImage;
}
QImage* UIDemo01::Erosiontionrgb(QImage* image)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[7][7] = {
        { 0,0,0,1,0,0,0 },
        { 0,1,1,1,1,1,0 },
        { 0,1,1,1,1,1,0 },
        { 1,1,1,1,1,1,1 },
        { 0,1,1,1,1,1,0 },
        { 0,1,1,1,1,1,0 },
        { 0,0,0,1,0,0,0 } };
    int sizeKernel = 7;
    QColor color;
    QColor Rcolor;

    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            Rcolor = QColor(image->pixel(x, y));
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() < kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() < kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() < kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    return newImage;
}
QImage* UIDemo01::Dilationgary(QImage* image, int k)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[7][7] = {
        { 0,0,0,1,0,0,0 },
        { 0,1,1,1,1,1,0 },
        { 0,1,1,1,1,1,0 },
        { 1,1,1,1,1,1,1 },
        { 0,1,1,1,1,1,0 },
        { 0,1,1,1,1,1,0 },
        { 0,0,0,1,0,0,0 } };
    int sizeKernel = 7;
    QColor color;
    QColor Rcolor;
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int r = 0;
            int g = 0;
            int b = 0;
            int hr = 1;
            int hg = 1;
            int hb = 1;
            Rcolor = QColor(image->pixel(x, y));
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() >= k && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j] && hr == 1)
                    {
                        hr = 0;
                    }
                    while (color.green() >= k && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j] && hg == 1)
                    {
                        hg = 0;
                    }
                    while (color.blue() >= k && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j] && hb == 1)
                    {
                        hb = 0;
                    }
                }
            }
            if (hr == 0)
            {
                r = color.red();
            }
            else
            {
                r = 0;
            }
            if (hg == 0)
            {
                g = color.green();
            }
            else
            {
                g = 0;
            }
            if (hb == 0)
            {
                b = color.blue();
            }
            else
            {
                b = 0;
            }

            newImage->setPixel(x, y, qRgb(r, r, r));
        }
    }
    return newImage;
}
QImage* UIDemo01::Dilationrgb(QImage* image)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[7][7] = {
        { 0,0,0,1,0,0,0 },
        { 0,1,1,1,1,1,0 },
        { 0,1,1,1,1,1,0 },
        { 1,1,1,1,1,1,1 },
        { 0,1,1,1,1,1,0 },
        { 0,1,1,1,1,1,0 },
        { 0,0,0,1,0,0,0 } };
    int sizeKernel = 7;
    QColor color;
    QColor Rcolor;

    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            Rcolor = QColor(image->pixel(x, y));
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() < kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() < kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() < kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    return newImage;
}
//内边界
QImage* UIDemo01::SideInner(QImage* image)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[3][3] = {
        { 1,1,1 },
        { 1,1,1 },
        { 1,1,1 }
    };
    int sizeKernel = 3;
    QColor color;
    QColor newcolor;
    int r = 0;
    int g = 0;
    int b = 0;
    /*腐蚀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() < kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() < kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() < kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    /*end*/
    for (int y = 0; y<image->height(); y++)
    {
        for (int x = 0; x<image->width(); x++)
        {
            color = QColor(image->pixel(x, y));
            newcolor = QColor(newImage->pixel(x, y));
            if (color.red() != newcolor.red())
            {
                r = 255;
            }
            else
            {
                r = 0;
            }
            if (color.green() != newcolor.green())
            {
                g = 255;
            }
            else
            {
                g = 0;
            }
            if (color.blue() != newcolor.blue())
            {
                b = 255;
            }
            else
            {
                b = 0;
            }
            newImage->setPixel(x, y, qRgb(r, g, b));
        }
    }
    return newImage;
}

/*提取二值图的外边界*/
QImage* UIDemo01::SideOutter(QImage* image)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[3][3] = {
        { 1,1,1 },
        { 1,1,1 },
        { 1,1,1 }
    };
    int sizeKernel = 3;
    QColor color;
    QColor newcolor;
    int r = 0;
    int g = 0;
    int b = 0;
    /*膨胀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 0;
            int kg = 0;
            int kb = 0;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() > kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() > kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() > kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    /*end*/
    for (int y = 0; y<image->height(); y++)
    {
        for (int x = 0; x<image->width(); x++)
        {
            color = QColor(image->pixel(x, y));
            newcolor = QColor(newImage->pixel(x, y));
            if (color.red() != newcolor.red())
            {
                r = 255;
            }
            else
            {
                r = 0;
            }
            if (color.green() != newcolor.green())
            {
                g = 255;
            }
            else
            {
                g = 0;
            }
            if (color.blue() != newcolor.blue())
            {
                b = 255;
            }
            else
            {
                b = 0;
            }
            newImage->setPixel(x, y, qRgb(r, g, b));
        }
    }
    return newImage;
}

/*提取双线空心文字*/
QImage* UIDemo01::SideIO(QImage* image)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    QImage* newImage1 = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    QImage* newImage2 = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[3][3] = {
        { 1,1,1 },
        { 1,1,1 },
        { 1,1,1 }
    };
    int sizeKernel = 3;
    QColor color;
    QColor newcolor;
    int r = 0;
    int g = 0;
    int b = 0;
    /*第一次腐蚀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() < kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() < kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() < kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    /*end*/
    /*第二次腐蚀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(newImage->pixel(x + i, y + j));
                    while (color.red() < kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() < kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() < kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage1->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    /*end end*/
    /*二次腐蚀相减*/
    for (int y = 0; y<image->height(); y++)
    {
        for (int x = 0; x<image->width(); x++)
        {
            color = QColor(newImage->pixel(x, y));
            newcolor = QColor(newImage1->pixel(x, y));
            if (color.red() != newcolor.red())
            {
                r = 255;
            }
            else
            {
                r = 0;
            }
            if (color.green() != newcolor.green())
            {
                g = 255;
            }
            else
            {
                g = 0;
            }
            if (color.blue() != newcolor.blue())
            {
                b = 255;
            }
            else
            {
                b = 0;
            }
            newImage->setPixel(x, y, qRgb(r, g, b));
        }
    }

    /*第一次膨胀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 0;
            int kg = 0;
            int kb = 0;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() > kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() > kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() > kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage1->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    /*end*/
    /*第二次膨胀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 0;
            int kg = 0;
            int kb = 0;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(newImage1->pixel(x + i, y + j));
                    while (color.red() > kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() > kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() > kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage2->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    /*end*/
    /*二次膨胀相减*/
    for (int y = 0; y<image->height(); y++)
    {
        for (int x = 0; x<image->width(); x++)
        {
            color = QColor(newImage1->pixel(x, y));
            newcolor = QColor(newImage2->pixel(x, y));
            if (color.red() != newcolor.red())
            {
                r = 255;
            }
            else
            {
                r = 0;
            }
            if (color.green() != newcolor.green())
            {
                g = 255;
            }
            else
            {
                g = 0;
            }
            if (color.blue() != newcolor.blue())
            {
                b = 255;
            }
            else
            {
                b = 0;
            }
            newImage1->setPixel(x, y, qRgb(r, g, b));
        }
    }

    /*复合提取内外边界*/
    for (int y = 0; y<image->height(); y++)
    {
        for (int x = 0; x<image->width(); x++)
        {
            color = QColor(newImage1->pixel(x, y));
            newcolor = QColor(newImage->pixel(x, y));
            if (color.red() > newcolor.red())
            {
                r = color.red();
            }
            else
            {
                r = newcolor.red();
            }
            if (color.green() > newcolor.green())
            {
                g = color.green();
            }
            else
            {
                g = newcolor.green();
            }
            if (color.blue() > newcolor.blue())
            {
                b = color.blue();
            }
            else
            {
                b = newcolor.blue();
            }
            newImage->setPixel(x, y, qRgb(r, g, b));
        }
    }
    delete newImage1;
    delete newImage2;
    return newImage;
}
/*二值化的开运算*/

QImage* UIDemo01::Opening(QImage* image)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    QImage* newImage1 = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[7][7] = {
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 } };
    int sizeKernel = 7;
    QColor color;
    /*腐蚀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() < kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() < kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() < kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }

    /*膨胀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 0;
            int kg = 0;
            int kb = 0;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(newImage->pixel(x + i, y + j));
                    while (color.red() > kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() > kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() > kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage1->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
    delete newImage;
    return newImage1;
}

/*二值化的闭运算*/

QImage* UIDemo01::Closing(QImage* image)
{
    QImage* newImage = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    QImage* newImage1 = new QImage(image->width(), image->height(), QImage::Format_ARGB32);
    int kernel[7][7] = {
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 } };
    int sizeKernel = 7;
    QColor color;

    /*膨胀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 0;
            int kg = 0;
            int kb = 0;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(image->pixel(x + i, y + j));
                    while (color.red() > kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() > kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() > kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }

    /*腐蚀操作*/
    for (int y = sizeKernel / 2; y < image->height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < image->width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(newImage->pixel(x + i, y + j));
                    while (color.red() < kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() < kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() < kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            newImage1->setPixel(x, y, qRgb(kr, kg, kb));
        }
    }


    delete newImage;
    return newImage1;
}
void UIDemo01::OnOpenButton2Clicked()
{
QString QFileName =QFileDialog::getOpenFileName(this, tr(" 文件对话框 "), "", tr(" vtk文件(*vtp *mha *mhd) "));
//这是一个方便的静态函数，它将返回用户选择的一个或多个现有文件。
QFileInfo fileInfo(QFileName);//为我们提供了系统无关的文件信息
m_FileName = QFileName.toStdString();
set<string> m_fileNameSet;
if (fileInfo.exists() == true)
{
    if (m_fileNameSet.find(m_FileName) == m_fileNameSet.end())
    {

        if (fileInfo.suffix() == "vtp")
        {
            m_fileNameSet.insert(m_FileName);
            ReadVtkFile(VTP_FILETYPE);
        }
        else if (fileInfo.suffix() == "mha" ||
            fileInfo.suffix() == "mhd")
        {
            ReadVtkFile(MHAORMHD_FILETYPE);
        }
    }
    else if (m_fileNameSet.find(m_FileName) != m_fileNameSet.end())
    {
        QMessageBox::information(this, tr(" 提示对话框 "), tr(" 您已加载该文件 "));
    }
}
}
//--------------------------------------------------------------------------------------------------------------
void UIDemo01::ReadVtkFile(char difsuff)//different suffix
{
//XMLPolyData
vtkSmartPointer<vtkXMLPolyDataReader> reader =
vtkSmartPointer<vtkXMLPolyDataReader>::New();
vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();//读取VTK XML PolyData文件格式

vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();

if (difsuff == VTP_FILETYPE)
{
    reader->SetFileName(m_FileName.c_str());
    reader->Update();
    m_vVtpPolyData.push_back(reader->GetOutput());

    static int numVtp = 0;
    switch (numVtp % 3)
    {
    case 0:
        actor->GetProperty()->SetColor(m_RedColor);
        break;
    case 1:
        actor->GetProperty()->SetColor(m_GreenColor);
        break;
    case 2:
        actor->GetProperty()->SetColor(m_BlueColor);
        break;
    default:
        break;
    }
    ++numVtp;
    mapper->SetInputConnection(reader->GetOutputPort());
    mapper->Update();
    actor->SetMapper(mapper);
    m_vVTPActor.push_back(actor);

    m_Renderer->AddActor(actor);
    m_Renderer->ResetCamera();

}

else if (difsuff == MHAORMHD_FILETYPE)
{
    if (m_pMetaImageReader == nullptr)
    {
        m_pMetaImageReader = vtkSmartPointer<vtkMetaImageReader>::New();
    }
    m_pMetaImageReader->SetFileName(m_FileName.c_str());
    m_pMetaImageReader->Update();
    m_pMetaImageReader->GetOutput()->GetExtent(VolumeExtent);

    vtkSmartPointer<vtkGPUVolumeRayCastMapper> volumeMapper =
        vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
    volumeMapper->SetInputConnection(m_pMetaImageReader->GetOutputPort());

    vtkSmartPointer<vtkVolumeProperty> volumeProperty =
        vtkSmartPointer<vtkVolumeProperty>::New();
    volumeProperty->SetInterpolationTypeToLinear();
    volumeProperty->ShadeOn(); //打开或者关闭阴影测试
    volumeProperty->SetAmbient(0.4);
    volumeProperty->SetDiffuse(0.6);
    volumeProperty->SetSpecular(0.2);

    vtkSmartPointer<vtkPiecewiseFunction> volumeScalarOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
    volumeScalarOpacity->AddPoint(147.216912, 0.000000);
    volumeScalarOpacity->AddPoint(274.458333, 0.228650);
    volumeScalarOpacity->AddPoint(430.330882, 0.675532);
    volumeProperty->SetScalarOpacity(volumeScalarOpacity); //设置不透明度传输函数

    vtkSmartPointer<vtkPiecewiseFunction> volumeGradientOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
    volumeGradientOpacity->AddPoint(560.695000, 1.000000);
    volumeProperty->SetGradientOpacity(volumeGradientOpacity);//设置梯度不透明度效果对比

    vtkSmartPointer<vtkColorTransferFunction> volumeColor = vtkSmartPointer<vtkColorTransferFunction>::New();
    volumeColor->AddRGBPoint(129.607774, 0.478431, 0.000000, 0.000000);
    volumeColor->AddRGBPoint(213.812721, 0.933333, 0.000000, 0.000000);
    volumeColor->AddRGBPoint(348.540636, 1.000000, 0.800000, 0.062745);
    volumeColor->AddRGBPoint(500.419118, 1.000000, 0.898039, 0.776471);
    volumeColor->AddRGBPoint(579.268382, 1.000000, 1.000000, 1.000000);
    volumeProperty->SetColor(volumeColor);

    vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();
    volume->SetMapper(volumeMapper);
    volume->SetProperty(volumeProperty);

    m_Renderer->AddVolume(volume);
    m_Renderer->ResetCamera();

    m_vReslice.clear();
    m_vImageInteractor.clear();

    DisplaySlice(m_vPlaneWidget);
    m_Renderer->ResetCamera();
}

vtkSmartPointer<vtkInteractorStyleTrackballCamera> interactorStyle =
    vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();

m_VolumeInteractor->SetInteractorStyle(interactorStyle);
m_VolumeInteractor->SetRenderWindow(ui->qvtkWidget_4->GetRenderWindow());
ui->qvtkWidget_4->GetRenderWindow()->Render();

//   if (m_bThreePlaneOn == true)
//   {
//	m_bThreePlaneOn = false;
//	OnThreePlaneButtonClicked();
//   }
//else if(m_bThreePlaneOn == false)
//{
//	m_bThreePlaneOn = true;
//	OnThreePlaneButtonClicked();
//}
}
void UIDemo01::DisplaySlice(const std::vector<vtkSmartPointer<vtkImagePlaneWidget> >& vPlaneWidget)
{
int imageDims[3];
m_pMetaImageReader->GetOutput()->GetDimensions(imageDims);//获得图片尺寸

for (int i = 0; i < vPlaneWidget.size(); ++i)
{
    vPlaneWidget[i]->SetInputConnection(m_pMetaImageReader->GetOutputPort());
    vPlaneWidget[i]->SetInteractor(m_VolumeInteractor);
    vPlaneWidget[i]->RestrictPlaneToVolumeOn();
    vPlaneWidget[i]->SetResliceInterpolateToLinear();
    vPlaneWidget[i]->SetLeftButtonAction(vtkImagePlaneWidget::VTK_SLICE_MOTION_ACTION);//改变交互方式，原先是按下中键移动plane,
    vPlaneWidget[i]->SetMiddleButtonAction(vtkImagePlaneWidget::VTK_CURSOR_ACTION);//现在是按下左键移动
    vPlaneWidget[i]->UpdatePlacement();

    vtkSmartPointer<vtkTransform> transform =
        vtkSmartPointer<vtkTransform>::New();
    transform->Identity();//把vtkTransform重置成标准状态。

    vtkSmartPointer<vtkImageReslice> reslice =
        vtkSmartPointer<vtkImageReslice>::New();
    reslice->SetInputConnection(m_pMetaImageReader->GetOutputPort());
    reslice->SetOutputDimensionality(2);
    reslice->SetInterpolationModeToLinear();

    if (i == 0)
    {
        vPlaneWidget[i]->SetPlaneOrientationToZAxes();//①该两行顺序不能改变，否则sliceindex将会被重置,设置平面垂直于Z轴
        vPlaneWidget[i]->SetSliceIndex(imageDims[2] / 2);//②根据数据范围设置切片位置，在图像的中间

        transform->Translate(vPlaneWidget[i]->GetCenter());//在旋转之前创建一个平移矩阵
        transform->RotateX(180);
    }
    else if (i == 1)
    {
        vPlaneWidget[i]->SetPlaneOrientationToXAxes();
        vPlaneWidget[i]->SetSliceIndex(imageDims[0] / 2);

        transform->Translate(vPlaneWidget[i]->GetCenter());
        transform->RotateY(90);
        transform->RotateZ(90);
        /*reslice->SetResliceAxesDirectionCosines(0, 1, 0,//元素横着排列
        0, 0, 1,
        1, 0, 0);*/
    }
    else if (i == 2)
    {
        vPlaneWidget[i]->SetPlaneOrientationToYAxes();
        vPlaneWidget[i]->SetSliceIndex(imageDims[1] / 2);

        transform->Translate(vPlaneWidget[i]->GetCenter());
        transform->RotateX(90);
    }
    reslice->SetResliceAxes(transform->GetMatrix());
    reslice->Update();

    auto origin = reslice->GetOutput()->GetOrigin();
    std::cout << origin[0] << " " << origin[1] << " " << origin[2] << std::endl;

    vtkSmartPointer<vtkImageActor> imgActor =
        vtkSmartPointer<vtkImageActor>::New();
    imgActor->SetInputData(reslice->GetOutput());
    imgActor->SetOpacity(1);//设置对象的不透明度。

    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(imgActor);
    renderer->ResetCamera();

    vtkSmartPointer<vtkInteractorStyleImage> imagestyle =
        vtkSmartPointer<vtkInteractorStyleImage>::New();
    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetInteractorStyle(imagestyle);

    if (vPlaneWidget[i]->GetNormal()[2] == 1)//得到平面的法线
    {
        interactor->SetRenderWindow(ui->qvtkWidget_1->GetRenderWindow());
        ui->qvtkWidget_1->GetRenderWindow()->AddRenderer(renderer);
        ui->qvtkWidget_1->GetRenderWindow()->Render();
    }
    else if (vPlaneWidget[i]->GetNormal()[0] == 1)
    {
        interactor->SetRenderWindow(ui->qvtkWidget_2->GetRenderWindow());
        ui->qvtkWidget_2->GetRenderWindow()->AddRenderer(renderer);
        ui->qvtkWidget_2->GetRenderWindow()->Render();
    }
    else if (vPlaneWidget[i]->GetNormal()[1] == 1)
    {
        interactor->SetRenderWindow(ui->qvtkWidget_3->GetRenderWindow());
        ui->qvtkWidget_3->GetRenderWindow()->AddRenderer(renderer);
        ui->qvtkWidget_3->GetRenderWindow()->Render();
    }
    m_vImageRenderer.push_back(renderer);
    m_vReslice.push_back(reslice);
    m_vImageInteractor.push_back(interactor);
    m_vImageActor.push_back(imgActor);
}

for (int i = 0; i < m_vImageRenderer.size(); ++i)
{
    SetCamera(m_vImageActor[i], m_vImageRenderer[i]);
}
}

//--------------------------------------------------------------------------------------------------------------
void UIDemo01::OnThreePlaneButtonClicked()
{
if (m_bThreePlaneOn)
{
m_pPlaneX->On();
m_pPlaneY->On();
m_pPlaneZ->On();
m_bThreePlaneOn = false;
ui->ThreePlaneButton->setText("ThreePlaneOn");

}
else
{
    m_pPlaneX->Off();
    m_pPlaneY->Off();
    m_pPlaneZ->Off();
    m_bThreePlaneOn = true;
    ui->ThreePlaneButton->setText("ThreePlaneOff");
}


if (m_vVtpPolyData.size() != 0)
{
    DisplayContours(m_vPlaneWidget);
}

if (m_PlaneCallback == nullptr)
{
    m_PlaneCallback = vtkSmartPointer<vtkPlaneCallback>::New();
}
m_PlaneCallback->SetImageReslice(m_vReslice);
m_PlaneCallback->SetPlaneWidget(m_vPlaneWidget);
m_PlaneCallback->SetInteractor(m_vImageInteractor);
m_PlaneCallback->SetPlane(m_vPlane);
m_PlaneCallback->SetRenderer(m_vImageRenderer);
m_PlaneCallback->SetvtpPolydata(m_vVtpPolyData);
m_PlaneCallback->SetActor(m_vCutterActor);

if (!m_pPlaneZ->HasObserver(vtkCommand::InteractionEvent, m_PlaneCallback))
{
    m_pPlaneZ->AddObserver(vtkCommand::InteractionEvent, m_PlaneCallback);
}
if (!m_pPlaneX->HasObserver(vtkCommand::InteractionEvent, m_PlaneCallback))
{
    m_pPlaneX->AddObserver(vtkCommand::InteractionEvent, m_PlaneCallback);
}
if (!m_pPlaneY->HasObserver(vtkCommand::InteractionEvent, m_PlaneCallback))
{
    m_pPlaneY->AddObserver(vtkCommand::InteractionEvent, m_PlaneCallback);
}
}

//--------------------------------------------------------------------------------------------------
void UIDemo01::DisplayContours(const std::vector<vtkSmartPointer<vtkImagePlaneWidget> >& vPlaneWidget)
{
m_vPlane.clear();
m_vCutterActor.clear();

for (int i = 0; i < vPlaneWidget.size(); ++i)
{
    vtkSmartPointer <vtkPlane> plane = vtkSmartPointer <vtkPlane>::New();
    plane->SetOrigin(vPlaneWidget[i]->GetOrigin());
    plane->SetNormal(vPlaneWidget[i]->GetNormal());
    m_vPlane.push_back(plane);



    for (int j = 0; j < m_vVtpPolyData.size(); ++j)
    {
        vtkSmartPointer<vtkCutter> cutter = vtkSmartPointer<vtkCutter>::New();
        cutter->SetInputData(m_vVtpPolyData[j]);
        cutter->SetCutFunction(plane);
        cutter->Update();

        vtkSmartPointer<vtkPolyDataMapper> cutterMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        cutterMapper->SetInputConnection(cutter->GetOutputPort());
        //cutterMapper->ScalarVisibilityOff();
        cutterMapper->Update();

        // Create cut actor
        vtkSmartPointer<vtkActor> cutterActor = vtkSmartPointer<vtkActor>::New();
        cutterActor->SetMapper(cutterMapper);
        cutterActor->GetProperty()->SetLineWidth(1.5);
        cutterActor->GetProperty()->SetOpacity(1);
        cutterActor->GetProperty()->SetLighting(0);
        cutterActor->GetProperty()->SetDiffuse(0.8);
        cutterActor->GetProperty()->SetInterpolation(0);

        vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
        transform->Identity();

        if (vPlaneWidget[i]->GetNormal()[2] == 1)
        {
            //vPlaneWidget[i]->getpo

            transform->Translate(vPlaneWidget[i]->GetCenter());
            transform->RotateX(180);
            transform->Translate(0, 0, -0.1);
            transform->Inverse();

            cutterActor->GetProperty()->SetColor(m_vVTPActor[j]->GetProperty()->GetColor());
            cutterActor->SetUserMatrix(transform->GetMatrix());

            m_vImageRenderer[0]->AddActor(cutterActor);
            ui->qvtkWidget_1->GetRenderWindow()->Render();
        }
        else if (vPlaneWidget[i]->GetNormal()[0] == 1)
        {
            transform->Translate(vPlaneWidget[i]->GetCenter());
            transform->RotateY(90);
            transform->RotateZ(90);
            transform->Translate(0, 0, -0.1);
            transform->Inverse();

            cutterActor->GetProperty()->SetColor(m_vVTPActor[j]->GetProperty()->GetColor());
            cutterActor->SetUserMatrix(transform->GetMatrix());

            m_vImageRenderer[1]->AddActor(cutterActor);
            ui->qvtkWidget_2->GetRenderWindow()->Render();
        }
        else if (vPlaneWidget[i]->GetNormal()[1] == 1)
        {
            std::cout << "transform:" << transform->GetMatrix()->GetElement(1, 1) << " " << transform->GetMatrix()->GetElement(2, 3) << std::endl;
            transform->Translate(vPlaneWidget[i]->GetCenter());
            transform->RotateX(90);
            transform->Translate(0, 0, -0.1);
            transform->Inverse();

            cutterActor->GetProperty()->SetColor(m_vVTPActor[j]->GetProperty()->GetColor());
            cutterActor->SetUserMatrix(transform->GetMatrix());

            m_vImageRenderer[2]->AddActor(cutterActor);
            ui->qvtkWidget_3->GetRenderWindow()->Render();
        }
        m_vCutterActor.push_back(cutterActor);
        //m_Renderer->AddActor(cutterActor);
    }
}
}

void UIDemo01::SetCamera(vtkSmartPointer<vtkImageActor> actor, vtkSmartPointer<vtkRenderer> renderer)
{
//获取图像的实际大小
double *XRange = actor->GetXRange();
double *YRange = actor->GetYRange();
//获取窗口大小
int *rendererSize = renderer->GetSize();
//得到纵横比
double widgetAspectRatio = static_cast<double> (rendererSize[0]) / rendererSize[1];
double imageAspectRatio = static_cast<double> (XRange[1] - XRange[0]) / (YRange[1] - YRange[0]);
double angle = 0;

std::cout << "center: " << actor->GetCenter()[0] << "range: " << actor->GetXRange()[0] << " " << actor->GetXRange()[1] << std::endl;

if (widgetAspectRatio >= imageAspectRatio)
{
    angle = 2.0 * (atan((YRange[1] - YRange[0]) / 2.0 / 900000.0)) * 180 / M_PI;
    renderer->GetActiveCamera()->UseHorizontalViewAngleOff();
}
else if (widgetAspectRatio < imageAspectRatio)
{
    angle = 2.0 * (atan((XRange[1] - XRange[0]) / 2.0 / 900000.0)) * 180 / M_PI;
    renderer->GetActiveCamera()->UseHorizontalViewAngleOn();
    //renderer->GetActiveCamera()->SetPosition((XRange[0] + XRange[1]) / 2, (YRange[0] + YRange[1]) / 2, 900000);
    //renderer->GetActiveCamera()->SetFocalPoint((XRange[0] + XRange[1]) / 2, (YRange[0] + YRange[1]) / 2, 0);
    //renderer->GetActiveCamera()->SetViewAngle(angle);
    //renderer->ResetCameraClippingRange();
}
renderer->GetActiveCamera()->SetPosition(actor->GetCenter()[0], actor->GetCenter()[1], actor->GetCenter()[2] + 900000);
renderer->GetActiveCamera()->SetFocalPoint(actor->GetCenter());
renderer->GetActiveCamera()->SetViewAngle(angle);
renderer->ResetCameraClippingRange();
}

void UIDemo01::resizeEvent(QResizeEvent * event)
{
for (int i = 0; i < m_vImageRenderer.size(); ++i)
{
SetCamera(m_vImageActor[i], m_vImageRenderer[i]);
}
}
