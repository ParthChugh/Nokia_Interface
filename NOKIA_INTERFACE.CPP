#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include<string.h>
struct emp
{
   char name[10];
   char a[10];
}e;
void display();
void timer();
void menu(void);
void contacts();
void back();
void inbox1();
void compcontact();
void message();
void menu1(void);
void inbox();
void sms();
void Rcalls(void);
void calls();
void calling();
void box()
{
	printf("\n");
	gotoxy(5,5);
	printf("2 FOR UP KEY");
	gotoxy(5,6);
	printf("8 FOR DOWN KEY");
	gotoxy(5,7);
	printf("1 FOR BACK KEY");
	gotoxy(5,8);
	printf("5 FOR SELECTION");
	void line(int);
	void line1(int);
	line(8);
	line(24);
	line1(30);
	line1(45);
	gotoxy(30,8);
	printf("É");
	gotoxy(30,24);
	printf("È");
	gotoxy(45,8);
	printf("»");
	gotoxy(45,24);
	printf("¼");
	gotoxy(41,23);
	printf("Back");

}
void line(int y)
{
	int i;
	for(i=30;i<45;i++)
	{
		gotoxy(i,y);
		printf("Í");
	}

}

void line1(int x)
{
	int i;
	for(i=8;i<24;i++)
	{
		gotoxy(x,i);
		printf("º");
	}
}

void main()
	{
	   TOP:
	   textbackground(BLACK);
	   textcolor(WHITE);
	   clrscr();
	   box();
	  // gotoxy(32,16);
	  // printf("MENU");
	   int k=12;
	   int c;
	   char ch;
	  //  menu();
	  while(1)
	{
	   menu();
	   textbackground(RED);
	   switch(k)
	   {
	      case 12 :
			 gotoxy(32,12);
			 cprintf("SMS");
			 c=1;
			 break;
	      case 14 :
			 gotoxy(32,14);
			 cprintf("CALLS");
			 c=2;
			 break;
	      case 16 :
			 gotoxy(32,16);
			cprintf("CONTACTS");
			c=3;
			break;
	      case 18 :
			gotoxy(32,18);
			cprintf("NEW CONTACT");
			c=4;
			break;
	      case 20 :
			gotoxy(32,20);
			cprintf("TIME AND DATE");
			c=5;
	   }
	     ch=getch();
	     if(ch=='2')
	      {
		k+=2;
	      }
	     if(ch=='8')
	     {
	       k-=2;

	     }
	     if(ch=='5')
	     {
	       goto end;
	     }
	     if(k<12)
	       k=12;
	     if(k>20)
	       k=20;
	}

       end:
       switch(c)
       {
       case 1:
	sms();
	break;
       case 2:
	Rcalls();
	break;
       case 3:
       char m;
       contacts();
       kk:m=getch();
       if(m=='1')
       {
       goto TOP;
       }
       else
       goto kk;
	break;
	case 4:
	compcontact();
	goto TOP;
	break;
	case 5:
	int g;
	timer();
	g=getch();
	if(g=='1')
	{
	goto TOP;
	}
       }
       getch();

	}
void menu()
{
	   textbackground(BLACK);
	   textcolor(WHITE);
	   clrscr();
	   box();
		gotoxy(36,10);
		cprintf("Menu");
		gotoxy(32,12);
		cprintf("SMS");
		gotoxy(32,14);
		cprintf("CALLS");
		gotoxy(32,16);
		cprintf("CONTACTS");
		gotoxy(32,18);
		cprintf("NEW CONTACT");
		gotoxy(32,20);
		cprintf("TIME AND DATE");

	}
void compcontact()
{
textbackground(BLACK);
textcolor(WHITE);
clrscr();
box();
gotoxy(32,9);
printf("New Contact");
gotoxy(32,10);
printf("Enter Name\n");
gotoxy(32,13);
printf("Phone Number");

FILE *p;

   p = fopen("on5.txt", "a");
   gotoxy(32,11);
   scanf("%s", e.name);
   gotoxy(32,14);
   scanf("%s",e.a);
   fprintf(p,"%s\n%s\n", e.name , e.a);
   fclose(p);
   textbackground(BLACK);
   textcolor(WHITE);
   clrscr();
   box();
   gotoxy(32,15);
    printf("Contact Saved");
   getch();
  }
