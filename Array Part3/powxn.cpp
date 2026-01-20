#include<bits/stdc++.h>
using namespace std;
// Solution1 using stl pow function
class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};
// Solution2 using recursion
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion stack
class Solution1 {
    public:
    double f(double x, long n) {
        if(n == 0) return 1;
        if(n < 0) {
            f(1/x, -n);
        }
        if(n%2 == 0) {
            return f(x*x, n/2);
        }
        return x*f(x*x, (n-1)/2);
    } 
    double myPow(double x, int n) {
        return f(x, (long)n);
    }
};
int main() {
    Solution s;
    double x = 2.00000;
    int n = 10;
    cout << s.myPow(x, n) << endl;
    Solution1 s1;
    cout << s1.myPow(x, n) << endl;
    return 0;
}