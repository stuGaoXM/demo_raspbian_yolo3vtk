#include "pages.h"
#include <QtWidgets>

Page1::Page1(QWidget *parent)
    : QWidget(parent)
{


}
//void Page1::buttonClicked(){}

Page2::Page2(QWidget *parent)
    : QWidget(parent)
{
    QLabel *pageName = new QLabel(tr("Page2"));
    QHBoxLayout *myLayout = new QHBoxLayout;
    myLayout->addWidget(pageName, 1, Qt::AlignCenter);
    setLayout(myLayout);
}
