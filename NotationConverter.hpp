#ifndef CONVERTER_HPP
#define CONVERTER_HPP


#include <string>
#include <iostream>
#include "NotationConverterInterface.hpp"
#include "DLinkedList.hpp"
#include "DLinkedList.cpp"

typedef std::string Elem;
class NotationConverter: public NotationConverterInterface{
    private:
        Dlinkedlist list;
        int num;
    public:
    NotationConverter() : list(), num(0) {} //In here I already create a deque with Doubly linked list call list in private. Also i included the size of it.
    void deletedeque();
    bool Isempty() const;
    int size() const {return num;}//return the size of the deque
    const Elem& front(); // const throw (DequeEmpty); //make sure to write the throw
    const Elem& back(); // const throw (DequeEmpty);
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront(); // const throw (DequeEmpty);
    void removeBack(); // const throw (DequeEmpty);
    // From line 18->27 is from the slides, change name if you think we need to. I prefer to change it.
    //I think we need to write isoperator, is character
    bool validoperator(char a);
    bool validoperand(char a);
    bool validinput(char a);
    std::string format(std::string c);

    int precedence(char a);
    int Stringprecedence(std::string a);


    // virtual std::string reverse(std::string inStr); // reverse the string

    virtual std::string postfixToInfix(std::string inStr);
    virtual std::string postfixToPrefix(std::string inStr);

    virtual std::string infixToPostfix(std::string inStr);
    virtual std::string infixToPrefix(std::string inStr);

    virtual std::string prefixToInfix(std::string inStr);
    virtual std::string prefixToPostfix(std::string inStr);

    
};

#endif