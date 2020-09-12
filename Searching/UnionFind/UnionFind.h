//
// Created by Haopeng Song on 2020/9/12.
//

#ifndef FIRST_PROJECT_UNIONFIND_H
#define FIRST_PROJECT_UNIONFIND_H


#include <vector>

class UnionFind {
private:
    int count; // initial numbers of group
    std::vector<int> id;
public:
    UnionFind(int n);

    // locates the node's root
    int find(int p);

    // combine two sets into one
    void Union(int p, int q);
};
#endif //FIRST_PROJECT_UNIONFIND_H
