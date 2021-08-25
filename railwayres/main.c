#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"
#include<string.h>
#include<errno.h>
int main()
{
extern int errno;
    int choice,ticket_no;
    Passenger *ptr;
    add_trains();
      int *pticket_no;
      int result;
      char *pmob_no,*ptrain_no,*train_no;

    while(1)
    {
        choice=enterchoice();
        if(choice==9)
            exit(0);
        switch(choice)
        {
                        case 1:
                                    view_trains();
                                    getch();
                                    clrscr();
                                    break;
                       case 2:


                       clrscr();
            ptr=get_passenger_details();
            clrscr();
            if(ptr!=NULL)
            {
                ticket_no=book_ticket(*ptr);
                if(ticket_no==-1)
                {
                    textcolor(RED);
                    printf("Booking Failed");
                }
                else
                {
                    textcolor(GREEN);
                    printf("Ticket successfully booked\nYour ticket number is %d",ticket_no);
                    textcolor(WHITE);
                    printf("\nPress any key to go back to main screen");
                    getch();
                }
            }
            clrscr();

            break;


                       case 3:      clrscr();
                       int num = accept_ticket_no();
                       view_ticket(num);
                       getch();
            clrscr();
                                    break;





                       case 4:
                                    clrscr();

            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();


                                    break;




                       case 5:      clrscr();
                                    printf("Press enter to view all bookings\n");
                                    getch();
                                    view_all_bookings();
                                    break;




                      case 6:
                                    clrscr();
                                  ptrain_no=accept_train_no();
                                  if(ptrain_no!=NULL)
                                  {
                                      view_booking(ptrain_no);

                                  }
                                  clrscr();

                                    break;
                      case 7:
                                   clrscr();
                                   ticket_no=accept_ticket_no();
                                   if(ticket_no!=0)
                                   {
                                       result=cancel_ticket(ticket_no);
                                       if(result==0)
                                       {
                                           textcolor(LIGHTRED);
                                           printf("no bookings done against ticket number %d",ticket_no);

                                       }
                                       else if( result==1)
                                       {
                                           textcolor(LIGHTGREEN);
                                           printf(" ticket number %d succesfully cancelled ",ticket_no);
                                       }
                                       else if(result==2)
                                       {
                                           printf("sorry ! error in cancellation, Try again ");
                                             printf("\n error code is &d",result);
                                             printf("\n reason %s",strerror(errno));
                                       }
                                       printf("\n\n press any key to go back to main screen");
                                   }

                                   getch();
                                   clrscr();

                                    break;
                      case 8:
                                               clrscr();
            train_no=accept_train_no();
            if(train_no!=0)
            {
                result=cancel_train(train_no);

                    if(result==0)
                    {
                        textcolor(LIGHTRED);
                        printf("SORRY! No tickets Booked against train no. %s",train_no);
                    }
                    else if(result==1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Train no. %s Successfully Cancelled",train_no);
                    }
                    else if(result==2)
                    {
                        textcolor(LIGHTRED);
                        printf("SORRY! Error in Cancellation.TRY AGAIN!!");
                    }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen!");
                }

            getch();
            clrscr();



                                    break;
                      default:
                                      textcolor(LIGHTRED);
                                      printf("Wrong Choice! Try Again\n");
                                      getch();
                                      clrscr();
        }
    }

    return 0;
}
