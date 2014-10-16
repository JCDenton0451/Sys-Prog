struct node {
    struct node*next;
    char*vorname;
    char*nachname;
};

void printList(struct node*head);
void freeList(struct node*head);
struct node*insertSorted(char*nachname, char*vorname, struct node*head);
