#include "MainView.h"

#include <QApplication>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

#include "SerialReader.h"
#include "can_parser.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainView mainView(&a);

    mainView.show();
    return a.exec();
}


