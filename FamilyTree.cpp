#include "FamilyTree.hpp"
using namespace std;
namespace family{
   Tree::Tree(string){

    }
    Tree Tree::addFather(string ,string){
        return Tree("S");
    }
    Tree Tree::addMother(string ,string){
        return Tree("S");
    }
    string Tree::relation(string){
        return "s";
    }
    string Tree::find(string)
    {
        return "fd";
    }
    void Tree::remove(string)
    {

    }
    void Tree::display(){
        
    }
}