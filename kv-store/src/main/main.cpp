#include <iostream>
#include "hashtable.hpp"

int main(void) {
    HashTable ht;
    ht.insert("name", "gomes");

    auto resultado = ht.get("name");
    if (resultado.has_value()) {
        std::cout << "Encontrado: " << resultado.value() << std::endl;
    } else {
        std::cout << "Nao encontrado" << std::endl;
    }
}