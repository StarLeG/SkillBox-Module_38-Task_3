#include "blur.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Blur w;

    w.show();
    return a.exec();
}
