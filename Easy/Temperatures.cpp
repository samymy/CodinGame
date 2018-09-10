#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    
    vector<int>     temperatures;
    
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        
        temperatures.push_back(t);
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int     min = 0;
    
    if (temperatures.size())
        min = *min_element(temperatures.begin(), temperatures.end(),
            [](const int & a, const int & b){
                return abs(a) == abs(b) ? a > b : abs(a) < abs(b);
            });
    
    cout << min << endl;
}
