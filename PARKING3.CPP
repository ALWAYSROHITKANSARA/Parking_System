#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
class info
{
  char vehical_no[10],name[20],mobile_no[10],vehical_type[10];
  int hour;
  public :
//////////////////////////////////////////////////////////////////////
	   info()
	   {
	    hour=0;
	    strcpy(vehical_no,"");
	    strcpy(name,"");
	    strcpy(mobile_no,"");
	   }
void get_data();
void display();
void v_type();
};
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class parking
{
int spot[80];
char name[8];
info i[30];
public :
/////////////////////////////////////////////////////////////////////
	  parking (char a[8])
	   {
	   strcpy(name,a);
	    for(int i=0;i<=40;i++)
	    {
	     spot[i]=0;
	    }
	   }
////////////////////////////////////////////////////////////////////////
void border();
void sound1();
void sound2();
void login();
void welcome();
void menu();
void booking();
void hall();
void print();
void checkout();
void reset();
void big_car();
void vacancy();
};
////////////////////////////////////////////////////////////////////////
	 void parking::border()
	 {
	    clrscr();
	    for(int i=1;i<=79;i++)
	    {
	     gotoxy(i,1);
	     cprintf("%c",(char)176);
	     gotoxy(i,24);
	     cprintf("%c",(char)176);
	    }
	    for(i=1;i<=24;i++)
	    {
	     gotoxy(1,i);
	     cprintf("%c",(char)176);
	     gotoxy(79,i);
	     cprintf("%c",(char)176);
	    }
	 }
///////////////////////////////////////////////////////////////////////
	  void parking::sound1()
	   {
	    sound(500);
	    delay(100);
	    nosound();
	   }
////////////////////////////////////////////////////////////////////////
	   void parking::sound2()
	   {
	    for(int i=370;i<470;i+=10)
	    {
	     for(int j=i+100;j<800;j+=10)
	     {
	      sound(j);
	      delay(50);
	      nosound();
	      if(kbhit())
	      exit(0);
	     }
	    }
	   }
/////////////////////////////////////////////////////////////////////
	    void parking::login()
	    {
	     border();
	     char pin[4]="1234",u[4],uname[4],name[4]="aadi";
	     gotoxy(30,6);
	     textcolor(13);
	     cprintf("<<\"THE ROCK PARKING\">>"); sound1();
	     textcolor(15);
	     gotoxy(33,11);
	     cout<<"enter name : "; sound1();
	     cin>>uname; sound1();
	     gotoxy(33,12);
	     cout<<"enter pin : "; sound1();
	     for(int i=0;i<=3;i++)
	     {
	      u[i]=getch();
	      cout<<"*"; sound1();
	     }
	     for(i=0;i<=3;i++)
	     {
	      if (u[i]!=pin[i]||name[i]!=uname[i])
	      {
	       break;
	      }
	     }
	     gotoxy(32,20);
	     if (i==4)
	     {
	      cout<<"name and pin matched"; sound1();
	      welcome();
	     }
	     else
	     {
	     cout<<"name and pin not matched"; sound2();
	     getch();
	     }
	     }
//////////////////////////////////////////////////////////////////////
	    void parking::welcome()
	    {
	     border();
	     big_car();
	     gotoxy(35,6);
	     textcolor(13);
	     cprintf("<<\"THE ROCK PARKING\">>"); sound1();
	     gotoxy(35,20);
	     textcolor(15+BLINK);
	     cprintf("PRESS ANY KEY TO ENTER"); sound1();
	     getch();
	     textcolor(YELLOW);
	    }
//////////////////////////////////////////////////////////////////////////
	    void parking::menu()
	    {
	     border();
	     textcolor(YELLOW);
	     gotoxy(26,5);
	     cprintf("<<<<<\"THE ROCK PARKING\">>>>>"); sound1();
	     gotoxy(8,10);  cout<<"MENU"; sound1();
	     gotoxy(8,11);  cout<<"1.BOOKING"; sound1();
	     gotoxy(8,12);  cout<<"2.VACANCY"; sound1();
	     gotoxy(8,13);  cout<<"3.CHECKOUT"; sound1();
	     gotoxy(8,14);  cout<<"4.RESET"; sound1();
	     gotoxy(8,15);  cout<<"esc->EXIT"; sound1();
	     gotoxy(8,18);  cout<<"enter choice : ";
	    }
