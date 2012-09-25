#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "Calculator.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT
public:
    FenPrincipale();

public slots:
    void envoyer();

private:
    Calculator calc;
    QVBoxLayout* layout_principale;
    QLineEdit* ligne_calc;  
};

#endif // FENPRINCIPALE_H
