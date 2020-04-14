#pragma once
#include <iostream>
using namespace std;
namespace family{

class Tree{
    public:
    Tree(string);
    Tree addFather(string ,string);
    Tree addMother(string ,string);
    void display();
    string relation(string);
    string find(string);
    void remove(string);
};
}