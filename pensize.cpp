#include "pensize.h"
#include "ui_pensize.h"

#include <QVBoxLayout>

PenSize::PenSize(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pensize)
{
    ui->setupUi(this);

    QVBoxLayout* layout = new QVBoxLayout();

    minSize = 1;
    maxSize = 30;

    penSlider = new QSlider(Qt::Horizontal);
    penSlider->setMinimum(minSize);
    penSlider->setMaximum(maxSize);
    penSlider->setFocusPolicy(Qt::StrongFocus);
    penSlider->setTickPosition(QSlider::TicksBothSides);
    penSlider->setTickInterval(5);
    penSlider->setSingleStep(1);

    layout->addWidget(penSlider);
//    layout->addItem(new QSpacerItem());
    setLayout(layout);

}

QSlider* PenSize::getSlider()
{
    return penSlider;
}

PenSize::~PenSize()
{
    delete ui;
}
