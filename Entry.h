// Entry.h
#ifndef ENTRY_H
#define ENTRY_H

template <typename K, typename V>
class Entry {
private:
    K _key;
    V _value;

public:
    Entry(K key, V value) : _key(key), _value(value) {}
    virtual ~Entry() {}

    K getK() const { return _key; }
    V getV() const { return _value; }

    void setK(K key) { _key = key; }
    void setV(V value) { _value = value; }
};

#endif // ENTRY_H
