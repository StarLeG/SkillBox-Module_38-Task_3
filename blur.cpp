#include "blur.h"
#include "./ui_blur.h"

Blur::Blur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Blur)
{
    ui->setupUi(this);
}

Blur::~Blur()
{
    delete ui;
}

QImage Blur::blurImage(QImage sourse, int value)
{
    if(sourse.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(sourse));

    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(value);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result (sourse.size(),
                   QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter,
                 QRectF(),
                 QRectF(0, 0, sourse.width(),
                        sourse.height()));
    return result;
}

void Blur::openFile()
{
   m_filePath = QFileDialog::getOpenFileName(nullptr,
                                 "Open image .jpg",
                                 "/pic/",
                                 "jpg files (*.jpg)");
   ui->Image->setPixmap(QPixmap(m_filePath));
   for(int i = 0; i < m_filePath.length() - 4; i++ )
   {
       m_filePathBlur.push_back(m_filePath[i]);
   }

    m_filePathBlur.push_back("blur.jpg");

}

void Blur::slaiderValue()
{
    m_value = ui->Slider->value();
    auto blured = blurImage(QImage(m_filePath), m_value);
    blured.save(m_filePathBlur);
    ui->Image->setPixmap(QPixmap(m_filePathBlur));
}


