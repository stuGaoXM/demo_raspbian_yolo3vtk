/********************************************************************************
** Form generated from reading UI file 'uidemo01.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIDEMO01_H
#define UI_UIDEMO01_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qvtkwidget.h>

QT_BEGIN_NAMESPACE

class Ui_UIDemo01
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnMain;
    QToolButton *btnConfig;
    QToolButton *btnData;
    QToolButton *btnHelp;
    QToolButton *btnExit;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Max;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QLabel *imagelabel;
    QLineEdit *path;
    QPushButton *pushButton;
    QWidget *page2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QLabel *label;
    QLabel *label2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *page3;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_7;
    QLabel *label_2;
    QLabel *label_13;
    QTextEdit *textEdit;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *page4;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_10;
    QPushButton *openButton;
    QPushButton *ThreePlaneButton;
    QVTKWidget *qvtkWidget_4;
    QVTKWidget *qvtkWidget_3;
    QVTKWidget *qvtkWidget_2;
    QVTKWidget *qvtkWidget_1;

    void setupUi(QDialog *UIDemo01)
    {
        if (UIDemo01->objectName().isEmpty())
            UIDemo01->setObjectName(QString::fromUtf8("UIDemo01"));
        UIDemo01->resize(800, 600);
        UIDemo01->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(UIDemo01);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(UIDemo01);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QString::fromUtf8("labIco"));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        labTitle->setStyleSheet(QString::fromUtf8(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QString::fromUtf8("widgetTop"));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnMain = new QToolButton(widgetTop);
        btnMain->setObjectName(QString::fromUtf8("btnMain"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnMain->sizePolicy().hasHeightForWidth());
        btnMain->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/main_main.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMain->setIcon(icon);
        btnMain->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnMain);

        btnConfig = new QToolButton(widgetTop);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));
        sizePolicy1.setHeightForWidth(btnConfig->sizePolicy().hasHeightForWidth());
        btnConfig->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/main_config.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfig->setIcon(icon1);
        btnConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnConfig);

        btnData = new QToolButton(widgetTop);
        btnData->setObjectName(QString::fromUtf8("btnData"));
        sizePolicy1.setHeightForWidth(btnData->sizePolicy().hasHeightForWidth());
        btnData->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/main_data.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnData->setIcon(icon2);
        btnData->setChecked(false);
        btnData->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnData);

        btnHelp = new QToolButton(widgetTop);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        sizePolicy1.setHeightForWidth(btnHelp->sizePolicy().hasHeightForWidth());
        btnHelp->setSizePolicy(sizePolicy1);
        btnHelp->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/main_person.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon3);
        btnHelp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnHelp);

        btnExit = new QToolButton(widgetTop);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        sizePolicy1.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy1);
        btnExit->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/main_exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon4);
        btnExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnExit);


        horizontalLayout_2->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 3);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QString::fromUtf8("btnMenu_Min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 1, 1, 1);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QString::fromUtf8("btnMenu_Close"));
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 3, 1, 1);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QString::fromUtf8("btnMenu_Max"));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 2, 1, 1);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        stackedWidget = new QStackedWidget(UIDemo01);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        verticalLayout_2 = new QVBoxLayout(page1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(page1);
        widget->setObjectName(QString::fromUtf8("widget"));
        imagelabel = new QLabel(widget);
        imagelabel->setObjectName(QString::fromUtf8("imagelabel"));
        imagelabel->setGeometry(QRect(110, 60, 511, 371));
        path = new QLineEdit(widget);
        path->setObjectName(QString::fromUtf8("path"));
        path->setGeometry(QRect(110, 10, 481, 31));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 10, 61, 31));

        verticalLayout_2->addWidget(widget);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        verticalLayout_3 = new QVBoxLayout(page2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_2 = new QWidget(page2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 16));
        label2 = new QLabel(widget_2);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(10, 40, 201, 161));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 40, 201, 161));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 10, 121, 16));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 40, 201, 161));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(480, 10, 121, 16));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(480, 220, 121, 16));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(480, 250, 201, 161));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 220, 121, 16));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 250, 201, 161));
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(240, 220, 121, 16));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(240, 250, 201, 161));

        verticalLayout_3->addWidget(widget_2);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        verticalLayout_5 = new QVBoxLayout(page3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_7 = new QWidget(page3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        label_2 = new QLabel(widget_7);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 321, 251));
        label_13 = new QLabel(widget_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(40, 20, 141, 16));
        textEdit = new QTextEdit(widget_7);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 340, 551, 151));
        label_14 = new QLabel(widget_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(40, 320, 54, 12));
        label_15 = new QLabel(widget_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(400, 20, 141, 16));
        label_16 = new QLabel(widget_7);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(400, 40, 321, 251));

        verticalLayout_5->addWidget(widget_7);

        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        verticalLayout_4 = new QVBoxLayout(page4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_10 = new QWidget(page4);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        openButton = new QPushButton(widget_10);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(30, 20, 81, 21));
        ThreePlaneButton = new QPushButton(widget_10);
        ThreePlaneButton->setObjectName(QString::fromUtf8("ThreePlaneButton"));
        ThreePlaneButton->setGeometry(QRect(130, 20, 91, 21));
        qvtkWidget_4 = new QVTKWidget(widget_10);
        qvtkWidget_4->setObjectName(QString::fromUtf8("qvtkWidget_4"));
        qvtkWidget_4->setGeometry(QRect(40, 60, 211, 161));
        qvtkWidget_3 = new QVTKWidget(widget_10);
        qvtkWidget_3->setObjectName(QString::fromUtf8("qvtkWidget_3"));
        qvtkWidget_3->setGeometry(QRect(280, 60, 211, 161));
        qvtkWidget_2 = new QVTKWidget(widget_10);
        qvtkWidget_2->setObjectName(QString::fromUtf8("qvtkWidget_2"));
        qvtkWidget_2->setGeometry(QRect(40, 250, 211, 161));
        qvtkWidget_1 = new QVTKWidget(widget_10);
        qvtkWidget_1->setObjectName(QString::fromUtf8("qvtkWidget_1"));
        qvtkWidget_1->setGeometry(QRect(280, 250, 211, 161));

        verticalLayout_4->addWidget(widget_10);

        stackedWidget->addWidget(page4);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(UIDemo01);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(UIDemo01);
    } // setupUi

    void retranslateUi(QDialog *UIDemo01)
    {
        UIDemo01->setWindowTitle(QCoreApplication::translate("UIDemo01", "Form", nullptr));
        labIco->setText(QString());
        labTitle->setText(QString());
        btnMain->setText(QCoreApplication::translate("UIDemo01", "\344\270\273\347\225\214\351\235\242", nullptr));
        btnConfig->setText(QCoreApplication::translate("UIDemo01", "\345\233\276\345\203\217\345\211\215\345\244\204\347\220\206", nullptr));
        btnData->setText(QCoreApplication::translate("UIDemo01", "yolo\346\250\241\345\236\213", nullptr));
        btnHelp->setText(QCoreApplication::translate("UIDemo01", "3D\351\207\215\345\273\272", nullptr));
        btnExit->setText(QCoreApplication::translate("UIDemo01", "\347\224\250\346\210\267\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        btnMenu_Min->setToolTip(QCoreApplication::translate("UIDemo01", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMenu_Min->setText(QString());
#if QT_CONFIG(tooltip)
        btnMenu_Close->setToolTip(QCoreApplication::translate("UIDemo01", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMenu_Close->setText(QString());
        btnMenu_Max->setText(QString());
        imagelabel->setText(QString());
        pushButton->setText(QCoreApplication::translate("UIDemo01", "\351\200\211\346\213\251", nullptr));
        label->setText(QCoreApplication::translate("UIDemo01", "\350\205\220\350\232\200", nullptr));
        label2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("UIDemo01", "\350\206\250\350\203\200", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("UIDemo01", "\345\274\200\350\277\220\347\256\227", nullptr));
        label_7->setText(QCoreApplication::translate("UIDemo01", "\351\227\255\350\277\220\347\256\227", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("UIDemo01", "\346\217\220\345\217\226\345\206\205\350\276\271\347\225\214", nullptr));
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("UIDemo01", "\346\217\220\345\217\226\345\244\226\350\276\271\347\225\214", nullptr));
        label_12->setText(QString());
        label_2->setText(QCoreApplication::translate("UIDemo01", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("UIDemo01", "\344\275\277\347\224\250Yolo\347\275\221\347\273\234\350\256\255\347\273\203\347\273\223\346\236\234", nullptr));
        label_14->setText(QCoreApplication::translate("UIDemo01", "\350\257\212\346\226\255\347\273\223\346\236\234", nullptr));
        label_15->setText(QCoreApplication::translate("UIDemo01", "\345\216\237\345\247\213\345\233\276\345\203\217", nullptr));
        label_16->setText(QCoreApplication::translate("UIDemo01", "TextLabel", nullptr));
        openButton->setText(QCoreApplication::translate("UIDemo01", "\346\211\223\345\274\200", nullptr));
        ThreePlaneButton->setText(QCoreApplication::translate("UIDemo01", "\347\224\237\346\210\220\344\270\211\350\247\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIDemo01: public Ui_UIDemo01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIDEMO01_H
