#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef unsigned long long big_num;

unsigned long long bigmod(big_num a, big_num b, big_num d, big_num du_const) {
    if (b==1) return du_const;
    big_num du;

    if (b%2==1){
        du = (((bigmod(a, b/2, d, du_const)*bigmod(a, b/2, d, du_const))%d)*du_const)%d;
    } else {
        du = (bigmod(a, b/2, d, du_const)*bigmod(a, b/2, d, du_const))%d;
    }
    return du;
}


int main() {

    big_num a, b;
    const big_num d=1000000007;

    cin>>a>>b;

    big_num du_const = a%d;
    cout<< bigmod(a, b, d, du_const);


    return 0;
}