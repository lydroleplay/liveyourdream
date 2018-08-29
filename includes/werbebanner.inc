#define MAX_WERBEBANNER 50

// 4729
enum e_Werbebanner {
	W_iID,
	Float:W_fX,
	Float:W_fY,
	Float:W_fZ,
	Text3D:W_t3dLabel,
	W_iPickup,
	
	W_iObjectID,
	W_iModelID,
	Float:W_fObjX,
	Float:W_fObjY,
	Float:W_fObjZ,
	Float:W_fObjRotX,
	Float:W_fObjRotY,
	Float:W_fObjRotZ,

	W_sText[256],
	W_iMaterialIndex,
	W_iMaterialSize,
	W_iFontFace[32],
	W_iFontSize,
	W_iBold,
	W_iFontColor,
	W_iBackColor,
	W_iTextAlignment,
	
	W_unixBought,
	W_sOwner[MAX_PLAYER_NAME]
};

/*
new g_Werbebanner[1][e_Werbebanner] = {
	{1560.9818,-1723.1691,13.5469,Text3D:0,0,INVALID_OBJECT_ID,4729,1565.2359, -1722.4185, 31.1512, 0.0000, 0.0000, -65.3964,
		"{FFFFFF}Das ist ein {FF0000}Test", 0, 90, "Arial", 24, 0, -32256, -16777216, 0,
		0,"Niemand"}
};
*/
new
	g_iWerbebanner,
	g_Werbebanner[MAX_WERBEBANNER][e_Werbebanner];


stock InitWerbebanner() {
	mysql_oquery("SELECT * FROM `werbetafel`",THREAD_WERBEBANNER,INVALID_OBJECT_ID,gSQL);
	SetTimer("SaveWerbebanner",99989 * 5 , true );
	SetTimer("CheckWerbebanner",30103,true);
	return 1;
}
forward CheckWerbebanner();
public CheckWerbebanner() {
	new
	    now;
	now = gettime();
	//print("CheckWerbebanner");
	for(new i ; i < g_iWerbebanner ; i++) {
	    if( g_Werbebanner[i][W_unixBought] > 0 ) {
	        if( now >= g_Werbebanner[i][W_unixBought] ) {
	            // printf("Werbetafel %d muss verkauft werden",i);
	            if( strcmp("Niemand",g_Werbebanner[i][W_sOwner],true) != 0 ) {
	                new
	                    playerid;
					sscanf(g_Werbebanner[i][W_sOwner],"u",playerid);
					if(IsPlayerConnected(playerid)) {
					    SendClientMessage(playerid,COLOR_YELLOW,"Deine Werbetafelmiete ist abgelaufen!");
					}
					WerbetafelZuVermieten(i);
					UpdateObject(i);
	            }
	        }
	    }
	}
	return 1;
}

