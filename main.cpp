// Compile and run with: g++ main.cpp -o main && time ./main
#include <chrono>
#include <iostream>
#include <vector>

int count_primes(int up_to) {
    int count = 0;
    bool is_prime;
    for (int number = 2; number <= up_to; number++) {
        bool is_prime = true;
        for (int divisor = 2; divisor < number; divisor++) {
            if (number % divisor == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            count += 1;
        }
    }
    return count;
}

int main() {
    std::vector<int> numbers = {10000, 20000, 30000, 40000};
    double total_runtime = 0.0;
    for (auto& number: numbers) {
        auto start = std::chrono::steady_clock::now();
        auto result = count_primes(number);
        auto end = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
        total_runtime += elapsed_seconds;
        std::cout << result << "(" << elapsed_seconds << "sec) ";
    }
    std::cout << std::endl;
    std::cout << "Total runtime: " << total_runtime << "sec" << std::endl;
    return 0;
}
