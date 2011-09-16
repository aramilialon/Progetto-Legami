/*
  File: main.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "gui/legamimainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTranslator>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);

        QTranslator* translator= new QTranslator();
        translator->load("./translation/legami_eng");
        app.installTranslator(translator);

    legamimainwindow legmainwin;
    legmainwin.show();
    return app.exec();
}
