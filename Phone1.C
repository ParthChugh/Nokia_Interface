#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include<string.h>
  struct ent
{
  char a1[10];
  char a2[10];
  char a3[10];
  char a4[10];
  char a5[10];
}
e1;
struct emp
{
  char name[10];
  char a[10];
}
e;
void mainmenu();
void line(int);
void line1(int);
int display();
void timer();
void menu(void);
void contacts();
void outb();
void inbox1();
void compcontact();
void message();
void menu1(void);
void inbox();
void inb();
void intox(char);
void sms();
void Rcalls(void);
void calls();
void calling();
void take();
void callme();
void box()
{
  printf("\n");
  gotoxy(29, 2);
  cprintf("NOKIA INTERFACE OF NOKIA 1100");
  gotoxy(5, 10);
  printf("->operations");
  gotoxy(5, 11);
  printf("2 FOR UP KEY");
  gotoxy(5,12);
  printf("8 FOR DOWN KEY");
  gotoxy(5, 13);
  printf("1 FOR BACK KEY");
  gotoxy(5, 14);
  printf("5 FOR SELECTION");
  gotoxy(5,15);
  printf("1 FOR END CALL");
  gotoxy(3,4);
  printf("->functions like->date and time display");
  gotoxy(3,5);
  printf("#composing & sending messages from one phone to other phone");
  gotoxy(3,6);
  printf("#saving contacts & search contacts");
  gotoxy(3,7);
  printf("#calling timer start & end is displayed are performed");
  line(8);
  line(24);
  line1(30);
  line1(45);
  gotoxy(30, 8);
  printf("É");
  gotoxy(30, 24);
  printf("È");
  gotoxy(45, 8);
  printf("»");
  gotoxy(45, 24);
  printf("¼");
  gotoxy(41, 23);
  printf("Back");
}
void line(int y)
{
  int i;
  for (i=30; i<45; i++)
  {
    gotoxy(i, y);
    printf("Í");
  }
}

void line1(int x)
{
  int i;
  for (i=8; i<24; i++)
  {
    gotoxy(x, i);
    printf("º");
  }
}

