#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <QString>
#include <iostream>
#include <sstream>

class InputManager
{
public:
    InputManager();
    InputManager(const QString& str);

    void operator>>(char& ch);
    void operator>>(double& n_double);
    void operator>>(int& n_int);
    void putback();


private:
    std::string data;
    std::string poppedData;
};

#endif // INPUTMANAGER_H
