#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

struct node
{
    string data;
    node *link;
};

class stack_linkedlist
{
    private:
    node *head=NULL;
    int top=-1;

    public:
    bool isEmpty();
    void add_text(string text);    // do push function in stack
    int size();         //return current size of stack ( string available in stack )
    string front();  // return first element  ( not used much in code )
    string back();      //return last element ( not used much in code )
    void pop_back();  //pop last element
    void clear();          //clear stack by breaking all link to element one by one
    node* begin();    //return head pointer
};

class Text_Editor
{
    private:
        struct stack_linkedlist undo;        // store main text in stack
        struct stack_linkedlist redo;          // store string that we have undo from main text into redo string
                                          //  ( we can preform perform undo-redo task multiple time which is not available in notepad
    public:
        void push(string input_text);     // preforms push string into stack
        void undo_text();                // add undo strings into redo stack
        int redo_text();                  //add undo string stored in redo stack back to main stack
        void print_undo_redo();             // display string of any stack
        int* select_replace(string change);    // find input string and replace by updated entered string one by one as occurrence found in string
        void search_string(string );           // Search entered word and highlight that word
};

#endif // TEXT_EDITOR_H
