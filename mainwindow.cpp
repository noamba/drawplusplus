#include "mainwindow.h"
#include "scribblearea.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
//#include <QSizePolicy>
#include <QColorDialog>


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
    openAction = new QAction(tr("&Load"));
    openColorPickerAction = new QAction(tr("&Change Color"));
    fileMenu->addAction(saveAction);
    fileMenu ->addAction(openAction);
    fileMenu ->addAction((openColorPickerAction));

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
                               tr("Images (*.png *.jpg *.giff)"));
    if(!fileName.isEmpty()&& !fileName.isNull()){
        QString filetype = fileName.split(".").last();
        if (filetype.isEmpty()){
            filetype = "png";
        }
        scribbleArea->saveImage(fileName, filetype.toUtf8());
}
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



