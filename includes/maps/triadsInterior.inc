#include <YSI\y_hooks>

// Global interior define
#define MAPS_TRIADSEXTERIOR_INTERIOR      0
#define MAPS_TRIADSINTERIOR_INTERIOR      6

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Yakuza interior points
#define TRIADS_INTERIOR_SPAWN_POINT               768.1578, -36.6934, 1000.6865
#define TRIADS_INTERIOR_SPAWN_POINT_FACING        180.0
#define TRIADS_INTERIOR_SAFEBOX_POINT             765.3478, -39.7774, 1000.6865
#define TRIADS_INTERIOR_GANGSHOP_POINT            777.1221, -40.4455, 1000.5859
#define TRIADS_INTERIOR_WEAPONS_DEPOT_POINT       771.2057, -39.4471, 1000.6865 // coords for functionality are loaded from database in lyd.pwn

// Map variables
new object_triadsInterior[6];
new pickup_triadsInterior[5];
new text3D_triadsInterior[4];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (GetPlayerVirtualWorld(playerid) == VW_TRIADSINTERIOR && IsPlayerInRangeOfPoint(playerid, 2.0, TRIADS_INTERIOR_EXIT_COORDS)) { // Triads Exit
            SetPlayerInterior(playerid, MAPS_TRIADSEXTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_MAIN);
            SetPlayerPos(playerid, TRIADS_INTERIOR_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, TRIADS_INTERIOR_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_triadsInterior[0] = CreateDynamicPickup(1240, 1, TRIADS_INTERIOR_SPAWN_POINT, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR); // Spawn point
    pickup_triadsInterior[1] = CreateDynamicPickup(1275, 1, TRIADS_INTERIOR_GANGSHOP_POINT, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR); // Gangshop point
    pickup_triadsInterior[2] = CreateDynamicPickup(1254, 1, TRIADS_INTERIOR_WEAPONS_DEPOT_POINT, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR); // Weapons depot point
    pickup_triadsInterior[3] = CreateDynamicPickup(1279, 1, TRIADS_INTERIOR_SAFEBOX_POINT, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR); // Safebox point
    pickup_triadsInterior[4] = CreateDynamicPickup(19197, 1, TRIADS_INTERIOR_EXIT_COORDS, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR); // Exit point

    // 3DTextLabels
    text3D_triadsInterior[0] = _:CreateDynamic3DTextLabel("Triaden Spawn\n" COLOR_HEX_WHITE "Tippe /Gangwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, TRIADS_INTERIOR_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_TRIADSINTERIOR, .interiorid = MAPS_TRIADSINTERIOR_INTERIOR); // Spawn point
    text3D_triadsInterior[1] = _:CreateDynamic3DTextLabel("Triaden - Gangshop\n" COLOR_HEX_WHITE "Tippe /Gangitem", COLOR_YELLOW, TRIADS_INTERIOR_GANGSHOP_POINT, 15.0, .testlos = 1, .worldid = VW_TRIADSINTERIOR, .interiorid = MAPS_TRIADSINTERIOR_INTERIOR); // Gangshop point
    text3D_triadsInterior[2] = _:CreateDynamic3DTextLabel("Triaden - Waffenlager\n" COLOR_HEX_WHITE "Tippe /Waffenlager", COLOR_YELLOW, TRIADS_INTERIOR_WEAPONS_DEPOT_POINT, 15.0, .testlos = 1, .worldid = VW_TRIADSINTERIOR, .interiorid = MAPS_TRIADSINTERIOR_INTERIOR); // Weapons depot point
    text3D_triadsInterior[3] = _:CreateDynamic3DTextLabel("Safebox der Triaden\n" COLOR_HEX_WHITE "Tippe /FSafebox", COLOR_YELLOW, TRIADS_INTERIOR_SAFEBOX_POINT, 15.0, .testlos = 1, .worldid = VW_TRIADSINTERIOR, .interiorid = MAPS_TRIADSINTERIOR_INTERIOR); // Safebox point

    // Actors

	// Objects
    object_triadsInterior[0] = CreateDynamicObject(2629, 766.30469, -48.30469, 999.57177, 360.00000, 0.00000, 0.00000, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsInterior[1] = CreateDynamicObject(2630, 769.24219, -47.89844, 999.57177, 360.00000, 0.00000, 0.00000, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsInterior[2] = CreateDynamicObject(2755, 762.21875, -28.80469, 1001.31250, 360.00000, 0.00000, 0.00000, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsInterior[3] = CreateDynamicObject(2755, 774.16406, -28.80469, 1001.31250, 360.00000, 0.00000, 0.00000, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsInterior[4] = CreateDynamicObject(2627, 759.63281, -48.12500, 999.57177, 360.00000, 0.00000, 0.00000, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_triadsInterior[5] = CreateDynamicObject(2755, 768.14063, -28.80469, 1001.31250, 360.00000, 0.00000, 0.00000, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}