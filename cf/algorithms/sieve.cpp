// Check if the number is prime
bool prime[1e5 + 100];

void sieve() {
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i + i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

// TC: O(nloglogn)
// SC: O(n)