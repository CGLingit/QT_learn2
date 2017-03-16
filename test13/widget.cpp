#include "widget.h"
#include "ui_widget.h"
#include<QLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGridLayout *layout=new QGridLayout;
    //添加部件，从第0行0列开始，占据1行2列
    layout->addWidget(ui->fontComboBox,0,0,1,2);
    //添加部件，从第0行2列开始，占据1行1列
    layout->addWidget(ui->pushButton,0,2,1,1);
    //添加部件，从第1行0列开始，，占据1行2列
    layout->addWidget(ui->textEdit,1,0,1,3);
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
