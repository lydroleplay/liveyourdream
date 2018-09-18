#include <YSI\y_hooks>

// Global interior define
#define MAPS_FBIEXTERIOR_INTERIOR      0
#define MAPS_FBIINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// FBI points
#define FBI_INTERIOR_ENTER_COORDS		1901.9264, 742.8745, 10.8198
#define FBI_INTERIOR_EXIT_COORDS		264.3734, 191.1904, 1008.1719
#define FBI_INTERIOR_ENTER_FACING		180.0
#define FBI_INTERIOR_EXIT_FACING   	    90.0
#define FBI_STATEREPAIR_COORDS			1882.3618, 718.3406, 10.8203
#define FBI_GATE_FOR_RANGE_COORDS	    1877.8368, 703.3236, 10.7716
#define FBI_GATE_OPEN_Z				    6.8897
#define FBI_GATE_CLOSED_Z			    11.3403

// Map variables
new object_fbiExterior[54];
new pickup_fbiExterior[2];
new text3D_fbiExterior[1];
new vehicle_fbiExterior[27];
new object_fbiExterior_gate;

// Map commands
CMD:fbigate(playerid, params[]) {
	if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 9 || Spieler[playerid][pFraktion] == 18 || Spieler[playerid][pFraktion] == 22))
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Staatsbeamter.");
	if (!IsPlayerInRangeOfPoint(playerid, 20.0, FBI_GATE_FOR_RANGE_COORDS)) return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Tores.");

	new Float:fX, Float:fY, Float:fZ;
	GetDynamicObjectPos(object_fbiExterior_gate, fX, fY, fZ);

	if (fZ == FBI_GATE_OPEN_Z)
		MoveDynamicObject(object_fbiExterior_gate, fX, fY, FBI_GATE_CLOSED_Z, 2.0);
	else
		MoveDynamicObject(object_fbiExterior_gate, fX, fY, FBI_GATE_OPEN_Z, 2.0);

	return 1;
}

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 1343, 1877.880, 722.734, 10.562, 0.250);
	RemoveBuildingForPlayer(playerid, 1231, 2182.050, 1463.250, 12.523, 0.250);
	RemoveBuildingForPlayer(playerid, 625, 1879.050, 698.914, 10.710, 0.250);
	RemoveBuildingForPlayer(playerid, 625, 1879.050, 710.335, 10.710, 0.250);
	RemoveBuildingForPlayer(playerid, 1343, 1976.680, 693.710, 10.562, 0.250);
	RemoveBuildingForPlayer(playerid, 1344, 1975.699, 712.703, 10.625, 0.250);
	RemoveBuildingForPlayer(playerid, 625, 1978.199, 710.015, 10.710, 0.250);
	RemoveBuildingForPlayer(playerid, 625, 1978.199, 698.914, 10.710, 0.250);
	RemoveBuildingForPlayer(playerid, 1344, 1882.099, 722.703, 10.625, 0.250);
	RemoveBuildingForPlayer(playerid, 1344, 1884.839, 722.703, 10.625, 0.250);
	RemoveBuildingForPlayer(playerid, 1231, 1917.420, 723.085, 12.460, 0.250);
	RemoveBuildingForPlayer(playerid, 1231, 1937.359, 723.085, 12.460, 0.250);
	RemoveBuildingForPlayer(playerid, 1231, 1917.709, 683.265, 12.460, 0.250);
	RemoveBuildingForPlayer(playerid, 1231, 1937.300, 683.265, 12.460, 0.250);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, FBI_INTERIOR_ENTER_COORDS)) { // Entrance
			SetPlayerFacingAngle(playerid, FBI_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, FBI_INTERIOR_EXIT_COORDS + 0.5, MAPS_FBIINTERIOR_INTERIOR, VW_FBIINTERIOR);
			return 1;
		}
	}

	return 1;
}

