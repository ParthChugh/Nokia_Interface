#include"Phone1.c"
#include"Phone2.c"
#include<stdio.h>
void main()
{
int i;
{
TOP:
clrscr();
printf("WHICH PHONE YOU WANT TO SELECT\n");
printf("1.Phone 1\n");
printf("2.Phone 2:");
scanf("%d",&i);
switch(i)
{
case 1:
maina();
break;
case 2:
mainb();
break;
}
goto TOP;
}
}