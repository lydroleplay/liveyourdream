#include <YSI\y_hooks>

static SW_score[MAX_FACTIONS];

#define SW_STREETWAREND 22

task SW_checkStreetwarEnd[60000]() {
    new hour, minute;
    gettime(hour, minute);

    if (hour != SW_STREETWAREND || minute != 0)
       return 1;
    
    new highScore = 0, winnerCount = 0;
    for (new i; i < MAX_FACTIONS; i++) // find high score
        if (SW_score[i] > highScore) highScore = SW_score[i];

    for (new i; i < MAX_FACTIONS; i++) // count winners
        if (SW_score[i] == highScore) winnerCount++;

    new money, wamount, damount;

    money = floatround(RandomEx(100000, 150000) / winnerCount, floatround_ceil);
    wamount = floatround(RandomEx(20000, 30000) / winnerCount, floatround_ceil);
    damount = floatround(RandomEx(400, 600) / winnerCount, floatround_ceil);

    new message[144], winners[144];

    for (new i; i < MAX_FACTIONS; i++) {
        if (SW_score[i] == highScore && highScore != 0) {
            if (i == 6) Kasse[Grove] += money;
            else if (i == 7) Kasse[Ballas] += money;
            else if (i == 10) Kasse[Yakuza] += money;
            else if (i == 11) Kasse[Aztecas] += money;
            else if (i == 12) Kasse[LCN] += money;
            else if (i == 13) Kasse[Vagos] += money;
            else if (i == 14) Kasse[Hitman] += money;
            else if (i == 20) Kasse[OutlawzK] += money;
            else if (i == 21) Kasse[ndgradethaK] += money;

            g_FraktionsSafeBox[i][FSB_iDrogen] += damount;
            g_FraktionsSafeBox[i][FSB_iWaffenteile] += wamount;

            format(winners, sizeof(winners), "%s%s, ", winners, factionNames[i]);

            format(message, sizeof(message), "[Streetwar] {FFFFFF}Gewinn: $%s, %s Waffenteile und %sg Drogen", AddDelimiters(money), AddDelimiters(wamount), AddDelimiters(damount));
            SendFraktionMessage(i, COLOR_YELLOW, message); 
        }

        SW_score[i] = 0;
    }

    if (highScore) {
        winners[strlen(winners) - 2] = EOS;
        format(winners, sizeof(winners), "[Streetwar] {FFFFFF}Gewinner des heutigen Streetwars: %s", winners);
        SendClientMessageToAll(COLOR_DARKGREEN, winners);
    } else
        SendClientMessageToAll(COLOR_DARKRED, "[Streetwar] {FFFFFF}Keine Gang oder Mafia hat Punkte erkämpft. Niemand hat eine Belohnung bekommen.");

    return 1;
}

CMD:swinfo(playerid, params[]) return cmd_streetwarinfo(playerid, params);
CMD:streetwarinfo(playerid, params[]) {
    new dialogText[256] = "Gang / Mafia\tStreetwar-Punkte\n";

    for (new i = 0; i < sizeof(factionNames); i++)
        if (IsAFightFaction(i))
            format(dialogText, sizeof(dialogText), "%s%s\t%d\n", dialogText, factionNames[i], SW_score[i]);

    return ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_TABLIST_HEADERS, "{32B232}Streetwar Info", dialogText, "Schließen", "");
}

forward LoadStreetwar();
public LoadStreetwar() {
    for (new i; i < cache_get_row_count(); i++)
        SW_score[cache_get_field_content_int(i, "factionid", gSQL)] = cache_get_field_content_int(i, "score", gSQL);

    return 1;
}

hook OnGameModeInit2() {
    mysql_tquery(gSQL, "SELECT * FROM `streetwar`", "LoadStreetwar");
    return 1;
}

hook SaveAll() {
    saveStreetwar();
    return 1;
}

hook OnGameModeExit() {
    saveStreetwar();
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason) {
    if (Spieler[playerid][pFraktion] == Spieler[killerid][pFraktion]) return 1;
    if (IsAFightFaction(Spieler[playerid][pFraktion]) && killerid != INVALID_PLAYER_ID && IsAFightFaction(Spieler[killerid][pFraktion])) {
        new fightid = GetGangFight(Spieler[playerid][pFraktion]);
        if (fightid != GetGangFight(Spieler[killerid][pFraktion]) || fightid == -1) {
            new message[128], rk[35];
            
            ReturnPlayerRank(killerid, rk);
            format(message, sizeof(message), "[Streetwar] {FFFFFF}%s %s hat %s (%s) getötet.", rk, GetName(killerid), GetName(playerid), factionNames[Spieler[playerid][pFraktion]]);
            GameTextForPlayer(killerid, "+1 Streetwarkill", 3000, 4);
            SendFraktionMessage(Spieler[killerid][pFraktion], COLOR_DARKGREEN, message);
            SW_score[Spieler[killerid][pFraktion]]++;
            Spieler[killerid][pKillsStreetwar]++;
        }
    }
    
    return 1;
}

stock saveStreetwar() {
    new query[128];
    for (new i = 0; i < sizeof(factionNames); i++) {
        format(query, sizeof(query), "INSERT INTO `streetwar` (factionid, score) VALUES (%d, %d) ON DUPLICATE KEY UPDATE factionid = %d, score = %d", i, SW_score[i], i, SW_score[i]);
        mysql_pquery(gSQL, query);
    }

    return 1;
}
