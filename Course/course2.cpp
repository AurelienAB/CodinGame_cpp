#include <iostream>
#include <string>
#include <set>

using namespace std;

// Print function for multiset in case of need in debugging
void print(multiset<int> const &s) {
    for (multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
        cerr << *it << ' ';
    }
    cerr << endl;
}


// Reading input data AND sorting them at the same time.
int main()
{
    int N; // number of horses
    cin >> N; cin.ignore();
    multiset<int> power; // horses' power
    // std::multiset allows to have duplicate values (on the contrary of set)

	for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        power.insert(t);
  }
  
 // print(power);
    
    // Looking for smallest difference between two power:
    // (powers are already sorted so we just need to compare values two by two)
    int diff_min = 10000000;
	for (multiset<int>::iterator it=power.begin(); it!=power.end();) {
		int first = *it;
		int second = *(++it);
        diff_min = min(abs(second-first), diff_min);
        // cerr << second << ' ' << first << ' ' << abs(second-first) << endl;
    }    

// Results
    cout << diff_min << endl;
    
    return 0;
}