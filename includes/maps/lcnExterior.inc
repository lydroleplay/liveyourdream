#include <YSI\y_hooks>

// Global interior define
#define MAPS_LCNEXTERIOR_INTERIOR      0
#define MAPS_LCNINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// La Cosa Nostra base points
#define LCN_INTERIOR_ENTER_COORDS        1083.0183, -1226.5609, 15.8203
#define LCN_INTERIOR_EXIT_COORDS         -794.9042, 490.1946, 1376.1953
#define LCN_INTERIOR_ENTER_FACING        270.0
#define LCN_INTERIOR_EXIT_FACING         0.0

// Map variables
new object_lcnExterior[33];
new pickup_lcnExterior[1];
new text3D_lcnExterior[1];
new vehicle_lcnExterior[17];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, LCN_INTERIOR_ENTER_COORDS)) { // LCN Entrance
            if (Spieler[playerid][pFraktion] != 12) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der LCN.");
            SetPlayerInterior(playerid, MAPS_LCNINTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_LCNINTERIOR);
            SetPlayerPos(playerid, LCN_INTERIOR_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, LCN_INTERIOR_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Pickups
    pickup_lcnExterior[0] = CreateDynamicPickup(19197, 1, LCN_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR); // LCN Entrance
    
    // 3DTextLabels
    text3D_lcnExterior[0] = _:CreateDynamic3DTextLabel("Territorium der\n" COLOR_HEX_BLACK "LCN", COLOR_YELLOW, LCN_INTERIOR_ENTER_COORDS, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LCNEXTERIOR_INTERIOR);
    
    // Vehicles
    vehicle_lcnExterior[0] = AddStaticVehicleEx(411, 1093.5651, -1225.2573, 15.5453, 179.6005, 75, 75, -1); // LCNInfernus1
	vehicle_lcnExterior[1] = AddStaticVehicleEx(411, 1097.7482, -1225.2493, 15.5518, 178.5437, 75, 75, -1); // LCNInfernus2
	vehicle_lcnExterior[2] = AddStaticVehicleEx(541, 1101.8160, -1224.9753, 15.4502, 180.5087, 75, 75, -1); // LCNBullet
	vehicle_lcnExterior[3] = AddStaticVehicleEx(451, 1105.7065, -1225.3906, 15.5357, 180.2435, 75, 75, -1); // LCNTurismo
	vehicle_lcnExterior[4] = AddStaticVehicleEx(415, 1110.0857, -1225.2145, 15.5810, 177.0805, 75, 75, -1); // LCNCHeetah
	vehicle_lcnExterior[5] = AddStaticVehicleEx(560, 1085.1581, -1233.8633, 15.5268, 270.0235, 75, 75, -1); // LCNSultan1
	vehicle_lcnExterior[6] = AddStaticVehicleEx(560, 1085.1577, -1238.1287, 15.5303, 270.0153, 75, 75, -1); // LCNSultan2
	vehicle_lcnExterior[7] = AddStaticVehicleEx(545, 1085.0730, -1242.3641, 15.6388, 269.5403, 75, 75, -1); // LCNHustler
	vehicle_lcnExterior[8] = AddStaticVehicleEx(409, 1086.2042, -1249.8860, 15.6279, 312.7260, 75, 75, -1); // LCNStretch
	vehicle_lcnExterior[9] = AddStaticVehicleEx(579, 1094.4312, -1250.1664, 15.7551, 0.0048, 75, 75, -1); // LCNHuntley
	vehicle_lcnExterior[10] = AddStaticVehicleEx(579, 1098.6012, -1250.1639, 15.7501, 359.7653, 75, 75, -1); // LCNHuntle2
	vehicle_lcnExterior[11] = AddStaticVehicleEx(580, 1103.6172, -1250.3773, 15.6175, 359.0536, 75, 75, -1); // LCNStafford1
	vehicle_lcnExterior[12] = AddStaticVehicleEx(580, 1109.1460, -1250.3403, 15.6179, 358.9023, 75, 75, -1); // LCNStafford2
	vehicle_lcnExterior[13] = AddStaticVehicleEx(522, 1120.5494, -1248.6732, 15.6190, 87.9424, 75, 75, -1); // LCNNRG1
	vehicle_lcnExterior[14] = AddStaticVehicleEx(522, 1120.5509, -1247.0037, 15.6137, 86.6539, 75, 75, -1); // LCNNRG2
	vehicle_lcnExterior[15] = AddStaticVehicleEx(468, 1120.6541, -1245.2303, 15.7300, 86.4783, 75, 75, -1); // LCNSanchez1
	vehicle_lcnExterior[16] = AddStaticVehicleEx(468, 1120.6490, -1243.2313, 15.7329, 89.4255, 75, 75, -1); // LCNSanchez2

    // Objects
    object_lcnExterior[0] = CreateDynamicObject(19121, 1083.127685, -1249.881225, 15.387152, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[1] = CreateDynamicObject(19121, 1085.797607, -1252.912353, 15.387152, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[2] = CreateDynamicObject(19121, 1082.892333, -1228.695556, 15.230315, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[3] = CreateDynamicObject(19121, 1082.892333, -1224.614990, 15.230315, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[4] = CreateDynamicObject(18652, 1081.926269, -1225.705200, 18.400325, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[5] = CreateDynamicObject(18652, 1081.926269, -1227.575439, 18.400325, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[6] = CreateDynamicObject(1361, 1083.116455, -1223.411621, 15.550312, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[7] = CreateDynamicObject(1361, 1083.116455, -1229.651977, 15.550312, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[8] = CreateDynamicObject(3017, 1090.112426, -1222.863403, 16.190317, 0.000000, 0.000000, -2.100007, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[9] = CreateDynamicObject(3017, 1090.083862, -1223.643066, 16.190317, 0.000000, 0.000000, -2.100007, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[10] = CreateDynamicObject(3928, 1088.369384, -1198.745727, 17.074693, 0.000000, 0.000000, -90.800018, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[11] = CreateDynamicObject(3928, 1109.577636, -1199.041381, 17.074693, 0.000000, 0.000000, -90.800018, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[12] = CreateDynamicObject(19121, 1121.587402, -1250.174316, 15.522873, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[13] = CreateDynamicObject(19121, 1121.587402, -1241.753417, 15.522873, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[14] = CreateDynamicObject(3461, 1083.020141, -1229.005371, 16.370313, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[15] = CreateDynamicObject(3461, 1083.020141, -1224.214721, 16.370313, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[16] = CreateDynamicObject(3014, 1114.425415, -1252.388427, 15.035564, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[17] = CreateDynamicObject(1271, 1113.868896, -1253.041381, 15.170311, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[18] = CreateDynamicObject(1271, 1114.568847, -1253.041381, 15.170311, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[19] = CreateDynamicObject(3014, 1113.885131, -1252.388427, 15.035564, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[20] = CreateDynamicObject(1575, 1114.579467, -1253.153808, 15.470314, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[21] = CreateDynamicObject(1575, 1113.769042, -1253.153808, 15.470314, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[22] = CreateDynamicObject(1575, 1090.121704, -1223.365844, 16.030315, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[23] = CreateDynamicObject(356, 1085.467773, -1222.699829, 16.150312, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[24] = CreateDynamicObject(356, 1086.817504, -1222.699829, 16.150312, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[25] = CreateDynamicObject(3383, 1083.725830, -1185.659423, 17.312070, 0.000000, 0.000000, -92.399993, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[26] = CreateDynamicObject(970, 1140.890991, -1203.531616, 18.699331, 0.000000, 0.000000, -86.500015, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[27] = CreateDynamicObject(19121, 1141.023803, -1205.828613, 18.606925, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[28] = CreateDynamicObject(2319, 1083.142089, -1219.064208, 16.804687, 0.000000, 0.000000, -91.400009, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[29] = CreateDynamicObject(355, 1082.777099, -1219.574340, 17.422010, 0.000000, 0.000000, 92.999992, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[30] = CreateDynamicObject(355, 1082.750854, -1220.625610, 17.422010, 0.000000, 0.000000, 93.899978, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[31] = CreateDynamicObject(351, 1083.192993, -1219.404418, 17.321632, 85.499984, -5.799996, -84.199981, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_lcnExterior[32] = CreateDynamicObject(19173, 1082.729125, -1219.829589, 19.062023, 0.000000, 0.000000, 88.000030, VW_MAIN, MAPS_LCNEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}