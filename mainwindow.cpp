#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
         this->setStyleSheet("QWidget {background-image: url(:/img/chainik.jpg);};");
    this->setGeometry(0,0,1920,1100);
}

MainWindow::~MainWindow()
{

}

