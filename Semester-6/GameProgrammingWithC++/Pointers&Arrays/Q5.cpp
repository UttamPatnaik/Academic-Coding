#include <iostream>
using namespace std;

void swap(int *x,int *y,int *z) {
    int temp=*x;
    *x=*y;
    *y=*z;
    *z=temp;
}

int main() {
    int m,n,o;
    cin>>m;
    cin>>n;
    cin>>o;
    swap(&m,&n,&o);
    cout << "Values after Swapping" << m << n << o;
    return 0;
}
