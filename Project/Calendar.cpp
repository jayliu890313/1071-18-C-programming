#include "Calendar.h"

void information()    //Menu
{
    printf("|---------------------------------------------------|\n");
    printf("|                 It is a Calendar                  |\n");
    printf("|                       Menu                        |\n");
    printf("|---------------------------------------------------|\n");
    printf("| 1.Check all the schdule.                          |\n");
    printf("|---------------------------------------------------|\n");
    printf("| 2.Adding the schdule.                             |\n");
    printf("|---------------------------------------------------|\n");
    printf("| 3.Delete the schdule. (Enter ID)                  |\n");
    printf("|---------------------------------------------------|\n");
    printf("| 4.Check the date.                                 |\n");
    printf("|---------------------------------------------------|\n");
    printf("| 5.Check the calendar.                             |\n");
    printf("|---------------------------------------------------|\n");
    printf("| 6.Exit                                            |\n");
    printf("|---------------------------------------------------|\n");
    printf(" Enter => ");
}

int printList(Node **startPtr, int ID){     //have to choice
    Node *ptr;
    ptr = *startPtr;
    int choice;
    int delID;
    if(ptr == NULL)
    {
        printf("There is no schdeule!\n");
        printf("1.Return to Menu\n");
        printf("2.Adding the schdule.\n");  //unfinished
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
                    insert(startPtr, ID);
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
                            ID = printList(startPtr, ID);
                            return ID;
                            break;
                        case 3:
                            return ID;
                            break;
                        case 4:
                            printf( "End of run.\n" );
                            exit(1);
                    }
                    printf("\n");
                }
                return ID;
                break;
            case 3:
                printf( "End of run.\n" );
                exit(1);
                break;
        }
    }else{
        printf("----------------------The List-----------------------\n");
        while(ptr != NULL)
        {
            printf("ID : %d\n", ptr->calender.ID);
            printf("Date: %d / %0d / %0d\n", ptr->calender.year, ptr->calender.month, ptr->calender.day);
            printf("Planning:\n");
            printf("%s\n", ptr->calender.item);
            printf("\n");
            ptr = ptr->nextPtr;
        }
        printf("-----------------------------------------------------\n");
        printf("1.Return to Menu.\n");
        printf("2.Adding the schdule.\n");
        printf("3.Delete the schdule.\n");
        printf("4.Exit\n");
        printf("Enter => ");
        scanf("%d", &choice);
        system("CLS");
        switch(choice)
        {
            case 1:
                return ID;
                break;
            case 2:
                choice = 1;
                while(choice == 1)
                {
                    ID += 1;
                    insert(startPtr, ID);
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
                            ID = printList(startPtr, ID);
                            return ID;
                            break;
                        case 3:
                            return ID;
                            break;
                        case 4:
                            printf( "End of run.\n" );
                            exit(1);
                    }
                    printf("\n");
                }
                return ID;
                break;
            case 3:
                if(startPtr == NULL)
                {
                    printf("There is no schdeule!\n");
                    printf("1.Return to Menu.\n");
                    printf("2.Adding the schdule.\n");  //unfinished
                    printf("3.Exit\n");
                    printf("Enter => ");
                    scanf("%d", &choice);
                    system("CLS");
                    switch(choice)
                    {
                        case 1:
                            return ID;
                        case 2:
                            choice = 1;
                            while(choice == 1)
                            {
                                ID += 1;
                                insert(startPtr, ID);
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
                                        ID = printList(startPtr, ID);
                                        return ID;
                                        break;
                                    case 3:
                                        return ID;
                                        break;
                                    case 4:
                                        printf( "End of run.\n" );
                                        exit(1);
                                }
                                printf("\n");
                            }
                            return ID;
                            break;
                        case 3:
                            printf( "End of run.\n" );
                            exit(1);
                    }
                }else{
                    printList_a(*startPtr);
                    printf("Enter ID: ");
                    scanf("%d", &delID);
                    system("CLS");
                    ID = del(startPtr, delID, ID);
                    return ID;
                }
                return ID;
                break;
            case 4:
                printf( "End of run.\n" );
                exit(1);
        }
    }
    return ID;
}

void printList_a(Node *startPtr){    //just print
    Node *ptr;
    ptr = startPtr;
    if(ptr == NULL)
    {
        printf("There is no schdeule!\n");
        return;
    }else{
        printf("----------------------The List-----------------------\n");
        while(ptr != NULL)
        {
            printf("ID : %d\n", ptr->calender.ID);
            printf("Date: %d / %0d / %0d\n", ptr->calender.year, ptr->calender.month, ptr->calender.day);
            printf("Planning:\n");
            printf("%s\n", ptr->calender.item);
            printf("\n");
            ptr = ptr->nextPtr;
        }
        printf("-----------------------------------------------------\n");
    }
}

