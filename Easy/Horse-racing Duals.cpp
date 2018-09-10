#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    
    vector<int>     strengths;
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        strengths.push_back(Pi);
    }
    
    sort(strengths.begin(), strengths.end());
    adjacent_difference(strengths.begin(), strengths.end(), strengths.begin());
    cout << *min_element(strengths.begin(), strengths.end()) << endl;
}
