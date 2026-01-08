#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <string_or_number>";
        return 1;
    }

    string s = argv[1];
    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }

    return 0;
}
