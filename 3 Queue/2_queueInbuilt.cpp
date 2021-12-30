#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> qu;
    qu.push(1);
    qu.push(4);
    qu.push(6);
    cout << qu.front() << " " << qu.back() << endl;
    qu.pop();
    qu.push(8);
    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
    return 0;
}