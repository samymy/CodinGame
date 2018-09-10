#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
class Scrabble {

    const string  letters[10] = {
        "eaionrtlsu",
        "dg",
        "bcmp",
        "fhvwy",
        "k",
        "",
        "",
        "jx",
        "",
        "qz"
    };
    
    map<string, int>    words;

public:
    Scrabble() {};
    
    void    addWord(const string& word) {
        
        int     points = 0;
        
        for (auto c : word)
            for (int i = 0; i < sizeof(letters) / sizeof(letters[0]); i++)
                if (letters[i].find_first_of(c) != -1) {
                    points += i + 1;
                    break;
                }
        
        words[word] = points;
    }
    
    string   findWord(const string& letters) {
    
        map<string, int> found_words;
    
        for (auto pair : words) {
            int i;
            for (i = 0; i < pair.first.size(); i++)
                if (letters.find_first_of(pair.first[i]) == -1)
                    break;
            if (i == pair.first.size())
                found_words[pair.first] = words[pair.first];
        }
                
        pair<string, int> word = *max_element(found_words.begin(), found_words.end(),
            [](const pair<string, int>& a, const pair<string, int>& b){
                return a.second < b.second;
            }
        );
        
        cerr << "Words" << endl;
        for (auto i : words)
            cerr << i.first << "<->" << i.second << endl;
        cerr << "Found words" << endl;
        for (auto j : found_words)
            cerr << j.first << "<->" << j.second << endl;
        
        for (auto i : words)
            for (auto j : found_words)
                if (i.first == j.first && i.second == word.second)
                    return i.first;
    }

};


int main()
{
    int N;
    cin >> N; cin.ignore();
    
    Scrabble scrabble;
    
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        
        scrabble.addWord(W);
    }
    string LETTERS;
    getline(cin, LETTERS);

    cout << scrabble.findWord(LETTERS) << endl;
}
