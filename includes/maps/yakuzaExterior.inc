#include <YSI\y_hooks>

// Global interior define
#define MAPS_YAKUZAEXTERIOR_INTERIOR      0
#define MAPS_YAKUZAINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Yakuza points
#define YAKUZA_INTERIOR_ENTER_COORDS        1046.3217, 1008.5336, 11.0000
#define YAKUZA_INTERIOR_EXIT_COORDS         2234.0027, 1713.4369, 1012.1367
#define YAKUZA_INTERIOR_ENTER_FACING        180.0
#define YAKUZA_INTERIOR_EXIT_FACING         320.5

// Map variables
new object_yakuzaExterior[24];
new pickup_yakuzaExterior[1];
new text3D_yakuzaExterior[1];
new vehicle_yakuzaExterior[16];

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, YAKUZA_INTERIOR_ENTER_COORDS)) { // Yakuza Entrance
            if (Spieler[playerid][pFraktion] != 10) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Yakuza.");
            SetPlayerInterior(playerid, MAPS_YAKUZAINTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_YAKUZAINTERIOR);
            SetPlayerPos(playerid, YAKUZA_INTERIOR_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, YAKUZA_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Vehicles
    vehicle_yakuzaExterior[0] = AddStaticVehicleEx(560, 1060.8455, 1003.2398, 10.7049, 343.6647, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[1] = AddStaticVehicleEx(560, 1064.5527, 1002.2625, 10.7050, 345.5482, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[2] = AddStaticVehicleEx(411, 1031.2972, 1023.8698, 10.6505, 306.0809, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[3] = AddStaticVehicleEx(560, 1057.3182, 1004.2559, 10.7051, 344.2378, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[4] = AddStaticVehicleEx(411, 1029.0913, 1027.0346, 10.7178, 305.6538, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[5] = AddStaticVehicleEx(541, 1024.7022, 1033.4511, 10.6250, 304.5452, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[6] = AddStaticVehicleEx(579, 1072.5628, 1000.3178, 10.9321, 344.0097, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[7] = AddStaticVehicleEx(482, 1076.5375, 998.7431, 11.1202, 343.2066, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[8] = AddStaticVehicleEx(579, 1068.5966, 1001.4723, 10.9336, 342.9969, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[9] = AddStaticVehicleEx(480, 1020.8213, 1039.5676, 10.7727, 302.7391, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[10] = AddStaticVehicleEx(451, 1027.0180, 1030.4375, 10.7065, 305.1675, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[11] = AddStaticVehicleEx(415, 1022.7122, 1036.6342, 10.7718, 302.7264, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[12] = AddStaticVehicleEx(522, 1035.0516, 1017.4267, 10.5487, 286.6670, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[13] = AddStaticVehicleEx(522, 1033.6325, 1018.8350, 10.5691, 285.4402, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[14] = AddStaticVehicleEx(521, 1052.3873, 1004.5975, 10.6684, 5.7473, 13, 13, -1); // Yakuza
	vehicle_yakuzaExterior[15] = AddStaticVehicleEx(521, 1050.5258, 1005.7860, 10.6317, 7.7559, 13, 13, -1); // Yakuza

    // Pickups
    pickup_yakuzaExterior[0] = CreateDynamicPickup(19197, 1, YAKUZA_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR); // Yakuza Entrance
    
    // 3DTextLabels
    text3D_yakuzaExterior[0] = _:CreateDynamic3DTextLabel("Territorium der\n" COLOR_HEX_GRAU "YAKUZA", COLOR_YELLOW, YAKUZA_INTERIOR_ENTER_COORDS, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_YAKUZAEXTERIOR_INTERIOR);
    
    // Actors

    // Objects
    object_yakuzaExterior[0] = CreateDynamicObject(1215, 1053.7462, 1002.2079, 10.4697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[1] = CreateDynamicObject(1215, 1078.4964, 994.9673, 10.4697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[2] = CreateDynamicObject(1215, 1031.4466, 1018.6584, 10.4697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[3] = CreateDynamicObject(1215, 1016.8665, 1040.5992, 10.4697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[4] = CreateDynamicObject(3934, 1088.2928, 1064.6407, 9.8289, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_yakuzaExterior[5] = CreateDynamicObject(3934, 1098.1514, 1074.4993, 9.8289, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_yakuzaExterior[6] = CreateDynamicObject(3934, 1088.3702, 1084.2806, 9.8289, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_yakuzaExterior[7] = CreateDynamicObject(3934, 1078.5410, 1074.4514, 9.8289, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_yakuzaExterior[8] = CreateDynamicObject(1215, 1083.1650, 1064.2180, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[9] = CreateDynamicObject(1215, 1087.9653, 1059.3758, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[10] = CreateDynamicObject(1215, 1093.3950, 1064.8057, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[11] = CreateDynamicObject(1215, 1088.5743, 1069.6268, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[12] = CreateDynamicObject(1215, 1088.0438, 1079.0378, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[13] = CreateDynamicObject(1215, 1088.6444, 1089.2486, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[14] = CreateDynamicObject(1215, 1093.4750, 1084.4390, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[15] = CreateDynamicObject(1215, 1083.2446, 1083.8385, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[16] = CreateDynamicObject(1215, 1078.8037, 1079.4382, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[17] = CreateDynamicObject(1215, 1078.2337, 1069.1976, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[18] = CreateDynamicObject(1215, 1073.4218, 1074.0191, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[19] = CreateDynamicObject(1215, 1083.6442, 1074.6093, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[20] = CreateDynamicObject(1215, 1093.0242, 1074.0588, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[21] = CreateDynamicObject(1215, 1097.8243, 1069.2290, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[22] = CreateDynamicObject(1215, 1098.4149, 1079.5201, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_yakuzaExterior[23] = CreateDynamicObject(1215, 1103.2749, 1074.6400, 9.7697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
}
