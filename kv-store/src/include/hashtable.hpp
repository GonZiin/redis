#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream>
#include <cstdint>

inline constexpr uint64_t FNV_offset_basis = 0xcbf29ce484222325;
inline constexpr uint64_t FNV_prime        = 0x100000001b3;

inline uint64_t fnv1a_hash(const std::string& key) {
    uint64_t hash = FNV_offset_basis;
    for (unsigned char c : key) {
        hash ^= c;
        hash *= FNV_prime;
    }
    return hash;
}

#endif