#ifndef UNIONFIND_H
#define UNIONFIND_H
#define N 11

class UnionFind {
public:
    UnionFind();
    ~UnionFind();
    void Union(int p, int q); //Merge two components represented by elements p and q.
    int Find(int p); //Find the component identifier of element p.
    bool Connected(int p, int q); //Check if elements p and q are in the same component.
    void Print(); //Displays the id and sz arrays
    
private:
    int* id;
    int* sz;
};

#endif