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
	bool:DP_bInUse
}

new
	g_DrogenPflanzen[MAX_DROGEN_PFLANZEN][e_DrogenPflanzen];

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
    g_DrogenPflanzen[index][DP_iFireObject]  = CreateDynamicObject( 18688 , g_DrogenPflanzen[index][DP_fX] , g_DrogenPflanzen[index][DP_fY], g_DrogenPflanzen[index][DP_fZ] - 2.0, 0.0,0.0,0.0 );
    g_DrogenPflanzen[index][DP_bInUse] = false;
    SetTimerEx("DestroyDrogenPflanze",10*1000,false,"d",index);
	return 1;
}

forward DestroyDrogenPflanze(index);
public DestroyDrogenPflanze(index) {
	DestroyDynamicObject(g_DrogenPflanzen[index][DP_iObject]);
	g_DrogenPflanzen[index][DP_iObject] = INVALID_OBJECT_ID;
	DestroyDynamicObject(g_DrogenPflanzen[index][DP_iFireObject]);
	g_DrogenPflanzen[index][DP_iFireObject] = INVALID_OBJECT_ID;
    g_DrogenPflanzen[index][DP_bInUse] = false;
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
	    if( g_DrogenPflanzen[i][DP_bInUse] == true ) {
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
	    if( g_DrogenPflanzen[i][DP_bInUse] == true ) {
            g_DrogenPflanzen[i][DP_iFortschritt]++;
            if( g_DrogenPflanzen[i][DP_iFortschritt] > DROGENPFLANZE_REIF ) {
                if( g_DrogenPflanzen[i][DP_iFortschritt] >= (DROGENPFLANZE_REIF + DROGENPFLANZE_UEBERREIF) ) {
     	           DestroyDrogenPflanze(i);
                }
            }
            else if( g_DrogenPflanzen[i][DP_iFortschritt] == DROGENPFLANZE_REIF ) {

            }
            else {
	            g_DrogenPflanzen[i][DP_iWasser]--;
	            if( g_DrogenPflanzen[i][DP_iWasser] <= 0 ) {
	                DestroyDrogenPflanze(i);
	            }
            }
	    }
	}
	return 1;
}

new const PFLANZEN_HELP[][] = {
	"/Pflanzen help\t\tDiese Liste anzeigen",
	"/Pflanzen anbauen\tEine Pflanze anbauen",
	"/Pflanzen info\t\tInfo über nächstgelegene Pflanze (Reifezeit, Gießzeit)",
	"/Pflanzen giessen\t\tNächstgelegene Pflanze giessen (Zeit zum Gießen: 600 Sekunden)",
	"/Pflanzen verbrennen\tNächstgelegene Pflanze wird verbrannt",
	"/Pflanzen abbauen\tNächstgelegene Pflanze wird geerntet",
	"/Nimmspice\t\tEin Gramm Spice einnehmen (10 Sekunden Cooldown)",
	"/Sellspice\t\tSpice verkaufen",
	"/Geben [ID] Spice [Menge]\tEinem Spieler Spice geben",
	"/Getsamen\t\tAn einem Samenpunkt Samen holen"
};

