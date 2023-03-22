#include <string>
#include <iostream>

using namespace std;

// hash table size
#define CAP 1024

// hash table class
class HashTable{
    // struct of hash table item
    struct ht_item{
        string key;
        string value;
        ht_item* next;
    };
    // array of pointers with hash table items
    ht_item **items;
    int size;

    private:
        int hash_func(string str);
    public:
        HashTable(int s);
        ~HashTable();    
        void delete_item(string key);
        void print();
        void print_item(string key);
        void insert(string key, string value);
};
