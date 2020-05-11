#include "iostream"
#include<conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
/*void gotoxy(int i,int j)
 { int o=0,p=0;
    for(;p<=j;p++)
      { cout<<"\n";
      }
    for(;o<=i;o++)
      {cout<<" ";
      }

  }*/
/*  void gotoxy(int x, int y)
{ printf("%c[%d;%df", 0x1B, y, x);
}  */

void delline()
{
    int i=0;
    while(i<200)
    {
        cout<<endl;
        i++;
    }
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
char password[100]; char  user_name[100], profile_name[100];
int main()
{     cout<<"Welcome! Enter the following details to create your account and start using the planner right away!"<<endl;
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
        delline();
        gotoxy(11,4);
        ch=_getch();

        //While loop to print '*' instead of text for password entry
        int i=0;
        while(ch!=13)
        {   if(ch!=8) {
            password[i]=ch;
            cout<<'*';
            ch=_getch();
            i++;
        }

        }

        delline();
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
         if(strcmp(password, temp_password)==0)
         {
             cout<<endl<<"PASSWORD NOT VERIFIED. ENTER AGAIN.";
             goto password_confirmation;
         }
        return 0;
}
