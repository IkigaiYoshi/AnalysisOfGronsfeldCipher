//
// Created by ikigai on 15.09.18.
//

#include "AnalysisOfGronsfeld.h"
#include "Gronsfeld.h"

#include <fstream>
#include <math.h>
#include <iostream>


char AnalysisOfGronsfeld::searchKeyForOnePartOfText(const std::string &onePartOfText) {
    std::map<char, float> characters;
    for (char symb : onePartOfText) {
        characters[symb] += 1;
    }

    char res = ' ';
    float charSymb = 0;

    for (char symb : onePartOfText) {
        if (characters[symb] > charSymb) {
            res = static_cast<char>(symb - 48);
            charSymb = characters[symb];
        }
    }

    return res;
}

void AnalysisOfGronsfeld::decryptText(const std::string &text) {
    std::vector<std::string> monoAlphabeticalTexts = divisionText(text);

    std::string key;
    for (const auto &onePartOfText : monoAlphabeticalTexts) {
        key += searchKeyForOnePartOfText(onePartOfText);
    }
    std::cout << "Key analysis: " << key << std::endl;
    Gronsfeld gronsfeld;
    gronsfeld.decryptText(text, key);
}

std::vector<std::string> AnalysisOfGronsfeld::divisionText(const std::string &text) {
    int keyLenght = findKeyLength(text);
    std::vector<std::string> partsOfText;

    for (int j = 0; j < keyLenght; j++) {
        std::string onePart;

        for (int i = j; i < text.length(); i += keyLenght) {
            onePart += text[i];
        }
        partsOfText.push_back(onePart);
    }

    return partsOfText;
}

int AnalysisOfGronsfeld::findKeyLength(const std::string &text) {
    std::string piecesOfText;
    int N = static_cast<int>(text.length()), res = 0;
    float IC = 0;

    for (int i = 2; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j % i == 0)
                piecesOfText += text[j];
        }

        IC = indexOfCoincidence(piecesOfText);

        if (IC > 0.07) {
            res = i;
            break;
        }

        piecesOfText.clear();
    }
    return res;
}

float AnalysisOfGronsfeld::indexOfCoincidence(const std::string &text) {
    std::map<char, float> characters;
    for (char symb : text) {
        characters[symb]++;
    }

    float IC = 0;
    int N = static_cast<int>(text.length());

    for (const auto &character : characters)
        IC += (character.second * (character.second - 1)) / (N * (N - 1));

    return IC;
}
