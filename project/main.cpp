#include "UnionFind.h"
#include <iostream>

int main() {
    UnionFind unionFind;
    unionFind.Print();

    int p, q;

    while (true) { 
        std::cout << "P: ";
        std::cin >> p;
        std::cout << "Q: ";
        std::cin >> q;
        std::cout << "P's root: " << unionFind.Find(p) << '\n';
        std::cout << "P and Q are connected: " << unionFind.Connected(p, q) << '\n';
        unionFind.Union(p, q);
        unionFind.Print();
    }

    return 0;
}
