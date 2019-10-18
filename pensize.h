#ifndef PENSIZE_H
#define PENSIZE_H

#include <QWidget>
#include <QSlider>
#include <QScrollBar>

namespace Ui {
class pensize;
}

class PenSize : public QWidget
{
    Q_OBJECT

public:
    explicit PenSize(QWidget *parent = nullptr);
    QSlider *getSlider();
    ~PenSize();

private:
    Ui::pensize *ui;

    QSlider *penSlider;

    int minSize;
    int maxSize;
};

#endif // PENSIZE_H
