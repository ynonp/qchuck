#include <QtCore/QCoreApplication>
#include "chuckapp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ChuckApp app;
    app.start( a.arguments() );

    return a.exec();
}
