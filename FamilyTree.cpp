#include "FamilyTree.hpp"
#include <cmath>
using namespace std;
namespace family
{
Tree::Tree(string root)
{
    string s[128-1]; //defualt to 7 generations 2^7 each generation is twice the size of the last generation
    tree = s;
    tree[0] = root;
    length = 127;
    for(size_t i = 1; i < length;i++){
        tree[i] = "";
    }
    this->size_gen = 0;
    this->max_gen = 7;
}
int Tree::getInd(string child)
{
    bool found = false;
    size_t index = -1;
    for (size_t i = 0; i < length && !found; i++)
    {
        
        if (!tree[i].compare(child))
        {
            found = true;
            index = i;
        }
    }

    return index;
}
Tree Tree::addFather(string child, string father)
{
    //i*2+1 father
    size_t index = getInd(child);
    if(index * 2 + 1 > length)resize(4);
    if(tree[index * 2 + 1]!= ""){
        throw runtime_error("already has a father");
    }
    tree[index * 2 + 1] = father;
    return *this;
}
Tree Tree::addMother(string child, string mother)
{
    //i*2+2 mother
    size_t index = getInd(child);
   
    if(index * 2 + 2 > length)resize(4);

     if(tree[index * 2 + 2]!= ""){
        throw runtime_error("already has a mother");
    }
    printf("ssss");
    tree[index * 2 + 2] = mother;
    printf(child.c_str());
    printf("\n");
     printf(tree[2*index+2].c_str());
      printf("\n");
    return *this;
}
string Tree::relation(string name)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (name.compare(tree[i])==0)
        {
            if (i == 0)
                return "me";
            else if (i == 1)
                return "father";
            else if (i == 2)
                return "mother";
            else
            {
                if (i % 2 == 1)
                {
                    string ans = "grandfather";
                    while (i != 0)
                    {
                        ans = "great-" + ans;
                        i = i / 2;
                    }
                    return ans;
                }
                else
                {
                    string ans = "grandmother";
                    while (i != 0)
                    {
                        ans = "great-" + ans;
                        i = i / 2;
                    }
                    return ans;
                }
            }
        }
    }
    return "unrelated";
}

string Tree::find(string relate)
{
    if (relate.compare("me") == 0)
        return tree[0];
    else if (relate.compare("father") == 0)
        return tree[1];
    else if (relate.compare("mother") == 0)
        return tree[2];
    else
    {
        int c = 0;
        int i = 0;
        while (i < relate.length())
        {
            if (relate.at(i) == '-')
                c++;
            i++;
        }
        int x = 3;
        while (c != 0)
        {
            x = 2 * x;
            c--;
        }
        if (relate.std::string::find("grandfather") != std::string::npos)
            return tree[x + 1];
        else if (relate.std::string::find("grandmother") != std::string::npos)
            return tree[x + 2];
    }
    throw runtime_error("didn't find someone with that relation in the tree");
}
void recremove(int ind , string* t){//auxaillry
    if(2*ind+1 < t->length() && t[2*ind+1].compare(""))
    recremove(2*ind+1, t);
    if(2*ind+2 < t->length() && t[2*ind+2].compare(""))
    recremove(2*ind+2, t);
}
void Tree::remove(string toremove)
{
    size_t ind = getInd(toremove);
    if(ind==0)
        throw runtime_error("can't delete root");
    else if(ind!=-1)
        throw runtime_error("does not exist in the tree");
    if(2*ind+1 < length && tree[2*ind+1].compare(""))
    recremove(2*ind+1, tree);
    if(2*ind+1 < length &&tree[2*ind+2].compare(""))
    recremove(2*ind+2, tree);
}
void recdisplay(int ind , string* t){//auxaillry
    if(2*ind+1 < t->length() && t[2*ind+1].compare("")){
    printf(t[2*ind+1].c_str());
    recdisplay(2*ind+1, t);
    }
    if(2*ind+2 < t->length() && t[2*ind+2].compare("")){
    printf(t[2*ind+2].c_str());
    recdisplay(2*ind+2, t);
    }
    if(ind-1 & (ind-2)==0)//chack if this cell is the end of a generation
    printf("\n");
}
void Tree::display()
{
    printf(tree[0].c_str() + '\n');
    if(tree[1].compare(""))
        recdisplay(1, tree);
    if(tree[2].compare(""))
        recdisplay(2, tree);
    
}
void Tree::resize(int x)
{
    this->max_gen = this->max_gen + x;
    string newtree[(int)pow(2, (this->max_gen + x)) - 1];
    length = (int)pow(2, (this->max_gen + x)) - 1;
    for (size_t i = 0; i < length; i++)
    {
        newtree[i] = tree[i];
    }
    delete &tree;
    this->tree = newtree;
}
} // namespace family