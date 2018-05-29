#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "enumerations.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    gameState.init_test_game();
    gameState.test_breed();

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

    for(auto food : gameState.food_array)
    {
        food.draw_sprite(&painter);
    }

    if(!gameState.pollens_array.empty())
        for(auto &pollen : gameState.pollens_array)
        {
            pollen.draw_sprite(&painter);
        }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_R :
        gameState.test_collision();
        break;

        default:
        break;
    }
}


void MainWindow::time_ring()
{
    gameState.grow_old();
    gameState.find_partner();
    gameState.breeding();
    gameState.move();
    gameState.eat();
    gameState.change_behavior();

    update();
}
