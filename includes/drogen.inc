#define MAX_DROGEN_PFLANZEN 200
#define DROGENPFLANZE_REIF 2*60*60
//#define DROGENPFLANZE_REIF 2*60
#define DROGENPFLANZE_UEBERREIF 15*60
#define DROGENPFLANZEN_WASSER_COOLDOWN 60*60
#define DROGENPFLANZEN_WASSER_NOTICE 10*60

enum e_DrogenPflanzen {
	Float:DP_fX,
	Float:DP_fY,
	Float:DP_fZ,
	DP_iObject,
	DP_iFireObject,
	DP_iWasser,
	DP_iFortschritt,
	bool:DP_bInUse,
	bool:DP_bDestroyed
}

new g_DrogenPflanzenCount = 0;
new g_DrogenPflanzen[MAX_DROGEN_PFLANZEN][e_DrogenPflanzen];

stock InitDrogenPflanzen() {
	SetTimer("Pulse_DrogenPflanzen",997,true);
	return 1;
}

stock CreateDrogenPflanzen( Float:x,Float:y,Float:z ) {
	new
	    index;
	index = GetFreeDrogenPflanzenSlot();
	if( index == -1 ) {
	    return 0;
	}
    g_DrogenPflanzen[index][DP_fX] = x;
    g_DrogenPflanzen[index][DP_fY] = y;
    g_DrogenPflanzen[index][DP_fZ] = z;
    g_DrogenPflanzen[index][DP_iWasser] = DROGENPFLANZEN_WASSER_COOLDOWN + 15;
    g_DrogenPflanzen[index][DP_iFortschritt] = 0;
    g_DrogenPflanzen[index][DP_bInUse] = true;
    g_DrogenPflanzen[index][DP_bDestroyed] = false;
    g_DrogenPflanzenCount++;
    g_DrogenPflanzen[index][DP_iObject] = CreateDynamicObject( 808 , x , y, z - 1.5 , 0.0,0.0,0.0 );
    g_DrogenPflanzen[index][DP_iFireObject] = INVALID_OBJECT_ID;
    MoveDynamicObject( g_DrogenPflanzen[index][DP_iObject] , x,y,z , 0.1 );
	return 1;
}
stock GetFreeDrogenPflanzenSlot() {
	for(new i ; i < sizeof(g_DrogenPflanzen) ; i++) {
	    if( g_DrogenPflanzen[i][DP_bInUse] == false ) {
			return i;
	    }
	}
	return -1;
}

stock SetDrogenPflanzenOnFire(index) {
    g_DrogenPflanzen[index][DP_iFireObject] = CreateDynamicObject( 18688 , g_DrogenPflanzen[index][DP_fX] , g_DrogenPflanzen[index][DP_fY], g_DrogenPflanzen[index][DP_fZ] - 2.0, 0.0,0.0,0.0 );
    g_DrogenPflanzen[index][DP_bDestroyed] = true;
    SetTimerEx("DestroyDrogenPflanze",10*1000,false,"d",index);
    g_DrogenPflanzenCount--;
	return 1;
}

forward DestroyDrogenPflanze(index);
public DestroyDrogenPflanze(index) {
	DestroyDynamicObject(g_DrogenPflanzen[index][DP_iObject]);
	g_DrogenPflanzen[index][DP_iObject] = INVALID_OBJECT_ID;
	DestroyDynamicObject(g_DrogenPflanzen[index][DP_iFireObject]);
	g_DrogenPflanzen[index][DP_iFireObject] = INVALID_OBJECT_ID;
	g_DrogenPflanzen[index][DP_bInUse] = false;
	g_DrogenPflanzen[index][DP_bDestroyed] = false;
    return 1;
}
stock GetClosestDrogenPflanze(playerid,Float:radius = 8.0) {
	new
	    index = -1,
	    Float:distance,
	    Float:best_distance = 100.0,
	    Float:x,
	    Float:y,
	    Float:z;
	GetPlayerPos(playerid,x,y,z);
	for(new i ; i < sizeof(g_DrogenPflanzen) ; i++) {
	    if( g_DrogenPflanzen[i][DP_bInUse] == true && !g_DrogenPflanzen[i][DP_bDestroyed]) {
	        distance = GetDistance(x,y,z,g_DrogenPflanzen[i][DP_fX],g_DrogenPflanzen[i][DP_fY],g_DrogenPflanzen[i][DP_fZ]);
	        if( distance < best_distance && distance <= radius ) {
	            best_distance = distance;
	            index = i;
	        }
	    }
	}
	return index;
}

