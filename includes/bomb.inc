#define _include_bomb_

#define INVALID_BOMB_INDEX -1

#define BOMB_DISTANCE_DETONATE 100.0

enum {
	Bombe_Inactive = 0,
	Bombe_Planting,
	Bombe_Planted,
	Bombe_Defusing
}
enum e_Bomb {
	B_iStatus,
	B_iObjectID,
	Float:B_fX,
	Float:B_fY,
	Float:B_fZ,
	B_iInterior,
	B_iDraht,
	
	B_iTickBlocked,
	B_iTick,
	B_tBomb,
}

new Bombs[e_Bomb];

stock Bomb_PlantBomb(playerid,draht) {
	if( Bombs[B_iStatus] != Bombe_Inactive ) {
	    return 0;
	}
	new
	    Float:_Face,
	    _Interior,
	    Float:_X,
	    Float:_Y,
	    Float:_Z;
	GetPlayerPos(playerid,_X,_Y,_Z);
	_Interior = GetPlayerInterior(playerid);
	GetPlayerFacingAngle(playerid,_Face);

	GetXYInFrontOfPosition( _X , _Y , _Face , 0.8 );
	_Z -= 0.9;

	Bombs[B_iStatus] = Bombe_Planting;
	Bombs[B_fX] = _X;
	Bombs[B_fY] = _Y;
	Bombs[B_fZ] = _Z;
	Bombs[B_iInterior] = _Interior;
	Bombs[B_iDraht] = draht;
	Bombs[B_iObjectID] = CreateDynamicObject(1654,_X,_Y,_Z,float(random(360)),90.0,0.0,.interiorid = _Interior);

	ApplyAnimation(playerid, "BOMBER", "BOM_PLANT", 4.0, 1, 0, 0, 1, 0); // bombe legen
	SetTimerEx("Bomb_Delay",73,false,"d",playerid);
	Bombs[B_iTickBlocked] = 0;
	return 1;
}

forward Bomb_Delay(playerid);
public Bomb_Delay(playerid) {
	Streamer_Update(playerid);
	//Bombs[B_iTick] = gettime() + 30;
	Bombs[B_iTick] = gettime() + 2*60;
	Bombs[B_tBomb] = SetTimerEx("Bomb_Legen",1319,true,"d",playerid);
	return 1;
}

forward Bomb_Legen(playerid);
public Bomb_Legen(playerid) {
	//printf("Bomb_Legen(%s(%d))",GetName(playerid),playerid);
	if( Bombs[B_iTick] < gettime() ) {
		KillTimer( Bombs[B_tBomb] );
		ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_CROUCH_OUT", 4.0, 1, 0, 0, 1, 0); // bombe ende
		SendClientMessage(playerid,COLOR_YELLOW,"Bombe gelegt!");
		ClearAnimationsEx(playerid,100);
		CallLocalFunction("OnBombPlanted","d",playerid);
		Bombs[B_iStatus] = Bombe_Planted;
		Bombs[B_iTick] = gettime() + 10*60; // Nach dem die Bombe gelegt wurde, wie lange es dauert bis sie explodiert. 2*60 = 2 Minuten
	 	Bombs[B_tBomb] = SetTimer("Bomb_Pulse",1451,true);
	 	//printf("Bombs[B_tBomb] = %d",Bombs[B_tBomb]);
	}
	else {
		ApplyAnimation(playerid, "BOMBER", "BOM_PLANT_LOOP", 4.0, 1, 0, 0, 1, 0); // bombe idle
	}
	return 1;
}

forward Bomb_Pulse();
public Bomb_Pulse() {
	//printf("Bomb_Pulse() %d", GetTickCount() );
	if( gettime() >= Bombs[B_iTick] ) {
	    //printf("Bomb_Pulse KillTimer(%d)",Bombs[B_tBomb]);
	    SendClientMessageToAll(COLOR_RED,"ACHTUNG! Die Bombe ist explodiert! Es wurde Schaden angerichtet.");
	    Bomb_ExplodeBomb();
	}
	return 1;
}

stock DestroyBomb( ) {
    KillTimer(Bombs[B_tBomb]);
    Bombs[B_iStatus] = Bombe_Inactive;
    DestroyDynamicObject( Bombs[B_iObjectID] );
    Bombs[B_iTickBlocked] = gettime() + 5*60*60;
	return 1;
}

stock Bomb_ExplodeBomb() {
	//print("Bomb_ExplodeBomb");
	DestroyBomb();
	Bombs[B_tBomb] = SetTimer("Bomb_Explode",79,true);
	Bombs[B_iTick] = GetTickCount() + 750;
	return 1;
}
forward Bomb_Explode();
public Bomb_Explode() {
	//print("Bomb_Explode");
	if( Bombs[B_iTick] < GetTickCount() ) {
	    KillTimer(Bombs[B_tBomb]);
		//print("Bomb_Explode KillTimer");
	}
	CreateExplosion( Bombs[B_fX] + float(random(8)) - float(random(8)), Bombs[B_fY]  + float(random(8)) - float(random(8)) , ( Bombs[B_fZ] + 2.0 ) + float(random(5)) , 7 , float( random(8) + 5 ) );
	return 1;
}

stock IsPlayerInRangeOfBomb(playerid) {
    if( IsPlayerInRangeOfPoint(playerid,2.5,Bombs[B_fX],Bombs[B_fY],Bombs[B_fZ])) {
        return 1;
    }
	return 0;
}
