#include <bits/stdc++.h>

using namespace std;
int n,m,res,s=0,edges=1;
int d[30][30], path[30];
bool visited[30];
int min_path = 0;
int med_path = 0;
priority_queue<int, vector<int>, greater<int> > edges_queue;

void input() {

    cin>>n>>m;
    int from, to, weight;
    for (int i=0; i<m; i++) {
        cin>>from>>to>>weight;
        d[from][to] = weight;
        edges_queue.push(weight);
    }

    for (int i=0;i<n;i++) {
        min_path += edges_queue.top();
        edges_queue.pop();
    }
    med_path = min_path/n +1;
}
bool check(int v,int k){
    if (visited[v] == true) return false;
    int temp = d[path[k-1]][v];
    if (temp == 0) return false;
    if (s + temp + (n-k)*(med_path) > res) return false;
    if (v==1  && edges < n) return false;
    return true;
}

void solution() {
    if (s < res) res = s;
}
void Try(int k) {
    for (int v=n; v>=1; v--) {
        if (check(v,k)) {
            path[k] = v;
            visited[v] = true;
            int temp = d[path[k-1]][v];
            s+=temp;
            edges++;

            if (k == n+1) solution();
            else Try(k+1);

            edges--;
            s-=temp;
            visited[v] = false;
        }
    }
}


int main() {
    for (int i=1;i<=n;i++) {
        for (int j=1;i<=n;j++)
            d[i][j] = 0;
        visited[i] = false;
        path[i] = 0;
    }
    res = INT_MAX;
    path[1] = 1;
    input();
    Try(2);
    cout<<res;
}