#include "CappedStack.h"

CappedStack::CappedStack(const int cap):BasicStack(){
    if(cap < 1){
        throw std::invalid_argument(to_string(cap) + "not a positive number");
    }
    else{
        this->cap = cap; // scrivo all'interno dell'attributo della classe
        // essendo il costruttore vuoto, esso può essere
        // chiamato implicitamente dalla classe derivata
        // vedi ereditarietà del costruttore
    }
}

string CappedStack:: as_string() const{
    
    return string("CappedStack:\n") 
            + to_string(this->cap) +string("\n") 
            + string("elements: ") + this->elements;
}

void CappedStack:: push(const char c){
    
    int i = this->elements.size();

    if(i < cap){
        this -> elements.push_back(c);
    }
    return;
}

int CappedStack::get_cap() const{
    return this->cap;
}
     
void CappedStack:: set_cap(const int cap){
    int i = this->elements.size();
    if(cap < 1){
        throw std::invalid_argument("cap must be positive");
    }
    else if(cap < i){
        //remove all elements above cap
        //per ottenere questo effetto chiamo la popn su elements
        //chiamo il metodo della classe
        this->popn(i-cap);
    }
    this -> cap = cap;
    return;
}