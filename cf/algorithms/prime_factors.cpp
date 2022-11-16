// Simple Prime Factor Calculation
// TC: O(sqrt(n) * log(n))

void calculatePrimeFactors(int n) {
    set<int> primes;
    while (n % 2 == 0) {
        primes.insert(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            primes.insert(i);
            n /= i;
        }
    }

    for (auto el : primes) {
        cout << el << " ";
    }
    cout << endl;
}
