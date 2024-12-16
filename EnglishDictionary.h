// EnglishDictionary.h
#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H

#include "NodeDictionaryG.h"
#include <string>

class EnglishDictionary {
private:
    std::string name;
    NodeDictionaryG<std::string, std::string> dictionary;

public:
    EnglishDictionary(std::string dictName);
    virtual ~EnglishDictionary();

    void add(std::string word, std::string definition);
    void printDictionary(bool fromStart) const;
};

#endif // ENGLISHDICTIONARY_H
