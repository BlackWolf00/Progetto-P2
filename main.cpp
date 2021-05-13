#include <iostream>
#include <QApplication>
#include "controller/controller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/icona.png"));
    Controller c;

    return a.exec();
}
