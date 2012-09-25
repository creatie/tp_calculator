#include "Calculator.h"

Calculator::Calculator():
    flux(""), curr_tok()
{
}

QString Calculator::run(const QString& line)
{
    //this.inputLine = entree;
    flux = line+QString("\n");
    get_token();

    return QString().number(expr(false)); // return a string repsesentation of this number
}


double Calculator::expr(bool get)
{
    double left = term(get);

    while(true){
        switch (curr_tok.getKind()){
        case PLUS:
            left = left + term(true);	// TODO change
            break;
        case MINUS:
            left = left - term(true);	// TODO change
            break;
        default:
            return left;
        }
    }
}

////------------------------------------------------------

double Calculator::term(bool get) // multiply or divide
{
    double left = prim(get);

    while(true){
        switch (curr_tok.getKind()){
        case MUL:
            left = left * prim(true);
            break;
        case DIV:{
            double d = prim(true);
            if(d != 0.0){
                //left = left / term(true);
                left = left / d;
                break;
            }//if
            else{
                qDebug() << "oops: some tried dividing by 0\n";
                //msg_erreur = "erreur: division par 0";
                return 0;
            }
        }
        default:
            return left;
        }
    }
}

////------------------------------------------------------

double Calculator::prim(bool get)
{
    if(get) get_token();

    switch(curr_tok.getKind()){
    case NUMBER:                     //floating point constant
    {
        double v = curr_tok.getValue();
        get_token();
        return v;
    }
        /** @todo
        case NAME:
        {
            double& v = table[std::string_value];
            if (get_token() == ASSIGN) v = expr(true);
            return v;
        }*/
    case MINUS:                     //unary minus
    {
        return -prim(true);
    }
    case LP:
    {
        double e = expr(true);
        if (curr_tok.getKind() != RP){
            qDebug() << "oops: Right parenthesis expected\n";
            //msg_erreur = "erreur: manque parenthese de femeture";
            return 0;
        }

        //throw  ErreurRpExpected();
        get_token();    // eat')'
        return e;
    }
    default:
        qDebug() << "oops: primary expected\n";
        //msg_erreur = "erreur: manque numero primaire";
        return 0;
    }// switch

    return 0;
}

////------------------------------------------------------

Token Calculator::get_token() {
    char ch;
    flux >> ch;

    /// @todo : skip whitespaces

    switch(ch){
    case ';': case '\n':
        return curr_tok = Token(PRINT);

    case '*' : case '/' : case '+' : case '-' : case '(' : case ')' : case '=' :
        // cast it to Token_value assign to current token variable and returns it
        return curr_tok= Token(ch);

        // if (ch) is a number or '.'
    case '0' : case '1' : case '2' : case '3' : case '4' :
    case '5' : case '6' : case '7' : case '8' : case '9' :
    case '.' :
        // put (ch) back to istream and read it as a number now
        flux.putback();
        double temp;
        return curr_tok = Token(NUMBER, ( flux.operator>> (temp) ));


    default:
        /// @todo
        /*
        if (isalpha(ch)){
            std::string_value = ch;
            while (input->get(ch) && isalnum(ch))
                std::string_value.push_back(ch);
            input->putback(ch);
            return curr_tok=NAME;
        }
        error("bad token");
        */
        return Token(PRINT);
    }
}
