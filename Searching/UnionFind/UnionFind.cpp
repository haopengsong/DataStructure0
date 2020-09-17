//
// Created by Haopeng Song on 2020/9/12.
//

#include "UnionFind.h"

UnionFind::UnionFind(int n) : id(n), count(n) {
    for (int i = 0; i < n; i++) {
        id[i] = i;
    }
}

int UnionFind::find(int p) {
    while (p != id[p]) {
        id[p] = id[id[p]]; // path compression
        p = id[p];
    }
    return p;
}

void UnionFind::Union(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) {
        return;
    }

    // combine two sets
    id[rootP] = rootQ;
    count--;
}
