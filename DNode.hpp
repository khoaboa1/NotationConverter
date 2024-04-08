#ifndef DNODE
#define DNODE


#include <string>
#include <iostream>

typedef std::string Elem;
class DNode{
    public:
        DNode(){}
    private:
        Elem elem;
        DNode *next;
        DNode *prev;
        friend class Dlinkedlist;
};


#endif