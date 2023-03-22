#include "hashTable.h"
#include <iostream>

using namespace std;

int main()
{
    HashTable *t = new HashTable(CAP);

    // print non existing item
    t->print_item("kot");

    // insert random item
    t->insert("kot", "2");

    t->print();

    // insert next few items
    t->insert("pies", "3");

    t->insert("tok", "2");

    t->insert("kto", "4");

    // print existing item
    t->print_item("tok");

    t->print();

    // print non existing item
    t->print_item("koto");

    // delete item which is in the middle of bucket
    t->delete_item("tok");

    t->print();

    // print last item after deleting previous item in bucket
    t->print_item("kto");

    // print first item in bucket
    t->print_item("kot");

    // delete first item in bucket
    t->delete_item("kot");

    // print last item in bucket which is first now
    t->print_item("kto");

    // insert item to the existing index after all operations
    // check if moving item in bucket works properly
    t-> insert("kot", "2");

    // delete item on different index; simple delete operation
    t->delete_item("pies");

    t->print();

    delete t;

    return 0;
}