int isEmpty(Node *startPtr)
{
    if(startPtr == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

void insert(Node **startPtr, int ID)
{
    Node *prePtr, *currentPtr, *newnode;
    newnode = (Node *)malloc(sizeof(Node));

    printf("Enter the year month day:\n");
    scanf("%d %d %d", &newnode->calender.year, &newnode->calender.month, &newnode->calender.day);

    newnode->nextPtr = NULL;
    newnode->calender.ID = ID;

    printf("Enter your plan:\n");
    scanf("%s", newnode->calender.item);

    if(isEmpty(*startPtr))
    {
        *startPtr = newnode;
    }else
    {
        prePtr = NULL;
        currentPtr = *startPtr;
        while(currentPtr != NULL)
        {
            if(currentPtr->calender.year == newnode->calender.year)
            {
                while(currentPtr != NULL)
                {
                    if(currentPtr->calender.month == newnode->calender.month)
                    {
                        while(currentPtr != NULL)
                        {
                            if(currentPtr->calender.day >= newnode->calender.day ||
                               currentPtr->calender.year > newnode->calender.year ||
                               currentPtr->calender.month > newnode->calender.month)
                            {
                                break;
                            }
                            else
                            {
                                prePtr = currentPtr;
                                currentPtr = currentPtr->nextPtr;
                            }
                        }
                        break;
                    }
                    else if(currentPtr->calender.month > newnode->calender.month ||
                            currentPtr->calender.year > newnode->calender.year)
                    {
                        break;
                    }
                    else
                    {
                        prePtr = currentPtr;
                        currentPtr = currentPtr->nextPtr;
                    }
                }
                break;
            }
            else if(currentPtr->calender.year > newnode->calender.year){
                break;
            }
            else{
                prePtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
            }
        }

        if(prePtr == NULL){
            newnode->nextPtr = currentPtr;
            *startPtr = newnode;
        }else if(prePtr != NULL && currentPtr != NULL){
            newnode->nextPtr = currentPtr;
            prePtr->nextPtr = newnode;
        }else{
            prePtr->nextPtr = newnode;
        }
    }
}

int del(Node **startPtr, int delID, int ID)
{
    int choice;
    Node *prePtr, *currentPtr;
    prePtr = NULL;
    currentPtr = *startPtr;

    if(isEmpty(*startPtr))
    {
        return ID;
    }else{
        while(currentPtr != NULL)
        {
            if(currentPtr->calender.ID == ID)
            {
                break;
            }else{
                prePtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
            }
        }
        if(currentPtr == NULL)
        {
            printf("%d is not recording in the calendar.\n", ID);
            printf("1.Continue to delete\n");
            printf("2.Return to menu\n");
            printf("3.Exit\n");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    if(startPtr == NULL)
                    {
                        printf("There is no schdeule!\n");
                        printf("1.Return to Menu.\n");
                        printf("2.Adding the schdule.\n");  //unfinished
                        printf("3.Exit\n");
                        printf("Enter => ");
                        scanf("%d", &choice);
                        system("CLS");
                        switch(choice)
                        {
                            case 1:
                                return ID;
                                break;
                            case 2:
                                choice = 1;
                                while(choice == 1)
                                {
                                    ID += 1;
                                    insert(startPtr, ID);
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
                                            ID = printList(startPtr, ID);
                                            return ID;
                                            break;
                                        case 3:
                                            return ID;
                                            break;
                                        case 4:
                                            printf( "End of run.\n" );
                                            exit(1);
                                    }
                                    printf("\n");
                                }
                                return ID;
                                break;
                        case 3:
                            printf( "End of run.\n" );
                            exit(1);
                            break;
                    }
                }else{
                    printList_a(*startPtr);
                    printf("Enter ID: ");
                    scanf("%d", &delID);
                    system("CLS");
                    ID = del(startPtr, delID, ID);
                }
                    break;
                case 2:
                    break;
                case 3:
                    printf( "End of run.\n" );
                    exit(1);
                    break;
            }
        }else if(prePtr == NULL){
            *startPtr = currentPtr->nextPtr;
            free(currentPtr);
        }else if(prePtr != NULL && currentPtr->nextPtr != NULL){
            prePtr->nextPtr = currentPtr->nextPtr;
            free(currentPtr);
        }else{
            prePtr->nextPtr = NULL;
            free(currentPtr);
        }
    }
    return ID;
}
