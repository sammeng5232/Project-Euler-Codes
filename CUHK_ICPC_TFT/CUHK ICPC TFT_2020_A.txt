CUHK ICPC TFT-2020-A

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[10];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    sort(a, a+n);
    int numofplay=0;
    for(int i=0; i<n; i++) {
        if(a[i]<=i+2) {
            numofplay=i+2;
        }
    }
    if(numofplay<4) puts("0");
    else if(numofplay==11) puts("10");
    else cout<<numofplay<<"\n";
    return 0;
}