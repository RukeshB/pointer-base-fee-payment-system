#include<graphics.h>
#include<stdio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
int i=20;
char clsin[3];
class data
{
  public:
  char r[3],n[25],pn[20],cls[3],amt[20];
  d_add()
  {
     gotoxy(20,13);cout<<"Class:";
		    cin>>cls;
     gotoxy(20,14); cout<<"Roll no.:";
		    cin>>r;
     gotoxy(20,15); cout<<"Name:";
		    cin>>n;
     gotoxy(20,16); cout<<"Phone number:";
		    cin>>pn;
     gotoxy(20,17); cout<<"Total amount:";
		    cin>>amt;
     }
  list_h()
  {
    outtextxy(90,65,"Class");
    outtextxy(145,65,"Roll no.");
    outtextxy(225,65,"Name");
    outtextxy(345,65,"Phone number");
    outtextxy(470,65,"Totl Amount");
    setcolor(10); rectangle(2,58,597,73);
    setcolor(10);
    }
/*  d_list()
   {
      //	sprintf(a,"%d",s.cls); //accept int value convert into string
	   //	delay(500);
		outtextxy(90,110+i,d.cls);
		outtextxy(145,110+i,d.r);
		outtextxy(225,110+i,d.n);
		outtextxy(345,110+i,d.pn);
		outtextxy(470,110+i,d.amt);
		i=i+20;
	   //	n=1;
      }*/

  };

class mmenu
{
  data d;
  char c;
  fstream f;
  public:
  friend void menu();
  void title(char *);
  void add()
   {
     char t[]="ADD RECORDS";
     f.open("c:/student_cpp.txt",ios::app);
     if(f.fail())
      {
	cout<<"\n file can't open";
	}
     title(t);
     d.d_add();
     f.write((char*)(&d),sizeof(d));
     f.close();
     outtextxy(180,350,"Enter y if you want to add another record:");
     c=getche();
     if(c=='y'|| c=='Y')
      { add();
	}
     title(t);
     f.close();
     }


  void list()
   {
    int n=0;
     char t[]="LIST RECORDS";
   f.open("c:/student_cpp.txt",ios::in);
   if(f.fail())
      {
	cout<<"\n file can't open";
	}
   title(t);
   gotoxy(20,15); cout<<"Which Class record do you want to see:";
		  cin>>clsin;
   title(t);
   d.list_h();
   i=20;
	while(f.read((char*)(&d),sizeof(d))<0)
	{
	    if(strcmp(d.cls,clsin)==1)
	      {
		if(i>250)
		{
			outtextxy(180,370,"***Enter any key to continue***");
			getch();
			title(t);
			d.list_h();
			i=20;
		}
	    //  d.d_list();
		outtextxy(90,110+i,d.cls);
		outtextxy(145,110+i,d.r);
		outtextxy(225,110+i,d.n);
		outtextxy(345,110+i,d.pn);
		outtextxy(470,110+i,d.amt);
		i=i+20;
		n=1;
	     }
	  }
    if(n==0)
     {
      cout<<"data not found";
      }
    f.close();

     /*cleardevice();
     menu();
     setcolor(1);
     rectangle(75,25,147,45);
     rectangle(75,45,147,65);
     setfillstyle(1,7);
     floodfill(77,27,1);
     floodfill(77,47,1);
     setfillstyle(1,15);
     outtextxy(95,32,"Alpha");
     outtextxy(95,52,"acce");*/
     }
  void alpha()
  {
     char t[]="ALPHABATICAL LISTING";
     title(t);
     }
  void ace()
  {  char t[]="ASCENDING LISTING";
     title(t);
     }

  void edit()
  {
     char t[]="EDIT RECORDS";
     title(t);
    }
 };

 void mmenu::title(char *t)
   { cleardevice();
     setcolor(14);
     settextstyle(1,0,2);
     outtextxy(210,31,t);
     setcolor(14);
     settextstyle(12,0,1);
     rectangle(2,55,597,58);
     menu();
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
    outtextxy(460,12,"setting");
    outtextxy(545,12,"Exit");
    }

class mouse:public mmenu
{ private:
    union REGS in,out;
  public:
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
    else if(cl==1&& x>525&&y>5&&x<597&&y<25)
      {
	mousehide();
	cleardevice();
	outtextxy(170,230,"Thank you for useing this software");
	getch();
	exit(0);
       }
     if(cl==1&& x>75&&y>25&&x<147&&y<45)
      {
	alpha();
       }
     else if(cl==1&& x>75&&y>45&&x<147&&y<65)
      {
	ace();
       }
      }
    };
int main()
 {
   mouse m;
   int x,y,cl,a,b,n=1;
   int gd=DETECT,g;
   initgraph(&gd,&g,"c:\\tc\\bgi");
 //  a=100; b=400;
   menu();
   m.callmouse();
   //  while(!kbhit())
   while(n!=0)
    {
      m.click();
      /*   mouseposi(x,y,cl);
      gotoxy(2,455);
      printf("Mouse Position is (%d,%d)",x,y);   */
      }
   getch();
 }
