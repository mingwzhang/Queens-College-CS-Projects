#include <iostream>
#include <unordered_set>

using namespace std;

bool isUnique(const string& str) {
    // Assuming ASCII character set (8 bits)
    if (str.length() > 128) {
        return false;
    }

    unordered_set<char> charSet;

    for (char ch : str) {
        if (charSet.find(ch) != charSet.end()) {
            return false;  // Character is already in the set, not unique
        }
        charSet.insert(ch);
    }

    return true;  // All characters are unique
}

int main() {
    cout << boolalpha;  // to print 'true' or 'false' instead of '1' or '0'

    cout << isUnique("abcde") << endl;   // Output: true
    cout << isUnique("hello") << endl;   // Output: false
    cout << isUnique("world") << endl;   // Output: false

    return 0;
}

