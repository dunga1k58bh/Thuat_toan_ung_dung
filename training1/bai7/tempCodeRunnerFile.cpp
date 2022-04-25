#include <bits/stdc++.h>
#include <string>
using namespace std;



int count_press_times(string s){
    int count = 0;
    int len = s.length();
    for (int i=0;i<len;i++){
        if (s[i] <= 'o') {
            int press_times = (s[i] - 'a' + 1) % 3;
            if (press_times == 0) press_times =3;

            count+=press_times;
        } else if (s[i] == ' ') {
            count++;
        } else if ('p' <= s[i] && s[i] <= 's') {
            int press_times = (s[i] - 'p'+1) % 4;
            if (press_times == 0) press_times =4;

            count+=press_times;
        }

        else if ('w' <= s[i] && s[i] <= 'z') {
            int press_times = (s[i] - 'w'+1) % 4;
            if (press_times == 0) press_times =4;

            count+=press_times;
        }
        else if ('t' <= s[i] && s[i] <= 'v') {
            int press_times = (s[i] - 't'+1) % 3;
            if (press_times == 0) press_times =3;

            count+=press_times;
        }
    }

    return count;
}

int main() {

    int n;
    cin>>n;
    string s[n];
    getline(cin, s[0]);
    for (int i=0; i<n; i++) {
        getline(cin, s[i]);
    }

    for (int i=0; i<n; i++) {
        cout<<"Case #"<<i+1<<": "<<count_press_times(s[i]);
    }
}
