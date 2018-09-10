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
 
struct defibrillator {
    string      name;
    long double longitude;
    long double latitude;
};

long double getDistance(const defibrillator& def, long double lon, long double lat) {

     long double    distance;
     
     long double    x = (lon - def.longitude) * cos(((lat + def.latitude) * 180) / (2 * M_PI));
     long double    y = lat - def.latitude;
     
     distance = sqrt(x*x + y*y) * 6371;
     
     return distance;
}

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    LON[LON.find_first_of(',')] = '.';
    LAT[LAT.find_first_of(',')] = '.';
    
    long double lon = stold(LON);
    long double lat = stold(LAT);
    
    vector<defibrillator>   defibrillators;
    
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        
        defibrillator   def;
        
        int     pos1 = DEFIB.find_first_of(';') + 1;
        int     pos2 = DEFIB.find_first_of(';', pos1);
        def.name = DEFIB.substr(pos1, pos2 - pos1);

        pos2 = DEFIB.find_last_of(';');
        DEFIB[pos2] = ' ';
        pos1 = DEFIB.find_last_of(';');
        
        string tmp = DEFIB.substr(pos1 + 1, pos2 - pos1);
        tmp[tmp.find_first_of(',')] = '.';
        def.longitude = stold(tmp);
        
        tmp =  DEFIB.substr(pos2 + 1);
        tmp[tmp.find_first_of(',')] = '.';
        def.latitude = stold(tmp);
        
        defibrillators.push_back(def);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    defibrillator  closest = *min_element(defibrillators.begin(), defibrillators.end(),
        [lon, lat](const defibrillator& a, const defibrillator& b){
            return getDistance(a, lon, lat) < getDistance(b, lon, lat);
        }
    );
    
    cout << closest.name << endl;
}
