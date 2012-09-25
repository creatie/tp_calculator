#include "FenPrincipale.h"

FenPrincipale::FenPrincipale() :
    QWidget(),
    calc(),
    ligne_calc(new QLineEdit(this)),
    layout_principale(new QGridLayout(this)),

    bouton_ok(new QPushButton("=", this)),
    bouton_plus(new QPushButton("+", this)),
    bouton_minus(new QPushButton("-", this)),
    bouton_div(new QPushButton(QString("/"), this)), // TODO "÷"
    bouton_mult(new QPushButton(QString("*"), this)), // TODO "×"

    bouton_num_1(new QPushButton("1", this)),
    bouton_num_2(new QPushButton("2", this)),
    bouton_num_3(new QPushButton("3", this)),
    bouton_num_4(new QPushButton("4", this)),
    bouton_num_5(new QPushButton("5", this)),
    bouton_num_6(new QPushButton("6", this)),
    bouton_num_7(new QPushButton("7", this)),
    bouton_num_8(new QPushButton("8", this)),
    bouton_num_9(new QPushButton("9", this)),
    bouton_num_0(new QPushButton("0", this)),

    bouton_percent(new QPushButton("%", this)),
    bouton_point(new QPushButton(".", this)),
    bouton_p_gauche(new QPushButton("(", this)),
    bouton_p_droite(new QPushButton(")", this)),
    bouton_return(new QPushButton("R", this)),
    bouton_clear(new QPushButton("C", this))
{
    /// @note 1. Format <<this>> -----------------------------
    this->setFixedSize(320, 200);


    /// @note 2. Format the widgets to show ------------------
    ligne_calc->setFixedHeight(60);
    ligne_calc->setFont(QFont("Lucida Console", 15, QFont::Bold));
    ligne_calc->setAlignment(Qt::AlignRight);
    ligne_calc->setReadOnly(true);
    //ligne_calc->setText("1+2/(6-7)*8");

    // Change font on the CLEAR and RETURN button
    bouton_clear->setFont(QFont("Arial", 11, QFont::Bold));
    bouton_return->setFont(QFont("Arial", 11, QFont::Bold));

    // Work on the "=" button to expand through multiple columns and rows
    bouton_ok->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    bouton_ok->setFont(QFont("Monospace", 30, QFont::Bold));


    /// @note 3. Set layout ----------------------------------
    layout_principale->setSpacing(0);

    // 1° row
    layout_principale->addWidget(ligne_calc, 0, 0, 1, 6);

    // 2° row
    layout_principale->addWidget(bouton_num_7, 1, 0);
    layout_principale->addWidget(bouton_num_8, 1, 1);
    layout_principale->addWidget(bouton_num_9, 1, 2);
    layout_principale->addWidget(bouton_div, 1, 3);
    layout_principale->addWidget(bouton_return, 1, 4);
    layout_principale->addWidget(bouton_clear, 1, 5);

    // 3° row
    layout_principale->addWidget(bouton_num_4, 2, 0);
    layout_principale->addWidget(bouton_num_5, 2, 1);
    layout_principale->addWidget(bouton_num_6, 2, 2);
    layout_principale->addWidget(bouton_mult, 2, 3);
    layout_principale->addWidget(bouton_p_gauche, 2, 4);
    layout_principale->addWidget(bouton_p_droite, 2, 5);

    // 4° row
    layout_principale->addWidget(bouton_num_1, 3, 0);
    layout_principale->addWidget(bouton_num_2, 3, 1);
    layout_principale->addWidget(bouton_num_3, 3, 2);
    layout_principale->addWidget(bouton_plus, 3, 3);
    layout_principale->addWidget(bouton_ok, 3, 4, 2, 2); // span 4 grids

    // 5° row
    layout_principale->addWidget(bouton_num_0, 4, 0);
    layout_principale->addWidget(bouton_point, 4, 1);
    layout_principale->addWidget(bouton_percent, 4, 2);
    layout_principale->addWidget(bouton_minus, 4, 3);


    setLayout(layout_principale);

    /// @note 4. Make connections --------------------------
    connect(bouton_point, SIGNAL(clicked()), this, SLOT(append_point()));
    connect(bouton_num_0, SIGNAL(clicked()), this, SLOT(append_0()));
    connect(bouton_num_1, SIGNAL(clicked()), this, SLOT(append_1()));
    connect(bouton_num_2, SIGNAL(clicked()), this, SLOT(append_2()));
    connect(bouton_num_3, SIGNAL(clicked()), this, SLOT(append_3()));
    connect(bouton_num_4, SIGNAL(clicked()), this, SLOT(append_4()));
    connect(bouton_num_5, SIGNAL(clicked()), this, SLOT(append_5()));
    connect(bouton_num_6, SIGNAL(clicked()), this, SLOT(append_6()));
    connect(bouton_num_7, SIGNAL(clicked()), this, SLOT(append_7()));
    connect(bouton_num_8, SIGNAL(clicked()), this, SLOT(append_8()));
    connect(bouton_num_9, SIGNAL(clicked()), this, SLOT(append_9()));
    connect(bouton_div, SIGNAL(clicked()), this, SLOT(append_div()));
    connect(bouton_mult, SIGNAL(clicked()), this, SLOT(append_mult()));
    connect(bouton_plus, SIGNAL(clicked()), this, SLOT(append_plus()));
    connect(bouton_minus, SIGNAL(clicked()), this, SLOT(append_minus()));
    connect(bouton_p_gauche, SIGNAL(clicked()), this, SLOT(append_p_gauche()));
    connect(bouton_p_droite, SIGNAL(clicked()), this, SLOT(append_p_droite()));

    connect(bouton_clear, SIGNAL(clicked()), this, SLOT(tout_effacer()));
    connect(bouton_return, SIGNAL(clicked()), this, SLOT(corriger()));
    connect(bouton_ok, SIGNAL(clicked()), this, SLOT(envoyer()));
}

void FenPrincipale::envoyer()
{
    QString result = calc.run(ligne_calc->text());
    ligne_calc->setText(result);
}

