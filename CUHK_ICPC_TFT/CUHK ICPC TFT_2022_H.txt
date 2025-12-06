CUHK ICPC TFT-2022-H

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    long long a, b, c, d, ans;
    for(int i=0; i<t; i++) {
        cin>>b>>d;
        /* TLE
        ans=0;
        for(a=1; a<=b*b/d; a++) {
            if((b*b-a*d)/b*b==b*b-a*d && b*b>a*d) {ans++; a+=b/__gcd(b,d)-1;}
        }
        */
        if(b*__gcd(b, d)/d*d==b*__gcd(b, d)){//b gcd(b,d)/d is an integer
            cout<<b*__gcd(b, d)/d-1<<"\n";
        } else cout<<b*__gcd(b, d)/d<<"\n";
    }
    return 0;
}

//We need ad/b+c=b, i.e. ad+bc=b^2
//Solutions: (a, c)=(0, b), (b/gcd(b,d), b-d/gcd(b,d)), ..., (bk/gcd(b,d), b-dk/gcd(b,d))
//Thus the answer is the largest value of integer k such that b-dk/gcd(b,d)>0, i.e. k<b gcd(b,d)/d