#include "TextWrapper.h"

int TextWrapper::columns() const {
    return 10;
}

std::string TextWrapper::Wrapping(int columnsOut, std::string text) {

        std:: string bufor;
        int OmittedSpaces=0;                // spacje pominięte - zamienione na \n
                                            // wartość służąca "cofaniu" indeksu i bieżącego znaku text[i] podczas dodawania znaku nowej linii

        for( int i=0; i<text.length(); i++)
        {
            int o = i - OmittedSpaces;
            if(i!=0 && i%columnsOut==0+OmittedSpaces && text[i]==' ')
            {
                OmittedSpaces++;
                continue;
            }
            bufor = bufor + text[i];
            if(i!=text.length()-1  && o%columnsOut==columnsOut-1)
                bufor = bufor + "\n";
        }
        return bufor;
}
