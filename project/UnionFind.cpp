#include "UnionFind.h"
#include <iostream>
#include "ResizingArray.h"
#include <iomanip>

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

void UnionFind::Union(int p, int q) {//Merge two components represented by elements p and q.
    int i = 0, j = 0;

    //Find roots for p and q
    i = Find(q);
    j = Find(p);

    if (i == j) return; //p and q share a root - i.e. they are connected
    
    if (sz[i] < sz[j]) { //merge weighted
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i; 
        sz[i] += sz[j];
    }
}
int UnionFind::Find(int p) { //Find the component identifier of element p. //Find the root
    int i = 0;
    //compress trees when nodes are touched
    for (i = p; i != id[i]; i = id[i])
        id[i] = id[id[i]]; 
    return id[i];
}

bool UnionFind::Connected(int p, int q) { //Check if elements p and q are in the same component.
    //If p and q share the same root they are in the same component
    return (Find(p) == Find(q));
}

int UnionFind::SizeOf(int p) { //Find the size of the component containing element p
    p = Find(p);
    return sz[p];
}

//Displays the id and sz arrays
void UnionFind::Print() {
    std::cout << "ID: {";
    for (int i = 0; i < N; i++) {
        std::cout << id[i];
        if (i < N - 1)
            std::cout << ", ";
    }
    std::cout << "}\n";    

    std::cout << "SZ: {";
    for (int i = 0; i < N; i++) {
        std::cout << sz[i];
        if (i < N - 1)
            std::cout << ", ";
    }
    std::cout << "}\n";
} 


void UnionFind::DFS(ResizingArray<node> &arr, int source, int depth) {
    for (int i = 0; i < N; i++) {
        if (source == i) //Dont add self
            continue;

        if (id[i] == source) {//Add children of source
            arr.Push({i, depth + 1});
            //Add grand children of I
            DFS(arr, i, depth + 1);
        }
    }
}

void UnionFind::PrintGraph() {
    ResizingArray<node> tree[N];
    
    //Determine roots
    for (int i = 0; i < N; i++) {
        if (id[i] != i) //if isnt root
            continue;

        tree[i].Push({i, 0});
        DFS(tree[i], i, 0);
    }
    
    std::cout << "\nGraph Visualization:\n";
    std::cout << "-------------------\n";

    for (int i = 0; i < N; i++) {
        int depth = 0;
        for (int j = 0; j < tree[i].getSize(); j++) {
            if (tree[i][j].depth > depth) { //if node is further down than we are currently printing
                std::cout << "-> ";
                depth = tree[i][j].depth;
            }
            std::cout << tree[i][j].id << ' ';
        }
        std::cout << '\n';
    }

    for (int i = 0; i < N; i++) {
        int depth = 0;
        for (int j = 0; j < tree[i].getSize(); j++) {
            if (tree[i][j].depth > depth) {
                std::cout << "-> ";
                depth = tree[i][j].depth;
            }
            std::cout << tree[i][j].id << ' ';
        }
        std::cout << '\n';
    }

    // for (int i = longestBranch - 1; i >= 0; i--) { //Each level of the tree
    // for (int i = 0; i < longestBranch; i++) { //Each level of the tree
    //     for (int j = 0; j < N; j++) { //Each branch
    //         if (tree[j].getSize() > i)
    //         {
    //             if (length[tree[j][i]] == i+1) {
    //                 std::cout << tree[j][i];
    //                 std::cout << '|' << length[tree[j][i]];
    //             } else {
    //                 std::cout << " |" << length[tree[j][i]];
    //             }
    //         } else 
    //             std::cout << "   ";
    //         std::cout << ' ';
    //     }
    //     std::cout << '\n';
    // }
}
