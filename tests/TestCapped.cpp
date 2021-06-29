#include "CappedStack.h"
#include "catch2/catch2.hpp"

SCENARIO("The user initnialize a CappedStack obj","[CappedStack]"){
    WHEN("A negative cap is provided"){
        int cap = -1;
        THEN("CappedStack should throw invalid_argument"){
            REQUIRE_THROWS_AS(CappedStack(cap),std::invalid_argument);
        }
    }
}

SCENARIO("The user push an element in the Stack","[CappedStack::push]"){
    GIVEN("An existing CappedStack data structure and a Stack ptr to it"){
        CappedStack CS(1);
        Stack* cs = &CS;
        cs -> push('a');

        WHEN("When the user push new element but reaches cap size"){
            cs->push('b');
            THEN("silently removes new elements"){
                REQUIRE(cs->size()==1);
                REQUIRE(cs->peek() == 'a');
            }

        }

    }

}

SCENARIO("The user want to know cap size","[CappedStack::get_cap]"){
    GIVEN("An existing CappedStack data structure and a Stack ptr to it"){
        CappedStack CS(3);
        Stack* cs = &CS;

        WHEN("get_cap method called should return current cap size"){
            /*
            Come chiamare il metodo get_cap? 
            Ricordiamoci che "cs" è un puntatore di classe Stack, che è la 
            classe base. Il metodo get_cap tuttavia è solo in CappedStack e 
            non è ereditato dalla classe Base, quindi per accedervi necessito 
            di un oggeetto di classe CappedStack oppure di un puntatore di classe
            Cappedstack
            */
           int i;
           i = CS.get_cap();
           //((CappedStack*)cs)->get_cap(); //accesso alternativo al metodo mediante casting del puntatore
            REQUIRE(i == 3);
        }
    }

}
SCENARIO("The user want to set a new cap size","[CappedStack::set_size]"){
    GIVEN("An existing CappedStack data structure and a Stack ptr to it"){
        CappedStack CS(2);
        Stack* cs = &CS;
        //insert an element
        cs -> push('a');
        cs -> push('b');

        WHEN("The user provides a non valid cap size, zero or negative"){
            int i = 0;
            int j = -1;
            THEN("set_cap should throw invalid_argument"){
                REQUIRE_THROWS_AS(CS.set_cap(i),std::invalid_argument);
                REQUIRE_THROWS_AS(CS.set_cap(j),std::invalid_argument);
            }
        }
        WHEN("The user provides a cap size smaller than current one"){
            int i = 1;
            CS.set_cap(i);
            THEN("Silently removes all elements exceeding the new cap size"){
                REQUIRE(CS.get_cap() == 1);
                REQUIRE(cs->size() == 1);
                REQUIRE(cs->peek() == 'a');
            }

        }
        WHEN("The user provides a cap size bigger than current one"){
            int i = 3;
            CS.set_cap(i);
            THEN("Update the current size w/ new one and make no changes"){
                REQUIRE(CS.get_cap()==3);
                REQUIRE(cs->size()==2);
                REQUIRE(cs->peekn(cs->size())== "ab");
            }
        }

    }
}

