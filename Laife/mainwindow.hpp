#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QKeyEvent>
#include "time.h"

#include "animal_specie.hpp"
#include "plant_specie.hpp"
#include "gamestate.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void time_ring(); //each time the timer rings : update the species state

private:
    Ui::MainWindow *ui;

    GameState gameState;
    QTimer *timer;
};

#endif // MAINWINDOW_HPP
