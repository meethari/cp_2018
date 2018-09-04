#include <iostream>
#include <vector>
#define NUM_COUNT 15

using namespace std;

int main() {
    int n; // number of lines
    cin >> n;

    vector<vector<int>> numbers;

    for (int i = 0; i < n; i++) {
      vector<int> v1;
      for (int j = 0; j < NUM_COUNT + 1; j++) {

        int input;
        cin >> input;

        if (j == 0) {
          continue;
        }

        v1.push_back(input);
      }
      numbers.push_back(v1);
    }

   for (int i = 0; i < n; i++) {
       int island_count = 0;

       for (int j = 1; j < NUM_COUNT; j++) {
         if (numbers[i][j-1] - numbers[i][j] == -1) {
           island_count++;
         }
       }

       cout << i + 1 << " " << island_count << endl;
   }

}
