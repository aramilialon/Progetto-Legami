/*
  File: main.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "gui/legamimainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    legamimainwindow legmainwin;
    legmainwin.show();
    return app.exec();
}
