#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}
int main() {
    long long N, M;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter M: ";
    cin >> M;
    cout << "LCM of " << N << " and " << M << " is " << lcm(N, M) << endl;
    return 0;
}
