#include <QApplication>
#include "Entry.h"
#include "FenPrincipale.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv); //renamed the a to app
    FenPrincipale fenetre;


    fenetre.show();
    return app.exec(); //and we run the application
}
