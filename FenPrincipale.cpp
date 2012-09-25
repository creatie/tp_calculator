#include "FenPrincipale.h"

FenPrincipale::FenPrincipale() :
    QWidget(),
    ligne_calc(new QLineEdit(this)),
    bouton_ok(new QPushButton("Calculer", this)),
    layout_principale(new QVBoxLayout(this))
{
    // 1. Format <<this>>
    //this->setFixedSize(200, 300);

    // 2. Format the widgets to show

    // 3. Set layout
    layout_principale->addWidget(ligne_calc);
    layout_principale->addWidget(bouton_ok);
    setLayout(layout_principale);

    connect(bouton_ok, SIGNAL(clicked()), this, SLOT(envoyer()));
}

void FenPrincipale::envoyer()
{
    QString result = calc.run(ligne_calc->text());
    ligne_calc->setText(result);
}

