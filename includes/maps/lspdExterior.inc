#include <YSI\y_hooks>

// Global interior define
#define MAPS_LSPDEXTERIOR_INTERIOR      0
#define MAPS_LSPDINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// LSPD points
#define LSPD_INTERIOR_ENTER_COORDS		        960.5489, -1598.3197, 13.6220
#define LSPD_INTERIOR_EXIT_COORDS		        1619.5063, -1377.3353, 1962.5280
#define LSPD_INTERIOR_ENTER_FACING		        0.0000
#define LSPD_INTERIOR_EXIT_FACING               270.0000
#define LSPD_STATEREPAIR_COORDS			        1027.2825, -1616.0955, 5.9308
#define LSPD_ARREST_COORDS                      1027.3700, -1672.3691, 5.9308
#define LSPD_HELI_STAIRS_POINT                  949.6291, -1606.3474, 22.5215
#define LSPD_HELI_STAIRS_POINT_FACING           90.0000
#define LSPD_INTERIOR_HELI_STAIRS_POINT         1626.2921, -1369.3011, 1962.5068
#define LSPD_INTERIOR_HELI_STAIRS_POINT_FACING  180.0000
#define LSPD_GATE_FOR_RANGE_COORDS	            999.0969, -1602.5316, 8.4957
#define LSPD_GATE_OPEN_Z                        9.7009
#define LSPD_GATE_CLOSED_Z                      4.5309

#define LSPD_INTERIOR_GARAGE_POINT              1642.4449, -1388.1652, 1962.5164
#define LSPD_INTERIOR_GARAGE_POINT_FACING       0.0000
#define LSPD_GARAGE_POINT                       1040.0753, -1632.6056, 5.9308
#define LSPD_GARAGE_POINT_FACING                270.0000

// Map variables
new object_lspdExterior[303];
new pickup_lspdExterior[5];
new text3D_lspdExterior[2];
new actor_lspdExterior[2];
new vehicle_lspdExterior[35]; // using vehicle_lspdExterior for the alcatraz vehicles
new object_lspdExterior_gate;


