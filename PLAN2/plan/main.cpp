#include "config.h"
#include "widget.h"

#include <QApplication>
#include <QResource>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
        QResource::registerResource(GAME_RES_PATH);
    w.show();
    return a.exec();
}
