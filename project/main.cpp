#include "UnionFind.h"
#include <iostream>

int main() {
    UnionFind unionFind;

    std::cout << "Enter value of N: ";
    int n = 0;
    std::cin >> n;
    unionFind.AddNodes(n);
    unionFind.PrintArrays();

    return 0;
}
