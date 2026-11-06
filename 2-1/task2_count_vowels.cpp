// 2-1 任务二：统计元音字母
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int countVowels(const char *p) {
    int count = 0;
    while (*p != '\0') {
        char ch = static_cast<char>(tolower(static_cast<unsigned char>(*p)));
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++count;
        }
        ++p;
    }
    return count;
}

int main() {
    string line;
    getline(cin, line);
    cout << "Number of vowels: " << countVowels(line.c_str()) << endl;
    return 0;
}
