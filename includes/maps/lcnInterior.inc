#include <YSI\y_hooks>

// Global interior define
#define MAPS_LCNEXTERIOR_INTERIOR      0
#define MAPS_LCNINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// La Cosa Nostra interior points
#define LCN_INTERIOR_SPAWN_POINT               -780.2622, 506.0549, 1371.7422
#define LCN_INTERIOR_SPAWN_POINT_FACING        90.0
#define LCN_INTERIOR_SAFEBOX_POINT             -788.7941, 496.9221, 1371.7422
#define LCN_INTERIOR_GANGSHOP_POINT            -784.4557, 496.9431, 1371.7422
#define LCN_INTERIOR_WEAPONS_DEPOT_POINT       -779.5251, 496.6631, 1371.7490 // coords for functionality are loaded from database in lyd.pwn

// Map variables
new object_lcnInterior[1];
new pickup_lcnInterior[4];
new text3D_lcnInterior[4];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, LCN_INTERIOR_EXIT_COORDS)) { // LCN Exit
            SetPlayerInterior(playerid, MAPS_LCNEXTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_MAIN);
            SetPlayerPos(playerid, LCN_INTERIOR_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, LCN_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
	// Pickups            
    pickup_lcnInterior[0] = CreateDynamicPickup(1254, 1, LCN_INTERIOR_WEAPONS_DEPOT_POINT, VW_LCNINTERIOR, MAPS_LCNINTERIOR_INTERIOR);
    pickup_lcnInterior[1] = CreateDynamicPickup(1275, 1, LCN_INTERIOR_GANGSHOP_POINT, VW_LCNINTERIOR, MAPS_LCNINTERIOR_INTERIOR);
    pickup_lcnInterior[2] = CreateDynamicPickup(1279, 1, LCN_INTERIOR_SAFEBOX_POINT, VW_LCNINTERIOR, MAPS_LCNINTERIOR_INTERIOR);
    pickup_lcnInterior[3] = CreateDynamicPickup(1240, 1, LCN_INTERIOR_SPAWN_POINT, VW_LCNINTERIOR, MAPS_LCNINTERIOR_INTERIOR);

    // 3DTextLabels    
    text3D_lcnInterior[0] = _:CreateDynamic3DTextLabel("LCN - Gangshop\n" COLOR_HEX_WHITE "Tippe /Gangitem", COLOR_YELLOW, LCN_INTERIOR_GANGSHOP_POINT, 15.0, .testlos = 1, .worldid = VW_LCNINTERIOR, .interiorid = MAPS_LCNINTERIOR_INTERIOR);
    text3D_lcnInterior[2] = _:CreateDynamic3DTextLabel("LCN - Waffenlager\n" COLOR_HEX_WHITE "Tippe /Waffenlager", COLOR_YELLOW, LCN_INTERIOR_WEAPONS_DEPOT_POINT, 15.0, .testlos = 1, .worldid = VW_LCNINTERIOR, .interiorid = MAPS_LCNINTERIOR_INTERIOR);
    text3D_lcnInterior[3] = _:CreateDynamic3DTextLabel("LCN Spawn\n" COLOR_HEX_WHITE "Tippe /Gangwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, LCN_INTERIOR_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_LCNINTERIOR, .interiorid = MAPS_LCNINTERIOR_INTERIOR);
    text3D_lcnInterior[1] = _:CreateDynamic3DTextLabel("Safebox der LCN\n" COLOR_HEX_WHITE "Tippe /FSafebox", COLOR_YELLOW, LCN_INTERIOR_SAFEBOX_POINT, 15.0, .testlos = 1, .worldid = VW_LCNINTERIOR, .interiorid = MAPS_LCNINTERIOR_INTERIOR);

    // Objects
    object_lcnInterior[0] = CreateDynamicObject(19360, -791.964233, 495.070618, 1371.931519, 0.000000, 0.000000, 90.00000, VW_LCNINTERIOR, MAPS_LCNINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}