hook OnGameModeInit() {    
	// Pickups
	pickup_fbiExterior[0] = CreateDynamicPickup(19197, 1, FBI_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR); // Entrance
    pickup_fbiExterior[1] = CreateDynamicPickup(1239, 1, FBI_STATEREPAIR_COORDS, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR); // Staterepair
    
    // 3DTextLabels
    text3D_fbiExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, FBI_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_FBIEXTERIOR_INTERIOR); // Staterepair

	// Vehicles
    vehicle_fbiExterior[0] = AddStaticVehicleEx(523, 1898.4823, 720.6070, 10.3905, 271.9332, 0, 0, -1); // FBIMotorrad1
    vehicle_fbiExterior[1] = AddStaticVehicleEx(523, 1898.5605, 722.6526, 10.3913, 271.5622, 0, 0, -1); // FBIMotorrad2
    vehicle_fbiExterior[2] = AddStaticVehicleEx(523, 1898.2538, 724.8604, 10.3901, 270.4993, 0, 0, -1); // FBIMotorrad3
    vehicle_fbiExterior[3] = AddStaticVehicleEx(523, 1898.3014, 727.3496, 10.3901, 269.3506, 0, 0, -1); // FBIMotorrad4
    vehicle_fbiExterior[4] = AddStaticVehicleEx(560, 1909.9938, 708.0081, 10.5265, 0.0000, 0, 0, -1); // FBISultan1
    vehicle_fbiExterior[5] = AddStaticVehicleEx(560, 1916.2933, 708.0099, 10.5327, 359.3907, 0, 0, -1); // FBISultan2
    vehicle_fbiExterior[6] = AddStaticVehicleEx(560, 1922.6940, 708.0628, 10.5299, 0.5165, 0, 0, -1); // FBISultan3
    vehicle_fbiExterior[7] = AddStaticVehicleEx(598, 1929.2278, 708.2212, 10.6145, 0.4616, 0, 0, -1); // FBIPDCar1
    vehicle_fbiExterior[8] = AddStaticVehicleEx(598, 1935.5248, 708.2570, 10.6133, 359.9110, 0, 0, -1); // FBIPDCar2
    vehicle_fbiExterior[9] = AddStaticVehicleEx(598, 1942.0066, 708.4412, 10.5905, 359.6378, 0, 0, -1); // FBIPDCar3
    vehicle_fbiExterior[10] = AddStaticVehicleEx(597, 1942.0570, 698.3959, 10.6099, 180.3381, 0, 0, -1); // FBIPDCar4
    vehicle_fbiExterior[11] = AddStaticVehicleEx(599, 1935.5797, 698.5533, 11.0176, 179.6054, 0, 0, -1); // FBIPDRanger1
    vehicle_fbiExterior[12] = AddStaticVehicleEx(599, 1929.2791, 698.4995, 11.0202, 180.6479, 0, 0, -1); // FBIPDRanger2
    vehicle_fbiExterior[13] = AddStaticVehicleEx(490, 1922.6265, 698.3480, 10.9633, 180.4432, 0, 0, -1); // FBIRanger1
    vehicle_fbiExterior[14] = AddStaticVehicleEx(490, 1916.4125, 698.2446, 10.9479, 180.7977, 0, 0, -1); // FBIRanger2
    vehicle_fbiExterior[15] = AddStaticVehicleEx(490, 1909.7554, 698.1930, 10.9433, 179.5954, 0, 0, -1); // FBIRanger3
    vehicle_fbiExterior[16] = AddStaticVehicleEx(601, 1920.1407, 738.2609, 10.5791, 181.0959, 0, 0, -1); // FBIWasserwerfer
    vehicle_fbiExterior[17] = AddStaticVehicleEx(427, 1926.9146, 738.3283, 10.9536, 175.2241, 0, 0, -1); // EnforcerFBI1
    vehicle_fbiExterior[18] = AddStaticVehicleEx(427, 1935.4410, 738.0777, 10.9531, 177.9978, 0, 0, -1); // EnforcerFBI2
    vehicle_fbiExterior[19] = AddStaticVehicleEx(528, 1942.4806, 739.8932, 10.8982, 181.8614, 0, 0, -1); // FBITruck1
    vehicle_fbiExterior[20] = AddStaticVehicleEx(528, 1948.0559, 739.5679, 10.8638, 180.5453, 0, 0, -1); // FBITruck2
    vehicle_fbiExterior[21] = AddStaticVehicleEx(447, 1887.8113, 671.3311, 19.3851, 270.7577, 0, 0, -1); // FBISeasparrow1
    vehicle_fbiExterior[22] = AddStaticVehicleEx(447, 1887.8379, 653.7224, 19.4047, 270.8672, 0, 0, -1); // FBISeasparrow2
    vehicle_fbiExterior[23] = AddStaticVehicleEx(497, 1887.1563, 734.1370, 19.5620, 269.1373, 0, 1, -1); // FBIMaverick1
    vehicle_fbiExterior[24] = AddStaticVehicleEx(497, 1887.2302, 753.8856, 19.5664, 270.6569, 0, 1, -1); // FBIMaverick2
    vehicle_fbiExterior[25] = AddStaticVehicleEx(597, 1899.6368, 731.8348, 10.5908, 270.1892, 37, 1, -1); // FBIPDCar5
    vehicle_fbiExterior[26] = AddStaticVehicleEx(541, 1954.2128, 727.6370, 10.4458, 93.2108, 0, 0, -1); // FBIPDCar5

	// Objects
	object_fbiExterior[0] = CreateDynamicObject(987, 1877.640747, 729.728149, 9.820312, 0.000000, 0.000000, -89.699981, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[1] = CreateDynamicObject(987, 1877.656982, 720.858520, 9.820312, 0.000000, 0.000000, -89.699981, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[2] = CreateDynamicObject(987, 1877.619140, 697.396850, 9.820312, 0.000000, 0.000000, -89.699981, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[3] = CreateDynamicObject(987, 1877.665649, 688.416625, 9.820312, 0.000000, 0.000000, -89.699981, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[4] = CreateDynamicObject(987, 1977.217895, 693.292541, 9.668911, 0.000000, 0.000000, 90.200035, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[5] = CreateDynamicObject(987, 1977.186401, 702.292724, 9.668911, 0.000000, 0.000000, 90.200035, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[6] = CreateDynamicObject(3928, 1887.942626, 671.211364, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[7] = CreateDynamicObject(3928, 1887.942626, 653.591430, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[8] = CreateDynamicObject(3928, 1905.643554, 653.591430, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[9] = CreateDynamicObject(3928, 1921.354125, 653.591430, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[10] = CreateDynamicObject(3928, 1938.414550, 653.591430, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[11] = CreateDynamicObject(3928, 1968.694091, 667.221679, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[12] = CreateDynamicObject(3928, 1968.694091, 684.571838, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[13] = CreateDynamicObject(3928, 1968.694091, 718.841735, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[14] = CreateDynamicObject(3928, 1968.694091, 734.192077, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[15] = CreateDynamicObject(3928, 1952.092895, 754.022949, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[16] = CreateDynamicObject(3928, 1935.573120, 754.022949, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[17] = CreateDynamicObject(3928, 1916.103027, 754.022949, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[18] = CreateDynamicObject(3928, 1888.253051, 754.022949, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[19] = CreateDynamicObject(3928, 1888.253051, 734.202758, 18.346893, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[20] = CreateDynamicObject(19903, 1881.550903, 722.842895, 9.824152, -0.199999, 0.000000, -87.800025, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[21] = CreateDynamicObject(19903, 1882.699951, 722.887084, 9.820138, -0.199999, 0.000000, -87.800025, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[22] = CreateDynamicObject(2609, 1883.891601, 722.832336, 10.620311, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[23] = CreateDynamicObject(2609, 1884.342041, 722.832336, 10.620311, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[24] = CreateDynamicObject(2609, 1880.391723, 722.832336, 10.620311, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[25] = CreateDynamicObject(2609, 1879.961914, 722.832336, 10.620311, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[26] = CreateDynamicObject(1437, 1898.515136, 666.883789, 14.397019, -22.899999, 0.000000, -176.699996, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[27] = CreateDynamicObject(1437, 1898.666748, 739.782470, 14.419746, -20.500013, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[28] = CreateDynamicObject(970, 1911.347290, 703.149902, 10.662812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[29] = CreateDynamicObject(970, 1921.237915, 703.149902, 10.662812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[30] = CreateDynamicObject(970, 1898.841796, 719.653015, 10.410315, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[31] = CreateDynamicObject(19121, 1913.636962, 703.138732, 10.702815, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[32] = CreateDynamicObject(19121, 1918.936889, 703.138732, 10.702815, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[33] = CreateDynamicObject(970, 1927.898193, 703.149902, 10.662812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[34] = CreateDynamicObject(970, 1936.128906, 703.149902, 10.662812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[35] = CreateDynamicObject(19121, 1930.167724, 703.138732, 10.702815, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[36] = CreateDynamicObject(19121, 1933.837890, 703.138732, 10.702815, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[37] = CreateDynamicObject(970, 1898.841796, 721.913574, 10.410315, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[38] = CreateDynamicObject(970, 1898.841796, 724.053771, 10.410315, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[39] = CreateDynamicObject(970, 1898.841796, 726.294189, 10.410315, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[40] = CreateDynamicObject(970, 1898.841796, 728.424743, 10.410315, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[41] = CreateDynamicObject(19121, 1901.056274, 719.649169, 10.362812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[42] = CreateDynamicObject(19121, 1901.056274, 721.919494, 10.362812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[43] = CreateDynamicObject(19121, 1901.056274, 724.059936, 10.362812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[44] = CreateDynamicObject(19121, 1901.056274, 726.280151, 10.362812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[45] = CreateDynamicObject(19121, 1901.056274, 728.420715, 10.362812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[46] = CreateDynamicObject(19121, 1900.846069, 743.070739, 10.362812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[47] = CreateDynamicObject(19121, 1902.856567, 743.070739, 10.362812, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[48] = CreateDynamicObject(19860, 264.88489, 190.44450, 1008.42548, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[49] = CreateDynamicObject(19439, 264.99011, 191.09171, 1008.89130, 90.00000, 0.00000, 0.00000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[50] = CreateDynamicObject(19439, 264.99011, 191.09171, 1007.28528, 90.00000, 0.00000, 0.00000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[51] = CreateDynamicObject(19464, 237.58881, 193.96500, 1009.47888, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_fbiExterior[52] = CreateDynamicObject(19464, 268.08679, 193.96500, 1009.47888, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_fbiExterior[53] = CreateDynamicObject(980, 1877.524658, 703.223693, 11.3403, 0.000000, 0.000000, 90.00000, VW_MAIN, MAPS_FBIEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

    object_fbiExterior_gate = object_fbiExterior[53];
}