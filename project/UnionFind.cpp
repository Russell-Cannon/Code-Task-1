#include "UnionFind.h"
#include <iostream>

UnionFind::UnionFind() {
    id = new int[N];
    sz = new int[N];

    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

UnionFind::~UnionFind() {
    delete [] id;
    delete [] sz;
}

// void UnionFind::Union(int p, int q); //Merge two components represented by elements p and q.
// int UnionFind::Find(int p); //Find the component identifier of element p. //Find the root
// bool UnionFind::Connected(int p, int q); //Check if elements p and q are in the same component.
// void UnionFind::Print();
