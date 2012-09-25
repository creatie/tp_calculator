#include "CalcFlux.h"

CalcFlux::CalcFlux()
{
}


char CalcFlux::operator >>(char &ch)
{
    if (data.isEmpty()){
        ch = 0;
    }
    else{	//if not empty
        ch = data.toStdString()[0];
        poppedData = QString(ch);
        data = data.mid(1);
    }
    return ch;
}


double CalcFlux::operator >>(double& num_double){
    if (data.isEmpty()){
        return num_double = 0;
    }
    else {	//if not empty
        int i=0;
        for(; i < data.length(); ++i)
            if ( data.at(i) != QChar('.') && (data.at(i) < QChar('0') || data.at(i) > QChar('9')) )
                break;

        poppedData = data.mid(0, i);
        data = data.mid(i);
        return num_double = poppedData.toDouble();
    }
}

void CalcFlux::putback(){
    data = poppedData+data;
    poppedData = "";
}
