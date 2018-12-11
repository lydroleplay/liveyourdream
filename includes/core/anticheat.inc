#include <sampcac>
#include <ArrayList>
#include <YSI\y_hooks>

new ArrayList:AC_factions;

hook OnGameModeInit() {
    AC_factions = NewArrayList<INTEGER>(11);

    // Define factions that must use the AC
    ArrayList::Add(AC_factions, 1); // LSPD
    ArrayList::Add(AC_factions, 2); // FBI
    ArrayList::Add(AC_factions, 6); // Grove Street
    ArrayList::Add(AC_factions, 7); // Ballas
    ArrayList::Add(AC_factions, 10); // Yakuza
    ArrayList::Add(AC_factions, 11); // Aztecas
    ArrayList::Add(AC_factions, 12); // LCN 
    ArrayList::Add(AC_factions, 13); // Vagos
    ArrayList::Add(AC_factions, 14); // Hitman
    ArrayList::Add(AC_factions, 17); // Wheelman
    ArrayList::Add(AC_factions, 20); // OutlawZ
    ArrayList::Add(AC_factions, 21); // Triaden

    // Define allowed glitches
    CAC_SetGlitchStatus(CAC_GLITCH__ALL, 0);
    CAC_SetGlitchStatus(CAC_GLITCH__FASTMOVE, 1);
    CAC_SetGlitchStatus(CAC_GLITCH__FASTSPRINT, 1);
    CAC_SetGlitchStatus(CAC_GLITCH__QUICKSTAND, 1);

    // Define allowed game options
    CAC_SetGameOptionStatus(CAC_GAMEOPTION__ALL, 0);
    CAC_SetGameOptionStatus(CAC_GAMEOPTION__VEHICLEBLIPS, 1);
    CAC_SetGameOptionStatus(CAC_GAMEOPTION__SPRINT, CAC_GAMEOPTION_STATUS__SPRINT_ALLSURFACES);

    // Define disallowed game ressources (reporting)
    CAC_SetGameResourceReportStatus(CAC_GAMERESOURCE_MODELTYPEFLAG__ALL, 0);
    CAC_SetGameResourceReportStatus(CAC_GAMERESOURCE_MODELTYPEFLAG__PEDIFP, 1);

    CAC_SetGameResourceReportType(CAC_GAMERESOURCE_REPORTTYPE__ONLY_IF_MODDED);

    return 1;
}

hook OnPlayerSpawn(playerid) {
	if (gPlayerLogged[playerid] && ArrayList::IndexOf(AC_factions, Spieler[playerid][pFraktion]) > -1 && !CAC_GetStatus(playerid))
        return AC_kick(playerid, "Anti-Cheat Client Pflicht");

    return 1;
}

public CAC_OnPlayerKick(player_id, reason_id) {
    static const kickReasons[][] = { "Verbindungsprobleme mit dem AC Client", "AC Client Version nicht kompatibel" };

    if(IsPlayerConnected(player_id))
        AC_kick(player_id, kickReasons[reason_id]);

    return 1;
}

public CAC_OnCheatDetect(player_id, cheat_id, opt1, opt2) {    
    switch (cheat_id) {
        case CAC_CHEAT__AIMBOT_1,
             CAC_CHEAT__AIMBOT_2,
             CAC_CHEAT__AIMBOT_3,
             CAC_CHEAT__AIMBOT_4,
             CAC_CHEAT__AIMBOT_5,
             CAC_CHEAT__AIMBOT_6: {
            AC_ban(player_id, "Aimbot");
        }

        case CAC_CHEAT__TRIGGERBOT_1,
             CAC_CHEAT__TRIGGERBOT_2: {
            AC_ban(player_id, "Triggerbot");
        }

        case CAC_CHEAT__NAMETAG_1: {
            AC_ban(player_id, "Nametag ESP");
        }

        case CAC_CHEAT__ESP_1: {
            AC_ban(player_id, "ESP");
        }

        case CAC_CHEAT__FAKE_PING_1: {
            AC_kick(player_id, "Fake Ping");
        }

        case CAC_CHEAT__WEAPON_INFO_1: {
            AC_ban(player_id, "Ver‰nderungen in der weapon.dat Datei");
        }

        case CAC_CHEAT__NORECOIL_1,
             CAC_CHEAT__NORECOIL_2,
             CAC_CHEAT__NORECOIL_3: {
            AC_ban(player_id, "NoRecoil");
        }

        case CAC_CHEAT__UNTRUSTED_1,
             CAC_CHEAT__UNTRUSTED_2,
             CAC_CHEAT__UNTRUSTED_3,
             CAC_CHEAT__UNTRUSTED_4: {
            AC_kick(player_id, "Verd‰chtiges Verhalten");
        }
    }

    return 1;
}

public CAC_OnGameResourceMismatch(player_id, model_id, component_type, checksum) {
    if (model_id == CAC_GAMERESOURCE_MODELID__PEDIFP)
        AC_kick(player_id, "Ver‰nderungen in der PED.IFP Datei");
    
    return 1;
}

AC_kick(playerid, reason[]) {
    new string[256];

    format(string, sizeof(string), "[KICK]: Spieler %s wurde vom Anti-Cheat aus dem Server gekickt. Grund: %s", GetName(playerid), reason);
    SendAdminMessage(COLOR_RED, string);

    format(string, sizeof(string), "[KICK] Du wurdest soeben vom Anti-Cheat aus dem Server gekickt. Grund: %s", reason);
    SendClientMessage(playerid, COLOR_RED, string);

    format(string, sizeof(string), "Du wurdest aufgrund eines Regelverstoﬂes (oder einem anderen Grund) aus dem Server gekickt!\nDu wurdest vom Anti-Cheat aus dem Server gekickt!\nGrund: %s", reason);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "Kick Information", string, "Exit", "");

    KickDelay(playerid);

    return 1;
}

AC_ban(playerid, reason[]) {
    new string[256];

    format(string, sizeof(string), "[BANNED]: Spieler %s wurde vom Anti-Cheat dauerhaft aus dem Server gebannt, Grund: %s", GetName(playerid), reason);
    SendAdminMessage(COLOR_RED, string);

    format(string, sizeof(string), "[BANNED] Du wurdest soeben vom Anti-Cheat dauerhaft aus dem Server gebannt. Grund: %s", reason);
    SendClientMessage(playerid, COLOR_RED, string);
    SendClientMessage(playerid, COLOR_RED, "Sind Sie der Meinung das diese Sperre falsch war? Dann schreiben Sie auf www.LyD-Roleplay.de ein Entbannantrag!");

    mysql_real_escape_string(reason, reason);
    format(string, sizeof(string), "UPDATE `accounts` SET `GebanntVon` = 'Anti-Cheat', `BanGrund` = '%s', `Banned` = 1 WHERE `Name` = '%s'", reason, GetName(playerid));
    mysql_pquery(string, THREAD_BAN, playerid, gSQL, MySQLThreadOwner);

    format(string, sizeof(string), "Gebannt: %s von: Anti-Cheat, Grund: %s, Dauer: %s", GetName(playerid), reason, "Immer");
    BanLog(string);

    format(string, sizeof(string), "%s wurde vom Anti-Cheat dauerhaft gebannt, Grund: %s", GetName(playerid), reason);
    SendUCPAktenEintrag(playerid, "Anti-Cheat", GetName(playerid), string);

    format(string, sizeof(string), "Anti-Cheat hat Spieler %s dauerhaft gebannt, Grund: %s", GetName(playerid), reason);
    AdminLog(string);
    
    return 1;
}