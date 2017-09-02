#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameState.create_test_game();

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(time_ring()));
    timer->start(2000);

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for(auto &specie : gameState.species_array)
    {
        specie->draw_sprite(&painter);
    }
}

void MainWindow::time_ring()
{
    gameState.move();
    update();
}
