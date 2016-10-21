  #include"phone1.c"
  #include"phone2.c"
  #include<stdio.h>
  int main()
{
  int i;
  {
  TOP:
    clrscr();
    printf("WHICH PHONE YOU WANT TO SELECT\n");
    printf("1.Phone 1\n");
    printf("2.Phone 2:");
    scanf("%d", &i);
    switch(i)
    {
    case 1:
      maina();
      break;
    case 2:
      mainb();
      break;
    default:
      printf("Worng Choice");
      goto end;
    }
    goto TOP;
  }
end:
  return 0;
}
