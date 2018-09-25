#include <YSI\y_hooks>

// Global interior define
#define MAPS_CITYHALLEXTERIOR_INTERIOR      0
#define MAPS_CITYHALLINTERIOR_INTERIOR      0
#define MAPS_REGISTRATIONOFFICE_INTERIOR    0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Cityhall coords & points
#define CITYHALL_INTERIOR_ENTER_COORDS              1481.2209, -1805.4011, 15.9027
#define CITYHALL_INTERIOR_EXIT_COORDS               920.2045, -1475.2966, 2754.3318
#define CITYHALL_INTERIOR_ENTER_FACING              0.0
#define CITYHALL_INTERIOR_EXIT_FACING               0.0
#define REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS    1544.7505, -1765.5770, 13.5286
#define REGISTRATIONOFFICE_INTERIOR_EXIT_COORDS     2305.8259, -16.1325, 26.7496
#define REGISTRATIONOFFICE_INTERIOR_ENTER_FACING    180.0
#define REGISTRATIONOFFICE_INTERIOR_EXIT_FACING     270.0
#define JEFF_VAN_COORDS                             1339.6373, -1808.8037, 13.6913, 180.0000
#define JEFF_COORDS									1338.7585, -1805.1331, 13.5469
#define JEFF_COORDS_FACING                          1338.7585, -1805.1331, 13.5469, 270.0000


// Map variables
new object_cityhallExterior[363];
new pickup_cityhallExterior[2];
new text3D_cityhallExterior[3];
new actor_cityhallExterior[1];
new vehicle_cityhallExterior[1];

// TODO: Peek adjust cityhall /gotoliste

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 4024, 1479.8672, -1790.3984, 56.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 4044, 1481.1875, -1785.0703, 22.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 4045, 1479.3359, -1802.2891, 12.5469, 0.25);
	RemoveBuildingForPlayer(playerid, 4046, 1479.5234, -1852.6406, 24.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 4047, 1531.6328, -1852.6406, 24.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 1448.2344, -1755.8984, 14.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 4217, 1449.2500, -1852.5703, 22.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1407.1953, -1749.3125, 13.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 1266, 1482.0859, -1859.9688, 25.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1405.2344, -1821.1172, 13.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1417.9766, -1832.5313, 11.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1405.5781, -1831.6953, 12.3984, 0.25);
	RemoveBuildingForPlayer(playerid, 1265, 1465.4766, -1848.2500, 12.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 1372, 1466.9453, -1847.8438, 12.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1372, 1419.7344, -1846.5469, 12.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1265, 1420.4297, -1845.3438, 12.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 1372, 1419.6953, -1844.2031, 12.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1220, 1420.4922, -1842.4375, 12.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 1220, 1419.7266, -1842.8516, 12.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 1230, 1419.6719, -1842.0313, 12.9766, 0.25);
	RemoveBuildingForPlayer(playerid, 4170, 1433.9531, -1844.4063, 21.4219, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1447.1016, -1832.5000, 12.9141, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 1432.3047, -1832.9141, 15.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 4174, 1435.7656, -1823.6641, 15.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1456.3984, -1832.5313, 11.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1464.0938, -1831.8828, 12.3984, 0.25);
	RemoveBuildingForPlayer(playerid, 1260, 1482.0859, -1859.9688, 25.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 4004, 1479.5234, -1852.6406, 24.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1357, 1487.6953, -1848.1094, 12.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1372, 1486.2109, -1848.1250, 12.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1372, 1468.0625, -1847.7891, 12.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1230, 1488.9219, -1848.2734, 12.9766, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 1480.0313, -1832.9141, 15.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 3997, 1479.3359, -1802.2891, 12.5469, 0.25);
	RemoveBuildingForPlayer(playerid, 4171, 1503.3984, -1848.3359, 21.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1504.8438, -1832.5313, 11.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1499.0469, -1832.2734, 12.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 1265, 1515.3828, -1850.0547, 12.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 1265, 1514.4219, -1850.0391, 12.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1512.9453, -1832.3516, 13.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 1372, 1516.6875, -1850.0547, 12.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1404.9141, -1765.2656, 12.9141, 0.25);
	RemoveBuildingForPlayer(playerid, 4173, 1427.2734, -1756.1797, 15.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1415.3125, -1748.5625, 12.3984, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1429.5313, -1748.4219, 12.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1438.0313, -1747.9375, 13.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1447.9063, -1748.2266, 12.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 4002, 1479.8672, -1790.3984, 56.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 3980, 1481.1875, -1785.0703, 22.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 4003, 1481.0781, -1747.0313, 33.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1516.0000, -1748.6016, 13.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 4048, 1531.6328, -1852.6406, 24.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1372, 1538.9453, -1849.2734, 12.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1230, 1538.8359, -1847.6250, 13.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1220, 1538.3906, -1847.9297, 12.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 1220, 1539.1016, -1847.2969, 12.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 1529.2891, -1832.9141, 15.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1549.5313, -1832.3125, 12.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1555.6641, -1830.5938, 13.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 4175, 1524.4141, -1823.8516, 15.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1554.8203, -1816.1563, 13.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1553.2578, -1764.8125, 12.7969, 0.25);
	RemoveBuildingForPlayer(playerid, 4172, 1534.7656, -1756.1797, 15.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1533.2656, -1749.0234, 12.8047, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1522.1641, -1748.5703, 13.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1553.7031, -1747.9375, 13.4063, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, CITYHALL_INTERIOR_ENTER_COORDS)) { // Cityhall Entrance
			SetPlayerFacingAngle(playerid, CITYHALL_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, CITYHALL_INTERIOR_EXIT_COORDS + 0.5, MAPS_CITYHALLINTERIOR_INTERIOR, VW_CITYHALLINTERIOR);
			return 1;
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS)) { // Registration office Entrance
            SendClientMessage(playerid, COLOR_WHITE, "Sachbearbeiter sagt: Herzlich Willkommen beim Kraftfahrtbundesamt (Zulassungsstelle)!");
		    SetPlayerFacingAngle(playerid, REGISTRATIONOFFICE_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, REGISTRATIONOFFICE_INTERIOR_EXIT_COORDS, MAPS_REGISTRATIONOFFICE_INTERIOR, VW_REGISTRATIONOFFICE);
			return 1;
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, REGISTRATIONOFFICE_INTERIOR_EXIT_COORDS)) { // Registration office Exit
			SendClientMessage(playerid, COLOR_WHITE, "Sachbearbeiter sagt: Vielen Dank für Ihr Besuch! Wir wünschen Ihnen einen schönen Tag.");
		    SetPlayerFacingAngle(playerid, REGISTRATIONOFFICE_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS + 0.5, MAPS_CITYHALLEXTERIOR_INTERIOR, VW_MAIN);
            return 1;
		}
	}

	return 1;
}

