#include <YSI\y_hooks>

// Global interior define
#define MAPS_WHEELMANBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Wheelman points
#define WHEELMANBASE_SPAWN_POINT             938.7240, 1733.3646, 8.8516
#define WHEELMANBASE_SPAWN_POINT_FACING      270.0

// Map variables
new object_wheelmanBase[1];
new pickup_wheelmanBase[1];
new text3D_wheelmanBase[1];
new vehicle_wheelmanBase[14];

hook OnPlayerConnect(playerid) {
	RemoveBuildingForPlayer(playerid, 1250, 997.4141, 1707.5234, 10.8516, 0.25);
    RemoveBuildingForPlayer(playerid, 1251, 997.0469, 1710.9531, 11.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 1251, 998.0938, 1755.6875, 11.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 1250, 997.7266, 1759.1250, 10.8516, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
	// Pickups
	pickup_wheelmanBase[0] = CreateDynamicPickup(1240, 1, WHEELMANBASE_SPAWN_POINT, VW_MAIN, MAPS_WHEELMANBASE_INTERIOR); // Wheelman Spawn point
	
    // 3DTextLabels
    text3D_wheelmanBase[0] = _:CreateDynamic3DTextLabel("Wheelman Spawn\n" COLOR_HEX_WHITE "Tippe /Gangwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, WHEELMANBASE_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_WHEELMANBASE_INTERIOR);
    
    // Vehicles
	vehicle_wheelmanBase[0] = AddStaticVehicleEx(468, 952.5954, 1758.7262, 8.3156, 180.5374, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[1] = AddStaticVehicleEx(468, 955.0316, 1758.8654, 8.3157, 180.7352, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[2] = AddStaticVehicleEx(522, 958.3127, 1758.9200, 8.2156, 179.1201, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[3] = AddStaticVehicleEx(522, 960.8812, 1759.0088, 8.2190, 180.3178, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[4] = AddStaticVehicleEx(411, 983.6983, 1745.4128, 8.3823, 90.1818, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[5] = AddStaticVehicleEx(411, 983.8836, 1741.1553, 8.3880, 90.9491, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[6] = AddStaticVehicleEx(560, 983.9272, 1737.0353, 8.3485, 91.7573, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[7] = AddStaticVehicleEx(560, 984.1312, 1733.3309, 8.3707, 93.2435, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[8] = AddStaticVehicleEx(560, 983.9086, 1729.8083, 8.4432, 90.8776, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[9] = AddStaticVehicleEx(560, 984.0126, 1726.1807, 8.4343, 91.3444, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[10] = AddStaticVehicleEx(415, 984.0925, 1722.7196, 8.3845, 92.1436, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[11] = AddStaticVehicleEx(541, 984.3115, 1719.5607, 8.2907, 89.2417, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[12] = AddStaticVehicleEx(487, 952.3722, 1692.2795, 15.9515, 270.6660, 19, 19, -1); // wheelmen car
	vehicle_wheelmanBase[13] = AddStaticVehicleEx(487, 951.6595, 1680.0258, 15.9471, 268.2809, 19, 19, -1); // wheelmen car

	// Objects
	object_wheelmanBase[0] = CreateDynamicObject(7096, 968.0623, 1677.0314, 12.9567, 0.0000, 0.0000, -180.0000, VW_MAIN, MAPS_WHEELMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
