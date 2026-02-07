#include <iostream>
using namespace std;
int main()
{
    int x=10;
    int &r=x;
    r=200;
    cout<<x;
    return 0;
}
