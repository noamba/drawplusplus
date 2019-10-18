#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scribblearea.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void handleSave();

private:
    Ui::MainWindow *ui;

    ScribbleArea *scribbleArea;
    QAction *saveAction;
};
#endif // MAINWINDOW_H
