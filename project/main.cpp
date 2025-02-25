#include "UnionFind.h"
#include <iostream>

int main() {
    UnionFind unionFind;
    unionFind.Print();
    unionFind.PrintGraph();

    int p, q;
    char c;

    while (true) {
        // std::cout << "U (union) / Q (query): ";
        // std::cin >> c;
        std::cout << "P: ";
        std::cin >> p;
        // if (toupper(c) == 'U') {
            std::cout << "Q: ";
            std::cin >> q;
            unionFind.Union(p, q);
            unionFind.Print();
            unionFind.PrintGraph();
        // } else {
        //     std::cout << "size of " << p << " = " << unionFind.SizeOf(p) << '\n';
        // }

    }

    return 0;
}
