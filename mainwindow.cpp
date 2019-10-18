#include "mainwindow.h"
#include "scribblearea.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    saveAction = new QAction(tr("&Save Masterpiece"));
    openAction = new QAction(tr("&Load"));
    openColorPickerAction = new QAction(tr("&Change Color"));
    fileMenu->addAction(saveAction);
    fileMenu ->addAction(openAction);
    fileMenu ->addAction((openColorPickerAction));

    setWindowTitle(tr("Scribble"));
    resize(500, 500);

    connect(saveAction, &QAction::triggered, this, &MainWindow::handleSave);
    connect(openAction, &QAction::triggered, this, &MainWindow::openImage);
    connect(openColorPickerAction, &QAction::triggered, this, &MainWindow::openColorPicker);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleSave()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "untitled.png",
                               tr("Images (*.png)"));
    scribbleArea->saveImage(fileName, "png");
}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));
    scribbleArea->openImage(fileName);
}

void MainWindow::openColorPicker()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    scribbleArea->setPenColor(color);
}



