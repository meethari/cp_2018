#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int find_sum(int);
int is_palindrome(int, int);
int recursive_check(int, int);
int find_lower_bound(int num, int length);

int main() {

    string s;
    cin >> s;

    int length = s.length();
    int num = 0;
    for (int i = 0; i < length; i++) {
        num += int(s[(length - 1) - i] - '0') * pow(10, i);
    }

    int lower_bound = find_lower_bound(num, length);

    cout << lower_bound << endl;
    
    for (int i = 0; i <= lower_bound; i++) {
        
        int limit = pow(10, length);

        for (int j = 0; j < pow(10, length); j++) {
            
            if (find_sum(j) != i)
                continue;
            
            int candidate = (num + j) % limit;
            if (is_palindrome(candidate, length)) {
                cout << i << endl;
                return 0;
            }

        }
    }

    cout << "Wtf no palindrome";
    return 0;
}

int find_sum(int a) {
    int sum = 0;
    while (a != 0) {
        sum += a % 10;
        a = a / 10;
    }
    return sum;
}

int is_palindrome(int candidate, int length) {
    
    vector<int> v1 (length, 0);

    for (int i = length - 1; i >= 0; i--) {

        v1[i] = candidate % 10;
        candidate = candidate / 10;

    }

    for (int i = 1; i <= (length + 1) / 2; i++) {
        if (v1[i - 1] != v1[(length - 1) - (i - 1)])
            return 0;
    }
    return 1;
}

int find_lower_bound(int num, int length) {
    int lower_bound = 0;

    int base_1 = 1, base_2 = pow(10, length-1);
    while (base_2 > base_1) {

        int a = (num / base_1) % 10, b = (num / base_2) % 10;
        lower_bound += abs(a-b);
        base_1 *= 10;
        base_2 /= 10;
    }

    return lower_bound;
}