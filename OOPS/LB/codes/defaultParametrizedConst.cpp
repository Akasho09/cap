// 1️⃣ Constructor with Default Argument
    // This constructor:
    // Acts as a default constructor
// Also acts as a parameterized constructor
#include <iostream>
using namespace std;

class GfG {
    public:
    int val;
    
    GfG(int x = 22) {
        this->val = x;
    }
};

int main() {
    GfG gfg;
    cout << gfg.val;
    return 0;
}