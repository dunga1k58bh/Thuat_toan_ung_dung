#include<bits/stdc++.h>
#include<string>

using namespace std;

int main() {
    unsigned long long a, b;
    const unsigned long long d=1000000007;

    cin>>a>>b;

    unsigned long long du_a = a % d;
    unsigned long long du_b = b % d;

    unsigned long long sum_du = du_a + du_b;
    if (sum_du < d) {
        cout<<sum_du<<endl;
        return 0;
    }

    unsigned long long du = sum_du % d;

    cout<<du;

    return 0;
}