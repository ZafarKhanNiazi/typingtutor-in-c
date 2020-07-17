//Made by Muhammad Zafar Ijaz Khan Niazi


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>


void add(char,int);
int len();
void remov(char);
void display(int);
void Viewer(char);


struct myList
{
	 char data;
	 int x;
	 struct myList* next;
};

void gotoxy(int x,int y)
{
    COORD crd;
    crd.X=x;
    crd.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
}
int score=0;

struct myList* head;


int main()
{	 int choice;
gotoxy(30,4);
    printf("Enter Your Choice");
    gotoxy(30,5);
    printf("Press 1 for digits");
    gotoxy(30,6);
    printf("Press 2 for Capital Alphabets");
    gotoxy(30,7);
    printf("Press 3 for Small Alphabets");
    gotoxy(30,8);
    scanf("%d",&choice);
	display(choice);
	return 0;
}


void add(char value,int cp)
{
	char ch;
struct myList *link = (struct myList*) malloc(sizeof(struct myList));
   link->data = value;
   link->x=cp;
   link->next = head;
   head = link;
}

 int len( )
 {
 	int length=0;
 	struct myList* temp;
 	temp=head;
 	while(temp!=NULL)
 	{
 		length++;
 		temp=temp->next;
	 }
	 return length;
 }

void display(int choice)
{
int i;
int X;
char ch,character;
	X=0;
	char element;

	while(len()!=20)
	{
		ch='0';
		if(choice==1)
		{   element=(rand()%(57-48+1))+48;
		}
	   else if(choice==2)
	    {
	    	element=(rand()%(90-65+1))+65;
		}
		else if(choice==3)
		{
				element=(rand()%(122-97+1))+97;
		}
	    else
	    {
	    printf("you Entered Wrong key");
	}
		X=(rand()%(90-5+1))+5;
		 add(element,X);
		if(kbhit())
		{
			score--;
			ch=getch();
		}
		if(score==10)
        {

        	    gotoxy(50,50);
        		printf("You Win The match");
        		Sleep(1000);
        		exit(0);

		}
		character=(int)ch;
		   Viewer(character);
      Sleep(1000);
		}
}

void Viewer(char ch)
{
	int i;
  int y=1;
struct myList* list;
list=head;
 system("cls");
 gotoxy(50,25);
 printf("SCORES : %d",score);
 	while(list!=NULL)
	{
 	 gotoxy(list->x,y);
     printf("%c",list->data);
     y++;
    if(ch!='0')
         	{
       		remov(ch);
			}

	list=list->next;
   }
}


void remov(char ch)
{
struct myList* temp;
temp=head;
int i=1;
   	while(i<len()-1)
       	{
     		temp=temp->next;
           	i++;
    	}
	if(ch==temp->next->data)
		{
		score+=2;
		   temp->next=NULL;
		}
}


