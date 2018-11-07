//
// Created by ikigai on 15.09.18.
//

#ifndef Lab1_GRONSFELD_H
#define Lab1_GRONSFELD_H


#include <ostream>
#include <fstream>

class Gronsfeld {
private:
    std::string alph = ":;'?/!123456789-,. abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:

    std::string encryptText(const std::string &text, const std::string &key);

    void decryptText(const std::string &text, const std::string &key);

};

#endif //Lab1_GRONSFELD_H