forward SaveWerbebannerEx(index);
public SaveWerbebannerEx(index) {
	new
	    query[800];
    format(query,sizeof(query),"UPDATE `werbetafel` SET \
        `IconX` = '%.2f',\
        `IconY` = '%.2f',\
        `IconZ` = '%.2f',\
        `ModelID` = '%d',\
        `ObjectX` = '%.2f',\
        `ObjectY` = '%.2f',\
        `ObjectZ` = '%.2f',\
        `RotX` = '%.2f',\
        `RotY` = '%.2f',\
        `RotZ` = '%.2f',\
        `Text` = '%s',\
        `MaterialIndex` = '%d',\
        `MaterialSize` = '%d',\
        `FontFace` = '%s',\
        `FontSize` = '%d',\
        `Bold` = '%d',\
        `FontColor` = '%d',\
        `BackColor` = '%d',\
        `TextAlignment` = '%d',\
        `UnixTimestamp` = '%d',\
        `Besitzer` = '%s' \
        WHERE `ID` = '%d'",
			g_Werbebanner[index][W_fX],
			g_Werbebanner[index][W_fY],
			g_Werbebanner[index][W_fZ],
			g_Werbebanner[index][W_iModelID],
			g_Werbebanner[index][W_fObjX],
			g_Werbebanner[index][W_fObjY],
			g_Werbebanner[index][W_fObjZ],
			g_Werbebanner[index][W_fObjRotX],
			g_Werbebanner[index][W_fObjRotY],
			g_Werbebanner[index][W_fObjRotZ],
			g_Werbebanner[index][W_sText],
			g_Werbebanner[index][W_iMaterialIndex],
			g_Werbebanner[index][W_iMaterialSize],
			g_Werbebanner[index][W_iFontFace],
			g_Werbebanner[index][W_iFontSize],
			g_Werbebanner[index][W_iBold],
			g_Werbebanner[index][W_iFontColor],
			g_Werbebanner[index][W_iBackColor],
			g_Werbebanner[index][W_iTextAlignment],
			g_Werbebanner[index][W_unixBought],
			g_Werbebanner[index][W_sOwner],
			g_Werbebanner[index][W_iID]
	);
	mysql_oquery(query,THREAD_SAVEWERBEBANNER,INVALID_PLAYER_ID,gSQL);
	return 1;
}
forward SaveWerbebanner();
public SaveWerbebanner() {
	new
	    query[800];
	for(new i ; i < g_iWerbebanner ; i++) {
	    format(query,sizeof(query),"UPDATE `werbetafel` SET \
	        `IconX` = '%.2f',\
	        `IconY` = '%.2f',\
	        `IconZ` = '%.2f',\
	        `ModelID` = '%d',\
	        `ObjectX` = '%.2f',\
	        `ObjectY` = '%.2f',\
	        `ObjectZ` = '%.2f',\
	        `RotX` = '%.2f',\
	        `RotY` = '%.2f',\
	        `RotZ` = '%.2f',\
	        `Text` = '%s',\
	        `MaterialIndex` = '%d',\
	        `MaterialSize` = '%d',\
	        `FontFace` = '%s',\
	        `FontSize` = '%d',\
	        `Bold` = '%d',\
	        `FontColor` = '%d',\
	        `BackColor` = '%d',\
	        `TextAlignment` = '%d',\
	        `UnixTimestamp` = '%d',\
	        `Besitzer` = '%s' \
	        WHERE `ID` = '%d'",
				g_Werbebanner[i][W_fX],
				g_Werbebanner[i][W_fY],
				g_Werbebanner[i][W_fZ],
				g_Werbebanner[i][W_iModelID],
				g_Werbebanner[i][W_fObjX],
				g_Werbebanner[i][W_fObjY],
				g_Werbebanner[i][W_fObjZ],
				g_Werbebanner[i][W_fObjRotX],
				g_Werbebanner[i][W_fObjRotY],
				g_Werbebanner[i][W_fObjRotZ],
				g_Werbebanner[i][W_sText],
				g_Werbebanner[i][W_iMaterialIndex],
				g_Werbebanner[i][W_iMaterialSize],
				g_Werbebanner[i][W_iFontFace],
				g_Werbebanner[i][W_iFontSize],
				g_Werbebanner[i][W_iBold],
				g_Werbebanner[i][W_iFontColor],
				g_Werbebanner[i][W_iBackColor],
				g_Werbebanner[i][W_iTextAlignment],
				g_Werbebanner[i][W_unixBought],
				g_Werbebanner[i][W_sOwner],
				g_Werbebanner[i][W_iID]
		);
		mysql_oquery(query,THREAD_SAVEWERBEBANNER,INVALID_PLAYER_ID,gSQL);
	}
	return 1;
}
stock AddWerbebanner( index ) {
	//printf("AddWerbebanner(%d)",index);
	new
	    String[64];
	g_Werbebanner[index][W_iPickup] = CreateDynamicPickup(1239,1,g_Werbebanner[index][W_fX],g_Werbebanner[index][W_fY],g_Werbebanner[index][W_fZ]);
	if(!strcmp(g_Werbebanner[index][W_sOwner],"Niemand")) {
		format(String,sizeof(String),"Diese Werbetafel steht zum Verkauf!");
	}
	else {
		format(String,sizeof(String),"Werbetafel gehört: %s",g_Werbebanner[index][W_sOwner]);
	}
	g_Werbebanner[index][W_t3dLabel] = CreateDynamic3DTextLabel(String,0xFFFFFFFF,g_Werbebanner[index][W_fX],g_Werbebanner[index][W_fY],g_Werbebanner[index][W_fZ],30.0);

	g_Werbebanner[index][W_iObjectID] = CreateDynamicObject( g_Werbebanner[index][W_iModelID],g_Werbebanner[index][W_fObjX],g_Werbebanner[index][W_fObjY],g_Werbebanner[index][W_fObjZ],g_Werbebanner[index][W_fObjRotX],g_Werbebanner[index][W_fObjRotY],g_Werbebanner[index][W_fObjRotZ]);
	UpdateObject(index);
	Streamer_SetFloatData(STREAMER_TYPE_OBJECT,g_Werbebanner[index][W_iObjectID], E_STREAMER_DRAW_DISTANCE , 300.0 );
	return 1;
}
stock IsPlayerAtWerbetafel(playerid,Float:distance = 3.0) {
	for(new x = 0; x < g_iWerbebanner ; x++) {
		if(IsPlayerInRangeOfPoint(playerid, distance, g_Werbebanner[x][W_fX], g_Werbebanner[x][W_fY], g_Werbebanner[x][W_fZ])) {
			return x;
		}
	}
	return 999;
}
COMMAND:atafelentmieten(playerid,params[]) {
	new
	    werbetafel;
	if( !gPlayerLogged[playerid] ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt");
	    return 1;
	}
	if(Spieler[playerid][pAdmin] < 3) return SendClientMessage(playerid, COLOR_RED, "Du besitzt nicht die benötigten Rechte.");
	werbetafel = IsPlayerAtWerbetafel(playerid);
	//printf("werbetafel %d",werbetafel);
	if(werbetafel == 999 ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe einer Werbetafel.");
	    return 1;
	}
	new
	    String[128];
	format(String,sizeof(String),"Admin %s hat Werbetafel Nr. %d freigestellt.",GetName(playerid),werbetafel);
	SendAdminMessage(COLOR_YELLOW, String);

	WerbetafelZuVermieten(werbetafel);
	return 1;
}
COMMAND:werbetafel(playerid,params[]) {
	new
	    werbetafel;
	if( !gPlayerLogged[playerid] ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt");
	    return 1;
	}
	werbetafel = IsPlayerAtWerbetafel(playerid);
	//printf("werbetafel %d",werbetafel);
	if(werbetafel == 999 ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe einer Werbetafel.");
	    return 1;
	}
	if(!strcmp(g_Werbebanner[werbetafel][W_sOwner],GetName(playerid))) {
	    ShowMainMenu(playerid);
	}
	else {
        SendClientMessage(playerid, COLOR_RED, "Diese Werbetafel gehört nicht dir.");
	    return 1;
	}
	return 1;
}
COMMAND:werbetafelkaufen(playerid,params[]) {
	#pragma unused params
	new
	    werbetafel;
	if( !gPlayerLogged[playerid] ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht eingeloggt");
	    return 1;
	}
	werbetafel = IsPlayerAtWerbetafel(playerid);
	if(werbetafel == 999 ) {
        SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe einer Werbetafel.");
	    return 1;
	}
	if(strcmp(g_Werbebanner[werbetafel][W_sOwner],"Niemand") != 0 ) {
		if(!strcmp(g_Werbebanner[werbetafel][W_sOwner],GetName(playerid) )) {
		    // Owner
		    return cmd_werbetafel(playerid,"");
		}
		else {
	        SendClientMessage(playerid, COLOR_RED, "Diese Werbetafel steht nicht zum Verkauf.");
		    return 1;
		}
	}
	else {
	    // Hat vllt schon Werbetafel gemietet
	    if(GetPlayerWerbetafel(playerid) != 999 ) {
	        SendClientMessage(playerid, COLOR_RED, "Du besitzt bereits eine Werbetafel");
		    return 1;
	    }
	    ShowPlayerDialog(playerid,DIALOG_WERBETAFEL_KAUFEN,DIALOG_STYLE_MSGBOX,"Werbetafel Kaufen","Das Kaufen dieser Werbetafel kostet 40.000$.\nDauer: 4 Tage","Kaufen","Abbruch");
	}
	return 1;
}

