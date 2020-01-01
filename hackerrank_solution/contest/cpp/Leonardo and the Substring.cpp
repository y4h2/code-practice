#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    while(n-- != 0)
    {
        string s;
        cin >> s;
        //cout << s <<endl;
        long long ans = 0;
        int b = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i != 0 && s[i] == s[i - 1])
                b = i;
            ans += i - b + 1;
        }
        
        cout << ans << endl;
    }
    return 0;
}
