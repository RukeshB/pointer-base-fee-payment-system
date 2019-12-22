#include<graphics.h>
#include<string.h>
#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
union REGS in,out;
void menu();
int callmouse();
void mouseposi(int &,int &,int &);
int mousehide();
void title(char *);
void menu();
void click();
void password();
/*void add();
void list();
void alpha();
void ace();
void edit(); */

fstream f;
char cls[3],c,r[3],p[15],un[15];
float amt;
int n=0,i,k;


class data
{
  public:
  char r[3],fn[15],ln[15],pn[20],cls[3],p[15],un[15];
  float amt;
 // int i;
  get()
  {
     gotoxy(20,11); cout<<"Class:";
		      cin>>cls;
     gotoxy(20,13); cout<<"Roll no.:";
		      cin>>r;
     gotoxy(20,15); cout<<"First Name:";
		      cin>>fn;
     gotoxy(20,17); cout<<"Last Name:";
		      cin>>ln;
     gotoxy(20,19); cout<<"Phone number:";
		      cin>>pn;
     gotoxy(20,21); cout<<"Total amount:";
		      cin>>amt;
     }
  show_h()
  {
    outtextxy(15,65,"Class");      //63
    outtextxy(70,65,"Roll no.");
    outtextxy(151,65,"Fist Name");
    outtextxy(264,65,"Last Name");
    outtextxy(377,65,"Phone number");
    outtextxy(497,65,"Totl Amount");
    setcolor(9); line(2,75,597,75);
		 line(2,78,597,78);
    setcolor(10);
    }
  show()
   {            char a[20];
		outtextxy(15,65+i,cls);
		outtextxy(70,65+i,r);
		outtextxy(151,65+i,fn);
		outtextxy(264,65+i,ln);
		outtextxy(377,65+i,pn);
		sprintf(a,"%.2f",amt);
		outtextxy(497,65+i,a);
		i=i+15;
      }
  show2()
   {
     gotoxy(20,11); cout<<"Class:"<<cls;
     gotoxy(20,13); cout<<"Roll no.:"<<r;
     gotoxy(20,15); cout<<"First Name:"<<fn;
     gotoxy(20,17); cout<<"Last Name:"<<ln;
     gotoxy(20,19); cout<<"Phone number:"<<pn;
     gotoxy(20,21); cout<<"Total amount:"<<amt;
     }

   getpass()
   {
     for(i=0;i<15;i++)
       {p[i]=getch();
	n=p[i];
	if(n==13)    //13 is ASCII value of Enter
	break;       //to break loop when press Enter
       /*	if(n==27)    //27 is ASCII value of Esc
	menu();      //to go back to menu when press Esc
	 */
	else
	printf("*");
	}
     p[i]='\0';    //end the string
    }
   getun()
   {
     gotoxy(20,15); cout<<"User Name:";
		      cin>>un;
    /* gotoxy(20,17); cout<<"password:";
       for(i=0;i<15;i++)
       {p[i]=getch();
	n=p[i];
	if(n==13)    //13 is ASCII value of Enter
	break;       //to break loop when press Enter
	else
	printf("*");
	}
     p[i]='\0';    //end the string    */
    }
  }d,d1,d2,d3;


int callmouse()
 {
   in.x.ax=1;
   int86(51,&in,&out);
   return 1;
  }
void mouseposi(int &xpos,int &ypos,int &click)
 {
   in.x.ax=3;
   int86(51,&in,&out);
   click=out.x.bx;
   xpos=out.x.cx;
   ypos=out.x.dx;
  }
int mousehide()
 {
   in.x.ax=2;
   int86(51,&in,&out);
   return 1;
   }


void title(char *t)
 { cleardevice();
   setcolor(14);
   settextstyle(1,0,2);
   outtextxy(210,31,t);
   setcolor(14);
   settextstyle(12,0,1);
   rectangle(2,55,597,58);
   menu();
   }


void add()
 {
     char t[]="ADD RECORDS";
     f.open("c:/student.txt",ios::app);
     if(f.fail())
      {
	cout<<"\n file can't open";
	}
     title(t);
     d.get();
     f.write((char*)(&d),sizeof(d));
     f.close();
     outtextxy(120,440,"Enter y if you want to add another record:");
     c=getche();
     if(c=='y'|| c=='Y')
      { add();
	}
     title(t);
     outtextxy(190,250,"Data sucessful added");
     f.close();

  }
void list()
 {
  char t[]="LIST RECORDS";
   f.open("c:/student.txt",ios::in);
   if(f.fail())
      {
	cout<<"\n file can't open";
	}
   title(t);
   gotoxy(20,15); cout<<"Which Class record do you want to see:";
		  cin>>cls;
   title(t);
   d.show_h();
   i=20;
	while(f.read((char*)(&d),sizeof(d)))
	{
	    if(strcmp(d.cls,cls)==0)
	      {
		if(i>300)
		{
			outtextxy(140,440,"***Enter any key to continue***");
			getch();
			title(t);
			d.show_h();
			i=20;
		}
		d.show();
		n=1;
	     }
	  }
    if(n==0)
     {
      cout<<"data not found";
      }
    f.close();
  // char t[]="LIST RECORDS";
   //title(t);
  /* cleardevice();
   menu();
   setcolor(1);
   rectangle(75,25,147,45);
   rectangle(75,45,147,65);
   setfillstyle(1,7);
   floodfill(77,27,1);
   floodfill(77,47,1);
   setfillstyle(1,15);
   outtextxy(95,32,"Alpha");
   outtextxy(95,52,"acce");  */
   }

