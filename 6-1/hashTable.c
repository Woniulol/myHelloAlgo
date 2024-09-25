#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SIZE = 100;

typedef struct Pair {
    int key;
    char *val;
} Pair;

Pair *newPair(const int key, const char *val) {
    Pair *p = malloc(sizeof(Pair));
    p->key = key;
    p->val = malloc(strlen(val) + 1);
    strcpy(p->val, val);
    return p;
}

typedef struct ArrayHashMap {
    Pair *buckets[MAX_SIZE]
} ArrayHashMap;

ArrayHashMap *newArrayHashMap() {
    ArrayHashMap *hmap = malloc(sizeof(ArrayHashMap));
    for (int i = 0; i < MAX_SIZE; i++) {
        hmap->buckets[i] = NULL;
    }
    return hmap;
}

typedef struct MapSet {
    void *set;
    int len;
} MapSet;

void delArraryHashMap(ArrayHashMap *hmap) {
    for (int i = 0; i < MAX_SIZE; i++) {
        free(hmap->buckets[i]->val);
        free(hmap->buckets[i]);
    }
    free(hmap);
}

int hashFunc(int key) {
    return key % 100;
}

void put(ArrayHashMap *hmap, const int key, const char *val) {
    Pair *p = newPair(key, val);
    hmap->buckets[hashFunc(key)] = p;
}

void removeItem(ArrayHashMap *hmap, const int key) {
    int index = hashFunc(key);
    free(hmap->buckets[index]->val);
    free(hmap->buckets[index]);
    hmap->buckets[index] = NULL;
}

void pairSet(ArrayHashMap *hmap, Mapset *set) {

}



