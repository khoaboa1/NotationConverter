/* Name: Sadman Sakib
   Name: Khoa Le 
   This is the doubly linked list */

#include <string>
#include <iostream>
#include "DLinkedList.hpp"


Dlinkedlist::Dlinkedlist(){
    header = new DNode;
    trailer  =new DNode;
    header->next = trailer;
    trailer->prev = header;
};

Dlinkedlist::~Dlinkedlist(){
    while(!empty()){
        removeFront();
    }
    delete header;
    delete trailer;
}


bool Dlinkedlist::empty() const {
    return (header->next == trailer);
}

void Dlinkedlist::add (DNode *v, const Elem& e){
    DNode *u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}


void Dlinkedlist::addFront(const Elem& e){
    add(header->next, e);
}

void Dlinkedlist::addBack(const Elem& e){
    add(trailer,e);
}

void Dlinkedlist::remove(DNode *v){
    DNode *u = new DNode;
    DNode *w = new DNode;
    u = v->prev;
    w = v->next;
    u->next = w;
    w->prev = u;
    delete v;

}

void Dlinkedlist::removeBack(){
    remove(trailer->prev);
}

void Dlinkedlist::removeFront(){
    remove(header->next);
}


const Elem& Dlinkedlist::front() const {
    return (header->next->elem);
}

const Elem& Dlinkedlist::back() const {
    return (trailer->prev->elem);
}