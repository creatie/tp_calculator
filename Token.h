#ifndef TOKEN_H
#define TOKEN_H



class Token
{
public:
    /** @category constructors */
    //------------------------------------------------------------------------
    Token(): kind(0), value(0)
    {}

    Token(char k, double v) : kind(k), value(v)
    {}

    Token(char k): kind(k), value(0)
    {}


    /** @category getters */
    //------------------------------------------------------------------------
    char getKind() const {
        return kind;
    }

    double getValue() const{
        return value;
    }


private:
    char kind;
    double value;
};




#endif // TOKEN_H
