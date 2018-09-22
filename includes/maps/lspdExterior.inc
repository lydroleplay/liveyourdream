#include <YSI\y_hooks>

// Global interior define
#define MAPS_LSPDEXTERIOR_INTERIOR      0
#define MAPS_LSPDINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// LSPD points
#define LSPD_INTERIOR_ENTER_COORDS		        960.5081, -1599.0929, 13.6134
#define LSPD_INTERIOR_EXIT_COORDS		        1619.5063, -1377.3353, 1962.5280
#define LSPD_INTERIOR_ENTER_FACING		        0.0000
#define LSPD_INTERIOR_EXIT_FACING               270.0000
#define LSPD_STATEREPAIR_COORDS			        942.5826, -1658.7054, 13.5491
#define LSPD_ARREST_COORDS                      982.1033, -1604.8241, 13.5228
#define LSPD_HELI_STAIRS_POINT                  950.1772, -1605.3492, 22.4687
#define LSPD_HELI_STAIRS_POINT_FACING           90.0000
#define LSPD_INTERIOR_HELI_STAIRS_POINT         1626.2921, -1369.3011, 1962.5068
#define LSPD_INTERIOR_HELI_STAIRS_POINT_FACING  180.0000
#define LSPD_BARRIER_FOR_RANGE_COORDS	        943.2167, -1625.7542, 13.5469
#define LSPD_BARRIER_OPEN_RY				    0.0000
#define LSPD_BARRIER_CLOSED_RY			        -90.0000

// Map variables
new object_lspdExterior[523];
new pickup_lspdExterior[4];
new text3D_lspdExterior[2];
new vehicle_lspdExterior[34]; // using vehicle_lspdExterior for the alcatraz vehicles
new object_lspdExterior_barrier;

