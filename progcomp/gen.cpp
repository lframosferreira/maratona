#include <iostream>
#include <random>

int main() {
    // Seed for the random number generator
    std::random_device rd;
    std::mt19937_64 gen(rd());

    // Define the range of random numbers
    std::uniform_int_distribution<long long> dist((long long)1e7, (long long)1e10); // 1 to 10^10

    // Generate two random numbers
    long long num1 = dist(gen);
    long long num2 = dist(gen);

    // Ensure num1 is smaller than num2
    if (num1 > num2) {
        std::swap(num1, num2);
    }

    // Output the random numbers
    std::cout << num1 << " " << num2 << std::endl;

    return 0;
}

