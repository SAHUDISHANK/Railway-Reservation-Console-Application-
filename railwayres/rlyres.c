#include <stdio.h>
#include <string.h>
#include "conio2.h"
#include "rlyres.h"
#include<ctype.h>
#include<malloc.h>

int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("\n");
    for(i=1;i<=39;i++)
        printf("*");
        textcolor(WHITE);
    printf("RAILWAY RESERVATION SYSTEM");
    textcolor(YELLOW);
    for(i=1;i<=39;i++)
        printf("*");
    for(i=1;i<=104;i++)
        printf("-");
    printf("\nSelect an option"); printf("\n");
    printf("\n1-View Trains");     printf("\n");
    printf("\n2-Book Ticket"); printf("\n");
    printf("\n3-View Ticket"); printf("\n");
    printf("\n4-Search Ticket No"); printf("\n");
    printf("\n5-View All Bookings"); printf("\n");
    printf("\n6-View Train Bookings"); printf("\n");
    printf("\n7-Cancel Ticket"); printf("\n");
    printf("\n8-Cancel Train"); printf("\n");
    printf("\n9-Quit"); printf("\n");
    printf("\n\nEnter choice:");
    scanf("%d",&choice);
    return choice;
}
void add_trains()
{
    Train alltrains[4]={
              {"123","BPL","GWA",2100,1500},
              {"546","BPL","DEL",3500,2240},
              {"345","HBJ","AGR",1560,1135},
              {"896","HBJ","MUM",4500,3360},
              };
    FILE *fp=fopen("F:\\railwayres\\alltrains.dat","rb");
    if(fp==NULL)
    {
        fp=fopen("F:\\railwayres\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        printf("File created and saved!\n");

    }
    else
        printf("File already present\n");
    fclose(fp);

}
void view_trains()
{
    int i;
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
     for(i=1;i<=80;i++)
        printf("-");
    FILE *fp=fopen("F:\\railwayres\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);

    }
    printf("\n\n\n\n");
    fclose(fp);
}
int check_train_no(char *trainno)
{
    FILE *fp=fopen("F:\\railwayres\\allTrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
          if(strcmp(tr.train_no,trainno)==0)
          {
                  fclose(fp);
                  return 1;
          }

    }
fclose(fp);
return 0;
}
int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;
}
Passenger * get_passenger_details()
{
    clrscr();
    static Passenger P;
    gotoxy(60,1);
    textcolor(BLUE);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter Passenger name:");
    fflush(stdin);
    fgets(P.p_name,20,stdin);
    char *pos;
    pos=strchr(P.p_name,'\n');
    *pos='\0';
    if(strcmp(P.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
    }
    int valid;
    printf("Gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&P.gender);
        if(P.gender=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(P.gender!='M'&&P.gender!='F')
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Gender should be M or F (in uppercase)");
            valid=0;

            gotoxy(13,2);
            printf(" \b");
            textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",P.train_no);
        if(strcmp(P.train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        valid=check_train_no(P.train_no);
        if(valid==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Invalid train number");
            gotoxy(20,3);
            printf("\t\t\t\t\t");
            gotoxy(20,3);
            textcolor(YELLOW);
        }

    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter travelling class(F-First AC,S-Second AC):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&P.p_class);
        if(P.p_class=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(P.p_class!='F'&&P.p_class!='S')
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Travelling class should be F or S (in uppercase)");
            valid=0;

            gotoxy(48,4);
            printf(" \b");
            textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter address:");
    fflush(stdin);
    fgets(P.address,20,stdin);
    pos=strchr(P.address,'\n');
    *pos='\0';
    if(strcmp(P.address,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        clrscr();
        return NULL;
    }
    printf("Enter age:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&P.age);
        if(P.age==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(P.age<0||P.age>130)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Age should be positive and valid");
            valid=0;

            gotoxy(11,6);
            printf("\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,7);
    printf("Enter mobile number:");
    do
    {
        fflush(stdin);

        fgets(P.mob_no,12,stdin);
        pos=strchr(P.mob_no,'\n');
        *pos='\0';
        if(strcmp(P.mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        valid=check_mob_no(P.mob_no);
        if(valid==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Invalid mobile number");

            gotoxy(21,7);
            printf("\t\t\t\t\t");
            gotoxy(21,7);
            textcolor(YELLOW);
        }
    }while(valid==0);
    return &P;
}
int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp=fopen("F:\\railwayres\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    int count=0;
    Passenger p;
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if(strcmp(p.train_no,train_no)==0 && tc==p.p_class)
            count++;
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    FILE *fp;
    fp=fopen("F:\\railwayres\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;

    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticket_no;
}
int book_ticket(Passenger p)
{
    int x=get_booked_ticket_count(p.train_no,p.p_class);
    if(x==30)
    {
        textcolor(LIGHTRED);
        printf("All seat in train no %s in class %c are full",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticket_no=ticket_no;
    FILE *fp=fopen("F:\\railwayres\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! File cannot be opened");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;

}
int accept_ticket_no()
{
    printf("Enter a valid ticket number:");
    int valid;
    int ticket_no;
    do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelled input.....");
            getch();
            textcolor(YELLOW);
            clrscr();
            return 0;
        }
        if(ticket_no<0&&ticket_no>30)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Ticket number should be positive and valid");
            valid=0;

            gotoxy(11,6);
            printf("\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }

    }while(valid==0);
    return ticket_no;
}
void view_ticket(int ticket_no)
{

    FILE* fp=fopen("F:\\railwayres\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("No booking done yet");
        return ;
    }
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticket_no==ticket_no)
        {
            printf("Name:%s\nGender:%c\nTrain no:%s\nClass:%c\nAddress:%s\nAge:%d\nMobile no:%s\nTicket no:%d",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticket_no);
            found=1;
        }

    }
    if(found==0)
    {
        printf("No detail of the ticket found");
        return;
    }
    return;
}
char* accept_mob_no()
{
    gotoxy(1,25);
                                    printf("press 0 to cancel input");
                                    gotoxy(1,1);
    static char mob_no[11];
    char *pos;
    int valid;
    printf("Enter mobile number:");
    do
{
fflush(stdin);
fgets(mob_no,11,stdin);
pos=strchr(mob_no,'\n');
if(pos!=NULL)
   *pos='\0';
if(strcmp(mob_no,"0")==0)
{
  textcolor(LIGHTRED);
  gotoxy(1,25);
  printf("\t\t\t\t\t\t\t");
  gotoxy(1,25);
  printf("Cancelling Input. . .!");
  getch();
  textcolor(YELLOW);
  return NULL;
}
valid=check_mob_no(mob_no);
if(valid==0)
  {
   textcolor(LIGHTRED);
   gotoxy(1,25);
   printf("Error! Invalid Mobile No");
   getch();
   gotoxy(21,1);
   printf("\t\t\t\t\t\t");
   gotoxy(21,1);
   textcolor(YELLOW);
  }
 }while(valid==0);
clrscr();
return mob_no;
}
    int* get_ticket_no(char *p_mob_no)
{
   int count=0;
   FILE *fp=fopen("F:\\railwayres\\allbookings.dat","rb");
   if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("sorry !file cannot be opened");
        return NULL;
    }
   Passenger pr;
   while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
   }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(strcmp(pr.mob_no,p_mob_no)==0)
      {
          *(p+i)=pr.ticket_no;
            i++;
      }
    }
*(p+i)=-1;
fclose(fp);
return p;
}
void view_all_tickets(char *pmob_no,int*pticket_no)
{
    if(pticket_no==NULL)
   {
    textcolor(LIGHTRED);
    printf("Sorry! No tickets booked against mobile no %s",pmob_no);
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        getch();
        return;
    }

        printf("Following are tickets booked for mobile no %s",pmob_no);
    int i;
    printf("\n\nTICKET NO\n");
    printf("-------------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
textcolor(WHITE);
printf("\n\nPress any key to go back to the main screen");
textcolor(YELLOW);
getch();
}
char* accept_train_no()
{
  static char train_no[10];
  int Valid;
  gotoxy(60,1);
  textcolor(LIGHTGREEN);
  printf("Press 0 to exit");
  gotoxy(1,1);
  textcolor(YELLOW);
    printf("Enter train number:");
       do
       {
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
   textcolor(LIGHTRED);


   gotoxy(1,25);
   printf("\t\t\t\t\t\t");
   gotoxy(1,25);
   printf("Cancelling input.........!");
   textcolor(YELLOW);
   return NULL;
  }
        Valid=check_train_no(train_no);
        if(Valid==0)
        {

                      gotoxy(1,25);
   textcolor(LIGHTRED);
   printf("enter valid train number");
   getch();
   gotoxy(20,1);
   printf("\t\t\t\t\t\t");
   gotoxy(20,1);
   textcolor(YELLOW);
        }

        } while(Valid==0);
        clrscr();
        return train_no;
}
void view_booking(char *train_no)
{

    int found=0;
  FILE *fp=fopen("F:\\railwayres\\allbookings.dat","rb");
   if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("sorry !file cannot be opened");
        return NULL;
    }

    Passenger pr;
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
        for(int i=1;i<=80;i++)
        printf("-");

    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {

        if(strcmp(pr.train_no,train_no)==0)
        {
            printf("\n %d\t\t%c\t%s",pr.ticket_no,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s",pr.gender,pr.age,pr.mob_no);
            row++;
            found=1;
        }
    }
    if(!found)
    {
      clrscr();
      textcolor(LIGHTRED);
      printf("\n no details of bookings of given train number %s found",train_no);


    }

   textcolor(WHITE);
   printf("\n press an key to continue");
   textcolor(YELLOW);
   getch();
   fclose(fp);

}
int cancel_ticket(int ticketno)
{
  int result;
 FILE *fp1=fopen("F:\\railwayres\\allbookings.dat","rb");
 if(fp1==NULL)
 {
     textcolor(LIGHTRED);
     printf("no bookings done yet");
     return -1;
 }
 FILE *fp2=fopen("F:\\railwayres\\temp.dat","wb");
 Passenger pr;
 int found=0;
 while(fread(&pr,sizeof(pr),1,fp1)==1)
 {
     if (pr.ticket_no==ticketno)
     {
         found=1;
     }
     else
        {
        fwrite(&pr,sizeof(pr),1,fp2);
     }
 }
 fclose(fp1);
 fclose(fp2);
 if (found==0)
 {
     remove( "F:\\railwayres\\temp.dat" );

 }
    else
        {
      result = remove("F:\\railwayres\\allbookings.dat");
      if(result!=0)
        return 2;
        result = rename("F:\\railwayres\\temp.dat","F:\\railwayres\\allbookings.dat");
    if(result!=0)
    {
        return 2;
    }
    }
 return found;
 }
void view_all_bookings()
 {
     FILE *fp=fopen("F:\\railwayres\\allbookings.dat","rb");
     Passenger pr;
     while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        printf("Name:%s\nGender:%c\nTrain no:%s\nClass:%c\nAddress:%s\nAge:%d\nMobile no:%s\nTicket no:%d",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticket_no);
        printf("\n");
        for(int i=1;i<=105;i++)
        printf("-");
    }
    fclose(fp);

    getch();
     clrscr();

 }
int cancel_train(char* train_no)
{
    int result;
    FILE *fp1=fopen("F:\\railwayres\\alltrains.dat","rb");

    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("No Bookings done yet!");
        return -1;
    }
    FILE *fp2=fopen("F:\\railwayres\\temp.dat","wb");
    Train pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("F:\\railwayres\\temp.dat");
    }
    else
        {
      result=remove("F:\\railwayres\\alltrains.dat");
            if(result!=0)
                return 2;
            result=rename("F:\\railwayres\\temp.dat","F:\\railwayres\\alltrains.dat");
            if(result!=0)
                return 2;

        }
        return found;
}













