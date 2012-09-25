#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#include "Calculator.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT
public:
    FenPrincipale();

public slots:
    void envoyer();
    void tout_effacer() { ligne_calc->clear(); }
    void corriger() {
        QString tmp = ligne_calc->text();
        ligne_calc->setText( tmp.mid(0, tmp.size()-1) );
    }

    void append_point() { ligne_calc->setText(ligne_calc->text() + QString(".")); }
    void append_0() { ligne_calc->setText(ligne_calc->text() + QString("0")); }
    void append_1() { ligne_calc->setText(ligne_calc->text() + QString("1")); }
    void append_2() { ligne_calc->setText(ligne_calc->text() + QString("2")); }
    void append_3() { ligne_calc->setText(ligne_calc->text() + QString("3")); }
    void append_4() { ligne_calc->setText(ligne_calc->text() + QString("4")); }
    void append_5() { ligne_calc->setText(ligne_calc->text() + QString("5")); }
    void append_6() { ligne_calc->setText(ligne_calc->text() + QString("6")); }
    void append_7() { ligne_calc->setText(ligne_calc->text() + QString("7")); }
    void append_8() { ligne_calc->setText(ligne_calc->text() + QString("8")); }
    void append_9() { ligne_calc->setText(ligne_calc->text() + QString("9")); }
    void append_div() { ligne_calc->setText(ligne_calc->text() + QString("/")); }
    void append_mult() { ligne_calc->setText(ligne_calc->text() + QString("*")); }
    void append_plus() { ligne_calc->setText(ligne_calc->text() + QString("+")); }
    void append_minus() { ligne_calc->setText(ligne_calc->text() + QString("-")); }
    void append_p_gauche() { ligne_calc->setText(ligne_calc->text() + QString("(")); }
    void append_p_droite() { ligne_calc->setText(ligne_calc->text() + QString(")")); }

private:
    Calculator calc;
    QLineEdit* ligne_calc;
    QGridLayout* layout_principale;

    // Bouttons
    QPushButton* bouton_ok;

    QPushButton* bouton_plus;
    QPushButton* bouton_minus;
    QPushButton* bouton_div;
    QPushButton* bouton_mult;

    QPushButton* bouton_num_1;
    QPushButton* bouton_num_2;
    QPushButton* bouton_num_3;
    QPushButton* bouton_num_4;
    QPushButton* bouton_num_5;
    QPushButton* bouton_num_6;
    QPushButton* bouton_num_7;
    QPushButton* bouton_num_8;
    QPushButton* bouton_num_9;
    QPushButton* bouton_num_0;

    QPushButton* bouton_percent;
    QPushButton* bouton_point;
    QPushButton* bouton_p_gauche;
    QPushButton* bouton_p_droite;
    QPushButton* bouton_return;
    QPushButton* bouton_clear;
};

#endif // FENPRINCIPALE_H