forward Pulse_DrogenPflanzen();
public Pulse_DrogenPflanzen() {
	for(new i ; i < sizeof(g_DrogenPflanzen) ; i++) {
	    if( g_DrogenPflanzen[i][DP_bInUse] == true  && !g_DrogenPflanzen[i][DP_bDestroyed]) {
            g_DrogenPflanzen[i][DP_iFortschritt]++;
            if( g_DrogenPflanzen[i][DP_iFortschritt] > DROGENPFLANZE_REIF ) {
                if( g_DrogenPflanzen[i][DP_iFortschritt] >= (DROGENPFLANZE_REIF + DROGENPFLANZE_UEBERREIF) ) {
     	           DestroyDrogenPflanze(i);
     	           g_DrogenPflanzenCount--;
                }
            }
            else if( g_DrogenPflanzen[i][DP_iFortschritt] == DROGENPFLANZE_REIF ) {

            }
            else {
	            g_DrogenPflanzen[i][DP_iWasser]--;
	            if( g_DrogenPflanzen[i][DP_iWasser] <= 0 ) {
	                DestroyDrogenPflanze(i);
	                g_DrogenPflanzenCount--;
	            }
            }
	    }
	}
	return 1;
}

new const PFLANZEN_HELP[][] = {
	"/Pflanzen help{FFFFFF}\t\tDiese Liste anzeigen",
	"/Pflanzen anzahl{FFFFFF}\t\tDie Anzahl der angebauten Pflanzen anzeigen",
	"/Pflanzen info{FFFFFF}\t\tInfo über nächstgelegene Pflanze (Reifezeit, Gießzeit)",
	"/Pflanzen anbauen{FFFFFF}\tEine Pflanze anbauen (maximal 200 Pflanzen gleichzeitig)",
	"/Pflanzen giessen{FFFFFF}\t\tNächstgelegene Pflanze giessen (Zeit zum Gießen: 600 Sekunden)",
	"/Pflanzen verbrennen{FFFFFF}\tNächstgelegene Pflanze wird verbrannt",
	"/Pflanzen abbauen{FFFFFF}\tNächstgelegene Pflanze wird geerntet",
	"/Nimmspice{FFFFFF}\t\tEin Gramm Spice einnehmen (10 Sekunden Cooldown)",
	"/Sellspice{FFFFFF}\t\tSpice verkaufen",
	//"{00FF33}/Geben [ID] Spice [Menge]\tEinem Spieler Spice geben",
	"/Samen{FFFFFF}\t\t\tSamenanzahl im Inventar anzeigen",
	"/Getsamen{FFFFFF}\t\tAn einem Samenpunkt Samen holen",
	"/Samenpunkte{FFFFFF}\t\tDie Samenpunkte auf der Karte anzeigen"
};

