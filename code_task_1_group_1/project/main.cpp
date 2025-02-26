#include "UnionFind.h"
#include <cctype>
#include <iostream>

int main() {
    UnionFind unionFind;
    unionFind.Print();

    int a, b;
    char c;

    while (true) {
        std::cout << "Operation types:\n";
        std::cout << "\t U. Union (a, b).\n";
        std::cout << "\t Q. Query (a).\n";
        std::cout << "\t E. End program.\n";
        std::cout << "Enter choice: ";

        std::cin >> c;
        c = toupper(c);
        
        switch (c) {
            case 'U':
                std::cout << "a: ";
                std::cin >> a;
                std::cout << "b: ";
                std::cin >> b;
                unionFind.Union(a, b);
                unionFind.Print();
            break;

            case 'Q':
                std::cout << "a: ";
                std::cin >> a;
                std::cout << "size of " << a << " = " << unionFind.SizeOf(a) << '\n';
            break;

            case 'E':
                std::cout << "Shutting down...\n";
            return 0;
            break;

            default:
                std::cout << "Invalid choice!\n";
            break;
        }

        std::cout << '\n';
    }

    return 0;
}