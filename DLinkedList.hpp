#ifndef DLINKLIST_HPP
#define DLINKLIST_HPP

#include <iostream>
#include <string>
#include "DNode.hpp"


class Dlinkedlist{
    public:
        Dlinkedlist();
        ~Dlinkedlist();
        bool empty () const;
        int size() const;
        const Elem& front() const;
        const Elem& back() const ;

        void addFront(const Elem& e);
        void addBack(const Elem& e);

        void removeFront();
        void removeBack();
    private:
        DNode* header;
        DNode* trailer;
    protected:
        void add(DNode *v, const Elem& e);
        void remove(DNode*v);

};


#endif