COMMAND:pflanzen(playerid,params[]) {
	if (!IsPlayerExecutive(playerid) && Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du hast mit Pflanzen nichts am Hut.");

	if (!strcmp(params, "verbrennen", true)) {
	    new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
		if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
		SendClientMessage(playerid, COLOR_YELLOW, "Die Spicepflanze wurde verbrannt.");

		new message[145];
		format(message, sizeof(message), "%s%s hat eine Spicepflanze verbrannt.", Spieler[playerid][pFraktion] != 15 ? "Ein Exekutivbeamter" : "Member ", Spieler[playerid][pFraktion] != 15 ? "" : GetName(playerid));
		SetDrogenPflanzenOnFire(pflanze);
        return SendFraktionMessage(15, Spieler[playerid][pFraktion] != 15 ? COLOR_RED : COLOR_YELLOW, message);
	}

	if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Nine Demons.");

	if (!strcmp(params, "help", true) || isnull(params)) {
		new dialogText[1024];
		for (new i = 0; i < sizeof(PFLANZEN_HELP); i++) format(dialogText, sizeof(dialogText), "%s{FFFF00}%s\n", dialogText, PFLANZEN_HELP[i]);
		return ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_LIST, "{b4c12e}Pflanzen Hilfe", dialogText, "Schließen", "");
	}

	if (!strcmp(params, "anzahl", true)) {
		if (g_DrogenPflanzenCount == 0) return SendClientMessage(playerid, COLOR_GREEN, "Es sind momentan {7FFFD4}keine {009D00}Spicepflanzen angebaut.");
		if (g_DrogenPflanzenCount == 1) return SendClientMessage(playerid, COLOR_GREEN, "Es ist momentan {7FFFD4}eine von 200 {009D00}Spicepflanzen angebaut.");

		new message[148];
		format(message, sizeof(message), "Es sind momentan {7FFFD4}%i von 200 {009D00}Spicepflanzen angebaut.", g_DrogenPflanzenCount);
		return SendClientMessage(playerid, COLOR_GREEN, message);
	}

	if (!strcmp(params, "anbauen", true)) {
		if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Fahrzeug keine Spicepflanzen anbauen.");
		if (g_DrogenPflanzenCount >= 200) return SendClientMessage(playerid, COLOR_RED, "Es sind bereits 200 Spicepflanzen angebaut.");
	    new pflanze = GetClosestDrogenPflanze(playerid); 
		if (pflanze != -1) return SendClientMessage(playerid, COLOR_RED, "Hier ist bereits eine Spicepflanze.");
		if (Spieler[playerid][pDrogenSamen] < 1) return SendClientMessage(playerid, COLOR_RED, "Du besitzt keine Samen, um eine Spicepflanze anzubauen.");

	    new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		if (!CreateDrogenPflanzen(x, y, z)) return SendClientMessage(playerid, COLOR_RED, "Du kannst gerade keine Pflanze anbauen.");
		Spieler[playerid][pDrogenSamen]--;
		new message[145];
		if (Spieler[playerid][pDrogenSamen] == 0) message = "Eine Spicepflanze wird gezogen. Du hast {FFFFFF}keine {FFFF00}Samen mehr übrig.";
		else if (Spieler[playerid][pDrogenSamen] == 1) message = "Eine Spicepflanze wird gezogen. Du hast noch {FFFFFF}einen {FFFF00}Samen übrig.";
		else format(message, sizeof(message), "Eine Spicepflanze wird gezogen. Du hast noch {FFFFFF}%d {FFFF00}Samen übrig.", Spieler[playerid][pDrogenSamen]);
		SendClientMessage(playerid, COLOR_YELLOW, message);
		SetTimerEx("TogglePlayerControllableEx", 1000, false, "dd", playerid, true);
		FreezePlayer(playerid);
		SetPlayerPos(playerid, x, y, z + 0.01);
		return 1;
	}
	
	if (!strcmp(params, "info", true)) {
	    new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
		if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
        if (g_DrogenPflanzen[pflanze][DP_iFortschritt] > DROGENPFLANZE_REIF) return SendClientMessage(playerid,COLOR_YELLOW,"Diese Spicepflanze ist reif.");

        new message[145];
		format(message, sizeof(message), "Die Spicepflanze ist reif in: %d Sekunden.", DROGENPFLANZE_REIF - g_DrogenPflanzen[pflanze][DP_iFortschritt]);
		SendClientMessage(playerid, COLOR_WHITE, message);
		format(message, sizeof(message), "Die Spicepflanze benötigt Wasser in: %d bis %d Sekunden.", g_DrogenPflanzen[pflanze][DP_iWasser] - DROGENPFLANZEN_WASSER_NOTICE, g_DrogenPflanzen[pflanze][DP_iWasser]);
		return SendClientMessage(playerid, COLOR_WHITE, message);
	}

	if (!strcmp(params,"giessen", true)) {
	    new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
		if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
		if (g_DrogenPflanzen[pflanze][DP_iWasser] > DROGENPFLANZEN_WASSER_NOTICE ) return SendClientMessage(playerid, COLOR_RED, "Diese Spicepflanze benötigt noch kein Wasser.");
		g_DrogenPflanzen[pflanze][DP_iWasser] = DROGENPFLANZEN_WASSER_COOLDOWN;
		return SendClientMessage(playerid, COLOR_YELLOW, "Du hast die Spicepflanze bewässert.");
	}

	if (!strcmp(params,"abbauen", true)) {
		if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "Du kannst in einem Fahrzeug keine Spicepflanzen abbauen.");
	    new pflanze = GetClosestDrogenPflanze(playerid, 3.0);
		if (pflanze == -1) return SendClientMessage(playerid, COLOR_RED, "Es ist keine Spicepflanze in deiner Nähe.");
        if (g_DrogenPflanzen[pflanze][DP_iFortschritt] < DROGENPFLANZE_REIF) return SendClientMessage(playerid, COLOR_RED, "Die Spicepflanze ist noch nicht reif.");
        new randomAmount = RandomEx(25, 30), message[145];
        g_DrogenPflanzen[pflanze][DP_bDestroyed] = true;
	    SetTimerEx("DestroyDrogenPflanze", 2 * 1000, false, "d", pflanze);
	    g_DrogenPflanzenCount--;
	    MoveDynamicObject(g_DrogenPflanzen[pflanze][DP_iObject], g_DrogenPflanzen[pflanze][DP_fX], g_DrogenPflanzen[pflanze][DP_fY], g_DrogenPflanzen[pflanze][DP_fZ] - 2.0, 0.05);
		FreezePlayer(playerid);
		SetTimerEx("TogglePlayerControllableEx", 2 * 1000, false, "dd", playerid, true);
	 	g_FraktionsSafeBox[15][FSB_iSpice] += randomAmount;
	 	format(message, sizeof(message), "%s hat %d Gramm Spice abgebaut. Es befinden sich nun %d Gramm Spice in der Fraktions-Safebox.", GetName(playerid), randomAmount, g_FraktionsSafeBox[15][FSB_iSpice]);
		SendClientMessage(playerid, COLOR_YELLOW, "Die Spicepflanze wird von dir geerntet.");
		return SendFraktionMessage(15, COLOR_RED, message);
	}

	return SendClientMessage(playerid, COLOR_BLUE, "* Benutze: {00CC00}/Pflanzen für eine Übersicht");
}

