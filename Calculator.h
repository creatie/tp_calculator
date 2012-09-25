#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>
#include <QTextStream>
#include <QDebug>

#include "Token.h"
#include "CalcFlux.h"


enum calc_Types{ PLUS = '+',
                 MINUS = '-',
                 MUL = '*',
                 DIV = '/',
                 NUMBER = '8',
                 NAME = '7',
                 END = '6',
                 ASSIGN = '=',
                 PRINT = '5',
                 LP = '(',
                 RP = ')' };

class Calculator
{
public:
    Calculator(); //Set to private
    QString run(const QString&);

private:
    double expr(bool get);  // Handle expression : 'SUM', 'SUBSTRACTION'
    double term(bool get);
    double prim(bool get);
    Token get_token();


    CalcFlux flux;
    Token curr_tok;
};

#endif // CALCULATOR_H
