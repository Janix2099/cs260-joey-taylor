// DSU.h
#pragma once 
#include <vector>

class DSU {
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DSU(int n) : parent(n, -1), rank(n, 1) {}

    int find(int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};
