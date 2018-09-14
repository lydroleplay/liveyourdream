#include <YSI\y_hooks>

// Global interior define
#define MAPS_POOEXTERIOR_INTERIOR      0
#define MAPS_POOINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// POO points
#define POO_INTERIOR_ENTER_COORDS		1940.9537, -2031.6035, 13.6589
#define POO_INTERIOR_EXIT_COORDS		1932.5820, -2002.2120, 823.4130
#define POO_INTERIOR_ENTER_FACING		332.4775
#define POO_INTERIOR_EXIT_FACING   	    239.3597
#define POO_STATEREPAIR_COORDS			1930.7341, -2026.2643, 13.6586

// Map variables
new object_pooExterior[297];
new pickup_pooExterior[2];
new text3D_pooExterior[1];
new vehicle_pooExterior[20];

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 4978, 1940.1875, -2007.3047, 15.3359, 0.25);
    RemoveBuildingForPlayer(playerid, 4979, 1942.6797, -1986.7500, 14.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1531, 1950.6172, -2034.3984, 14.0938, 0.25);
    RemoveBuildingForPlayer(playerid, 4850, 1940.1875, -2007.3047, 15.3359, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1936.2578, -1999.3828, 16.3438, 0.25);
    RemoveBuildingForPlayer(playerid, 4857, 1942.6797, -1986.7500, 14.8984, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1957.3359, -1982.3984, 16.3828, 0.25);
    // TODO: peek remove old poo exterior hangars, so towed vehicles can still spawn on the old base

	// Map Icon
    SetPlayerMapIcon(playerid, 32, POO_INTERIOR_ENTER_COORDS, 11, 0, 0);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys == KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, POO_INTERIOR_ENTER_COORDS)) { // Entrance
			SetPlayerFacingAngle(playerid, POO_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, POO_INTERIOR_EXIT_COORDS + 0.5, MAPS_POOINTERIOR_INTERIOR, VW_POOINTERIOR);
			return 1;
		}
	}

	return 1;
}

