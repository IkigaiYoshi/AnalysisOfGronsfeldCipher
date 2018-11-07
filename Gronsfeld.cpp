//
// Created by ikigai on 15.09.18.
//
#include "Gronsfeld.h"


std::string Gronsfeld::encryptText(const std::string &text, const std::string &key) {
    std::string encryptText;
    int num = 0;
    for (int i = 0; i < text.size(); i++) {
        char symb = text[i];
        num = key[i % key.length()] - 48;
        char encryptSymb = alph[(alph.find(symb) + num) % alph.length()];
        encryptText.push_back(encryptSymb);
    }

    std::ofstream out("/home/ikigai/CLionProjects/Lab1/EncryptedText.txt");
    out << encryptText;

    return encryptText;
}

void Gronsfeld::decryptText(const std::string &text, const std::string &key) {
    int num = 0;
    std::string decryptText;

    for (int i = 0; i < text.size(); i++) {
        char symb = text[i];
        num = key[i % key.length()] - 48;
        int decryptSymb = static_cast<int>(alph.find(symb) - num);

        if (decryptSymb < 0)
            decryptSymb += alph.length();

        char encryptSymb = alph[decryptSymb];
        decryptText.push_back(encryptSymb);
    }

    std::ofstream out("/home/ikigai/CLionProjects/Lab1/DecryptedText.txt");
    out << decryptText;
}

