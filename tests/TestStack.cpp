#include "BasicStack.h"
#include "catch2/catch2.hpp"

SCENARIO("The user performs basic uploading and deleteing ops","[BasicStack]"){
    GIVEN("An existing BasicStack data structure and a Stack ptr to it"){
        BasicStack BS;
        Stack* bs = &BS;
        WHEN("The user looks at the last element of the Stack but it's empty"){
            THEN("peek should throw runtime_error"){
                REQUIRE_THROWS_AS(bs->peek(), std::runtime_error);
            }
        }
        WHEN("The user want to delete the last element of the Stack but it's empty"){
            THEN("pop should throw runtime_error"){
                REQUIRE_THROWS_AS(bs->pop(), std::runtime_error);
            }
        }

        bs->push('c');

        WHEN("The user want to insert a new element at the top of the Stack"){
            THEN("peek should return the inserted character"){
                REQUIRE(bs->peek() == 'c');
            }
        }
        WHEN("The user want to delete the last element of the Stack"){
            THEN("pop should return the last character"){
                char res = bs->pop();
                REQUIRE(res == 'c');
            }
        }
    }

}

SCENARIO("The user wnat to extract w/out deleting last n elements in the Stack","[BasicStack::peekn]"){
    GIVEN("An existing BasicStack data structure and a Stack ptr to it"){
        BasicStack BS("abcdefg");
        Stack* bs = &BS;

        WHEN("the user provides a negative number"){
            int n = -1;
            THEN("peekn should throw invalid_argument"){
                REQUIRE_THROWS_AS(bs->peekn(n), std::invalid_argument);
            }

        }
        WHEN("the user provides a number greater then the size of the Stack"){
            int n = 8;
            THEN("peekn should throw invalid_argument"){
                REQUIRE_THROWS_AS(bs->peekn(n), std::invalid_argument);
            }
        }
        WHEN("the user provide a correct input"){
            int n = 3;
            THEN("peekn should return a substring w/ the last n elements of the Stack"){
                REQUIRE(bs->peekn(n)=="efg");
            }
        }
    }
}

SCENARIO("The user want to pop the last n elements in the Stack","[BasicStack::popn]"){
    GIVEN("An existing BasicStack data structure and a Stack ptr to it"){
        BasicStack BS("abcdefg");
        Stack* bs = &BS;

        WHEN("the user provides a negative number"){
            int n = -1;
            THEN("popn should throw invalid_argument"){
                REQUIRE_THROWS_AS(bs->popn(n), std::invalid_argument);
            }

        }
        WHEN("the user provides a number greater then the size of the Stack"){
            int n = 8;
            THEN("popn should throw invalid_argument"){
                REQUIRE_THROWS_AS(bs->popn(n), std::invalid_argument);
            }
        }
        WHEN("the user provide a correct input"){
            int n = 3;
            THEN("popn should return a substring w/ the last n elements of the Stack end delete them from the Stack"){
                //salvo la dimensione originaria dello Stack
                int size = bs->size();
                REQUIRE(bs->popn(n)=="efg");
                REQUIRE(bs->peekn(size - n)== "abcd");
            }
        }
    }
}