#include "InputManager.h"

InputManager::InputManager() :
    data(""), poppedData("")
{
}

InputManager::InputManager(const QString& str) :
    data(str.toStdString()), poppedData("")
{
}

void InputManager::operator >>(char &ch)
{
    std::sstream ss;
    ch = data[0];
    data = data.substr(1);
    poppedData = ch;
}


void InputManager::operator >>(double& n_double)
{
    data.
}
