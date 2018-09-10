#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    cin >> n; cin.ignore();
    
    vector<int>     stock_values;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        
        stock_values.push_back(v);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int max = *stock_values.begin(), diff = 0;
    
    for (auto val : stock_values) {
        if (val < max)
            if (abs(max - val) > diff)
                diff = abs(max - val);
        if (max < val)
            max = val;
    }

    cout << -diff << endl;
}
