#include <stdio.h>
#include "stdlib.h"

void remplir(int l[12]) {
    for (int a = 0 ; a < 12 ; a++) {
        l[a] = 4;
    }
}

void affichage(int l[12] , int p1 , int p2) {
    printf("==============\n");
    printf("   1 2 3 4 5 6\n\n");
    printf("1  ");
    for (int a = 5; a >= 0; a--) {
        printf("%i ", l[a]);
    }
    printf("     Joueur 1 : %i points\n", p1);
    printf("2  ");
    for (int a = 6; a < 12; a++) {
        printf("%i ", l[a]);
    }
    printf("     Joueur 2 : %i points\n\n", p2);
}

int player(int l[12] , int x , int p1 , int p2){
    int v;
    int w;
    printf ("Joueur %i, choisis une case de la ligne numero %i :\n", x+1, x+1);
    if (x == 0){
        do {
            scanf("%i", &v);
        }while (v <= 0 || v > 6 || l[-(v-1) + 5] == 0);
        v = -(v-1) + 5;
        w = v;

        while (l[v] > 0) {
            w += 1;
            if (w == 12) {
                w = 0;
            }
            l[w] += 1;
            l[v] -= 1;
        }
        while ((l[w] == 2 || l[w] == 3) && (w >= 6 && w <= 11)) {
            p1 += l[w];
            l[w] = 0;
            w -= 1;
        }
        return p1;
    }
    if (x == 1) {
        do {
            scanf("%i", &v);
        }while (v <= 0 || v > 6 || l[-(-(v-1) + 5) + 11] == 0);
        v = -(-(v-1) + 5) + 11;
        w = v;
        while (l[v] > 0) {
            w += 1;
            if (w == 12) {
                w = 0;
            }
            l[w] += 1;
            l[v] -= 1;
        }
        while ((l[w] == 2 || l[w] == 3) && (w >= 0 && w <= 5)) {
            p2 += l[w];
            l[w] = 0;
            w -= 1;
        }
        return p2;
    }
}

void tableauDeScore(int p1 , int p2) {
    printf ("              SCORE\n\n");
    if (p1 > p2) {
        printf ("    WINNER\n");
    }
    if (p1 < p2) {
        printf ("                      WINNER\n");
    }
    printf ("   Joueur 1 :        Joueur 2 :\n"
            "   %i points         %i points\n\n", p1, p2);
}

void pvp(int l[12] , int p1 , int p2) {
    int x;
    remplir (l);
    affichage (l , p1 , p2);
    while (l[0]+l[1]+l[2]+l[3]+l[4]+l[5] != 0 || l[6]+l[7]+l[8]+l[9]+l[10]+l[11] != 0) {
        x = 0;
        p1 = player (l , x , p1 , p2);
        affichage (l , p1 , p2);
        x = 1;
        p2 = player (l , x , p1 , p2);
        affichage (l , p1, p2);
    }
}

int main() {
    printf ("=================AWALE================\n\n\n");
    int x;
    int p1 = 0;
    int p2 = 0;
    int y = 0;
    int l[12];
    do {
        printf ("MENU :\n\n"
                "1 - Joueur vs Joueur\n"
                "2 - Joueur vs IA\n"
                "3 - Exit game\n\n");
        do {
            scanf ("%i", &x);
        }while (x <= 0 || x > 3);
        switch (x){
            case 1:
                pvp (l , p1 , p2);
                tableauDeScore (p1 , p2);
                break;
            case 2:
                break;
            case 3:
                y += 1;
                printf ("       Merci d'avoir joue !\n\n");
                break;
        }
    }while (y == 0);
}