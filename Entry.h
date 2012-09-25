#ifndef ENTRY_H
#define ENTRY_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "Calculator.h"


class Entry : public QWidget
{
    Q_OBJECT
public:
    Entry();

public slots:
    void envoyer() {
        QString result = calc.run(ligne_calc->text());
        ligne_calc->setText(result);
    }

private:
    Calculator calc;
    QLineEdit* ligne_calc;
    QPushButton* bouton_ok;
    QVBoxLayout* layout_principale;
};

#endif // ENTRY_H
