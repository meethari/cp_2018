#include <iostream>
#include <vector>
#define NUM_COUNT 16

using namespace std;

int main() {
    int n; // number of lines
    cin >> n;

    // learn how to declare a vector array correctly
    int inputs[n][16];
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < NUM_COUNT; j++)
            cin >> inputs[i][j];
    
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < NUM_COUNT; j++)
            cout << inputs[i][j] << " ";
        cout << endl;
    }
    */

   // To check every subsequence to see whether it's an island

   // brute force

   for (int i = 0; i < n; i++) {
       // TODO: implement the stuff up here
       // finally
       cout << inputs[i][0] << " " << islandCount << endl;
   }

}