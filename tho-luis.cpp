#include <iostream>
using namespace std;

long long total[1000];

int TongSoThoSau1Thang(long long& a, long long& a0, long long& a1, long long& a2) {
    long long result = 3*a + a1 + a2 + a0;
    a += a2;
    a2 = a1;
    a1 = a0;
    a0 = 2*a;
    return result;
}

int main() {
    int n;
    cout << " Nhap so thang: ";
    cin >> n;
    for (int i = 0; )
}

