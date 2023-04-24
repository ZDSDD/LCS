//
// Created by User on 12.04.2023.
//

#ifndef PROJEKT3_DIFF_H
#define PROJEKT3_DIFF_H
#include "lcs.h"

vector<string> diff(string text1, string text2) {
    vector<string> results;
    vector<vector<ull>> lcs = computeLcsMatrix(text1, text2);

    ull i = text1.size();
    ull j = text2.size();

    while (i != 0 || j != 0) {

        if (i == 0) {               //RESULTS IF WE ITERATED THROUGH WHOLE STRING 1
            results.push_back("Addition(" + string(1, text2[j - 1]) + ")");
            j -= 1;
        } else if (j == 0) {        //RESULTS IF WE ITERATED THROUGH WHOLE STRING 2
            results.push_back("Removal(" + string(1, text1[i - 1]) + ")");
            i -= 1;
        } else if (text1[i - 1] == text2[j - 1]) {
            results.push_back("Unchanged(" + string(1, text1[i - 1]) + ")");
            i -= 1;
            j -= 1;
        } else if (lcs[i - 1][j] <= lcs[i][j - 1]) {
            results.push_back("Addition(" + string(1, text2[j - 1]) + ")");
            j -= 1;
        } else {
            results.push_back("Removal(" + string(1, text1[i - 1]) + ")");
            i -= 1;
        }
    }
    reverse(results.begin(), results.end());
    return results;
}
#endif //PROJEKT3_DIFF_H
