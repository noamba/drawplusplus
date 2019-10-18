#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scribblearea.h"
#include "pensize.h"

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolBar>

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
    void handlePenSizeChange(int value);
    void openImage();
    void openColorPicker();

private:
    Ui::MainWindow *ui;

    ScribbleArea *scribbleArea;

    PenSize *penSize;

    QAction *saveAction;
    QVBoxLayout *outerLayout;
    QHBoxLayout *innerLayout;
    QToolBar *topToolBar;
    QToolBar *leftToolBar;
    QAction *openAction;
    QAction *openColorPickerAction;
};
#endif // MAINWINDOW_H
