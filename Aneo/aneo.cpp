#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Reading inputs:
    int speed; // speed limit
    int lightCount; // number of lights    
    
    cin >> speed; cin.ignore();
    cin >> lightCount; cin.ignore();
    
    int distance[lightCount]; // all distance to test
    int duration[lightCount]; // all duration for th lights
    
    for (int i = 0; i < lightCount; i++) {
        cin >> distance[i] >> duration[i]; cin.ignore();
    }
        
    int si = speed; // Test speed.
    bool all_green = false; // Test: are all lights green with this speed ?
    double conv = 3.6; // h/s to km/h

    // Looking for optimum speed:
    // In each loop we test if we can go through all light on green using test speed si.
    // (Starting from speed limit and decreasing si.)
    
    while(si > 0 & all_green == false) {
     int j = 0;
     int time_to_light = 0;
     int test = 0;
     
     while (j < lightCount & int(test)%2 == 0) {
      time_to_light = (distance[j] * conv) / si;
      test = time_to_light / duration[j]; // If test is even then the light is green.
      j++;
     }
     
     if(j == lightCount & int(test)%2 == 0) {
         all_green = true;
     }
     
     si--;
     
    }

    // Output:
    cout << si+1 << endl;
}