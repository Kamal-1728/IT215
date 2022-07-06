#include "Text_Editor.h"
#include <bits/stdc++.h>

using namespace std;

bool stack_linkedlist::isEmpty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
int stack_linkedlist::size()
{
    return top;                     //return current number of string in stack
}
string stack_linkedlist::front()
{
    return head->data;               // return first element
}
node* stack_linkedlist::begin()
{
    return head;                        // return head pointer to stack ( very useful function )
}

string stack_linkedlist::back()
{
    node *ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    return ptr->data;                   // traverse through stack and return last element in stack
}

void stack_linkedlist::add_text(string text)
{
    node *temp=new node;
    node *ptr=head;
    if(isEmpty())
    {
        temp->data=text;
        temp->link=NULL;            // add first element
        head=temp;
        top=1;
    }
    else
    {
        temp->link=NULL;
        temp->data=text;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;        // add string in stack from back
         top++;                     // top contains size
    }
}

void stack_linkedlist::pop_back()
{
    node *ptr=head;
    if(ptr->link==NULL)
    {
        top=0;
    }
    else
    {
        while(ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        free(ptr->link);            //traverse through stack and delete last element and also break link to it
        ptr->link=NULL;
    }
    top--;              // top contains size
}

void stack_linkedlist::clear()
{
    node *ptr=head;
    node *de_node=NULL;
    while(ptr!=NULL)
    {
        de_node=ptr->link;        // traverse through whole stack and one by one all link
        delete ptr;
        ptr=de_node;
    }
    head=NULL;
    top=-1;
}

void Text_Editor::push(string input)
{
    redo.clear();
    undo.add_text(input+" ");           // insert word
}

void Text_Editor::undo_text()
{
    if(!undo.isEmpty())
    {
        redo.add_text(undo.back());                  // add undo word from main text to redo stack
        undo.pop_back();                              // remove that element from main stack
    }
    else
    {
        cout<<"nothing to undo\n";
    }
}

int Text_Editor::redo_text()
{
    if(!redo.isEmpty())
    {
        undo.add_text(redo.back());                  // add again last word of redo stack to main text (undo stack)
        redo.pop_back();                            // remove last word of redo stack
    }
    else
    {
        return -1;                      //  if no undo item is stored in redo stack it will return -1
    }
    return 0;
}

int* Text_Editor::select_replace(string s)
{
    string s1;
    cout<<"Replace with::";
    cin>>s1;
    string chk;
    int i=0;
    static int k[2];            // it will store how many element user want have updated and how many found
                                //ex.  main sting hi hi ok hi if user want to replace hi with hello it will ask for all 3 occurrence if user change only 2 than 2 out of 3 update
    int j=0,kk=0;
    node *temp=undo.begin();
    node *undo_temp=undo.begin();
    for(i=0;i<undo.size();i++)                          //traverse to whole stack
    {
        undo_temp=undo.begin();
        if(temp->data==s+' ')                           //if word that you want to change found ask for change or not
        {
            cout<<"\ndo you want to update "<< kk+1<<"th occurrence , yes or no : ";
            cin>>chk;
            if(chk=="yes"||chk=="YES"||chk=="Yes")              // if user enter yes it will update that word and highlight that word
            {
                temp->data=s1+' ';
                cout<<kk+1<<" th occurrence updated"<<endl;
                cout<<"updated text:"<<endl;
                        for(int j=0;j<undo.size();j++)       //traverse to print updated string after every occurrence of word found
                        {
                            if(j==i)
                            {
                                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);        //to highlight word
                                    SetConsoleTextAttribute(h,13);
                                    cout<<undo_temp->data;
                                    SetConsoleTextAttribute(h,7);
                            }
                            else
                                {
                                    cout<<undo_temp->data;
                                }
                                undo_temp=undo_temp->link;
                        }
                        cout<<endl;
                 kk++;
            }
            else                                //if user says not to update that occurrence than print stack without any updatation
            {
                cout<<kk+1<<" th occurrence not updated"<<endl;
                cout<<"updated text:"<<endl;
                        for(int j=0;j<undo.size();j++)
                        {
                            if(j==i)
                            {
                                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                                SetConsoleTextAttribute(h,13);
                                    cout<<undo_temp->data;
                                SetConsoleTextAttribute(h,7);

                            }
                            else
                                    cout<<undo_temp->data;
                                undo_temp=undo_temp->link;
                        }
                    cout<<endl;
            }
           j++;
        }
        temp=temp->link;
    }
    k[0]=kk;        // out of all occurrence use change how much
    k[1]=j;            // number of all occurrence
    return k;
}

void Text_Editor::search_string(string str )
{
    node *ptr=undo.begin();
    for(int i=0;i<undo.size();i++)
    {
        if(ptr->data==str+' ')
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,13);
            cout<<ptr->data;
            SetConsoleTextAttribute(h,7);
        }
        else
        {
            cout<<ptr->data;
        }
        ptr=ptr->link;
    }
}

void Text_Editor::print_undo_redo()
{
    string all="",redo_all="";
    node *undo_temp=undo.begin();
    cout<<"main text:"<<endl;
    for(int i=0;i<undo.size();i++)
    {
        cout<<undo_temp->data;
        undo_temp=undo_temp->link;
    }
    cout<<endl<<"                                        total words : "<<undo.size()<<endl;
}
