#include <stdio.h>
int pieceValide(int p) {
    if (p == 10 || p == 20 || p == 50 || p == 100 || p == 200){
         return 1;
    }
    return 0;
}

int main() {
    int etat = 0;              
    int choix;
    int prix = 0;
    int verse = 0;
    int piece;

    do {
        switch (etat) {
        case 0:  
            printf("\n1.Cafe 120c  2.The 100c  3.Chocolat 150c  0.Quitter : ");
            scanf("%d", &choix);
            if (choix == 1) prix = 120;
            else if (choix == 2) prix = 100;
            else if (choix == 3) prix = 150;
            if (choix >= 1 && choix <= 3) { verse = 0; etat = 1; }
            else if (choix != 0) printf("Choix invalide\n");
            break;

        case 1:  
            printf("Reste %d c. Piece (0 = annuler) : ", prix - verse);
            scanf("%d", &piece);
            if (piece == 0) { printf("Rendu : %d c\n", verse); etat = 0; }
            else if (!pieceValide(piece)) printf("Piece refusee\n");
            else { verse += piece; if (verse >= prix) etat = 2; }
            break;

        case 2:  
            if (verse > prix) printf("Monnaie : %d c\n", verse - prix);
            printf("Boisson servie !\n");
            etat = 0;
            break;
        }
    } while (choix != 0);

    return 0;
}