void display()
{
char ch,ch1;
int i=0;
textbackground(BLACK);
textcolor(WHITE);
clrscr();
box();
gotoxy(33,9);
printf("CONTACTS");
FILE *q;
  q = fopen("on5.txt", "r");
      while(!feof(q))
      {
      fscanf(q,"%s\n%s\n", e.name,&e.a);
      gotoxy(34,11+2*i);
      printf("%s",e.name);
      gotoxy(32,12+2*i);
      printf("%s",e.a);
      i++;
      }
}
void contacts()
{

textbackground(BLACK);
textcolor(WHITE);
clrscr();
box();
display();
}
void Rcalls()
{
	int cf;
       int c,k=12;
	char ch;
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	box();
	while(1)
	{
	   calls();
	   textbackground(YELLOW);
	   switch(k)
	   {
	      case 12 :
			 gotoxy(32,12);
			 cprintf("8149404001");
			 c=1;
			 break;
	      case 14 :
			 gotoxy(32,14);
			 cprintf("8875317243");
			 c=2;
			 break;
	      case 16 :
			 gotoxy(32,16);
			cprintf("9828831361");
			c=3;
			break;
	   }
	     ch=getch();
	     if(ch=='2')
	      {
		k+=2;
	      }
	     if(ch=='8')
	     {
	       k-=2;
	     }
	     if(ch=='5')
	     {
	       goto end;
	     }
	     if(ch=='1')
	     {
	     main();
	     }
	     if(k<12)
	       k=12;
	     if(k>16)
	       k=16;
	}
     end:
     if(c>0)
     {
	calling();
     }
}
void calling()
{
     int cf;
     textbackground(BLACK);
     textcolor(WHITE);
     clrscr();
     box();
     int h,m,s,t;
     h=0;
     s=0;
     m=0;
       while(!kbhit())
       {
     if(s>59) {m=m+1; s=0; }
      if(m>59) { h=h+1; m=0; }
      if(h>24) { h=0; m=0; s=0; }
      delay(1000);
      s=s+1;
      gotoxy(32,10);
      printf("CALLING");
      gotoxy(32,16);
      printf("%d:%d:%d",h,m,s);
	}
	cf=getch();
	if(cf=='1')
	{
	main();
	}
}
void calls()
{

		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(32,10);
		cprintf("Recived Calls");
		gotoxy(32,12);
		cprintf("8149404001");
		gotoxy(32,14);
		cprintf("8875317243");
		gotoxy(32,16);
		cprintf("9828831361");
}
void sms()
{
	int c,k=12;
	char ch;
	textbackground(BLACK);
	textcolor(WHITE);
	box();
	clrscr();
	   box();
	  while(1)
	{
	   inbox();
	   textbackground(GREEN);
	   switch(k)
	   {
	      case 12 :
			 gotoxy(32,12);
			 cprintf("Inbox");
			 c=1;
			 break;
	      case 14 :
			 gotoxy(32,14);
			 cprintf("Outbox");
			 c=2;
			 break;
	      case 16 :
			 gotoxy(32,16);
			cprintf("Compose sms");
			c=3;
			break;


	   }
	     ch=getch();
	     if(ch=='2')
	      {
		k+=2;
	      }
	     if(ch=='8')
	     {
	       k-=2;
	     }
	     if(ch=='5')
	     {
	       goto end;
	     }
	     if(ch=='1')
	     {
	     main();
	     }
	     if(k<12)
	       k=12;
	     if(k>16)
	       k=16;
	}
     end:
     switch(c)
     {
     case 1:
      message();
     break;
     case 2:
     break;
     }
  }
void inbox()
{
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(36,10);
		cprintf("SMS");
		gotoxy(32,12);
		cprintf("Inbox");
		gotoxy(32,14);
		cprintf("Outbox");
		gotoxy(32,16);
		cprintf("Compose sms");
}
void inbox1()
{
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(36,10);
		cprintf("Inbox");
		gotoxy(32,12);
		cprintf("VR-00001");
		gotoxy(32,14);
		cprintf("VR-00002");
		gotoxy(32,16);
		cprintf("VR-00003");
}
void message()
{
	int c,k=12;
	char ch;
	textbackground(BLACK);
	textcolor(WHITE);
	box();
	clrscr();
	   box();
	  while(1)
	{
	   top5:textbackground(BLACK);
	   textcolor(WHITE);
	   box();
	   clrscr();
	   box();
	   inbox1();
	   textbackground(GREEN);
	   switch(k)
	   {
	      case 12 :
			 gotoxy(32,12);
			 cprintf("VR-00001");
			 c=1;
			 break;
	      case 14 :
			 gotoxy(32,14);
			 cprintf("VR-00002");
			 c=2;
			 break;
	      case 16 :
			 gotoxy(32,16);
			 cprintf("VR-00003");
			 c=3;
			 break;
	   }
	     ch=getch();
	     if(ch=='2')
	      {
		k+=2;
	      }
	     if(ch=='8')
	     {
	       k-=2;
	     }
	     if(ch=='5')
	     {
	       goto end;
	     }
	     if(ch=='1')
	     {
	     sms();
	     }
	     if(k<12)
	       k=12;
	     if(k>16)
	       k=16;
	}
     end:
     switch(c)
     {
     case 1:
	char j;
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	box();
	gotoxy(34,10);
	printf("VR-00001");
	gotoxy(32,12);
	printf("HELLO BROTHER");
	j=getch();
	if(j=='1')
	{
	goto top5;
	}
	break;
     case 2:
	int j1;
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	box();
	gotoxy(34,10);
	printf("VR-00002");
	gotoxy(31,12);
	printf("Saryu Chugh");
	j1=getch();
	if(j1=='1')
	{
	goto top5;
	}
	break;
     case 3:
     int j2;
     textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	box();
	gotoxy(34,10);
	printf("VR-00003");
	gotoxy(31,12);
	printf("Saryu");
	j2=getch();
	if(j2=='1')
	{
	goto top5;
	}
	break;
     }
}
void back()
{

}
void timer()
{
     textbackground(BLACK);
     textcolor(WHITE);
     clrscr();
     box();
     struct tm *timeinfo;
     int h,m,s,i,d,mon,y;
     time_t rawtime;
     time(&rawtime);
     timeinfo = localtime(&rawtime);
     h=timeinfo->tm_hour;
     s= timeinfo->tm_sec;
     m= timeinfo->tm_min;

       while(!kbhit())
       {
     if(s>59) {m=m+1; s=0; }
      if(m>59) { h=h+1; m=0; }
      if(h>24) { h=0; m=0; s=0; }
      delay(1000);
      s=s+1;
				    // clrscr();
      gotoxy(32,10);
      printf("TIME");
      gotoxy(32,12);
      printf("%d:%d:%d",h,m,s);
      d=timeinfo->tm_mday;
      mon= timeinfo->tm_mon+1;
      y= timeinfo->tm_year;
      gotoxy(32,14);
      printf("DATE");
      gotoxy(32,16);
      printf("%d/%d/%d",d,mon,y+1900);

}
}