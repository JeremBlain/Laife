#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    gameState.create_test_game();
    gameState.fill_up_cos_sin_array();

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(time_ring()));
    timer->start(500);

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
    gameState.change_behavior();
    gameState.move();
    update();
}