int mainb()
{
  int l;
  struct tm *timeinfo;
  int h, m1, s, i, d, mon, y;
  time_t rawtime;
as:
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  gotoxy(41, 23);
  printf("    ");
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  h=timeinfo->tm_hour;
  s= timeinfo->tm_sec;
  m1= timeinfo->tm_min;

  while (!kbhit())
  {
    if (s>59) {
      m1=m1+1;
      s=0;
    }
    if (m1>59) {
      h=h+1;
      m1=0;
    }
    if (h>24) {
      h=0;
      m1=0;
      s=0;
    }
    delay(1000);
    s=s+1;            // clrscr();
    gotoxy(36, 10);
    printf("TIME");
    gotoxy(34, 12);
    printf("%d:%d:%d", h, m1, s);
    d=timeinfo->tm_mday;
    mon= timeinfo->tm_mon+1;
    y= timeinfo->tm_year;
    gotoxy(36, 14);
    printf("DATE");
    gotoxy(33, 16);
    printf("%d/%d/%d", d, mon, y+1900);
  }
  l=getch();
  if (l=='3')
  {
    exit(0);
  }
  if (l=='1')
  {
    return 0;
  } else
  {
    mainmenu();
  }
  goto  as;
  return 0;
}
void mainmenu()
{
  int g;
  char m;
  int k=12;
  int c;
  char ch;
TOP:
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  while (1)
  {
    menu();
    textbackground(RED);
    switch(k)
    {
    case 12 :
      gotoxy(32, 12);
      cprintf("SMS");
      c=1;
      break;
    case 14 :
      gotoxy(32, 14);
      cprintf("EMER.CALLS");
      c=2;
      break;
    case 16 :
      gotoxy(32, 16);
      cprintf("CONTACTS");
      c=3;
      break;
    case 18 :
      gotoxy(32, 18);
      cprintf("NEW CONTACT");
      c=4;
      break;
    case 20 :
      gotoxy(32, 20);
      cprintf("TIME AND DATE");
      c=5;
    }
    ch=getch();
    if (ch=='2')
    {
      k+=2;
    }
    if (ch=='8')
    {
      k-=2;
    }
    if (ch=='5')
    {
      goto end;
    }
    if (ch=='1'|| ch=='3')
    {
      //  mainb();
      goto aaa;
    }
    if (k<12)
      k=12;
    if (k>20)
      k=20;
  }
end:
  switch(c)
  {
  case 1:
    sms();
    goto TOP;
    break;
  case 2:
    Rcalls();
    goto TOP;
    break;
  case 3:
    contacts();
  kk:
    m=getch();
    if (m=='1')
    {
      goto TOP;
    } else
      goto kk;
    break;
  case 4:
    compcontact();
    goto TOP;
    break;
  case 5:
  mp:
    timer();
    g=getch();
    if (g=='1')
    {
      goto TOP;
    } else
      goto mp;
  }
  getch();
aaa:
}
void menu()
{
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  gotoxy(36, 10);
  cprintf("Menu");
  gotoxy(32, 12);
  cprintf("SMS");
  gotoxy(32, 14);
  cprintf("EMER.CALLS");
  gotoxy(32, 16);
  cprintf("CONTACTS");
  gotoxy(32, 18);
  cprintf("NEW CONTACT");
  gotoxy(32, 20);
  cprintf("TIME AND DATE");
}
void compcontact()
{
  FILE *p;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  gotoxy(32, 9);
  printf("New Contact");
  gotoxy(32, 10);
  printf("Enter Name\n");
  gotoxy(32, 13);
  printf("Phone Number");
  p = fopen("on1.txt", "a");
  gotoxy(32, 11);
  scanf("%s", e.name);
  gotoxy(32, 14);
  scanf("%s", e.a);
  fprintf(p, "%s\n%s\n", e.name, e.a);
  fclose(p);
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  gotoxy(32, 15);
  printf("Contact Saved");
  getch();
}
int display()
{
  char ch, ch1;
  int i=0, c=-1;
  FILE *q;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  gotoxy(33, 9);
  printf("CONTACTS");
  q = fopen("on1.txt", "r");
  if(!feof(q))
  {
  while (!feof(q) && c<3)
  {
    c++;
    fscanf(q, "%s\n%s\n", e.name, &e.a);
    gotoxy(34, 11+2*i);
    printf("%s", e.name);
    gotoxy(32, 12+2*i);
    printf("%s", e.a);
    i++;
  }
  }
  if(feof(q)==NULL )
  {
  gotoxy(34,16);
  printf("NO CONTACTS");
  return 1;
}
}
void contacts()
{
  int k;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  k=display();
  if(k==1)
  {
  goto fg;
  }
  take();
  fg:
}
void Rcalls()
{
  int cf;
  int c, k=12;
  char ch;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  while (1)
  {
    calls();
    textbackground(YELLOW);
    switch(k)
    {
    case 12 :
      gotoxy(32, 12);
      cprintf("8149404001");
      c=1;
      break;
    case 14 :
      gotoxy(32, 14);
      cprintf("8875317243");
      c=2;
      break;
    case 16 :
      gotoxy(32, 16);
      cprintf("9828831361");
      c=3;
      break;
    }
    ch=getch();
    if (ch=='2')
    {
      k+=2;
    }
    if (ch=='8')
    {
      k-=2;
    }
    if (ch=='5')
    {
      goto end;
    }
    if (ch=='1')
    {
      goto hp;
    }
    if (k<12)
      k=12;
    if (k>16)
      k=16;
  }
end:
  if (c>0)
  {
    calling(NULL);
  }
hp:
}
void calling(int x[])
{
  int cf;
  int h, m, s, t;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  h=0;
  s=0;
  m=0;
  while (!kbhit())
  {
    if (s>59) {
      m=m+1;
      s=0;
    }
    if (m>59) {
      h=h+1;
      m=0;
    }
    if (h>24) {
      h=0;
      m=0;
      s=0;
    }
    delay(1000);
    s=s+1;
    gotoxy(32, 10);
    printf("NOW CALLING :");
    gotoxy(36, 11);
    puts(x);
    gotoxy(34, 16);
    printf("%d:%d:%d", h, m, s);
  }
  cf=getch();
  if (cf=='1')
  {
    goto qw;
  }
qw:
}
void calls()
{
  textbackground(BLACK);
  textcolor(WHITE);
  gotoxy(32, 10);
  cprintf("Emergency");
  gotoxy(32,11);
  cprintf("calls");
  gotoxy(32, 12);
  cprintf("8149404001");
  gotoxy(32, 14);
  cprintf("8875317243");
  gotoxy(32, 16);
  cprintf("9828831361");
}
void sms()
{
  int c, k=12;
  char ch;
  textbackground(BLACK);
  textcolor(WHITE);
  box();
  clrscr();
  box();
  while (1)
  {
    inbox();
    textbackground(GREEN);
    switch(k)
    {
    case 12 :
      gotoxy(32, 12);
      cprintf("Inbox");
      c=1;
      break;
    case 14 :
      gotoxy(32, 14);
      cprintf("Outbox");
      c=2;
      break;
    case 16 :
      gotoxy(32, 16);
      cprintf("Compose sms");
      c=3;
      break;
    }
    ch=getch();
    if (ch=='2')
    {
      k+=2;
    }
    if (ch=='8')
    {
      k-=2;
    }
    if (ch=='5')
    {
      goto end;
    }
    if (ch=='1'||ch=='3')
    {
      goto er;
    }
    if (k<12)
      k=12;
    if (k>16)
      k=16;
  }
end:
  switch(c)
  {
  case 1:
    inb();
    goto er;
    break;
  case 2:
    inbox1();
    goto er;
    break;
  case 3:
    message();
    goto er;
    break;
  }
er:
}
void inbox()
{
  textbackground(BLACK);
  textcolor(WHITE);
  gotoxy(36, 10);
  cprintf("SMS");
  gotoxy(32, 12);
  cprintf("Inbox");
  gotoxy(32, 14);
  cprintf("Outbox");
  gotoxy(32, 16);
  cprintf("Compose sms");
}
void inbox1()
{
  char ch, ch1;
  int i=0, c=-1;
  char v=65;
  FILE *q;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  gotoxy(33, 9);
  printf("OUTBOX");

  q = fopen("from1.txt", "r");
  while (!feof(q) )
  {
    c++;
    fscanf(q, "%s\n", e1.a1);
    gotoxy(32, 12+i);
    if (c%5==0)
    {
      printf("%c.> %s", v, e1.a1);
      i=i+2;
      v++;
    }
  }
  ch=getch();
  if (ch=='1'||ch=='3')
  {
    goto last;
  } else
  {
    outb(ch);
  }
last:
}
void outb(char ch)
{
  FILE *q;
  int i=0, j, k, c=0, a;
here:
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  if (ch>=65 && ch<95)
    ch=ch-64;
  if (ch>=97)
    ch=ch-96;
  k=5*(int)ch;
  j=k-5;
  gotoxy(33, 9);
  printf("To:Phone 2");
  q = fopen("from1.txt", "r");
  while (!feof(q))
  {
    fscanf(q, "%s\n", e1.a1);
    if (c>=j && c<k)
    {
      gotoxy(32, 12+i);
      printf("%s\n", e1.a1);
      i++;
    }
    c++;
  }
  a=getch();
  if (a=='1')
  {
    goto hd;
    //  inbox1();
  } else if (a=='3')
  {
    goto hd;
  } else
  {
    goto here;
  }
hd:
}
void inb()
{
  char ch, ch1;
  int i=0, c=-1;
  char v=65;
  FILE *q;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  gotoxy(33, 9);
  printf("INBOX");

  q = fopen("from2.txt", "r");
  while (!feof(q) )
  {
    c++;
    fscanf(q, "%s\n", e1.a1);
    gotoxy(32, 12+i);
    if (c%5==0)
    {
      printf("%c.> %s", v, e1.a1);
      i=i+2;
      v++;
    }
  }
  ch=getch();
  if (ch=='1')
  {
    sms();
  } else if (ch=='3')
  {
    goto ml;
  } else
  {
    intox(ch);
  }
ml:
}
void intox(char ch)
{
  FILE *q;
  int i=0, j, k, c=0, a;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  if (ch>=65 && ch<95)
    ch=ch-64;
  if (ch>=97)
    ch=ch-96;
  k=5*(int)ch;
  j=k-5;
  gotoxy(33, 9);
  printf("From:Phone 1");
  q = fopen("from2.txt", "r");
  while (!feof(q))
  {
    fscanf(q, "%s\n", e1.a1);
    if (c>=j && c<k)
    {
      gotoxy(32, 12+i);
      printf("%s\n", e1.a1);
      i++;
    }
    c++;
  }
  a=getch();
  if (a=='1')
  {
    inb();
  } else if (a=='3')
  {
    goto ser;
  } else
  {
    inbox();
  }
ser:
}
void message()
{
  FILE *p;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  p = fopen("from1.txt", "a");
  gotoxy(32, 9);
  printf("To:PHONE 1");
  gotoxy(32, 12);
  scanf("%s", e1.a1);
  gotoxy(32, 13);
  scanf("%s", e1.a2);
  gotoxy(32, 14);
  scanf("%s", e1.a3);
  gotoxy(32, 15);
  scanf("%s", e1.a4);
  gotoxy(32, 16);
  scanf("%s", e1.a5);
  fprintf(p, "%s\n", e1.a1);
  fprintf(p, "%s\n", e1.a2);
  fprintf(p, "%s\n", e1.a3);
  fprintf(p, "%s\n", e1.a4);
  fprintf(p, "%s\n", e1.a5);
  fclose(p);
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  gotoxy(32, 15);
  printf("Message Sent");
  getch();
}
void timer()
{
  struct tm *timeinfo;
  int h, m, s, i, d, mon, y;
  time_t rawtime;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box();
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  h=timeinfo->tm_hour;
  s= timeinfo->tm_sec;
  m= timeinfo->tm_min;

  while (!kbhit())
  {
    if (s>59) {
      m=m+1;
      s=0;
    }
    if (m>59) {
      h=h+1;
      m=0;
    }
    if (h>24) {
      h=0;
      m=0;
      s=0;
    }
    delay(1000);
    s=s+1;
    // clrscr();
    gotoxy(32, 10);
    printf("TIME");
    gotoxy(32, 12);
    printf("%d:%d:%d", h, m, s);
    d=timeinfo->tm_mday;
    mon= timeinfo->tm_mon+1;
    y= timeinfo->tm_year;
    gotoxy(32, 14);
    printf("DATE");
    gotoxy(32, 16);
    printf("%d/%d/%d", d, mon, y+1900);
  }
}
void take()
{
  char x[20];
  int flag=0, u;
  FILE *q;
  gotoxy(33, 21);
  gets(x);
  q = fopen("on1.txt", "r");
  while (!feof(q))
  {
    fscanf(q, "%s\n%s\n", e.name, &e.a);
    u=strcmpi(x, e.name);
    if (u==0)
    {
      flag=1;
    }
  }
  if (flag==1)
  {
    callme(x);
  } else
  {
    gotoxy(33, 22);
    printf("NOT FOUND");
  }
}
void callme(char x[])
{
  clrscr();
  calling(x);
}