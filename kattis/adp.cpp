#include <iostream>
#include <vector>
// #include <utility>

using namespace std;

int main() {
    vector<long long> out;

    pair<long long, long long> p;

    while (cin >> p.first >> p.second) {
        if (p.first > p.second) {
            out.push_back(p.first - p.second);
        }
        else {
            out.push_back(p.second - p.first);
        }
    }

    int len = out.size();

    for (int i = 0; i < len; i++) {
        cout << out[i] << endl;
    }

    return 0;
}