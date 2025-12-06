CUHK CSE Contest-2017-A

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0; i<t; i++) {
        int a, b;
        cin>>a>>b;
        if(a%10==b%10||a/10%10==b/10%10||a/100==b/100||a%10==b/10%10||a/10%10==b/100||a/100==b%10||a%10==b/100||a/10%10==b%10||a/100==b/10%10) puts("Yes");
        else puts("No");
    }
    return 0;
}