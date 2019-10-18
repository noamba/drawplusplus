#include "mainwindow.h"
#include "scribblearea.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);


    setWindowTitle(tr("Scribble"));
    resize(500, 500);
}


MainWindow::~MainWindow()
{
    delete ui;
}

