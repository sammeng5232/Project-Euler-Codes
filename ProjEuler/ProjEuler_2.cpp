#include<bits/stdc++.h>
using namespace std;

int f (int n) {
    if (n==0) return 1;
    else if (n==1) return 1;
    else return f(n-1)+f(n-2);
}

int main () {
    int i=1;
    long long s=0;
    while (true) {
        if (f(i)>=4000000) {cout<<s<<"\n"; return 0;}
        if (f(i)%2==0) s+=f(i);
        i++;
    }
}