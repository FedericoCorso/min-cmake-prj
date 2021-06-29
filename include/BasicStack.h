#ifndef BASIC_STACK_H
#define BASIC_STACK_H
/**
 * Devo includere la libreria contenente l'interfaccia da
 * implementare
*/
#include "Stack.h"

/**
 * Classe derivata da Stack, ho gli stessi metodi, 
 * tuttavia devo implementarli.
*/
class BasicStack:public Stack{

    protected: //attributi della classe derivata
    /**
     * Questi attributi ricordiamo essere accessibili solo 
     * dalla classe in cui sono definiti + sottoclassi, questo significa
     * che nelle sottoclassi non dovrò ridichiarare questi 
     * attributi -> evito fenomeni di shadowing
    */
    string elements;
    
    public: ///campo public, in cui metto tutti i metodi, saranno ereditati
    /// dalle classi derivate, attenzione a Overriding
        /**
         * Costruttore della classe BasicStack
        */
        BasicStack();

        /**
         * Costruttore di Stack con stringa in input
        */
        BasicStack(string data);

        int size() const;

        string as_string() const;
       
        bool is_empty() const;
 
        void push(const char c);
 
        char peek() const;
 
        char pop();
 
       
        string peekn(const int n) const;
 
       
        string popn(const int n);

        /*
        Osservo come siano stati eliminati dalle dichiarazioni dei
        metodi:
            - virtual
            - =0
        Questo poichè non voglio che la classe derivata sia una
        classe astratta.
        Inoltre ricordiamo che una volta che un metodo è stato 
        definito come virtuale nella classe base, esso sarà virtuale 
        anche nelle classi derivate.
        L'importante è che non sia virtuale puro
        */

};



#endif