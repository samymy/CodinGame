#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    
    vector<string>  rows;
    
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        rows.push_back(ROW);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    vector<int> indeces;
    
    for (auto symbol : T) {
        int index;
        if (!isalpha(symbol))
            index = 26;
        if (isupper(symbol))
            index = symbol - 65;
        if (islower(symbol))
            index = symbol - 97;
        indeces.push_back(index);
    }

    for (auto row : rows) {
        for (auto index : indeces)
            cout << row.substr(index * L, L);
        cout << endl;
    }
}
