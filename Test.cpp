/**
 * unit test to FamilyTree
 * AUTHOR: RoiPeleg
 * */
#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>

// a macro to simply check exception b must be init to FALSE!
#define expc(T,f, b){\
      try{\
        T.f;\
    }catch(exception& e){\
        b = true;\
    }\
}
using namespace std;
Tree T("Yosef");   
TEST_CASE("Test add")
{
                   
    T.addFather("Yosef", "Yaakov")    
        .addMother("Yosef", "Rachel") 
        .addFather("Yaakov", "Isaac")
        .addMother("Yaakov", "Rivka")
        .addFather("Isaac", "Avraham")
        .addFather("Avraham", "Terah")
        .addMother("Rivka","m")
        .addMother("m","m1");

    CHECK(T.find("father")=="Yaakov");
    CHECK(T.find("mother")=="Rachel");
    CHECK(T.find("grandfather")=="Issac");
    CHECK(T.find("grandmother")=="Rivka");
    CHECK(T.find("great-grandfather")=="Avraham");
    CHECK(T.find("great-great-grandfather")=="Terah");
    CHECK(T.find("great-grandmother")=="m");
    CHECK(T.find("great-great-grandmother")=="m1");

    bool b =false;
    expc(T,addFather("yakov","ff"),b)
    CHECK(b==true);
}
TEST_CASE("Test remove")
{
    T.remove("m1");
    CHECK(T.relation("m1")=="unrealted");
    T.remove("Rivka");
    CHECK(T.relation("m")=="unrealted");
    CHECK(T.relation("Rivka")=="unrealted");
    T.remove("Yaakov");
    CHECK(T.relation("Issac")=="unrealted");
    CHECK(T.relation("Terah")=="unrealted");
    CHECK(T.relation("Avraham")=="unrealted");
    bool b = false;
    expc(T,remove("Yosef"),b)
    CHECK(b==true);
    b = false;
    expc(T,remove("Yaakov"),b)
    CHECK(b==true);
    b = false;
    expc(T,remove("m1"),b)
    CHECK(b==true);
}
TEST_CASE("Test realtion")
{
}
TEST_CASE("Test find")
{
}