stock GetPlayerWerbetafel(playerid) {
	new
	    name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,sizeof(name));
	for(new x = 0; x < g_iWerbebanner ; x++) {
		if(!strcmp(g_Werbebanner[x][W_sOwner],name)) {
		    return x;
		}
	}
	return 999;
}


ShowMainMenu(playerid)
{
    new string[600];
    strcat(string,""COLOR_Y"1. "COLOR_B"Hilfe\n"COLOR_Y"2. "COLOR_B"---\n"COLOR_Y"3. "COLOR_B"Set Object Text\
	\n"COLOR_Y"4. "COLOR_B"---\n"COLOR_Y"5. "COLOR_B"Set Material Size\n");
	strcat(string, ""COLOR_Y"6. "COLOR_B"Set Text Font\n"COLOR_Y"7. "COLOR_B"Set Text Size\n"COLOR_Y"8. "COLOR_B"Set Bold Text\
	\n"COLOR_Y"9. "COLOR_B"Set Text Color\n"COLOR_Y"10. "COLOR_B"Set Background Color\n"COLOR_Y"11. "COLOR_B"Set Text Alignment\n"COLOR_Y"12. "COLOR_G"---\
	\n"COLOR_Y"13. "COLOR_G"---\n"COLOR_Y"14. "COLOR_G"Reset Object");
	ShowPlayerDialog(playerid,MainDialog,DIALOG_STYLE_LIST,""COLOR_R"Text Object | Main Menu",string,"Continue","Exit");
	return 1;
}

