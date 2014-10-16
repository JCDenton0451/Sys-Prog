#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

int main() {
    char*filename = malloc(sizeof(char)*100);
    char puffer[200];
    
    printf("Name der Datei: "); // Dateinamen einlesen
    scanf("%s", filename);
    
    struct node*head=NULL;    
    FILE*f = fopen(filename, "r"); // Datei zum Lesen öffnen
    
    char*vorname;
    char*nachname;
    while(fgets(puffer, 200, f)) { // Zeilenweise lesen
        vorname=malloc(100);
        nachname=malloc(100);
        int b=0;
        //int real_v;
        //int real_n;
        int i;
        for(i=0; i<sizeof(puffer); i++) {
            if(b==0) { // Vornamen trennen
                if(puffer[i]!=' ') {
                    //vorname=realloc(vorname, sizeof(char)*(i+1));
                    vorname[i]=puffer[i];
                } else {
                    vorname[i]='\0';
                    //real_v=i;
                    b=i+1;
                }
            } else { // Nachnamen trennen
                if(puffer[i]!='\n') {
                   //.nachname=realloc(nachname, sizeof(char)*(i-b+1));
                   nachname[i-b]=puffer[i];
                } else {
                   nachname[i-b]='\0';
                   //real_n=i-b;
                   break;
                }
            }
        }
        
        // ggf. realloc auf real_v/real_n, um Speicher zu sparen        
        head = insertSorted(nachname, vorname, head);   
    }
    printList(head); // Liste ausgeben
    fclose(f); // Filestream schließen
    
    freeList(head); // Speicherplatz freigeben
    return 0;
}