COMMAND:pflanzen(playerid,params[]) {
	if (!strcmp(params,"help") || isnull(params)) {
		if (Spieler[playerid][pFraktion] != 15)	return SendClientMessage(playerid, COLOR_RED, "Du hast mit Pflanzen nichts am Hut.");
		new dialogText[800];
		for (new i = 0; i < sizeof(PFLANZEN_HELP); i++) format(dialogText, sizeof(dialogText), "%s%s\n", dialogText, PFLANZEN_HELP[i]);
		return ShowPlayerDialog(playerid, DIALOG_NO_RESPONSE, DIALOG_STYLE_LIST, "Pflanzen Hilfe", dialogText, "Schließen", "");
	}
	else if(!strcmp(params,"anbauen")) {
	    new
	        pflanze;
		pflanze = GetClosestDrogenPflanze(playerid);
		if( Spieler[playerid][pFraktion] != 15 ) {
			SendClientMessage(playerid,COLOR_RED,"Du kannst keine Spicepflanzen anbauen.");
		    return 1;
		}
		if(pflanze != -1 ) {
			SendClientMessage(playerid,COLOR_RED,"Hier ist bereits eine Spicepflanze.");
		    return 1;
		}
		if( Spieler[playerid][pDrogenSamen] < 1 ) {
			SendClientMessage(playerid,COLOR_RED,"Du besitzt keine Samen, um eine Spicepflanze anzubauen.");
		    return 1;
		}
	    new
	        Float:face,
	        Float:x,
	        Float:y,
	        Float:z;
		GetPlayerPos(playerid,x,y,z);
		GetPlayerFacingAngle(playerid,face);
		GetXYInFrontOfPosition(x, y, face, 1.0 );
		CreateDrogenPflanzen(x,y,z);
		Spieler[playerid][pDrogenSamen]--;
		new message[128];
		format(message, sizeof(message), "Spicepflanze wird gezogen. Du hast noch {FFFFFF}%d {FFFF00}Samen übrig.", Spieler[playerid][pDrogenSamen]);
		SendClientMessage(playerid, COLOR_YELLOW, message);
		SetTimerEx("TogglePlayerControllableEx",1*1000,false,"dd",playerid,true);
		FreezePlayer(playerid);
		SetPlayerPos(playerid,x,y,z + 0.01);
	}
	else if(!strcmp(params,"info")) {
		if( Spieler[playerid][pFraktion] != 15 ) {
			SendClientMessage(playerid,COLOR_RED,"Du kannst keine Spicepflanzen einsehen.");
		    return 1;
		}
	    new
	        pflanze;
		pflanze = GetClosestDrogenPflanze(playerid,3.0);

		if(pflanze == -1 ) {
			SendClientMessage(playerid,COLOR_RED,"Keine Spicepflanze in deiner Nähe.");
		    return 1;
		}
        if( g_DrogenPflanzen[pflanze][DP_iFortschritt] > DROGENPFLANZE_REIF ) {
			SendClientMessage(playerid,COLOR_YELLOW,"Diese Spicepflanze ist reif.");
        }
        else {
            new
                reif,
                wasser,
                String[128];
			reif = DROGENPFLANZE_REIF - g_DrogenPflanzen[pflanze][DP_iFortschritt];
			format(String,sizeof(String),"Spicepflanze reif in: %d Sekunden",reif);
			SendClientMessage(playerid,COLOR_WHITE,String);
			wasser = g_DrogenPflanzen[pflanze][DP_iWasser] - DROGENPFLANZEN_WASSER_NOTICE;
			format(String,sizeof(String),"Spicepflanze benötigt Wasser in: %d bis %d Sekunden",wasser,g_DrogenPflanzen[pflanze][DP_iWasser]);
			SendClientMessage(playerid,COLOR_WHITE,String);
        }
		return 1;
	}
	else if(!strcmp(params,"giessen")) {
		if( Spieler[playerid][pFraktion] != 15 ) {
			SendClientMessage(playerid,COLOR_RED,"Du kannst keine Spicepflanzen gießen.");
		    return 1;
		}
	    new
	        pflanze;
		pflanze = GetClosestDrogenPflanze(playerid,3.0);
		if(pflanze == -1 ) {
			SendClientMessage(playerid,COLOR_RED,"Keine Spicepflanze in deiner Nähe.");
		    return 1;
		}
		if( g_DrogenPflanzen[pflanze][DP_iWasser] > DROGENPFLANZEN_WASSER_NOTICE ) {
			SendClientMessage(playerid,COLOR_RED,"Diese Pflanze benötigt noch kein Wasser.");
		    return 1;
		}
		g_DrogenPflanzen[pflanze][DP_iWasser] = DROGENPFLANZEN_WASSER_COOLDOWN;
		SendClientMessage(playerid,COLOR_YELLOW,"Du hast die Spicepflanze bewässert.");
	}
	else if(!strcmp(params,"verbrennen")) {
	    if(!IsPlayerExecutive(playerid) && Spieler[playerid][pFraktion] != 15) {
			SendClientMessage(playerid,COLOR_RED,"Diese Funktion können nur FBI Agenten und Polizisten nutzen.");
		    return 1;
	    }
	    new
	        pflanze;
		pflanze = GetClosestDrogenPflanze(playerid,3.0);
		if(pflanze == -1 ) {
			SendClientMessage(playerid,COLOR_RED,"Keine Spicepflanze in deiner Nähe.");
		    return 1;
		}
		SendClientMessage(playerid,COLOR_YELLOW,"Die Spicepflanze wurde verbrannt");
		if (Spieler[playerid][pFraktion] != 15) SendFraktionMessage(15, COLOR_RED, "Eine eurer Spicepflanzen wurde von einem Exekutivbeamten zerstört.");
        SetDrogenPflanzenOnFire(pflanze);
	}
	else if(!strcmp(params,"abbauen")) {
		if( Spieler[playerid][pFraktion] != 15 ) {
			SendClientMessage(playerid,COLOR_RED,"Du kannst keine Spicepflanzen abbauen.");
		    return 1;
		}
	    new
	        pflanze;
		pflanze = GetClosestDrogenPflanze(playerid,3.0);
		if(pflanze == -1 ) {
			SendClientMessage(playerid,COLOR_RED,"Keine Spicepflanze in deiner Nähe.");
		    return 1;
		}
        if( g_DrogenPflanzen[pflanze][DP_iFortschritt] < DROGENPFLANZE_REIF ) {
			SendClientMessage(playerid,COLOR_RED,"Die Pflanze ist noch nicht reif.");
		    return 1;
        }
        new
            r = RandomEx(25,30),
            String[128];
		format(String,sizeof(String),"%s hat %d Gramm Spice abgebaut. Es befinden sich nun %d Gramm Spice in der Fraktions-Safebox.",GetName(playerid),r,g_FraktionsSafeBox[15][FSB_iSpice] + r );
		SendFraktionMessage(15, COLOR_RED, String);
		SendClientMessage(playerid,COLOR_YELLOW,"Die Spicepflanze wird von dir geerntet.");
	    SetTimerEx("DestroyDrogenPflanze",2*1000,false,"d",pflanze);
	    MoveDynamicObject(g_DrogenPflanzen[pflanze][DP_iObject] ,g_DrogenPflanzen[pflanze][DP_fX] , g_DrogenPflanzen[pflanze][DP_fY], g_DrogenPflanzen[pflanze][DP_fZ] - 2.0 , 0.05 );
	    g_DrogenPflanzen[pflanze][DP_bInUse] = false;
		FreezePlayer(playerid);
		SetTimerEx("TogglePlayerControllableEx",2*1000,false,"dd",playerid,true);
	 	g_FraktionsSafeBox[15][FSB_iSpice] += r;
	}
	return 1;
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
 	SetPlayerDrunkLevel(playerid,50000);
	DrogenTimer[playerid] = SetTimerEx("Drogen_Clear", 60000, 0, "i", playerid);

	new Float:x, Float:y, Float:z;
	new string[128];
	GetPlayerPos(playerid, x,y,z);
	format(string, sizeof(string), "* %s nimmt Spice zu sich.", GetName(playerid));
    SendRoundMessage(x,y,z, COLOR_PURPLE, string);

	return 1;
}

