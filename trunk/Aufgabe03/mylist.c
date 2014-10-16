#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"
#include "stringfunc.h"


void printList(struct node*head) {
    struct node*cursor=head;
    while(cursor!=NULL) {
        printf("%s %s\n", cursor->vorname, cursor->nachname);
        cursor=cursor->next;
    }
}

void freeList(struct node*head) {
    struct node*prev=NULL;
    struct node*cursor=head;
    
    while(cursor!=NULL) {
        if(prev != NULL) {
             free(prev->vorname);
             free(prev->nachname);
             free(prev);
        }
        prev=cursor;
        cursor=cursor->next;
    }
}

// Diese Funktion fügt den Namen sortiert in die Liste ein.
// Sie ist kein void, da ggf. nach Ausführung ein neuer Kopf der Liste vorhanden ist, der zurückgegeben wird.
struct node*insertSorted(char*nachname, char*vorname, struct node*head) {
    char cursor_vorname[100]; // Chararrays mit Speicherplatz für die je max. 100 Zeichen langen Namen
    char cursor_nachname[100];
    struct node*cursor=head;
    struct node*tmp = malloc(sizeof(struct node)); // Speicherallokation für den neuen Eintrag
    tmp->nachname = nachname;
    tmp->vorname = vorname;
    tmp->next=NULL;
    
    if(head==NULL) return tmp; // Falls Liste noch leer
    struct node*prev; // enthält je das vorangegangene Element in der Liste
    do {
        if(cursor==NULL) break;
        // Abfragen ob hiervor hätte eingefügt werden sollen
        if(cmp(nachname, vorname, cursor->nachname, cursor->vorname)) {
          //  printf("Prüfung ergab: %s %s soll vor %s %s eingefügt werden\n", nachname, vorname, cursor->nachname, cursor->vorname);

            if(cursor==head) {
                    //printf("KKKKKKKKK %s --- %s\n", vorname, nachname);
                    //printList(head);
                tmp->next = head;
                return tmp; // dies ist der neue Kopf der Liste
            } else {
                prev->next = tmp; // Zwischendrin einfügen
                tmp->next = cursor; 
                return head; // Listenkopf unverändert
            }
        }
        
        prev=cursor;
        cursor=cursor->next; // Nächstes Element betrachten
    } while(1);

    // Hinten einfügen
    prev->next = tmp;
    return head;
}

