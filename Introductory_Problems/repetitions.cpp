#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    char lastSeen = '#';
    int count = 0;
    int maxCount = 0;
    for(char c: s){
        if(c != lastSeen){
            lastSeen = c;
            count = 1;
        } else {
            count++;
        }
        maxCount = max(maxCount, count);
    }
    cout<<maxCount;
}