//////////////////////////////////////////////////////////////////////
	     void parking::booking()
	     {
	      int n;
	      print();
	      gotoxy(33,21);
	      cout<<" enter block no. : ";
	      cin>>n;
	      if(spot[n]==0)
	      {
	       i[n].get_data();
	       spot[n]=1;
	      }
	      else
	      {
	       cout<<" already booked!!! ";
	      }
	      cout<<"\nPARKING BOOKED!!!\n\n\n\n";
	      i[n].display();
	      getch();
	      print();
	      gotoxy(28,21); cout<<" press any key for menu ";
	      getch();
	     }
/////////////////////////////////////////////////////////////////////
	     void parking::hall()
	     {
	      char ch;
	      border();
	      big_car();
	      parking A("Hall A"),B("Hall B"),C("Hall C");
	      gotoxy(30,3); cout<<"<<<THE ROCK PARKING>>>";
	      gotoxy(40,5); cout<<"HALL";
	      gotoxy(41,6); cout<<"1.a";
	      gotoxy(41,7); cout<<"2.b";
	      gotoxy(41,8); cout<<"3.c";
	      gotoxy(41,12); cout<<"enter hall no. : ";
	     }
///////////////////////////////////////////////////////////////////////
	     void parking::print()
	     {
	      int i,j,k=0,l=0;
	      border();
	      gotoxy(26,3);
	      textcolor(10);
	      cprintf("<<<<<\"THE ROCK PARKING\">>>>>");
	      gotoxy(36,5);
	      cout<<name;
	      textcolor(10);
	      for(i=1;i<=40;i++)
	      {
	       if (spot[i]==0)
		{
		 textcolor(GREEN);
		}
		else
		{
		 textcolor(RED);
		}

		gotoxy(5+k,7+l);
		cprintf("<<%02d>>",i);
		k=k+9;
		if(i%8==0)
		{
		 k=0;
		 l=l+2;
		}
	     }
	     textcolor(3);
	     for(i=2;i<79;i++)
	     {
	      gotoxy(i,17); cout<<(char)15;
	      gotoxy(i,23); cout<<(char)15;
	      gotoxy(i,20); cout<<(char)205;
	     }
	     textcolor(3+BLINK);
	     gotoxy(3,20); cprintf("  entry  ");
	     gotoxy(71,20); cprintf("  exit  ");
	     textcolor(3);
	    }
/////////////////////////////////////////////////////////////////////
	      void parking::checkout()
	      {
		int n;
	      print();
	      gotoxy(33,21);
	      cout<<" enter block no. : ";
	      cin>>n;
	      if(spot[n]==1)
	      {
	       i[n].display();
	       getch();
	       spot[n]=0;
	       print();
	      }
	      else
	      {
	       print();
	       gotoxy(33,19);
	       cout<<" Oops no match found!!! ";
	      }
	      gotoxy(28,21); cout<<" press any key for menu ";
	      getch();
	     }

/////////////////////////////////////////////////////////////////////////
	     void parking::reset()
	     {
	     int i;
	     for(i=1;i<=24;i++)
	     {
	       if (spot[i]==1)
		{
		 spot[i]=0;
		}
	      }
	      print();
	      gotoxy(28,23); cout<<" PRESS ANY KEY FOR MENU ";
	      getch();
	     }
///////////////////////////////////////////////////////////////////////////
	     void parking::big_car()
	     {
	      for(int i=10;i<=22;i++)
		 {
		 gotoxy(i,3); cout<<(char)64;
		 }
		 for(i=10;i<=22;i++)
		 {
		   gotoxy(i,5); cout<<(char)205;
		 }
		 for(i=5;i<=27;i++)
		 {
		    gotoxy(i,7); cout<<(char)205;
		 }
		 gotoxy(16,4); cout<<(char)186;  gotoxy(16,6); cout<<(char)186;
		 gotoxy(9,4); cout<<(char)47;    gotoxy(23,4); cout<<(char)92;
		 gotoxy(8,5); cout<<(char)64;    gotoxy(24,5); cout<<(char)64;
		 gotoxy(7,5); cout<<(char)64;    gotoxy(25,5); cout<<(char)64;
		 gotoxy(6,5); cout<<(char)64;    gotoxy(26,5); cout<<(char)64;
		 gotoxy(5,5); cout<<(char)64;    gotoxy(27,5); cout<<(char)64;
		 gotoxy(5,6); cout<<(char)15;    gotoxy(27,6); cout<<(char)15;
		 gotoxy(5,7); cout<<(char)15;    gotoxy(27,7); cout<<(char)15;
		  for(i=9;i<12;i++)
		 {
		  gotoxy(i,8); cout<<(char)15;
		 }
		  for(i=21;i<24;i++)
		 {
		  gotoxy(i,8); cout<<(char)15;
		 }
		 gotoxy(9,7); cout<<(char)210;       gotoxy(21,7); cout<<(char)210;
		 gotoxy(11,7); cout<<(char)210;      gotoxy(23,7); cout<<(char)210;
	     }
