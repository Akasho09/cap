#include <iostream>
using namespace std ;

// m+n-2 C m-1 or n-1
int uniquePaths(int m, int n) {
    long long res = 1;
    int N = m + n - 2;
    int r = min(m - 1, n - 1);

    for (int i = 1; i <= r; i++) {
        res = res * (N - r + i) / i;
    }

    return (int)res;
}

class Solution {
public:
    vector<vector<int>> dp; 

    int helper(int m, int n) {
        if (m <= 1 || n <= 1) return 1;
        if (dp[m][n] != -1) return dp[m][n];

        dp[m][n] = helper(m-1, n) + helper(m, n-1);
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        dp.assign(m+1, vector<int>(n+1, -1));
        return helper(m, n);
    }
};
