int calculatePlayerPoints(Match match, int playerId)
{
    int points = 0;

    // WIN / LOSS
    if(match.winnerId == playerId)
    {
        points += 10;
    }
    else
    {
        points -= 3;
    }

    // BONUS 2 SETS
    if(match.twoSetsWinnerId == playerId)
    {
        points += 3;
    }

    // ACES
    if(match.player1Id == playerId)
    {
        points += match.player1Aces * 2;
        points += match.player1Breaks * 0.5;
        points -= match.player1DoubleFaults;
    }
    else
    {
        points += match.player2Aces * 2;
        points += match.player2Breaks * 0.5;
        points -= match.player2DoubleFaults;
    }

    return points;
}

void showTournamentRanking()
{
    FILE *fp;

    Match match;

    int playerIds[100];
    int totalPoints[100];

    int count = 0;

    int i;
    int found;

    fp = fopen("matches.dat", "rb");

    if(fp == NULL)
    {
        printf("Nessun match trovato!\n");
        return;
    }

    while(fread(&match, sizeof(Match), 1, fp))
    {
        int p1Points;
        int p2Points;

        p1Points = calculatePlayerPoints(match, match.player1Id);

        p2Points = calculatePlayerPoints(match, match.player2Id);

        // PLAYER 1
        found = 0;

        for(i = 0; i < count; i++)
        {
            if(playerIds[i] == match.player1Id)
            {
                totalPoints[i] += p1Points;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            playerIds[count] = match.player1Id;
            totalPoints[count] = p1Points;
            count++;
        }

        // PLAYER 2
        found = 0;

        for(i = 0; i < count; i++)
        {
            if(playerIds[i] == match.player2Id)
            {
                totalPoints[i] += p2Points;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            playerIds[count] = match.player2Id;
            totalPoints[count] = p2Points;
            count++;
        }
    }

    fclose(fp);

    printf("\n===== TOURNAMENT RANKING =====\n");

    for(i = 0; i < count; i++)
    {
        printf("\nPlayer %d -> %d punti",
               playerIds[i],
               totalPoints[i]);
    }

    printf("\n");
}
