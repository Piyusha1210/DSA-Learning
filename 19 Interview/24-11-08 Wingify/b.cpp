#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string v = "01010";
    int n = v.size();
    int req = n-1;
    int ans = 0;
    for(int i = n-1; i > = 0; i--)    
    {
        if(v[i] == '1')
        {
            ans += req - i;
            req--;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}