COMMAND:sellspice(playerid,params[]) {
	new pID, menge, preis, Float:x, Float:y, Float:z;
	if(sscanf(params, "uii", pID, menge, preis))return SendClientMessage(playerid, COLOR_GREY, "* Benutze: /Sellspice [SpielerID/Name] [Menge] [Preis]");
	if(Spieler[playerid][pFraktion] != 15)return SendClientMessage(playerid, COLOR_RED, "Du bist kein Spicedealer.");
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
		Der aktuelle Preis je Gramm Spice ist im Rahmen von 2.000$ bis 2.500$!\n\
		Höhere Beträge werden laut Server Regel §6 als Geldwäsche gewertet und Administrativ bestraft!\n\
		Die Strafe könnte sein: Perm-/Timeban, Admin-Verwarnung, Prison oder Drogen/Geld wird eingezogen!\n\
		Jeder Drogenhandel wird gespeichert!!!","Einverstanden","Ablehnen");
	}
	else
		SendClientMessage(playerid, COLOR_GREY, "Der Preis sollte zwischen $1 und $1.000.000 liegen.");
	
	return 1;
}

COMMAND:getsamen(playerid,params[]) {
	if( Spieler[playerid][pFraktion] != 15 ) {
		SendClientMessage(playerid,COLOR_RED,"Du kannst mit Samen nichts anfangen.");
	    return 1;
	}
	if( Spieler[playerid][pDrogenSamen] >= 3 ) {
		SendClientMessage(playerid,COLOR_RED,"Du besitzt bereits die maximale Anzahl an Samen.");
	    return 1;
	}
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, -85.5813, 2.2551, 3.1172) && !IsPlayerInRangeOfPoint(playerid, 3.0, 760.485779, 378.900787, 23.168301) && !IsPlayerInRangeOfPoint(playerid, 3.0, 797.553528, -617.843811, 16.335899)) {
		SendClientMessage(playerid,COLOR_RED,"Hier kannst du dir keine Samen besorgen.");
	    return 1;
	}
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



