// EnglishDictionary.cpp
#include "EnglishDictionary.h"
#include <iostream>

EnglishDictionary::EnglishDictionary(std::string dictName) : name(dictName) {}

EnglishDictionary::~EnglishDictionary() {}

void EnglishDictionary::add(std::string word, std::string definition) {
    dictionary.put(word, definition);
}

void EnglishDictionary::printDictionary(bool fromStart) const {
    dictionary.print(fromStart);
}
