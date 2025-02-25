#ifndef UNIONFIND_H
#define UNIONFIND_H
#define N 11

#include "ResizingArray.h"

struct node{
    int id;
    int depth;
};


class UnionFind {
public:
    UnionFind();
    ~UnionFind();
    void Union(int p, int q); //Merge two components represented by elements p and q.
    int Find(int p); //Find the component identifier of element p.
    bool Connected(int p, int q); //Check if elements p and q are in the same component.
    int SizeOf(int p); //Query operation - Find the size of the component containing element p
    void Print(); //Displays the id and sz arrays
    void PrintGraph();
    void DFS(ResizingArray<node> &arr, int source, int depth);
        
private:
    int* id;
    int* sz;
};

#endif