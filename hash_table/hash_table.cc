#include <bits/stdc++.h>
using namespace std;

const int ksz = 1'000'000;
const int kmod = 999'997;

struct HashTable {
    struct Node {
        int key, value, next;
    } data[ksz];
    int head[kmod], size;
    int func(int key) {
        return key % kmod;
    }
    int get(int key) {
        for (int pos = head[func(key)]; pos; pos = data[pos].next) {
            if (data[pos].key == key) {
                return data[pos].value;
            }
        }
        return -1;
    }
    int modify(int key, int repvalue) {
        for (int pos = head[func(key)]; pos; pos = data[pos].next) {
            if (data[pos].key == key) {
                return data[pos].value = repvalue;
            }
        }
    }
    // head insertion
    int add(int key, int value) {
        if (get(key) != -1) return -1;
        data[++size] = (Node){key, value, head[func(key)]};
        head[func(key)] = size;
        return value;
    }
};

