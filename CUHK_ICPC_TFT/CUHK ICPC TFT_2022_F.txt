CUHK ICPC TFT-2022-F

#include<bits/stdc++.h>
using namespace std;

int main() {
    char c;
    string s;
    cin>>s;
    int a=0;
    bool z=1;
    for(int i=0; i<s.length(); i++) {
        c=s[i];
        if(c=='0') {
            z=1;
        } else {
            if(z==1) a++;
            z=0;
        }
    }
    cout<<a<<"\n";
    return 0;
}