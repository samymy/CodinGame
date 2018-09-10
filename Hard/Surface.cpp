#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
class Surface {

    char**  surface;
    int     width;
    int     height;
    
    int     getLakeSquareRec(char** _surface, int x, int y) {
        if (x < 0 || x >= width ||
            y < 0 || y >= height ||
            _surface[x][y] == '#'
        )
            return 0;
        
        _surface[x][y] = '#';
        
        return 1 + getLakeSquareRec(_surface, x - 1, y) +
                    getLakeSquareRec(_surface, x, y + 1) +
                    getLakeSquareRec(_surface, x + 1, y) +
                    getLakeSquareRec(_surface, x, y - 1);
    }
    
public:
    Surface(int _width, int _height): width(_width), height(_height) {
    
        surface = new char*[height];
        for (int i = 0; i < height; i++)
            surface[i] = new char[width];
    }
    
    ~Surface() {
        
        for (int i = 0; i < height; i++)
            delete[] surface[i];
        delete[] surface;
    }
    
    void    init(const vector<string>& _surface) {
       
        int row = -1;
        for (auto str : _surface) {
            
            ++row;
            int col = -1;
            for (auto c : str) {
                col++;
                surface[row][col] = c;
            } 
        }
    }
    
    int     getLakeSquare(int x, int y) {
        
        char**  surface_cpy;
        
        surface_cpy = new char*[height];
        for (int i = 0; i < height; i++)
            surface_cpy[i] = new char[width];
            
        for (int row = 0; row < height; row++)
            for (int col = 0; col < width; col++)
                surface_cpy[row][col] = surface[row][col];
                
        int lake_square = getLakeSquareRec(surface_cpy, x, y);
            
        for (int i = 0; i < height; i++)
            delete[] surface_cpy[i];
        delete[] surface_cpy;
        
        return lake_square;
    }
    
    void    showSurface() {
    
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++)
                cerr << surface[row][col];
            cerr << endl;
        }
    }

};
 
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    
    vector<string>  rows;
    
    for (int i = 0; i < H; i++) {
        string row;
        getline(cin, row);
        rows.push_back(row);
    }
    
    Surface surface(L, H);
    surface.init(rows);
    surface.showSurface();
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        
        cout << surface.getLakeSquare(Y, X) << endl;
    }
}