COMMAND:nimmspice(playerid,params[]) {
	if(Spieler[playerid][pSpice] < 1)return SendClientMessage(playerid, COLOR_GREY, "Du benötigst mindestens ein Gramm Spice.");
	if( gettime() < Spieler[playerid][unixSpiceCooldown] ) {
		SendClientMessage(playerid,COLOR_RED,"Du musst noch einen Moment warten, bis du wieder Spice nehmen kannst.");
	    return 1;
	}
	new
	    Float:armor;
	GetPlayerArmour(playerid,armor);
	if( armor >= 80.0 ) {
		SendClientMessage(playerid,COLOR_RED,"Du kannst kein Spice nehmen, da deine AP bereits zu hoch sind.");
	    return 1;
	}
	if(damagesperre[playerid]>0)
	{
	    SendClientMessage(playerid,COLOR_RED,"Du kannst noch kein Spice nehmen, da du gerade Schaden genommen hast.");
	    return 1;
	}
	armor += 30.0;
	if( armor > 100.0 ) armor = 100.0;
	SetPlayerArmour(playerid,armor);
    Spieler[playerid][unixSpiceCooldown] = gettime() + 10;

    pDrogenEinfluss[playerid] = 1;
	Spieler[playerid][pSpice] -= 1;
	KillTimer(DrogenTimer[playerid]);
 	SetPlayerDrunkLevel(playerid, 50000);
	DrogenTimer[playerid] = SetTimerEx("Drogen_Clear", 30000, 0, "i", playerid);

	new Float:x, Float:y, Float:z;
	new string[128];
	GetPlayerPos(playerid, x,y,z);
	format(string, sizeof(string), "* %s nimmt Spice zu sich.", GetName(playerid));
    SendRoundMessage(x,y,z, COLOR_PURPLE, string);

	return 1;
}

COMMAND:sellspice(playerid,params[]) {
	new pID, menge, preis, Float:x, Float:y, Float:z;
	if(sscanf(params, "uii", pID, menge, preis))return SendClientMessage(playerid, COLOR_BLUE, "* Benutze: {00CC00}/Sellspice [SpielerID/Name] [Menge] [Preis]");
	if(Spieler[playerid][pFraktion] != 15)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Member der Nine Demons.");
	GetPlayerPos(pID, x,y,z);
	if(playerid==pID)return SendClientMessage(playerid, COLOR_RED, "Du kannst Spice nicht an dich selbst verkaufen.");
	if(!IsPlayerConnected(pID))return SendClientMessage(playerid, COLOR_RED, "Der Spieler ist nicht online.");
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, x,y,z))return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Spielers.");
	if(menge > Spieler[playerid][pSpice]) return SendClientMessage(playerid, COLOR_RED, "Soviel Spice hast du nicht.");
	if(menge < 1 || menge > 10000)return SendClientMessage(playerid, COLOR_RED, "Der Wert sollte zwischen 1 und 10.000 liegen.");
	SetPVarString(playerid,"SellSpice",params);
	if(preis > 1 && preis < 1000000)
	{
		ShowPlayerDialog(playerid,DIALOG_SELLSPICE,DIALOG_STYLE_MSGBOX,"Spice Verkauf Information","\
		Der aktuelle Preis je Gramm Spice ist im Rahmen von 1.000$ bis 1.500$!\n\
		Höhere Beträge werden laut Server Regel §6 als Geldwäsche gewertet und Administrativ bestraft!\n\
		Die Strafe könnte sein: Perm-/Timeban, Admin-Verwarnung, Prison oder Drogen/Geld wird eingezogen!\n\
		Jeder Drogenhandel wird gespeichert!","Einverstanden","Ablehnen");
	}
	else
		SendClientMessage(playerid, COLOR_GREY, "Der Preis sollte zwischen $1 und $1.000.000 liegen.");
	
	return 1;
}

