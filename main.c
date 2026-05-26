#include <stdio.h>

#include "players.h"
#include "tornei.h"
#include "ranking.h"
#include "coach.h"
#include "squadre.h"

void menuAdmin() {

    int scelta;

    do {

        printf("\n========== MENU ADMIN ==========\n");
        printf("1. Gestione Tennisti\n");
        printf("2. Gestione Tornei\n");
        printf("3. Ranking\n");
        printf("0. Torna indietro\n");

        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta) {

            case 1:
                menuPlayers();
                break;

            case 2:
                menuTornei();
                break;

            case 3:
                menuRanking();
                break;

            case 0:
                printf("Ritorno...\n");
                break;

            default:
                printf("Scelta non valida!\n");
        }

    } while(scelta != 0);
}

void menuCoach() {

    int scelta;

    do {

        printf("\n======= MENU FANTA COACH =======\n");
        printf("1. Registrazione Coach\n");
        printf("2. Creazione Squadra\n");
        printf("3. Modifica Squadra\n");
        printf("4. Visualizza Squadra\n");
        printf("0. Torna indietro\n");

        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta) {

            case 1:
                registerCoach();
                break;

            case 2:
                createTeam();
                break;

            case 3:
                modifyTeam();
                break;

            case 4:
                displayTeam();
                break;

            case 0:
                printf("Ritorno...\n");
                break;

            default:
                printf("Scelta non valida!\n");
        }

    } while(scelta != 0);
}

int main() {

    int scelta;

    do {

        printf("\n====================================\n");
        printf("         FANTA TENNIS GAME          \n");
        printf("====================================\n");

        printf("1. Admin\n");
        printf("2. Fanta Coach\n");
        printf("3. Ranking Generale\n");
        printf("0. Esci\n");

        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta) {

            case 1:
                menuAdmin();
                break;

            case 2:
                menuCoach();
                break;

            case 3:
                menuRanking();
                break;

            case 0:
                printf("Uscita dal programma...\n");
                break;

            default:
                printf("Scelta non valida!\n");
        }

    } while(scelta != 0);

    return 0;
}
