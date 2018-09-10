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

struct Point {
    int x;
    int y;
    
    Point(): x(0), y(0) {}
    Point(int _x, int _y): x(_x), y(_y) {}
};

class Batman {

    Point   position;
    Point   bounds;
    Point   delta;
    
public:
    Batman(int X0, int Y0, int W, int H) {
        
        position = Point(X0, Y0);
        bounds = Point(W, H);
        delta = Point(W / 2, H / 2);
    }
    
    void    move(char to) {
        
        if (to == 'U') {
            position.y -= delta.y;
            if (position.y < 0)
                position.y = 0;
            delta.y += 1;
            delta.y /= 2;
            if (delta.y < 1)
                delta.y = 1;
        }
        if (to == 'D') {
            position.y += delta.y;
            if (position.y >= bounds.y)
                position.y = bounds.y - 1;
            delta.y += 1;
            delta.y /= 2;
            if (delta.y < 1)
                delta.y = 1;
        }
        if (to == 'R') {
            position.x += delta.x;
            if (position.x >= bounds.x)
                position.x = bounds.x - 1;
            delta.x += 1;
            delta.x /= 2;
            if (delta.x < 1)
                delta.x = 1;
        }
        if (to == 'L') {
            position.x -= delta.x;
            if (position.x < 0)
                position.x = 0;
            delta.x += 1;
            delta.x /= 2;
            if (delta.x < 1)
                delta.x = 1;
        }
    }
    
    int     getX() const {
        return position.x;
    }
    
    int     getY() const {
        return position.y;
    }
};

ostream&    operator<<(ostream& o, const Batman& b) {

    o << b.getX() << " " << b.getY() << endl;
    
    return o;    
}

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();

    // game loop
    Batman  B(X0, Y0, W, H);
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        for (auto to : bombDir)
            B.move(to);
        cout << B;
        
        // the location of the next window Batman should jump to.
    }
}
