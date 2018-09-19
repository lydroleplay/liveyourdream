#include <YSI\y_hooks>

// Global interior define
#define MAPS_NOOBSPAWN_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Bike rental in LS points
#define NOOBSPAWN_STARTBONUS_POINT   809.3212, -1339.9855, 13.5408
#define NOOBSPAWN_SERVERINFO_POINT   817.4735, -1345.8376, 13.5269

// Map variables
new object_noobSpawn[170];
new pickup_noobSpawn[2];
new text3D_noobSpawn[2];
new actor_noobSpawn[2];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(NOOBSPAWN_STARTBONUS_POINT, 38, 0, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // S icon for spawn

    // Pickups
    pickup_noobSpawn[0] = CreateDynamicPickup(1239, 1, NOOBSPAWN_SERVERINFO_POINT, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // Server info point
    pickup_noobSpawn[1] = CreateDynamicPickup(1239, 1, NOOBSPAWN_STARTBONUS_POINT, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR); // Start bonus point

    // 3DTextLabels
    text3D_noobSpawn[0] = _:CreateDynamic3DTextLabel("Server Informationen\n" COLOR_HEX_WHITE "Tippe /Info", COLOR_GREEN, NOOBSPAWN_SERVERINFO_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR);
    text3D_noobSpawn[1] = _:CreateDynamic3DTextLabel("Startbonus\n" COLOR_HEX_RED "Tippe: /Startbonus", COLOR_GREEN, NOOBSPAWN_STARTBONUS_POINT, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR);

    actor_noobSpawn[0] = CreateDynamicActor(150, 809.7925, -1338.9929, 13.5400, 255.5065, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR); // Greeting woman
    ApplyDynamicActorAnimation(actor_noobSpawn[0], "PED", "endchat_03", 4.0, 1, 0, 0, 0, 0);
    actor_noobSpawn[1] = CreateDynamicActor(141, 816.6170, -1345.5221, 13.5283, 271.2476, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR); // Information woman

	// Objects
    object_noobSpawn[0] = CreateDynamicObject(19124, 904.9968, -1277.2143, 14.1455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_noobSpawn[1] = CreateDynamicObject(19124, 900.0770, -1277.2143, 14.1455, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_noobSpawn[2] = CreateDynamicObject(19124, 925.7747, -1295.0367, 13.3451, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_noobSpawn[3] = CreateDynamicObject(19124, 917.5244, -1303.3651, 13.3851, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_noobSpawn[4] = CreateDynamicObject(19124, 899.8048, -1260.3420, 18.8080, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_noobSpawn[5] = CreateDynamicObject(19124, 899.7750, -1276.7237, 18.7980, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_noobSpawn[6] = CreateDynamicObject(19124, 921.3859, -1276.7237, 18.7980, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_noobSpawn[7] = CreateDynamicObject(3934, 922.1994, -1180.6002, 15.9624, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_noobSpawn[8] = CreateDynamicObject(19903, 902.0206, -1259.8680, 13.8950, 0.0000, 0.0000, 89.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
    object_noobSpawn[9] = CreateDynamicObject(19903, 903.5609, -1259.8813, 13.8950, 0.0000, 0.0000, 89.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
    object_noobSpawn[10] = CreateDynamicObject(19903, 905.0413, -1259.8945, 13.8950, 0.0000, 0.0000, 89.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
    object_noobSpawn[11] = CreateDynamicObject(970, 899.6655, -1258.1549, 14.4975, 0.0000, 0.0000, -91.3999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[12] = CreateDynamicObject(19934, 900.6350, -1259.9770, 13.9370, 0.0000, 0.0000, -90.5998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKCupboard1
    object_noobSpawn[13] = CreateDynamicObject(2609, 906.5905, -1259.9056, 14.5825, 0.0000, 0.0000, -179.8000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_P_FILEING1
    object_noobSpawn[14] = CreateDynamicObject(2609, 906.1405, -1259.9072, 14.5825, 0.0000, 0.0000, -179.8000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_P_FILEING1
    object_noobSpawn[15] = CreateDynamicObject(2609, 907.0205, -1259.9039, 14.5825, 0.0000, 0.0000, -179.8000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_P_FILEING1
    object_noobSpawn[16] = CreateDynamicObject(19124, 899.7047, -1255.9416, 14.4580, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_noobSpawn[17] = CreateDynamicObject(970, 888.0208, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[18] = CreateDynamicObject(970, 829.3300, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[19] = CreateDynamicObject(970, 883.0302, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[20] = CreateDynamicObject(8661, 909.7451, -1287.2679, 13.1618, 2.4488, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_noobSpawn[21] = CreateDynamicObject(8661, 929.7301, -1288.5467, -5.1613, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_noobSpawn[22] = CreateDynamicObject(8661, 869.7470, -1297.5096, 12.7847, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_noobSpawn[23] = CreateDynamicObject(8661, 869.7470, -1287.2679, 13.1618, 2.4488, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_noobSpawn[24] = CreateDynamicObject(970, 823.6002, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[25] = CreateDynamicObject(3934, 913.2683, -1269.0926, 18.2290, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_noobSpawn[26] = CreateDynamicObject(8661, 909.7451, -1297.5096, 12.7847, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_noobSpawn[27] = CreateDynamicObject(10183, 870.6467, -1281.9156, 13.3908, 1.5168, -1.5168, 45.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_noobSpawn[28] = CreateDynamicObject(13681, 914.9957, -1268.6297, 18.2548, 0.0000, 0.0000, 0.6226, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //TCEhilhouse03
    object_noobSpawn[29] = CreateDynamicObject(10183, 925.6638, -1273.3785, 13.7517, 1.5260, 1.9227, 314.7369, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_noobSpawn[30] = CreateDynamicObject(10183, 895.8018, -1303.3431, 12.7945, -0.2280, 0.2280, 225.4028, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_noobSpawn[31] = CreateDynamicObject(3934, 909.1785, -1180.6002, 15.9624, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_noobSpawn[32] = CreateDynamicObject(8645, 876.1381, -1277.4150, 14.4245, 0.0000, 0.0000, -0.0599, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shbbyhswall01_lvs
    object_noobSpawn[33] = CreateDynamicObject(8645, 849.9508, -1292.5295, 13.4488, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shbbyhswall01_lvs
    object_noobSpawn[34] = CreateDynamicObject(8645, 849.9528, -1292.5334, 14.4266, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shbbyhswall01_lvs
    object_noobSpawn[35] = CreateDynamicObject(10183, 870.6467, -1303.3431, 12.7888, -0.2280, 0.2280, 225.4028, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_noobSpawn[36] = CreateDynamicObject(8645, 864.6087, -1277.4189, 14.4266, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shbbyhswall01_lvs
    object_noobSpawn[37] = CreateDynamicObject(970, 900.5565, -1276.9056, 14.0495, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[38] = CreateDynamicObject(970, 927.6140, -1294.7468, 13.3444, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[39] = CreateDynamicObject(717, 927.5631, -1296.7690, 12.8971, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_noobSpawn[40] = CreateDynamicObject(717, 919.5383, -1305.1079, 12.8971, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_noobSpawn[41] = CreateDynamicObject(1280, 815.7056, -1356.5904, 12.9231, 0.0000, 0.0000, -89.4999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    SetDynamicObjectMaterial(object_noobSpawn[41], 1, 14668, "711c", "gun_ceiling1128", 0xFFFFFFFF);
    object_noobSpawn[42] = CreateDynamicObject(1280, 820.2255, -1356.5506, 12.9231, 0.0000, 0.0000, -89.4999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    SetDynamicObjectMaterial(object_noobSpawn[42], 1, 14668, "711c", "gun_ceiling1128", 0xFFFFFFFF);
    object_noobSpawn[43] = CreateDynamicObject(970, 904.7340, -1276.9056, 14.0495, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[44] = CreateDynamicObject(717, 927.5631, -1305.1079, 12.8971, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sm_bevhiltreepv
    object_noobSpawn[45] = CreateDynamicObject(1231, 924.9207, -1221.1202, 18.6061, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_noobSpawn[46] = CreateDynamicObject(8572, 910.4088, -1259.2773, 16.8656, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsSstairs02_lvs
    object_noobSpawn[47] = CreateDynamicObject(3578, 894.7390, -1274.9552, 12.8687, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DockBarr1_LA
    object_noobSpawn[48] = CreateDynamicObject(3578, 894.7390, -1275.4707, 12.8687, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DockBarr1_LA
    object_noobSpawn[49] = CreateDynamicObject(8841, 875.8801, -1180.0362, 18.9810, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rsdncarprk01_lvs
    object_noobSpawn[50] = CreateDynamicObject(8841, 832.0031, -1180.0362, 18.9810, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //rsdncarprk01_lvs
    object_noobSpawn[51] = CreateDynamicObject(8661, 890.2780, -1276.0996, -6.4380, 0.0000, -90.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_noobSpawn[52] = CreateDynamicObject(8645, 864.6066, -1277.4172, 13.7594, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shbbyhswall01_lvs
    object_noobSpawn[53] = CreateDynamicObject(8645, 876.1361, -1277.4172, 13.7594, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //shbbyhswall01_lvs
    object_noobSpawn[54] = CreateDynamicObject(8661, 911.4143, -1267.2905, 13.5979, 0.0500, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_noobSpawn[55] = CreateDynamicObject(10832, 877.1757, -1273.6982, 15.3969, 0.0000, 1.1548, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gatehouse2_SFSe
    object_noobSpawn[56] = CreateDynamicObject(19121, 924.7802, -1209.5117, 16.4799, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[57] = CreateDynamicObject(3578, 884.4401, -1275.4707, 12.8687, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DockBarr1_LA
    object_noobSpawn[58] = CreateDynamicObject(3578, 884.4401, -1274.9552, 12.8687, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DockBarr1_LA
    object_noobSpawn[59] = CreateDynamicObject(10183, 925.6638, -1273.3785, 13.7517, 1.5260, 1.9227, 314.7369, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_noobSpawn[60] = CreateDynamicObject(10183, 870.6467, -1281.9156, 13.3908, 1.5168, -1.5168, 45.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_noobSpawn[61] = CreateDynamicObject(970, 917.3378, -1305.2784, 13.3233, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[62] = CreateDynamicObject(8661, 893.3762, -1267.2905, 13.6021, 0.0500, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_noobSpawn[63] = CreateDynamicObject(19324, 881.1057, -1198.5445, 16.6023, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Unknown Model
    object_noobSpawn[64] = CreateDynamicObject(970, 926.9942, -1211.4610, 16.4636, 0.0000, 0.0000, 7.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[65] = CreateDynamicObject(8673, 899.5518, -1172.0019, 15.9812, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //csrsfence03_lvs
    object_noobSpawn[66] = CreateDynamicObject(8673, 874.0156, -1198.1418, 15.9812, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //csrsfence03_lvs
    object_noobSpawn[67] = CreateDynamicObject(8673, 899.5518, -1186.8342, 15.9812, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //csrsfence03_lvs
    object_noobSpawn[68] = CreateDynamicObject(8673, 853.6085, -1198.1418, 15.9812, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //csrsfence03_lvs
    object_noobSpawn[69] = CreateDynamicObject(8673, 833.2186, -1198.1418, 15.9812, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //csrsfence03_lvs
    object_noobSpawn[70] = CreateDynamicObject(3660, 898.8109, -1187.4704, 17.9137, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_noobSpawn[71] = CreateDynamicObject(3660, 898.2769, -1171.8031, 17.9157, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_noobSpawn[72] = CreateDynamicObject(970, 873.2092, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[73] = CreateDynamicObject(1231, 884.1740, -1198.1285, 18.6061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_noobSpawn[74] = CreateDynamicObject(1231, 808.8917, -1198.1285, 18.6061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_noobSpawn[75] = CreateDynamicObject(1231, 822.4475, -1198.1285, 18.6061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_noobSpawn[76] = CreateDynamicObject(19966, 932.5131, -1230.8109, 15.9111, 0.0000, 0.0000, -105.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign19
    object_noobSpawn[77] = CreateDynamicObject(19978, 886.5036, -1277.4195, 12.6146, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_noobSpawn[78] = CreateDynamicObject(970, 817.7100, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[79] = CreateDynamicObject(970, 877.9699, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[80] = CreateDynamicObject(640, 924.8980, -1221.1202, 16.6201, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_noobSpawn[81] = CreateDynamicObject(970, 890.9470, -1275.0310, 14.1450, 0.0000, -1.5000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[82] = CreateDynamicObject(19971, 922.3510, -1221.1202, 15.8472, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
    object_noobSpawn[83] = CreateDynamicObject(3287, 844.3007, -1230.3066, 18.5181, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxrf_oiltank
    object_noobSpawn[84] = CreateDynamicObject(3287, 835.2097, -1230.3066, 18.5181, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cxrf_oiltank
    object_noobSpawn[85] = CreateDynamicObject(19971, 927.4304, -1221.1202, 15.8472, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign24
    object_noobSpawn[86] = CreateDynamicObject(1231, 898.5029, -1197.8447, 18.6061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_noobSpawn[87] = CreateDynamicObject(970, 867.2390, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[88] = CreateDynamicObject(970, 861.5684, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[89] = CreateDynamicObject(19121, 826.4506, -1179.9991, 16.5365, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[90] = CreateDynamicObject(970, 856.8383, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[91] = CreateDynamicObject(19121, 820.6801, -1179.9991, 16.5365, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[92] = CreateDynamicObject(970, 848.9666, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[93] = CreateDynamicObject(970, 834.0501, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[94] = CreateDynamicObject(970, 844.1806, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[95] = CreateDynamicObject(970, 839.1397, -1180.0185, 16.4465, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    object_noobSpawn[96] = CreateDynamicObject(19121, 836.5805, -1179.9991, 16.5365, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[97] = CreateDynamicObject(19121, 841.6906, -1179.9991, 16.5365, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[98] = CreateDynamicObject(19121, 864.4010, -1180.0190, 16.5965, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[99] = CreateDynamicObject(19121, 870.2517, -1180.0190, 16.5965, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[100] = CreateDynamicObject(19121, 880.4722, -1180.0190, 16.5965, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[101] = CreateDynamicObject(19121, 885.5122, -1180.0190, 16.5965, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[102] = CreateDynamicObject(19121, 851.3311, -1180.0190, 16.5365, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[103] = CreateDynamicObject(19121, 854.5015, -1179.9991, 16.5365, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[104] = CreateDynamicObject(970, 825.3814, -1337.3884, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[104], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[105] = CreateDynamicObject(970, 821.2515, -1337.3884, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[105], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[106] = CreateDynamicObject(970, 813.6513, -1337.3884, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[106], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[107] = CreateDynamicObject(19121, 815.8870, -1337.3857, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[108] = CreateDynamicObject(19452, 808.5363, -1339.5000, 11.0361, 89.8000, -24.6000, -1.2999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall092
    SetDynamicObjectMaterial(object_noobSpawn[108], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_noobSpawn[109] = CreateDynamicObject(19121, 818.9970, -1337.3857, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[110] = CreateDynamicObject(970, 807.4481, -1346.5837, 13.0527, -0.0996, -0.1999, -90.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[110], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[111] = CreateDynamicObject(970, 807.4406, -1350.7430, 13.0670, -0.0996, -0.1999, -90.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[111], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[112] = CreateDynamicObject(970, 807.4334, -1354.9045, 13.0818, -0.0996, -0.1999, -90.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[112], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[113] = CreateDynamicObject(970, 807.4602, -1339.4532, 13.0277, -0.0996, -0.1999, -90.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[113], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[114] = CreateDynamicObject(19121, 807.4464, -1341.6861, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[115] = CreateDynamicObject(19121, 807.4464, -1344.3664, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[116] = CreateDynamicObject(19121, 807.5366, -1357.0367, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[117] = CreateDynamicObject(1280, 811.2056, -1356.6291, 12.9231, 0.0000, 0.0000, -89.4999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    SetDynamicObjectMaterial(object_noobSpawn[117], 1, 14668, "711c", "gun_ceiling1128", 0xFFFFFFFF);
    object_noobSpawn[118] = CreateDynamicObject(1360, 849.4369, -1378.2752, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[118], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[118], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[119] = CreateDynamicObject(1360, 853.4190, -1382.0546, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[119], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[119], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[120] = CreateDynamicObject(1360, 857.0679, -1385.5168, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[120], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[120], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[121] = CreateDynamicObject(19172, 808.7720, -1339.1927, 14.1365, 0.0000, -0.2000, 64.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[121], 0,"Forum: www.lyd-roleplay.de", 90, "Arial", 16, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[122] = CreateDynamicObject(19172, 808.7848, -1339.1671, 14.7067, 0.0000, -0.2000, 64.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[122], 0,"Unsere Plattformen:", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[123] = CreateDynamicObject(19172, 808.7589, -1339.2186, 13.7064, 0.0000, -0.2000, 64.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[123], 0,"Teamspeak: ts.lyd-roleplay.de", 90, "Arial", 16, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[124] = CreateDynamicObject(19172, 808.7546, -1339.2282, 13.9264, 0.0000, -0.2000, 64.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[124], 0,"UCP: www.ucp.lyd-roleplay.de", 90, "Arial", 16, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[125] = CreateDynamicObject(19172, 808.3779, -1355.2445, 14.7985, 0.0000, -0.2000, 129.9998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[125], 0,"Willkommen auf LyD!", 90, "Arial", 22, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[126] = CreateDynamicObject(19172, 808.4025, -1355.2229, 14.1688, -0.7999, -0.2000, 129.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[126], 0,"Fuer Cheatermeldungen - benutze /Admin", 90, "Arial", 14, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[127] = CreateDynamicObject(19172, 808.4042, -1355.2202, 13.9488, -0.7999, -0.2000, 129.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[127], 0,"Fuer die Orientierung - benutze /Navi", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[128] = CreateDynamicObject(1280, 813.2362, -1337.6838, 12.9231, 0.0000, 0.0000, 90.1001, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    SetDynamicObjectMaterial(object_noobSpawn[128], 1, 14668, "711c", "gun_ceiling1128", 0xFFFFFFFF);
    object_noobSpawn[129] = CreateDynamicObject(1280, 822.0169, -1337.6694, 12.9231, 0.0000, 0.0000, 90.1001, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    SetDynamicObjectMaterial(object_noobSpawn[129], 1, 14668, "711c", "gun_ceiling1128", 0xFFFFFFFF);
    object_noobSpawn[130] = CreateDynamicObject(19172, 808.4005, -1355.2257, 14.3988, -0.7999, -0.2000, 129.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[130], 0,"Fuer Fragen - benutze /Sup", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[131] = CreateDynamicObject(970, 809.5009, -1337.3884, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[131], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[132] = CreateDynamicObject(1360, 845.0623, -1374.1252, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[132], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[132], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[133] = CreateDynamicObject(1360, 839.3535, -1368.7060, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[133], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[133], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[134] = CreateDynamicObject(1375, 815.3081, -1359.7972, 0.1385, -0.2998, 1.0000, 47.6996, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tramstop_SF
    object_noobSpawn[135] = CreateDynamicObject(640, 841.4866, -1341.9995, 6.7670, 0.0000, 0.0000, 23.7999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_noobSpawn[135], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[136] = CreateDynamicObject(1360, 814.6018, -1346.1185, -0.8320, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[137] = CreateDynamicObject(1375, 796.9146, -1342.7358, 0.0697, 0.0000, 0.3998, 51.7000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tramstop_SF
    object_noobSpawn[138] = CreateDynamicObject(1360, 820.2686, -1351.2290, -0.8920, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[139] = CreateDynamicObject(1360, 808.6868, -1340.8188, -0.7421, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[140] = CreateDynamicObject(1360, 802.9547, -1335.6457, -0.7421, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[141] = CreateDynamicObject(1360, 796.7241, -1330.2165, -0.7421, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[142] = CreateDynamicObject(1360, 789.8045, -1323.9852, -0.7421, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[143] = CreateDynamicObject(1233, 816.4837, -1332.9117, 14.0256, 0.0000, 0.0000, 179.8000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //noparkingsign1
    object_noobSpawn[144] = CreateDynamicObject(1375, 825.1723, -1368.7724, -0.1176, -0.2998, 1.0000, 47.6996, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tramstop_SF
    object_noobSpawn[145] = CreateDynamicObject(967, 816.3640, -1346.6331, 12.5152, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebox01
    SetDynamicObjectMaterial(object_noobSpawn[145], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[145], 1, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_noobSpawn[146] = CreateDynamicObject(2942, 827.1663, -1355.6239, 13.1646, 0.0000, 0.0000, -90.6998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_noobSpawn[147] = CreateDynamicObject(3802, 826.8685, -1352.6462, 17.5550, 0.0996, 1.5999, 179.1999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[147], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[147], 3, 16093, "a51_ext", "stormdrain2_nt", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[147], 5, 16093, "a51_ext", "BLOCK2", 0xFFFFFFFF);
    object_noobSpawn[148] = CreateDynamicObject(19358, 808.4810, -1355.4625, 14.1331, 0.0000, -0.8999, 39.7999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall006
    SetDynamicObjectMaterial(object_noobSpawn[148], 0, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    object_noobSpawn[149] = CreateDynamicObject(3802, 814.8411, -1356.4261, 17.5310, 0.0000, 0.0000, 91.4998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[149], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    object_noobSpawn[150] = CreateDynamicObject(1360, 834.5607, -1364.2596, -0.8920, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[150], 1, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[151] = CreateDynamicObject(3802, 817.3513, -1339.9890, 17.6177, 0.8999, 2.0999, -90.1996, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[151], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    object_noobSpawn[152] = CreateDynamicObject(3802, 810.1104, -1347.7403, 17.5069, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[152], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    object_noobSpawn[153] = CreateDynamicObject(3802, 823.1591, -1356.1816, 17.5062, -0.5000, 0.4999, 89.3000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[153], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    object_noobSpawn[154] = CreateDynamicObject(640, 839.3153, -1337.0770, 6.7670, 0.0000, 0.0000, 23.7999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_noobSpawn[154], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[155] = CreateDynamicObject(19172, 808.4059, -1355.2174, 13.7188, -0.7999, -0.2000, 129.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[155], 0,"Fuer eine Uebersicht - benutze /Help", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[156] = CreateDynamicObject(19172, 808.3779, -1355.2445, 14.7985, 0.0000, -0.2000, 129.9998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[156], 0,"Willkommen auf LyD!", 90, "Arial", 22, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[157] = CreateDynamicObject(1257, 803.6715, -1358.0559, 13.8233, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bustopm
    object_noobSpawn[158] = CreateDynamicObject(967, 816.3640, -1345.1729, 12.5152, 0.0000, 0.0000, -179.1999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebox01
    SetDynamicObjectMaterial(object_noobSpawn[158], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[158], 1, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_noobSpawn[159] = CreateDynamicObject(1239, 817.0948, -1345.2106, 13.5363, 0.0000, 0.0000, -93.3999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //info
    object_noobSpawn[160] = CreateDynamicObject(1375, 832.9511, -1375.8508, -0.3194, -0.6998, 1.0000, 47.6996, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tramstop_SF
    object_noobSpawn[161] = CreateDynamicObject(970, 825.4514, -1344.5699, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[161], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[162] = CreateDynamicObject(19121, 823.2172, -1344.5666, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[163] = CreateDynamicObject(1286, 813.7977, -1356.6202, 13.1358, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newstandnew4
    object_noobSpawn[164] = CreateDynamicObject(1286, 813.3776, -1356.6202, 13.1358, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newstandnew4
    object_noobSpawn[165] = CreateDynamicObject(1286, 817.6781, -1356.6202, 13.1358, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newstandnew4
    object_noobSpawn[166] = CreateDynamicObject(1286, 818.0985, -1356.6202, 13.1358, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newstandnew4
    object_noobSpawn[167] = CreateDynamicObject(640, 843.6531, -1346.9138, 6.7670, 0.0000, 0.0000, 23.7999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_noobSpawn[167], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[168] = CreateDynamicObject(1340, 826.0897, -1348.7567, 13.5705, 0.0000, 0.0000, 179.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chillidogcart
    object_noobSpawn[169] = CreateDynamicObject(1239, 815.6415, -1346.5881, 13.5363, 0.0000, 0.0000, -93.3999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //info
}
