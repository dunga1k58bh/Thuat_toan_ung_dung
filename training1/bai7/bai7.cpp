#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {

    int n;
    int m;
    cin>>n;
    int a[n];

    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    cin>>m;
    int b[m];
    for (int i=0; i<m; i++) {
        cin>>b[i];
    }

    bool check = true;
    for (int i=0;i<m;i++) {

        bool check_i = false;
        for (int j=0; j<n; j++) {

            if (b[i] == a[j]) {
                check_i = true;
                break;
            }
        }
        if (check_i == false) {
            check = false;
            break;
        }
    }

    if (check) cout<<1; else cout<<0;
}
