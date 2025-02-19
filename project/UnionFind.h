#ifndef UNIONFIND_H
#define UNIONFIND_H

#include "ResizingArray.h"

class UnionFind {
public:
    UnionFind();
    void Union(int p, int q); //Merge two components represented by elements p and q.
    int Find(int p); //Find the component identifier of element p.
    bool Connected(int p, int q); //Check if elements p and q are in the same component.
    void AddNodes(int _n);
    void PrintArrays();
    //print tree state (?)
private:
    ResizingArray<int> id;
    ResizingArray<int> sz;
    int n;
};

#endif