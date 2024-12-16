// NodeDictionaryG.h
#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include "DNodeG.h"
#include <iostream>

template <typename K, typename V>
class NodeDictionaryG {
private:
    int _uniqueKeys;
    int _size;
    DNodeG<K, V>* header;
    DNodeG<K, V>* trailer;

    void removeNode(DNodeG<K, V>* node);

public:
    NodeDictionaryG();
    virtual ~NodeDictionaryG();

    int size() const { return _size; }
    int uniqueKeys() const { return _uniqueKeys; }
    bool empty() const { return _size == 0; }

    void put(K key, V value);
    void erase(K key);
    void eraseFirst(K key);
    void print(bool fromStart) const;
};

#endif // NODEDICTIONARYG_H
