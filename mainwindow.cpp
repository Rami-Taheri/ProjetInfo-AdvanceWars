#include "mainwindow.h"
#include "Gameobject.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <math.h>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i=0 ;i<21;i++){
        for (int j=0; j <21 ;j++){
            gameobject[i][j]= *new Gameobject(i,j,1);
        }}
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    for(int i=0 ;i<21;i++){
        for (int j=0; j <21 ;j++){
           painter.drawRect(i*40,j*40,38,38);
           if(gameobject[i][j].getType() == 1){
           painter.fillRect(i*40,j*40,38,38,Qt::cyan);}
           else{
           painter.fillRect(i*40,j*40,38,38,Qt::red);}
        }
    }
  }

void MainWindow::mousePressEvent(QMouseEvent *e)
{

    if(e->buttons() == Qt::LeftButton && selected){
        float x=floorf(e->x()/40);
        float y=floorf(e->y()/40);
        int r= (int)x;
        int s= (int)y;

        std::cout<<"la position en X est "<< e->x() <<std::endl;
        std::cout<<"la position en Y est "<< e->y() <<std::endl;
        std::cout<<"la position en X est "<< x <<std::endl;
        std::cout<<"la position en Y est "<< y <<std::endl;
        gameobject[posXselec][posYselec].setPosX(r);
        gameobject[posXselec][posYselec].setPosY(s);
        gameobject[r][s]=gameobject[posXselec][posYselec];
        gameobject[posXselec][posYselec]= *new Gameobject(posXselec,posYselec,1);
        std::cout<< "gameobject[posXselec][posYselec]="<< gameobject[posXselec][posYselec].getType()  <<std::endl;


        selected = false;
        this->repaint();
    }
    else if(e->buttons() == Qt::LeftButton){
        float x=floorf(e->x()/40);
        float y=floorf(e->y()/40);
        int r= (int)x;
        int s= (int)y;

        if( gameobject[r][s].getType()==2 ){
             selected=true ;
             posXselec=r;
             posYselec=s;
       }
    }
}

void MainWindow::setgameobject(Gameobject value)
{
    gameobject[value.getPosX()][value.getPosY()] = value;
}
