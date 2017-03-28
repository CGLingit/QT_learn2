#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QDateTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::timerUpdate);
    timer->start(1000);

//    //开启三个定时器，返回其ID
//    id1=startTimer(1000);
//    id2=startTimer(2000);
//    id3=startTimer(10000);
}

Widget::~Widget()
{
    delete ui;
}

////1.通过事件来使用定时器
//void Widget::timerEvent(QTimerEvent *event)
//{
//    //判断是哪个定时器
//    if(event->timerId()==id1){
//        ui->label->setText("I LOVE YIYA");
//    }else if(event->timerId()==id2){
//        ui->label_2->setText("YI LOVE CHUNGUANG");
//    }
//    else{
//        qApp->quit();
//    }
//}
void Widget::timerUpdate(){
    //获取系统现在的时间
    QDateTime time=QDateTime::currentDateTime();
    //设置时间显示的格式
    QString str=time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->lineEdit->setText(str);
}
