#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, a, junk; 
    cin >> n;

    vector <vector <int> > v1(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        cin >> junk >> a;
        vector<int> entry(3, 0); 
        entry[0] = a * (a+1)/2;
        entry[1] = (a * a);
        entry[2] = (a * (a+1));
        v1[i] = entry;
    }

    for (int i = 0; i < n; i++) {
        cout << i+1 << " " << v1[i][0] << " " << v1[i][1] << " " << v1[i][2] << endl;
    }    
    return 0;
}