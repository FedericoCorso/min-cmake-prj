#include <iostream>
#include <stdexcept>

#include "BasicStack.h"

///implementazione del costruttore
BasicStack::BasicStack(){
    this->elements = string();
    /*
    string() è il costruttore di default di un oggetto di classe string
    esso inizializza una stringa vuota, ovvero con una lunghezza nulla
    */
}

BasicStack::BasicStack(string data):elements(data){}

int BasicStack::size() const{
    return this -> elements.size();
}

string BasicStack::as_string() const{ //meglio implementare all'inizio metodi di questo
//tipo in modo da fare meglio il debug
return string("BasicStack size: ") + to_string(this->elements.size()) + string("elements: ") + this->elements;

}
       
bool BasicStack::is_empty() const{
    return this-> elements.size() == 0; 
    //ritorna la size solo se essa è nulla

}
 
void BasicStack::push(const char c){
    this -> elements.push_back(c);
    // pongo alla fine della stringa il carattere c
}
 
char BasicStack::peek() const{
    if(this->elements.size()==0){
        throw std::runtime_error("Stack is empty !");
    }
    return this->elements.back();
    //uso un metodo implementato nella classe string per 
    //ritornare l'ultimo elemento di una stringa

}
 
char BasicStack::pop(){
    if(this -> elements.size()==0){
        throw std::runtime_error("Stack is empty!");
    }
    else{
        char ret = this->elements.back();
        //il metodo pop_back elimina senza ritornare l'elemento
        this->elements.pop_back();
        return ret;
    }
}
        
string BasicStack::peekn(const int n) const{
    /*
    N.B. Passandogli un parametro costante in ingresso sono sicuro che 
    estrarrò proprio n elementi 
    */
   if(n < 0){
       throw std::invalid_argument("n must be positive !");
   }
   else if(n > this->elements.size()){
       throw std::invalid_argument("n exceeds stack size !");
   }
   else{
       return this->elements.substr(this->elements.size()-n, string::npos);
   }

}
 
       
string BasicStack::popn(const int n){
    if(n < 0){
       throw std::invalid_argument("n must be positive !");
   }
   else if(n > this->elements.size()){
       throw std::invalid_argument("n exceeds stack size !");
   }
   else{
       //per migliorare la velocità di esecuzione definisco una variabile ausiliaria
       int i = this->elements.size() - n;
       string ret = this->elements.substr(i,string::npos);
       this->elements = this->elements.substr(0,i);
       return ret;
   }
}