int bs(int k) {
    int l = 0, r = n - 1, p;
    while (l <= r) {
        p = (l + r) >> 1;
        if (a[p] == k)
            return p;
        if (a[p] < k)
            l = p + 1;
        else
            r = p - 1;
    }
    return -1;
}

/// algo
bool binary_search( ForwardIt first, ForwardIt last, const T &value,
                    Compare comp );
#include <iostream>
#include <algorithm>
#include <vector>
int main() {
    std::vector<int> haystack {1, 3, 4, 5, 9};
    std::vector<int> needles {1, 2, 3};

    for (auto needle : needles) {
        std::cout << "Searching for " << needle << '\n';
        if (std::binary_search(haystack.begin(), haystack.end(), needle)) {
            std::cout << "Found " << needle << '\n';
        } else {
            std::cout << "no dice!\n";
        }
    }
}

/// std
#include <cstdlib>
#include <iostream>
int compare(const void *ap, const void *bp) {
    const int *a = (int *) ap;
    const int *b = (int *) bp;
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}
int main(int argc, char **argv) {
    const int ARR_SIZE = 8;
    int arr[ARR_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int key1 = 4;
    int *p1 = (int *) std::bsearch(&key1, arr, ARR_SIZE, sizeof(arr[0]), compare);
    if (p1)
        std::cout << "value " << key1 << " found at position " << (p1 - arr) << '\n';
    else
        std::cout << "value " << key1 << " not found\n";

    int key2 = 9;
    int *p2 = (int *) std::bsearch(&key2, arr, ARR_SIZE, sizeof(arr[0]), compare);
    if (p2)
        std::cout << "value " << key2 << " found at position " << (p2 - arr) << '\n';
    else
        std::cout << "value " << key2 << " not found\n";
}