CMD:pdgate(playerid, params[]) {
    if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 9 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Staatsbeamter.");

    if (IsPlayerInRangeOfPoint(playerid, 20.0, LSPD_GATE_FOR_RANGE_COORDS)) {
        new Float:fX, Float:fY, Float:fZ;
        GetDynamicObjectPos(object_lspdExterior_gate, fX, fY, fZ);
        
        if (fZ == LSPD_GATE_OPEN_Z)
            MoveDynamicObject(object_lspdExterior_gate, fX, fY, LSPD_GATE_CLOSED_Z, 3.25);
        else
            MoveDynamicObject(object_lspdExterior_gate, fX, fY, LSPD_GATE_OPEN_Z, 3.25);

        return 1;
    }
    
    return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Tores.");
}

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 759, 930.8439, -1615.9799, 12.2734, 0.10); // sm_bush_large_1
    RemoveBuildingForPlayer(playerid, 634, 930.8750, -1616.7199, 11.9218, 0.10); // veg_palmkbb11
    RemoveBuildingForPlayer(playerid, 759, 940.6640, -1616.1999, 12.3671, 0.10); // sm_bush_large_1
    RemoveBuildingForPlayer(playerid, 6047, 952.7109, -1599.5400, 20.7108, 0.10); // wilshire1_law
    RemoveBuildingForPlayer(playerid, 6072, 952.7109, -1599.5400, 20.7108, 0.10); // LOD Model of wilshire1_law
    RemoveBuildingForPlayer(playerid, 6043, 955.1480, -1612.2500, 20.1718, 0.10); // wilshire1w_law
    RemoveBuildingForPlayer(playerid, 6036, 1003.8900, -1598.0400, 17.8437, 0.10); // filler01_laW
    RemoveBuildingForPlayer(playerid, 6073, 1003.8900, -1598.0400, 17.8437, 0.10); // LOD Model of filler01_laW
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, LSPD_INTERIOR_ENTER_COORDS)) { // Entrance
			SetPlayerFacingAngle(playerid, LSPD_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, LSPD_INTERIOR_EXIT_COORDS + 0.5, MAPS_LSPDINTERIOR_INTERIOR, VW_LSPDINTERIOR);
			return 1;
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, LSPD_HELI_STAIRS_POINT)) { // Helicopter Stairway
            // -- Not needed to check if the user is a part of the executive
			SetPlayerFacingAngle(playerid, LSPD_INTERIOR_HELI_STAIRS_POINT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, LSPD_INTERIOR_HELI_STAIRS_POINT + 0.5, MAPS_LSPDINTERIOR_INTERIOR, VW_LSPDINTERIOR);
			return 1;
        } else if (IsPlayerInRangeOfPoint(playerid, 2.0, LSPD_GARAGE_POINT)) { // Garage point
            // -- Not needed to check if the user is a part of the executive
            SetPlayerFacingAngle(playerid, LSPD_INTERIOR_GARAGE_POINT_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, LSPD_INTERIOR_GARAGE_POINT + 0.5, MAPS_LSPDINTERIOR_INTERIOR, VW_LSPDINTERIOR);
            return 1;
        }
	}

	return 1;
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(LSPD_INTERIOR_ENTER_COORDS, 30, 0, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR);

	// Pickups
	pickup_lspdExterior[0] = CreateDynamicPickup(19197, 1, LSPD_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Entrance
    pickup_lspdExterior[1] = CreateDynamicPickup(1239, 1, LSPD_STATEREPAIR_COORDS, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Staterepair
    pickup_lspdExterior[2] = CreateDynamicPickup(1247, 1, LSPD_ARREST_COORDS, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Arrest
    pickup_lspdExterior[3] = CreateDynamicPickup(19197, 1, LSPD_HELI_STAIRS_POINT, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Helicopter Stairway
    pickup_lspdExterior[4] = CreateDynamicPickup(19197, 1, LSPD_GARAGE_POINT, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Garage Point

    // 3DTextLabels
    text3D_lspdExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, LSPD_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LSPDEXTERIOR_INTERIOR); // Staterepair
    text3D_lspdExterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Einsperrpunkt\n" COLOR_HEX_WHITE "Tippe /Arrest", COLOR_WHITE, LSPD_ARREST_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LSPDEXTERIOR_INTERIOR); // /arrest
    // Actors
    actor_lspdExterior[0] = CreateDynamicActor(50, 1031.0018, -1619.6342, 6.2667, -0.1000); //Mechanic
    ApplyDynamicActorAnimation(actor_lspdExterior[0], "BD_FIRE", "M_SMKLEAN_LOOP", 4.0999, 1, 0, 0, 0, 0);
    actor_lspdExterior[1] = CreateDynamicActor(307, 997.8622, -1607.8023, 7.8608, -82.3001); //San Fierro Police Of
    ApplyDynamicActorAnimation(actor_lspdExterior[1], "ON_LOOKERS", "WAVE_LOOP", 4.0999, 1, 0, 0, 0, 0);

	// Vehicles
    vehicle_lspdExterior[0] = AddStaticVehicleEx(596, 1041.4632, -1598.8326, 5.6530, 178.9314, 0, 1, -1); //Police Car (LSPD)
    vehicle_lspdExterior[1] = AddStaticVehicleEx(596, 1045.5600, -1598.8183, 5.6530, 178.7480, 0, 1, -1); //Police Car (LSPD)
    vehicle_lspdExterior[2] = AddStaticVehicleEx(596, 1037.4035, -1598.8984, 5.6530, 180.0000, 0, 1, -1); //Police Car (LSPD)
    vehicle_lspdExterior[3] = AddStaticVehicleEx(596, 1025.1334, -1599.0087, 5.6126, 179.2696, 0, 1, -1); //Police Car (LSPD)
    vehicle_lspdExterior[4] = AddStaticVehicleEx(596, 1033.3349, -1598.9114, 5.6126, 181.1799, 0, 1, -1); //Police Car (LSPD)
    vehicle_lspdExterior[5] = AddStaticVehicleEx(596, 1049.5992, -1598.8242, 5.6117, 180.1795, 0, 1, -1); //Police Car (LSPD)
    vehicle_lspdExterior[6] = AddStaticVehicleEx(596, 1029.2883, -1598.9927, 5.6339, 179.7215, 0, 1, -1); //Police Car (LSPD)
    vehicle_lspdExterior[7] = AddStaticVehicleEx(596, 1053.8437, -1598.7366, 5.6339, 178.9711, 0, 1, -1); //Police Car (LSPD)
    vehicle_lspdExterior[8] = AddStaticVehicleEx(599, 1061.1827, -1613.8105, 6.1064, 91.1303, 0, 1, -1); //Police Ranger
    vehicle_lspdExterior[9] = AddStaticVehicleEx(560, 1061.6958, -1626.2728, 5.6048, 90.1818, 0, 0, -1); //Sultan
    vehicle_lspdExterior[10] = AddStaticVehicleEx(599, 1061.1654, -1610.0373, 6.0166, 90.2578, 0, 1, -1); //Police Ranger
    vehicle_lspdExterior[11] = AddStaticVehicleEx(599, 1061.3525, -1605.8996, 5.9965, 89.8180, 0, 1, -1); //Police Ranger
    vehicle_lspdExterior[12] = AddStaticVehicleEx(523, 1045.2065, -1642.9703, 5.5082, 339.2755, 0, 0, -1); //HPV1000
    vehicle_lspdExterior[13] = AddStaticVehicleEx(523, 1043.1491, -1643.0185, 5.5078, 341.5162, 0, 0, -1); //HPV1000
    vehicle_lspdExterior[14] = AddStaticVehicleEx(523, 1041.5400, -1643.0275, 5.5954, 334.8616, 0, 0, -1); //HPV1000
    vehicle_lspdExterior[15] = AddStaticVehicleEx(523, 1047.1789, -1642.9948, 5.5029, 339.2992, 0, 0, -1); //HPV1000
    vehicle_lspdExterior[16] = AddStaticVehicleEx(541, 1061.6998, -1622.1527, 5.5557, 90.5394, 0, 1, -1); //Bullet
    vehicle_lspdExterior[17] = AddStaticVehicleEx(601, 1061.6773, -1642.6955, 5.6896, 90.3759, 0, 0, -1); //S.W.A.T. Van
    vehicle_lspdExterior[18] = AddStaticVehicleEx(541, 1061.8089, -1618.0526, 5.5556, 90.0226, 0, 1, -1); //Bullet
    vehicle_lspdExterior[19] = AddStaticVehicleEx(560, 1061.7751, -1630.3138, 5.5949, 89.3181, 0, 0, -1); //Sultan
    vehicle_lspdExterior[20] = AddStaticVehicleEx(426, 1061.3447, -1634.5394, 5.6747, 90.2958, 0, 0, -1); //Premier
    vehicle_lspdExterior[21] = AddStaticVehicleEx(445, 1061.4068, -1638.5823, 5.8058, 89.7346, 0, 0, -1); //Admiral
    vehicle_lspdExterior[22] = AddStaticVehicleEx(497, 958.3012, -1604.9287, 27.1474, 0.1081, 1, 0, -1); //Police Maverick
    vehicle_lspdExterior[23] = AddStaticVehicleEx(497, 970.6135, -1605.6573, 27.1574, 359.7147, 1, 0, -1); //Police Maverick
    vehicle_lspdExterior[24] = AddStaticVehicleEx(427, 1037.7852, -1671.9428, 6.0644, 0.2669, 0, 1, -1); //Enforcer
    vehicle_lspdExterior[25] = AddStaticVehicleEx(427, 1033.7615, -1672.3277, 6.0636, 359.8333, 0, 1, -1); //Enforcer
    vehicle_lspdExterior[26] = AddStaticVehicleEx(430, 961.4000, -2050.2000, 0.0000, 0.0000, 0, 1, -1); // LSPD boat

	// Objects
	object_lspdExterior[0] = CreateDynamicObject(10051, 1055.5577, -1632.4438, 5.0949, 0.0000, 0.0000, 0.1000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //carimp_SFE
    object_lspdExterior[1] = CreateDynamicObject(8661, 1017.6079, -1602.0249, 12.5396, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_lspdExterior[1], 0, 4829, "airport_las", "Grass_128HV", 0xFFFFFFFF);
    object_lspdExterior[2] = CreateDynamicObject(19363, 1002.4769, -1606.2613, 16.7859, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall011
    SetDynamicObjectMaterial(object_lspdExterior[2], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
    object_lspdExterior[3] = CreateDynamicObject(18981, 966.6613, -1594.7561, 12.1197, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[3], 0, 4829, "airport_las", "Grass_128HV", 0x00000000);
    object_lspdExterior[4] = CreateDynamicObject(19464, 953.6362, -1599.9095, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[4], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[5] = CreateDynamicObject(19464, 965.4862, -1599.9598, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[5], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[6] = CreateDynamicObject(19464, 971.3964, -1599.9498, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[6], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[7] = CreateDynamicObject(19464, 959.5562, -1599.9398, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[7], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[8] = CreateDynamicObject(19464, 975.1973, -1599.9394, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[8], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[9] = CreateDynamicObject(19377, 955.4810, -1599.8619, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[9], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[10] = CreateDynamicObject(19377, 963.7324, -1599.8918, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[10], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[11] = CreateDynamicObject(19377, 973.3032, -1599.9018, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[11], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[12] = CreateDynamicObject(19464, 978.0374, -1602.7873, 15.1042, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[12], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[13] = CreateDynamicObject(19464, 978.0274, -1607.4095, 15.1042, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[13], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[14] = CreateDynamicObject(19377, 978.0640, -1604.6534, 20.7157, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[14], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[15] = CreateDynamicObject(19377, 978.0540, -1605.5340, 20.7157, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[15], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[16] = CreateDynamicObject(1522, 960.5474, -1599.8105, 12.4568, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_lspdExterior[16], 0, 12855, "cunte_cop", "sw_copdoor1", 0xFFFFFFFF);
    object_lspdExterior[17] = CreateDynamicObject(18981, 952.3911, -1594.7392, 12.1176, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[17], 0, 4829, "airport_las", "Grass_128HV", 0x00000000);
    object_lspdExterior[18] = CreateDynamicObject(19464, 960.4467, -1599.6297, 16.4144, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[18], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[19] = CreateDynamicObject(19464, 960.4268, -1599.6595, 16.3644, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[19], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[20] = CreateDynamicObject(1522, 959.0474, -1599.8105, 12.4568, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_lspdExterior[20], 0, 12855, "cunte_cop", "sw_copdoor1", 0xFFFFFFFF);
    object_lspdExterior[21] = CreateDynamicObject(19450, 960.5629, -1599.8413, 10.4483, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_lspdExterior[21], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[22] = CreateDynamicObject(19445, 960.5274, -1603.8448, 12.5275, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[22], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[23] = CreateDynamicObject(19461, 953.9624, -1582.3194, 11.3781, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[23], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[24] = CreateDynamicObject(19377, 988.4738, -1613.8105, 16.7856, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[24], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_lspdExterior[25] = CreateDynamicObject(19464, 960.4066, -1599.6297, 16.4144, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[25], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[26] = CreateDynamicObject(19565, 957.6693, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[26], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[27] = CreateDynamicObject(19565, 958.1389, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[27], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[28] = CreateDynamicObject(19565, 958.6093, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[28], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[29] = CreateDynamicObject(19565, 963.1701, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[29], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[30] = CreateDynamicObject(19565, 962.7000, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[30], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[31] = CreateDynamicObject(19565, 962.2302, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[31], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[32] = CreateDynamicObject(19565, 963.3806, -1597.3144, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[32], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[33] = CreateDynamicObject(19565, 957.4611, -1597.3144, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[33], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[34] = CreateDynamicObject(19565, 963.3806, -1597.7845, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[34], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[35] = CreateDynamicObject(19565, 963.3806, -1598.2451, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[35], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[36] = CreateDynamicObject(19565, 963.3806, -1598.7154, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[36], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[37] = CreateDynamicObject(19565, 963.3806, -1599.1760, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[37], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[38] = CreateDynamicObject(19565, 963.3806, -1599.6462, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[38], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[39] = CreateDynamicObject(19565, 957.4611, -1599.6462, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[39], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[40] = CreateDynamicObject(19565, 957.4611, -1599.1761, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[40], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[41] = CreateDynamicObject(19466, 963.6514, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[41], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[42] = CreateDynamicObject(19565, 957.4611, -1598.7054, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[42], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[43] = CreateDynamicObject(19565, 957.4611, -1598.2452, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[43], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[44] = CreateDynamicObject(19565, 957.4611, -1597.7750, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[44], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[45] = CreateDynamicObject(19461, 934.8098, -1582.3204, 11.0937, -3.3998, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[45], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[46] = CreateDynamicObject(19445, 960.0789, -1587.6848, 12.5345, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[46], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[47] = CreateDynamicObject(19175, 959.9796, -1597.0742, 15.7966, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[47], 0, "Eingang - Polizei", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lspdExterior[47], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[48] = CreateDynamicObject(19425, 983.0443, -1582.2580, 12.4341, 18.1000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_lspdExterior[49] = CreateDynamicObject(19445, 960.5274, -1587.0532, 12.5361, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[49], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[50] = CreateDynamicObject(19466, 959.5402, -1599.7425, 24.6791, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[50], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[51] = CreateDynamicObject(1232, 962.0841, -1582.5045, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[52] = CreateDynamicObject(1232, 958.9036, -1582.5045, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[53] = CreateDynamicObject(19461, 932.1981, -1620.1212, 11.1574, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[53], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[54] = CreateDynamicObject(19466, 955.3311, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[54], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[55] = CreateDynamicObject(19466, 955.3911, -1599.7624, 24.6492, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[55], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[56] = CreateDynamicObject(19466, 966.7418, -1599.7624, 24.6492, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[56], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[57] = CreateDynamicObject(19466, 952.3010, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[57], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[58] = CreateDynamicObject(19466, 963.7216, -1599.7624, 24.6492, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[58], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[59] = CreateDynamicObject(19466, 952.3010, -1599.7624, 24.6492, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[59], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[60] = CreateDynamicObject(19466, 959.5402, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[60], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[61] = CreateDynamicObject(19461, 953.8413, -1589.4908, 11.1688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[61], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[62] = CreateDynamicObject(19461, 944.6812, -1589.5107, 11.1686, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[62], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[63] = CreateDynamicObject(19461, 958.7412, -1594.2313, 11.1786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[63], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[64] = CreateDynamicObject(18981, 939.8906, -1594.8204, 12.1070, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[64], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_lspdExterior[65] = CreateDynamicObject(19445, 953.9588, -1587.6848, 12.5375, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[65], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[66] = CreateDynamicObject(19461, 962.3516, -1594.2313, 11.1786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[66], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[67] = CreateDynamicObject(19461, 944.3314, -1582.3204, 11.3772, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[67], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[68] = CreateDynamicObject(19377, 998.9749, -1612.5904, 16.7856, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[68], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_lspdExterior[69] = CreateDynamicObject(19461, 932.1906, -1582.3214, 10.8669, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[69], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[70] = CreateDynamicObject(19425, 986.3480, -1582.2580, 12.4341, 18.1000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_lspdExterior[71] = CreateDynamicObject(19425, 989.6519, -1582.2580, 12.4341, 18.1000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_lspdExterior[72] = CreateDynamicObject(19377, 1008.9710, -1600.6302, 14.6211, 0.0000, 114.4000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[72], 0, 4829, "airport_las", "Grass_128HV", 0xFFFFFFFF);
    object_lspdExterior[73] = CreateDynamicObject(8615, 949.7387, -1605.6832, 24.2394, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsSstairs04_lvs
    object_lspdExterior[74] = CreateDynamicObject(19377, 963.9799, -1610.2723, 10.2156, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[74], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[75] = CreateDynamicObject(19466, 954.1113, -1610.3840, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[75], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[76] = CreateDynamicObject(19466, 957.3007, -1610.3840, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[76], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[77] = CreateDynamicObject(19466, 960.5512, -1610.3840, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[77], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[78] = CreateDynamicObject(19466, 963.8615, -1610.3540, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[78], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[79] = CreateDynamicObject(19466, 967.0119, -1610.3540, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[79], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[80] = CreateDynamicObject(19466, 969.8720, -1610.3540, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[80], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[81] = CreateDynamicObject(19466, 972.7921, -1610.3540, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[81], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[82] = CreateDynamicObject(19466, 975.7224, -1610.3708, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[82], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[83] = CreateDynamicObject(19466, 975.7219, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[83], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[84] = CreateDynamicObject(19466, 972.7119, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[84], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[85] = CreateDynamicObject(19466, 969.8413, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[85], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[86] = CreateDynamicObject(19466, 963.8305, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[86], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[87] = CreateDynamicObject(19466, 957.3015, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[87], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[88] = CreateDynamicObject(19466, 960.5512, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[88], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[89] = CreateDynamicObject(19466, 954.1409, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[89], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[90] = CreateDynamicObject(19466, 966.9812, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[90], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[91] = CreateDynamicObject(19377, 973.3032, -1610.2502, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[91], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[92] = CreateDynamicObject(19377, 963.7324, -1610.2524, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[92], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[93] = CreateDynamicObject(19377, 955.4810, -1610.2733, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[93], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[94] = CreateDynamicObject(19377, 955.4810, -1610.2733, 10.2156, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[94], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[95] = CreateDynamicObject(19377, 965.1303, -1610.2733, 10.2156, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[95], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[96] = CreateDynamicObject(19377, 973.1895, -1610.2331, 10.2156, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[96], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[97] = CreateDynamicObject(19466, 978.1710, -1605.0544, 24.6291, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[97], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[98] = CreateDynamicObject(19466, 978.1710, -1608.3652, 24.6291, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[98], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[99] = CreateDynamicObject(19466, 978.1710, -1601.7237, 24.6191, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[99], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[100] = CreateDynamicObject(19466, 978.1710, -1601.7237, 21.4892, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[100], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[101] = CreateDynamicObject(19466, 978.1710, -1608.3652, 21.4792, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[101], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[102] = CreateDynamicObject(19466, 978.1710, -1605.0544, 21.4792, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[102], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[103] = CreateDynamicObject(19466, 978.1710, -1605.0439, 18.8491, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[103], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[104] = CreateDynamicObject(19466, 978.1710, -1601.7137, 18.8491, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[104], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[105] = CreateDynamicObject(19466, 978.1710, -1608.3238, 18.8491, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[105], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[106] = CreateDynamicObject(19175, 960.6892, -1599.7746, 22.0265, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[106], 0, "S", OBJECT_MATERIAL_SIZE_256x128, "Arial", 155, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lspdExterior[106], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[107] = CreateDynamicObject(19175, 964.0999, -1599.7746, 22.0265, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[107], 0, "L", OBJECT_MATERIAL_SIZE_256x128, "Arial", 155, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lspdExterior[107], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[108] = CreateDynamicObject(19377, 950.7105, -1604.5799, 20.7056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[108], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[109] = CreateDynamicObject(19175, 956.7786, -1599.7746, 22.0265, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[109], 0, "P", OBJECT_MATERIAL_SIZE_256x128, "Arial", 155, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lspdExterior[109], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[110] = CreateDynamicObject(19175, 953.0479, -1599.7746, 22.0265, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[110], 0, "D", OBJECT_MATERIAL_SIZE_256x128, "Arial", 155, 1, 0xFFFFFFFF, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lspdExterior[110], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[111] = CreateDynamicObject(19377, 950.7080, -1605.5406, 20.7056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[111], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[112] = CreateDynamicObject(19461, 962.3516, -1603.8614, 11.1786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[112], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[113] = CreateDynamicObject(19461, 958.7421, -1603.8614, 11.1786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[113], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[114] = CreateDynamicObject(19466, 975.7219, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[114], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[115] = CreateDynamicObject(19466, 972.7512, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[115], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[116] = CreateDynamicObject(19466, 969.8311, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[116], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[117] = CreateDynamicObject(19466, 966.9312, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[117], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[118] = CreateDynamicObject(19466, 963.8107, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[118], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[119] = CreateDynamicObject(19466, 960.5402, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[119], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[120] = CreateDynamicObject(19466, 957.3103, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[120], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[121] = CreateDynamicObject(19466, 954.1300, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[121], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[122] = CreateDynamicObject(19466, 952.3397, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[122], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[123] = CreateDynamicObject(19466, 955.3098, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[123], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[124] = CreateDynamicObject(19466, 966.7307, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[124], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[125] = CreateDynamicObject(19466, 972.7221, -1599.7425, 21.4491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[125], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[126] = CreateDynamicObject(19461, 939.8405, -1594.4215, 11.1385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[126], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[127] = CreateDynamicObject(19461, 939.8203, -1615.2629, 11.1583, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[127], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[128] = CreateDynamicObject(19461, 939.8308, -1604.0318, 11.1385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[128], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[129] = CreateDynamicObject(19461, 938.5524, -1589.5129, 11.1597, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[129], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[130] = CreateDynamicObject(19445, 944.5739, -1587.6848, 12.5354, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[130], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[131] = CreateDynamicObject(19461, 967.2512, -1589.4908, 11.1688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[131], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[132] = CreateDynamicObject(1886, 962.9552, -1599.2646, 16.3071, 13.6000, 0.0000, -159.1999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_lspdExterior[133] = CreateDynamicObject(19371, 962.3643, -1584.1971, 11.1449, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_lspdExterior[133], 0, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
    object_lspdExterior[134] = CreateDynamicObject(1232, 980.9556, -1582.7153, 10.8760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[135] = CreateDynamicObject(19461, 939.8305, -1613.2821, 11.1485, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[135], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[136] = CreateDynamicObject(1232, 993.6948, -1582.7153, 10.8760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[137] = CreateDynamicObject(19461, 935.1005, -1620.1202, 11.1583, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[137], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[138] = CreateDynamicObject(18763, 1009.3237, -1590.9022, 14.0326, -48.2999, -90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete3mx3mx5m
    SetDynamicObjectMaterial(object_lspdExterior[138], 0, 1355, "break_s_bins", "marble1", 0x00000000);
    object_lspdExterior[139] = CreateDynamicObject(18981, 968.6925, -1607.7557, 12.1176, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[139], 0, 4829, "airport_las", "Grass_128HV", 0x00000000);
    object_lspdExterior[140] = CreateDynamicObject(1232, 995.9843, -1590.6850, 13.0261, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[141] = CreateDynamicObject(18981, 952.3021, -1607.7557, 12.1155, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[141], 0, 4829, "airport_las", "Grass_128HV", 0x00000000);
    object_lspdExterior[142] = CreateDynamicObject(19464, 939.6467, -1592.8292, 10.0612, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[142], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[143] = CreateDynamicObject(19464, 939.6467, -1598.7591, 10.0621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[143], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[144] = CreateDynamicObject(19464, 939.6467, -1604.6789, 10.0612, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[144], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[145] = CreateDynamicObject(19464, 939.6467, -1610.6097, 10.0621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[145], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[146] = CreateDynamicObject(19464, 939.6467, -1616.5400, 10.0642, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[146], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[147] = CreateDynamicObject(19464, 939.6467, -1617.0705, 10.0621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[147], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[148] = CreateDynamicObject(19466, 969.7807, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[148], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[149] = CreateDynamicObject(19461, 945.5208, -1599.8204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[149], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[150] = CreateDynamicObject(19461, 949.0214, -1599.8204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[150], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[151] = CreateDynamicObject(19461, 942.0310, -1599.7701, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[151], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[152] = CreateDynamicObject(19461, 940.3208, -1601.5106, 16.6485, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[152], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[153] = CreateDynamicObject(19461, 943.8112, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[153], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[154] = CreateDynamicObject(19461, 949.0819, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[154], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[155] = CreateDynamicObject(19461, 942.0413, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[155], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[156] = CreateDynamicObject(1232, 984.4539, -1596.2358, 12.8760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[157] = CreateDynamicObject(19461, 947.2918, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[157], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[158] = CreateDynamicObject(19461, 945.5217, -1601.3907, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[158], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[159] = CreateDynamicObject(19377, 945.3720, -1605.5400, 21.4335, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[159], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[160] = CreateDynamicObject(19461, 940.3208, -1604.9698, 16.6485, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[160], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[161] = CreateDynamicObject(19461, 941.4849, -1600.9438, 16.6284, 90.0000, 90.0000, 135.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[161], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[162] = CreateDynamicObject(19461, 941.9520, -1601.3508, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[162], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[163] = CreateDynamicObject(19461, 941.9520, -1603.1308, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[163], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[164] = CreateDynamicObject(19461, 941.9520, -1604.8917, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[164], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[165] = CreateDynamicObject(19461, 941.9520, -1606.7314, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[165], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[166] = CreateDynamicObject(19466, 972.7011, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[166], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[167] = CreateDynamicObject(19466, 975.7019, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[167], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[168] = CreateDynamicObject(19461, 940.3208, -1608.5102, 16.6485, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[168], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[169] = CreateDynamicObject(19425, 1015.0584, -1601.1770, 4.8537, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_lspdExterior[170] = CreateDynamicObject(19461, 941.9520, -1608.5821, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[170], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[171] = CreateDynamicObject(19461, 942.0098, -1610.2204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[171], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[172] = CreateDynamicObject(19461, 945.4608, -1610.2204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[172], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[173] = CreateDynamicObject(19461, 948.8916, -1610.2204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[173], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[174] = CreateDynamicObject(19461, 950.5717, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[174], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[175] = CreateDynamicObject(19461, 948.6818, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[175], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[176] = CreateDynamicObject(19461, 946.6820, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[176], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[177] = CreateDynamicObject(19461, 944.8311, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[177], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[178] = CreateDynamicObject(19461, 943.2008, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[178], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[179] = CreateDynamicObject(19461, 941.5905, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[179], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[180] = CreateDynamicObject(19461, 941.4677, -1609.0633, 16.6284, 90.0000, 90.0000, 45.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[180], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[181] = CreateDynamicObject(19466, 972.7921, -1599.7624, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[181], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[182] = CreateDynamicObject(19466, 969.7412, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[182], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[183] = CreateDynamicObject(19466, 972.6914, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[183], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[184] = CreateDynamicObject(19466, 969.7412, -1599.7425, 21.4491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[184], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[185] = CreateDynamicObject(19466, 975.6823, -1599.7425, 21.4491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[185], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[186] = CreateDynamicObject(19466, 975.6713, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[186], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[187] = CreateDynamicObject(19466, 969.7520, -1599.7624, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[187], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[188] = CreateDynamicObject(19466, 975.7224, -1599.7624, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[188], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[189] = CreateDynamicObject(2911, 950.6364, -1606.4150, 21.4692, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_petroldoor
    SetDynamicObjectMaterial(object_lspdExterior[189], 0, 18241, "cw_tempstuffcs_t", "des_metaldoor1", 0xFFFFFFFF);
    object_lspdExterior[190] = CreateDynamicObject(2911, 950.6364, -1606.3857, 21.4692, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_petroldoor
    SetDynamicObjectMaterial(object_lspdExterior[190], 0, 18241, "cw_tempstuffcs_t", "des_metaldoor1", 0xFFFFFFFF);
    object_lspdExterior[191] = CreateDynamicObject(19175, 950.6292, -1606.9256, 23.1867, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[191], 0, "Eingang - Dach", OBJECT_MATERIAL_SIZE_256x128, "Arial", 25, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lspdExterior[191], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[192] = CreateDynamicObject(963, 939.6231, -1584.2972, 13.6316, 90.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_T_TICKET
    object_lspdExterior[193] = CreateDynamicObject(7010, 990.8521, -1591.0704, 14.0499, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgnpolicecpark
    object_lspdExterior[194] = CreateDynamicObject(19464, 939.6467, -1592.5688, 10.0621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[194], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[195] = CreateDynamicObject(19464, 936.7869, -1620.0511, 10.0628, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[195], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[196] = CreateDynamicObject(19464, 936.7869, -1616.4807, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[196], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[197] = CreateDynamicObject(19464, 936.7869, -1612.6606, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[197], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[198] = CreateDynamicObject(19464, 936.7869, -1608.7496, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[198], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[199] = CreateDynamicObject(19464, 936.7869, -1604.7076, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[199], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[200] = CreateDynamicObject(19464, 936.7869, -1600.7464, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[200], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[201] = CreateDynamicObject(19464, 936.7869, -1596.8664, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[201], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[202] = CreateDynamicObject(19464, 936.7869, -1593.1549, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[202], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[203] = CreateDynamicObject(19464, 936.7869, -1589.6435, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[203], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[204] = CreateDynamicObject(3934, 970.6865, -1604.9554, 26.0158, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_lspdExterior[205] = CreateDynamicObject(19426, 933.8853, -1608.7320, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[205], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[206] = CreateDynamicObject(19426, 933.8853, -1612.6330, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[206], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[207] = CreateDynamicObject(19426, 933.8853, -1616.4936, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[207], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[208] = CreateDynamicObject(19426, 933.8853, -1604.6533, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[208], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[209] = CreateDynamicObject(19426, 933.8853, -1600.7126, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[209], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[210] = CreateDynamicObject(19426, 933.8853, -1596.8618, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[210], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[211] = CreateDynamicObject(19426, 933.8853, -1593.1610, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[211], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[212] = CreateDynamicObject(19461, 950.7930, -1601.4200, 16.7091, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[212], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[213] = CreateDynamicObject(19377, 965.0595, -1604.9707, 25.9158, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[213], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[214] = CreateDynamicObject(19377, 973.3087, -1604.9707, 25.9358, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[214], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[215] = CreateDynamicObject(19377, 973.3087, -1605.1003, 25.9258, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[215], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[216] = CreateDynamicObject(19377, 963.7293, -1605.1003, 25.9258, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[216], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[217] = CreateDynamicObject(19377, 955.4387, -1605.1003, 25.9158, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[217], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[218] = CreateDynamicObject(19466, 966.7210, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[218], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[219] = CreateDynamicObject(18981, 939.8906, -1607.6700, 12.1090, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[219], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_lspdExterior[220] = CreateDynamicObject(18981, 939.8906, -1607.6700, 12.1070, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[220], 0, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[221] = CreateDynamicObject(18981, 939.8906, -1607.6700, 12.1070, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[221], 0, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[222] = CreateDynamicObject(1232, 1001.8546, -1596.6953, 15.7159, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[223] = CreateDynamicObject(19377, 945.3720, -1604.4598, 21.4356, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[223], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[224] = CreateDynamicObject(1232, 995.4345, -1607.7756, 15.7959, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[225] = CreateDynamicObject(19461, 950.6137, -1601.4200, 16.7091, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[225], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[226] = CreateDynamicObject(18764, 981.4237, -1616.4034, 15.0438, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete5mx5mx5m
    SetDynamicObjectMaterial(object_lspdExterior[226], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_lspdExterior[227] = CreateDynamicObject(19425, 992.9558, -1582.2580, 12.4341, 18.1000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_lspdExterior[228] = CreateDynamicObject(2921, 996.6176, -1606.9001, 14.8989, 0.0000, 0.0000, -33.2999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_cam
    object_lspdExterior[229] = CreateDynamicObject(18764, 981.4227, -1616.4023, 15.6639, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete5mx5mx5m
    SetDynamicObjectMaterial(object_lspdExterior[229], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_lspdExterior[230] = CreateDynamicObject(18764, 986.4221, -1616.4023, 16.3640, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete5mx5mx5m
    SetDynamicObjectMaterial(object_lspdExterior[230], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_lspdExterior[231] = CreateDynamicObject(18764, 991.4215, -1616.4023, 16.3640, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete5mx5mx5m
    SetDynamicObjectMaterial(object_lspdExterior[231], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_lspdExterior[232] = CreateDynamicObject(18980, 1006.5388, -1582.5058, 12.0972, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_lspdExterior[232], 0, 4829, "airport_las", "Grass_128HV", 0x00000000);
    object_lspdExterior[233] = CreateDynamicObject(18980, 1011.4196, -1582.5035, 12.0963, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_lspdExterior[233], 0, 4829, "airport_las", "Grass_128HV", 0x00000000);
    object_lspdExterior[234] = CreateDynamicObject(19377, 1008.9710, -1608.9814, 14.6232, 0.0000, 114.4000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[234], 0, 4829, "airport_las", "Grass_128HV", 0xFFFFFFFF);
    object_lspdExterior[235] = CreateDynamicObject(19174, 1008.6245, -1589.7579, 14.9932, 41.7000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterial(object_lspdExterior[235], 0, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterialText(object_lspdExterior[235], 1, "LSPD", OBJECT_MATERIAL_SIZE_256x128, "Times New Roman", 114, 1, 0xFF000000, 0x00000000, 0);
    object_lspdExterior[236] = CreateDynamicObject(19445, 960.5274, -1596.6877, 12.5361, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[236], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[237] = CreateDynamicObject(1232, 1006.5648, -1588.5250, 11.5761, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[238] = CreateDynamicObject(1232, 1012.1051, -1588.5250, 11.5158, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[239] = CreateDynamicObject(19174, 1010.1851, -1589.9298, 15.1871, 41.7000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture3
    SetDynamicObjectMaterial(object_lspdExterior[239], 0, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterialText(object_lspdExterior[239], 1, "p", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 150, 0, 0xFF000000, 0x00000000, 0);
    object_lspdExterior[240] = CreateDynamicObject(19445, 969.6984, -1587.6848, 12.5345, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[240], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[241] = CreateDynamicObject(19461, 967.0925, -1582.3194, 11.3781, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[241], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[242] = CreateDynamicObject(19445, 976.7683, -1587.6848, 12.5325, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[242], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[243] = CreateDynamicObject(19461, 967.0925, -1582.3194, 11.3781, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[243], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[244] = CreateDynamicObject(19461, 974.3300, -1582.3183, 11.3788, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[244], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[245] = CreateDynamicObject(19425, 1015.0584, -1604.4775, 4.8537, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_lspdExterior[246] = CreateDynamicObject(869, 942.9190, -1584.0670, 13.0403, 0.0000, 0.0000, -4.1999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[247] = CreateDynamicObject(19425, 1015.0584, -1607.7779, 4.8537, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_lspdExterior[248] = CreateDynamicObject(19425, 1015.0584, -1609.6379, 4.8529, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //speed_bump01
    object_lspdExterior[249] = CreateDynamicObject(869, 975.5645, -1584.0814, 13.0403, 0.0000, 0.0000, -4.1999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[250] = CreateDynamicObject(869, 955.5645, -1584.0456, 13.0403, 0.0000, 0.0000, -4.1999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[251] = CreateDynamicObject(869, 965.8496, -1584.1046, 13.0403, 0.0000, 0.0000, -4.1999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[252] = CreateDynamicObject(19371, 939.8363, -1583.9770, 11.1469, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_lspdExterior[252], 0, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
    object_lspdExterior[253] = CreateDynamicObject(19371, 939.8342, -1584.3374, 11.1449, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_lspdExterior[253], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[254] = CreateDynamicObject(1280, 976.2883, -1592.1722, 12.9905, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_lspdExterior[255] = CreateDynamicObject(19461, 944.6812, -1585.8581, 11.1686, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[255], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[256] = CreateDynamicObject(19461, 953.9633, -1585.8563, 11.1666, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[256], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[257] = CreateDynamicObject(19371, 958.6862, -1583.9870, 11.1469, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_lspdExterior[257], 0, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
    object_lspdExterior[258] = CreateDynamicObject(19371, 958.6842, -1584.1971, 11.1449, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_lspdExterior[258], 0, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
    object_lspdExterior[259] = CreateDynamicObject(19461, 967.0828, -1585.8563, 11.1666, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[259], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[260] = CreateDynamicObject(19461, 975.3458, -1585.8581, 11.1646, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[260], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[261] = CreateDynamicObject(19371, 962.3624, -1584.0140, 11.1469, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_lspdExterior[261], 0, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
    object_lspdExterior[262] = CreateDynamicObject(19371, 977.5842, -1589.4941, 11.1766, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall019
    SetDynamicObjectMaterial(object_lspdExterior[262], 0, 7088, "casinoshops1", "fakestone1_LA", 0x00000000);
    object_lspdExterior[263] = CreateDynamicObject(19445, 974.0280, -1594.2247, 12.5354, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[263], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[264] = CreateDynamicObject(1280, 976.2883, -1596.1838, 12.9905, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_lspdExterior[265] = CreateDynamicObject(1280, 971.7567, -1596.1838, 12.9905, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_lspdExterior[266] = CreateDynamicObject(1280, 971.7567, -1592.1722, 12.9905, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_lspdExterior[267] = CreateDynamicObject(11706, 976.2883, -1594.1384, 12.5914, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
    object_lspdExterior[268] = CreateDynamicObject(11706, 971.7567, -1594.1384, 12.5914, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
    object_lspdExterior[269] = CreateDynamicObject(1215, 975.8698, -1589.5118, 12.5747, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_lspdExterior[270] = CreateDynamicObject(1215, 972.2000, -1589.5118, 12.5747, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_lspdExterior[271] = CreateDynamicObject(3934, 958.5465, -1604.9554, 26.0158, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_lspdExterior[272] = CreateDynamicObject(9019, 948.5780, -1606.4239, 14.3072, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //luxortrees01_lvS
    SetDynamicObjectMaterial(object_lspdExterior[272], 0, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(object_lspdExterior[272], 1, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(object_lspdExterior[272], 2, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[273] = CreateDynamicObject(1232, 1016.3353, -1596.6953, 15.6555, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[274] = CreateDynamicObject(19463, 1014.8955, -1597.8039, 7.3225, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall103
    object_lspdExterior[275] = CreateDynamicObject(717, 949.6547, -1594.5649, 10.3673, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_lspdExterior[276] = CreateDynamicObject(1232, 1024.1767, -1582.6240, 10.8156, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[277] = CreateDynamicObject(1232, 958.9036, -1589.7049, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[278] = CreateDynamicObject(1232, 962.0841, -1589.7049, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[279] = CreateDynamicObject(1232, 940.0136, -1589.2945, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[280] = CreateDynamicObject(1232, 940.0136, -1586.0627, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[281] = CreateDynamicObject(748, 947.6920, -1584.0439, 12.5186, 0.0000, 0.0000, 166.5000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[282] = CreateDynamicObject(748, 950.9431, -1584.0876, 12.5186, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[283] = CreateDynamicObject(19463, 1014.8955, -1613.0349, 7.3225, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall103
    object_lspdExterior[284] = CreateDynamicObject(748, 970.8333, -1584.0876, 12.5186, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[285] = CreateDynamicObject(9019, 969.8474, -1606.4239, 14.3072, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //luxortrees01_lvS
    SetDynamicObjectMaterial(object_lspdExterior[285], 0, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(object_lspdExterior[285], 1, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(object_lspdExterior[285], 2, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[286] = CreateDynamicObject(8623, 949.6049, -1594.4176, 13.1559, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
    object_lspdExterior[287] = CreateDynamicObject(870, 965.1870, -1595.0096, 12.8219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_lspdExterior[288] = CreateDynamicObject(870, 968.7871, -1593.7198, 12.8219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_lspdExterior[289] = CreateDynamicObject(870, 966.4873, -1592.4399, 12.8219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_lspdExterior[290] = CreateDynamicObject(870, 967.4865, -1596.1694, 12.8219, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers2wee
    object_lspdExterior[291] = CreateDynamicObject(1232, 1021.9647, -1590.6850, 12.6660, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[292] = CreateDynamicObject(19545, 932.9862, -1610.9681, 12.4977, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane62_5x15Conc1
    object_lspdExterior[294] = CreateDynamicObject(19538, 1036.4620, -1623.0290, 4.6652, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane62_5x125Conc1
    object_lspdExterior[295] = CreateDynamicObject(19538, 1036.7612, -1684.0567, 4.6652, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane62_5x125Conc1
    // object_lspdExterior[296] = CreateDynamicObject(18766, 958.7770, -1602.5750, 25.4237, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    // object_lspdExterior[297] = CreateDynamicObject(18766, 958.7770, -1607.6494, 25.4237, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    // object_lspdExterior[298] = CreateDynamicObject(18766, 970.6376, -1607.6494, 25.4237, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    // object_lspdExterior[299] = CreateDynamicObject(18766, 970.6376, -1602.4686, 25.4237, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    // object_lspdExterior[300] = CreateDynamicObject(18766, 945.5972, -1602.5952, 20.7136, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    // object_lspdExterior[301] = CreateDynamicObject(18766, 945.5972, -1607.5157, 20.7136, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    object_lspdExterior[296] = CreateDynamicObject(19464, 958.3568, -1604.7772, 25.8397, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Solid ground
    object_lspdExterior[297] = CreateDynamicObject(19464, 970.6373, -1604.7775, 25.8397, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Solid ground

    object_lspdExterior[298] = CreateDynamicObject(19545, 948.2772, -1590.9487, 12.0777, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane62_5x15Conc1
    object_lspdExterior[299] = CreateDynamicObject(19172, 1028.7048, -1620.1451, 6.2786, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_lspdExterior[299], 0, "Reparieren", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lspdExterior[299], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[300] = CreateDynamicObject(19172, 1027.3035, -1620.1451, 6.5186, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_lspdExterior[300], 0, "@", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 100, 0, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_lspdExterior[300], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[301] = CreateDynamicObject(19172, 1025.5529, -1620.1451, 5.7886, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_lspdExterior[301], 0, "Tanken", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_lspdExterior[301], 1, 19297, "matlights", "invisible", 0x00000000);
    object_lspdExterior[302] = CreateDynamicObject(19912, 1002.3541, -1597.9836, 9.7009, 0.0000, 0.0000, 60.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gate

    object_lspdExterior_gate = object_lspdExterior[302];
}