#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include<string.h>
struct ent1
{
  char g1[10];
  char g2[10];
  char g3[10];
  char g4[10];
  char g5[10];
}as;
struct emp1
{
   char name[10];
   char a[10];
}b;
void mainmenua();
void linea(int);
void line1aa(int);
void displaya();
void timera();
void menua(void);
void contactsa();
void outba();
void inboxa1a();
void compcontactsa();
void messagea();
void menu1a(void);
void inboxa();
void in();
void into();
void smsa();
void rcallsa(void);
void callsa();
void callinga();
void takea();
void callmea();
void boxa()
{
	printf("\n");
	gotoxy(31,4);
	printf("NOKIA INTERFACE");
	gotoxy(5,5);
	printf("2 FOR UP KEY");
	gotoxy(5,6);
	printf("8 FOR DOWN KEY");
	gotoxy(5,7);
	printf("1 FOR BACK KEY");
	gotoxy(5,8);
	printf("5 FOR SELECTION");
	linea(8);
	linea(24);
	line1aa(30);
	line1aa(45);
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
void linea(int y)
{
	int i;
	for(i=30;i<45;i++)
	{
		gotoxy(i,y);
		printf("Í");
	}

}

void line1aa(int x)
{
	int i;
	for(i=8;i<24;i++)
	{
		gotoxy(x,i);
		printf("º");
	}
}

void maina()
	{
	   int l;
	   struct tm *timeinfo;
	   int h,m1,s,i,d,mon,y;
	   time_t rawtime;
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	boxa();
	gotoxy(41,23);
	printf("    ");
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	h=timeinfo->tm_hour;
	s= timeinfo->tm_sec;
	m1= timeinfo->tm_min;

       while(!kbhit())
       {
     if(s>59) {m1=m1+1; s=0; }
      if(m1>59) { h=h+1; m1=0; }
      if(h>24) { h=0; m1=0; s=0; }
      delay(1000);
      s=s+1;				    // clrscr();
      gotoxy(36,10);
      printf("TIME");
      gotoxy(34,12);
      printf("%d:%d:%d",h,m1,s);
      d=timeinfo->tm_mday;
      mon= timeinfo->tm_mon+1;
      y= timeinfo->tm_year;
      gotoxy(36,14);
      printf("DATE");
      gotoxy(33,16);
      printf("%d/%d/%d",d,mon,y+1900);
      }
	 l= getch();
	  if(l=='3')
	  {
	  exit(0);
	  }
	  else if(l=='1')
	  {
	  switch(1)
	  {
	  break;
	  }

	  }
	  else
	  {mainmenua();
	  }
	}
	void mainmenua()
	{
	int g;
	   char m;
	   int k=12;
	   int c;
	   char ch;
	TOP: textbackground(BLACK);
	   textcolor(WHITE);
	   clrscr();
	   boxa();
	  while(1)
	{
	   menua();
	   textbackground(RED);
	   switch(k)
	   {
	      case 12 :
			 gotoxy(32,12);
			 cprintf("sms");
			 c=1;
			 break;
	      case 14 :
			 gotoxy(32,14);
			 cprintf("calls");
			 c=2;
			 break;
	      case 16 :
			 gotoxy(32,16);
			cprintf("contacts");
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
	     if(ch=='1'|| ch=='3')
	     {
	     maina();
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
	smsa();
	break;
       case 2:
	rcallsa();
	break;
       case 3:
       contactsa();
       kk:m=getch();
       if(m=='1')
       {
       goto TOP;
       }
       else
       goto kk;
	break;
	case 4:
	compcontactsa();
	goto TOP;
	break;
	case 5:
	timera();
	g=getch();
	if(g=='1')
	{
	goto TOP;
	}
       }
       getch();
	}
void menua()
{
	   textbackground(BLACK);
	   textcolor(WHITE);
	   clrscr();
	   boxa();
		gotoxy(36,10);
		cprintf("menu");
		gotoxy(32,12);
		cprintf("sms");
		gotoxy(32,14);
		cprintf("calls");
		gotoxy(32,16);
		cprintf("contacts");
		gotoxy(32,18);
		cprintf("NEW CONTACT");
		gotoxy(32,20);
		cprintf("TIME AND DATE");
	}
void compcontactsa()
{
FILE *p;
textbackground(BLACK);
textcolor(WHITE);
clrscr();
boxa();
gotoxy(32,9);
printf("New Contact");
gotoxy(32,10);
printf("Enter Name\n");
gotoxy(32,13);
printf("Phone Number");
   p = fopen("on2.txt", "a");
   gotoxy(32,11);
   scanf("%s", b.name);
   gotoxy(32,14);
   scanf("%s",b.a);
   fprintf(p,"%s\n%s\n", b.name , b.a);
   fclose(p);
   textbackground(BLACK);
   textcolor(WHITE);
   clrscr();
   boxa();
   gotoxy(32,15);
    printf("Contact Saved");
   getch();
  }
void displaya()
{
char ch,ch1;
int i=0,c=-1;
FILE *q;
textbackground(BLACK);
textcolor(WHITE);
clrscr();
boxa();
gotoxy(33,9);
printf("contacts");
  q = fopen("on2.txt", "r");
      while(!feof(q) && c<3)
      {
      c++;
      fscanf(q,"%s\n%s\n", b.name,&b.a);
      gotoxy(34,11+2*i);
      printf("%s",b.name);
      gotoxy(32,12+2*i);
      printf("%s",b.a);
      i++;
      }
}
void contactsa()
{
textbackground(BLACK);
textcolor(WHITE);
clrscr();
boxa();
displaya();
takea();
}
void rcallsa()
{
	int cf;
       int c,k=12;
	char ch;
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	boxa();
	while(1)
	{
	   callsa();
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
	     mainmenua();
	     }
	     if(k<12)
	       k=12;
	     if(k>16)
	       k=16;
	}
     end:
     if(c>0)
     {
	callinga(NULL);
     }
}
void callinga(int x[])
{
     int cf;
     int h,m,s,t;
     textbackground(BLACK);
     textcolor(WHITE);
     clrscr();
     boxa();
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
      printf("NOW CALLING :");
      gotoxy(36,11);
      puts(x);
      gotoxy(34,16);
      printf("%d:%d:%d",h,m,s);
	}
	cf=getch();
	if(cf=='1')
	{
	maina();
	}
}
void callsa()
{
	     textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(32,10);
		cprintf("Recived calls");
		gotoxy(32,12);
		cprintf("8149404001");
		gotoxy(32,14);
		cprintf("8875317243");
		gotoxy(32,16);
		cprintf("9828831361");
}
void smsa()
{
	int c,k=12;
	char ch;
	textbackground(BLACK);
	textcolor(WHITE);
	boxa();
	clrscr();
	   boxa();
	  while(1)
	{
	   inboxa();
	   textbackground(GREEN);
	   switch(k)
	   {
	      case 12 :
			 gotoxy(32,12);
			 cprintf("inbox");
			 c=1;
			 break;
	      case 14 :
			 gotoxy(32,14);
			 cprintf("outbox");
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
	     mainmenua();
	     }
	     if(ch=='3')
	     {
	     maina();
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
     in();
     break;
     case 2:
     inboxa1a();
     break;
     case 3:
     messagea();
     break;
     }
  }
  void in()
  {
char ch,ch1;
int i=0,c=-1;
char v=65;
FILE *q;
textbackground(BLACK);
textcolor(WHITE);
clrscr();
boxa();
gotoxy(33,9);
printf("INBOX");

  q = fopen("from1.txt", "r");
      while(!feof(q) )
      {
      c++;
      fscanf(q,"%s\n", as.g1);
      gotoxy(32,12+i);
      if(c%5==0)
      {
      printf("%c.> %s",v,as.g1);
      i=i+2;
      v++;
      }
      }
      ch=getch();
      if(ch=='1')
      {
      smsa();
      }
      else if(ch=='3')
      {
      maina();
      }
      else
      into(ch);

  }
  void into(int ch)
  {

  FILE *q;
  int i=0,j,k,c=0,a;
  textbackground(BLACK);
		textcolor(WHITE);
		clrscr();
		boxa();
  if(ch>=65 && ch<95)
     ch=ch-64;
  if(ch>=97)
     ch=ch-96;
  k=5*(int)ch;
  j=k-5;
  gotoxy(33,9);
  printf("From:Phone 1");
  q = fopen("from1.txt", "r");
      while(!feof(q))
      {
       fscanf(q,"%s\n", as.g1);
       if(c>=j && c<k)
       {
		gotoxy(32,12+i);
		printf("%s\n",as.g1);
		i++;
	}
	  c++;
       }
       a=getch();
       if(a=='1')
       {
       in();
       }
       else if(a=='3')
       {
       maina();
       }
      else
      {
       inboxa();
      }

}


void inboxa()
{
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(36,10);
		cprintf("sms");
		gotoxy(32,12);
		cprintf("inbox");
		gotoxy(32,14);
		cprintf("outbox");
		gotoxy(32,16);
		cprintf("Compose sms");
}
void inboxa1a()
{
char ch,ch1;
int i=0,c=-1;
char v=65;
FILE *q;
textbackground(BLACK);
textcolor(WHITE);
clrscr();
boxa();
gotoxy(33,9);
printf("outbox");

  q = fopen("from2.txt", "r");
      while(!feof(q) )
      {
      c++;
      fscanf(q,"%s\n", as.g1);
      gotoxy(32,12+i);
      if(c%5==0)
      {
      printf("%c.> %s",v,as.g1);
      i=i+2;
      v++;
      }
      }
      ch=getch();
      if(ch=='1')
      {
      smsa();
      }
      else if(ch=='3')
      {
      maina();
      }
      else
      outba(ch);
      }
void outba(char ch)
{
  FILE *q;
  int i=0,j,k,c=0,a;
  textbackground(BLACK);
		textcolor(WHITE);
		clrscr();
		boxa();
  if(ch>=65 && ch<95)
     ch=ch-64;
  if(ch>=97)
     ch=ch-96;
  k=5*(int)ch;
  j=k-5;
  gotoxy(33,9);
  printf("To:Phone 2");
  q = fopen("from2.txt", "r");
      while(!feof(q))
      {
       fscanf(q,"%s\n", as.g1);
       if(c>=j && c<k)
       {
		gotoxy(32,12+i);
		printf("%s\n",as.g1);
		i++;
	}
	  c++;
       }
       a=getch();
       if(a=='1')
       {
       inboxa1a();
       }
       else if(a=='3')
       {
       maina();
       }
      else
      {
       inboxa();
      }

}
void messagea()
{
   FILE *p;
   textbackground(BLACK);
   textcolor(WHITE);
   clrscr();
   boxa();
   p = fopen("from2.txt", "a");
   gotoxy(32,9);
   printf("To:PHONE 2");
   gotoxy(32,12);
   scanf("%s",as.g1);
   gotoxy(32,13);
   scanf("%s",as.g2);
   gotoxy(32,14);
   scanf("%s",as.g3);
   gotoxy(32,15);
   scanf("%s",as.g4);
   gotoxy(32,16);
   scanf("%s",as.g5);
   fprintf(p,"%s\n", as.g1);
   fprintf(p,"%s\n", as.g2);
   fprintf(p,"%s\n", as.g3);
   fprintf(p,"%s\n", as.g4);
   fprintf(p,"%s\n", as.g5);
   fclose(p);
   textbackground(BLACK);
   textcolor(WHITE);
   clrscr();
   boxa();
   gotoxy(32,15);
    printf("Message Sent");
   getch();
   mainmenua();
  }
void timera()
{
     struct tm *timeinfo;
     int h,m,s,i,d,mon,y;
     time_t rawtime;
     textbackground(BLACK);
     textcolor(WHITE);
     clrscr();
     boxa();
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
void takea()
{
  char x[20];
  int flag=0,u;
  FILE *q;
  gotoxy(33,21);
  gets(x);
  q = fopen("on2.txt", "r");
      while(!feof(q))
      {
       fscanf(q,"%s\n%s\n", b.name,&b.a);
       u=strcmpi(x,b.name);
       if(u==0)
	{
	  flag=1;
	}
      }
  if(flag==1)
  {
    callmea(x);
  }
  else
  {
    gotoxy(33,22);
    printf("NOT FOUND");
  }
}
void callmea(char x[])
{
  clrscr();
  callinga(x);
}
