#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "animal_specie.hpp"
#include "vegetal_specie.hpp"
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

private:
    Ui::MainWindow *ui;

    GameState gameState;
};

#endif // MAINWINDOW_HPP