void alpha()
{  char t[]="ALPHABATICAL LISTING";
   title(t);
   }
void ace()
{  char t[]="ASCENDING LISTING";
   title(t);
   }

void edit()
 {
   char t[]="EDIT RECORDS";
   f.open("c:/student.txt",ios::in|ios::out);
   if(f.fail())
      {
	cout<<"\n file can't open";
	}
   title(t);
   gotoxy(20,10); cout<<"Enter data of student you want to modify:";
   gotoxy(20,12); cout<<"Class:";
		  cin>>cls;
   gotoxy(20,14); cout<<"Roll no.";
		  cin>>r;
   title(t);
    while(f.read((char*)&d,sizeof(d)))
       {
	 if(strcmp(cls,d.cls)==0 && strcmp(r,d.r)==0)
	   {
	      gotoxy(20,9); cout<<"old data:";
	      d.show2();
	      outtextxy(140,440,"***Enter any key to modify data***");
	      getch();
	      title(t);
	      f.seekg(0,ios::cur);
	      gotoxy(20,9); cout<<"Enter New Record:";
	      d.get();
	      f.seekp(f.tellg() - sizeof(d));
	      f.write((char*)&d,sizeof(d));
	      n=1;
	      outtextxy(190,440,"Modify sucessful......");
	       }
	 }
     if(n==0)
     {
      cout<<"data not found";
      }
    f.close();
   }

void search()
{
   char t[]="SEARCH RECORDS";
   f.open("c:/student.txt",ios::in|ios::out);
   if(f.fail())
      {
	cout<<"\n file can't open";
	}
   title(t);
   gotoxy(20,10); cout<<"Enter data of student you want to search:";
   gotoxy(20,12); cout<<"Class:";
		  cin>>cls;
   gotoxy(20,14); cout<<"Roll no.";
		  cin>>r;
   title(t);
    while(f.read((char*)&d,sizeof(d)))
       {
	 if(strcmp(cls,d.cls)==0 && strcmp(r,d.r)==0)
	   {
	      gotoxy(20,9); cout<<"Student Data:";
	      d.show2();
	      n=1;
	       }
	 }
     if(n==0)
     {
      cout<<"data not found";
      }
    f.close();
 }

void payment()
{
   char t[]="PAYMENT";
   f.open("c:/student.txt",ios::in|ios::out);
   if(f.fail())
      {
	cout<<"\n file can't open";
	}
   title(t);
   gotoxy(20,10); cout<<"Enter data of student:";
   gotoxy(20,12); cout<<"Class:";
		  cin>>cls;
   gotoxy(20,14); cout<<"Roll no.";
		  cin>>r;
   title(t);
    while(f.read((char*)&d,sizeof(d)))
       {
	 if(strcmp(cls,d.cls)==0 && strcmp(r,d.r)==0)
	   {
	      gotoxy(20,15); cout<<"current amount:"<<d.amt;
	      f.seekg(0,ios::cur);
	      gotoxy(20,17); cout<<"payment:";
			    cin>>amt;
		d.amt=d.amt-amt;
	      f.seekp(f.tellg() - sizeof(d));
	      f.write((char*)&d,sizeof(d));
	      n=1;
	      gotoxy(20,19); cout<<"Remaining amount:"<<d.amt;
	       }
	 }
     if(n==0)
     {
      cout<<"data not found";
      }
    f.close();
 }

void del()
{  ofstream f1;
   char t[]="DELEAT";
   f.open("c:/student.txt",ios::in);
   f1.open("c:/new.txt",ios::out);
   if(f.fail())
      {
	cout<<"\n file can't open";
	}
   title(t);
   gotoxy(20,10); cout<<"Enter data of student:";
   gotoxy(20,12); cout<<"Class:";
		  cin>>cls;
   gotoxy(20,14); cout<<"Roll no.:";
		  cin>>r;
   title(t);
    while(f.read((char*)&d,sizeof(d)))
       {
	 if(strcmp(cls,d.cls)==0 && strcmp(r,d.r)==0)
	 {
	    n=1;
	    }
	 if(strcmp(cls,d.cls)!=0 && strcmp(r,d.r)!=0)
	  {
	    f1.write((char*)&d,sizeof(d));
	    }
	 }
    if(n==0)
     {
      cout<<"data not found";
      }
	f1.close();
	f.close();
	remove("student.txt");
	rename("new.txt","student.txt");
 }

