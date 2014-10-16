#include "stringfunc.h"

int cmp(char*nachname, char*vorname, char*ref_nachname, char*ref_vorname) {
    int i;
    for(i=0; i<((sizeof(nachname)<sizeof(ref_nachname))?sizeof(nachname):sizeof(ref_nachname)); i++) {
        if(nachname[i]<ref_nachname[i]) {
            return 1;
        } else if(nachname[i]>ref_nachname[i]) {
            return 0;
        }
    }

    if(sizeof(nachname)!=sizeof(ref_nachname)) return 1; // Nachname kommt in anderem vor, sind aber nicht identisch. Kürzerer soll per Def. vorne stehen
    
    //Nachnamen gleich, Vornamen vergleichen
    for(i=0; i<((sizeof(vorname)<sizeof(ref_vorname))?sizeof(vorname):sizeof(ref_vorname)); i++) {
        if(vorname[i]<ref_vorname[i]) {
            return 1;
        } else if(vorname[i]>ref_vorname[i]) {
            return 0;
        }
    }
    // Entweder sind Vornamen (auch) identisch, oder einer kommt im anderen vor. In beiden Fällen ist das Verhalten egal.
    return 1;
}
