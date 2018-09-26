#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    string s;
    cin >> s;

    int length = s.length();
    int num = 0;
    for (int i = 0; i < length; i++) {
        num += int(s[(length - 1) - i] - '0') * pow(10, i);
    }

    cout << length << " " << num;

    return 0;
}