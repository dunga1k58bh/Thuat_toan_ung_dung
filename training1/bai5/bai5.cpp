#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef unsigned long long big_num;

big_num sum_mod(big_num a[], int n, big_num d) {
    big_num du = 0;
    for (int i=0;i<n;i++) {
        big_num du_i = a[i]%d;
        du = (du + du_i)%d;
    }
    return du;

}
int main() {

    int n;
    cin>>n;
    big_num a[n];
    const big_num d=1000000007;

    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    cout<< sum_mod(a, n, d)<<endl;



    return 0;
}