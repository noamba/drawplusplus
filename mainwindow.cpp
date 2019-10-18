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

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    saveAction = new QAction(tr("&Save Masterpiece"));
    fileMenu->addAction(saveAction);

    setWindowTitle(tr("Scribble"));
    resize(500, 500);

    connect(saveAction, &QAction::triggered, this, &MainWindow::handleSave);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleSave()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "untitled.png",
                               tr("Images (*.png *.jpg *.giff)"));
    if(!fileName.isEmpty()&& !fileName.isNull()){
        QString filetype = fileName.split(".").last();
        if (filetype.isEmpty()){
            filetype = "png";
        }
        scribbleArea->saveImage(fileName, filetype.toUtf8());
}
}

