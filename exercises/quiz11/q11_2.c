/* Arinah Karim
 * CSCI-C 291/Spring 2021
 * 3/22/2021
 */

//This program is supposed to scan 5 ints from the user
//Using those 5 ints, it should construct a linked list of 5 elements
//Then it prints the elements of the list using the PrintList function


#include <stdio.h>
#include <stdlib.h>

struct Node{
        int data;
        struct Node* next;
};
void PrintList(struct Node* n);
int main(void){
        struct Node* first = {0, 0};
        struct Node* second = {0, 0};
        struct Node* third = {0, 0};
        struct Node* fourth = {0, 0};
        struct Node* fifth = {0, 0};



        first = (struct Node*)malloc(sizeof(struct Node));
        second = (struct Node*)malloc(sizeof(struct Node));
        third = (struct Node*)malloc(sizeof(struct Node));
        fourth = (struct Node*)malloc(sizeof(struct Node));
        fifth = (struct Node*)malloc(sizeof(struct Node));

        int i;
        printf("First data: ");
        scanf(" %d", &i);
        first->data = i;

        printf("\nSecond data: ");
        scanf(" %d", &i);
        second->data = i;
        first->next = second;

        printf("\nThird data: ");
        scanf(" %d", &i);
        third->data = i;
        second->next = third;

        printf("\nFourth data: ");
        scanf(" %d", &i);
        fourth->data = i;
        third->next = fourth;

        printf("\nFifth data: ");
        scanf(" %d", &i);
        fifth->data = i;
        fourth->next = fifth;
        fifth->next = NULL;

        PrintList(first);
}

void PrintList(struct Node* n){
        while(n != NULL){
                printf("%d ", n->data);
                n = n->next;
        }

        printf("\n");
}
