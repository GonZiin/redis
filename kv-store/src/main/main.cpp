#include <iostream>
#include "hashtable.hpp"

int main(void) {
    std::string key = "gomes";
    uint64_t hash = fnv1a_hash(key);
    return 0;
}