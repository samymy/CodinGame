#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
class ConwaySequence {

    int     base;
    
public:
    ConwaySequence(int _base): base(_base) {}
    
    vector<int>     getLine(int idx) {
    
        vector<int> line;
        
        line.push_back(base);
        while (--idx) {
            
            vector<int> curr;
            typename vector<int>::iterator  it = line.begin();
            
            while (it != line.end()) {
                int nbr = *it;
                int count = 0;
                while (it != line.end() && *it == nbr) {
                    ++count;
                    ++it;
                }
                curr.push_back(count);
                curr.push_back(nbr);
            }
            line = curr;
        }
        
        return line;
    }

};

int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();

    ConwaySequence  sequence(R);
    
    vector<int> line = sequence.getLine(L);
    typename vector<int>::const_iterator    it = line.begin();
    
    cout << *it;
    while (++it != line.end())
        cout << " " << *it;
    cout << endl;
}
