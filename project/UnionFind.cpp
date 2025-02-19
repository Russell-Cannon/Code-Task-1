#include "UnionFind.h"
#include "ResizingArray.h"
#include <iostream>

UnionFind::UnionFind() {}
// void UnionFind::Union(int p, int q); //Merge two components represented by elements p and q.
// int UnionFind::Find(int p); //Find the component identifier of element p.
// bool UnionFind::Connected(int p, int q); //Check if elements p and q are in the same component.

void UnionFind::AddNodes(int _n) {
    for (int i = n; i < n+_n; i++) { //start from old n, in case of repeated increase
        id.Push(i);
        sz.Push(1);
    }
    n += _n;
}

void UnionFind::PrintArrays() {
    std::cout << "ID: ";
    id.Print();
    std::cout << "SZ: ";
    sz.Print();
}