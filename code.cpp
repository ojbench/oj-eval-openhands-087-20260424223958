
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int D;
    long long n;
    if (!(std::cin >> D >> n)) return 0;

    // Find the position of the n-th ball
    long long current_n = n;
    int pos = 1;
    for (int i = 1; i < D; ++i) {
        if (current_n % 2 == 1) {
            pos = 2 * pos;
            current_n = (current_n + 1) / 2;
        } else {
            pos = 2 * pos + 1;
            current_n = current_n / 2;
        }
    }
    std::cout << pos << std::endl;

    // Find the state of all leaf nodes
    int num_nodes = 1 << D;
    std::vector<long long> count(num_nodes, 0);
    count[1] = n;
    for (int i = 1; i < (1 << (D - 1)); ++i) {
        count[2 * i] = (count[i] + 1) / 2;
        count[2 * i + 1] = count[i] / 2;
    }

    for (int i = (1 << (D - 1)); i < (1 << D); ++i) {
        std::cout << (count[i] % 2);
        if (i < (1 << D) - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
