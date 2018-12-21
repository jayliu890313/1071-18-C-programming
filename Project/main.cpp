#include "Calendar.h"

int main()
{
    Node *startPtr = NULL;  //Linked list head.
    int choice;             //User's choice.
    int ID = 0;             //Data ID.
    int delID;              //User to delete the ID number.
    while(choice != EOF)
    {
        information();
        scanf("%d", &choice);
        system("CLS");
        switch(choice){
            case 1:     //check all the schdule.
                ID = printList(&startPtr, ID);
                break;
            case 2:     //adding the schdule.
                choice = 1;
                while(choice == 1)
                {
                    ID += 1;
                    insert(&startPtr, ID);
                    printf("\n1.Continue to add\n");
                    printf("2.Check all the schdule\n");
                    printf("3.Return to Menu\n");
                    printf("4.Exit\n");
                    printf("Enter => ");
                    scanf("%d", &choice);
                    system("CLS");
                    switch(choice)
                    {
                        case 1:
                            continue;
                        case 2:
                            ID = printList(&startPtr, ID);
                            break;
                        case 3:
                            break;
                        case 4:
                            printf( "End of run.\n" );
                            exit(1);
                    }
                }
                break;
            case 3:     //Delete the schdule
                if(startPtr == NULL)
                {
                    printf("There is no schdeule!\n");
                    printf("1.Return to Menu.\n");
                    printf("2.Adding the schdule.\n");
                    printf("3.Exit\n");
                    printf("Enter => ");
                    scanf("%d", &choice);
                    system("CLS");
                    switch(choice)
                    {
                        case 1:
                            break;
                        case 2:
                            choice = 1;
                            while(choice == 1)
                            {
                                ID += 1;
                                insert(&startPtr, ID);
                                printf("\n1.Continue to add\n");
                                printf("2.Check all the schdule\n");
                                printf("3.Return to Menu\n");
                                printf("4.Exit\n");
                                printf("Enter => ");
                                scanf("%d", &choice);
                                system("CLS");
                                switch(choice)
                                {
                                    case 1:
                                        continue;
                                    case 2:
                                        ID = printList(&startPtr, ID);
                                        break;
                                    case 3:
                                        break;
                                    case 4:
                                        printf( "End of run.\n" );
                                        exit(1);
                                }
                                printf("\n");
                            }
                            break;
                        case 3:
                            printf( "End of run.\n" );
                            exit(1);
                            break;
                    }
                }else{
                    printList_a(startPtr);
                    printf("Enter ID: ");
                    scanf("%d", &delID);
                    system("CLS");
                    ID = del(&startPtr, delID, ID);
                }
                break;
            case 4:

                break;
            case 5:
                break;
            case 6:
                printf( "End of run.\n" );
                return 0;
        }
    }
    return 0;
}
