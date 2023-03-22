#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

// simple hash function
int HashTable::hash_func(string key)
{
    int hash = 0, index = 0;

    for(int i = 0; i < key.length(); i++){
        hash = hash + (int)key[i];
    }

    return hash % size;
}

// hashtable constructor
HashTable::HashTable(int s){
    items = new ht_item*[s];
    size = s;
}

// hashtable destructor
// delete all pointers
HashTable::~HashTable(){
    for(int i = 0; i < size; i++){
        if(items[i]){
            ht_item* curr = items[i];
            while(!curr){
                ht_item* next = curr -> next;
                delete curr;
                curr = NULL;
                curr = next;
            }           
        }
    }
    delete[] items;
}

// delete certain item specified by key
void HashTable::delete_item(string key){
    // find its index
    int index = hash_func(key);

    // element doesn't exist at this index
    if(!items[index]){
        cout << "There is no item with that key - " << key << "\n";
    }
    // element exists, matches the key and is first in bucket
    else if(items[index] && items[index]->next == NULL && items[index]->key == key){
        delete items[index];
        items[index] = NULL;
        cout << "Item "<< key << " deleted.\n";
    }
    // element exists, matches the key but there's more items in bucket
    else if(items[index] && items[index]->key == key){
        ht_item* delPtr = items[index];
        items[index] = items[index] -> next;
        delete delPtr;
        delPtr = NULL;
        cout << "Item "<< key << " deleted.\n";
    }
    // element exists and is not first in bucket
    else{
        ht_item* P1 = items[index] -> next;
        ht_item* P2 = items[index];

        // find the item
        while(P1 != NULL && P1 -> key != key){
            P2 = P1;
            P1 = P1 -> next;
        }
        if(!P1){    
            cout << "There is no item with that key - " << key << "\n";          
        }
        // if item found, delete it and alter 'next' pointers
        else{
            ht_item* delPtr = P1;
            P1 = P1 -> next;
            P2 -> next = P1;
            delete delPtr;
            delPtr = NULL;
            cout << "Item "<< key << " deleted.\n";
    }
    }
}

// insert item to hashtable
void HashTable::insert(string key, string value){
    // calculate the index
    int index = hash_func(key);

    ht_item* Ptr = items[index];

    // if index if empty, create new object with specified parameters
    if(Ptr == NULL){
        items[index] = new ht_item;
        Ptr = items[index];
        Ptr -> key = key;
        Ptr -> value = value;
        Ptr -> next = NULL;
    }
    // if index is not empty, go to the end of bucket and insert there new item
    else{
        ht_item* item = new ht_item;
        item -> key = key;
        item -> value = value;
        item -> next = NULL;
        while(Ptr->next){
            Ptr = Ptr -> next;
        }
        Ptr -> next = item;
    }
}

// print all items in hashtable
void HashTable::print(){
    cout << "---------------\n";
    cout << "HASH TABLE\n";
    for(int i = 0; i < size; i++){
        if(items[i]){
            // print item on items[index]
            printf("Index %d Key %s Value %s \n", i, items[i] -> key.c_str(), items[i] -> value.c_str());
            ht_item* Ptr = items[i] -> next;
            // print other items in bucket if exist
            while(Ptr){
                printf("Index %d Key %s Value %s \n", i, Ptr -> key.c_str(), Ptr -> value.c_str());
                Ptr = Ptr -> next;
            }
        }
    }
    cout << "---------------\n";
}

// print item with specified key
void HashTable::print_item(string key){
    int index = hash_func(key);

    ht_item* Ptr = items[index];
    // loop if item on index exist; if it's not the head of bucket, loop to find it
    while(Ptr){
        if(Ptr-> key == key){
            printf("ITEM FOUND. Index %d Key %s Value %s \n", index, Ptr -> key.c_str(), Ptr -> value.c_str());
            return;
        }
        Ptr = Ptr -> next;
    }
    cout << "Item with that key - " << key << " was not found\n";
    }