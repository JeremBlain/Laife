#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "enumerations.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    gameState.create_test_game();

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(time_ring()));
    timer->start(Constant::TICK);

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for(auto &specie : gameState.animals_array)
    {
        specie->draw_sprite(&painter);
    }

    for(auto &specie : gameState.vegans_array)
    {
        specie->draw_sprite(&painter);
    }

    if(!gameState.pollens_array.empty())
        for(auto &pollen : gameState.pollens_array)
        {
            pollen->draw_sprite(&painter);
        }
}

void MainWindow::time_ring()
{
    gameState.grow_old();
    gameState.find_partner();
    gameState.move();
    gameState.breed();
    gameState.change_behavior();

    update();
}
