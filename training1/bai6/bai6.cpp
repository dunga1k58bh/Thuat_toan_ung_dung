#include<bits/stdc++.h>
#include<string>

using namespace std;

int main(){

    int n;
    cin>>n;
    string s[n];
    for (int i=0;i<n;i++) {
        cin>>s[i];
    }

    for (int i=0;i<n;i++) {
        int len = s[i].length();
        if (len >10) {
            cout<<s[i][0]<<len - 2<<s[i][len-1]<<endl;
            continue;
        }
        cout<<s[i]<<endl;
    }
    return 0;
}