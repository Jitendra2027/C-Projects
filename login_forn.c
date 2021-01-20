#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define Esc 27

void signup();
void login();
void delay(float);
void gotoxy(int,int);
struct user
{
    char passwd[10];
    char name[30];
}s;
FILE *fp;
int main()
{
    char ch;
    while(1)
    {
        system("cls");
        gotoxy(40,7);
        printf("_________________Select an option________________");
        gotoxy(45,9);
        printf("Yours welcome here");
        gotoxy(45,11);
        printf("Press 1 for login");
        gotoxy(45,13);
        printf("Press 2 for sign up");
        gotoxy(45,15);
        printf("Press Esc for exit");
        gotoxy(40,17);
        printf("_________________________________________________");
        ch=getch();
        switch(ch)
        {
        case '1':
                system("cls");
                gotoxy(23,3);
                printf("Page loading...\n");
                gotoxy(23,5);
                for(int i=0;i<50;i++)
                {
                    printf("_");
                    delay(0.05);
                }
                login();
                break;
        case '2':
                system("cls");
                gotoxy(23,3);
                printf("Page loading...\n");
                gotoxy(23,5);
                for(int i=0;i<40;i++)
                {
                    printf("_");
                    delay(0.05);
                }
                signup();
                break;
        case Esc:
                exit(0);
        default:
                printf("Press a valid button!");
        }
    }
    return 0;
}
void login()
{
    char c;
    char name[20];
    char passwd[10];
    char chkp,chku;
    system("cls");
    gotoxy(23,5);
    printf("_______________login zone_______________");
    gotoxy(23,7);

    fp=fopen("record.bin","rb");

    printf("Enter username:  ");
    gets(name);

    gotoxy(23,9);

    printf("Enter password:  ");

    /*for(int i=0;i<8;i++)
    {
        scanf("%c",&c);
        passwd[i]=c;
        if(i==7)
            break;
    }*/
    gets(passwd);
    gotoxy(23,11);
    printf("Press 'L' to login...");
    scanf("%c",&c);
    if(c=='L' || c=='l')
    {
        while(!feof(fp))
        {
            fread(&s,sizeof(s),1,fp);
            chku=strcmp(name,s.name);
            chkp=strcmp(passwd,s.passwd);

            if(chku==0 && chkp!=0)
            {
                system("cls");
                gotoxy(23,11);
                printf("Invalid password...!");
                system("Pause");
                break;
            }
            else if(chku!=0 && chkp==0)
            {
                system("cls");
                gotoxy(23,11);
                printf("Invalid username...!");
                system("Pause");
                break;
            }
            else if(chku!=0 && chkp!=0)
            {
                system("cls");
                gotoxy(23,11);
                printf("Invalid username and password...!");
                system("Pause");
                break;
            }
        else{
            system("cls");
            gotoxy(23,9);
            printf("Hello welcome %s in this zone....",name);
            gotoxy(23,11);
            printf("\"So this is the basic login form built with c language \n");
            gotoxy(23,13);
            printf("which uses c concepts like file handing,delay() function,\n");
            gotoxy(23,15);
            printf("looping,switch case,conditional statements,structure etc.\" \n");
            gotoxy(23,17);
            printf("____________________*_*_*_*_*_*_*_*_*_*___________________\n");
            gotoxy(23,19);
            system("Pause");
            break;
            }
    }
    }
    else{
        printf("Press a invalid key,press the enter key...");
        system("Pause");
        login();
    }
}
void signup()
{
    char s1;
    fp=fopen("record.bin","ab");
    system("cls");
    gotoxy(23,5);
    printf("______________Sign up zone_____________");
    gotoxy(23,7);
    printf("Set username:  ");
    gets(s.name);
    gotoxy(23,9);
    printf("Set password:  ");
    //for(int i=0;i<8;i++)
    //{
      //  scanf("%c",&c);
        //s.passwd[i]=c;
    //}
    gets(s.passwd);
    gotoxy(23,11);
    printf("Press 'S' to continue...");
    scanf("%c",&s1);
    if(s1=='s' || s1=='S')
    {
        fwrite(&s,sizeof(s),1,fp);
        gotoxy(23,13);
        printf("Information saved!...login to enter in page.");
        system("Pause");
    }
    else return;
    fclose(fp);
}
void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}
void delay(float number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
