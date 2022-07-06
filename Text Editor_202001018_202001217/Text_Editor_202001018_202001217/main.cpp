#include <iostream>
#include "Text_Editor.h"
using namespace std;

int main()
{
    int chk;
    int *a;
    Text_Editor yz;
    //instructions
        cout<<"How to use TEXT EDITOR"<<endl<<endl;
        cout<<"i) Enter string you like to add ....\n\n";
        cout<<"ii) If you want to do UNDO process enter sign of ' - ' \n\n";
        cout<<"iii) If you want to do REDO process enter sign of ' + ' \n\n";
        cout<<"iv)  If you want to do FIND AND REPLACE process enter sign of ' / ' \n\n ";
        cout<<"      For multiple word replacement EDITOR will ask you which word you want to replace which not ....\n\n";
        cout<<"v) If you want to search any string /word enter sign of ' ? ' \n\n\n";

        cout<<"There is also another command for change font color of whole screen in-between using command :: fc_color (enter yellow , red ..in space of color\n";
        cout<<"       Enter fc_default to come back to default font color\n\n";
        cout<<"EDITOR will also display number of total word on right bottom corner of screen \n\n\n";
        cout<<"Enter exit(0) to exit program\n\n\n";
        cout<<"Let's start with first word :: ";

 string s;
    while(1)
    {
           cin>>s;

        if(s[0]=='-')
        {
            yz.undo_text();
        }
        else if(s[0]=='+')
        {
            chk=yz.redo_text();    // if chk =-1 means nothing to redo
        }
        else if(s[0]=='/')
        {
            cout<<"Find what ::";
            string str;
            cin>>str;
             a=yz.select_replace(str);   // a is pointer to array that has value how many occurrence user changed and how many total occurrence are there
        }
        else if(s[0]=='?')
        {
            cout<<"Find what ::";
            string str;
            cin>>str;
            yz.search_string(str);
        }
        else if(s=="fc_red")       // not part of DS only change font color using code like 4 for red,6 for yellow,etc...
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,4);
        }
        else if(s=="fc_yellow")
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,6);
        }
        else if(s=="fc_green")
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,2);
        }
        else if(s=="fc_blue")
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,1);
        }
        else if(s=="fc_default")
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,7);
        }
        else if(s=="exit(0)")
        {
            exit(0);
        }
        else
        {
            yz.push(s);            //if no other command given like undo,redo ,.. than it will add input string to main text
        }
        if(s[0]=='/')
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,4);
            cout<<endl<<endl<<*a<<" out of total "<<*(a+1)<<" occurrence updated"<<endl<<endl;
            SetConsoleTextAttribute(h,7);
        }
        else if(s[0]=='?')
        {
            cout<<endl;
        }
        else
        {
            system("CLS");
        }
        cout<<"                            Text Editor  \n\n\n";
        if(chk==-1)
        {
            cout<<"nothing to redo\n\n";
            chk=0;
        }
        cout<<endl<<"--------------------------------------------------------"<<endl;
        yz.print_undo_redo();
        cout<<endl<<"--------------------------------------------------------"<<endl;
    }
    return 0;
}
