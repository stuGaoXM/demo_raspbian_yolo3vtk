#ifndef PAGES_H
#define PAGES_H


#include <QWidget>
//#include <Qlabel.h>
#include <QLineEdit>
#include <QImage>
#include <QFileInfo>
#include <QFileDialog>

class Page1 : public QWidget
{
public:
    Page1(QWidget *parent = 0);

private slots:
    //void openImg();

};

class Page2 : public QWidget
{
public:
    Page2(QWidget *parent = 0);
};

class Page3 : public QWidget
{
public:
    Page3(QWidget *parent = 0);
};
class Page4 : public QWidget
{
public:
    Page4(QWidget *parent = 0);
};


#endif // PAGES_H
