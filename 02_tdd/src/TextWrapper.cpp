#include "TextWrapper.h"

int TextWrapper::columns() const {
    return 10;
}

std::string TextWrapper::Wrapping(int columnsOut, std::string text) {

        std:: string bufor;
        if( text.length() < 2) {
            if(text.length()==1 && text==" ")
                return "";
            return text;
        }
        else
        {
            for( int i=0; i<text.length(); i++)
            {
                bufor = bufor + text[i];
                if(i!=text.length()-1  && i%columnsOut==columnsOut-1)
                    bufor = bufor + "\n";
            }
            return bufor;
        }
}
