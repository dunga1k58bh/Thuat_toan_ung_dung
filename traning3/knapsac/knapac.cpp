#include <bits/stdc++.h>

using namespace std;
int n, b, res = 0, suma =0, sumc=0;
int a[51], c[51], s[51];
bool check(int i, int k){
    if (suma + i*a[k]> b) return false;
    return true;
}
void solution() {
    if (sumc >res) res=sumc;
}

void input() {
    cin>>n>>b;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
    }
}

void Try(int k) {
    for(int i=0;i<=1;i++) {
        if (check(i,k)) {
            suma+= i*a[k];
            sumc+= i*c[k];
            if (k==n) solution();
            else Try(k+1);
            suma-= i*a[k];
            sumc-= i*c[k];
        }
    }
}

int main()
{
    input();
    Try(1);
    cout<<res;
    return 0;
}
