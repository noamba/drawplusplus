#include "mainwindow.h"
#include "scribblearea.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);

    PenSize *penSize = new PenSize();
    penSize->show();

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    saveAction = new QAction(tr("&Save Masterpiece"));
    openAction = new QAction(tr("&Load"));
    fileMenu->addAction(saveAction);
    fileMenu ->addAction(openAction);

    setWindowTitle(tr("Scribble"));
    resize(500, 500);

    connect(penSize->getSlider(), &QSlider::valueChanged, this, &MainWindow::handlePenSizeChange);
    connect(saveAction, &QAction::triggered, this, &MainWindow::handleSave);
    connect(openAction, &QAction::triggered, this, &MainWindow::openImage);

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

void MainWindow::handlePenSizeChange(int value)
{
    scribbleArea->setPenSize(value);
}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));
    scribbleArea->openImage(fileName);
}