stock Werbebanner_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new
	    werbetafel;
	werbetafel = IsPlayerAtWerbetafel(playerid);
	if(werbetafel == 999 ) {
	    return 0;
	}
	if(dialogid == MainDialog){
	    if(response){
	        switch(listitem) {
	            case 1,3,11,12: {
	                ShowMainMenu(playerid);
				}
	            case 0:{
					ShowPlayerDialog(playerid,DIALOG_WERBEANLEITUNG,DIALOG_STYLE_MSGBOX,"    "COLOR_R"Anleitung","{FFFFFF}Wichtig Information:\n\nZeilenumbruch im Text wird wie folgt eingefügt:\n<br>\n\nBeispiel:\n1. Eins<br>2. Zwei\n\nErgebnis:\n1. Eins\n2. Zwei","Zurück","");
	            }
	            /*
	            case 1:{
	                new string[128];
	                format(string, sizeof(string), ""COLOR_B"Current Object Model ID: "COLOR_Y"%d\
					\n"COLOR_G"Please, type below a Model ID for the object (example = 19353):",ObjectID[playerid]);
					ShowPlayerDialog(playerid,OModelDialog,DIALOG_STYLE_INPUT,"    "COLOR_R"Object Model ID",string,"Change","Back");
	            }
	            */
	        	case 2:{
	        	    new string[400];
	        	    format(string, sizeof(string),""COLOR_B"Current Object Text: "COLOR_Y"%s\
					\n"COLOR_G"Please, type below your text for the object:",g_Werbebanner[werbetafel][W_sText]);
	        	    ShowPlayerDialog(playerid,TextDialog,DIALOG_STYLE_INPUT,"    "COLOR_R"Object Text",string,"Change","Back");
	        	}
	        	/*
	        	case 3: {
					new string[128];
					format(string, sizeof(string),""COLOR_B"Current Material Index: "COLOR_Y"%d\
					\n"COLOR_G"Please, type below the Material Index which you want use (default = 0):",Index[playerid]);
					ShowPlayerDialog(playerid,IndexDialog,DIALOG_STYLE_INPUT,"    "COLOR_R"Material Index",string,"Change","Back");
				}
				*/
				case 4: {
				    new sizes[600];
					strcat(sizes,""COLOR_Y"1. "COLOR_B"32x32 "COLOR_G"(10)\
								\n"COLOR_Y"2. "COLOR_B"64x32 "COLOR_G"(20)\
								\n"COLOR_Y"3. "COLOR_B"64x64 "COLOR_G"(30)\
								\n"COLOR_Y"4. "COLOR_B"128x32 "COLOR_G"(40)\
								\n"COLOR_Y"5. "COLOR_B"128x64 "COLOR_G"(50)\
								\n"COLOR_Y"6. "COLOR_B"128x128 "COLOR_G"(60)\
								\n"COLOR_Y"7. "COLOR_B"256x32 "COLOR_G"(70)");
					strcat(sizes,"\n"COLOR_Y"8. "COLOR_B"256x64 "COLOR_G"(80)\
								\n"COLOR_Y"9. "COLOR_B"256x128 "COLOR_G"(90)\
								\n"COLOR_Y"10. "COLOR_B"256x256 "COLOR_G"(100)\
								\n"COLOR_Y"11. "COLOR_B"512x64 "COLOR_G"(110)\
								\n"COLOR_Y"12. "COLOR_B"512x128 "COLOR_G"(120)\
								\n"COLOR_Y"13. "COLOR_B"512x256 "COLOR_G"(130)\
								\n"COLOR_Y"14. "COLOR_B"512x512 "COLOR_G"(140)");
					new current[128];
					format(current, sizeof(current),""COLOR_R"Material Size "COLOR_G"| "COLOR_B"Current size: "COLOR_Y"%d",g_Werbebanner[werbetafel][W_iMaterialSize]);
					ShowPlayerDialog(playerid,SizesDialog,DIALOG_STYLE_LIST,current,sizes,"Change","Back");
				}
				case 5: {
				    new string[128];
				    format(string, sizeof(string), ""COLOR_B"Current Text Font: "COLOR_Y"%s\
					\n"COLOR_G"Please, type below the Text Font name which you want use:",g_Werbebanner[werbetafel][W_iFontFace]);
                    ShowPlayerDialog(playerid,FontNDialog,DIALOG_STYLE_INPUT,"    "COLOR_R"Text Font",string,"Change","Back");
				}
				case 6: {
				    new string[128];
				    format(string, sizeof(string), ""COLOR_B"Current Text Size: "COLOR_Y"%d\
					\n"COLOR_G"Please, type below the Text Size which you want use:",g_Werbebanner[werbetafel][W_iFontSize]);
                    ShowPlayerDialog(playerid,FontSDialog,DIALOG_STYLE_INPUT,"    "COLOR_R"Text Size",string,"Change","Back");
				}
				case 7: {
				    new title[100]; new yesorno[10];
				    if(g_Werbebanner[werbetafel][W_iBold] == 0) yesorno = "No";
				    else if(g_Werbebanner[werbetafel][W_iBold] == 1) yesorno = "Yes";
				    format(title, sizeof(title), ""COLOR_R"Bold Text "COLOR_G"| "COLOR_B"Using Bold Text: "COLOR_Y"%s",yesorno);
                    ShowPlayerDialog(playerid,BoldDialog,DIALOG_STYLE_LIST,title,""COLOR_Y"1. "COLOR_B"No\n"COLOR_Y"2. "COLOR_B"Yes","Change","Back");
				}
				case 8: {
				    new titulo[100];
				    format(titulo, sizeof(titulo),""COLOR_R"Text Color "COLOR_G"| "COLOR_B"Current Text Color: "COLOR_Y"%i",g_Werbebanner[werbetafel][W_iFontColor]);
                    ShowPlayerDialog(playerid,ColorDialog,DIALOG_STYLE_LIST,titulo,""COLOR_Y"1. "COLOR_B"Type a ARGB color code\
					\n"COLOR_Y"2. "COLOR_B"Select a predefinded color","Next","Back");
				}
				case 9: {
				    new titulo[100];
				    format(titulo, sizeof(titulo),""COLOR_R"Object Background "COLOR_G"| "COLOR_B"Current Text Color: "COLOR_Y"%i",g_Werbebanner[werbetafel][W_iBackColor]);
                    ShowPlayerDialog(playerid,BackgColorD,DIALOG_STYLE_LIST,titulo,""COLOR_Y"1. "COLOR_B"Disable Background\n"COLOR_Y"2. "COLOR_B"Type a ARGB color code\
					\n"COLOR_Y"3. "COLOR_B"Select a predefinded color","Next","Back");
				}
				case 10: {
                    new title[100]; new position[30];
				    if(g_Werbebanner[werbetafel][W_iTextAlignment] == 0) position = "Left";
				    else if(g_Werbebanner[werbetafel][W_iTextAlignment] == 1) position = "Center";
				    else if(g_Werbebanner[werbetafel][W_iTextAlignment] == 2) position = "Right";
				    format(title, sizeof(title), ""COLOR_R"Text Alignment "COLOR_G"| "COLOR_B"Current Alignment: "COLOR_Y"%s",position);
                    ShowPlayerDialog(playerid,AlignDialog,DIALOG_STYLE_LIST,title,""COLOR_Y"1. "COLOR_B"Left\n"COLOR_Y"2. "COLOR_B"Center\n"COLOR_Y"3. "COLOR_B"Right","Change","Back");
				}
				/*
				case 11: {
				    EditPlayerObject(playerid, Object[playerid]);
					SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"INFO: "COLOR_Y"Use "COLOR_G"ESC "COLOR_Y"to cancel the object edition.");
				}
				case 12: {
				    ShowPlayerDialog(playerid,SaveDialog,DIALOG_STYLE_INPUT,"    "COLOR_R"Exporting Lines",
					"Please, type a name for the object below (example = MyObject):","Export","Back");
				}
				*/
				case 13: {
                    // CreatingTextO[playerid] = false;
					// DestroyDynamicObject(playerid, g_Werbebanner[werbetafel][W_iObjectID]);
					g_Werbebanner[werbetafel][W_iTextAlignment] = 1;
					format(g_Werbebanner[werbetafel][W_sText],256,"Example");
					format(g_Werbebanner[werbetafel][W_iFontFace],32,"Arial");
					g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFFFF8200");
					g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFF000000");
     				g_Werbebanner[werbetafel][W_iFontSize] = 50;
					g_Werbebanner[werbetafel][W_iMaterialIndex] = 0;
					g_Werbebanner[werbetafel][W_iBold] = 0;
					g_Werbebanner[werbetafel][W_iFontSize] = 24;
					// g_Werbebanner[werbetafel][W_iModelID] = 19353;
					SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"INFO: "COLOR_Y"All settings have been reseted.");
                    SaveWerbebannerEx(werbetafel);
				}
	        }
	    }
	    return 1;
	}
	if(dialogid == DIALOG_WERBEANLEITUNG ) {
	    ShowMainMenu(playerid);
	}
	/*
	if(dialogid == OTypeDialog)
	{
	    if(response)
	    {
	        ObjectType[playerid] = false;
	        SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"Object Type: "COLOR_Y"Normal Object"); ShowMainMenu(playerid);
	    } else {
			ObjectType[playerid] = true;
            SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"Object Type: "COLOR_Y"Player Object"); ShowMainMenu(playerid);
		}
	    return 1;
	}
	if(dialogid == OModelDialog)
	{
	    if(response)
	    {
	        if(!IsNumeric(inputtext)) return SendClientMessage(playerid,-1,""COLOR_Y"* "COLOR_R"ERROR: "COLOR_G"Please, use a numeric value"COLOR_R"!"), ShowMainMenu(playerid);
	        new string[128];
	        ObjectID[playerid] = strval(inputtext);
	        format(string, sizeof(string), ""COLOR_R"* "COLOR_B"Object Model ID: "COLOR_Y"%d",ObjectID[playerid]);
	        SendClientMessage(playerid,-1,string); UpdateObject(werbetafel), ShowMainMenu(playerid);
	    } else { ShowMainMenu(playerid); }
	    return 1;
	}
	*/
	if(dialogid == TextDialog){
	    if(response){
	        new
	            string[400];
	        g_Werbebanner[werbetafel][W_sText][0] = '\0';
	        strcat( g_Werbebanner[werbetafel][W_sText] , inputtext , 256 );
	        
			format(string, sizeof(string), ""COLOR_R"* "COLOR_B"Object Text: "COLOR_Y"%s",g_Werbebanner[werbetafel][W_sText]);
	        SendClientMessage(playerid,-1,string); UpdateObject(werbetafel), ShowMainMenu(playerid);
	        SaveWerbebannerEx(werbetafel);
	    } else { ShowMainMenu(playerid); }
		return 1;
	}
	/*
	if(dialogid == IndexDialog){
	    if(response){
	        if(!IsNumeric(inputtext)) return SendClientMessage(playerid,-1,""COLOR_Y"* "COLOR_R"ERROR: "COLOR_G"Please, use a numeric value"COLOR_R"!"), ShowMainMenu(playerid);
			new string[100];
			Index[playerid] = strval(inputtext);
			format(string, sizeof(string),""COLOR_R"* "COLOR_B"Object Material Index: "COLOR_Y"%d",Index[playerid]);
			SendClientMessage(playerid,-1,string); UpdateObject(werbetafel), ShowMainMenu(playerid);
	    } else { ShowMainMenu(playerid); }
		return 1;
	}
	*/
	if(dialogid == SizesDialog){
	    if(response)
	    {
	        switch(listitem) {
	            case 0: g_Werbebanner[werbetafel][W_iMaterialSize] = 10;
	            case 1:  g_Werbebanner[werbetafel][W_iMaterialSize] = 20;
	            case 2:  g_Werbebanner[werbetafel][W_iMaterialSize] = 30;
	            case 3:  g_Werbebanner[werbetafel][W_iMaterialSize] = 40;
	            case 4:  g_Werbebanner[werbetafel][W_iMaterialSize] = 50;
	            case 5:  g_Werbebanner[werbetafel][W_iMaterialSize] = 60;
	            case 6:  g_Werbebanner[werbetafel][W_iMaterialSize] = 70;
	            case 7:  g_Werbebanner[werbetafel][W_iMaterialSize] = 80;
	            case 8:  g_Werbebanner[werbetafel][W_iMaterialSize] = 90;
	            case 9:  g_Werbebanner[werbetafel][W_iMaterialSize] = 100;
	            case 10:  g_Werbebanner[werbetafel][W_iMaterialSize] = 110;
	            case 11:  g_Werbebanner[werbetafel][W_iMaterialSize] = 120;
	            case 12:  g_Werbebanner[werbetafel][W_iMaterialSize] = 130;
	            case 13:  g_Werbebanner[werbetafel][W_iMaterialSize] = 140;
	            default: g_Werbebanner[werbetafel][W_iMaterialSize] = 70;
			}
			new string[128];
			format(string, sizeof(string), ""COLOR_R"* "COLOR_B"Object Material Size: "COLOR_Y"%d",g_Werbebanner[werbetafel][W_iMaterialSize]);
			SendClientMessage(playerid,-1,string); UpdateObject(werbetafel), ShowMainMenu(playerid);
            SaveWerbebannerEx(werbetafel);
	    } else { ShowMainMenu(playerid); }
	    return 1;
	}
	if(dialogid == FontNDialog)
	{
	    if(response) {
	        new string[128]; format(string, sizeof(string),"%s",inputtext);
			format(g_Werbebanner[werbetafel][W_iFontFace],32,string);
	        format(string, sizeof(string), ""COLOR_R"* "COLOR_B"Text Font: "COLOR_Y"%s",g_Werbebanner[werbetafel][W_iFontFace]);
			SendClientMessage(playerid,-1,string);
			UpdateObject(werbetafel);
			ShowMainMenu(playerid);
			SaveWerbebannerEx(werbetafel);
	    } else { ShowMainMenu(playerid); }
	    return 1;
	}
	if(dialogid == FontSDialog)
	{
	    if(response) {
	        if(!IsNumeric(inputtext)) return SendClientMessage(playerid,-1,""COLOR_Y"* "COLOR_R"ERROR: "COLOR_G"Please, use a numeric value"COLOR_R"!"), ShowMainMenu(playerid);
	        new string[128];
			g_Werbebanner[werbetafel][W_iFontSize] = strval(inputtext);
			format(string, sizeof(string), ""COLOR_R"* "COLOR_B"Text Size: "COLOR_Y"%d",g_Werbebanner[werbetafel][W_iFontSize]);
			SendClientMessage(playerid,-1,string);
			UpdateObject(werbetafel), ShowMainMenu(playerid);
			SaveWerbebannerEx(werbetafel);
	    } else { ShowMainMenu(playerid); }
	    return 1;
	}
	if(dialogid == BoldDialog)
	{
	    if(response)
	    {
			switch(listitem)
			{
	        	case 0: {
                    g_Werbebanner[werbetafel][W_iBold] = 0;
	        		SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"Bold Text: "COLOR_Y"No");
	        		UpdateObject(werbetafel), ShowMainMenu(playerid);
				}
				case 1: {
				    g_Werbebanner[werbetafel][W_iBold] = 1;
	        		SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"Bold Text: "COLOR_Y"Yes");
	        		UpdateObject(werbetafel), ShowMainMenu(playerid);
				}
				
			}
			SaveWerbebannerEx(werbetafel);
	    } else { ShowMainMenu(playerid); }
	    return 1;
	}
	if(dialogid == ColorDialog)
	{
	    if(response)
	    {
			switch(listitem)
			{
			    case 0: {
			        ShowPlayerDialog(playerid,ColorDialog2,DIALOG_STYLE_INPUT,"    "COLOR_R"Text Color",
			        ""COLOR_G"Please, type a ARGB color code below (example = 0xFFFF0000):","Change","Back");
			    }
			    case 1: {
			        ShowPlayerDialog(playerid,ColorDialog3,DIALOG_STYLE_LIST,""COLOR_R"Color List",
			        "{FF0000}Red\n{04B404}Green\n{00B5CD}Sky-Blue\n{FFFF00}Yellow\
					\n{0000FF}Blue\n{848484}Grey\n{FF00FF}Pink\n{FFFFFF}White","Change","Back");
			    }
			}
	    } else { ShowMainMenu(playerid); }
	    return 1;
	}
	if(dialogid == ColorDialog2)
	{
	    if(response) {
	    	new string[80]; g_Werbebanner[werbetafel][W_iFontColor] = HexToInt(inputtext);
			format(string, sizeof(string),""COLOR_R"* "COLOR_B"Text Color: "COLOR_Y"%i", g_Werbebanner[werbetafel][W_iFontColor]);
			SendClientMessage(playerid,-1,string); UpdateObject(werbetafel), ShowMainMenu(playerid);
		} else {
		    new titulo[100];
		    format(titulo, sizeof(titulo),""COLOR_R"Text Color "COLOR_G"| "COLOR_B"Current Text Color: "COLOR_Y"%i",g_Werbebanner[werbetafel][W_iFontColor]);
            ShowPlayerDialog(playerid,ColorDialog,DIALOG_STYLE_LIST,titulo,""COLOR_Y"1. "COLOR_B"Type a ARGB color code\
			\n"COLOR_Y"2. "COLOR_B"Select a predefinded color","Next","Back");
		}
   		return 1;
	}
	if(dialogid == ColorDialog3)
	{
	    if(response) {
	        switch(listitem)
	        {
	            case 0: { g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFFFF0000"); } //Red
	            case 1: { g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFF04B404"); }
	            case 2: { g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFF00B5CD"); }
	            case 3: { g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFFFFFF00"); } //Yellow
	            case 4: { g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFF0000FF"); }
	            case 5: { g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFF848484"); }
	            case 6: { g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFFFF00FF"); }
	            case 7: { g_Werbebanner[werbetafel][W_iFontColor] = HexToInt("0xFFFFFFFF"); } //White
	        }
	        new string[80]; UpdateObject(werbetafel);
	        format(string, sizeof(string),""COLOR_R"* "COLOR_B"Text Color: "COLOR_Y"%i",g_Werbebanner[werbetafel][W_iFontColor]);
			SendClientMessage(playerid,-1,string); ShowMainMenu(playerid);
			SaveWerbebannerEx(werbetafel);
		} else {
		    new titulo[100];
		    format(titulo, sizeof(titulo),""COLOR_R"Text Color "COLOR_G"| "COLOR_B"Current Text Color: "COLOR_Y"%i",g_Werbebanner[werbetafel][W_iFontColor]);
            ShowPlayerDialog(playerid,ColorDialog,DIALOG_STYLE_LIST,titulo,""COLOR_Y"1. "COLOR_B"Type a ARGB color code\
			\n"COLOR_Y"2. "COLOR_B"Select a predefinded color","Next","Back");
			SaveWerbebannerEx(werbetafel);
		}
   		return 1;
	}
	if(dialogid == BackgColorD)
	{
	    if(response)
	    {
	        switch(listitem)
	        {
	            case 0: { g_Werbebanner[werbetafel][W_iBackColor] = 0; UpdateObject(werbetafel);  ShowMainMenu(playerid); SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"Background Color: "COLOR_Y"Disabled"); }
	            case 1: {
	                ShowPlayerDialog(playerid,ColorDialog4,DIALOG_STYLE_INPUT,"    "COLOR_R"Background Color",
			        ""COLOR_G"Please, type a ARGB color code below (example = 0xFFFF0000):","Change","Back");
	            }
	            case 2: {
	                ShowPlayerDialog(playerid,ColorDialog5,DIALOG_STYLE_LIST,""COLOR_R"Color List",
			        "{FF0000}Red\n{04B404}Green\n{00B5CD}Sky-Blue\n{FFFF00}Yellow\
					\n{0000FF}Blue\n{848484}Grey\n{FF00FF}Pink\n{FFFFFF}White","Change","Back");
	            }
	        }
	    } else { ShowMainMenu(playerid); }
	    return 1;
	}
	if(dialogid == ColorDialog4)
	{
	    if(response) {
	    	new string[80]; g_Werbebanner[werbetafel][W_iBackColor] = HexToInt(inputtext);
			format(string, sizeof(string),""COLOR_R"* "COLOR_B"Background Color: "COLOR_Y"%i",g_Werbebanner[werbetafel][W_iBackColor]);
			SendClientMessage(playerid,-1,string); UpdateObject(werbetafel), ShowMainMenu(playerid);
			SaveWerbebannerEx(werbetafel);
		} else {
		    new titulo[100];
		    format(titulo, sizeof(titulo),""COLOR_R"Object Background "COLOR_G"| "COLOR_B"Current Text Color: "COLOR_Y"%i",g_Werbebanner[werbetafel][W_iBackColor]);
            ShowPlayerDialog(playerid,BackgColorD,DIALOG_STYLE_LIST,titulo,""COLOR_Y"1. "COLOR_B"Disable Background\n"COLOR_Y"2. "COLOR_B"Type a ARGB color code\
			\n"COLOR_Y"3. "COLOR_B"Select a predefinded color","Next","Back");
		}
   		return 1;
	}
	if(dialogid == ColorDialog5)
	{
	    if(response) {
	        switch(listitem)
	        {
	            case 0: { g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFFFF0000"); } //Red
	            case 1: { g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFF04B404"); }
	            case 2: { g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFF00B5CD"); }
	            case 3: { g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFFFFFF00"); } //Yellow
	            case 4: { g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFF0000FF"); }
	            case 5: { g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFF848484"); }
	            case 6: { g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFFFF00FF"); }
	            case 7: { g_Werbebanner[werbetafel][W_iBackColor] = HexToInt("0xFFFFFFFF"); } //White
	        }
	        new string[80]; UpdateObject(werbetafel); ShowMainMenu(playerid);
	        format(string, sizeof(string),""COLOR_R"* "COLOR_B"Background Color: "COLOR_Y"%i", g_Werbebanner[werbetafel][W_iBackColor]);
			SendClientMessage(playerid,-1,string);
			SaveWerbebannerEx(werbetafel);
		} else {
		    new titulo[100];
		    format(titulo, sizeof(titulo),""COLOR_R"Object Background "COLOR_G"| "COLOR_B"Current Text Color: "COLOR_Y"%i",g_Werbebanner[werbetafel][W_iBackColor]);
            ShowPlayerDialog(playerid,BackgColorD,DIALOG_STYLE_LIST,titulo,""COLOR_Y"1. "COLOR_B"Disable Background\n"COLOR_Y"2. "COLOR_B"Type a ARGB color code\
			\n"COLOR_Y"3. "COLOR_B"Select a predefinded color","Next","Back");
		}
   		return 1;
	}
	if(dialogid == AlignDialog)
	{
	    if(response) {
			switch(listitem)
			{
			    case 0: {
					g_Werbebanner[werbetafel][W_iTextAlignment] = 0; UpdateObject(werbetafel);
					SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"Text Alignment: "COLOR_Y"Left"), ShowMainMenu(playerid);
				}
				case 1: {
					g_Werbebanner[werbetafel][W_iTextAlignment] = 1; UpdateObject(werbetafel);
					SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"Text Alignment: "COLOR_Y"Center"), ShowMainMenu(playerid);
				}
				case 2: {
					g_Werbebanner[werbetafel][W_iTextAlignment] = 2; UpdateObject(werbetafel);
					SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"Text Alignment: "COLOR_Y"Right"), ShowMainMenu(playerid);
				}
				
			}
			SaveWerbebannerEx(werbetafel);
		} else { ShowMainMenu(playerid); }
	}
	/*
	if(dialogid == SaveDialog)
	{
	    if(response)
	    {
	        if(strlen(inputtext) <= 0) return SendClientMessage(playerid,-1,""COLOR_Y"* "COLOR_R"ERROR: "COLOR_G"Please, type something for the object name"COLOR_R"!"), ShowMainMenu(playerid);
			new string[600], soname[30];
			format(soname, sizeof(soname),"%s",inputtext); OName[playerid] = soname;
		    new Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ;
		    GetPlayerObjectPos(playerid, Object[playerid], fX, fY, fZ),
			GetPlayerObjectRot(playerid, Object[playerid], fRotX, fRotY, fRotZ);
		    if(!fexist("textobjects.txt"))
			{
			    new File:archivo = fopen("textobjects.txt", io_write);
			    if(ObjectType[playerid] == false) {
			        format(string, sizeof(string),"new %s = CreateObject(%d, %0.4f, %0.4f, %0.4f, %0.4f, %0.4f, %0.4f);\
					\r\nSetObjectMaterialText(%s, \"%s\", %d, %d, \"%s\", %d, %d, %i, %i, %d);",OName[playerid],ObjectID[playerid],
					fX, fY, fZ, fRotX, fRotY, fRotZ, OName[playerid], Text[playerid], Index[playerid], Size[playerid], FontName[playerid],
					FontSize[playerid], UseBold[playerid], TextColor[playerid], BackgColor[playerid], TextAlign[playerid]);
			        fwrite(archivo,string);
			        fclose(archivo);
			    } else {
					format(string, sizeof(string),"new %s = CreatePlayerObject(playerid, %d, %0.4f, %0.4f, %0.4f, %0.4f, %0.4f, %0.4f);\
					\r\nSetPlayerObjectMaterialText(playerid, %s, \"%s\", %d, %d, \"%s\", %d, %d, %i, %i, %d);",OName[playerid],ObjectID[playerid],
					fX, fY, fZ, fRotX, fRotY, fRotZ, OName[playerid], Text[playerid], Index[playerid], Size[playerid], FontName[playerid],
					FontSize[playerid], UseBold[playerid], TextColor[playerid], BackgColor[playerid], TextAlign[playerid]);
			        fwrite(archivo,string); fclose(archivo);
				}
			} else {
            	new File:archivo = fopen("textobjects.txt", io_append);
            	if(ObjectType[playerid] == false) {
			        format(string, sizeof(string),"\r\n\r\nnew %s = CreateObject(%d, %0.4f, %0.4f, %0.4f, %0.4f, %0.4f, %0.4f);\
					\r\nSetObjectMaterialText(%s, \"%s\", %d, %d, \"%s\", %d, %d, %i, %i, %d);",OName[playerid],ObjectID[playerid],
					fX, fY, fZ, fRotX, fRotY, fRotZ, OName[playerid], Text[playerid], Index[playerid], Size[playerid], FontName[playerid],
					FontSize[playerid], UseBold[playerid], TextColor[playerid], BackgColor[playerid], TextAlign[playerid]);
			        fwrite(archivo,string); fclose(archivo);
			    } else {
					format(string, sizeof(string),"\r\n\r\nnew %s = CreatePlayerObject(playerid, %d, %0.4f, %0.4f, %0.4f, %0.4f, %0.4f, %0.4f);\
					\r\nSetPlayerObjectMaterialText(playerid, %s, \"%s\", %d, %d, \"%s\", %d, %d, %i, %i, %d);",OName[playerid],ObjectID[playerid],
					fX, fY, fZ, fRotX, fRotY, fRotZ, OName[playerid], Text[playerid], Index[playerid], Size[playerid], FontName[playerid],
					FontSize[playerid], UseBold[playerid], TextColor[playerid], BackgColor[playerid], TextAlign[playerid]);
			        fwrite(archivo,string); fclose(archivo);
				}
			}
			//---
			CreatingTextO[playerid] = false, DestroyPlayerObject(playerid, Object[playerid]);
			TextAlign[playerid] = 1, Text[playerid] = "Example", FontName[playerid] = "Arial",
			TextColor[playerid] = HexToInt("0xFFFF8200"), BackgColor[playerid] = HexToInt("0xFF000000"),
			Size[playerid] = 50, Index[playerid] = 0, UseBold[playerid] = 0,
			FontSize[playerid] = 24, OName[playerid] = "0", ObjectID[playerid] = 19353;
			//---
			SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"INFO: "COLOR_Y"Script saved, check your "COLOR_G"textobjects.txt "COLOR_Y"in "COLOR_G"scriptfiles"COLOR_Y".");
			SendClientMessage(playerid,-1,""COLOR_R"* "COLOR_B"INFO: "COLOR_Y"All settings have been reseted.");
	    } else { ShowMainMenu(playerid); }
	    return 1;
	}
	*/
    return 0;
}
stock HexToInt(string[]) //By Zamaroht, I think... =/
{
  if (string[0]==0) return 0;
  new i;
  new cur=1;
  new res=0;
  for (i=strlen(string);i>0;i--) {
    if (string[i-1]<58) res=res+cur*(string[i-1]-48); else res=res+cur*(string[i-1]-65+10);
    cur=cur*16;
  }
  return res;
}
stock UpdateObject(werbetafel)
{
	/*
	new
	    werbetafel;
	werbetafel = IsPlayerAtWerbetafel(playerid);
	if(werbetafel == 999 ) {
	    return 0;
	}
	*/
	new
	    anzahl,
	    debugstring[256];

    strcat(debugstring,g_Werbebanner[werbetafel][W_sText]);
    strreplace(debugstring,"<br>","%c");

    // print(debugstring);
    //printf("anzahl = %d",anzahl);
	switch(anzahl) {
	    case 1: format(debugstring,sizeof(debugstring),debugstring,'\n');
	    case 2: format(debugstring,sizeof(debugstring),debugstring,'\n','\n');
	    case 3: format(debugstring,sizeof(debugstring),debugstring,'\n','\n','\n');
	    case 4: format(debugstring,sizeof(debugstring),debugstring,'\n','\n','\n','\n');
	    case 5: format(debugstring,sizeof(debugstring),debugstring,'\n','\n','\n','\n','\n');
	    case 6: format(debugstring,sizeof(debugstring),debugstring,'\n','\n','\n','\n','\n','\n');
	    case 7: format(debugstring,sizeof(debugstring),debugstring,'\n','\n','\n','\n','\n','\n','\n');
	    case 8: format(debugstring,sizeof(debugstring),debugstring,'\n','\n','\n','\n','\n','\n','\n','\n');
	}
    
	SetDynamicObjectMaterialText(
		g_Werbebanner[werbetafel][W_iObjectID],
		g_Werbebanner[werbetafel][W_iMaterialIndex],
	 	debugstring,
		g_Werbebanner[werbetafel][W_iMaterialSize],
		g_Werbebanner[werbetafel][W_iFontFace],
		g_Werbebanner[werbetafel][W_iFontSize],
		g_Werbebanner[werbetafel][W_iBold],
		g_Werbebanner[werbetafel][W_iFontColor],
		g_Werbebanner[werbetafel][W_iBackColor],
		g_Werbebanner[werbetafel][W_iTextAlignment]
	);
	return 1;
}


stock WerbetafelZuVermieten(werbetafel) {
    format(g_Werbebanner[werbetafel][W_sText],256,"{FF9900}Werbetafel zu vermieten\n{00FFFF}Dauer: {FFFFFF}4 Tage\n{00FF00}Kosten: {FFFFFF}40.000$");
	format(g_Werbebanner[werbetafel][W_sOwner],MAX_PLAYER_NAME,"Niemand");
	g_Werbebanner[werbetafel][W_unixBought] = 0;
	g_Werbebanner[werbetafel][W_iMaterialIndex] = 0;
	g_Werbebanner[werbetafel][W_iMaterialSize] = 90;
	format(g_Werbebanner[werbetafel][W_iFontFace],24,"Arial");
	g_Werbebanner[werbetafel][W_iFontSize] = 20;
	g_Werbebanner[werbetafel][W_iBold] = 1;
	g_Werbebanner[werbetafel][W_iFontColor] = 0xFFFFFFFF;
	g_Werbebanner[werbetafel][W_iBackColor] = -16777216;
	g_Werbebanner[werbetafel][W_iTextAlignment] = 1;
	UpdateDynamic3DTextLabelText(g_Werbebanner[werbetafel][W_t3dLabel],0xFFFFFFFF,"Diese Werbetafel steht zum Verkauf!");
	return 1;
}
