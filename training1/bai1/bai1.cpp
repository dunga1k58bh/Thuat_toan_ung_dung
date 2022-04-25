#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    if (a.size() < b.size()) {
        a.swap(b);
    }
    string c;
    int m=a.size()-1, n=b.size()-1;
    int k = a.size();
    bool remember = false;
    while (n>=0) {
        int du = remember?1:0;
        int temp = a[m] + b[n] - 96 + du;

        if (temp>=10) {
            temp = temp - 10;
            remember = true;
        } else {
            remember = false;
        }
        char c_temp = (char)(temp+48);
        c.push_back(c_temp);
        m--;
        n--;
        k--;
    }
    if (remember == true) c.push_back('1');
    for (int i = m;i>=0;i--) {
        c.push_back(a[i]);
    }
    reverse(c.begin(), c.end());
    cout<<c<<endl;
    return 0;
}
