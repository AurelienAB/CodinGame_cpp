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
    int N;
    cin >> N; cin.ignore();
    vector<int> P(N);
    cin >> P[0]; cin.ignore();
    for (int i = 1; i < N; i++) {
        cin >> P[i]; cin.ignore();
        int t = P[i];
        int j = i;
        while(j > 0 & P[j-1] > t) {
            P[j] = P[j-1];
            j = j-1;
        }
        P[j] = t;
    }
    
    for (int i = 0; i < N; i++) cerr << P[i] << endl;
    
    
    //std::sort(P.begin(), P.end());
    //cerr << std::sort(P) << endl;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    int res = 10000000;
    for (int i = 0; i < N; i++) {

        for (int j = i+1; j < N; j++) {
            int t = abs(P[i] - P[j]);
            // cerr << t << endl;
            res = min(t, res);
        }        
    }    

    cout << res << endl;
}