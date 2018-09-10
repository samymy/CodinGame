#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    
    string      lines[height];
    
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        lines[i] = line;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (lines[i][j] == '0') {
                cout << j << " " << i;
                
                int k = j;
                
                while (++k < width)
                    if (lines[i][k] == '0') {
                        cout << " " << k << " " << i;
                        break;
                    }
                if (k == width)
                    cout << " -1 -1";
                
                k = i;
                
                while (++k < height)
                    if (lines[k][j] == '0') {
                        cout << " " << j << " " << k;
                        break;
                    }
                if (k == height)
                    cout << " -1 -1";
                    
                cout << endl;
            }    

    // Three coordinates: a node, its right neighbor, its bottom neighbor
}
