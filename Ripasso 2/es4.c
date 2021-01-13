/*
Esercizio A 15. Il gioco della dama si effettua su una scacchiera 8 x 8,
rappresentata da una matrice di interi ciascun elemento della quale rappresenta
una casella. Una casella può essere vuota (in tal caso l’elemento di matrice
vale 0), occupata da una “nostra” pedina (in tal caso l’elemento di matrice vale
1) oppure occupata da una pedina avversaria (in tal caso l’elemento di matrice
vale -1). Le pedine possono occupare solo caselle nere della scacchiera; le
caselle bianche pertanto sono tutte vuote. Una nostra pedina (che si trova in
una casella nera) si può spostare solamente “in avanti” cioè verso un’altra
casella nera con valore dell’indice di riga MAGGIORE di quello della casella in
cui si trova. Una nostra pedina può effettuare un “salto” di casella, cioè uno
spostamento di due caselle lungo una delle due diagonali (quella verso destra o
quella verso sinistra), solo se (i) la casella nera adiacente a quella in cui si
trova la nostra pedina è occupata da una pedina avversaria, mentre (ii) la
successiva casella nera lungo la stessa diagonale è vuota. In caso di salto la
nostra pedina si sposta nella casella destinazione mentre la pedina avversaria
che occupava la casella intermedia viene rimossa dalla scacchiera (ovvero viene
“mangiata”).


In una mossa è anche possibile effettuare un salto multiplo, costituito da più
salti consecutivi, anche lungo diagonali diverse purché sempre “in avanti”.
Scrivere una funzione ricorsiva che riceve in ingresso una scacchiera e i due
indici di posizione di una casella nera occupata da una “nostra” pedina, e –se
possibile- effettua il salto multiplo MASSIMO (cioè quello in cui viene
“mangiato” il maggior numero possibile di pedine avversarie): la funzione deve
modificare la scacchiera di conseguenza e restituire il numero di pedine
avversarie mangiate. Se non è possibile effettuare salti dalla posizione in
ingresso, la funzione non modifica la scacchiera e restituisce il valore 0.
*/

#include <stdio.h>

typedef int Scacchiera[8][8];

int mossaMigliore(Scacchiera s, int r, int c);

int main() {
  int i, j;
  Scacchiera s = {{0, 0, 1, 0, 0},
                  {0, -1, 0, -1, 0},
                  {0, 0, 0, 0, 0},
                  {0, -1, 0, 0, 0},
                  {0, 0, 0, 0, 0}};

  printf("Pedine massime mangiate: %d\n", mossaMigliore(s, 0, 2));

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("%2d ", s[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int mossaMigliore(Scacchiera s, int r, int c) {
  int dx, sx;

  // in basso a destra
  dx = 0;
  if (r + 2 < 8 && c + 2 < 8 && s[r + 1][c + 1] == -1 && s[r + 2][c + 2] == 0) {
    dx = 1 + mossaMigliore(s, r + 2, c + 2);
    s[r + 2][c + 2] = 1;
  }

  // in basso a sinistra
  sx = 0;
  if (r + 2 < 8 && c - 2 >= 0 && s[r + 1][c - 1] == -1 &&
      s[r + 2][c - 2] == 0) {
    sx = 1 + mossaMigliore(s, r + 2, c - 2);
    s[r + 2][c - 2] = 1;
  }

  if (dx == 0 && sx == 0) {
    return 0;
  }

  s[r][c] = 0;

  if (dx > 1) {
    s[r + 2][c + 2] = 0;
  }

  if (sx > 1) {
    s[r + 2][c - 2] = 0;
  }

  if (dx > sx) {
    s[r + 1][c + 1] = 0;
    s[r + 2][c - 2] = 0;

    return dx;
  }

  s[r + 1][c - 1] = 0;
  s[r + 2][c + 2] = 0;

  return sx;
}