enum E_SEED_POINT {
	Float:SEED_POINT_fX,
	Float:SEED_POINT_fY,
	Float:SEED_POINT_fZ,
	SEED_POINT_LOCATION_NAME[32]
}

new const seedPoints[][E_SEED_POINT] = {
	{-85.5813, 2.2551, 3.1172, "Bauernhof in Blueberry Acres"},
	{760.485779, 378.900787, 23.168301, "Hütte in Red County"},
	{797.553528, -617.843811, 16.335899, "Garage in Dillimore"}
};

COMMAND:getsamen(playerid,params[]) {
	if( Spieler[playerid][pFraktion] != 15 ) {
		SendClientMessage(playerid,COLOR_RED,"Du kannst mit Samen nichts anfangen.");
	    return 1;
	}
	if( Spieler[playerid][pDrogenSamen] >= 3 ) {
		SendClientMessage(playerid,COLOR_RED,"Du besitzt bereits die maximale Anzahl an Samen.");
	    return 1;
	}

	new bool:bAtPoint = false;
	for (new i = 0; i < sizeof(seedPoints); i++) {
		if (IsPlayerInRangeOfPoint(playerid, 3.0, seedPoints[i][SEED_POINT_fX], seedPoints[i][SEED_POINT_fY], seedPoints[i][SEED_POINT_fZ])) {
			bAtPoint = true;
			break;
		}
	}

	if (!bAtPoint) return SendClientMessage(playerid, COLOR_RED, "Du bist an keinem Samenpunkt (/samenpunkte).");

	new
	    total,
	    String[128],
		drogensamen;
	drogensamen = RandomEx(8,10);
    total = Spieler[playerid][pDrogenSamen] + drogensamen;
    if( total > 15 ) total = 15;
    format(String,sizeof(String),"Du hast nun insgesamt %d Samen (+ %d Stk)", total , total - Spieler[playerid][pDrogenSamen]);
    SendClientMessage(playerid,COLOR_YELLOW,String);
    Spieler[playerid][pDrogenSamen] = total;
    Spieler[playerid][unixGetSamenCooldown] = gettime() + 60*60;
	return 1;
}

CMD:samenpunkte(playerid, params[]) {
	if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du brauchst nicht zu wissen, wo sich die Samenpunkte befinden.");
	new dialogText[512];
	for (new i = 0; i < sizeof(seedPoints); i++) format(dialogText, sizeof(dialogText), "%s%s\n", dialogText, seedPoints[i][SEED_POINT_LOCATION_NAME]);
	return ShowPlayerDialog(playerid, DIALOG_SEEDPOINTS, DIALOG_STYLE_LIST, "{c3d038}Samenpunkte", dialogText, "Markieren", "Abbrechen");
}

CMD:samen(playerid, params[]) {
	if (Spieler[playerid][pFraktion] != 15) return SendClientMessage(playerid, COLOR_RED, "Du hast keine Samen.");
	new message[145];
	if (Spieler[playerid][pDrogenSamen] == 0) message = "[Info] {FFFFFF}Du hast {FFFF00}keine {FFFFFF}Samen bei dir.";
	else if (Spieler[playerid][pDrogenSamen] == 1) message = "[Info] {FFFFFF}Du hast {FFFF00}einen {FFFFFF}Samen bei dir.";
	else format(message, sizeof(message), "[Info] {FFFFFF}Du hast {FFFF00}%d {FFFFFF}Samen bei dir.", Spieler[playerid][pDrogenSamen]);
    return SendClientMessage(playerid, COLOR_YELLOW, message);
}