#include <iostream>
using namespace std;

void swap(int *x,int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main() {
    int m,n;
    cin>>m;
    cin>>n;
    swap(&m,&n);
    cout << "Values after Swapping" << m << n << endl;
    return 0;
}
