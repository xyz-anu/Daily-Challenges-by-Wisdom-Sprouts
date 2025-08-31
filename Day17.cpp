#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFactors(int N) {
    vector<int> factors;
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }
     for (int i = 3; 1LL * i * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    if (N > 2) {
        factors.push_back(N);
    }
    return factors;
}
int main() {
    int N;
    cin >> N;
    vector<int> result = primeFactors(N);
    for (int p : result) {
        cout << p << " ";
    }
    cout << endl;
    return 0;
}
