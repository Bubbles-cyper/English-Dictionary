// DNodeG.h
#ifndef DNODEG_H
#define DNODEG_H

#include "Entry.h"

template <typename K, typename V>
struct DNodeG {
    Entry<K, V> entry;
    DNodeG* prev;
    DNodeG* next;

    DNodeG(Entry<K, V> e, DNodeG* p = nullptr, DNodeG* n = nullptr) : entry(e), prev(p), next(n) {}
};

#endif // DNODEG_H
