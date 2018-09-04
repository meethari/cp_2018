#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> v1;
    string line;
    while (std::getline(std::cin, line))
    {
        v1.push_back(line);
    }

    /*
    * In our analysis, (before this, check if str_len % k == 0)
    * (potential optimisation - only check for values of k which are prime divisors
    * of str_len)
    * let's begin with the hypothesis that k = 1, check this by determining the
    * first substring and comparing it to other substrings of length k
    */
    for (int sentence_count = v1.size(), n = 0; n < sentence_count; n++) {
        string s1 (v1[n])
        for (int k = 1; k <= s1.size(); k++) {
            if (s1.size() % k != 0) {
                continue;
            }
            
        }
    }
}