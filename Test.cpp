/**
 * unit test to FamilyTree
 * AUTHOR: RoiPeleg
 * */
#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>

// a macro to simply check exception b must be init to FALSE!
#define checkExp(T, f, b)     \
    {                         \
        try                   \
        {                     \
            T.f;              \
        }                     \
        catch (exception & e) \
        {                     \
            b = true;         \
        }                     \
    }
#define initTree(T)                        \
    {                                      \
        T.addFather("Yosef", "Yaakov")     \
            .addMother("Yosef", "Rachel")  \
            .addFather("Yaakov", "Isaac")  \
            .addMother("Yaakov", "Rivka")  \
            .addFather("Isaac", "Avraham") \
            .addFather("Avraham", "Terah") \
            .addMother("Rivka", "m")       \
            .addMother("m", "m1");         \
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
        .addMother("Rivka", "m")
        .addMother("m", "m1");
    CHECK(T.find("father") == "Yaakov");
    CHECK(T.find("mother") == "Rachel");
    CHECK(T.find("grandfather") == "Issac");
    CHECK(T.find("grandmother") == "Rivka");
    CHECK(T.find("great-grandfather") == "Avraham");
    CHECK(T.find("great-great-grandfather") == "Terah");
    CHECK(T.find("great-grandmother") == "m");
    CHECK(T.find("great-great-grandmother") == "m1");
    bool b = false;
    checkExp(T, addFather("Yaakov", "ff"), b)
        CHECK(b == true);
    b = false;
    checkExp(T, addMother("Yaakov", "r2"), b)
        CHECK(b == true);
    b = false;
    checkExp(T, addMother("Rivka", "r2"), b)
        CHECK(b == true);
    b = false;
    checkExp(T, addMother("m", "r2"), b)
        CHECK(b == true);
}
TEST_CASE("Test remove")
{
    T.remove("m1");
    CHECK(T.relation("m1") == "unrealted");
    T.remove("Rivka");
    CHECK(T.relation("m") == "unrealted");
    CHECK(T.relation("Rivka") == "unrealted");
    T.remove("Yaakov");
    CHECK(T.relation("Issac") == "unrealted");
    CHECK(T.relation("Terah") == "unrealted");
    CHECK(T.relation("Avraham") == "unrealted");
    bool b = false;
    checkExp(T, remove("Yosef"), b)
        CHECK(b == true);
        b = false;
    checkExp(T, remove("Yaakov"), b)
        CHECK(b == true);
        b = false;
    checkExp(T, remove("m1"), b)
        CHECK(b == true);
        b = false;
    checkExp(T, remove("Issac"), b)
        CHECK(b == true);
        b = false;
    checkExp(T, remove("yossi"), b)
        CHECK(b == true);
}
TEST_CASE("Test realtion")
{
}
TEST_CASE("Test find")
{
    T2.addFather("Noa", "Shai")
        .addMother("Noa", "Shani")
        .addFather("Shai", "Pinchas")
        .addMother("Shai", "Riki")
        .addFather("Shani", "Silvan")
        .addMother("Shani", "Rachel")
        .addFather("Pinchas", "Avraham")
        .addMother("Pinchas", "Sara")
        .addFather("Riki", "Yakov")
        .addMother("Riki", "Lea")
        .addFather("Silvan", "Meni")
        .addMother("Silvan", "Hadas")
        .addFather("Rachel", "Almog")
        .addMother("Rachel", "Ariel")
        .addFather("Avraham", "Yosef")
        .addMother("Avraham", "Shontal")
        .addFather("Shontal", "Haim")
        .addMother("Shontal", "Sheli")
    
    CHECK(T.find("father")=="Shai");
    CHECK(T.find("mother")=="Shani");
    CHECK(T.find("grandfather")=="Pinchas");
    CHECK(T.find("grandfather")=="Silvan");
    CHECK(T.find("grandmother")=="Riki");
    CHECK(T.find("grandmother")=="Rachel");
    CHECK(T.find("great-grandfather")=="Avraham");
    CHECK(T.find("great-grandfather")=="Meni");
    CHECK(T.find("great-grandfather")=="Yakov");
    CHECK(T.find("great-grandfather")=="Almog");
    CHECK(T.find("great-grandmother")=="Sara");
    CHECK(T.find("great-grandmother")=="Lea");
    CHECK(T.find("great-grandmother")=="Hadas");
    CHECK(T.find("great-grandmother")=="Ariel");
    CHECK(T.find("great-great-grandfather")=="Yosef");
    CHECK(T.find("great-great-grandmother")=="Shontal");
    CHECK(T.find("great-great-great-grandfather")=="Haim");
    CHECK(T.find("great-great-great-grandmother")=="Sheli");

    CHECK(T.find("father")=="Pinchas");
    CHECK(T.find("mother")=="Rachel");
    CHECK(T.find("grandfather")=="Avraham");
    CHECK(T.find("grandfather")=="Meni");
    CHECK(T.find("grandmother")=="Lea");
    CHECK(T.find("grandmother")=="Ariel");
    CHECK(T.find("great-grandfather")=="Yosef");
    CHECK(T.find("great-grandfather")=="Silvan");
    CHECK(T.find("great-grandfather")=="Shai");
    CHECK(T.find("great-grandfather")=="Dvir");
    CHECK(T.find("great-grandmother")=="Riki");
    CHECK(T.find("great-grandmother")=="Rivka");
    CHECK(T.find("great-grandmother")=="Shontal");
    CHECK(T.find("great-grandmother")=="Shani");
    CHECK(T.find("great-great-grandfather")=="Haim");
    CHECK(T.find("great-great-grandmother")=="Noa");
    CHECK(T.find("great-great-great-grandfather")=="Beni");
    CHECK(T.find("great-great-great-grandmother")=="Hadas");
}