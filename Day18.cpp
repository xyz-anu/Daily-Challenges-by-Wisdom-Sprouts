#include <iostream>
#include <cmath>
using namespace std;
 int countDivisors(int N) {
    int count = 0;
    int sqrtN = (int)sqrt(N);
     for (int i = 1; i <= sqrtN; i++) {
         if (N % i == 0) {
            if (i == N / i) {
                count += 1; // Perfect square divisor counted once
            } else {
                count += 2; // Pair of divisors
            }
        }
    }
    return count;
}
int main() {
    int N;
    cout << "Enter a positive integer N : ";
    cin >> N;

     if (N < 1 || N > 1000000000) {
        cout << "Input out of range " << endl;
        return 1;
    }
    int result = countDivisors(N);
    cout << "Total number of divisors: " << result << endl;
    return 0;
}