CMD:lspdbarrier(playerid, params[]) {
	if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 9 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))
		return SendClientMessage(playerid, COLOR_RED, "Du bist kein Staatsbeamter.");

	if (!IsPlayerInRangeOfPoint(playerid, 20.0, LSPD_BARRIER_FOR_RANGE_COORDS)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe der LSPD-Schranke.");

	new Float:fX, Float:fY, Float:fZ, Float:fRX, Float:fRY, Float:fRZ;
	GetDynamicObjectPos(object_lspdExterior_barrier, fX, fY, fZ);
	GetDynamicObjectRot(object_lspdExterior_barrier, fRX, fRY, fRZ);

	if (fRY == LSPD_BARRIER_OPEN_RY)
		MoveDynamicObject(object_lspdExterior_barrier, fX, fY, fZ - 0.0001, 0.0002, fRX, LSPD_BARRIER_CLOSED_RY, fRZ);
	else
		MoveDynamicObject(object_lspdExterior_barrier, fX, fY, fZ + 0.0001, 0.0002, fRX, LSPD_BARRIER_OPEN_RY, fRZ);

	return 1;
}

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 6072, 952.7109, -1599.5391, 20.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 726, 958.0391, -1678.0547, 10.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 729, 940.9297, -1668.8594, 11.3203, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 930.0703, -1649.4063, 4.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 930.1406, -1662.2969, 4.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 748, 934.3438, -1635.8672, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 933.1016, -1634.8516, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 792, 936.4219, -1651.6641, 12.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 638, 942.7969, -1653.4531, 13.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 942.3516, -1656.1797, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1231, 942.6641, -1651.6094, 15.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 638, 942.7969, -1649.8672, 13.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 942.2422, -1647.0313, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 943.5000, -1656.2344, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 955.9063, -1656.2344, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 954.7578, -1656.1797, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 792, 949.0313, -1651.6641, 12.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 943.5000, -1647.0313, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1231, 955.0547, -1651.6094, 15.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 638, 955.3281, -1653.4531, 13.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 638, 955.3281, -1649.8672, 13.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 954.6484, -1647.0313, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 955.9063, -1647.0313, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 943.2734, -1640.3203, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 951.8672, -1639.4063, 11.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 944.7344, -1637.1484, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 945.2656, -1638.8047, 20.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 972.3359, -1675.5391, 11.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 979.5703, -1680.3047, 11.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 978.9609, -1674.7344, 11.4688, 0.25);
    RemoveBuildingForPlayer(playerid, 792, 960.9922, -1651.6641, 12.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 1231, 966.8750, -1651.6094, 15.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 638, 967.0313, -1653.4531, 13.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 967.6719, -1656.2344, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 966.5234, -1656.1797, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 615, 968.2266, -1665.6875, 12.2109, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 979.5469, -1665.4766, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 975.6094, -1662.2109, 11.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 979.2031, -1650.7500, 11.7188, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 979.9688, -1656.8672, 11.4375, 0.25);
    RemoveBuildingForPlayer(playerid, 792, 973.5625, -1651.6641, 12.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 638, 967.0313, -1649.8672, 13.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 966.4141, -1647.0313, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1280, 967.6719, -1647.0313, 12.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 982.0156, -1640.8281, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 963.5469, -1639.4063, 11.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 968.9063, -1635.2109, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 748, 971.0000, -1634.7813, 12.6172, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 968.2578, -1634.1094, 20.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 748, 929.2813, -1632.7109, 12.6172, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 931.2734, -1631.9219, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 932.1016, -1632.8984, 20.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 930.8438, -1615.9844, 12.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 930.8750, -1616.7188, 11.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 940.6641, -1616.2031, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 943.3906, -1619.9688, 8.2109, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 951.8906, -1619.9688, 4.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 949.9219, -1624.7188, 11.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 961.1172, -1624.7188, 11.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 959.4766, -1616.7188, 11.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 944.8516, -1615.9844, 12.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 958.6953, -1615.9844, 12.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 954.5078, -1616.2031, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 6047, 952.7109, -1599.5391, 20.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 6043, 955.1484, -1612.2500, 20.1719, 0.25);
    RemoveBuildingForPlayer(playerid, 748, 966.5625, -1630.7891, 12.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 634, 967.0391, -1616.7188, 11.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 967.6094, -1632.0000, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 969.6328, -1616.2031, 12.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 973.8281, -1615.9844, 12.2734, 0.25);
    RemoveBuildingForPlayer(playerid, 1297, 922.8828, -1623.7578, 15.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 1297, 922.8828, -1599.8750, 15.9297, 0.25);
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
    
    // 3DTextLabels
    text3D_lspdExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, LSPD_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LSPDEXTERIOR_INTERIOR); // Staterepair
    text3D_lspdExterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Einsperrpunkt\n" COLOR_HEX_WHITE "Tippe /Arrest", COLOR_WHITE, LSPD_ARREST_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LSPDEXTERIOR_INTERIOR); // /arrest

	// Vehicles
    vehicle_lspdExterior[0] = AddStaticVehicleEx(523, 955.0487, -1627.1980, 13.1190, 91.8772, 0, 0, -1);
    vehicle_lspdExterior[1] = AddStaticVehicleEx(523, 955.0923, -1629.6763, 13.1271, 89.3321, 0, 0, -1);
    vehicle_lspdExterior[2] = AddStaticVehicleEx(596, 955.5467, -1633.0267, 13.1997, 89.1210, 0, 1, -1);
    vehicle_lspdExterior[3] = AddStaticVehicleEx(596, 955.6099, -1637.8204, 13.1997, 88.8109, 0, 1, -1);
    vehicle_lspdExterior[4] = AddStaticVehicleEx(596, 955.5961, -1642.7668, 13.2087, 90.8908, 0, 1, -1);
    vehicle_lspdExterior[5] = AddStaticVehicleEx(596, 955.5625, -1647.5470, 13.2000, 89.8973, 0, 1, -1);
    vehicle_lspdExterior[6] = AddStaticVehicleEx(599, 955.6841, -1652.1779, 13.8556, 89.6328, 0, 1, -1);
    vehicle_lspdExterior[7] = AddStaticVehicleEx(599, 930.5978, -1652.3821, 13.6117, 267.8501, 0, 1, -1);
    vehicle_lspdExterior[8] = AddStaticVehicleEx(596, 930.6427, -1647.5671, 13.1997, 269.9098, 0, 1, -1);
    vehicle_lspdExterior[9] = AddStaticVehicleEx(596, 930.7032, -1642.7721, 13.1987, 269.7331, 0, 1, -1);
    vehicle_lspdExterior[10] = AddStaticVehicleEx(596, 930.8272, -1637.9507, 13.1978, 270.5612, 0, 1, -1);
    vehicle_lspdExterior[11] = AddStaticVehicleEx(596, 930.9959, -1632.8950, 13.2015, 269.2267, 0, 1, -1);
    vehicle_lspdExterior[12] = AddStaticVehicleEx(523, 931.0034, -1629.6007, 13.1191, 269.4981, 0, 0, -1);
    vehicle_lspdExterior[13] = AddStaticVehicleEx(523, 930.8427, -1627.1454, 13.1205, 269.7829, 0, 0, -1);
    vehicle_lspdExterior[14] = AddStaticVehicleEx(426, 955.5193, -1664.8403, 13.3106, 89.6815, 0, 0, -1);
    vehicle_lspdExterior[15] = AddStaticVehicleEx(560, 955.8607, -1670.0212, 13.2051, 90.5172, 0, 0, -1);
    vehicle_lspdExterior[16] = AddStaticVehicleEx(560, 955.8809, -1674.9282, 13.1932, 90.2041, 0, 0, -1);
    vehicle_lspdExterior[17] = AddStaticVehicleEx(427, 954.4572, -1679.9684, 13.7067, 90.4432, 0, 1, -1);
    vehicle_lspdExterior[18] = AddStaticVehicleEx(427, 954.4075, -1685.1206, 13.7298, 89.5198, 0, 1, -1);
    vehicle_lspdExterior[19] = AddStaticVehicleEx(601, 931.0857, -1684.6996, 13.2339, 270.0629, 0, 0, -1);
    vehicle_lspdExterior[20] = AddStaticVehicleEx(601, 931.1354, -1679.8901, 13.3853, 269.6816, 0, 0, -1);
    vehicle_lspdExterior[21] = AddStaticVehicleEx(541, 930.4506, -1675.0322, 13.1999, 269.9868, 0, 0, -1);
    vehicle_lspdExterior[22] = AddStaticVehicleEx(426, 930.5852, -1664.9645, 13.3122, 270.8643, 0, 0, -1);
    vehicle_lspdExterior[23] = AddStaticVehicleEx(541, 930.3528, -1669.8665, 13.1877, 270.3683, 0, 0, -1);
    vehicle_lspdExterior[24] = AddStaticVehicleEx(497, 944.5777, -1605.9824, 22.6371, 359.4388, 0, 0, -1);
    vehicle_lspdExterior[25] = AddStaticVehicleEx(430, 961.4000, -2050.2000, 0.0000, 0.0000, 0, 1, -1); // LSPD boat

	// Objects
	object_lspdExterior[0] = CreateDynamicObject(18981, 966.5106, -1607.6793, 12.0690, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[0], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_lspdExterior[1] = CreateDynamicObject(18981, 939.8814, -1594.7486, 12.1084, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[1], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_lspdExterior[2] = CreateDynamicObject(18981, 941.6107, -1607.6700, 12.0586, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[2], 0, 16640, "a51", "concretemanky", 0xFFA7A28F);
    object_lspdExterior[3] = CreateDynamicObject(18981, 966.5468, -1601.8924, 12.1000, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[3], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[4] = CreateDynamicObject(18981, 952.3770, -1601.8924, 12.1103, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[4], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[5] = CreateDynamicObject(19464, 953.6362, -1599.9095, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[5], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[6] = CreateDynamicObject(19464, 965.4862, -1599.9598, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[6], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[7] = CreateDynamicObject(19464, 971.3964, -1599.9498, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[7], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[8] = CreateDynamicObject(19464, 959.5562, -1599.9398, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[8], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[9] = CreateDynamicObject(19464, 975.1973, -1599.9394, 15.1042, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[9], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[10] = CreateDynamicObject(19377, 955.4810, -1599.8619, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[10], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[11] = CreateDynamicObject(19377, 963.7324, -1599.8918, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[11], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[12] = CreateDynamicObject(19377, 973.3032, -1599.9018, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[12], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[13] = CreateDynamicObject(19464, 978.0374, -1602.7873, 15.1042, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[13], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[14] = CreateDynamicObject(19464, 978.0274, -1607.4095, 15.1042, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[14], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[15] = CreateDynamicObject(19377, 978.0640, -1604.6534, 20.7157, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[15], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[16] = CreateDynamicObject(19377, 978.0540, -1605.5340, 20.7157, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[16], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[17] = CreateDynamicObject(19572, 957.3383, -1598.9293, 13.4799, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PisshBox1
    SetDynamicObjectMaterial(object_lspdExterior[17], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[18] = CreateDynamicObject(1522, 960.5474, -1599.8105, 12.4568, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_lspdExterior[18], 0, 12855, "cunte_cop", "sw_copdoor1", 0xFFFFFFFF);
    object_lspdExterior[19] = CreateDynamicObject(19572, 957.3383, -1598.6395, 13.4799, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PisshBox1
    SetDynamicObjectMaterial(object_lspdExterior[19], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[20] = CreateDynamicObject(19611, 957.3383, -1598.7628, 12.1471, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MicrophoneStand1
    SetDynamicObjectMaterial(object_lspdExterior[20], 0, 14477, "crlsbits", "newtreeleavesb128", 0xFFFFFFFF);
    object_lspdExterior[21] = CreateDynamicObject(640, 954.0858, -1598.7370, 12.5424, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_lspdExterior[22] = CreateDynamicObject(640, 953.4758, -1598.6269, 12.5424, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_lspdExterior[23] = CreateDynamicObject(19429, 956.0308, -1598.8270, 12.5235, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall069
    SetDynamicObjectMaterial(object_lspdExterior[23], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[24] = CreateDynamicObject(19429, 952.5407, -1598.8270, 12.5235, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall069
    SetDynamicObjectMaterial(object_lspdExterior[24], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[25] = CreateDynamicObject(19429, 952.3908, -1598.8270, 12.5235, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall069
    SetDynamicObjectMaterial(object_lspdExterior[25], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[26] = CreateDynamicObject(19429, 966.7299, -1598.8270, 12.5333, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall069
    SetDynamicObjectMaterial(object_lspdExterior[26], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[27] = CreateDynamicObject(19572, 963.1795, -1598.9294, 13.4799, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PisshBox1
    SetDynamicObjectMaterial(object_lspdExterior[27], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[28] = CreateDynamicObject(19429, 964.6096, -1598.8220, 12.5235, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall069
    SetDynamicObjectMaterial(object_lspdExterior[28], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[29] = CreateDynamicObject(19464, 960.4467, -1599.6297, 16.4144, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[29], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[30] = CreateDynamicObject(19464, 960.4268, -1599.6595, 16.3644, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[30], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[31] = CreateDynamicObject(640, 965.9069, -1598.6269, 12.5424, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_lspdExterior[32] = CreateDynamicObject(19572, 963.1795, -1598.6395, 13.4799, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PisshBox1
    SetDynamicObjectMaterial(object_lspdExterior[32], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[33] = CreateDynamicObject(974, 930.6232, -1625.8979, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[33], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[33], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[34] = CreateDynamicObject(974, 933.9837, -1625.8979, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[34], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[34], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[35] = CreateDynamicObject(19611, 963.1787, -1598.7628, 12.1773, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MicrophoneStand1
    SetDynamicObjectMaterial(object_lspdExterior[35], 0, 14477, "crlsbits", "newtreeleavesb128", 0xFFFFFFFF);
    object_lspdExterior[36] = CreateDynamicObject(1522, 959.0475, -1599.8105, 12.4568, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_lspdExterior[36], 0, 12855, "cunte_cop", "sw_copdoor1", 0xFFFFFFFF);
    object_lspdExterior[37] = CreateDynamicObject(19450, 960.5629, -1599.8413, 10.4486, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_lspdExterior[37], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[38] = CreateDynamicObject(19445, 960.5274, -1603.8448, 12.5275, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[38], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[39] = CreateDynamicObject(19087, 962.8900, -1599.7634, 12.6148, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope1
    SetDynamicObjectMaterial(object_lspdExterior[39], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    object_lspdExterior[40] = CreateDynamicObject(19461, 974.2025, -1582.3194, 11.5783, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[40], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[41] = CreateDynamicObject(19461, 944.7022, -1582.3194, 11.5783, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[41], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[42] = CreateDynamicObject(19461, 979.0625, -1587.0498, 11.5783, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[42], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[43] = CreateDynamicObject(19461, 974.2025, -1584.1494, 12.5277, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[43], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[44] = CreateDynamicObject(19461, 944.7019, -1584.1494, 12.5284, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[44], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[45] = CreateDynamicObject(19464, 960.4066, -1599.6297, 16.4144, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[45], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[46] = CreateDynamicObject(19461, 954.3220, -1584.1494, 12.5284, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[46], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[47] = CreateDynamicObject(19461, 954.3422, -1582.3194, 11.5783, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[47], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[48] = CreateDynamicObject(19565, 957.6693, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[48], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[49] = CreateDynamicObject(19461, 977.2432, -1587.8409, 12.5284, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[49], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[50] = CreateDynamicObject(19565, 958.1389, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[50], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[51] = CreateDynamicObject(19565, 958.6093, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[51], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[52] = CreateDynamicObject(19565, 963.1701, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[52], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[53] = CreateDynamicObject(19565, 962.7000, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[53], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[54] = CreateDynamicObject(19565, 962.2302, -1597.1142, 16.2693, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[54], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[55] = CreateDynamicObject(19565, 963.3806, -1597.3144, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[55], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[56] = CreateDynamicObject(19565, 957.4611, -1597.3144, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[56], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[57] = CreateDynamicObject(19565, 963.3806, -1597.7845, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[57], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[58] = CreateDynamicObject(19565, 963.3806, -1598.2451, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[58], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[59] = CreateDynamicObject(19565, 963.3806, -1598.7154, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[59], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[60] = CreateDynamicObject(19565, 963.3806, -1599.1760, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[60], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[61] = CreateDynamicObject(19565, 963.3806, -1599.6462, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[61], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[62] = CreateDynamicObject(19565, 957.4611, -1599.6462, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[62], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[63] = CreateDynamicObject(19565, 957.4611, -1599.1761, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[63], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[64] = CreateDynamicObject(19466, 963.6514, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[64], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[65] = CreateDynamicObject(19565, 957.4611, -1598.7054, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[65], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[66] = CreateDynamicObject(19565, 957.4611, -1598.2452, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[66], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[67] = CreateDynamicObject(19565, 957.4611, -1597.7750, 16.2693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_lspdExterior[67], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_lspdExterior[68] = CreateDynamicObject(673, 970.8645, -1583.8813, 10.3802, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltree
    object_lspdExterior[69] = CreateDynamicObject(19445, 970.6685, -1587.6848, 12.5275, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[69], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[70] = CreateDynamicObject(869, 971.4724, -1584.0648, 12.7341, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[71] = CreateDynamicObject(869, 977.2406, -1587.4394, 12.7341, 0.0000, 0.0000, 76.5998, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[72] = CreateDynamicObject(673, 977.1644, -1587.5416, 10.3802, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltree
    object_lspdExterior[73] = CreateDynamicObject(19445, 960.5274, -1597.0747, 12.5172, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[73], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[74] = CreateDynamicObject(19445, 960.5274, -1594.2237, 12.5275, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[74], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[75] = CreateDynamicObject(19445, 957.7985, -1587.6848, 12.5275, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[75], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[76] = CreateDynamicObject(19445, 948.1677, -1587.6848, 12.5275, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[76], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[77] = CreateDynamicObject(19445, 961.1386, -1587.6848, 12.5375, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[77], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[78] = CreateDynamicObject(19461, 967.0620, -1584.1494, 12.5186, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[78], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[79] = CreateDynamicObject(19175, 959.9796, -1597.0742, 15.7966, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[79], 0, "Eingang - Polizei", 90, "Arial", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdExterior[79], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[80] = CreateDynamicObject(19461, 967.0819, -1582.3083, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[80], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[81] = CreateDynamicObject(19445, 960.5274, -1587.0532, 12.5172, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[81], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[82] = CreateDynamicObject(869, 964.3712, -1584.0648, 12.7341, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[83] = CreateDynamicObject(19466, 959.5402, -1599.7425, 24.6791, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[83], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[84] = CreateDynamicObject(1232, 962.0841, -1582.5045, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[85] = CreateDynamicObject(1232, 959.2340, -1582.5045, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[86] = CreateDynamicObject(19445, 944.6970, -1587.6848, 12.5172, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[86], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[87] = CreateDynamicObject(869, 957.1010, -1584.0648, 12.7341, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[88] = CreateDynamicObject(869, 942.1408, -1584.0648, 12.7341, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[89] = CreateDynamicObject(869, 950.1513, -1584.0648, 12.7341, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[90] = CreateDynamicObject(673, 941.7042, -1583.8813, 10.3802, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltree
    object_lspdExterior[91] = CreateDynamicObject(19445, 973.8291, -1587.8349, 12.5172, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[91], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[92] = CreateDynamicObject(19466, 955.3311, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[92], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[93] = CreateDynamicObject(19466, 955.3911, -1599.7624, 24.6492, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[93], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[94] = CreateDynamicObject(19466, 966.7418, -1599.7624, 24.6492, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[94], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[95] = CreateDynamicObject(19466, 952.3010, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[95], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[96] = CreateDynamicObject(19466, 963.7216, -1599.7624, 24.6492, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[96], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[97] = CreateDynamicObject(19466, 952.3010, -1599.7624, 24.6492, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[97], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[98] = CreateDynamicObject(1281, 974.6046, -1584.3524, 13.4047, 0.0000, 0.0000, -27.7999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    SetDynamicObjectMaterial(object_lspdExterior[98], 0, 10765, "airportgnd_sfse", "white", 0xFF6C8495);
    object_lspdExterior[99] = CreateDynamicObject(1570, 953.8385, -1584.1269, 13.7770, 0.0000, 0.0000, -26.9999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_NOODLE_3
    SetDynamicObjectMaterial(object_lspdExterior[99], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[99], 2, 10765, "airportgnd_sfse", "white", 0xFF4D8495);
    object_lspdExterior[100] = CreateDynamicObject(19466, 959.5402, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[100], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[101] = CreateDynamicObject(19461, 953.8413, -1589.4908, 11.1786, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[101], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[102] = CreateDynamicObject(19461, 944.6812, -1589.5107, 11.1686, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[102], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[103] = CreateDynamicObject(19461, 958.7412, -1594.2313, 11.1786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[103], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[104] = CreateDynamicObject(19360, 971.9957, -1591.0373, 11.1745, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[104], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[105] = CreateDynamicObject(748, 946.0391, -1584.2574, 12.6724, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[106] = CreateDynamicObject(19464, 942.9863, -1601.8365, 21.3638, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[106], 0, 10756, "airportroads_sfse", "ws_white_wall1", 0xFFFFFFFF);
    object_lspdExterior[107] = CreateDynamicObject(19360, 973.5062, -1592.7375, 11.1745, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[107], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[108] = CreateDynamicObject(19461, 962.3817, -1594.2313, 11.1786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[108], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[109] = CreateDynamicObject(19461, 967.2722, -1589.4903, 11.1786, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[109], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[110] = CreateDynamicObject(19464, 948.0769, -1601.8365, 21.3537, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[110], 0, 10756, "airportroads_sfse", "ws_white_wall1", 0xFFFFFFFF);
    object_lspdExterior[111] = CreateDynamicObject(19464, 941.5460, -1601.8365, 21.3838, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[111], 0, 10756, "airportroads_sfse", "ws_white_wall1", 0xFFFFFFFF);
    object_lspdExterior[112] = CreateDynamicObject(19360, 976.7158, -1592.7375, 11.1745, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[112], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[113] = CreateDynamicObject(19360, 977.4063, -1592.7475, 11.1646, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[113], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[114] = CreateDynamicObject(19464, 941.5460, -1607.3498, 21.3938, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[114], 0, 10756, "airportroads_sfse", "ws_white_wall1", 0xFFFFFFFF);
    object_lspdExterior[115] = CreateDynamicObject(19464, 948.0769, -1607.3470, 21.3437, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[115], 0, 10756, "airportroads_sfse", "ws_white_wall1", 0xFFFFFFFF);
    object_lspdExterior[116] = CreateDynamicObject(19461, 979.0625, -1596.6695, 11.5783, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[116], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[117] = CreateDynamicObject(19464, 942.9779, -1607.3470, 21.3838, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[117], 0, 10756, "airportroads_sfse", "ws_white_wall1", 0xFFFFFFFF);
    object_lspdExterior[118] = CreateDynamicObject(19461, 979.0625, -1606.2795, 11.5783, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[118], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[119] = CreateDynamicObject(19461, 979.0723, -1615.3797, 11.5586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[119], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[120] = CreateDynamicObject(19466, 950.6024, -1602.1141, 23.7091, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[120], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[121] = CreateDynamicObject(19466, 950.6021, -1608.3448, 23.7091, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[121], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[122] = CreateDynamicObject(1458, 965.9069, -1584.9278, 12.8584, 0.0000, 0.0000, -70.3999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_CART
    object_lspdExterior[123] = CreateDynamicObject(19466, 954.1113, -1610.3840, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[123], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[124] = CreateDynamicObject(19466, 957.3007, -1610.3840, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[124], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[125] = CreateDynamicObject(19466, 960.5512, -1610.3840, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[125], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[126] = CreateDynamicObject(19466, 963.8615, -1610.3540, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[126], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[127] = CreateDynamicObject(19466, 967.0119, -1610.3540, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[127], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[128] = CreateDynamicObject(19466, 969.8720, -1610.3540, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[128], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[129] = CreateDynamicObject(19466, 972.7921, -1610.3540, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[129], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[130] = CreateDynamicObject(19466, 975.7224, -1610.3708, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[130], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[131] = CreateDynamicObject(19466, 975.7219, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[131], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[132] = CreateDynamicObject(19466, 972.7119, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[132], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[133] = CreateDynamicObject(19466, 969.8413, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[133], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[134] = CreateDynamicObject(19466, 963.8305, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[134], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[135] = CreateDynamicObject(19466, 957.3015, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[135], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[136] = CreateDynamicObject(19466, 960.5512, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[136], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[137] = CreateDynamicObject(19466, 954.1409, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[137], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[138] = CreateDynamicObject(19466, 966.9812, -1610.3840, 20.3992, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[138], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[139] = CreateDynamicObject(19377, 973.3032, -1610.2502, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[139], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[140] = CreateDynamicObject(19377, 963.7324, -1610.2524, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[140], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[141] = CreateDynamicObject(19377, 955.4810, -1610.2733, 20.7157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[141], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[142] = CreateDynamicObject(19377, 955.4810, -1610.2733, 10.2156, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[142], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[143] = CreateDynamicObject(19377, 965.1303, -1610.2733, 10.2156, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[143], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[144] = CreateDynamicObject(19377, 973.1895, -1610.2331, 10.2156, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[144], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[145] = CreateDynamicObject(19466, 978.1710, -1605.0544, 24.6291, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[145], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[146] = CreateDynamicObject(19466, 978.1710, -1608.3652, 24.6291, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[146], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[147] = CreateDynamicObject(19466, 978.1710, -1601.7237, 24.6191, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[147], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[148] = CreateDynamicObject(19466, 978.1710, -1601.7237, 21.4892, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[148], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[149] = CreateDynamicObject(19466, 978.1710, -1608.3652, 21.4792, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[149], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[150] = CreateDynamicObject(19466, 978.1710, -1605.0544, 21.4792, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[150], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[151] = CreateDynamicObject(19466, 978.1710, -1605.0439, 18.8491, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[151], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[152] = CreateDynamicObject(19466, 978.1710, -1601.7137, 18.8491, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[152], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[153] = CreateDynamicObject(19466, 978.1710, -1608.3238, 18.8491, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[153], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[154] = CreateDynamicObject(19175, 960.6892, -1599.7746, 22.0265, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[154], 0, "S", 90, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdExterior[154], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[155] = CreateDynamicObject(19175, 964.0999, -1599.7746, 22.0265, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[155], 0, "L", 90, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdExterior[155], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[156] = CreateDynamicObject(19377, 950.7105, -1604.5399, 20.7056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[156], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[157] = CreateDynamicObject(19175, 956.7786, -1599.7746, 22.0265, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[157], 0, "P", 90, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdExterior[157], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[158] = CreateDynamicObject(19175, 953.0479, -1599.7746, 22.0265, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[158], 0, "D", 90, "Arial", 160, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdExterior[158], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[159] = CreateDynamicObject(19377, 950.7205, -1605.5406, 20.7056, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[159], 0, 3820, "boxhses_sfsx", "ws_mixedbrick", 0xFFFFFFFF);
    object_lspdExterior[160] = CreateDynamicObject(19461, 962.3817, -1603.8614, 11.1786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[160], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[161] = CreateDynamicObject(19461, 958.7421, -1603.8614, 11.1786, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[161], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[162] = CreateDynamicObject(19466, 975.7219, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[162], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[163] = CreateDynamicObject(19466, 972.7512, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[163], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[164] = CreateDynamicObject(19466, 969.8311, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[164], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[165] = CreateDynamicObject(19466, 966.9312, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[165], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[166] = CreateDynamicObject(19466, 963.8107, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[166], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[167] = CreateDynamicObject(19466, 960.5402, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[167], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[168] = CreateDynamicObject(19466, 957.3103, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[168], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[169] = CreateDynamicObject(19466, 954.1300, -1610.3840, 16.2691, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[169], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[170] = CreateDynamicObject(19466, 952.3397, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[170], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[171] = CreateDynamicObject(19466, 955.3098, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[171], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[172] = CreateDynamicObject(19466, 966.7307, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[172], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[173] = CreateDynamicObject(19466, 972.7221, -1599.7425, 21.4491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[173], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[174] = CreateDynamicObject(19360, 939.8460, -1583.8365, 11.6047, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[174], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[175] = CreateDynamicObject(19360, 939.8358, -1588.0267, 11.1246, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[175], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[176] = CreateDynamicObject(19360, 939.8259, -1587.0063, 11.1447, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[176], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[177] = CreateDynamicObject(19461, 939.8405, -1594.4215, 11.1385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[177], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[178] = CreateDynamicObject(19461, 939.8203, -1615.2629, 11.1583, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[178], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[179] = CreateDynamicObject(19461, 939.8308, -1604.0318, 11.1385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[179], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[180] = CreateDynamicObject(19461, 934.9310, -1589.5301, 11.1583, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[180], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[181] = CreateDynamicObject(19461, 932.1712, -1589.5201, 11.1583, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[181], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[182] = CreateDynamicObject(19461, 932.1712, -1582.3100, 11.1583, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[182], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[183] = CreateDynamicObject(19461, 935.0714, -1582.3199, 11.1485, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[183], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[184] = CreateDynamicObject(19360, 927.4359, -1587.8465, 11.1547, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[184], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[185] = CreateDynamicObject(19360, 927.4359, -1584.6662, 11.1547, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[185], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[186] = CreateDynamicObject(19360, 927.4359, -1583.8762, 11.1344, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall008
    SetDynamicObjectMaterial(object_lspdExterior[186], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[187] = CreateDynamicObject(19603, 930.0280, -1585.9615, 12.7510, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane1
    object_lspdExterior[188] = CreateDynamicObject(19603, 935.0283, -1585.9615, 12.7510, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane1
    object_lspdExterior[189] = CreateDynamicObject(19603, 937.2788, -1585.9615, 12.7306, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane1
    object_lspdExterior[190] = CreateDynamicObject(748, 938.6353, -1583.4868, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[191] = CreateDynamicObject(748, 937.2805, -1583.5638, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[192] = CreateDynamicObject(748, 935.8513, -1583.4864, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[193] = CreateDynamicObject(748, 934.6267, -1583.5544, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[194] = CreateDynamicObject(748, 933.3753, -1583.5063, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[195] = CreateDynamicObject(748, 932.1787, -1583.5450, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[196] = CreateDynamicObject(748, 930.9910, -1583.4637, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[197] = CreateDynamicObject(748, 929.8374, -1583.5483, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[198] = CreateDynamicObject(748, 928.4345, -1583.4852, 11.8226, 0.0000, 0.0000, -118.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[199] = CreateDynamicObject(748, 928.6107, -1583.5664, 11.8226, 0.0000, 0.0000, -32.7999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[200] = CreateDynamicObject(748, 928.7885, -1588.4204, 11.8226, 0.0000, 0.0000, 48.0998, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[201] = CreateDynamicObject(748, 930.0056, -1588.2176, 11.8226, 0.0000, 0.0000, 73.4999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[202] = CreateDynamicObject(748, 931.2379, -1588.2485, 11.8226, 0.0000, 0.0000, 73.4999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[203] = CreateDynamicObject(748, 932.5484, -1588.2607, 11.8226, 0.0000, 0.0000, 73.4999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[204] = CreateDynamicObject(748, 933.8969, -1588.2923, 11.8226, 0.0000, 0.0000, 59.9999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[205] = CreateDynamicObject(748, 935.1248, -1588.2862, 11.8226, 0.0000, 0.0000, 59.9999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[206] = CreateDynamicObject(748, 936.3983, -1588.3409, 11.8226, 0.0000, 0.0000, 59.9999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[207] = CreateDynamicObject(748, 937.6743, -1588.3503, 11.8226, 0.0000, 0.0000, 59.9999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[208] = CreateDynamicObject(748, 938.7235, -1588.3325, 11.8226, 0.0000, 0.0000, 59.9999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[209] = CreateDynamicObject(748, 938.6262, -1588.2811, 11.8823, 0.0000, 0.0000, 152.1999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[210] = CreateDynamicObject(748, 928.7525, -1588.3269, 11.8226, 0.0000, 0.0000, -12.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_scrb_grp1
    object_lspdExterior[211] = CreateDynamicObject(9833, 933.3764, -1586.1445, 11.8940, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fountain_SFW
    object_lspdExterior[212] = CreateDynamicObject(1886, 963.1541, -1597.0279, 16.2786, 0.0000, 0.0000, -142.6999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_lspdExterior[213] = CreateDynamicObject(1886, 957.6973, -1597.1092, 16.3085, 0.0000, 0.0000, 140.8000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shop_sec_cam
    object_lspdExterior[214] = CreateDynamicObject(1256, 949.7393, -1586.2585, 13.2531, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Stonebench1
    object_lspdExterior[215] = CreateDynamicObject(1256, 942.0189, -1586.2585, 13.2531, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Stonebench1
    object_lspdExterior[216] = CreateDynamicObject(1256, 963.6198, -1586.2585, 13.2531, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Stonebench1
    object_lspdExterior[217] = CreateDynamicObject(1256, 971.0405, -1586.2585, 13.2531, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Stonebench1
    object_lspdExterior[218] = CreateDynamicObject(1256, 975.1207, -1590.9287, 13.2531, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Stonebench1
    object_lspdExterior[219] = CreateDynamicObject(1232, 951.6939, -1586.0753, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[220] = CreateDynamicObject(1232, 940.2337, -1586.0753, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[221] = CreateDynamicObject(1232, 965.4351, -1586.0753, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[222] = CreateDynamicObject(1232, 969.3751, -1586.0753, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[223] = CreateDynamicObject(1232, 975.2553, -1589.3258, 13.2762, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_lspdExterior[224] = CreateDynamicObject(19461, 939.8305, -1613.2821, 11.1485, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[224], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[225] = CreateDynamicObject(19461, 938.7307, -1620.1103, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[225], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[226] = CreateDynamicObject(19461, 932.1995, -1620.1202, 11.5485, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[226], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[227] = CreateDynamicObject(19449, 973.3120, -1615.5809, 12.4856, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[227], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[228] = CreateDynamicObject(19449, 973.3120, -1612.0815, 12.4856, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[228], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[229] = CreateDynamicObject(19449, 973.3120, -1618.3917, 12.4958, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[229], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[230] = CreateDynamicObject(19461, 948.3513, -1620.1103, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[230], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[231] = CreateDynamicObject(19461, 974.1909, -1620.1103, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[231], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[232] = CreateDynamicObject(19461, 964.6008, -1620.1103, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[232], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[233] = CreateDynamicObject(19461, 957.7805, -1620.1003, 11.5585, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[233], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[234] = CreateDynamicObject(19449, 963.6820, -1618.3917, 12.4958, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[234], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[235] = CreateDynamicObject(19464, 939.6467, -1592.8292, 10.0642, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[235], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[236] = CreateDynamicObject(19464, 939.6467, -1598.7591, 10.0642, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[236], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[237] = CreateDynamicObject(19464, 939.6467, -1604.6789, 10.0642, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[237], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[238] = CreateDynamicObject(19464, 939.6467, -1610.6097, 10.0642, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[238], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[239] = CreateDynamicObject(19464, 939.6467, -1616.5400, 10.0642, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[239], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[240] = CreateDynamicObject(19464, 939.6467, -1617.0705, 10.0839, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[240], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[241] = CreateDynamicObject(19449, 963.6820, -1614.8907, 12.4958, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[241], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[242] = CreateDynamicObject(19449, 944.5728, -1614.7634, 12.5690, 0.1999, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[242], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[243] = CreateDynamicObject(19449, 963.6820, -1611.4005, 12.4958, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[243], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[244] = CreateDynamicObject(19449, 954.0626, -1611.4005, 12.5158, 0.1999, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[244], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[245] = CreateDynamicObject(19377, 943.1635, -1630.7158, 12.4650, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[245], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[246] = CreateDynamicObject(19445, 944.5974, -1587.6848, 12.5375, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_lspdExterior[246], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_lspdExterior[247] = CreateDynamicObject(19377, 932.6635, -1649.8758, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[247], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[248] = CreateDynamicObject(19449, 954.0626, -1614.9028, 12.5158, 0.1999, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[248], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[249] = CreateDynamicObject(19466, 969.7807, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[249], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[250] = CreateDynamicObject(19461, 945.5208, -1599.8204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[250], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[251] = CreateDynamicObject(19461, 949.0214, -1599.8204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[251], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[252] = CreateDynamicObject(19461, 942.0310, -1599.7701, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[252], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[253] = CreateDynamicObject(19461, 940.3208, -1601.5106, 16.6485, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[253], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[254] = CreateDynamicObject(19461, 943.8112, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[254], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[255] = CreateDynamicObject(19461, 949.0819, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[255], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[256] = CreateDynamicObject(19461, 942.0413, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[256], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[257] = CreateDynamicObject(19461, 950.7224, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[257], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[258] = CreateDynamicObject(19461, 947.2918, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[258], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[259] = CreateDynamicObject(19461, 945.5217, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[259], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[260] = CreateDynamicObject(19461, 940.3508, -1601.4200, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[260], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[261] = CreateDynamicObject(19461, 940.3208, -1604.9698, 16.6485, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[261], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[262] = CreateDynamicObject(19461, 941.9520, -1599.8398, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[262], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[263] = CreateDynamicObject(19461, 941.9520, -1601.3508, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[263], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[264] = CreateDynamicObject(19461, 941.9520, -1603.1308, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[264], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[265] = CreateDynamicObject(19461, 941.9520, -1604.8917, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[265], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[266] = CreateDynamicObject(19461, 941.9520, -1606.7314, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[266], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[267] = CreateDynamicObject(19466, 972.7011, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[267], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[268] = CreateDynamicObject(19466, 975.7019, -1599.7641, 15.4989, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[268], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[269] = CreateDynamicObject(19461, 940.3208, -1608.5102, 16.6485, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[269], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[270] = CreateDynamicObject(19461, 941.9520, -1608.5821, 16.6284, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[270], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[271] = CreateDynamicObject(19461, 942.0098, -1610.2204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[271], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[272] = CreateDynamicObject(19377, 932.6740, -1630.6157, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[272], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[273] = CreateDynamicObject(19377, 932.6635, -1640.2452, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[273], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[274] = CreateDynamicObject(19461, 945.4608, -1610.2204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[274], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[275] = CreateDynamicObject(19461, 948.8916, -1610.2204, 16.6485, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[275], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[276] = CreateDynamicObject(19377, 943.1635, -1640.3454, 12.4670, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[276], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[277] = CreateDynamicObject(19461, 950.5717, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[277], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[278] = CreateDynamicObject(19461, 948.6818, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[278], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[279] = CreateDynamicObject(19461, 946.6820, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[279], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[280] = CreateDynamicObject(19461, 944.8311, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[280], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[281] = CreateDynamicObject(19461, 943.2008, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[281], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[282] = CreateDynamicObject(19461, 941.5905, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[282], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[283] = CreateDynamicObject(19461, 940.3496, -1608.5819, 16.6284, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[283], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[284] = CreateDynamicObject(19377, 943.1533, -1649.9759, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[284], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[285] = CreateDynamicObject(19377, 953.6535, -1649.8458, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[285], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[286] = CreateDynamicObject(3934, 944.5770, -1605.2458, 21.5259, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_lspdExterior[287] = CreateDynamicObject(19464, 930.2827, -1654.5389, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[287], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[288] = CreateDynamicObject(19377, 953.6535, -1630.5854, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[288], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[289] = CreateDynamicObject(19377, 953.6535, -1640.2154, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[289], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[290] = CreateDynamicObject(19464, 930.2827, -1626.0865, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[290], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[291] = CreateDynamicObject(19464, 930.2827, -1649.9680, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[291], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[292] = CreateDynamicObject(3526, 947.6657, -1601.9974, 21.5811, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasairportlight
    object_lspdExterior[293] = CreateDynamicObject(3526, 941.6452, -1601.9974, 21.5811, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasairportlight
    object_lspdExterior[294] = CreateDynamicObject(3526, 941.6652, -1608.6883, 21.5811, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasairportlight
    object_lspdExterior[295] = CreateDynamicObject(19464, 930.2827, -1645.0764, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[295], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[296] = CreateDynamicObject(19464, 930.2827, -1640.3946, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[296], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[297] = CreateDynamicObject(3526, 947.6555, -1608.6883, 21.5811, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vegasairportlight
    object_lspdExterior[298] = CreateDynamicObject(19466, 972.7921, -1599.7624, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[298], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[299] = CreateDynamicObject(19466, 969.7412, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[299], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[300] = CreateDynamicObject(19466, 972.6914, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[300], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[301] = CreateDynamicObject(19466, 969.7412, -1599.7425, 21.4491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[301], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[302] = CreateDynamicObject(19466, 975.6823, -1599.7425, 21.4491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[302], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[303] = CreateDynamicObject(19466, 975.6713, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[303], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[304] = CreateDynamicObject(19466, 969.7520, -1599.7624, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[304], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[305] = CreateDynamicObject(19466, 975.7224, -1599.7624, 24.6091, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[305], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[306] = CreateDynamicObject(2911, 950.6364, -1605.3647, 21.4692, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_petroldoor
    SetDynamicObjectMaterial(object_lspdExterior[306], 0, 18241, "cw_tempstuffcs_t", "des_metaldoor1", 0xFFFFFFFF);
    object_lspdExterior[307] = CreateDynamicObject(2911, 950.6364, -1605.3447, 21.4692, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_petroldoor
    SetDynamicObjectMaterial(object_lspdExterior[307], 0, 18241, "cw_tempstuffcs_t", "des_metaldoor1", 0xFFFFFFFF);
    object_lspdExterior[308] = CreateDynamicObject(19464, 930.2827, -1635.4144, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[308], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[309] = CreateDynamicObject(19464, 930.2827, -1630.6833, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[309], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[310] = CreateDynamicObject(19449, 954.0626, -1618.2635, 12.5256, 0.1999, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[310], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[311] = CreateDynamicObject(19175, 950.6292, -1605.8653, 23.6068, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_lspdExterior[311], 0, "Eingang - Dach", 90, "Arial", 25, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_lspdExterior[311], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[312] = CreateDynamicObject(19464, 955.8228, -1626.0865, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[312], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[313] = CreateDynamicObject(19464, 955.7932, -1630.6833, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[313], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[314] = CreateDynamicObject(19464, 955.8037, -1635.4144, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[314], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[315] = CreateDynamicObject(19464, 955.8037, -1640.3946, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[315], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[316] = CreateDynamicObject(19464, 955.8037, -1645.0764, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[316], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[317] = CreateDynamicObject(19449, 944.5728, -1618.2635, 12.5690, 0.1999, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[317], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[318] = CreateDynamicObject(19449, 944.5728, -1612.0720, 12.5488, 0.1999, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[318], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[319] = CreateDynamicObject(19464, 955.7932, -1649.9680, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[319], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[320] = CreateDynamicObject(19464, 955.8333, -1654.5389, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[320], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[321] = CreateDynamicObject(19464, 958.6735, -1651.7390, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[321], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[322] = CreateDynamicObject(19464, 958.6735, -1645.8089, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[322], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[323] = CreateDynamicObject(19461, 954.1007, -1625.8519, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[323], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[324] = CreateDynamicObject(19464, 958.6735, -1639.8796, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[324], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[325] = CreateDynamicObject(19464, 958.6735, -1628.7685, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[325], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[326] = CreateDynamicObject(19464, 958.6635, -1634.5594, 10.0248, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[326], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[327] = CreateDynamicObject(19464, 927.5031, -1634.5594, 10.0248, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[327], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[328] = CreateDynamicObject(19461, 958.8510, -1630.5737, 11.5684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[328], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[329] = CreateDynamicObject(19464, 927.5031, -1628.8675, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[329], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[330] = CreateDynamicObject(19461, 958.8510, -1640.1944, 11.5684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[330], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[331] = CreateDynamicObject(19461, 958.8510, -1649.8354, 11.5684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[331], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[332] = CreateDynamicObject(19464, 927.5031, -1640.4774, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[332], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[333] = CreateDynamicObject(19461, 954.1306, -1654.7159, 11.5686, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[333], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[334] = CreateDynamicObject(19464, 927.4829, -1646.4068, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[334], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[335] = CreateDynamicObject(19464, 927.5031, -1651.8050, 10.0248, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[335], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[336] = CreateDynamicObject(19461, 953.1207, -1654.7110, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[336], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[337] = CreateDynamicObject(1290, 943.1049, -1645.1269, 18.3337, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_lspdExterior[338] = CreateDynamicObject(19461, 933.1494, -1654.7159, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[338], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[339] = CreateDynamicObject(19461, 932.2199, -1654.7259, 11.5585, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[339], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[340] = CreateDynamicObject(1290, 943.1049, -1635.5860, 18.3337, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_lspdExterior[341] = CreateDynamicObject(19461, 932.2199, -1625.8929, 11.5585, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[341], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[342] = CreateDynamicObject(869, 974.3220, -1596.2956, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[343] = CreateDynamicObject(19461, 927.3300, -1630.6239, 11.5585, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[343], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[344] = CreateDynamicObject(869, 967.4923, -1593.7154, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[345] = CreateDynamicObject(19461, 927.3300, -1640.2440, 11.5585, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[345], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[346] = CreateDynamicObject(19449, 977.2454, -1615.2253, 12.5058, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[346], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[347] = CreateDynamicObject(19461, 927.3300, -1649.8745, 11.5585, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[347], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[348] = CreateDynamicObject(19461, 927.3400, -1649.9946, 11.5485, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[348], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[349] = CreateDynamicObject(19449, 977.2454, -1615.0852, 12.4958, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
    SetDynamicObjectMaterial(object_lspdExterior[349], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_lspdExterior[350] = CreateDynamicObject(869, 943.6309, -1612.4049, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[351] = CreateDynamicObject(869, 950.3308, -1617.0450, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[352] = CreateDynamicObject(869, 943.6309, -1617.0450, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[353] = CreateDynamicObject(869, 976.2822, -1616.6677, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[354] = CreateDynamicObject(869, 950.3308, -1612.8454, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[355] = CreateDynamicObject(869, 956.9713, -1612.8454, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[356] = CreateDynamicObject(869, 956.9713, -1617.1872, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[357] = CreateDynamicObject(869, 963.5319, -1617.1872, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[358] = CreateDynamicObject(869, 963.5319, -1612.5168, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[359] = CreateDynamicObject(869, 970.4321, -1612.5168, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[360] = CreateDynamicObject(869, 970.4321, -1616.6677, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[361] = CreateDynamicObject(869, 953.4519, -1593.7154, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[362] = CreateDynamicObject(869, 976.2822, -1612.3669, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[363] = CreateDynamicObject(869, 945.8214, -1593.7154, 13.0242, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_lspdExterior[364] = CreateDynamicObject(17969, 927.2758, -1642.1933, 14.6063, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hub_graffitti
    object_lspdExterior[365] = CreateDynamicObject(18667, 959.1627, -1649.9145, 14.5794, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprayTag9H
    object_lspdExterior[366] = CreateDynamicObject(18665, 958.7645, -1640.3325, 14.7173, 12.8999, 0.0000, 179.9998, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprayTag7
    object_lspdExterior[367] = CreateDynamicObject(18660, 958.7642, -1640.4123, 14.4820, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprayTag2
    object_lspdExterior[368] = CreateDynamicObject(673, 947.0042, -1615.0920, 10.3802, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltree
    object_lspdExterior[369] = CreateDynamicObject(673, 953.6442, -1615.0920, 10.3802, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltree
    object_lspdExterior[370] = CreateDynamicObject(673, 960.3839, -1615.0920, 10.3802, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltree
    object_lspdExterior[371] = CreateDynamicObject(673, 966.9536, -1615.0920, 10.3802, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltree
    object_lspdExterior[372] = CreateDynamicObject(673, 973.4038, -1615.0920, 10.3802, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltree
    object_lspdExterior[373] = CreateDynamicObject(19464, 939.6467, -1592.5688, 10.0642, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[373], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[374] = CreateDynamicObject(19464, 936.7869, -1620.0511, 10.0839, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[374], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[375] = CreateDynamicObject(19464, 936.7869, -1616.4807, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[375], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[376] = CreateDynamicObject(19464, 936.7869, -1612.6606, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[376], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[377] = CreateDynamicObject(19464, 936.7869, -1608.7496, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[377], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[378] = CreateDynamicObject(19464, 936.7869, -1604.7076, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[378], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[379] = CreateDynamicObject(19464, 936.7869, -1600.7464, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[379], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[380] = CreateDynamicObject(19464, 936.7869, -1596.7363, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[380], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[381] = CreateDynamicObject(19464, 936.7869, -1592.9947, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[381], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[382] = CreateDynamicObject(19464, 936.7869, -1589.6435, 10.0642, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[382], 0, 14668, "711c", "cj_white_wall2", 0xFFD6DAD6);
    object_lspdExterior[383] = CreateDynamicObject(19461, 983.7628, -1615.4195, 11.5586, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[383], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[384] = CreateDynamicObject(19461, 983.7628, -1615.2496, 11.5586, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[384], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[385] = CreateDynamicObject(19461, 983.7528, -1615.2093, 11.5586, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[385], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[386] = CreateDynamicObject(19426, 933.8853, -1608.7320, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[386], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[387] = CreateDynamicObject(19426, 933.8853, -1612.6330, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[387], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[388] = CreateDynamicObject(19426, 933.8853, -1616.4936, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[388], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[389] = CreateDynamicObject(19426, 933.8853, -1604.6533, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[389], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[390] = CreateDynamicObject(19426, 933.8853, -1600.7126, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[390], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[391] = CreateDynamicObject(19426, 933.8853, -1596.7016, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[391], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[392] = CreateDynamicObject(19426, 933.8853, -1592.9608, 10.8704, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_lspdExterior[392], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[393] = CreateDynamicObject(19978, 939.7819, -1618.3133, 12.2846, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_lspdExterior[394] = CreateDynamicObject(19978, 939.7819, -1614.5223, 12.2846, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_lspdExterior[395] = CreateDynamicObject(19978, 939.7819, -1610.5709, 12.2846, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_lspdExterior[396] = CreateDynamicObject(19978, 939.7819, -1606.6898, 12.2846, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_lspdExterior[397] = CreateDynamicObject(19978, 939.7819, -1602.6579, 12.2846, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_lspdExterior[398] = CreateDynamicObject(19978, 939.7819, -1598.8269, 12.2846, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_lspdExterior[399] = CreateDynamicObject(19978, 939.7819, -1594.8758, 12.2846, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_lspdExterior[400] = CreateDynamicObject(19978, 939.7819, -1591.3249, 12.2846, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_lspdExterior[401] = CreateDynamicObject(1270, 939.6334, -1596.7430, 13.3613, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkingmeterg
    SetDynamicObjectMaterial(object_lspdExterior[401], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
    object_lspdExterior[402] = CreateDynamicObject(1270, 939.6334, -1600.7141, 13.3613, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkingmeterg
    SetDynamicObjectMaterial(object_lspdExterior[402], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
    object_lspdExterior[403] = CreateDynamicObject(1270, 939.6334, -1593.0112, 13.3613, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkingmeterg
    SetDynamicObjectMaterial(object_lspdExterior[403], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
    object_lspdExterior[404] = CreateDynamicObject(1270, 939.6334, -1604.7125, 13.3613, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkingmeterg
    SetDynamicObjectMaterial(object_lspdExterior[404], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
    object_lspdExterior[405] = CreateDynamicObject(1270, 939.6334, -1608.7635, 13.3613, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkingmeterg
    SetDynamicObjectMaterial(object_lspdExterior[405], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
    object_lspdExterior[406] = CreateDynamicObject(1270, 939.6334, -1612.6745, 13.3613, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkingmeterg
    SetDynamicObjectMaterial(object_lspdExterior[406], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
    object_lspdExterior[407] = CreateDynamicObject(1270, 939.6334, -1616.4748, 13.3613, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkingmeterg
    SetDynamicObjectMaterial(object_lspdExterior[407], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
    object_lspdExterior[408] = CreateDynamicObject(19377, 955.4301, -1604.9707, 25.9158, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[408], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[409] = CreateDynamicObject(1270, 939.6334, -1619.9654, 13.3613, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkingmeterg
    SetDynamicObjectMaterial(object_lspdExterior[409], 1, 16640, "a51", "redmetal", 0xFFFFFFFF);
    object_lspdExterior[410] = CreateDynamicObject(19377, 965.0595, -1604.9707, 25.9158, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[410], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[411] = CreateDynamicObject(19377, 973.3087, -1604.9707, 25.9358, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[411], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[412] = CreateDynamicObject(19377, 973.3087, -1605.1003, 25.9258, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[412], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[413] = CreateDynamicObject(19377, 963.7293, -1605.1003, 25.9258, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[413], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[414] = CreateDynamicObject(19377, 955.4387, -1605.1003, 25.9158, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[414], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_lspdExterior[415] = CreateDynamicObject(18981, 966.5106, -1594.7486, 12.0986, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[415], 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0xFFFFFFFF);
    object_lspdExterior[416] = CreateDynamicObject(968, 946.6951, -1625.8210, 13.4181, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //barrierturn
    object_lspdExterior[417] = CreateDynamicObject(966, 946.5313, -1625.8183, 12.5670, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebar01
    object_lspdExterior[418] = CreateDynamicObject(19461, 932.6290, -1625.8973, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[418], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[419] = CreateDynamicObject(1237, 947.8942, -1625.9033, 12.4586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_lspdExterior[420] = CreateDynamicObject(19461, 953.6491, -1625.8571, 11.5686, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[420], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[421] = CreateDynamicObject(1237, 938.4332, -1625.9033, 12.4586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //strtbarrier01
    object_lspdExterior[422] = CreateDynamicObject(19466, 966.7210, -1599.7425, 18.8491, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_lspdExterior[422], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_lspdExterior[423] = CreateDynamicObject(18981, 939.8906, -1607.6700, 12.1090, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[423], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_lspdExterior[424] = CreateDynamicObject(19461, 953.1204, -1662.3321, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[424], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[425] = CreateDynamicObject(19461, 954.1306, -1662.3360, 11.5686, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[425], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[426] = CreateDynamicObject(19461, 933.1492, -1662.3360, 11.5684, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[426], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[427] = CreateDynamicObject(19461, 932.2199, -1662.3320, 11.5585, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[427], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[428] = CreateDynamicObject(19461, 948.3895, -1656.3808, 8.4883, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[428], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[429] = CreateDynamicObject(19461, 937.8792, -1656.3808, 8.4883, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[429], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[430] = CreateDynamicObject(19461, 937.8792, -1659.8814, 8.4883, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[430], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[431] = CreateDynamicObject(19461, 937.8795, -1660.6123, 8.4885, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[431], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[432] = CreateDynamicObject(19461, 948.3895, -1659.8830, 8.4883, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[432], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[433] = CreateDynamicObject(19461, 948.3900, -1660.5937, 8.4885, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[433], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[434] = CreateDynamicObject(19377, 943.1533, -1657.5871, 12.4631, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[434], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[435] = CreateDynamicObject(19461, 958.8510, -1667.0644, 11.5684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[435], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[436] = CreateDynamicObject(19461, 958.8510, -1676.6954, 11.5684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[436], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[437] = CreateDynamicObject(19461, 958.8515, -1682.5156, 11.5684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[437], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[438] = CreateDynamicObject(19461, 927.3300, -1667.0644, 11.5684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[438], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[439] = CreateDynamicObject(19461, 927.3305, -1676.6954, 11.5686, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[439], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[440] = CreateDynamicObject(19461, 927.3300, -1682.5156, 11.5684, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[440], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[441] = CreateDynamicObject(19461, 932.2199, -1687.2426, 11.5585, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[441], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[442] = CreateDynamicObject(19461, 941.8499, -1687.2426, 11.5585, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[442], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[443] = CreateDynamicObject(19461, 951.4896, -1687.2426, 11.5585, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[443], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[444] = CreateDynamicObject(19461, 954.1203, -1687.2469, 11.5579, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall101
    SetDynamicObjectMaterial(object_lspdExterior[444], 0, 7088, "casinoshops1", "fakestone1_LA", 0xFFFFFFFF);
    object_lspdExterior[445] = CreateDynamicObject(19377, 943.1533, -1667.2065, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[445], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[446] = CreateDynamicObject(19377, 943.1533, -1676.8355, 12.4631, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[446], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[447] = CreateDynamicObject(19377, 943.1533, -1682.4173, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[447], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[448] = CreateDynamicObject(19377, 953.6541, -1682.4173, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[448], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[449] = CreateDynamicObject(19377, 953.6541, -1672.8078, 12.4638, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[449], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[450] = CreateDynamicObject(19377, 953.6541, -1667.1179, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[450], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[451] = CreateDynamicObject(19377, 932.6442, -1667.1179, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[451], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[452] = CreateDynamicObject(19377, 932.6442, -1682.3487, 12.4637, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[452], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[453] = CreateDynamicObject(19377, 932.6442, -1672.7464, 12.4638, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
    SetDynamicObjectMaterial(object_lspdExterior[453], 0, 16640, "a51", "concretemanky", 0xFF58595A);
    object_lspdExterior[454] = CreateDynamicObject(19464, 955.8228, -1662.4663, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[454], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[455] = CreateDynamicObject(19464, 955.8228, -1687.1086, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[455], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[456] = CreateDynamicObject(19464, 955.8228, -1677.5168, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[456], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[457] = CreateDynamicObject(19464, 955.8228, -1682.4184, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[457], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[458] = CreateDynamicObject(19464, 955.8228, -1667.3774, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[458], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[459] = CreateDynamicObject(19464, 955.8228, -1672.4577, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[459], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[460] = CreateDynamicObject(19464, 958.6735, -1665.3681, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[460], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[461] = CreateDynamicObject(19464, 958.6740, -1671.2989, 10.0143, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[461], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[462] = CreateDynamicObject(19464, 958.6735, -1684.2126, 10.0143, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[462], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[463] = CreateDynamicObject(19464, 958.6743, -1678.2818, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[463], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[464] = CreateDynamicObject(19464, 958.6735, -1675.6750, 10.0150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[464], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[465] = CreateDynamicObject(19464, 930.2827, -1662.4663, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[465], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[466] = CreateDynamicObject(19464, 930.2827, -1667.3774, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[466], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[467] = CreateDynamicObject(19464, 930.2827, -1672.4577, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[467], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[468] = CreateDynamicObject(19464, 930.2827, -1677.5168, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[468], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[469] = CreateDynamicObject(19464, 930.2827, -1682.4184, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[469], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[470] = CreateDynamicObject(19464, 930.2827, -1687.1086, 10.0045, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[470], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[471] = CreateDynamicObject(19464, 927.5031, -1665.3681, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[471], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[472] = CreateDynamicObject(19464, 927.5034, -1671.2989, 10.0143, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[472], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[473] = CreateDynamicObject(19464, 927.5031, -1675.6750, 10.0150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[473], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[474] = CreateDynamicObject(19464, 927.5034, -1681.5915, 10.0148, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[474], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[475] = CreateDynamicObject(19464, 927.5031, -1684.2126, 10.0143, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[475], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_lspdExterior[476] = CreateDynamicObject(1290, 943.1049, -1679.7683, 18.3337, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_lspdExterior[477] = CreateDynamicObject(1290, 943.1049, -1669.5678, 18.3337, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
    object_lspdExterior[478] = CreateDynamicObject(974, 955.5245, -1625.8979, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[478], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[478], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[479] = CreateDynamicObject(974, 952.2246, -1625.8979, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[479], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[479], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[480] = CreateDynamicObject(974, 930.6232, -1654.7165, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[480], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[480], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[481] = CreateDynamicObject(974, 930.6232, -1662.3265, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[481], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[481], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[482] = CreateDynamicObject(974, 930.6232, -1687.2374, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[482], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[482], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[483] = CreateDynamicObject(974, 955.5036, -1662.3265, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[483], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[483], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[484] = CreateDynamicObject(974, 955.5036, -1654.7263, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[484], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[484], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[485] = CreateDynamicObject(974, 955.5036, -1687.2358, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[485], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[485], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[486] = CreateDynamicObject(974, 948.8032, -1687.2358, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[486], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[486], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[487] = CreateDynamicObject(974, 943.9436, -1687.2358, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[487], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[487], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[488] = CreateDynamicObject(974, 937.2733, -1687.2358, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[488], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[488], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[489] = CreateDynamicObject(974, 934.5336, -1662.3265, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[489], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[489], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[490] = CreateDynamicObject(974, 951.6831, -1654.7263, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[490], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[490], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[491] = CreateDynamicObject(974, 948.3820, -1658.9870, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[491], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[491], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[492] = CreateDynamicObject(974, 934.5825, -1654.7263, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[492], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[492], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[493] = CreateDynamicObject(974, 937.8820, -1658.0664, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[493], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[493], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[494] = CreateDynamicObject(974, 937.8820, -1659.0072, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[494], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[494], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[495] = CreateDynamicObject(974, 951.6840, -1662.3265, 13.1493, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[495], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[495], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[496] = CreateDynamicObject(974, 948.3723, -1658.0664, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[496], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[496], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[497] = CreateDynamicObject(974, 927.3222, -1665.6960, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[497], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[497], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[498] = CreateDynamicObject(974, 927.3222, -1672.3763, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[498], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[498], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[499] = CreateDynamicObject(974, 927.3222, -1678.9952, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[499], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[499], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[500] = CreateDynamicObject(974, 927.3222, -1683.9366, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[500], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[500], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[501] = CreateDynamicObject(974, 958.8731, -1683.9366, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[501], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[501], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[502] = CreateDynamicObject(974, 958.8731, -1665.6760, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[502], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[502], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[503] = CreateDynamicObject(974, 958.8731, -1672.3957, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[503], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[503], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[504] = CreateDynamicObject(974, 958.8731, -1679.0958, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[504], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[504], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[505] = CreateDynamicObject(974, 958.8731, -1651.3648, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[505], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[505], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[506] = CreateDynamicObject(974, 958.8731, -1644.6544, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[506], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[506], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[507] = CreateDynamicObject(974, 958.8731, -1637.9637, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[507], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[507], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[508] = CreateDynamicObject(974, 958.8731, -1631.2635, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[508], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[508], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[509] = CreateDynamicObject(974, 927.3131, -1629.1925, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[509], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[509], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[510] = CreateDynamicObject(974, 958.8731, -1629.1925, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[510], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[510], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[511] = CreateDynamicObject(974, 927.3134, -1631.2635, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[511], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[511], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[512] = CreateDynamicObject(974, 927.3134, -1637.9831, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[512], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[512], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[513] = CreateDynamicObject(974, 927.3134, -1644.6833, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[513], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[513], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[514] = CreateDynamicObject(974, 927.3134, -1651.3636, 13.1493, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tall_fence
    SetDynamicObjectMaterial(object_lspdExterior[514], 0, 3080, "adjumpx", "gen_chrome", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_lspdExterior[514], 1, 16322, "a51_stores", "fence_64", 0xFFFFFFFF);
    object_lspdExterior[515] = CreateDynamicObject(18981, 939.8906, -1598.6888, 12.1070, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[515], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[516] = CreateDynamicObject(18981, 939.8906, -1607.6700, 12.1070, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[516], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[517] = CreateDynamicObject(19464, 941.5460, -1601.8365, 21.3838, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[517], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[518] = CreateDynamicObject(19464, 941.5460, -1607.3498, 21.3938, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[518], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[519] = CreateDynamicObject(19464, 948.0769, -1607.3470, 21.3437, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[519], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[520] = CreateDynamicObject(19464, 948.0769, -1601.8365, 21.3537, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_lspdExterior[520], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[521] = CreateDynamicObject(18981, 939.8906, -1598.6888, 12.1070, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[521], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_lspdExterior[522] = CreateDynamicObject(18981, 939.8906, -1607.6700, 12.1070, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_lspdExterior[522], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);

    object_lspdExterior_barrier = object_lspdExterior[416];
}