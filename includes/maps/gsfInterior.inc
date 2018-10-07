#include <YSI\y_hooks>

// Global interior define
#define MAPS_GSFEXTERIOR_INTERIOR      0
#define MAPS_GSFINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// GSF interior points
#define GSF_INTERIOR_SPAWN_POINT               2496.0542, -1709.4050, 1014.7422
#define GSF_INTERIOR_SPAWN_POINT_FACING        0.0
#define GSF_INTERIOR_SAFEBOX_POINT             2498.2847, -1710.8126, 1014.7422
#define GSF_INTERIOR_GANGSHOP_POINT            2491.7261, -1701.2618, 1018.3438
#define GSF_INTERIOR_WEAPONS_DEPOT_POINT       2491.1003, -1699.9390, 1014.7416 // coords for functionality are loaded from database in lyd.pwn

// Map variables
new pickup_gsfInterior[5];
new text3D_gsfInterior[4];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (GetPlayerVirtualWorld(playerid) == VW_GSFINTERIOR && IsPlayerInRangeOfPoint(playerid, 2.0, GSF_INTERIOR_EXIT_COORDS)) { // GSF Exit
            SetPlayerInterior(playerid, MAPS_GSFEXTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_MAIN);
            SetPlayerPos(playerid, GSF_INTERIOR_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, GSF_INTERIOR_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_gsfInterior[0] = CreateDynamicPickup(1240, 1, GSF_INTERIOR_SPAWN_POINT, VW_GSFINTERIOR, MAPS_GSFINTERIOR_INTERIOR); // Spawn point
    pickup_gsfInterior[1] = CreateDynamicPickup(1275, 1, GSF_INTERIOR_GANGSHOP_POINT, VW_GSFINTERIOR, MAPS_GSFINTERIOR_INTERIOR); // Gangshop point
    pickup_gsfInterior[2] = CreateDynamicPickup(1254, 1, GSF_INTERIOR_WEAPONS_DEPOT_POINT, VW_GSFINTERIOR, MAPS_GSFINTERIOR_INTERIOR); // Weapons depot point
    pickup_gsfInterior[3] = CreateDynamicPickup(1279, 1, GSF_INTERIOR_SAFEBOX_POINT, VW_GSFINTERIOR, MAPS_GSFINTERIOR_INTERIOR); // Safebox point
    pickup_gsfInterior[4] = CreateDynamicPickup(19197, 1, GSF_INTERIOR_EXIT_COORDS, VW_GSFINTERIOR, MAPS_GSFINTERIOR_INTERIOR); // Exit point

    // 3DTextLabels
    text3D_gsfInterior[0] = _:CreateDynamic3DTextLabel("Grove Street Spawn\n" COLOR_HEX_WHITE "Tippe /Gangwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, GSF_INTERIOR_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_GSFINTERIOR, .interiorid = MAPS_GSFINTERIOR_INTERIOR); // Spawn point
    text3D_gsfInterior[1] = _:CreateDynamic3DTextLabel("Grove Street - Gangshop\n" COLOR_HEX_WHITE "Tippe /Gangitem", COLOR_YELLOW, GSF_INTERIOR_GANGSHOP_POINT, 15.0, .testlos = 1, .worldid = VW_GSFINTERIOR, .interiorid = MAPS_GSFINTERIOR_INTERIOR); // Gangshop point
    text3D_gsfInterior[2] = _:CreateDynamic3DTextLabel("Grove Street - Waffenlager\n" COLOR_HEX_WHITE "Tippe /Waffenlager", COLOR_YELLOW, GSF_INTERIOR_WEAPONS_DEPOT_POINT, 15.0, .testlos = 1, .worldid = VW_GSFINTERIOR, .interiorid = MAPS_GSFINTERIOR_INTERIOR); // Weapons depot point
    text3D_gsfInterior[3] = _:CreateDynamic3DTextLabel("Safebox der Grove Street\n" COLOR_HEX_WHITE "Tippe /FSafebox", COLOR_YELLOW, GSF_INTERIOR_SAFEBOX_POINT, 15.0, .testlos = 1, .worldid = VW_GSFINTERIOR, .interiorid = MAPS_GSFINTERIOR_INTERIOR); // Safebox point
}