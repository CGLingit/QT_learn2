#include "widget.h"
#include "ui_widget.h"
#include<QMovie>
#include<QMenu>
#include<QCompleter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //label显示图片
    ui->label_3->setPixmap(QPixmap("E:/QTpractice/untitled5/2.png"));
    QMovie *movie=new QMovie("E:/QTpractice/untitled5/1.gif");
    ui->label->setMovie(movie);
    movie->start();
    ui->pbt1->setText(tr("&nihao"));//快捷键alt+N
    ui->pbt2->setText(tr("帮助&H"));
    ui->pbt3->setIcon(QIcon("E:/QTpractice/untitled5/time.ico"));
    ui->pbt3->setText(tr("z&oom"));
    QMenu *menu=new QMenu(this);
    menu->addAction(QIcon("E:/QTpractice/untitled5/time.ico"),tr("放大"));
    menu->addAction(QIcon("E:/QTpractice/untitled5/time.ico"),tr("放大"));
    ui->pbt3->setMenu(menu);

    //自动补全功能
    QStringList wordList;
    wordList<<"QT"<<"QT Creatot"<<tr("nihao");
    QCompleter *completer=new QCompleter(wordList,this);
    //设置大小写不敏感
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);
    //设置时间为当前时间
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    //设置时间显示格式
    ui->dateEdit->setDisplayFormat(tr("yyyy年MM月dd日dddHH时mm分ss秒"));
}

Widget::~Widget()
{
    delete ui;
}
