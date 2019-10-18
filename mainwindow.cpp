#include "mainwindow.h"
#include "scribblearea.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
//#include <QSizePolicy>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QWidget *mainWidget = new QWidget(this);
    ui->setupUi(this);
    scribbleArea = new ScribbleArea;
    setCentralWidget(mainWidget);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    saveAction = new QAction(tr("&Save Masterpiece"));
    fileMenu->addAction(saveAction);

    setWindowTitle(tr("Scribble"));
    resize(500, 500);

    connect(saveAction, &QAction::triggered, this, &MainWindow::handleSave);

    outerLayout = new QVBoxLayout;
    mainWidget->setLayout(outerLayout);
    topToolBar = new QToolBar;
    outerLayout->addWidget(topToolBar);
    topToolBar->addAction(saveAction);

    innerLayout = new QHBoxLayout;
    outerLayout->addLayout(innerLayout);

    QWidget *leftWidget = new QWidget;
    leftWidget->setMaximumWidth(10);
//    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    innerLayout-> addWidget(leftWidget);
    innerLayout->addWidget(scribbleArea);
//    innerLayout->addSpacerItem(spacer);


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

