#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Calender{
    int ID;             //how to delete the schedule
    int year;           //time
    int month;
    int day;
    char item[100];     //schedule
};

typedef struct ListNode{
    struct Calender calender;
    struct ListNode *nextPtr;
}Node;

void information();
void insert(Node **startPtr, int ID);   //insert the Node
int del(Node **startPtr, int delID, int ID);       //delete the Node
int isEmpty(Node *startPtr);            //judge whether is empty
int printList(Node **startPtr, int ID); //have choice
void printList_a(Node *startPtr);       //just print
