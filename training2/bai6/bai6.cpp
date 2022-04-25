#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    return a>b?a:b;
}
int main() {
    int n,b, ans = -1;

    cin>>n>>b;
    int a[n];
    int max_prefix[n];
    int max_suffix[n];

    for (int i = 0; i < n; i++) {
        max_prefix[i] = -1;
        max_suffix[i] = -1;
    }
    for (int i=0; i<n; i++) cin>>a[i];

    for  (int i=0; i<n; i++) {
        if (i == 0) {
            max_prefix[i] = a[i];
        }else {
            max_prefix[i] = max(max_prefix[i-1], a[i]);
        }
        if (i == n-1) {
            max_suffix[i] = a[n-1];
        } else {
            max_suffix[i] = max(max_suffix[i+1], a[i]);
        }
    }

    for (int i = 1; i < n-1; i++) {
        if (max_prefix[i-1] - a[i] >= b && max_suffix[i+1] - a[i] >=b ) {
            ans = max(ans, max_prefix[i-1] - a[i] + max_suffix[i+1] - a[i]);
        }
    }

    cout<<ans;
}