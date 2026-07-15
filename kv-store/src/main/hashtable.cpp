#include "hashtable.hpp"
#include <iostream>
#include <algorithm>

uint64_t HashTable::fnv1a_hash(const std::string& key) {
    uint64_t hash = FNV_offset_basis;
    for (unsigned char c : key) {
        hash ^= c;
        hash *= FNV_prime;
    }
    return hash;
}

HashTable::HashTable() : bucketCount(16), buckets(16) {}

void HashTable::insert(const std::string& key, const std::string& value) {
    uint64_t index = fnv1a_hash(key);
    index %= bucketCount;

    auto& bucket = buckets[index];

    for (auto& pair : bucket) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    
    bucket.push_back({key, value});
}

std::optional<std::string> HashTable::get(const std::string& key) {
    uint64_t index = fnv1a_hash(key);
    index %= bucketCount;

    auto& bucket = buckets[index]; 

    for (auto& pair : bucket) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return std::nullopt;
}
