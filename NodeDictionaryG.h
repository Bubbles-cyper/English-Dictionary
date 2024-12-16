// NodeDictionaryG.h
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

template <typename K, typename V>
NodeDictionaryG<K, V>::NodeDictionaryG() : _uniqueKeys(0), _size(0) {
    header = new DNodeG<K, V>(Entry<K, V>(K(), V()));
    trailer = new DNodeG<K, V>(Entry<K, V>(K(), V()));
    header->next = trailer;
    trailer->prev = header;
}

template <typename K, typename V>
NodeDictionaryG<K, V>::~NodeDictionaryG() {
    while (!empty()) {
        removeNode(header->next);
    }
    delete header;
    delete trailer;
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::put(K key, V value) {
    DNodeG<K, V>* current = header->next;
    while (current != trailer) {
        if (current->entry.getK() == key) {
            current->entry.setV(value);
            return;
        }
        current = current->next;
    }
    DNodeG<K, V>* newNode = new DNodeG<K, V>(Entry<K, V>(key, value), trailer->prev, trailer);
    trailer->prev->next = newNode;
    trailer->prev = newNode;
    ++_uniqueKeys;
    ++_size;
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::erase(K key) {
    DNodeG<K, V>* current = header->next;
    while (current != trailer) {
        if (current->entry.getK() == key) {
            removeNode(current);
        }
        current = current->next;
    }
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::eraseFirst(K key) {
    DNodeG<K, V>* current = header->next;
    while (current != trailer) {
        if (current->entry.getK() == key) {
            removeNode(current);
            return;
        }
        current = current->next;
    }
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::removeNode(DNodeG<K, V>* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    --_size;
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::print(bool fromStart) const {
    if (fromStart) {
        DNodeG<K, V>* current = header->next;
        while (current != trailer) {
            std::cout << current->entry.getK() << ": " << current->entry.getV() << std::endl;
            current = current->next;
        }
    } else {
        DNodeG<K, V>* current = trailer->prev;
        while (current != header) {
            std::cout << current->entry.getK() << ": " << current->entry.getV() << std::endl;
            current = current->prev;
        }
    }
}
