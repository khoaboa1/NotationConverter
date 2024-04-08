#ifndef DEQUE_EXCEPTION
#define DEQUE_EXCEPTION


#include <string>

class RuntimeError{
    std::string message1;

public:
    RuntimeError(const std::string &err){message1 = err;}
    std::string getMessage() const{return message1;}
};

class EmptyError : public RuntimeError{
public:
    EmptyError(const std::string &err) : RuntimeError(err){}
    std::string getMessage() const{return RuntimeError::getMessage();}
};

#endif