hook OnGameModeInit() {
	// Map Icon
    CreateDynamicMapIcon(CITYHALL_INTERIOR_ENTER_COORDS, 38, 0, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR);

	// Pickups
    pickup_cityhallExterior[0] = CreateDynamicPickup(19197, 1, CITYHALL_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR); // Cityhall
    pickup_cityhallExterior[1] = CreateDynamicPickup(19197, 1, REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR); // Registration office

	// 3DTextLabels
    text3D_cityhallExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "-> San Andreas Stadtamt <-\n" COLOR_HEX_WHITE "Arbeitsamt, Meldeamt, Passbehörde\nGebäude betreten mit 'Enter'", COLOR_WHITE, CITYHALL_INTERIOR_ENTER_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CITYHALLEXTERIOR_INTERIOR); // Cityhall
    text3D_cityhallExterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "-> Kraftfahrtbundesamt - Zulassungsstelle <-\n" COLOR_HEX_WHITE "Gebäude betreten mit 'Enter'", COLOR_WHITE, REGISTRATIONOFFICE_INTERIOR_ENTER_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CITYHALLEXTERIOR_INTERIOR); // Registration office
    text3D_cityhallExterior[2] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Illegaler Jobvermittler - Jeff\n" COLOR_HEX_WHITE "Tippe /Illegalejobs", COLOR_WHITE, JEFF_COORDS, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_CITYHALLEXTERIOR_INTERIOR); // Jeff

    // Actors
    actor_cityhallExterior[0] = CreateDynamicActor(32, JEFF_COORDS_FACING, .streamdistance = STREAMDISTANCE);
    ApplyDynamicActorAnimation(actor_cityhallExterior[0], "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);

    // Vehicles
    vehicle_cityhallExterior[0] = AddStaticVehicle(482, JEFF_VAN_COORDS, 0, 0); // burrito (Jeff)

    // Parking ATM


	// Objects
	object_cityhallExterior[0] = CreateDynamicObject(19531, 1461.2900, -1804.1472, 12.5241, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane125x125Conc1
	SetDynamicObjectMaterial(object_cityhallExterior[0], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
	object_cityhallExterior[1] = CreateDynamicObject(19531, 1497.6905, -1804.1472, 12.5260, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane125x125Conc1
	SetDynamicObjectMaterial(object_cityhallExterior[1], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
	object_cityhallExterior[2] = CreateDynamicObject(10049, 1481.5747, -1826.2407, 28.9986, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Posh_thingsfe
	SetDynamicObjectMaterial(object_cityhallExterior[2], 0, 3980, "cityhall_lan", "citywall1", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[2], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[2], 2, 3980, "cityhall_lan", "citywall1", 0xFFBDBEC6);
	SetDynamicObjectMaterial(object_cityhallExterior[2], 3, 3980, "cityhall_lan", "citywall1", 0xFFBDBEC6);
	SetDynamicObjectMaterial(object_cityhallExterior[2], 5, 3980, "cityhall_lan", "citywall1", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[2], 6, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[2], 7, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[2], 8, 10377, "cityhall_sfs", "ws_cityhall4", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[2], 11, 3980, "cityhall_lan", "citywall1", 0xFFFFFFFF);
	object_cityhallExterior[3] = CreateDynamicObject(19377, 1481.4436, -1763.9309, 13.3648, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[3], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[4] = CreateDynamicObject(14416, 1478.1562, -1757.2434, 10.2601, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_cityhallExterior[4], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[4], 1, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	object_cityhallExterior[5] = CreateDynamicObject(19377, 1481.5334, -1747.0594, 12.4378, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[5], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[6] = CreateDynamicObject(14416, 1481.2259, -1757.2397, 10.2607, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_cityhallExterior[6], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[6], 1, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	object_cityhallExterior[7] = CreateDynamicObject(14416, 1484.7176, -1757.2434, 10.2601, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_cityhallExterior[7], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[7], 1, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	object_cityhallExterior[8] = CreateDynamicObject(19377, 1481.4436, -1773.5517, 13.3648, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[8], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[9] = CreateDynamicObject(19377, 1471.1241, -1769.4228, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[9], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[10] = CreateDynamicObject(14416, 1484.7176, -1776.8657, 10.9102, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_cityhallExterior[10], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[10], 1, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	object_cityhallExterior[11] = CreateDynamicObject(14416, 1481.5461, -1776.8697, 10.9104, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_cityhallExterior[11], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[11], 1, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	object_cityhallExterior[12] = CreateDynamicObject(19377, 1481.5334, -1756.6893, 12.4375, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[12], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[13] = CreateDynamicObject(19377, 1481.4536, -1793.1605, 14.0149, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[13], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[14] = CreateDynamicObject(19377, 1481.4536, -1783.5295, 14.0149, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[14], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[15] = CreateDynamicObject(19377, 1481.4536, -1802.7805, 14.0149, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[15], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[16] = CreateDynamicObject(14416, 1478.1643, -1776.8657, 10.9102, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_cityhallExterior[16], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[16], 1, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	object_cityhallExterior[17] = CreateDynamicObject(19450, 1486.6894, -1756.6810, 10.7938, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[17], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[18] = CreateDynamicObject(19450, 1486.6894, -1747.1008, 10.7931, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[18], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[19] = CreateDynamicObject(19450, 1476.2773, -1762.5788, 11.7138, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[19], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[20] = CreateDynamicObject(19450, 1486.6688, -1762.5793, 11.7138, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[20], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[21] = CreateDynamicObject(19450, 1486.6899, -1776.2191, 11.7138, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[21], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[22] = CreateDynamicObject(19450, 1486.6910, -1782.8479, 12.3638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[22], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[23] = CreateDynamicObject(19450, 1486.6910, -1792.4873, 12.3638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[23], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[24] = CreateDynamicObject(19450, 1486.6910, -1802.1173, 12.3638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[24], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[25] = CreateDynamicObject(19450, 1486.6915, -1811.7458, 12.3641, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[25], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[26] = CreateDynamicObject(19450, 1476.2794, -1811.7458, 12.3641, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[26], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[27] = CreateDynamicObject(19450, 1476.2794, -1802.1135, 12.3641, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[27], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[28] = CreateDynamicObject(19450, 1476.2789, -1792.5018, 12.3638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[28], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[29] = CreateDynamicObject(19450, 1476.2779, -1782.8713, 12.3638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[29], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[30] = CreateDynamicObject(19450, 1476.2789, -1782.8713, 12.3638, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[30], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[31] = CreateDynamicObject(19450, 1476.2794, -1776.2191, 11.7138, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[31], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[32] = CreateDynamicObject(14416, 1474.2956, -1769.4239, 10.2500, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_cityhallExterior[32], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[32], 1, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	object_cityhallExterior[33] = CreateDynamicObject(19450, 1479.6590, -1771.3286, 11.6997, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[33], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[34] = CreateDynamicObject(19450, 1476.2789, -1756.6810, 10.7938, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[34], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[35] = CreateDynamicObject(19450, 1476.2789, -1747.1008, 10.7931, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[35], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[36] = CreateDynamicObject(19450, 1481.5107, -1762.5793, 11.7038, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[36], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[37] = CreateDynamicObject(19450, 1481.5107, -1782.8808, 12.3535, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[37], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[38] = CreateDynamicObject(14416, 1488.6147, -1769.3640, 10.2500, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_cityhallExterior[38], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[38], 1, 12946, "ce_bankalley1", "sw_stairs1", 0xFFFFFFFF);
	object_cityhallExterior[39] = CreateDynamicObject(19450, 1479.6590, -1767.4775, 11.6997, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[39], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[40] = CreateDynamicObject(19450, 1483.2491, -1767.4775, 11.6997, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[40], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[41] = CreateDynamicObject(19450, 1483.2491, -1771.3089, 11.6997, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[41], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[42] = CreateDynamicObject(19377, 1460.6357, -1769.4228, 12.4454, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[42], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[43] = CreateDynamicObject(19377, 1450.1761, -1769.4228, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[43], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[44] = CreateDynamicObject(19377, 1491.9372, -1769.4228, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[44], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[45] = CreateDynamicObject(19377, 1502.4160, -1769.4228, 12.4454, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[45], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[46] = CreateDynamicObject(19377, 1512.9150, -1769.4228, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[46], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[47] = CreateDynamicObject(19377, 1439.7563, -1768.8138, 12.4453, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[47], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[48] = CreateDynamicObject(19377, 1439.7563, -1778.4436, 12.4453, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[48], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[49] = CreateDynamicObject(19377, 1439.7563, -1759.1855, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[49], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[50] = CreateDynamicObject(19377, 1429.2585, -1759.1855, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[50], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[51] = CreateDynamicObject(19377, 1429.2585, -1768.8160, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[51], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[52] = CreateDynamicObject(19377, 1429.2585, -1778.4470, 12.4453, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[52], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[53] = CreateDynamicObject(19377, 1418.7602, -1778.4470, 12.4453, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[53], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[54] = CreateDynamicObject(19377, 1418.7602, -1768.8164, 12.4453, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[54], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[55] = CreateDynamicObject(19377, 1418.7602, -1759.1855, 12.4453, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[55], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[56] = CreateDynamicObject(19377, 1418.7602, -1747.0943, 12.4453, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[56], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[57] = CreateDynamicObject(19377, 1439.7423, -1747.0943, 12.4453, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[57], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[58] = CreateDynamicObject(19377, 1439.7423, -1752.7353, 12.4441, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[58], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[59] = CreateDynamicObject(19377, 1418.7624, -1752.7353, 12.4441, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[59], 0, 16640, "a51", "concretemanky", 0xFF96918C);
	object_cityhallExterior[60] = CreateDynamicObject(18762, 1426.4813, -1754.8420, 12.9909, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[60], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[61] = CreateDynamicObject(18762, 1432.0129, -1754.8420, 12.9909, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[61], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[62] = CreateDynamicObject(18762, 1429.2016, -1754.8370, 12.9904, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[62], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[63] = CreateDynamicObject(18762, 1442.5135, -1782.7535, 12.9909, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[63], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[64] = CreateDynamicObject(18762, 1437.5141, -1782.7535, 12.9909, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[64], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[65] = CreateDynamicObject(18762, 1432.5124, -1782.7535, 12.9909, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[65], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[66] = CreateDynamicObject(18762, 1427.5222, -1782.7535, 12.9909, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[66], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[67] = CreateDynamicObject(18762, 1422.5322, -1782.7535, 12.9909, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[67], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[68] = CreateDynamicObject(18762, 1415.9997, -1782.7535, 12.9909, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[68], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[69] = CreateDynamicObject(18762, 1418.9399, -1782.7480, 12.9904, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[69], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[70] = CreateDynamicObject(19971, 1438.0067, -1743.2746, 17.9181, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[70], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[70], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[71] = CreateDynamicObject(19971, 1437.3564, -1743.2746, 17.9181, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[71], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[71], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[72] = CreateDynamicObject(736, 1457.3089, -1805.1103, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[73] = CreateDynamicObject(736, 1464.8485, -1805.1103, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[74] = CreateDynamicObject(736, 1449.7396, -1805.1103, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[75] = CreateDynamicObject(736, 1496.7298, -1805.1103, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[76] = CreateDynamicObject(736, 1504.7801, -1805.1103, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[77] = CreateDynamicObject(736, 1512.3010, -1805.1103, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[78] = CreateDynamicObject(18762, 1413.9787, -1780.7342, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[78], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[79] = CreateDynamicObject(18762, 1413.9787, -1775.7430, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[79], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[80] = CreateDynamicObject(18762, 1413.9787, -1770.7547, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[80], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[81] = CreateDynamicObject(18762, 1413.9787, -1765.7550, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[81], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[82] = CreateDynamicObject(18762, 1413.9787, -1760.7547, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[82], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[83] = CreateDynamicObject(18762, 1413.9787, -1755.7535, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[83], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[84] = CreateDynamicObject(18762, 1413.9787, -1750.7524, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[84], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[85] = CreateDynamicObject(18762, 1413.9787, -1745.7512, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[85], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[86] = CreateDynamicObject(18762, 1413.9781, -1744.7761, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[86], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[87] = CreateDynamicObject(18762, 1423.5196, -1744.7761, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[87], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[88] = CreateDynamicObject(18762, 1434.9809, -1744.7761, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[88], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[89] = CreateDynamicObject(18762, 1444.5124, -1744.7761, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[89], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[90] = CreateDynamicObject(18762, 1444.5124, -1749.7773, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[90], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[91] = CreateDynamicObject(18762, 1444.5124, -1754.7668, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[91], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[92] = CreateDynamicObject(18762, 1444.5124, -1759.7569, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[92], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[93] = CreateDynamicObject(18762, 1444.5118, -1764.2281, 12.9904, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[93], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[94] = CreateDynamicObject(18762, 1444.5118, -1774.6064, 12.9904, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[94], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[95] = CreateDynamicObject(18762, 1444.5124, -1780.6075, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[95], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[96] = CreateDynamicObject(18762, 1434.9809, -1749.7750, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[96], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[97] = CreateDynamicObject(18762, 1434.9801, -1752.8458, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[97], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[98] = CreateDynamicObject(18762, 1423.5268, -1752.8458, 12.9912, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[98], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[99] = CreateDynamicObject(18762, 1423.5196, -1749.7768, 12.9909, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[99], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[100] = CreateDynamicObject(19464, 1429.5034, -1765.7644, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[100], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[101] = CreateDynamicObject(19464, 1424.1412, -1765.7644, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[101], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[102] = CreateDynamicObject(19464, 1434.6330, -1765.7644, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[102], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[103] = CreateDynamicObject(19464, 1431.7822, -1768.6247, 10.0010, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[103], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[104] = CreateDynamicObject(18762, 1444.5124, -1766.2297, 14.9202, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[104], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[105] = CreateDynamicObject(18762, 1444.5124, -1772.5892, 14.9202, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[105], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[106] = CreateDynamicObject(18762, 1444.5113, -1769.6291, 16.9109, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[106], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[107] = CreateDynamicObject(18762, 1444.5118, -1769.2274, 16.9104, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[107], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[108] = CreateDynamicObject(18762, 1444.5129, -1778.7165, 12.9898, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[108], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[109] = CreateDynamicObject(1319, 1444.5599, -1769.4145, 13.0871, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_ref_bollard
	object_cityhallExterior[110] = CreateDynamicObject(19971, 1423.0487, -1742.2845, 17.9181, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[110], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[110], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[111] = CreateDynamicObject(19971, 1444.9986, -1772.5041, 16.9381, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[111], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[111], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[112] = CreateDynamicObject(18762, 1434.9908, -1742.7707, 14.9202, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[112], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[113] = CreateDynamicObject(19175, 1445.0218, -1769.5205, 16.9540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[113], 0, "Parkplatz", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[113], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[114] = CreateDynamicObject(18762, 1436.9997, -1742.7750, 17.9202, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[114], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[115] = CreateDynamicObject(18762, 1444.5113, -1742.7707, 15.9202, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[115], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[116] = CreateDynamicObject(18762, 1441.9831, -1742.7700, 17.9209, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[116], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[117] = CreateDynamicObject(18762, 1413.9803, -1742.7707, 15.9301, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[117], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[118] = CreateDynamicObject(18762, 1423.5112, -1742.7707, 14.9202, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[118], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[119] = CreateDynamicObject(18762, 1421.4908, -1742.7750, 17.9202, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[119], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[120] = CreateDynamicObject(18762, 1416.5522, -1742.7700, 17.9209, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[120], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[121] = CreateDynamicObject(19967, 1434.9681, -1742.2740, 12.3730, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
	SetDynamicObjectMaterial(object_cityhallExterior[121], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[122] = CreateDynamicObject(19967, 1444.4781, -1742.2740, 12.3730, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
	SetDynamicObjectMaterial(object_cityhallExterior[122], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[123] = CreateDynamicObject(19966, 1435.0041, -1743.2766, 12.6464, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign19
	SetDynamicObjectMaterial(object_cityhallExterior[123], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[124] = CreateDynamicObject(19966, 1444.5150, -1743.2766, 12.6464, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign19
	SetDynamicObjectMaterial(object_cityhallExterior[124], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[125] = CreateDynamicObject(19450, 1471.3996, -1764.6665, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[125], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[126] = CreateDynamicObject(19450, 1461.7884, -1764.6665, 10.7894, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[126], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[127] = CreateDynamicObject(19450, 1452.2198, -1764.6665, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[127], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[128] = CreateDynamicObject(19450, 1449.7983, -1764.6610, 10.7894, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[128], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[129] = CreateDynamicObject(19450, 1449.7983, -1774.1711, 10.7894, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[129], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[130] = CreateDynamicObject(19450, 1452.2198, -1774.1710, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[130], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[131] = CreateDynamicObject(19450, 1461.7884, -1774.1750, 10.7894, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[131], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[132] = CreateDynamicObject(19450, 1471.3996, -1774.1710, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[132], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[133] = CreateDynamicObject(19967, 1423.5183, -1743.2552, 12.3730, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
	SetDynamicObjectMaterial(object_cityhallExterior[133], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[134] = CreateDynamicObject(19967, 1413.9975, -1743.2552, 12.3730, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign20
	SetDynamicObjectMaterial(object_cityhallExterior[134], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[135] = CreateDynamicObject(19986, 1398.9542, -1737.4370, 12.3514, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign39
	object_cityhallExterior[136] = CreateDynamicObject(19979, 1398.9372, -1737.4370, 11.6243, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign32
	SetDynamicObjectMaterial(object_cityhallExterior[136], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[137] = CreateDynamicObject(19986, 1547.3055, -1726.8779, 12.3514, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign39
	object_cityhallExterior[138] = CreateDynamicObject(19979, 1547.3182, -1726.8868, 11.6243, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign32
	SetDynamicObjectMaterial(object_cityhallExterior[138], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[139] = CreateDynamicObject(19971, 1442.9980, -1742.2845, 17.9181, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[139], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[139], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[140] = CreateDynamicObject(19971, 1442.2978, -1742.2845, 17.9181, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[140], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[140], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[141] = CreateDynamicObject(19971, 1441.6070, -1742.2845, 17.9181, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[141], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[141], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[142] = CreateDynamicObject(19971, 1444.9986, -1771.7950, 16.9381, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[142], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[142], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[143] = CreateDynamicObject(19175, 1439.6622, -1742.2707, 17.9181, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[143], 0, "Ausfahrt", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[143], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[144] = CreateDynamicObject(19971, 1422.3492, -1742.2845, 17.9181, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[144], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[144], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[145] = CreateDynamicObject(19971, 1421.7989, -1742.2845, 17.9181, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[145], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[145], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[146] = CreateDynamicObject(19949, 1441.8524, -1727.4858, 12.6196, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign2
	object_cityhallExterior[147] = CreateDynamicObject(19175, 1419.8413, -1742.2707, 17.9440, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[147], 0, "Einfahrt", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[147], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[148] = CreateDynamicObject(19982, 1418.8039, -1742.2442, 17.8079, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign35
	SetDynamicObjectMaterial(object_cityhallExterior[148], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	SetDynamicObjectMaterial(object_cityhallExterior[148], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[148], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[149] = CreateDynamicObject(1290, 1481.4919, -1769.2882, 18.0979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost2
	object_cityhallExterior[150] = CreateDynamicObject(6965, 1523.8531, -1769.5583, 15.9531, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //venefountain02
	object_cityhallExterior[151] = CreateDynamicObject(11245, 1477.9790, -1803.5471, 22.2511, 0.0000, -8.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfsefirehseflag
	SetDynamicObjectMaterial(object_cityhallExterior[151], 0, 11008, "firehouse_sfse", "ws_usflagcrumpled", 0xFFFFFFFF);
	object_cityhallExterior[152] = CreateDynamicObject(19175, 1416.0295, -1742.2607, 17.6238, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[152], 0, "__", 130, "Arial", 50, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[152], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[153] = CreateDynamicObject(11245, 1484.6101, -1804.1827, 22.3173, 0.0000, -19.6000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfsefirehseflag
	SetDynamicObjectMaterial(object_cityhallExterior[153], 0, 11008, "firehouse_sfse", "ws_usflagcrumpled", 0xFFFFFFFF);
	object_cityhallExterior[154] = CreateDynamicObject(1226, 1537.9427, -1774.4625, 16.2865, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[155] = CreateDynamicObject(19175, 1416.1496, -1742.2550, 17.7138, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[155], 0, "<", 130, "Arial", 50, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[155], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[156] = CreateDynamicObject(19175, 1416.1396, -1742.2550, 18.1240, 0.0000, -90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[156], 0, "<", 130, "Arial", 50, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[156], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[157] = CreateDynamicObject(19175, 1416.0295, -1742.2607, 18.2140, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[157], 0, "__", 130, "Arial", 50, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[157], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[158] = CreateDynamicObject(736, 1490.8596, -1785.2506, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[159] = CreateDynamicObject(19986, 1423.4752, -1742.2674, 12.3514, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign39
	SetDynamicObjectMaterial(object_cityhallExterior[159], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[160] = CreateDynamicObject(19377, 1537.6844, -1769.4228, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[160], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[161] = CreateDynamicObject(19377, 1548.1352, -1769.4228, 12.4427, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[161], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[162] = CreateDynamicObject(19377, 1554.5864, -1769.4228, 12.4476, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[162], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[163] = CreateDynamicObject(6964, 1523.9365, -1769.4803, 12.0670, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //venefountwat02
	object_cityhallExterior[164] = CreateDynamicObject(6965, 1523.8531, -1769.5583, 16.2231, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //venefountain02
	SetDynamicObjectMaterial(object_cityhallExterior[164], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[164], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[164], 3, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[164], 4, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[164], 5, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[164], 6, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[164], 7, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[164], 8, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[165] = CreateDynamicObject(3515, 1528.7607, -1769.6279, 9.9898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsfountain
	object_cityhallExterior[166] = CreateDynamicObject(3515, 1518.6899, -1769.6279, 9.9898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsfountain
	object_cityhallExterior[167] = CreateDynamicObject(19377, 1514.5948, -1759.7827, 12.4448, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[167], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[168] = CreateDynamicObject(19377, 1525.0743, -1759.7827, 12.4504, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[168], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[169] = CreateDynamicObject(19377, 1533.7651, -1759.7827, 12.4476, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[169], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[170] = CreateDynamicObject(19377, 1533.7651, -1779.0522, 12.4476, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[170], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[171] = CreateDynamicObject(19377, 1523.2657, -1779.0522, 12.4530, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[171], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[172] = CreateDynamicObject(19377, 1514.6173, -1779.0522, 12.4476, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[172], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[173] = CreateDynamicObject(19450, 1491.5290, -1764.6665, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[173], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[174] = CreateDynamicObject(19450, 1501.1180, -1764.6665, 10.7894, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[174], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[175] = CreateDynamicObject(19450, 1504.6595, -1764.6610, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[175], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[176] = CreateDynamicObject(19450, 1504.6595, -1774.1927, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[176], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[177] = CreateDynamicObject(19450, 1491.5594, -1774.1927, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[177], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[178] = CreateDynamicObject(19450, 1496.7198, -1774.1970, 10.7889, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[178], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[179] = CreateDynamicObject(19450, 1543.7093, -1774.1927, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[179], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[180] = CreateDynamicObject(19450, 1554.7314, -1774.1927, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[180], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[181] = CreateDynamicObject(19450, 1549.3823, -1774.1970, 10.7889, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[181], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[182] = CreateDynamicObject(19450, 1554.7314, -1764.6208, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[182], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[183] = CreateDynamicObject(19450, 1549.3823, -1764.6262, 10.7889, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[183], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[184] = CreateDynamicObject(19450, 1543.6915, -1764.6208, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[184], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[185] = CreateDynamicObject(19450, 1538.9504, -1759.8902, 10.7896, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[185], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[186] = CreateDynamicObject(19450, 1538.9504, -1778.9112, 10.7896, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[186], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[187] = CreateDynamicObject(19450, 1509.4388, -1778.9112, 10.7896, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[187], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[188] = CreateDynamicObject(19450, 1509.4388, -1759.9316, 10.7889, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[188], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[189] = CreateDynamicObject(19450, 1514.1606, -1755.0500, 10.7896, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[189], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[190] = CreateDynamicObject(19450, 1523.7707, -1755.0500, 10.7917, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[190], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[191] = CreateDynamicObject(19450, 1533.3813, -1755.0500, 10.7910, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[191], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[192] = CreateDynamicObject(19450, 1534.2224, -1755.0600, 10.7917, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[192], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[193] = CreateDynamicObject(19450, 1534.2224, -1783.8017, 10.7917, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[193], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[194] = CreateDynamicObject(19450, 1524.6217, -1783.8017, 10.7924, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[194], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[195] = CreateDynamicObject(19450, 1515.0113, -1783.8017, 10.7929, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[195], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[196] = CreateDynamicObject(19450, 1514.1705, -1783.8060, 10.7910, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_cityhallExterior[196], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[197] = CreateDynamicObject(10631, 1549.4691, -1783.5821, 16.7998, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ammunation_SFS
	object_cityhallExterior[198] = CreateDynamicObject(18239, 1499.1213, -1758.1406, 12.5060, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); // Custom
	object_cityhallExterior[199] = CreateDynamicObject(789, 1416.1993, -1842.8155, 25.6730, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hashburytree4sfs
	object_cityhallExterior[200] = CreateDynamicObject(789, 1546.9604, -1847.3363, 25.6730, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hashburytree4sfs
	object_cityhallExterior[201] = CreateDynamicObject(16061, 1469.1811, -1855.8265, 12.1716, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //des_treeline2
	object_cityhallExterior[202] = CreateDynamicObject(16061, 1492.5605, -1855.8265, 12.1716, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //des_treeline2
	object_cityhallExterior[203] = CreateDynamicObject(1226, 1537.9427, -1764.6711, 16.2865, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[204] = CreateDynamicObject(1226, 1510.4233, -1764.4610, 16.2865, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[205] = CreateDynamicObject(11413, 1424.0284, -1838.4654, 14.1349, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fosterflowers1
	object_cityhallExterior[206] = CreateDynamicObject(7953, 1483.5461, -1860.7125, 13.1295, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //miragehedge04
	SetDynamicObjectMaterial(object_cityhallExterior[206], 0, 10368, "cathedral_sfs", "ws_woodyhedge", 0xFFFFFFFF);
	object_cityhallExterior[207] = CreateDynamicObject(17522, 1549.5128, -1757.1296, 14.6455, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gangshop7_lae2
	object_cityhallExterior[208] = CreateDynamicObject(736, 1471.2495, -1785.2506, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[209] = CreateDynamicObject(11413, 1538.0666, -1838.4654, 14.1349, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fosterflowers1
	object_cityhallExterior[210] = CreateDynamicObject(12951, 1500.6062, -1780.4936, 12.5205, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sw_shopflat01
	object_cityhallExterior[211] = CreateDynamicObject(4022, 1522.0239, -1749.9779, 15.4568, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Foodmart1_lan
	object_cityhallExterior[212] = CreateDynamicObject(708, 1499.5725, -1749.4404, 12.3177, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_veg_tree4_vbig
	object_cityhallExterior[213] = CreateDynamicObject(708, 1463.5118, -1749.4404, 12.3177, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_veg_tree4_vbig
	object_cityhallExterior[214] = CreateDynamicObject(1226, 1510.4233, -1774.1612, 16.2865, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[215] = CreateDynamicObject(1226, 1460.8038, -1770.6926, 16.2865, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[216] = CreateDynamicObject(1226, 1460.5035, -1768.2225, 16.2865, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[217] = CreateDynamicObject(18766, 1515.4499, -1789.0926, 13.0781, 0.0000, 0.0000, -26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[217], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_cityhallExterior[218] = CreateDynamicObject(18766, 1530.4748, -1789.8620, 13.0781, 0.0000, 0.0000, 26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[218], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_cityhallExterior[219] = CreateDynamicObject(18762, 1519.9637, -1790.7634, 13.4003, 0.0000, 0.0000, -26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[219], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[220] = CreateDynamicObject(18762, 1511.2219, -1786.4632, 13.4003, 0.0000, 0.0000, -26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[220], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[221] = CreateDynamicObject(18762, 1510.7840, -1787.3509, 13.4003, 0.0000, 0.0000, -26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[221], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[222] = CreateDynamicObject(18762, 1519.5272, -1791.6512, 13.4003, 0.0000, 0.0000, -26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[222], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[223] = CreateDynamicObject(18762, 1525.7375, -1791.5417, 13.4003, 0.0000, 0.0000, 26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[223], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[224] = CreateDynamicObject(18762, 1526.1789, -1792.4399, 13.4003, 0.0000, 0.0000, 26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[224], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[225] = CreateDynamicObject(18762, 1535.0030, -1788.1009, 13.4003, 0.0000, 0.0000, 26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[225], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[226] = CreateDynamicObject(18762, 1534.5627, -1787.2015, 13.4003, 0.0000, 0.0000, 26.1998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[226], 0, 14593, "papaerchaseoffice", "wall_stone3_256", 0xFFFFFFFF);
	object_cityhallExterior[227] = CreateDynamicObject(11414, 1457.5067, -1802.7818, 13.7931, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fosterflowers02
	object_cityhallExterior[228] = CreateDynamicObject(19986, 1413.9547, -1742.2674, 12.3514, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign39
	SetDynamicObjectMaterial(object_cityhallExterior[228], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[229] = CreateDynamicObject(869, 1431.7353, -1750.0156, 12.9951, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_cityhallExterior[230] = CreateDynamicObject(869, 1426.8546, -1745.3354, 12.9951, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_cityhallExterior[231] = CreateDynamicObject(817, 1430.9813, -1745.1656, 13.0584, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
	object_cityhallExterior[232] = CreateDynamicObject(817, 1426.5205, -1750.0963, 13.0584, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
	object_cityhallExterior[233] = CreateDynamicObject(672, 1429.3696, -1747.8398, 13.3013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_veg_tree5
	object_cityhallExterior[234] = CreateDynamicObject(19971, 1436.6468, -1743.2746, 17.9181, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[234], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[234], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[235] = CreateDynamicObject(19971, 1435.9364, -1743.2746, 17.9181, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[235], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[235], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[236] = CreateDynamicObject(19175, 1439.8520, -1743.3005, 17.9181, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[236], 0, "Auf Wiedersehen!", 130, "Arial", 70, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[236], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[237] = CreateDynamicObject(19971, 1438.5156, -1743.2746, 17.9181, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[237], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[237], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[238] = CreateDynamicObject(19464, 1443.9881, -1779.3249, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[238], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[239] = CreateDynamicObject(19464, 1439.3479, -1779.3249, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[239], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[240] = CreateDynamicObject(19464, 1434.6362, -1779.3249, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[240], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[241] = CreateDynamicObject(19464, 1424.1446, -1779.3249, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[241], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[242] = CreateDynamicObject(19464, 1414.5332, -1779.3249, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[242], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[243] = CreateDynamicObject(19464, 1419.3725, -1779.3249, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[243], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[244] = CreateDynamicObject(19464, 1429.5034, -1779.3249, 10.0003, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[244], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[245] = CreateDynamicObject(19464, 1441.0389, -1782.1363, 10.0010, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[245], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[246] = CreateDynamicObject(19464, 1417.4071, -1782.1363, 10.0010, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[246], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[247] = CreateDynamicObject(19464, 1423.2778, -1782.1400, 10.0015, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[247], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[248] = CreateDynamicObject(19464, 1429.1877, -1782.1357, 10.0010, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[248], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[249] = CreateDynamicObject(708, 1553.6334, -1781.2508, 12.3177, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_veg_tree4_vbig
	object_cityhallExterior[250] = CreateDynamicObject(19464, 1435.1191, -1782.1400, 10.0015, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[250], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[251] = CreateDynamicObject(708, 1404.8725, -1792.2004, 12.3177, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_veg_tree4_vbig
	object_cityhallExterior[252] = CreateDynamicObject(691, 1426.4350, -1787.2746, 11.4174, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_veg_tree4_big
	object_cityhallExterior[253] = CreateDynamicObject(1226, 1443.3342, -1773.8811, 15.3465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[254] = CreateDynamicObject(618, 1533.0853, -1800.9991, 12.3850, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_treea3
	object_cityhallExterior[255] = CreateDynamicObject(1226, 1443.3342, -1765.7115, 15.3465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[256] = CreateDynamicObject(1226, 1415.1933, -1765.3812, 15.3465, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[257] = CreateDynamicObject(1226, 1415.1933, -1775.8608, 15.3465, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[258] = CreateDynamicObject(1226, 1422.3725, -1754.7602, 15.3465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[259] = CreateDynamicObject(1226, 1436.1429, -1754.4798, 15.3465, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lamppost3
	object_cityhallExterior[260] = CreateDynamicObject(19971, 1432.0377, -1782.0985, 12.2880, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[260], 2, 3119, "cs_ry_props", "lightgrey", 0xFF3B4E78);
	object_cityhallExterior[261] = CreateDynamicObject(19971, 1441.5792, -1782.0985, 12.2880, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[261], 2, 3119, "cs_ry_props", "lightgrey", 0xFF3B4E78);
	object_cityhallExterior[262] = CreateDynamicObject(19971, 1436.9289, -1782.0985, 12.2880, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[262], 2, 3119, "cs_ry_props", "lightgrey", 0xFF3B4E78);
	object_cityhallExterior[263] = CreateDynamicObject(19971, 1426.7976, -1782.0985, 12.2880, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[263], 2, 3119, "cs_ry_props", "lightgrey", 0xFF3B4E78);
	object_cityhallExterior[264] = CreateDynamicObject(19971, 1421.7872, -1782.0985, 12.2880, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[264], 2, 3119, "cs_ry_props", "lightgrey", 0xFF3B4E78);
	object_cityhallExterior[265] = CreateDynamicObject(19971, 1416.8868, -1782.0985, 12.2880, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[265], 2, 3119, "cs_ry_props", "lightgrey", 0xFF3B4E78);
	object_cityhallExterior[266] = CreateDynamicObject(19175, 1441.5622, -1782.0810, 14.9040, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[266], 0, "P", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[266], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[267] = CreateDynamicObject(19175, 1436.9217, -1782.0810, 14.9040, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[267], 0, "P", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[267], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[268] = CreateDynamicObject(19175, 1432.0306, -1782.0810, 14.9040, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[268], 0, "P", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[268], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[269] = CreateDynamicObject(19175, 1426.7899, -1782.0810, 14.9040, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[269], 0, "P", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[269], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[270] = CreateDynamicObject(19175, 1421.7784, -1782.0810, 14.9040, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[270], 0, "P", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[270], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[271] = CreateDynamicObject(19175, 1416.8769, -1782.0810, 14.9040, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[271], 0, "P", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[271], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[272] = CreateDynamicObject(19175, 1436.9206, -1782.0810, 14.6140, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[272], 0, "Besucher", 130, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[272], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[273] = CreateDynamicObject(19175, 1432.0289, -1782.0810, 14.6140, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[273], 0, "Besucher", 130, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[273], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[274] = CreateDynamicObject(19377, 1580.6180, -1747.3243, 5.6363, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[274], 0, 16093, "a51_ext", "BLOCK2", 0xFFFFFFFF);
	object_cityhallExterior[275] = CreateDynamicObject(19377, 1410.1745, -1716.6450, 5.6963, 0.0000, 0.0000, -6.2999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[275], 0, 16093, "a51_ext", "BLOCK2", 0xFFFFFFFF);
	object_cityhallExterior[276] = CreateDynamicObject(19377, 1580.6180, -1756.9350, 5.6363, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[276], 0, 16093, "a51_ext", "BLOCK2", 0xFFFFFFFF);
	object_cityhallExterior[277] = CreateDynamicObject(19377, 1411.2329, -1707.0625, 5.6963, 0.0000, 0.0000, -6.2999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall025
	SetDynamicObjectMaterial(object_cityhallExterior[277], 0, 16093, "a51_ext", "BLOCK2", 0xFFFFFFFF);
	object_cityhallExterior[278] = CreateDynamicObject(19175, 1426.7884, -1782.0810, 14.6140, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[278], 0, "Besucher", 130, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[278], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[279] = CreateDynamicObject(19175, 1421.7772, -1782.0810, 14.6140, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[279], 0, "Besucher", 130, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[279], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[280] = CreateDynamicObject(19175, 1416.8852, -1782.0810, 14.6140, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[280], 0, "Besucher", 130, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[280], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[281] = CreateDynamicObject(19175, 1441.5721, -1782.0810, 14.6140, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[281], 0, "Besucher", 130, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[281], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[282] = CreateDynamicObject(19971, 1444.0279, -1766.2248, 16.9381, 0.0000, 90.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[282], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[282], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[283] = CreateDynamicObject(19971, 1444.0279, -1766.9156, 16.9381, 0.0000, 90.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[283], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[283], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[284] = CreateDynamicObject(19175, 1444.0113, -1769.1495, 16.9540, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[284], 0, "Zur Stadthalle", 90, "Arial", 35, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[284], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[285] = CreateDynamicObject(19971, 1444.0279, -1767.3955, 16.9381, 0.0000, 90.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[285], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[285], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[286] = CreateDynamicObject(19971, 1444.0279, -1765.6655, 16.9381, 0.0000, 90.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
	SetDynamicObjectMaterial(object_cityhallExterior[286], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[286], 2, 3119, "cs_ry_props", "lightgrey", 0xFFD78E10);
	object_cityhallExterior[287] = CreateDynamicObject(1280, 1515.3437, -1776.6833, 12.9097, 0.0000, 0.0000, 40.0998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
	object_cityhallExterior[288] = CreateDynamicObject(1280, 1515.0046, -1762.5450, 12.9097, 0.0000, 0.0000, -40.0998, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
	object_cityhallExterior[289] = CreateDynamicObject(1280, 1532.4432, -1762.5758, 12.9097, 0.0000, 0.0000, -141.1000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
	object_cityhallExterior[290] = CreateDynamicObject(1280, 1532.6494, -1776.6291, 12.9097, 0.0000, 0.0000, 140.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
	object_cityhallExterior[291] = CreateDynamicObject(19175, 1532.9315, -1788.1075, 14.7776, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[291], 0, "Ein", 90, "Arial", 85, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[291], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[292] = CreateDynamicObject(19175, 1514.8763, -1788.2451, 13.2271, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[292], 0, "LyD -", 90, "Arial", 40, 1, 0xFF86446E, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[292], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[293] = CreateDynamicObject(19175, 1532.4382, -1788.3509, 13.5874, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[293], 0, "- an die", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[293], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[294] = CreateDynamicObject(19175, 1527.8032, -1790.6273, 14.7776, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[294], 0, "Danke...", 90, "Arial", 75, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[294], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[295] = CreateDynamicObject(19175, 1532.4012, -1788.3680, 13.9673, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[295], 0, "- an alle", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[295], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[296] = CreateDynamicObject(19175, 1530.7508, -1789.1811, 13.9673, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[296], 0, "ehemaligen", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[296], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[297] = CreateDynamicObject(19175, 1528.4162, -1790.3277, 13.9673, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[297], 0, "Teammitglieder", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[297], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[298] = CreateDynamicObject(19175, 1532.4388, -1788.3524, 13.0775, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[298], 0, "für Ihre Treue", 90, "Arial", 30, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[298], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[299] = CreateDynamicObject(19175, 1531.0185, -1789.0483, 13.5874, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[299], 0, "gesamte", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[299], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[300] = CreateDynamicObject(19175, 1529.3039, -1789.8922, 13.5874, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[300], 0, "Community", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[300], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[301] = CreateDynamicObject(19175, 1513.5311, -1787.5842, 14.7776, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[301], 0, "Lob...", 90, "Arial", 85, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[301], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[302] = CreateDynamicObject(19175, 1528.3780, -1790.3454, 13.0775, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[302], 0, "und Ihr Engagement", 90, "Arial", 30, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[302], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[303] = CreateDynamicObject(19175, 1518.0030, -1789.7827, 14.7776, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[303], 0, "Ein ", 90, "Arial", 85, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[303], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[304] = CreateDynamicObject(19175, 1515.9641, -1788.7806, 14.7776, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[304], 0, "großes", 90, "Arial", 85, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[304], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[305] = CreateDynamicObject(19175, 1517.0041, -1789.2933, 13.9673, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[305], 0, "- an die", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[305], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[306] = CreateDynamicObject(19175, 1531.2164, -1788.9514, 14.7776, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[306], 0, "herzlic", 90, "Arial", 75, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[306], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[307] = CreateDynamicObject(19175, 1529.7351, -1789.6800, 14.7776, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[307], 0, "hes", 90, "Arial", 75, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[307], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[308] = CreateDynamicObject(19175, 1515.2801, -1788.4458, 13.9673, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[308], 0, "Projektleitung ", 90, "Arial", 40, 1, 0xFF840410, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[308], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[309] = CreateDynamicObject(19175, 1517.7502, -1789.6584, 13.6076, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[309], 0, "- an das ", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[309], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[310] = CreateDynamicObject(19175, 1516.1876, -1788.8907, 13.6176, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[310], 0, "engagierte", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[310], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[311] = CreateDynamicObject(19175, 1517.7502, -1789.6584, 13.2573, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[311], 0, "- an das ", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[311], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[312] = CreateDynamicObject(19175, 1513.4559, -1787.5483, 13.6176, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[312], 0, "Team", 90, "Arial", 40, 1, 0xFF335F3F, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[312], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[313] = CreateDynamicObject(19175, 1516.2501, -1788.9211, 13.2573, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[313], 0, "tatkräftige", 90, "Arial", 40, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[313], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[314] = CreateDynamicObject(19464, 1426.9809, -1768.6274, 10.0017, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_cityhallExterior[314], 0, 3119, "cs_ry_props", "lightgrey", 0xFFFFFFFF);
	object_cityhallExterior[315] = CreateDynamicObject(19175, 1514.6062, -1788.1136, 13.6176, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[315], 0, "Mapper -", 90, "Arial", 40, 1, 0xFF335F3F, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[315], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[316] = CreateDynamicObject(973, 1492.4333, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[317] = CreateDynamicObject(19175, 1513.9775, -1787.8039, 13.2271, 0.0000, 0.0000, 153.8000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[317], 0, "Team", 90, "Arial", 40, 1, 0xFF86446E, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[317], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[318] = CreateDynamicObject(973, 1470.9631, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[319] = CreateDynamicObject(973, 1450.8026, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[320] = CreateDynamicObject(973, 1460.8431, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[321] = CreateDynamicObject(973, 1502.6446, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[322] = CreateDynamicObject(973, 1512.8956, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[323] = CreateDynamicObject(973, 1535.3070, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[324] = CreateDynamicObject(973, 1554.8679, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[325] = CreateDynamicObject(973, 1545.1789, -1742.3663, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[326] = CreateDynamicObject(973, 1559.2972, -1747.0766, 13.3142, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[327] = CreateDynamicObject(973, 1559.2972, -1800.5672, 13.3142, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[328] = CreateDynamicObject(973, 1559.2972, -1811.0976, 13.3142, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[329] = CreateDynamicObject(973, 1559.2972, -1821.6278, 13.3142, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[330] = CreateDynamicObject(973, 1559.2972, -1832.0179, 13.3142, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[331] = CreateDynamicObject(973, 1559.1074, -1842.1777, 13.3142, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[332] = CreateDynamicObject(973, 1399.3531, -1842.1777, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[333] = CreateDynamicObject(973, 1399.2331, -1832.2574, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[334] = CreateDynamicObject(973, 1399.2331, -1821.8968, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[335] = CreateDynamicObject(973, 1399.2331, -1811.2464, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[336] = CreateDynamicObject(973, 1399.2331, -1801.0356, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[337] = CreateDynamicObject(973, 1399.2331, -1790.0760, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[338] = CreateDynamicObject(973, 1399.2331, -1779.4659, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[339] = CreateDynamicObject(973, 1399.2331, -1769.0157, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[340] = CreateDynamicObject(973, 1399.2331, -1758.3249, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[341] = CreateDynamicObject(973, 1399.2331, -1747.9952, 13.3142, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[342] = CreateDynamicObject(973, 1405.8636, -1742.4443, 13.3142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
	object_cityhallExterior[343] = CreateDynamicObject(1319, 1559.4184, -1769.4145, 13.0871, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_ref_bollard
	object_cityhallExterior[344] = CreateDynamicObject(1319, 1559.4184, -1771.7241, 13.0871, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_ref_bollard
	object_cityhallExterior[345] = CreateDynamicObject(1319, 1559.4184, -1767.1434, 13.0871, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_ref_bollard
	object_cityhallExterior[346] = CreateDynamicObject(1319, 1481.5583, -1742.3935, 13.0871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_ref_bollard
	object_cityhallExterior[347] = CreateDynamicObject(1319, 1484.3597, -1742.3935, 13.0871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_ref_bollard
	object_cityhallExterior[348] = CreateDynamicObject(1319, 1478.7893, -1742.3935, 13.0871, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ws_ref_bollard
	object_cityhallExterior[349] = CreateDynamicObject(18766, 1418.6667, -1742.7927, 10.0612, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[349], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
	object_cityhallExterior[350] = CreateDynamicObject(18766, 1439.9886, -1742.7927, 10.0612, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_cityhallExterior[350], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
	object_cityhallExterior[351] = CreateDynamicObject(19175, 1530.6245, -1789.2430, 13.0775, 0.0000, 0.0000, 206.1999, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[351], 0, ". Ihre Loyalität", 90, "Arial", 30, 1, 0xFFD78E10, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[351], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[352] = CreateDynamicObject(11414, 1504.1665, -1809.3912, 13.7931, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fosterflowers02
	object_cityhallExterior[353] = CreateDynamicObject(736, 1471.2495, -1778.2110, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[354] = CreateDynamicObject(736, 1490.8985, -1778.2110, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[355] = CreateDynamicObject(736, 1490.8985, -1792.9410, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	object_cityhallExterior[356] = CreateDynamicObject(736, 1470.3282, -1792.9410, 23.4013, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ceasertree01_lvs
	
	// Solid objects
	object_cityhallExterior[357] = CreateDynamicObject(18981, 1432.5223, -1770.1206, 12.0256, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_cityhallExterior[357], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[358] = CreateDynamicObject(18981, 1426.8801, -1770.1206, 12.0257, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_cityhallExterior[358], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	
	object_cityhallExterior[359] = CreateDynamicObject(19982, 1418.8039, -1742.2442, 18.0279, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign35
	SetDynamicObjectMaterial(object_cityhallExterior[359], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	SetDynamicObjectMaterial(object_cityhallExterior[359], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_cityhallExterior[359], 2, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_cityhallExterior[360] = CreateDynamicObject(19175, 1416.1396, -1742.2607, 17.9181, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_cityhallExterior[360], 0, "5 m", 90, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_cityhallExterior[360], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);

	// Custom Door Objects:
	object_cityhallExterior[361] = CreateDynamicObject(1532, 1522.1401, -1754.8687, 12.5363, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_cityhallExterior[362] = CreateDynamicObject(1556, 1549.2960, -1774.6709, 12.8107, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_CITYHALLEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}