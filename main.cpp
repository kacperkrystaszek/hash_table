#include "hashTable.h"
#include <iostream>

using namespace std;

int main()
{
    HashTable *t = new HashTable(CAP);

    t->print_item("kot");

    t->insert("kot", "2");

    t->print();

    t->insert("pies", "3");

    t->insert("tok", "2");

    t->insert("kto", "4");

    t->print_item("tok");

    t->print();

    t->print_item("koto");

    t->delete_item("tok");

    t->print();

    t->print_item("kto");

    t->print_item("kot");

    t->delete_item("kot");

    t->print_item("kto");

    t->delete_item("pies");

    t->print();

    delete t;

    return 0;
}