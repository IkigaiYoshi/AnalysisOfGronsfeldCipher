#include <iostream>
#include <fstream>
#include "AnalysisOfGronsfeld.h"
#include "Gronsfeld.h"

int main() {
    std::string text, key, str;

    std::ifstream in("/home/ikigai/CLionProjects/Lab1/text.txt");

    if (!in) {
        std::cerr << "Cannot open the File : " << "/home/ikigai/CLionProjects/Lab1/text.txt" << std::endl;
        return 0;
    }

    while (std::getline(in, str)) {
        if (!str.empty())
            text += str + ' ';
    }
    text.pop_back();
    in.close();

    Gronsfeld gronsfeld;
    std::cout << "Enter key:";
    std::cin >> key;
    auto encryptedText = gronsfeld.encryptText(text, key);
    std::cout << "Text encrypted." << std::endl;
    //gronsfeld.decryptText(encryptedText, key);
    AnalysisOfGronsfeld analysis;
    analysis.decryptText(encryptedText);
    std::cout << "Analysis done." << std::endl;

    return 0;
}