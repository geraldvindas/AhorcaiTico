#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>

class QMainWindow;
class QGraphicsScene;
class QGraphicsView;
class QStyleFactory;
class QSvgRenderer;
class QPushButton;
class QPalette;


class MainWindow : public QApplication
{
  protected:
    QGraphicsScene* escena;
    QGraphicsView* vista;

  public:
    MainWindow(int &argc, char **argv, int flags = ApplicationFlags);
    ~MainWindow();
    int run();

  protected slots:

};

#endif // MAINWINDOW_H