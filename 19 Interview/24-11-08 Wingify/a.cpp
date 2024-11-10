#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // vector<char> v = ['C','A','C','B','B','A'];
    string v = "CACBCBAAABB";
    int n = v.size();
    int i = 0, j = n-1, x = 0;
    while(i < j && x < j)
    {
        if(v[x] == 'A' && x > i)
        {
            swap(v[i], v[x]);
            x--;
            i++;
        }
        else if(v[x] == 'C')
        {
            swap(v[j], v[x]);
            j--;
        }
        else 
            x++;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}



