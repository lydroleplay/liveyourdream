#include <YSI\y_hooks>

// Global interior define
#define MAPS_YAKUZAEXTERIOR_INTERIOR      0
#define MAPS_YAKUZAINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// Yakuza interior points
#define YAKUZA_INTERIOR_SPAWN_POINT               2235.7871, 1676.2056, 1008.3594
#define YAKUZA_INTERIOR_SPAWN_POINT_FACING        0.0
#define YAKUZA_INTERIOR_SAFEBOX_POINT             2225.8369, 1697.4304, 1008.3594
#define YAKUZA_INTERIOR_GANGSHOP_POINT            2245.9250, 1696.2772, 1008.3594
#define YAKUZA_INTERIOR_WEAPONS_DEPOT_POINT       2246.1025, 1698.0223, 1008.3594 // coords for functionality are loaded from database in lyd.pwn

// Map variables
new pickup_yakuzaInterior[4];
new text3D_yakuzaInterior[4];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, YAKUZA_INTERIOR_EXIT_COORDS)) { // Yakuza Exit
            SetPlayerInterior(playerid, MAPS_YAKUZAEXTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_MAIN);
            SetPlayerPos(playerid, YAKUZA_INTERIOR_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, YAKUZA_INTERIOR_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_yakuzaInterior[0] = CreateDynamicPickup(1240, 1, YAKUZA_INTERIOR_SPAWN_POINT, VW_YAKUZAINTERIOR, MAPS_YAKUZAINTERIOR_INTERIOR); // Spawn point
    pickup_yakuzaInterior[1] = CreateDynamicPickup(1275, 1, YAKUZA_INTERIOR_GANGSHOP_POINT, VW_YAKUZAINTERIOR, MAPS_YAKUZAINTERIOR_INTERIOR); // Gangshop point
    pickup_yakuzaInterior[2] = CreateDynamicPickup(1254, 1, YAKUZA_INTERIOR_WEAPONS_DEPOT_POINT, VW_YAKUZAINTERIOR, MAPS_YAKUZAINTERIOR_INTERIOR); // Weapons depot point
    pickup_yakuzaInterior[3] = CreateDynamicPickup(1279, 1, YAKUZA_INTERIOR_SAFEBOX_POINT, VW_YAKUZAINTERIOR, MAPS_YAKUZAINTERIOR_INTERIOR); // Safebox point

    // 3DTextLabels
    text3D_yakuzaInterior[0] = _:CreateDynamic3DTextLabel("Yakuza Spawn\n" COLOR_HEX_WHITE "Tippe /Gangwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, YAKUZA_INTERIOR_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_YAKUZAINTERIOR, .interiorid = MAPS_YAKUZAINTERIOR_INTERIOR); // Spawn point
    text3D_yakuzaInterior[1] = _:CreateDynamic3DTextLabel("Yakuza - Gangshop\n" COLOR_HEX_WHITE "Tippe /Gangitem", COLOR_YELLOW, YAKUZA_INTERIOR_GANGSHOP_POINT, 15.0, .testlos = 1, .worldid = VW_YAKUZAINTERIOR, .interiorid = MAPS_YAKUZAINTERIOR_INTERIOR); // Gangshop point
    text3D_yakuzaInterior[2] = _:CreateDynamic3DTextLabel("Yakuza - Waffenlager\n" COLOR_HEX_WHITE "Tippe /Waffenlager", COLOR_YELLOW, YAKUZA_INTERIOR_WEAPONS_DEPOT_POINT, 15.0, .testlos = 1, .worldid = VW_YAKUZAINTERIOR, .interiorid = MAPS_YAKUZAINTERIOR_INTERIOR); // Weapons depot point
    text3D_yakuzaInterior[3] = _:CreateDynamic3DTextLabel("Safebox der Yakuza\n" COLOR_HEX_WHITE "Tippe /FSafebox", COLOR_YELLOW, YAKUZA_INTERIOR_SAFEBOX_POINT, 15.0, .testlos = 1, .worldid = VW_YAKUZAINTERIOR, .interiorid = MAPS_YAKUZAINTERIOR_INTERIOR); // Safebox point

    // Actors

	// Objects
}