#include <catch2/catch_test_macros.hpp>
#include "hashtable.hpp"

TEST_CASE("Insert in hash table is successful") {
    HashTable ht;

    ht.insert("name", "gomes");

    REQUIRE(ht.get("name").has_value());
    REQUIRE(ht.get("name").value() == "gomes");
}

TEST_CASE("Inserting in an existing key the value is updated") {
    HashTable ht;

    ht.insert("name", "gomes");
    ht.insert("name", "goncalo");

    REQUIRE(ht.get("name").value() != "gomes");
    REQUIRE(ht.get("name").value() == "goncalo");
}

TEST_CASE("Get on a key that was never inserted returns nullopt") {
    HashTable ht;

    REQUIRE_FALSE(ht.get("nao_existe").has_value());
}

TEST_CASE("Exists returns true for an inserted key") {
    HashTable ht;
    ht.insert("name", "gomes");

    REQUIRE(ht.exists("name"));
}

TEST_CASE("Exists returns false for a key that was never inserted") {
    HashTable ht;

    REQUIRE_FALSE(ht.exists("nao_existe"));
}

TEST_CASE("Remove deletes an existing key") {
    HashTable ht;
    ht.insert("name", "gomes");

    REQUIRE(ht.remove("name"));
    REQUIRE_FALSE(ht.exists("name"));
    REQUIRE_FALSE(ht.get("name").has_value());
}

TEST_CASE("Remove on a key that does not exist returns false") {
    HashTable ht;

    REQUIRE_FALSE(ht.remove("nao_existe"));
}

TEST_CASE("Remove does not affect other keys") {
    HashTable ht;
    ht.insert("name", "gomes");
    ht.insert("age", "22");

    ht.remove("name");

    REQUIRE_FALSE(ht.exists("name"));
    REQUIRE(ht.exists("age"));
    REQUIRE(ht.get("age").value() == "22");
}

TEST_CASE("Insert and get an empty string value") {
    HashTable ht;
    ht.insert("empty", "");

    REQUIRE(ht.get("empty").has_value());
    REQUIRE(ht.get("empty").value() == "");
}

TEST_CASE("Multiple keys can coexist independently") {
    HashTable ht;
    ht.insert("a", "1");
    ht.insert("b", "2");
    ht.insert("c", "3");

    REQUIRE(ht.get("a").value() == "1");
    REQUIRE(ht.get("b").value() == "2");
    REQUIRE(ht.get("c").value() == "3");
}