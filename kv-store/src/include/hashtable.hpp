#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream>
#include <cstdint>
#include <vector>
#include <optional>
#include <string>

inline constexpr uint64_t FNV_offset_basis = 0xcbf29ce484222325;
inline constexpr uint64_t FNV_prime        = 0x100000001b3;

class HashTable {
private:
    int bucketCount;
    std::vector<std::vector<std::pair<std::string, std::string>>> buckets;
    uint64_t fnv1a_hash(const std::string& key);

public:
    HashTable();

    void insert(const std::string& key, const std::string& value);
    std::optional<std::string> get(const std::string& key);
    bool remove(const std::string& key);
    bool exists(const std::string& key);
};

#endif
