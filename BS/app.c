#include<stdlib.h>
#include<stdio.h>
#include"app.h"
#define ACTIVE 1
#define RESTRICTED 0
#define CLOSED 0


int Create_Stack(Stack*ps)
{
	int i ;
   StackNode*ps=(StackNode*)malloc(sizeof(StackNode));
if (top !=NULL){
	ps->size=i;
    ps->next=NULL;
}
return ps ;
}

/*to PUSH new Account */
void Create_New_Account (Stack*ps)
{
		//   StackNode*pn=(StackNode*)malloc(sizeof(StackNode));

    static int i;
    i=ps->size;
    puts("Enter your name");                                              // assign client name
    scanf("%s",pn->Name);
    puts("Please Enter your Address");                                    // assign address
    scanf("%s",pn->Address);
    puts("Enter Your Age");                                               //assign age
    scanf("%d",&pn->Age);
    if (pn->Age<21)                                                       // gardian on age eligiblity
    {
        puts("age is less than 21 can not create account");               // must break the registeration process?
    }
    puts("National ID consist of 14 Digits");
    scanf("%d",&pn->NationalID);                                           // assign national ID
    puts("enter amount to be deposited");
    scanf("%f",&pn->Balance);                                              //assign deposite amount
    pn->Password=(1234+i);                                                 //generate password
    pn->AccountID=(221001+i);                                              //generate account ID
    pn->Status=ACTIVE;                                                    //set account active
    pn->next=ps->top;
    ps->top=pn;
    ps->size++;
    i++;
    puts("**********************************************");               // welcoming message and declaring new password and account id
    puts("Welcome and Thanks for choosing our bank");
    printf("Your New Password is:%d\nYour Account ID is:%d\n",pn->Password,pn->AccountID);
    puts("**********************************************");
}

StackNode* Traverse_List (Stack*ps, int id)
{
    for (StackNode* pn=ps->top; pn ;  pn=pn->next)
    {
        if(pn->AccountID==id)
        return pn;
    }

}

void Display_Exisiting_Account (StackNode* pn)
{
    puts("**********************************************");
    printf("CLIENT:%d INFORMATION\n",pn->AccountID);
    if(pn->Status==ACTIVE)printf("Account Status is Active\n");
    puts(pn->Name);
    puts(pn->Address);
    printf("AGE :%d\n",pn->Age);
    printf("National ID is:%d\n",pn->NationalID);
    printf("Current Balance is:%f\n",pn->Balance);
    puts("**********************************************");                       
}

void Get_Cash (StackNode* pn,float amount)
{
    puts("********//////////////************");
    pn->Balance-=amount;
    printf("Successful Process\nCurrent Balance is=%f\n",pn->Balance);
}

void Deposite (StackNode* pn,float amount)
{
    puts("Enter the amount");
    pn->Balance+=amount;
    printf("Successful Process\nCurrent Balance is=%f",pn->Balance);
}

void Change_Account_Status (StackNode*pn)
{
    printf("choose account status\n(A)ACTIVE\n(R)RESTRICTED\n(C)CLOSED\n");
    int state=getchar();
    switch (state)
    {
    case 'A' :
        pn->Status=ACTIVE;
        printf("Account State is ACTIVE");
        break;
    case 'R':
        pn->Status=RESTRICTED;
        printf("Account State is RESTRICTED");
        break;    
    case 'X':
        pn->Status=CLOSED;
        printf("Account State is CLOSED");
        break;
    }
}

void Transaction (Stack*ps)
{
    int idS,idR=0;
    float amount;
    StackNode* pt;;
    printf("Enter the account id u wanna send from\n");
    scanf("%d",&idS);
    printf("enter the tranaction amount\n");
    scanf("%d",&amount);
    printf("Enter the account id u wanna transfer to\n");
    scanf("%d",&idR);
    pt=Traverse_List(ps,idS);
    pt->Balance-=amount;
    pt=Traverse_List(ps,idR);
    pt->Balance+=amount;
    printf("Transaction is done successfully>>\n");
}

void Change_Account_Password(StackNode*pn){
	printf("Enter the password");
	scanf("%d",&pn ->Password);
	printf("Password Changed Successfully");
	
	
}


