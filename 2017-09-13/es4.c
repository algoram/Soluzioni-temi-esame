#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int dato1;
    char dato2;
} Dati;

typedef struct node {
    Dati dati;
    struct node* next;
} Node;

typedef Node* List;

void List2File(List l);
List File2List();
List insert(List l, Dati d); // funzione per provare
void printList(List l); // funzione per provare

int main() {
    List l1 = NULL;
    List l2;
    Dati d;

    d.dato1 = 1;
    d.dato2 = 'a';
    l1 = insert(l1, d);

    d.dato1 = 2;
    d.dato2 = 'b';
    l1 = insert(l1, d);

    d.dato1 = 3;
    d.dato2 = 'c';
    l1 = insert(l1, d);

    printList(l1);

    List2File(l1);

    l2 = File2List();

    printList(l2);

    return 0;
}

void List2File(List l) {
    FILE* file = fopen("Contents.dat", "wb");

    while (l != NULL) {
        fwrite(&(l->dati), sizeof(struct data), 1, file);

        l = l->next;
    }

    fclose(file);
}

List File2List() {
    FILE* file = fopen("Contents.dat", "rb");
    int byteLetti;
    Dati temp;
    List list = NULL;

    while ((byteLetti = fread(&temp, sizeof(Dati), 1, file)) > 0) {
        list = insert(list, temp);
    }

    fclose(file);

    return list;
}

// uso l'inserimento in testa, si poteva usare anche quello in coda
List insert(List l, Dati d) {
    Node* newNode = malloc(sizeof(Node));

    newNode->dati = d;
    newNode->next = l;

    return newNode;
}

void printList(List l) {
    while (l != NULL) {
        printf("(%d, %c) ", l->dati.dato1, l->dati.dato2);

        l = l->next;
    }
    printf("\n");
}
