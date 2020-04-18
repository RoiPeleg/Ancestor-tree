#pragma once
#include <iostream>
using namespace std;
namespace family{

class Tree{
    private:
    size_t size_gen;//actual capcity for the number of genarations that can be stored array
    string tree[];
    int getmother(string);//returns the location of the mother of given person
    int getfather(string);// '' asme for father
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