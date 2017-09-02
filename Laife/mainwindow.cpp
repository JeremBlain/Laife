#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    animal_specie animal;
    vegetal_specie veg;
    animal_specie animal2(200, 220);
    vegetal_specie veg2(333, 450);


    QPainter painter(this);

    animal.draw_sprite(&painter);
    veg.draw_sprite(&painter);
    animal2.draw_sprite(&painter);
    veg2.draw_sprite(&painter);
}