hook OnGameModeInit() {
	// Pickups
	pickup_pooExterior[0] = CreateDynamicPickup(19197, 1, POO_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR); // Entrance
    pickup_pooExterior[1] = CreateDynamicPickup(1239, 1, POO_STATEREPAIR_COORDS, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR); // Staterepair
    
    // 3DTextLabels
    text3D_pooExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, POO_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_POOEXTERIOR_INTERIOR); // Staterepair

	// Vehicles
	vehicle_pooExterior[0] = AddStaticVehicleEx(599, 926.3336, -1286.4506, 14.4465, 91.0184, 158, 8, -1);
    vehicle_pooExterior[1] = AddStaticVehicleEx(487, 1941.9177, -2038.4310, 21.4681, 1.1817, 158, 158, -1);
    vehicle_pooExterior[2] = AddStaticVehicleEx(599, 1939.1571, -2018.3842, 13.8958, 180.0897, 158, 8, -1);
    vehicle_pooExterior[3] = AddStaticVehicleEx(599, 1935.4164, -2018.4231, 13.8964, 180.1137, 158, 8, -1);
    vehicle_pooExterior[4] = AddStaticVehicleEx(598, 1931.8282, -2018.5294, 13.4154, 180.1284, 158, 8, -1);
    vehicle_pooExterior[5] = AddStaticVehicleEx(598, 1927.9823, -2018.4670, 13.4384, 179.7811, 158, 8, -1);
    vehicle_pooExterior[6] = AddStaticVehicleEx(426, 1928.0767, -2012.4497, 13.4215, 359.8296, 158, 158, -1);
    vehicle_pooExterior[7] = AddStaticVehicleEx(426, 1931.8129, -2012.4203, 13.4234, 0.3709, 158, 158, -1);
    vehicle_pooExterior[8] = AddStaticVehicleEx(560, 1935.4600, -2012.7880, 13.3687, 359.3246, 158, 158, -1);
    vehicle_pooExterior[9] = AddStaticVehicleEx(560, 1939.1714, -2012.7667, 13.3612, 0.1307, 158,  158, -1);
    vehicle_pooExterior[10] = AddStaticVehicleEx(525, 1939.2173, -2000.0000, 13.5433, 179.1260, 8, 158, -1);
    vehicle_pooExterior[11] = AddStaticVehicleEx(525, 1935.5348, -2000.0933, 13.5318, 180.2231, 8, 158, -1);
    vehicle_pooExterior[12] = AddStaticVehicleEx(525, 1931.8230, -2000.1855, 13.5318, 180.2053, 8, 158, -1);
    vehicle_pooExterior[13] = AddStaticVehicleEx(525, 1928.0831, -2000.1741, 13.5356, 180.4330, 8, 158, -1);
    vehicle_pooExterior[14] = AddStaticVehicleEx(525, 1928.0310, -1993.6702, 13.5356, 0.0585, 8, 158, -1);
    vehicle_pooExterior[15] = AddStaticVehicleEx(525, 1931.7048, -1993.7336, 13.5317, 0.0398, 8, 158, -1);
    vehicle_pooExterior[16] = AddStaticVehicleEx(525, 1935.5032, -1993.5992, 13.5295, 359.5856, 8, 158, -1);
    vehicle_pooExterior[17] = AddStaticVehicleEx(525, 1939.2357, -1993.5378, 13.5433, 359.6217, 8, 158, -1);
    vehicle_pooExterior[18] = AddStaticVehicleEx(461, 1949.1188, -2038.0056, 13.2458, 0.6688, 158, 8, -1);
    vehicle_pooExterior[19] = AddStaticVehicleEx(461, 1945.7896, -2037.8665, 13.2437, 359.0446, 158, 8, -1);

	// Objects
	object_pooExterior[0] = CreateDynamicObject(18762, 1951.2010, -2040.0041, 13.0562, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[0], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[1] = CreateDynamicObject(18762, 1949.1910, -2042.0255, 13.0565, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[1], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[2] = CreateDynamicObject(18762, 1944.2009, -2042.0255, 13.0565, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[2], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[3] = CreateDynamicObject(18762, 1939.1997, -2042.0255, 13.0565, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[3], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[4] = CreateDynamicObject(18762, 1934.2093, -2042.0255, 13.0565, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[4], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[5] = CreateDynamicObject(18762, 1931.4177, -2042.0200, 13.0562, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[5], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[6] = CreateDynamicObject(18762, 1925.6949, -2040.0206, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[6], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[7] = CreateDynamicObject(18762, 1925.6955, -2035.0301, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[7], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[8] = CreateDynamicObject(18762, 1925.6949, -2030.0301, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[8], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[9] = CreateDynamicObject(18762, 1925.6955, -2025.0400, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[9], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[10] = CreateDynamicObject(18762, 1925.6949, -2020.0394, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[10], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[11] = CreateDynamicObject(18762, 1925.6955, -2015.0389, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[11], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[12] = CreateDynamicObject(18762, 1925.6949, -2010.0483, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[12], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[13] = CreateDynamicObject(18762, 1925.6955, -2005.0583, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[13], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[14] = CreateDynamicObject(18762, 1925.6949, -2000.0670, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[14], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[15] = CreateDynamicObject(18762, 1925.6955, -1995.0664, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[15], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[16] = CreateDynamicObject(18762, 1925.6949, -1990.0664, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[16], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[17] = CreateDynamicObject(18762, 1925.6955, -1985.0766, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[17], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[18] = CreateDynamicObject(18762, 1925.6949, -1980.0843, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[18], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[19] = CreateDynamicObject(18762, 1931.4873, -1978.0837, 13.0562, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[19], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[20] = CreateDynamicObject(18762, 1936.4881, -1978.0837, 13.0562, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[20], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[21] = CreateDynamicObject(18762, 1941.4796, -1978.0837, 13.0562, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[21], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[22] = CreateDynamicObject(18762, 1946.4787, -1978.0837, 13.0562, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[22], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[23] = CreateDynamicObject(18762, 1949.1910, -1978.0853, 13.0565, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[23], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[24] = CreateDynamicObject(18762, 1951.2010, -2035.0040, 13.0562, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[24], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[25] = CreateDynamicObject(18762, 1951.2010, -2030.4343, 13.0562, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[25], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[26] = CreateDynamicObject(18762, 1951.2010, -2015.4918, 13.0562, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[26], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[27] = CreateDynamicObject(18762, 1951.2010, -2010.8623, 13.0562, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[27], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[28] = CreateDynamicObject(18762, 1951.2010, -2005.8614, 13.0562, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[28], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[29] = CreateDynamicObject(18762, 1951.2010, -2000.8602, 13.0562, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[29], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[30] = CreateDynamicObject(18762, 1951.2010, -1995.8708, 13.0562, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[30], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[31] = CreateDynamicObject(18762, 1951.2015, -1991.6722, 13.0565, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[31], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[32] = CreateDynamicObject(18762, 1951.1888, -1978.9099, 11.0570, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[32], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[33] = CreateDynamicObject(19604, 1948.3116, -1998.6230, 12.7065, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    object_pooExterior[34] = CreateDynamicObject(19464, 1945.8779, -2004.7259, 10.1625, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[34], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[35] = CreateDynamicObject(19464, 1945.8774, -2010.6617, 10.1619, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[35], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[36] = CreateDynamicObject(19604, 1948.3116, -2008.6197, 12.7065, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //WaterPlane2
    object_pooExterior[37] = CreateDynamicObject(19464, 1945.8774, -1998.8520, 10.1619, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[37], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[38] = CreateDynamicObject(19464, 1945.8779, -1996.5345, 10.1625, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[38], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[39] = CreateDynamicObject(19464, 1948.7176, -1993.6729, 10.1630, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[39], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[40] = CreateDynamicObject(19430, 1951.4260, -2018.0067, 10.9317, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_pooExterior[40], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[41] = CreateDynamicObject(19464, 1948.5487, -2000.7967, 12.5874, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[41], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    object_pooExterior[42] = CreateDynamicObject(19464, 1948.5487, -2005.9068, 12.5880, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[42], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    object_pooExterior[43] = CreateDynamicObject(19464, 1948.7176, -2008.9941, 10.1630, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[43], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[44] = CreateDynamicObject(19464, 1948.7176, -1997.7032, 10.1630, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[44], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[45] = CreateDynamicObject(19464, 1950.5592, -2010.6617, 10.1619, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[45], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[46] = CreateDynamicObject(19464, 1950.5592, -1996.6002, 10.1619, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[46], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[47] = CreateDynamicObject(18766, 1948.3385, -2003.1794, 11.2631, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[47], 0, 14593, "papaerchaseoffice", "wall_stone6_256", 0xFFFFFFFF);
    object_pooExterior[48] = CreateDynamicObject(19464, 1948.3673, -2004.4256, 13.7524, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[48], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[49] = CreateDynamicObject(19464, 1948.3675, -2002.1400, 13.7523, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[49], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[50] = CreateDynamicObject(18762, 1948.3260, -1998.6687, 14.6288, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[50], 0, 14593, "papaerchaseoffice", "wall_stone6_256", 0xFFFFFFFF);
    object_pooExterior[51] = CreateDynamicObject(18762, 1948.3260, -2007.6893, 14.6288, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[51], 0, 14593, "papaerchaseoffice", "wall_stone6_256", 0xFFFFFFFF);
    object_pooExterior[52] = CreateDynamicObject(18762, 1948.3270, -2005.6649, 16.6389, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[52], 0, 14593, "papaerchaseoffice", "wall_stone6_256", 0xFFFFFFFF);
    object_pooExterior[53] = CreateDynamicObject(18762, 1948.3266, -2000.7740, 16.6389, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[53], 0, 14593, "papaerchaseoffice", "wall_stone6_256", 0xFFFFFFFF);
    object_pooExterior[54] = CreateDynamicObject(19175, 1948.5421, -2004.4836, 14.9502, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[54], 0, "Los Santos", 90, "Arial", 50, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[54], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[55] = CreateDynamicObject(19175, 1948.5421, -2001.8242, 14.8702, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[55], 0, "________________________________________", 90, "Arial", 52, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[55], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[56] = CreateDynamicObject(19175, 1948.5421, -2001.8331, 14.9202, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[56], 0, "Ordnungsamt", 90, "Arial", 45, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[56], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[57] = CreateDynamicObject(19175, 1948.5416, -2004.5047, 14.8702, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[57], 0, "________________________________________", 90, "Arial", 52, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[57], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[58] = CreateDynamicObject(19175, 1948.5421, -2004.3033, 14.2601, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[58], 0, "rekrutiert", 90, "Arial", 40, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[58], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[59] = CreateDynamicObject(19791, 1946.6801, -1983.5045, 2.6594, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[59], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[60] = CreateDynamicObject(19175, 1948.5421, -2003.8127, 13.8302, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[60], 0, "neue", 90, "Arial", 40, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[60], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[61] = CreateDynamicObject(19175, 1948.5421, -2002.1319, 13.9902, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[61], 0, "Ordnungshüter", 90, "Arial", 40, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[61], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[62] = CreateDynamicObject(19791, 1946.6801, -1993.5036, 2.6594, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[62], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[63] = CreateDynamicObject(19791, 1946.6801, -2003.4825, 2.6594, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[63], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[64] = CreateDynamicObject(19791, 1946.6801, -2013.4809, 2.6594, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[64], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[65] = CreateDynamicObject(19791, 1946.6801, -2023.4704, 2.6594, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[65], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[66] = CreateDynamicObject(19791, 1946.6801, -2033.4709, 2.6594, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[66], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[67] = CreateDynamicObject(19791, 1946.6805, -2036.7231, 2.6589, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[67], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[68] = CreateDynamicObject(19791, 1936.6822, -2036.7231, 2.6589, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[68], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[69] = CreateDynamicObject(19791, 1936.6822, -2026.7231, 2.6589, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[69], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[70] = CreateDynamicObject(19791, 1936.6822, -2016.7337, 2.6589, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[70], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[71] = CreateDynamicObject(19791, 1936.6822, -2006.7336, 2.6589, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[71], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[72] = CreateDynamicObject(19791, 1936.6822, -1996.7452, 2.6589, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[72], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[73] = CreateDynamicObject(19791, 1936.6822, -1986.7447, 2.6589, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[73], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[74] = CreateDynamicObject(19791, 1936.6822, -1982.9934, 2.6593, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[74], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[75] = CreateDynamicObject(19791, 1931.1407, -1982.9934, 2.6586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[75], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[76] = CreateDynamicObject(19791, 1930.9110, -1992.9930, 2.6586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[76], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[77] = CreateDynamicObject(19791, 1930.9400, -2002.9832, 2.6586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[77], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[78] = CreateDynamicObject(19791, 1931.0993, -2012.9831, 2.6586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[78], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[79] = CreateDynamicObject(19791, 1931.0213, -2022.9831, 2.6586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[79], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[80] = CreateDynamicObject(19791, 1931.0506, -2032.9830, 2.6586, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[80], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[81] = CreateDynamicObject(19791, 1931.0609, -2036.5649, 2.6593, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[81], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[82] = CreateDynamicObject(19791, 1954.4201, -1984.3347, 1.8250, 0.0000, 12.2999, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[82], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[83] = CreateDynamicObject(19791, 1954.4201, -2022.9251, 1.8250, 0.0000, 12.2999, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Cube10mx10m
    SetDynamicObjectMaterial(object_pooExterior[83], 0, 4835, "airoads_las", "concretenewb256", 0xFF9CA1A3);
    object_pooExterior[84] = CreateDynamicObject(19464, 1948.7176, -2013.5240, 10.1630, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[84], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[85] = CreateDynamicObject(19430, 1951.4260, -1979.4355, 10.9317, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_pooExterior[85], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[86] = CreateDynamicObject(19430, 1950.6954, -1978.7148, 10.9317, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_pooExterior[86], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[87] = CreateDynamicObject(19430, 1951.4260, -2027.8366, 10.9317, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_pooExterior[87], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[88] = CreateDynamicObject(19464, 1947.8481, -1978.6014, 10.1229, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[88], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[89] = CreateDynamicObject(19464, 1941.9475, -1978.6059, 10.1224, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[89], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[90] = CreateDynamicObject(19464, 1936.0688, -1978.6014, 10.1229, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[90], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[91] = CreateDynamicObject(19464, 1932.2072, -1978.6059, 10.1224, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[91], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[92] = CreateDynamicObject(19464, 1929.7955, -1980.5855, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[92], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[93] = CreateDynamicObject(19464, 1926.2180, -1987.3813, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[93], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[94] = CreateDynamicObject(19464, 1926.2185, -1993.2407, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[94], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[95] = CreateDynamicObject(19464, 1929.1148, -1997.1208, 10.1215, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[95], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[96] = CreateDynamicObject(19464, 1928.9377, -1978.6014, 10.1233, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[96], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[97] = CreateDynamicObject(19464, 1929.9255, -2000.1555, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[97], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[98] = CreateDynamicObject(19464, 1929.9261, -1994.2448, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[98], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[99] = CreateDynamicObject(19464, 1929.1148, -2015.4925, 10.1215, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[99], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[100] = CreateDynamicObject(19464, 1929.9255, -2012.5543, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[100], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[101] = CreateDynamicObject(19464, 1929.9255, -2018.4742, 10.1232, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[101], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[102] = CreateDynamicObject(19464, 1929.1964, -2031.8912, 13.9823, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[102], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[103] = CreateDynamicObject(19464, 1950.7203, -1992.0396, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[103], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[104] = CreateDynamicObject(19464, 1950.7203, -2015.1313, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[104], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[105] = CreateDynamicObject(19430, 1951.4260, -1989.1662, 10.9317, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_pooExterior[105], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[106] = CreateDynamicObject(19464, 1950.7203, -2030.7126, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[106], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[107] = CreateDynamicObject(19464, 1950.7208, -2036.0217, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[107], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[108] = CreateDynamicObject(19464, 1950.7203, -2038.7141, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[108], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[109] = CreateDynamicObject(19464, 1932.2072, -2041.5163, 10.1224, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[109], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[110] = CreateDynamicObject(19464, 1938.0567, -2041.5108, 10.1218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[110], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[111] = CreateDynamicObject(19464, 1943.9666, -2041.5163, 10.1224, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[111], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[112] = CreateDynamicObject(19464, 1948.0678, -2041.5108, 10.1218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[112], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[113] = CreateDynamicObject(19464, 1933.7165, -1980.5855, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[113], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[114] = CreateDynamicObject(19464, 1937.4072, -1980.5855, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[114], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[115] = CreateDynamicObject(19464, 1941.1379, -1980.5855, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[115], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[116] = CreateDynamicObject(19464, 1941.1379, -1994.2448, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[116], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[117] = CreateDynamicObject(19464, 1937.3377, -1994.2448, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[117], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[118] = CreateDynamicObject(19464, 1933.6971, -1994.2448, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[118], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[119] = CreateDynamicObject(19464, 1932.9265, -1997.1259, 10.1218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[119], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[120] = CreateDynamicObject(19464, 1938.2965, -1997.1208, 10.1215, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[120], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[121] = CreateDynamicObject(19464, 1941.1379, -2000.1555, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[121], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[122] = CreateDynamicObject(19464, 1937.3371, -2000.1555, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[122], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[123] = CreateDynamicObject(19464, 1933.7052, -2000.1555, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[123], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[124] = CreateDynamicObject(19464, 1933.7052, -2012.6350, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[124], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[125] = CreateDynamicObject(19464, 1937.2769, -2012.6350, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[125], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[126] = CreateDynamicObject(19464, 1941.0986, -2012.6350, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[126], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[127] = CreateDynamicObject(19464, 1938.2563, -2015.4914, 10.1215, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[127], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[128] = CreateDynamicObject(19464, 1932.9060, -2015.4914, 10.1218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[128], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[129] = CreateDynamicObject(19464, 1933.7052, -2018.5251, 10.1230, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[129], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[130] = CreateDynamicObject(19464, 1937.2652, -2018.5251, 10.1230, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[130], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[131] = CreateDynamicObject(19464, 1941.0970, -2018.5251, 10.1230, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[131], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[132] = CreateDynamicObject(19464, 1945.0278, -1980.5855, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[132], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[133] = CreateDynamicObject(19464, 1947.4897, -1981.7066, 10.1230, 0.0000, 0.0000, 125.9999, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[133], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[134] = CreateDynamicObject(19464, 1948.4610, -1981.0019, 10.1233, 0.0000, 0.0000, 125.9999, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[134], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[135] = CreateDynamicObject(18762, 1927.7081, -2042.0255, 13.0565, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[135], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[136] = CreateDynamicObject(18762, 1927.7662, -1978.0870, 13.0565, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[136], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[137] = CreateDynamicObject(19464, 1929.0068, -2041.5108, 10.1218, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[137], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[138] = CreateDynamicObject(19464, 1926.2185, -1981.4621, 10.1218, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[138], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[139] = CreateDynamicObject(19464, 1926.2180, -1999.1108, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[139], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[140] = CreateDynamicObject(19464, 1926.2185, -2004.8499, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[140], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[141] = CreateDynamicObject(19464, 1926.2180, -2010.6717, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[141], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[142] = CreateDynamicObject(19464, 1926.2185, -2016.6097, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[142], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[143] = CreateDynamicObject(19464, 1926.2180, -2022.5113, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[143], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[144] = CreateDynamicObject(19464, 1926.2185, -2028.2901, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[144], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[145] = CreateDynamicObject(19464, 1926.2180, -2034.1314, 10.1224, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[145], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[146] = CreateDynamicObject(19464, 1926.2185, -2038.5908, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[146], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[147] = CreateDynamicObject(19464, 1932.0279, -2033.2312, 15.1124, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[147], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[148] = CreateDynamicObject(19466, 1929.0083, -2031.7622, 14.6030, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[148], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[149] = CreateDynamicObject(19464, 1934.8973, -2030.3902, 15.1124, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[149], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[150] = CreateDynamicObject(19466, 1934.7878, -2030.2524, 16.3031, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[150], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[151] = CreateDynamicObject(19466, 1934.7878, -2030.2524, 14.3631, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[151], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[152] = CreateDynamicObject(19464, 1937.7578, -2033.2312, 15.1124, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[152], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[153] = CreateDynamicObject(19450, 1940.5655, -2032.3236, 12.8177, 90.0000, -29.8999, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_pooExterior[153], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[154] = CreateDynamicObject(19450, 1937.3513, -2031.4392, 12.8177, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_pooExterior[154], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[155] = CreateDynamicObject(19450, 1942.0467, -2034.8840, 12.8177, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_pooExterior[155], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[156] = CreateDynamicObject(19464, 1941.1451, -2033.7999, 15.1124, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[156], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[157] = CreateDynamicObject(19464, 1943.9957, -2036.6801, 15.1124, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[157], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[158] = CreateDynamicObject(19466, 1944.1379, -2035.8719, 14.3631, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[158], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[159] = CreateDynamicObject(19466, 1944.1379, -2035.8719, 16.3031, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[159], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[160] = CreateDynamicObject(19464, 1943.9952, -2038.5617, 15.1120, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[160], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[161] = CreateDynamicObject(19466, 1944.1379, -2039.2425, 14.3631, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[161], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[162] = CreateDynamicObject(19466, 1944.1379, -2039.2425, 16.3031, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[162], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[163] = CreateDynamicObject(19464, 1941.1451, -2041.4101, 15.1124, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[163], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[164] = CreateDynamicObject(19464, 1935.2154, -2041.4101, 15.1124, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[164], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[165] = CreateDynamicObject(19464, 1932.0273, -2038.5515, 15.1124, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[165], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[166] = CreateDynamicObject(19464, 1934.8747, -2041.4150, 15.1120, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[166], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[167] = CreateDynamicObject(19464, 1929.1964, -2041.4122, 13.9823, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[167], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[168] = CreateDynamicObject(19464, 1926.2957, -2038.5620, 13.9823, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[168], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[169] = CreateDynamicObject(19464, 1926.2951, -2034.7518, 13.9820, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[169], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[170] = CreateDynamicObject(19466, 1941.6080, -2041.5426, 16.3031, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[170], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[171] = CreateDynamicObject(19466, 1934.3581, -2041.5526, 16.3031, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[171], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[172] = CreateDynamicObject(19466, 1937.9384, -2041.5526, 16.3031, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[172], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[173] = CreateDynamicObject(19466, 1937.9384, -2041.5468, 15.0331, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[173], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[174] = CreateDynamicObject(19466, 1941.6091, -2041.5468, 15.0331, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[174], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[175] = CreateDynamicObject(19466, 1934.3684, -2041.5468, 15.0331, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[175], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[176] = CreateDynamicObject(19466, 1929.0781, -2041.5467, 15.0331, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[176], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[177] = CreateDynamicObject(19466, 1926.1667, -2034.4066, 15.0331, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[177], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[178] = CreateDynamicObject(19466, 1926.1667, -2038.6573, 15.0331, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[178], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[179] = CreateDynamicObject(1522, 1939.9162, -2031.9200, 12.5529, 0.0000, 0.0000, -29.8999, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_pooExterior[179], 0, 11008, "firehouse_sfse", "halldoor01_law", 0xFFFFFFFF);
    object_pooExterior[180] = CreateDynamicObject(19464, 1934.8968, -2038.9814, 17.5415, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[180], 0, 3629, "arprtxxref_las", "corrRoof_64HV", 0xFFFFFFFF);
    object_pooExterior[181] = CreateDynamicObject(19464, 1940.6474, -2032.8280, 17.5405, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[181], 0, 3820, "boxhses_sfsx", "tanboard1", 0xFFFFFFFF);
    object_pooExterior[182] = CreateDynamicObject(19464, 1941.1479, -2038.9814, 17.5419, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[182], 0, 3629, "arprtxxref_las", "corrRoof_64HV", 0xFFFFFFFF);
    object_pooExterior[183] = CreateDynamicObject(19464, 1938.9571, -2032.8249, 17.5428, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[183], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[184] = CreateDynamicObject(19464, 1935.1971, -2037.9306, 17.5424, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[184], 0, 3629, "arprtxxref_las", "corrRoof_64HV", 0xFFFFFFFF);
    object_pooExterior[185] = CreateDynamicObject(19464, 1935.1971, -2038.9814, 17.5419, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[185], 0, 3629, "arprtxxref_las", "corrRoof_64HV", 0xFFFFFFFF);
    object_pooExterior[186] = CreateDynamicObject(19464, 1941.1379, -2037.9306, 17.5424, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[186], 0, 3629, "arprtxxref_las", "corrRoof_64HV", 0xFFFFFFFF);
    object_pooExterior[187] = CreateDynamicObject(19464, 1929.1964, -2034.3232, 16.4123, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[187], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[188] = CreateDynamicObject(19464, 1929.1964, -2038.9746, 16.4120, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[188], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[189] = CreateDynamicObject(19464, 1947.3901, -2038.7141, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[189], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[190] = CreateDynamicObject(19464, 1944.0892, -2038.7141, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[190], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[191] = CreateDynamicObject(19952, 1941.1419, -1997.1435, 12.0960, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[191], 2, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_pooExterior[192] = CreateDynamicObject(19952, 1941.1419, -2015.4757, 12.0960, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[192], 2, 10765, "airportgnd_sfse", "white", 0xFFD78E10);
    object_pooExterior[193] = CreateDynamicObject(19175, 1941.1523, -2014.3635, 14.2902, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[193], 0, "Block", 130, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[193], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[194] = CreateDynamicObject(19175, 1941.1523, -1996.0230, 14.2902, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[194], 0, "Block", 130, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[194], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[195] = CreateDynamicObject(19175, 1941.1523, -1995.8830, 14.0402, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[195], 0, "B", 130, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[195], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[196] = CreateDynamicObject(19175, 1941.1523, -2014.2844, 14.0502, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[196], 0, "c", 130, "Webdings", 63, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[196], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[197] = CreateDynamicObject(19175, 1941.1523, -2014.2143, 14.0402, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[197], 0, "A", 130, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[197], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[198] = CreateDynamicObject(19175, 1941.1523, -1995.9530, 14.0502, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[198], 0, "c", 130, "Webdings", 63, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[198], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[199] = CreateDynamicObject(19464, 1934.9039, -2033.7685, 17.7422, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[199], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[200] = CreateDynamicObject(3498, 1943.3088, -2030.9350, 13.0690, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wdpillar01_lvs
    SetDynamicObjectMaterial(object_pooExterior[200], 1, 1355, "break_s_bins", "marble1", 0xFF58595A);
    object_pooExterior[201] = CreateDynamicObject(19464, 1940.0832, -2033.7629, 17.7413, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[201], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[202] = CreateDynamicObject(19464, 1941.1379, -2032.8208, 17.5424, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[202], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[203] = CreateDynamicObject(19464, 1934.8968, -2036.2810, 17.5412, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[203], 0, 3629, "arprtxxref_las", "corrRoof_64HV", 0xFFFFFFFF);
    object_pooExterior[204] = CreateDynamicObject(19464, 1943.9857, -2036.6801, 17.7423, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[204], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[205] = CreateDynamicObject(19464, 1932.0434, -2036.6801, 17.7423, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[205], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[206] = CreateDynamicObject(19464, 1934.5019, -2036.6750, 20.1623, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[206], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[207] = CreateDynamicObject(19464, 1939.5323, -2036.6718, 20.1618, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[207], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[208] = CreateDynamicObject(19464, 1941.5627, -2036.6750, 20.1623, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[208], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[209] = CreateDynamicObject(19464, 1941.0638, -2033.7718, 17.7418, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[209], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[210] = CreateDynamicObject(19466, 1934.7878, -2033.6319, 18.9030, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[210], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[211] = CreateDynamicObject(19466, 1941.5988, -2033.6319, 18.9030, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[211], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[212] = CreateDynamicObject(19466, 1938.2882, -2033.6319, 18.9030, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[212], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[213] = CreateDynamicObject(19464, 1943.9853, -2038.5620, 17.7425, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[213], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[214] = CreateDynamicObject(19464, 1941.1158, -2041.4030, 17.7425, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[214], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[215] = CreateDynamicObject(19464, 1935.4150, -2041.4050, 17.7418, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[215], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[216] = CreateDynamicObject(19464, 1934.8961, -2041.4030, 17.7423, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[216], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[217] = CreateDynamicObject(19464, 1932.0428, -2038.5605, 17.7420, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[217], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[218] = CreateDynamicObject(19464, 1939.5323, -2038.4421, 20.1613, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[218], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[219] = CreateDynamicObject(19464, 1934.5019, -2038.4853, 20.1627, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[219], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[220] = CreateDynamicObject(19464, 1941.3634, -2038.4853, 20.1627, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[220], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[221] = CreateDynamicObject(19466, 1931.8781, -2035.7823, 18.5230, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[221], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[222] = CreateDynamicObject(19466, 1931.8781, -2039.2524, 18.5230, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[222], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[223] = CreateDynamicObject(19466, 1944.1373, -2039.2524, 18.5230, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[223], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[224] = CreateDynamicObject(19466, 1944.1373, -2035.8913, 18.5230, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[224], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[225] = CreateDynamicObject(19466, 1941.5971, -2041.5410, 18.5230, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[225], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[226] = CreateDynamicObject(19466, 1937.9071, -2041.5410, 18.5230, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[226], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[227] = CreateDynamicObject(19466, 1934.3669, -2041.5410, 18.5230, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //window001
    SetDynamicObjectMaterial(object_pooExterior[227], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
    object_pooExterior[228] = CreateDynamicObject(19464, 1934.8376, -2032.8208, 17.5424, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[228], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
    object_pooExterior[229] = CreateDynamicObject(19464, 1941.1374, -2032.8249, 17.5410, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[229], 0, 3820, "boxhses_sfsx", "tanboard1", 0xFFFFFFFF);
    object_pooExterior[230] = CreateDynamicObject(19175, 1948.2224, -2001.9632, 14.9502, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[230], 0, "Los Santos", 90, "Arial", 50, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[230], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[231] = CreateDynamicObject(19175, 1948.2224, -2004.6241, 14.9502, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[231], 0, "Ordnungsamt", 90, "Arial", 45, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[231], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[232] = CreateDynamicObject(19175, 1948.2414, -2001.8747, 14.8702, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[232], 0, "________________________________________", 90, "Arial", 52, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[232], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[233] = CreateDynamicObject(19175, 1948.2414, -2004.5739, 14.8702, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[233], 0, "________________________________________", 90, "Arial", 52, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[233], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[234] = CreateDynamicObject(19464, 1944.0894, -2036.4870, 10.1225, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[234], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[235] = CreateDynamicObject(19175, 1948.2224, -2002.9128, 13.9001, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[235], 0, "Herzlich", 90, "Arial", 40, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[235], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[236] = CreateDynamicObject(19175, 1948.2224, -2004.5528, 13.9001, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[236], 0, "Willkommen", 90, "Arial", 40, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[236], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[237] = CreateDynamicObject(19464, 1941.1883, -2033.6457, 10.1229, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[237], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[238] = CreateDynamicObject(19464, 1937.9278, -2033.0954, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[238], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[239] = CreateDynamicObject(19464, 1929.2086, -2031.7208, 10.1232, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[239], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[240] = CreateDynamicObject(19464, 1934.8675, -2030.2500, 10.1232, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[240], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[241] = CreateDynamicObject(19464, 1931.8465, -2033.0954, 10.1229, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[241], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_pooExterior[242] = CreateDynamicObject(1280, 1928.9117, -2030.9051, 13.0223, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_pooExterior[243] = CreateDynamicObject(19175, 1936.2823, -2021.7539, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[243], 0, "- A-07 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[243], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[244] = CreateDynamicObject(19175, 1938.4522, -2009.3006, 12.6500, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[244], 0, "- A-01 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[244], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[245] = CreateDynamicObject(19175, 1934.6711, -2009.3006, 12.6500, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[245], 0, "- A-02 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[245], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[246] = CreateDynamicObject(19175, 1931.0196, -2009.3006, 12.6500, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[246], 0, "- A-03 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[246], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[247] = CreateDynamicObject(19175, 1927.2391, -2009.3006, 12.6501, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[247], 0, "- A-04 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[247], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[248] = CreateDynamicObject(19175, 1928.8592, -2021.7539, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[248], 0, "- A-05 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[248], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[249] = CreateDynamicObject(19175, 1932.6109, -2021.7539, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[249], 0, "- A-06 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[249], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[250] = CreateDynamicObject(19175, 1928.7884, -1983.8829, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[250], 0, "- O-01 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[250], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[251] = CreateDynamicObject(19175, 1940.0528, -2021.7539, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[251], 0, "- A-08 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[251], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[252] = CreateDynamicObject(19175, 1940.0528, -2003.4621, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[252], 0, "- B-01 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[252], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[253] = CreateDynamicObject(19175, 1936.4018, -2003.4621, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[253], 0, "- B-02 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[253], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[254] = CreateDynamicObject(19175, 1932.6402, -2003.4621, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[254], 0, "- B-03 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[254], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[255] = CreateDynamicObject(19175, 1928.9289, -2003.4621, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[255], 0, "- B-04 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[255], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[256] = CreateDynamicObject(19952, 1945.7718, -2041.4344, 12.0960, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[256], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
    object_pooExterior[257] = CreateDynamicObject(19175, 1932.5499, -1983.8829, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[257], 0, "- O-02 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[257], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[258] = CreateDynamicObject(19175, 1936.3194, -1983.8829, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[258], 0, "- O-03 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[258], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[259] = CreateDynamicObject(19175, 1940.0715, -1983.8829, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[259], 0, "- O-04 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[259], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[260] = CreateDynamicObject(19175, 1943.8619, -1983.8829, 12.6501, -90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[260], 0, "- O-05 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[260], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[261] = CreateDynamicObject(19952, 1948.9824, -2041.4344, 12.0960, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[261], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
    object_pooExterior[262] = CreateDynamicObject(19175, 1947.7330, -2041.4256, 14.2701, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[262], 0, "P", 130, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[262], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[263] = CreateDynamicObject(19175, 1944.5124, -2041.4256, 14.2701, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[263], 0, "P", 130, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[263], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[264] = CreateDynamicObject(19175, 1947.8929, -2041.4256, 13.8101, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[264], 0, "Mitarbeiter", 130, "Arial", 22, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[264], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[265] = CreateDynamicObject(19175, 1944.6815, -2041.4256, 13.8101, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[265], 0, "Mitarbeiter", 130, "Arial", 22, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[265], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[266] = CreateDynamicObject(19966, 1951.1739, -2027.7531, 12.2792, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign19
    object_pooExterior[267] = CreateDynamicObject(19175, 1948.2735, -2035.4415, 12.6500, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[267], 0, "- P-01 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[267], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[268] = CreateDynamicObject(19175, 1944.9420, -2035.4415, 12.6500, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[268], 0, "- P-02 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[268], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[269] = CreateDynamicObject(19966, 1951.1739, -1989.1220, 12.2792, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign19
    object_pooExterior[270] = CreateDynamicObject(19952, 1943.2021, -1978.6822, 12.0960, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[270], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
    object_pooExterior[271] = CreateDynamicObject(19952, 1939.3620, -1978.6822, 12.0960, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[271], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
    object_pooExterior[272] = CreateDynamicObject(19952, 1935.6408, -1978.6822, 12.0960, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[272], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
    object_pooExterior[273] = CreateDynamicObject(19952, 1931.8092, -1978.6822, 12.0960, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[273], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
    object_pooExterior[274] = CreateDynamicObject(19952, 1928.0572, -1978.6822, 12.0960, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign5
    SetDynamicObjectMaterial(object_pooExterior[274], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
    object_pooExterior[275] = CreateDynamicObject(19175, 1944.4525, -1978.6949, 14.2701, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[275], 0, "P", 130, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[275], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[276] = CreateDynamicObject(19175, 1940.6113, -1978.6949, 14.2701, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[276], 0, "P", 130, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[276], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[277] = CreateDynamicObject(19175, 1936.9002, -1978.6949, 14.2701, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[277], 0, "P", 130, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[277], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[278] = CreateDynamicObject(19175, 1933.0592, -1978.6949, 14.2701, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[278], 0, "P", 130, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[278], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[279] = CreateDynamicObject(19175, 1929.3178, -1978.6949, 14.2701, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[279], 0, "P", 130, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[279], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[280] = CreateDynamicObject(19175, 1929.2077, -1978.6949, 13.8302, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[280], 0, "Fraktion", 130, "Arial", 23, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[280], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[281] = CreateDynamicObject(19175, 1932.9787, -1978.6949, 13.8302, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[281], 0, "Fraktion", 130, "Arial", 23, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[281], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[282] = CreateDynamicObject(19175, 1936.7794, -1978.6949, 13.8302, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[282], 0, "Fraktion", 130, "Arial", 23, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[282], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[283] = CreateDynamicObject(19175, 1940.5103, -1978.6949, 13.8302, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[283], 0, "Fraktion", 130, "Arial", 23, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[283], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[284] = CreateDynamicObject(19967, 1945.8442, -1995.6435, 12.4267, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
    object_pooExterior[285] = CreateDynamicObject(19984, 1951.2071, -1989.1081, 12.1972, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign37
    object_pooExterior[286] = CreateDynamicObject(19984, 1951.2071, -2027.7395, 12.1972, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign37
    object_pooExterior[287] = CreateDynamicObject(19175, 1944.3519, -1978.6949, 13.8302, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[287], 0, "Fraktion", 130, "Arial", 23, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[287], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[288] = CreateDynamicObject(1232, 1947.0975, -1980.0626, 15.2314, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_pooExterior[289] = CreateDynamicObject(19175, 1927.2391, -1991.0177, 12.6501, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[289], 0, "- B-05 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[289], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[290] = CreateDynamicObject(19175, 1930.9400, -1991.0177, 12.6501, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[290], 0, "- B-06 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[290], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[291] = CreateDynamicObject(19175, 1934.6805, -1991.0177, 12.6501, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[291], 0, "- B-07 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[291], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[292] = CreateDynamicObject(19175, 1938.4113, -1991.0177, 12.6501, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_pooExterior[292], 0, "- B-08 -", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    SetDynamicObjectMaterial(object_pooExterior[292], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_pooExterior[293] = CreateDynamicObject(1232, 1945.8974, -1998.5821, 15.2314, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_pooExterior[294] = CreateDynamicObject(1232, 1945.8974, -2007.6842, 15.2314, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_pooExterior[295] = CreateDynamicObject(1232, 1936.7469, -2029.9749, 15.2314, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
    object_pooExterior[296] = CreateDynamicObject(1232, 1932.7475, -2029.9749, 15.2314, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp1
}