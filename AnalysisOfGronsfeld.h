//
// Created by ikigai on 15.09.18.
//

#ifndef untitled1_ANALYSISOFGRONSFELD_H
#define untitled1_ANALYSISOFGRONSFELD_H

#include <map>
#include <vector>

class AnalysisOfGronsfeld {
    private:

        std::vector<std::string> divisionText(const std::string &text);

        char searchKeyForOnePartOfText(const std::string &onePartOfText);

        int findKeyLength(const std::string &text);

        float indexOfCoincidence(const std::string &text);

    public:

        void decryptText(const std::string &text);

};


#endif //untitled1_ANALYSISOFGRONSFELD_H
