#include <YSI\y_hooks>

// Global interior define
#define MAPS_FBIEXTERIOR_INTERIOR      0
#define MAPS_FBIINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// FBI points
#define FBI_INTERIOR_SPAWN_POINT               246.3446, 185.5452, 1008.1719 // + 0.5
#define FBI_INTERIOR_SPAWN_POINT_FACING        0.0
#define FBI_INTERIOR_DUTY_POINT                244.3387, 192.4503, 1008.1719
#define FBI_INTERIOR_FSKIN_POINT               244.9089, 188.2697, 1008.1719
#define FBI_INTERIOR_WEAPONS_LOCKER_POINT      251.3374, 188.2731 ,1008.1719

// Map variables
new object_fbiInterior[5];
new pickup_fbiInterior[4];

hook OnPlayerConnect(playerid) {
	// ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, FBI_INTERIOR_EXIT_COORDS)) { // Exit
			SetPlayerFacingAngle(playerid, FBI_INTERIOR_ENTER_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, FBI_INTERIOR_ENTER_COORDS, MAPS_FBIEXTERIOR_INTERIOR, VW_MAIN);
			return 1;
		}
	}

	return 1;
}

hook OnGameModeInit() {    
	// Pickups
	pickup_fbiInterior[0] = CreateDynamicPickup(19197, 1, FBI_INTERIOR_EXIT_COORDS, VW_ALL, MAPS_FBIINTERIOR_INTERIOR); // Exit
    pickup_fbiInterior[1] = CreateDynamicPickup(1240, 1, FBI_INTERIOR_DUTY_POINT, VW_ALL, MAPS_FBIINTERIOR_INTERIOR); // Duty
    pickup_fbiInterior[2] = CreateDynamicPickup(1275, 1, FBI_INTERIOR_FSKIN_POINT, VW_ALL, MAPS_FBIINTERIOR_INTERIOR); // FSKIN
    pickup_fbiInterior[3] = CreateDynamicPickup(1242, 1, FBI_INTERIOR_WEAPONS_LOCKER_POINT, VW_ALL, MAPS_FBIINTERIOR_INTERIOR); // Weapons Locker

    // 3DTextLabels
    // ---

	// Objects - VW_ALL because they are necessary for LV Bank as well
	object_fbiInterior[0] = CreateDynamicObject(19860, 264.88489, 190.44450, 1008.42548, 0.00000, 0.00000, 90.00000, VW_ALL, MAPS_FBIINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiInterior[1] = CreateDynamicObject(19439, 264.99011, 191.09171, 1008.89130, 90.00000, 0.00000, 0.00000, VW_ALL, MAPS_FBIINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiInterior[2] = CreateDynamicObject(19439, 264.99011, 191.09171, 1007.28528, 90.00000, 0.00000, 0.00000, VW_ALL, MAPS_FBIINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiInterior[3] = CreateDynamicObject(19464, 237.58881, 193.96500, 1009.47888, 0.00000, 0.00000, 90.00000, VW_ALL, MAPS_FBIINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiInterior[4] = CreateDynamicObject(19464, 268.08679, 193.96500, 1009.47888, 0.00000, 0.00000, 90.00000, VW_ALL, MAPS_FBIINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}