/* Name: Sadman Sakib
   Name: Khoa Le 
   This file contains the function definitions for all of our functions as well as the methods for NotationConverter*/
#include <iostream>
#include <string>
#include "NotationConverter.hpp"
#include "throw.hpp"
#include <algorithm>

void NotationConverter::deletedeque(){
    while (!Isempty()){
        removeFront();
    }
    return;
}

bool NotationConverter::Isempty() const{
    return (size()==0);
}



const Elem& NotationConverter::front(){
    if (Isempty()){
        throw EmptyError("Deque is empty");
    }
    return list.front();
} 

const Elem& NotationConverter::back(){
    if (Isempty()){
        throw EmptyError("Deque is empty");  
    }  
    return list.back();  
}

void NotationConverter::insertFront(const Elem& e){
    list.addFront(e); num++;
}

void NotationConverter::insertBack(const Elem& e){
    list.addBack(e); num++;
}

void NotationConverter::removeFront(){
    if (Isempty()){
        throw EmptyError("Deque is empty");
    }
    list.removeFront(); num--;
}

void NotationConverter::removeBack(){
    if (Isempty()){
        throw EmptyError("Deque is empty");
    }
    list.removeBack(); num--;
}

// function to check if the input has valid operators, i.e. +, -, *, /, (, )
bool NotationConverter::validoperator(char a){ // A function to check validoperator. Need to call everytime input or loop the input with this function.
    if ((a == '+') || (a == '-') || (a== '*') || (a == '/') || (a == '(') || (a == ')') || (a == ' ') || (a == '\t')){
        return 1;
    }
    return 0;
}

// function to check if the input has valid operands, i.e. a-z or A-Z
bool NotationConverter::validoperand(char a){ // A function to check validoperand. Need to call everytime input or loop the input with this function.
    if ((a >= 'a' && a <= 'z') || ( a >= 'A' && a <= 'Z')){
        return 1;
    }
    return 0;
}

// function to check if the input is valid or not
bool NotationConverter::validinput(char a){
    return (validoperator(a) || validoperand(a)); // this will return 1 if its valid operator or operand. If not, it will return 0.
    
    //TODO: maybe change to && depending on test cases
}

std::string NotationConverter::format(std::string c){ // this is to format as what we need to A B C instead of ABC when we print the value out. Make sure to put this under all the converter.
    std::string a = "";
    for (int j = 0; c[j]!='\0'; j++){
        if (c[j+1]=='\0'){
            a = a + c[j];
        }
        else{ 
            a = a + c[j];
            a = a + ' ';
        }
    }
    return a;
}

// this function will return the precedence of the operator. For example, + and - will return 1, while * and / will return 2
int NotationConverter::precedence(char a){ 
    if (a == '+' || a == '-'){
        return 1;
    }
    else if (a == '*' || a == '/'){
        return 2;
    }
    return 0;
}

// this function will return the precedence of the operator for string inputs instead of char inputs
int NotationConverter::Stringprecedence(std::string a){ 
    if (a == "+" || a == "-"){
        return 1;
    }
    else if (a == "*" || a == "/"){
        return 2;
    }
    return 0;
}


/* solution to the methods for converting from one number format to another*/

std::string NotationConverter::postfixToInfix(std::string inStr){ 
    // traverse the string from left to right
    for (int index = 0; index < inStr.size(); index++){
        if (validinput(inStr[index])){
            throw EmptyError("Invalid input");
        }
        if ((inStr[index] == ' ') || (inStr[index]) == '\t') // skip the space
            continue;
        if (validoperand(inStr[index])){
            std::string op(1, inStr[index]);
            insertFront(op); 
        }
        else {
            std::string op1 = front();
            removeFront();
            std::string op2 = front();
            removeFront();

            std::string temp = "(" + op2 + inStr[index] + op1 + ")";
            insertFront(temp);
        }
    }
    return format(front());   
};

std::string NotationConverter::postfixToPrefix(std::string inStr){ // convert to infix and then to prefix
    std::string result = postfixToInfix(inStr);
    return format(infixToPrefix(result));
};

std::string NotationConverter::infixToPostfix(std::string inStr){
    // traverse the string from left to right
    std::string result; // the result string

    for (int index = 0; index < inStr.size(); index++){
        if (!validinput(inStr[index])){
            throw EmptyError("Invalid input");
        }
        if ((inStr[index] == ' ') || (inStr[index]) == '\t') // skip the space
            continue;
        
        if (validoperand(inStr[index])){ // if the character is a valid operand, add it to the result
            result = result + inStr[index];
        } else if ((inStr[index]=')')) {
            while (!Isempty() && front() != "("){
                result += front();
                removeFront();
            }
            removeFront();
        }
        else {
            while (precedence(inStr[index]) <= Stringprecedence(front())){
                result = result + front();
                removeFront();
            }
        }

        while (!Isempty()){
            result = result + front();
            removeFront();
        }
    }
    return format(result);
};

std::string NotationConverter::infixToPrefix(std::string inStr){
    reverse(inStr.begin(), inStr.end());
    for (int i = 0;inStr[i] != '\0'; i++){
        if (!validinput(inStr[i]))
            throw EmptyError("Invalid input");
        if (inStr[i] == ' ' || inStr[i] == '\t')
            continue;   
        if (inStr[i] == ')')
            inStr[i] = '(';
        else if (inStr[i] == '(')
            inStr[i] = ')';    
    }
    std::string result = infixToPostfix(inStr);
    reverse(result.begin(), result.end());
    return format(result);
};

std::string NotationConverter::prefixToInfix(std::string inStr){ //needs brackets 
    for (int i = inStr.size()-1; i>=0; i--){ // traverse the string from right to left
        if (!validinput(inStr[i]))
            throw EmptyError("Invalid input");
        if (inStr[i] == ' ' || inStr[i] == '\t')
            continue;    
        if (!validoperand(inStr[i])){
            std::string op1 = front();
            removeFront();
            std::string op2 = front();
            removeFront();
            std::string temp = "(" + op1 + inStr[i] + op2 + ")";
            insertFront(temp);
        } else {
            std::string op(1, inStr[i]);
            insertFront(op);
        }
    }
    return format(front());
};

std::string NotationConverter::prefixToPostfix(std::string inStr){ // convert to infix and then to postfix
    std::string result = prefixToInfix(inStr);
    return format(infixToPostfix(result));
};
