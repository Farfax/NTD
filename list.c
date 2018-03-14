#include <stdio.h>
#include <malloc.h>

typedef struct Node
Node;

struct Node 
{
        Node* next;
        int value;
        Node* last;
};

void initList(Node* list)
{
        list->next=NULL;
        list->value=-1;
        list->last=NULL;
}
void addNode(Node* list, int value) 
{

        Node* temp = malloc(sizeof(Node));
        temp->value = value;

        if (!list->next) 
        { // gdy brak pierwszego
                list->next = temp;
                list->last = temp;
                return;
        }

        list->last->next = temp;
        list->last = temp;

}

void removeAll(Node* list, int value) 
{

        if (!list->next) // lista jest pusta, wiec konczymy nasza funkcje
                return;

        Node* node = list->next;

        if (!node->next) 
        { // przypadek gdy lista ma jeden element
                if (node->value == value)
                {
                        free(node); // usuwamy gdy jest rowny naszej wartosci
                        list->next = NULL;
                }
                return; // wychodzimy, bo nie ma wiecej elementow do sprawdzenia
        }

        Node* prev=node;
        node=node->next;

        while(node) // sprawdzamy po dwa elementy,
        {
                if (node->value == value)
                {
                        prev->next=node->next;
                        free(node);
                        node=prev;
                }

                prev=node;
                node = node->next;
        }

        // Naprawa elementu ostatniego
        list->last=prev;
}
void printList(Node* list)
{
        Node* node=list->next;

        while(node)
        {
                printf("%d ", node->value);
                node=node->next;
        }
}
int main() 
{
        Node lista;
        initList(&lista);

        addNode(&lista, 1);
        addNode(&lista, 2);
        addNode(&lista, 3);
        addNode(&lista, 3);
        addNode(&lista, 4);
        addNode(&lista, 2);
        addNode(&lista, 5);
        addNode(&lista, 3);
        removeAll(&lista,3);
        printList(&lista);
        return 0;
}
