#include <YSI\y_hooks>

// Global interior define
#define MAPS_NINEDEMONSBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Nine Demons base points
#define NINEDEMONSBASE_SAFEBOX_POINT        195.4771, -226.3883, 1.7786
#define NINEDEMONSBASE_SPAWN_POINT          195.1181, -232.7614, 1.7786
#define NINEDEMONSBASE_SPAWN_POINT_FACING   260.0

// Map variables
new object_nineDemonsBase[75];
new pickup_nineDemonsBase[2];
new text3D_nineDemonsBase[2];
new vehicle_nineDemonsBase[17];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 1412, 192.811, -263.842, 1.812, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 195.460, -271.820, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 200.742, -271.820, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 781, 196.772, -267.601, 0.453, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 192.906, -269.125, 1.843, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 209.570, -271.834, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 222.789, -263.851, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 214.843, -271.820, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 220.125, -271.795, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 222.804, -269.125, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 192.811, -254.804, 1.827, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 222.796, -253.296, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 222.796, -258.570, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 192.811, -249.531, 1.827, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 222.781, -248.022, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 192.811, -244.250, 1.827, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 192.914, -238.975, 1.820, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 222.804, -238.945, 1.850, 0.250);
    RemoveBuildingForPlayer(playerid, 1412, 215.000, -224.000, 2.023, 0.250);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_nineDemonsBase[0] = CreateDynamicPickup(1279, 1, NINEDEMONSBASE_SAFEBOX_POINT, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR); // Safebox point
    pickup_nineDemonsBase[1] = CreateDynamicPickup(1240, 1, NINEDEMONSBASE_SPAWN_POINT, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR); // Spawn point

    // 3DTextLabels
    text3D_nineDemonsBase[0] = _:CreateDynamic3DTextLabel("Nine Demons Spawn\n" COLOR_HEX_WHITE "Tippe /Ninowaffen zum Ausrüsten\nTippe /Gheilen zum Heilen\nTippe /Fskin für Skins", COLOR_BLUE, NINEDEMONSBASE_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NINEDEMONSBASE_INTERIOR);
    text3D_nineDemonsBase[1] = _:CreateDynamic3DTextLabel("Safebox der Nine Demons\n" COLOR_HEX_WHITE "Tippe /FSafebox", COLOR_YELLOW, NINEDEMONSBASE_SAFEBOX_POINT, 8.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NINEDEMONSBASE_INTERIOR);
    
    // Vehicles
    vehicle_nineDemonsBase[0] = AddStaticVehicleEx(541, 217.9363, -227.8569, 1.3853, 92.5174, 245, 245, -1); // BulletND
    vehicle_nineDemonsBase[1] = AddStaticVehicleEx(480, 218.0209, -232.5769, 1.5525, 91.4395, 245, 245, -1); // CometND
    vehicle_nineDemonsBase[2] = AddStaticVehicleEx(522, 213.0874, -234.8764, 1.3403, 90.3355, 245, 245, -1); // NRGND
    vehicle_nineDemonsBase[3] = AddStaticVehicleEx(468, 209.7309, -234.8420, 1.4437, 88.0967, 245, 245, -1); // SanchezND
    vehicle_nineDemonsBase[4] = AddStaticVehicleEx(478, 195.6311, -238.7896, 1.5743, 179.6374, 245, 245, -1); // BauernCarND
    vehicle_nineDemonsBase[5] = AddStaticVehicleEx(415, 210.5283, -249.6457, 1.3624, 90.4343, 245, 245, -1); // CheetahND
    vehicle_nineDemonsBase[6] = AddStaticVehicleEx(463, 220.9234, -238.1276, 1.1187, 85.3139, 245, 245, -1); // Freeway3ND
    vehicle_nineDemonsBase[7] = AddStaticVehicleEx(463, 221.0327, -241.4651, 1.1187, 87.9480, 245, 245, -1); // Freeway2ND
    vehicle_nineDemonsBase[8] = AddStaticVehicleEx(463, 220.9090, -244.5990, 1.1186, 91.1105, 245, 245, -1); // Freeway1ND
    vehicle_nineDemonsBase[9] = AddStaticVehicleEx(489, 219.4961, -250.9043, 1.7208, 118.7248, 245, 245, -1); // RancherND
    vehicle_nineDemonsBase[10] = AddStaticVehicleEx(487, 215.3044, -229.1679, 8.2553, 180.0780, 245, 245, -1); // NineDemonsHELI
    vehicle_nineDemonsBase[11] = AddStaticVehicleEx(482, 219.9123, -255.2900, 1.6960, 121.6129, 245, 245, -1); // BurritoND
    vehicle_nineDemonsBase[12] = AddStaticVehicleEx(411, 220.1589, -260.3581, 1.3074, 87.8231, 245, 245, -1); // InfernusND2
    vehicle_nineDemonsBase[13] = AddStaticVehicleEx(411, 220.1015, -265.4549, 1.3063, 90.8219, 245, 245, -1); // InfernusND
    vehicle_nineDemonsBase[14] = AddStaticVehicleEx(560, 209.3702, -269.2930, 1.2907, 2.0122, 245, 245, -1); // SultanND3
    vehicle_nineDemonsBase[15] = AddStaticVehicleEx(560, 205.2984, -269.1839, 1.2935, 359.4737, 245, 245, -1); // SultanND2
    vehicle_nineDemonsBase[16] = AddStaticVehicleEx(560, 201.5378, -269.1252, 1.2845, 1.3342, 245, 245, -1); // SultanND

    // Objects
    object_nineDemonsBase[0] = CreateDynamicObject(1491, 199.009857, -235.812438, 0.796140, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[1] = CreateDynamicObject(970, 201.376373, -227.708404, 1.331830, 0.000000, 0.000000, 270.673248, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[2] = CreateDynamicObject(1437, 198.494155, -239.793762, 2.081965, -26.599998, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[3] = CreateDynamicObject(970, 214.737533, -224.308074, 1.383280, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[4] = CreateDynamicObject(19124, 217.279953, -224.190505, 1.280089, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[5] = CreateDynamicObject(19124, 212.271789, -224.210159, 1.280089, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[6] = CreateDynamicObject(2315, 194.170852, -226.396453, 0.776278, 0.000000, 0.000000, 58.237819, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[7] = CreateDynamicObject(4100, 202.495193, -271.821563, 1.095659, 0.000000, 0.000000, 319.998809, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[8] = CreateDynamicObject(4100, 192.832565, -241.665039, 1.095659, 0.000000, 0.000000, 49.894851, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[9] = CreateDynamicObject(4100, 222.818969, -256.734130, 1.095659, 0.000000, 0.000000, 49.894851, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[10] = CreateDynamicObject(19124, 222.787322, -271.369720, 1.090299, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[11] = CreateDynamicObject(4100, 222.787338, -263.618988, 1.095659, 0.000000, 0.000000, 49.894851, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[12] = CreateDynamicObject(4100, 216.229751, -271.822937, 1.095659, 0.000000, 0.000000, 319.998809, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[13] = CreateDynamicObject(19124, 192.870010, -271.759918, 0.984160, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[14] = CreateDynamicObject(19124, 194.876419, -271.764648, 0.984160, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[15] = CreateDynamicObject(19124, 193.905502, -271.759674, 0.984160, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[16] = CreateDynamicObject(4100, 222.858306, -243.029678, 1.095659, 0.000000, 0.000000, 49.894851, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[17] = CreateDynamicObject(19124, 193.238433, -248.590362, 0.983160, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[18] = CreateDynamicObject(3928, 215.353256, -229.640045, 7.078618, 0.000000, 0.000000, -90.600013, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[19] = CreateDynamicObject(3928, 200.963973, -229.489379, 6.088613, 0.000000, 0.000000, -90.600013, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[20] = CreateDynamicObject(1279, 194.080093, -226.351013, 1.268617, 0.000000, 0.000000, -73.400001, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[21] = CreateDynamicObject(970, 220.787384, -243.288024, 1.073279, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[22] = CreateDynamicObject(970, 220.787384, -239.888046, 1.073279, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[23] = CreateDynamicObject(1580, 194.980300, -224.942779, 1.248618, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[24] = CreateDynamicObject(1580, 194.770309, -225.127243, 1.342775, 22.000001, -4.799999, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[25] = CreateDynamicObject(350, 194.417343, -225.595352, 1.326141, -90.999954, 1.399999, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[26] = CreateDynamicObject(350, 194.413681, -225.745269, 1.328758, -90.999954, 1.399999, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[27] = CreateDynamicObject(350, 194.410018, -225.895187, 1.331377, -90.999954, 1.399999, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[28] = CreateDynamicObject(19425, 193.047348, -250.499816, 0.578125, 0.000000, 0.000000, -90.100028, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[29] = CreateDynamicObject(19425, 193.041656, -253.789871, 0.578125, 0.000000, 0.000000, -90.100028, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[30] = CreateDynamicObject(19425, 202.611145, -235.479507, 0.757709, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[31] = CreateDynamicObject(19425, 205.911132, -235.479507, 0.757709, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[32] = CreateDynamicObject(19425, 193.035827, -257.079772, 0.578125, 0.000000, 0.000000, -90.100028, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[33] = CreateDynamicObject(19425, 193.030075, -260.339752, 0.578125, 0.000000, 0.000000, -90.100028, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[34] = CreateDynamicObject(19425, 215.600585, -245.463150, 0.578125, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[35] = CreateDynamicObject(19425, 193.024475, -263.509307, 0.578125, 0.000000, 0.000000, -90.100028, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[36] = CreateDynamicObject(19425, 200.480682, -245.503112, 0.578125, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[37] = CreateDynamicObject(19425, 200.480682, -248.903076, 0.578125, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[38] = CreateDynamicObject(19425, 193.018737, -266.799377, 0.578125, 0.000000, 0.000000, -90.100028, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[39] = CreateDynamicObject(19425, 203.770645, -248.903076, 0.578125, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[40] = CreateDynamicObject(19425, 193.013153, -269.979339, 0.578125, 0.000000, 0.000000, -90.100028, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[41] = CreateDynamicObject(19425, 215.600585, -248.873123, 0.578125, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[42] = CreateDynamicObject(19425, 203.780761, -245.503112, 0.578125, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[43] = CreateDynamicObject(2047, 200.957443, -232.273925, 3.348617, 0.000000, 0.000000, -89.999977, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[44] = CreateDynamicObject(19164, 195.801467, -230.056106, 3.056881, 89.200027, 90.799957, -91.899993, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[45] = CreateDynamicObject(3111, 198.878356, -230.059906, 2.961708, 89.599960, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[46] = CreateDynamicObject(1703, 200.802276, -229.269088, 0.778617, 0.000000, 0.000000, -179.699996, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[47] = CreateDynamicObject(1703, 198.352371, -229.281906, 0.778617, 0.000000, 0.000000, -179.699996, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[48] = CreateDynamicObject(1429, 198.195617, -224.760971, 1.508618, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[49] = CreateDynamicObject(2315, 197.447021, -224.867523, 0.776278, 0.000000, 0.000000, -0.162171, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[50] = CreateDynamicObject(2315, 194.001632, -233.404693, 0.776278, 0.000000, 0.000000, 89.737808, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[51] = CreateDynamicObject(372, 193.796401, -231.889892, 1.316097, -88.999992, 4.499999, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[52] = CreateDynamicObject(372, 193.769180, -233.389205, 1.320075, -88.999992, 3.399998, -5.300000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[53] = CreateDynamicObject(351, 193.727905, -232.255310, 1.314736, 89.299964, -46.400012, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[54] = CreateDynamicObject(358, 193.718841, -232.503799, 0.850578, -85.200004, 0.000000, 14.400004, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[55] = CreateDynamicObject(358, 193.789566, -233.061004, 0.914169, -85.200004, 0.000000, 14.400004, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[56] = CreateDynamicObject(3014, 194.017044, -230.651184, 0.778617, 0.000000, 0.000000, -133.699981, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[57] = CreateDynamicObject(3014, 193.945938, -234.596939, 0.807519, -0.799998, 0.000000, -59.399959, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[58] = CreateDynamicObject(19857, 192.782272, -227.531341, 2.068123, 0.000000, 0.000000, -88.899993, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[59] = CreateDynamicObject(1437, 198.494155, -241.038024, 0.401200, -26.599998, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[60] = CreateDynamicObject(1703, 198.124053, -230.525573, 0.778617, 0.000000, 0.000000, -1.199978, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[61] = CreateDynamicObject(19967, 208.108459, -236.344757, 0.508125, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[62] = CreateDynamicObject(1977, 197.328125, -230.306167, 0.778618, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[63] = CreateDynamicObject(355, 197.144744, -230.086486, 1.458618, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[64] = CreateDynamicObject(356, 197.094070, -230.087677, 1.778618, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[65] = CreateDynamicObject(349, 197.035644, -230.135818, 2.058617, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[66] = CreateDynamicObject(352, 197.186920, -230.051849, 2.438618, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[67] = CreateDynamicObject(1550, 193.624618, -229.528244, 1.208618, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[68] = CreateDynamicObject(1550, 193.577575, -229.127426, 1.208618, 0.000000, 0.000000, -60.200004, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[69] = CreateDynamicObject(11737, 199.945556, -234.827362, 0.770960, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[70] = CreateDynamicObject(970, 219.587570, -230.158035, 1.383280, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[71] = CreateDynamicObject(970, 217.567367, -230.158035, 1.383280, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[72] = CreateDynamicObject(19124, 215.331848, -230.150207, 1.410088, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[73] = CreateDynamicObject(19124, 221.861801, -230.150207, 1.410088, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_nineDemonsBase[74] = CreateDynamicObject(19967, 201.258499, -236.344757, 0.508125, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_NINEDEMONSBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}