#include <stdio.h>
#include "models.h"
#include "ranking.h"

// ==================== CALCULATE PLAYER POINTS ====================

int calculatePlayerPoints(Match match, int playerId)
{
    int points = 0;

    // PLAYER 1
    if(playerId == match.player1Id)
    {
        // Vittoria
        if(match.winnerId == playerId)
        {
            points += 10;
        }

        // Ace
        points += match.ace1 * 2;

        // Break
        points += match.break1;

        // Doppi falli
        points -= match.doppiFalli1;
    }

    // PLAYER 2
    else if(playerId == match.player2Id)
    {
        // Vittoria
        if(match.winnerId == playerId)
        {
            points += 10;
        }

        // Ace
        points += match.ace2 * 2;

        // Break
        points += match.break2;

        // Doppi falli
        points -= match.doppiFalli2;
    }

    return points;
}

// ==================== SHOW TOURNAMENT RANKING ====================

void showTournamentRanking()
{
    FILE *fp;

    Match match;

    fp = fopen("matches.dat", "rb");

    if(fp == NULL)
    {
        printf("Nessun match trovato!\n");
        return;
    }

    printf("\n===== TOURNAMENT RANKING =====\n");

    while(fread(&match, sizeof(Match), 1, fp))
    {
        int p1Points;
        int p2Points;

        p1Points = calculatePlayerPoints(match, match.player1Id);

        p2Points = calculatePlayerPoints(match, match.player2Id);

        printf("\nPlayer %d -> %d punti",
               match.player1Id,
               p1Points);

        printf("\nPlayer %d -> %d punti\n",
               match.player2Id,
               p2Points);
    }

    fclose(fp);
}
