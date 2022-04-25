#include <bits/stdc++.h>
#include <vector>

using namespace std;

// typedef unsigned long long int;
vector<int> input() {
  char c;
  vector<int> cl;
  std::string line;
  std::getline(cin, line);
  std::istringstream iss(line);
  while ( iss >> c) {
    cl.push_back(c - '0');
  }
  return cl;
}

int main() {
    while (true) {

        vector<int> a;
        a = input();
        if (a.size() == 1 && a[0] ==0) return 0;

        int n = a.size();
        int S = -1;
        int left =0, right=0;
        int min = 99999999;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (right - left <= 0) continue;
                int S_temp = (right - left +1)*min;
                if (S_temp > S) S = S_temp;
                left = i + 1;
                min = 99999999;
            }
            right = i;
            if (a[i] < min) {
                min = a[i];
            }
        }

        cout<<S;
        break;
    }
    return 0;
}