///////////////////////////////////////////////////////////////
		void parking::vacancy()
		{
		 print();
		 int b=0,i,v=0;
		 for(i=1;i<=40;i++)
		 {
		 if(spot[i]==1)
		  {
		   b++;
		  }
		  else
		  {
		   v++;
		  }
		 }
		  gotoxy(15,21);
		  cout<<"BOOKED : "<<b;
		  gotoxy(50,21);
		  cout<<"VACANT : "<<v;
		  gotoxy(28,23);
		  cout<<"PRESS ANY KEY FOR MENU";
		 getch();
		}
/////////////////////////////////////////////////////////////////////////
  void info::get_data()
  {
   clrscr();
   gotoxy(30,5);
   cout<<"PELASE ENTER THESE DETAILS........";
   cout<<"\nNAME : "; cin>>name;
   cout<<"\nVECHICAL NO. : "; cin>>vehical_no;
   cout<<"\nMOBILE NO. : "; cin>>mobile_no;
   cout<<"\nHOURS : "; cin>>hour;
   v_type();
  }
///////////////////////////////////////////////////////////////////
  void info::display()
  {
   clrscr();
   gotoxy(30,5);
   cout<<"DETAILS........";
   cout<<"\nNAME : "<<name;
   cout<<"\nVECHICAL NO. : "<<vehical_no;
   cout<<"\nMOBILE NO. : "<<mobile_no;
   cout<<"\nHOURS : "<<hour;
   gotoxy(30,15); cout<<"\n\n\n\PRESS ANY KEY...";
  }
/////////////////////////////////////////////////////////////////////////
 void info :: v_type()
 {
  char ch;
  gotoxy(37,8);  cout<<"press 1 : car";
  gotoxy(37,9);  cout<<"press 2 : bike";
  gotoxy(37,10);  cout<<"press 3 : truck";
  gotoxy(37,11);  cout<<"press 4 : bus";
  gotoxy(37,12);  cout<<"enter your choice : "; cin>>ch;
  switch(ch)
  {
   case '1': gotoxy(37,10); cout<<"car"; break;
   case '2': gotoxy(37,10); cout<<"bike"; break;
   case '3': gotoxy(37,10); cout<<"truck"; break;
   case '4': gotoxy(37,10); cout<<"bus"; break;
   case 27 : return;
  }
 }
/////////////////////////////////////////////////////////////////////////
void main()
{
char ch;
_setcursortype(0);
parking A("Hall A"),B("Hall B"),C("Hall C");
A.login();
while(1)
{
A.menu();
ch=getche();
switch(ch)
{
 case '1':{
	   A.hall();
	   ch=getche();
	   switch(ch)
	   {
	    case '1': A.booking(); break;
	    case '2': B.booking(); break;
	    case '3': C.booking(); break;
	    case 27: return;
	   }
	  } break;
 case '2':{
	   A.hall();
	   ch=getche();
	   switch(ch)
	   {
	    case '1':A.vacancy(); break;
	    case '2':B.vacancy(); break;
	    case '3':C.vacancy(); break;
	    case 27: return;
	   }
	  } break;
 case '3':{
	   A.hall();
	   ch=getche();
	   switch(ch)
	   {
	   case '1':A.checkout(); break;
	   case '2':B.checkout(); break;
	   case '3':C.checkout(); break;
	   case 27: return;
	   }
	  } break;
 case '4':{
	   A.hall();
	   ch=getche();
	   switch(ch)
	   {
	   case '1':A.reset(); break;
	   case '2':B.reset(); break;
	   case '3':C.reset(); break;
	   case 27: return;
	   }
	  } break;
 case 27 : return;
 default : cout<<"  !!!invalid choice!!!";
}
}
}
