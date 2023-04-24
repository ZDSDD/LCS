#include "diff.h"
enum Options {
    None,
    Add,
    Delete
};

Options resolveOptions(string s1) {
    s1 = s1.substr(0, s1.find('('));
    if (s1 == "Addition") {
        return Add;
    }
    if (s1 == "Removal") {
        return Delete;
    }
    if (s1 == "Unchanged") {
        return None;
    }
    return None;
}

int main() {
    string S1 = "ACBA";
    string S2 = "AABCAB";
    string result = findLcsString(S1, S2);
    cout << "\nS1: " << S1 << "\nS2: " << S2 << "\nLCS: " << result << endl;
    vector<string> d = diff(S1, S2);
    printLcsMatrix(computeLcsMatrix(S1,S2),S1,S2);
    for_each(d.begin(), d.end(), [S1, S2](auto i) {
        static int j = 0;
        static int z = 0;
        switch (resolveOptions(i)) {
            case Delete:
                cout <<" "<< S1[j++] << " - [ ]";
                break;
            case Add:
                cout << "[ ] + " << S2[z++];
                break;
            case None:
                cout <<" "<<S1[j++] << " = " << S2[z++];
                break;
        }
        cout << "  " << i << endl;
    });

}