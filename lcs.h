//
// Created by User on 12.04.2023.
//

#ifndef PROJEKT3_LCS_H
#define PROJEKT3_LCS_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using ull = unsigned long long;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::max;

vector<vector<ull>> computeLcsMatrix(string text1, string text2) {
    ull n = text1.length();
    ull m = text2.length();
    vector<vector<ull>> lcs(n + 1, vector<ull>(m + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    return lcs;
}

string findLcsString(string text1, string text2) {
    string result;
    vector<vector<ull>> lcs = computeLcsMatrix(text1, text2);

    ull i = text1.length();
    ull j = text2.length();

    while (i != 0 && j != 0) {
        if (text1[i - 1] == text2[j - 1]) {
            result.push_back(text1[i - 1]);
            i -= 1;
            j -= 1;
        } else if (lcs[i - 1][j] <= lcs[i][j - 1]) {
            j -= 1;
        } else {
            i -= 1;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}


void printLcsMatrix(const vector<vector<ull>> & matrix,const string& a,const string& b){
    cout << "\t  ";
    std::for_each(b.begin(),b.end(),[](char x){
        cout << x <<' ';
    });
    cout << endl << '\t';
    int i = 0;
    for(const auto & item : matrix){
        for(const auto & item2 : item){
            cout << item2 << ' ';
        }cout << endl << a[i++] <<'\t';
    }
    cout << endl;
}
#endif //PROJEKT3_LCS_H
