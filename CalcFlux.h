#ifndef CALCFLUX_H
#define CALCFLUX_H

#include <QString>

class CalcFlux
{
public:
    CalcFlux(const QString& str) : data(str), poppedData("") {}
    CalcFlux& operator= (const QString& str) { data = str; return (*this); }

    char operator>>(char& ch);
    double operator>>(double& num_double);
    void putback();

private:
    CalcFlux();
    QString data;
    QString poppedData;
};

#endif // CALCFLUX_H
