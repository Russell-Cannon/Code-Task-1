//Russell R Cannon 2/17/25
#include <iostream>
#define N 10000

int main() {
    int i, j, p, q, n;

    int* id = new int[N]; //Use dynamic arrays to move arrays from stack to heap. When N = 10 ^ 6, we get a stack overflow
    int* sz = new int[N]; 

    srand(time(NULL));

    //initialize
    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    //merge N times
    for (n = 0; n < N; n++) { 
        p = std::rand()%N; 
        q = std::rand()%N; 

        //compress trees when nodes are touched
        for (i = p; i != id[i]; i = id[i])
            id[i] = id[id[i]]; 
        for (j = q; j != id[j]; j = id[j])
            id[j] = id[id[j]];

        if (i == j) continue;
        
        if (sz[i] < sz[j]) { //merge weighted
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i; 
            sz[i] += sz[j];
        }
    }

    delete [] id;
    delete [] sz;

    return 0;
}