void setting()
{
  char t[]="   SETTING";
  f.open("c:/pass.txt",ios::in|ios::out);
  if(f.fail())
      {
	cout<<"\n file can't open";
	}
   title(t);
    d1.getun();
    gotoxy(20,17); cout<<"New Password:";
    d1.getpass();
    gotoxy(20,19); cout<<"Conform Password:";
    d2.getpass();
    f.write((char*)&d,sizeof(d));
    gotoxy(20,21); cout<<"Old password:";
    d3.getpass();
     while(f.read((char*)&d,sizeof(d)))
       {
	 if(strcmp(d.p,d3.p)==0 && strcmp(d1.p,d2.p)==0)
	   {
	    f.write((char*)&d,sizeof(d));
	    outtextxy(100,440,"---------Password changed Successfully---------");
	     }
	 else
	   {
	  title(t);
	  outtextxy(180,220," ***Wrong password***");
	  outtextxy(180,440,"  Enter Esc if you want to go to back:");
	  k=getch();
	  if(k==27)
	  {
	   menu();
	   }
	  else
	  {
	   setting();
	   }
	  }
	 }
   f.close();
  // outtextxy(100,440,"---------Password changed Successfully---------");
  // cout<<"---------Password changed Successfully---------";
 }


void password()
{
   fstream f1,f2;
   int k;
   char t[]="PASSWORD";
   f1.open("c:/pass.txt",ios::in);
   cleardevice();
   rectangle(140,212,400,282);

   if(f1.fail())
      {
	char pw[]={'a','d','m','i','n'};
	f2.open("c:/pass.txt",ios::out);
     //	d.un[]={'a','d','m','i','n','\0'};
     //	d.p[]={'a','d','m','i','n','\0'};
	strcpy(d.un,pw);
	strcpy(d.p,pw);
	f2.write((char*)&d,sizeof(d));
	f2.close();
	password();
	}
    d1.getun();
    gotoxy(20,17); cout<<"Password:";
    d1.getpass();
 /* gotoxy(40,15); cout<<"User Name:";
		      cin>>un;
  gotoxy(40,17); cout<<"password:";
       for(i=0;i<15;i++)
       {p[i]=getch();
	n=p[i];
	if(n==13)    //13 is ASCII value of Enter
	break;       //to break loop when press Enter
	else
	printf("*");
	}
     p[i]='\0';    //end the string   */
   while(f1.read((char*)&d,sizeof(d)))
       {
	 if(strcmp(d1.un,d.un)!=0 && strcmp(d1.p,d.p)!=0)
	 {
	  cleardevice();
	  setcolor(12);
	  outtextxy(180,220," ***Wrong username or password***");
	  outtextxy(180,440,"  Enter Esc if you want to exit:");
	  k=getch();
	  if(k==27)
	  {
	   exit(0);
	   }
	   password();
	  }
     }
   cleardevice();
   f1.close();
  }

void menu()
 { int i,j=2;
   //cleardevice();
   setcolor(14);
  // rectangle(2,5,597,25);
   rectangle(2,30,597,460);
   for(i=72;i<=597;i=j+72)
   {
     setfillstyle(1,1);
     setcolor(9);
     rectangle(j,5,i,25);
     floodfill(j+1,20,9);
     j=i+3;
     }
   setcolor(15);
   outtextxy(22,12,"Add");
   outtextxy(95,12,"List");
   outtextxy(170,12,"Edit");
   outtextxy(235,12,"Search");
   outtextxy(310,12,"Payment");
   outtextxy(385,12,"Delete");
   outtextxy(460,12,"setting");
   outtextxy(545,12,"Exit");
   }
void click()
 {
   int x,y,cl;
   setcolor(15);

   mouseposi(x,y,cl);
   if(cl==1&& x>2&&y>5&&x<72&&y<25)
     {
	add();
      }
   else if(cl==1&& x>75&&y>5&&x<147&&y<25)
     {
	list();
      }
   else if(cl==1&& x>150&&y>5&&x<222&&y<25)
     {
	edit();
      }
   else if(cl==1&& x>225&&y>5&&x<297&&y<25)
     {
      search();
      }
   else if(cl==1&& x>230&&y>5&&x<372&&y<25)
     {
      payment();
      }
   else if(cl==1&& x>375&&y>5&&x<447&&y<25)
     {
      del();
      }
   else if(cl==1&& x>450&&y>5&&x<522&&y<25)
     {
      setting();
      }
   else if(cl==1&& x>525&&y>5&&x<597&&y<25)
     {
	mousehide();
	cleardevice();
	outtextxy(170,230,"Thank you for useing this software");
	getch();
	exit(0);
      }
/*   else if(cl==1&& x>75&&y>25&&x<147&&y<45)
     {
	alpha();
      }
   else if(cl==1&& x>75&&y>45&&x<147&&y<65)
     {
	ace();
      }    */
     }
void main()
 {
   int x,y,cl,a,b,n=1;
   int g=DETECT,m;
   initgraph(&g,&m,"c:\\TC\\bgi");
  // a=100;
  // b=400;
   password();
   menu();
   callmouse();
   //  while(!kbhit())
   while(1)
    {
      click();
      /*   mouseposi(x,y,cl);
      gotoxy(2,455);
      printf("Mouse Position is (%d,%d)",x,y);   */
      }
   getch();
 }
