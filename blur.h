#ifndef BLUR_H
#define BLUR_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class Blur; }
QT_END_NAMESPACE

class Blur : public QMainWindow
{
    Q_OBJECT

public:
    Blur(QWidget *parent = nullptr);
    ~Blur();



private:
    Ui::Blur *ui;
    QString m_filePath;
    QString m_filePathBlur;
    int m_value = 0;
    QImage blurImage(QImage sourse, int value);

private slots:
    void openFile();
    void slaiderValue();
};
#endif // BLUR_H
