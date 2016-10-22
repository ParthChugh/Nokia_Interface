  #include<conio.h>
  #include<stdio.h>
  #include<stdlib.h>
  #include<dos.h>
  #include<time.h>
  #include<string.h>
  struct ent2
{
  char q1[10];
  char q2[10];
  char q3[10];
  char q4[10];
  char q5[10];
}
e2;
struct emp1
{
  char name1[10];
  char re[10];
}
e3;
void mainmenu1();
void line111(int);
void line11(int);
int display1();
void timer1();
void menu111(void);
void contacts1();
void outb1();
void inbox11();
void compcontact1();
void message1();
void menu11(void);
void inbox111();
void inb1();
void intox1(char);
void sms1();
void Rcalls1(void);
void calls1();
void calling1();
void take1();
void callme1();
void box1()
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
  line111(8);
  line111(24);
  line11(30);
  line11(45);
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
void line111(int y)
{
  int i;
  for (i=30; i<45; i++)
  {
    gotoxy(i, y);
    printf("Í");
  }
}

void line11(int x)
{
  int i;
  for (i=8; i<24; i++)
  {
    gotoxy(x, i);
    printf("º");
  }
}

int maina()
{
  int l;
  struct tm *timeinfo;
  int h, m1, s, i, d, mon, y;
  time_t rawtime;
as:
  textbackground(BLACK);
  textcolor(WHITE);

  clrscr();
  box1();
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
    mainmenu1();
  }
  goto  as;
  return 0;
}
void mainmenu1()
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
  box1();
  while (1)
  {
    menu111();
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
      cprintf("CALLS");
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
      //  maina();
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
    sms1();
    goto TOP;
    break;
  case 2:
    Rcalls1();
    goto TOP;
    break;
  case 3:
    contacts1();
  kk:
    m=getch();
    if (m=='1')
    {
      goto TOP;
    } else
      goto kk;
    break;
  case 4:
    compcontact1();
    goto TOP;
    break;
  case 5:
  mp:
    timer1();
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
void menu111()
{
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
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
void compcontact1()
{
  FILE *p;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  gotoxy(32, 9);
  printf("New Contact");
  gotoxy(32, 10);
  printf("Enter Name\n");
  gotoxy(32, 13);
  printf("Phone Number");
  p = fopen("on3.txt", "a");
  gotoxy(32, 11);
  scanf("%s", e3.name1);
  gotoxy(32, 14);
  scanf("%s", e3.re);
  fprintf(p, "%s\n%s\n", e3.name1, e3.re);
  fclose(p);
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  gotoxy(32, 15);
  printf("Contact Saved");
  getch();
}
int display1()
{
  char ch, ch1;
  int i=0, c=-1;
  FILE *q;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  gotoxy(33, 9);
  printf("CONTACTS");
  q = fopen("on3.txt", "r");
  if(!feof(q))
  {
  while (!feof(q) && c<3)
  {
    c++;
    fscanf(q, "%s\n%s\n", e3.name1, &e3.re);
    gotoxy(34, 11+2*i);
    printf("%s", e3.name1);
    gotoxy(32, 12+2*i);
    printf("%s", e3.re);
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
void contacts1()
{
  int k;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  k=display1();
  if(k==1)
  {
  goto gr;
  }
  take1();
  gr:
}
void Rcalls1()
{
  int cf;
  int c, k=12;
  char ch;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  while (1)
  {
    calls1();
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
    calling1(NULL);
  }
hp:
}
void calling1(int x[])
{
  int cf;
  int h, m, s, t;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
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
void calls1()
{

  textbackground(BLACK);
  textcolor(WHITE);
  gotoxy(32, 10);
  cprintf("EMERGENCY");
  gotoxy(32,11);
  cprintf("CALLS");
  gotoxy(32, 12);
  cprintf("8149404001");
  gotoxy(32, 14);
  cprintf("8875317243");
  gotoxy(32, 16);
  cprintf("9828831361");
}
void sms1()
{
  int c, k=12;
  char ch;
  textbackground(BLACK);
  textcolor(WHITE);
  box1();
  clrscr();
  box1();
  while (1)
  {
    inbox111();
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
    inb1();
    goto er;
    break;
  case 2:
    inbox11();
    goto er;
    break;
  case 3:
    message1();
    goto er;
    break;
  }
er:
}
void inbox111()
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
void inbox11()
{
  char ch, ch1;
  int i=0, c=-1;
  char v=65;
  FILE *q;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  gotoxy(33, 9);
  printf("OUTBOX");

  q = fopen("from2.txt", "r");
  while (!feof(q) )
  {
    c++;
    fscanf(q, "%s\n", e2.q1);
    gotoxy(32, 12+i);
    if (c%5==0)
    {
      printf("%c.> %s", v, e2.q1);
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
    outb1(ch);
  }
last:
}
void outb1(char ch)
{
  FILE *q;
  int i=0, j, k, c=0, a;
here:
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  if (ch>=65 && ch<95)
    ch=ch-64;
  if (ch>=97)
    ch=ch-96;
  k=5*(int)ch;
  j=k-5;
  gotoxy(33, 9);
  printf("To:Phone 2");
  q = fopen("from2.txt", "r");
  while (!feof(q))
  {
    fscanf(q, "%s\n", e2.q1);
    if (c>=j && c<k)
    {
      gotoxy(32, 12+i);
      printf("%s\n", e2.q1);
      i++;
    }
    c++;
  }
  a=getch();
  if (a=='1')
  {                        
    goto hd;
    //  inbox11();
  } else if (a=='3')
  {
    goto hd;
  } else
  {
    goto here;
  }
hd:
}
void inb1()
{
  char ch, ch1;
  int i=0, c=-1;
  char v=65;
  FILE *q;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  gotoxy(33, 9);
  printf("INBOX");

  q = fopen("from1.txt", "r");
  while (!feof(q) )
  {
    c++;
    fscanf(q, "%s\n", e2.q1);
    gotoxy(32, 12+i);
    if (c%5==0)
    {
      printf("%c.> %s", v, e2.q1);
      i=i+2;
      v++;
    }
  }
  ch=getch();
  if (ch=='1')
  {
    sms1();
  } else if (ch=='3')
  {
    goto ml;
  } else
  {
    intox1(ch);
  }
ml:
}
void intox1(char ch)
{
  FILE *q;
  int i=0, j, k, c=0, a;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  if (ch>=65 && ch<95)
    ch=ch-64;
  if (ch>=97)
    ch=ch-96;
  k=5*(int)ch;
  j=k-5;
  gotoxy(33, 9);
  printf("From:Phone 1");
  q = fopen("from1.txt", "r");
  while (!feof(q))
  {
    fscanf(q, "%s\n", e2.q1);
    if (c>=j && c<k)
    {
      gotoxy(32, 12+i);
      printf("%s\n", e2.q1);
      i++;
    }
    c++;
  }
  a=getch();
  if (a=='1')
  {
    inb1();
  } else if (a=='3')
  {
    goto ser;
  } else
  {
    inbox111();
  }
ser:
}
void message1()
{
  FILE *p;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  p = fopen("from2.txt", "a");
  gotoxy(32, 9);
  printf("To:PHONE 2");
  gotoxy(32, 12);
  scanf("%s", e2.q1);
  gotoxy(32, 13);
  scanf("%s", e2.q2);
  gotoxy(32, 14);
  scanf("%s", e2.q3);
  gotoxy(32, 15);
  scanf("%s", e2.q4);
  gotoxy(32, 16);
  scanf("%s", e2.q5);
  fprintf(p, "%s\n", e2.q1);
  fprintf(p, "%s\n", e2.q2);
  fprintf(p, "%s\n", e2.q3);
  fprintf(p, "%s\n", e2.q4);
  fprintf(p, "%s\n", e2.q5);
  fclose(p);
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
  gotoxy(32, 15);
  printf("Message Sent");
  getch();
}
void timer1()
{
  struct tm *timeinfo;
  int h, m, s, i, d, mon, y;
  time_t rawtime;
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  box1();
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
void take1()
{
  char x[20];
  int flag=0, u;
  FILE *q;
  gotoxy(33, 21);
  gets(x);
  q = fopen("on3.txt", "r");
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
    callme1(x);
  } else
  {
    gotoxy(33, 22);
    printf("NOT FOUND");
  }
}
void callme1(char x[])
{
  clrscr();
  calling1(x);
}