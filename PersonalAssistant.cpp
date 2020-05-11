/*USE THIS INDEX TO FIND WHAT YOU ARE LOOKING FOR*/





//All potentially required header files
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

using namespace std;

//Global function for moving cursor to (x,y) position
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

//Defining the class for creating an account
class admin_account
{
    public:
    //Declaring the data members of the class
    char user_name[100];
    char password[11];
    char profile_name[100];

    //Defining the methods for accessing and operating on the data members of this class
    void create_account()
    {
        cout<<"Welcome! Enter the following details to create your account and start using the planner right away!"<<endl;
        cout<<endl<<"USER NAME: "<<endl;
        cout<<"PROFILE NAME: "<<endl;
        cout<<"PASSWORD: "<<endl;
        cout<<"CONFIRM PASSWORD: "<<endl;

        char temp_password[100]; char ch;

        gotoxy(11,2);
        gets(user_name);
        gotoxy(14,3);
        gets(profile_name);

        password_confirmation:

        gotoxy(11,4);
        ch=_getch();

        //While loop to print '*' instead of text for password entry
        int i=0;
        while(ch!=13)
        {
            password[i]=ch;
            cout<<'*';
            ch=_getch();
            i++;
        }

        gotoxy(18,5);
        ch=_getch();
        int j=0;
        while(ch!=13)
        {
            temp_password[j]=ch;
            cout<<'*';
            ch=_getch();
            j++;
        }

         if(strcmp(password, temp_password)!=0)
         {
             cout<<endl<<"PASSWORD NOT VERIFIED. ENTER AGAIN.";
             goto password_confirmation;
         }

    }
};





int main()
{
    int ch=1;
    while(ch==1)
    {
        cout<<"Testing. Continue?"<<endl;
        cin>>ch;
    }
    return  1;
}
