#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "HA03_linkedListLib.h"

void addListElem(listElement *start)
{

    listElement *new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL)
    {
        printf("can't reserve storage.\n");
        return;
    }

    listElement *currElem = start;
    while (currElem->nextElem != NULL)
        currElem = currElem->nextElem; // get last elem in list
    currElem->nextElem = new;          // add new to the end of list
    new->nextElem = NULL;

    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);
    printf("Please enter first name: \n");
    scanf("%s", new->firstName);
    printf("Please enter age: \n");
    scanf("%d", &(new->age));
    printf("end of function\n");
}

void printList(listElement *start)
{

    if (start->nextElem == NULL)
        printf("List is empty.\n");
    else
    {
        int i = 0;
        listElement *currElem = start;
        printf("\ncurrent list:\n\n");
        do
        {
            currElem = currElem->nextElem;
            printf("%d", i);
            i++;
            printf("\t last name: %s\n", currElem->lastName);
            printf("\t first name: %s\n", currElem->firstName);
            printf("\t age: %d\n", currElem->age);
        } while (currElem->nextElem != NULL);
    }
    printf("\n");
}

void delListElem(listElement *start)
{
    listElement *currentElem = start;
    int index;
    int i = 0;
    if(start->nextElem == NULL){
        printf("List is already empty\n\n");
        return;
    }
    
    printf("Which element do you want to delete?\n");
    printList(start);
    scanf("%d", &index);

    do{
        if(i == index){
            listElement *deletedElem = currentElem->nextElem;
            currentElem->nextElem = currentElem->nextElem->nextElem; 
            free(deletedElem);
            printf("\nElement %d was deleted\n\n", index);
            return;
        }
        else{
            currentElem = currentElem->nextElem;
        }
        i++;
    }while(currentElem->nextElem != NULL);

    printf("\nCould not find Element %d\n\n", index);
}

void delList(listElement *start)
{
    if(start->nextElem == NULL){
        printf("List is already empty\n\n");
        return;
    }

    listElement *currElem = start->nextElem;
    listElement *next = NULL;
    while (currElem->nextElem != NULL)
    {
        next = currElem->nextElem;
        free(currElem);
        currElem = next;
    }
    
    start->nextElem = NULL;

    printf("\nList was deleted.\n\n");
}

int getLenOfList(listElement *start)
{ // we use this for save list fcn

    int counter = 0;
    listElement *currElem = start;
    while (currElem->nextElem != NULL)
    { // get last elem in list
        currElem = currElem->nextElem;
        counter++;
    }
    return counter;
}

void saveList(listElement *start)
{
    FILE *fp;
    char filename[50];
     
    printf("Type in filename:");
    scanf("%s", filename);
    strcat(filename, ".txt");
    printf("\nfilename: %s\n", filename);

    //open output File
    fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Could not create file");
        return;
    }

    if (start->nextElem != NULL)
    {
        int i = 0;
        listElement *currElem = start;
        fprintf(fp, "list contents:\n\n");
        do
        {
            currElem = currElem->nextElem;
            fprintf(fp, "%d", i);
            i++;
            fprintf(fp, "\t last name: %s\n", currElem->lastName);
            fprintf(fp, "\t first name: %s\n", currElem->firstName);
            fprintf(fp, "\t age: %d\n", currElem->age);
        } while (currElem->nextElem != NULL);
    }
    fprintf(fp, "\n");

    fclose(fp);
    printf("saving completed\n\n", filename);
}

void loadList(listElement *start)
{

    /* YOUR CODE HERE */
    /* ---------------*/

    printf("\n>> loadList fcn is tbd.\n\n");

    printf("loading data will be append to current list...\n");
    printList(start); // show loaded list
}

void exitFcn(listElement *start)
{

    printf("\n>> exitFcn fcn is tbd.\n\n");
}

void sortList(listElement *start)
{

    printf("\n>>sortList fcn is tbd.\n\n");
}

void stringToLower(char *string)
{

    printf("\n>>stringToLower fcn is tbd.\n\n");
}