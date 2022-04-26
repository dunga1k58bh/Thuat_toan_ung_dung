#include <bits/stdc++.h>

using namespace std;

int n, K, Q, edges;
int d[15], c[15][15], load[6], X[15], Y[15], s, res;
bool visited[13];
int min_c = INT_MAX;

void input() {
    cin>>n>>K>>Q;
    for (int i=1; i<=n; i++) {
        cin>>d[i];
    }
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            cin>>c[i][j];
            if (c[i][j] < min_c ) min_c = c[i][j];
        }
    }
}
bool checkX(int u,int v, int k){
    if (visited[u] && u) return false;
    if (u == 0 && k==K && edges != n+K-1) return false;
    if (load[k] + d[u] > Q) return false;
    // if (s+ (n+K-edges)*min_c > res) return false;
    return true;
}

bool checkY(int v, int k){
    if (visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    // if (s+ (n+K-edges)*min_c > res) return false;
    return true;
}

void solution() {
    // cout<<"Solving..."<<endl;
    // for (int i=1; i<=K; i++) {
    //     cout<<"xe "<<i<<": ";
    //     int v = Y[i];
    //     while (v) {
    //         cout<<v<<"-";
    //         v=X[v];
    //     }
    //     cout<<endl;
    // }
    if (s < res) res=s;
}

void TryX(int v, int k) {
    for (int u=0; u<=n; u++) {
        if (checkX(u,v,k)) {
            visited[u] = true;
            X[v] = u;
            edges++;
            load[k] += d[u];
            s+=c[v][u];
            if (u==0) {
                if (k==K) {
                    if (edges = n + K) solution();
                } else {
                    TryX(Y[k+1], k+1);
                }
            } else {
                TryX(u, k);
            }
            s-=c[v][u];
            load[k]-=d[u];
            edges--;
            visited[u] = false;
        }
    }
}
void TryY(int k) {
    for (int v = Y[k-1] + 1 ; v <= n; v++) {
        if (checkY(v, k)) {
            Y[k] = v;
            edges++;
            visited[v] = true;
            load[k] += d[v];
            s += c[0][v];
            if (k == K) {
                TryX(Y[1],1);
            } else {
                TryY(k+1);
            }
            s -= c[0][v];
            load[k] -= d[v];
            visited[v] = false;
            edges--;

        }
    }
}


int main() {
    input();
    edges = 0;
    for (int i = 0; i <=n; i++) {
        visited[i] = false;
        X[i] = 0;
        Y[i] = 0;
    }
    for (int i= 1; i <= K; i++) {
        load[i] = 0;
    }
    res = INT_MAX;
    s = 0;
    TryY(1);
    cout<<res;
}