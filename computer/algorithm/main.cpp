#include <QCoreApplication>
#include "src/GTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    GTest test;
    test.test();
    return a.exec();
}
