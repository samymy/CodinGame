#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    unordered_map<string, string>   MIME;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        MIME[EXT] = MT;
    }
    
    vector<string>  extensions;
    
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        
        const char*   pos = strrchr(FNAME.c_str(), '.');
        
        if (pos && pos + 1)
            extensions.push_back(pos + 1);
        else
            extensions.push_back("");
    }

    for (auto extension : extensions) {
        transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
        if (MIME.find(extension) != MIME.end())
            cout << MIME[extension] << endl;
        else
            cout << "UNKNOWN" << endl;
    }
    
}
