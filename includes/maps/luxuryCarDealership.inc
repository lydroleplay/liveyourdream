#include <YSI\y_hooks>

// Global interior define
#define MAPS_LUXURYCARDEALERSHIP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 180.0;

// Luxury car dealership points
#define LUXURYCARDEALERSHIP_COORDS    1142.3765, -1619.0011, 13.9445

// Map variables
new object_luxuryCarDealership[233];
new text3D_luxuryCarDealership[1];
new actor_luxuryCarDealership[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(LUXURYCARDEALERSHIP_COORDS, 55, 0, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR);

    // 3DTextLabels
    text3D_luxuryCarDealership[0] = _:CreateDynamic3DTextLabel("Autohaus - Luxus\n" COLOR_HEX_WHITE "Steig in ein beliebiges Fahrzeug deiner Wahl ein!", COLOR_BLUE, LUXURYCARDEALERSHIP_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LUXURYCARDEALERSHIP_INTERIOR);

    // Actors
    actor_luxuryCarDealership[0] = CreateDynamicActor(295, 1124.7650, -1629.1274, 13.7387, 12.1571, .worldid = VW_MAIN, .interiorid = MAPS_LUXURYCARDEALERSHIP_INTERIOR); // salesman
    ApplyDynamicActorAnimation(actor_luxuryCarDealership[0], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);

	// Objects
	object_luxuryCarDealership[0] = CreateDynamicObject(19284, 1139.2767, -1619.0157, 12.7459, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[1] = CreateDynamicObject(3440, 1139.3796, -1619.0229, 14.7312, 0.0000, 0.0000, 149.1999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //arptpillar01_lvs
    object_luxuryCarDealership[2] = CreateDynamicObject(1233, 1139.8596, -1606.3166, 13.7838, 0.0000, 0.0000, 88.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //noparkingsign1
    object_luxuryCarDealership[3] = CreateDynamicObject(1233, 1139.8923, -1632.1910, 14.2938, 0.0000, 0.0000, 90.6997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //noparkingsign1
    object_luxuryCarDealership[4] = CreateDynamicObject(2773, 1114.4200, -1623.2414, 19.9969, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[5] = CreateDynamicObject(2773, 1117.0915, -1623.2866, 19.9969, -0.5000, 0.0000, 89.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[6] = CreateDynamicObject(2773, 1120.0528, -1623.3542, 20.0326, -0.6000, 0.0000, 89.5000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[7] = CreateDynamicObject(2773, 1135.9493, -1617.0256, 18.0251, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[8] = CreateDynamicObject(2773, 1135.9294, -1620.4254, 18.0853, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[9] = CreateDynamicObject(2773, 1114.4200, -1615.2004, 19.9969, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[10] = CreateDynamicObject(2773, 1117.2053, -1615.2176, 19.9969, -0.5000, 0.0000, 89.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[11] = CreateDynamicObject(19361, 1139.6212, -1614.2673, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[11], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[12] = CreateDynamicObject(2773, 1120.1246, -1615.1743, 20.0326, -0.6000, 0.0000, 89.5000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[13] = CreateDynamicObject(2773, 1135.9094, -1623.6059, 18.1180, -0.4999, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[14] = CreateDynamicObject(2773, 1138.1937, -1625.3896, 18.1221, -0.4999, 0.0000, 88.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[15] = CreateDynamicObject(2773, 1138.1296, -1615.2287, 18.0484, -0.4999, 0.0000, 88.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[16] = CreateDynamicObject(19361, 1139.6212, -1611.0871, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[16], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[17] = CreateDynamicObject(19462, 1139.7677, -1620.2668, 19.1732, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall102
    SetDynamicObjectMaterial(object_luxuryCarDealership[17], 0, 16640, "a51", "redmetal", 0xFF840410);
    object_luxuryCarDealership[18] = CreateDynamicObject(19464, 1094.8861, -1613.4425, 15.1590, 0.0000, -0.6998, -0.4999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[18], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[19] = CreateDynamicObject(2773, 1141.5056, -1622.2026, 13.4504, 0.0000, 0.0000, 91.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[20] = CreateDynamicObject(19361, 1139.6212, -1607.9173, 13.3760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[20], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[21] = CreateDynamicObject(19462, 1137.9173, -1620.2485, 17.5041, -0.6000, -90.2996, -0.4999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall102
    SetDynamicObjectMaterial(object_luxuryCarDealership[21], 0, 16640, "a51", "redmetal", 0xFF840410);
    object_luxuryCarDealership[22] = CreateDynamicObject(19464, 1094.8354, -1619.2834, 15.1590, 0.0000, -0.6998, -0.4999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[22], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[23] = CreateDynamicObject(19361, 1139.6212, -1617.4372, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[23], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[24] = CreateDynamicObject(19361, 1139.6212, -1611.0970, 13.3760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[24], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[25] = CreateDynamicObject(19361, 1139.6212, -1614.2976, 13.3760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[25], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[26] = CreateDynamicObject(19361, 1139.6212, -1620.6080, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[26], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[27] = CreateDynamicObject(19361, 1139.6212, -1623.7779, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[27], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[28] = CreateDynamicObject(19462, 1139.6776, -1620.2668, 19.1732, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall102
    SetDynamicObjectMaterial(object_luxuryCarDealership[28], 0, 16640, "a51", "redmetal", 0xFF840410);
    object_luxuryCarDealership[29] = CreateDynamicObject(19464, 1097.2165, -1619.3033, 18.7140, 0.0000, 67.6997, -0.4999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[29], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[30] = CreateDynamicObject(19464, 1130.0583, -1631.1927, 14.3016, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[30], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_luxuryCarDealership[31] = CreateDynamicObject(19361, 1139.6212, -1626.9388, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[31], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[32] = CreateDynamicObject(19284, 1139.2767, -1629.0477, 12.7459, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[33] = CreateDynamicObject(19172, 1139.8485, -1620.9028, 19.2220, 0.0000, 0.0000, 89.9997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_luxuryCarDealership[33], 0,"haus", 90, "Arial", 120, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_luxuryCarDealership[33], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_luxuryCarDealership[34] = CreateDynamicObject(19361, 1139.6212, -1633.2995, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[34], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[35] = CreateDynamicObject(19361, 1139.6212, -1630.1091, 13.3760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[35], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[36] = CreateDynamicObject(19464, 1097.2049, -1608.5179, 15.1555, 0.0000, 0.0000, 131.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[36], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[37] = CreateDynamicObject(19172, 1139.8597, -1618.3410, 19.2119, 0.0000, 0.0000, 89.2996, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_luxuryCarDealership[37], 0,"-Lux", 90, "Arial", 120, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_luxuryCarDealership[37], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_luxuryCarDealership[38] = CreateDynamicObject(19361, 1139.6212, -1623.7983, 13.3760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[38], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[39] = CreateDynamicObject(2073, 1116.6728, -1628.4133, 17.5202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MLIGHT1
    object_luxuryCarDealership[40] = CreateDynamicObject(19361, 1139.6212, -1607.9173, 16.7961, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[40], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[41] = CreateDynamicObject(19172, 1139.8585, -1615.9887, 19.2119, 0.0000, 0.0000, 89.2996, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_luxuryCarDealership[41], 0,"us", 90, "Arial", 120, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_luxuryCarDealership[41], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_luxuryCarDealership[42] = CreateDynamicObject(2773, 1141.3309, -1615.9538, 13.4504, 0.0000, 0.0000, 91.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_AIRPRT_BAR
    object_luxuryCarDealership[43] = CreateDynamicObject(2073, 1113.2933, -1628.4133, 17.5202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MLIGHT1
    object_luxuryCarDealership[44] = CreateDynamicObject(19445, 1138.0832, -1626.7236, 12.8578, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[44], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[45] = CreateDynamicObject(19445, 1134.5372, -1607.5179, 12.7699, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[45], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    // object_luxuryCarDealership[46] = CreateObject(19872, 1121.8220, -1610.8795, 11.3908, 12.5000, 0.0000, 32.5000); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[46], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[47] = CreateDynamicObject(19464, 1094.7839, -1625.1534, 15.1590, 0.0000, -0.6998, -0.4999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[47], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[48] = CreateDynamicObject(19426, 1114.9311, -1625.3956, 17.0361, 89.1997, 1.0999, -90.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[48], 0, 4833, "airprtrunway_las", "ws_bluelino", 0xFFFFFFFF);
    object_luxuryCarDealership[49] = CreateDynamicObject(19445, 1131.1350, -1626.7480, 12.7489, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[49], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[50] = CreateDynamicObject(19445, 1127.6748, -1626.7601, 12.6946, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[50], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[51] = CreateDynamicObject(19445, 1134.6042, -1626.7358, 12.8034, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[51], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[52] = CreateDynamicObject(19445, 1134.5710, -1617.1153, 12.7866, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[52], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[53] = CreateDynamicObject(19445, 1138.0504, -1617.2038, 12.8415, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[53], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[54] = CreateDynamicObject(19445, 1138.0168, -1607.7152, 12.8247, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[54], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[55] = CreateDynamicObject(19445, 1124.2574, -1626.7711, 12.6408, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[55], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[56] = CreateDynamicObject(19445, 1127.6413, -1617.1311, 12.6778, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[56], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[57] = CreateDynamicObject(14699, 1131.0262, -1622.0411, 15.1183, 0.0000, -3.7999, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights
    object_luxuryCarDealership[58] = CreateDynamicObject(19445, 1131.1014, -1617.1379, 12.7320, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[58], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[59] = CreateDynamicObject(19445, 1131.0681, -1607.5189, 12.7152, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[59], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[60] = CreateDynamicObject(14699, 1121.2519, -1621.8808, 16.5559, 0.0000, -1.6000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights
    object_luxuryCarDealership[61] = CreateDynamicObject(19445, 1124.2812, -1607.5423, 12.6084, -0.0996, 89.6997, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[61], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[62] = CreateDynamicObject(19445, 1124.2248, -1617.1412, 12.6239, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[62], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[63] = CreateDynamicObject(14699, 1110.2446, -1621.8006, 15.6611, 0.0000, -36.0998, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights
    object_luxuryCarDealership[64] = CreateDynamicObject(19445, 1127.7799, -1607.4995, 12.6633, -0.0996, 89.0998, 0.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[64], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[65] = CreateDynamicObject(19426, 1111.6623, -1626.1473, 17.0816, 89.1997, 25.9999, -90.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[65], 0, 4833, "airprtrunway_las", "ws_bluelino", 0xFFFFFFFF);
    object_luxuryCarDealership[66] = CreateDynamicObject(14699, 1114.7137, -1621.8009, 16.3733, 0.0000, -1.6000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights
    object_luxuryCarDealership[67] = CreateDynamicObject(14699, 1126.6046, -1621.9609, 14.9280, 0.0000, 16.8999, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights
    object_luxuryCarDealership[68] = CreateDynamicObject(14699, 1138.7248, -1621.4105, 15.3134, 0.0000, -1.6000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Int_tat_lights
    object_luxuryCarDealership[69] = CreateDynamicObject(19445, 1120.7983, -1626.8015, 12.6202, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[69], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[70] = CreateDynamicObject(19445, 1117.3193, -1626.7832, 12.6928, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[70], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[71] = CreateDynamicObject(19445, 1107.1318, -1617.0915, 12.8030, 0.0000, 90.0998, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[71], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[72] = CreateDynamicObject(19445, 1113.9914, -1607.5166, 12.7649, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[72], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[73] = CreateDynamicObject(19445, 1117.3193, -1626.7832, 12.6928, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[73], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[74] = CreateDynamicObject(19445, 1120.8481, -1617.2209, 12.6202, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[74], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[75] = CreateDynamicObject(19445, 1117.3691, -1617.1534, 12.6928, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[75], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[76] = CreateDynamicObject(19445, 1120.8984, -1607.7115, 12.6202, 0.0000, 90.5000, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[76], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[77] = CreateDynamicObject(19445, 1117.4195, -1607.5343, 12.6928, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[77], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[78] = CreateDynamicObject(19445, 1113.9416, -1617.1267, 12.7649, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[78], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[79] = CreateDynamicObject(19464, 1123.9605, -1607.1018, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[79], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[80] = CreateDynamicObject(19445, 1113.9007, -1626.7054, 12.7644, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[80], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[81] = CreateDynamicObject(19464, 1118.1506, -1607.1223, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[81], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[82] = CreateDynamicObject(19464, 1112.2502, -1607.1429, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[82], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[83] = CreateDynamicObject(19445, 1110.4414, -1626.6866, 12.8372, 0.0000, 91.1997, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[83], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[84] = CreateDynamicObject(19445, 1110.5432, -1607.5102, 12.7972, 0.0000, 90.0998, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[84], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[85] = CreateDynamicObject(19464, 1106.3802, -1607.1643, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[85], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[86] = CreateDynamicObject(19464, 1100.4304, -1607.1854, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[86], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[87] = CreateDynamicObject(18647, 1132.2010, -1602.6960, 20.6541, 0.0000, 0.0000, -87.1999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RedNeonTube1
    object_luxuryCarDealership[88] = CreateDynamicObject(19445, 1107.1816, -1607.5019, 12.8030, 0.0000, 90.0998, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[88], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[89] = CreateDynamicObject(19445, 1110.4930, -1617.1202, 12.7972, 0.0000, 90.0998, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[89], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[90] = CreateDynamicObject(19464, 1126.9936, -1610.1881, 14.0516, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[90], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_luxuryCarDealership[91] = CreateDynamicObject(19464, 1126.7535, -1610.1881, 14.0417, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[91], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[92] = CreateDynamicObject(19445, 1107.0804, -1626.7408, 12.8227, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[92], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[93] = CreateDynamicObject(19172, 1139.8486, -1623.3626, 19.2119, 0.0000, 0.0000, 89.8996, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_luxuryCarDealership[93], 0,"Auto", 90, "Arial", 120, 1, 0xFFD78E10, 0x0, 0);
    SetDynamicObjectMaterial(object_luxuryCarDealership[93], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_luxuryCarDealership[94] = CreateDynamicObject(19445, 1103.7424, -1607.4704, 12.7510, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[94], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[95] = CreateDynamicObject(19445, 1100.2635, -1607.4543, 12.6780, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[95], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[96] = CreateDynamicObject(19445, 1100.2132, -1617.0736, 12.6780, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[96], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[97] = CreateDynamicObject(19445, 1103.6916, -1617.0699, 12.7510, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[97], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[98] = CreateDynamicObject(19445, 1096.7137, -1617.0554, 12.6048, 0.0000, 89.0000, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[98], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[99] = CreateDynamicObject(19445, 1096.7641, -1607.4455, 12.6048, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[99], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[100] = CreateDynamicObject(19464, 1130.1085, -1607.1733, 14.3016, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[100], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_luxuryCarDealership[101] = CreateDynamicObject(19361, 1139.6212, -1626.9289, 13.3760, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[101], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[102] = CreateDynamicObject(19445, 1103.6417, -1626.7220, 12.7510, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[102], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[103] = CreateDynamicObject(19445, 1100.1623, -1626.7036, 12.6780, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[103], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[104] = CreateDynamicObject(19445, 1096.7036, -1626.6855, 12.6056, 0.0000, 88.8001, -0.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    SetDynamicObjectMaterial(object_luxuryCarDealership[104], 0, 7650, "vgnusedcar", "lightblue2_32", 0xFFFFFFFF);
    object_luxuryCarDealership[105] = CreateDynamicObject(19464, 1126.9936, -1628.2491, 14.0516, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[105], 0, 16136, "des_telescopestuff", "stoneclad1", 0xFFFFFFFF);
    object_luxuryCarDealership[106] = CreateDynamicObject(19464, 1094.9697, -1607.5249, 15.1815, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[106], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_luxuryCarDealership[107] = CreateDynamicObject(19464, 1094.8403, -1631.0743, 15.1815, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[107], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_luxuryCarDealership[108] = CreateDynamicObject(19464, 1124.0144, -1631.1842, 15.1955, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[108], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_luxuryCarDealership[108], 1, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    object_luxuryCarDealership[109] = CreateDynamicObject(2163, 1123.9101, -1631.0605, 14.4574, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_luxuryCarDealership[110] = CreateDynamicObject(14468, 1121.2215, -1619.4510, 13.3319, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[111] = CreateDynamicObject(19464, 1117.9149, -1631.2358, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[111], 0, 18246, "cw_junkyard2cs_t", "Was_scrpyd_tires", 0xFFFFFFFF);
    object_luxuryCarDealership[112] = CreateDynamicObject(19464, 1115.0544, -1628.3081, 15.1118, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[112], 0, 14415, "carter_block_2", "mp_gs_woodpanel", 0xFFFFFFFF);
    object_luxuryCarDealership[113] = CreateDynamicObject(19464, 1114.8347, -1628.2878, 15.1118, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[113], 0, 14581, "ab_mafiasuitea", "wood02S", 0xFFFFFFFF);
    object_luxuryCarDealership[114] = CreateDynamicObject(19464, 1111.7441, -1631.2174, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[114], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[115] = CreateDynamicObject(19464, 1105.8343, -1631.2193, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[115], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    // object_luxuryCarDealership[116] = CreateObject(19872, 1130.7379, -1626.4316, 11.5541, 12.5000, 0.0000, 146.3999); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[116], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[117] = CreateDynamicObject(19464, 1100.0847, -1631.2203, 15.1555, 0.0000, 0.0000, 90.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[117], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    // object_luxuryCarDealership[118] = CreateObject(19872, 1131.4704, -1612.2888, 11.5522, 12.5000, 0.0000, 43.9000); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[118], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[119] = CreateDynamicObject(1281, 1084.9327, -1607.8360, 20.2329, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    object_luxuryCarDealership[120] = CreateDynamicObject(2184, 1125.5034, -1627.3851, 12.7369, 0.0000, 0.0000, -168.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_DESK_2
    object_luxuryCarDealership[121] = CreateDynamicObject(1671, 1124.8603, -1629.4984, 13.1735, 0.0000, 0.0000, -170.9998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_luxuryCarDealership[122] = CreateDynamicObject(19426, 1115.2558, -1625.3824, 14.4392, 0.0000, 0.0000, -89.5000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[122], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[123] = CreateDynamicObject(19426, 1122.3465, -1625.3603, 14.4392, 0.0000, 0.0000, -89.5000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[123], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[124] = CreateDynamicObject(19426, 1120.7667, -1625.3741, 14.4392, 0.0000, 0.0000, -89.5000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[124], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[125] = CreateDynamicObject(1811, 1125.4344, -1625.8468, 13.3507, 0.0000, 0.0000, 84.9000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_luxuryCarDealership[126] = CreateDynamicObject(19786, 1135.4447, -1607.1350, 15.3845, 0.0000, 0.0000, -0.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_luxuryCarDealership[126], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[127] = CreateDynamicObject(1811, 1123.4156, -1626.9277, 13.3507, 0.0000, 0.0000, 120.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_luxuryCarDealership[128] = CreateDynamicObject(2161, 1125.9665, -1631.0471, 12.7262, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_luxuryCarDealership[129] = CreateDynamicObject(2163, 1125.6601, -1631.0393, 14.4574, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_luxuryCarDealership[130] = CreateDynamicObject(19464, 1126.7535, -1628.2679, 14.0417, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[130], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    // object_luxuryCarDealership[131] = CreateObject(19872, 1114.0277, -1610.5654, 11.4974, 12.5000, 0.0000, 32.5000); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[131], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[132] = CreateDynamicObject(19893, 1125.1611, -1628.0621, 13.5079, 0.0000, 0.0000, -3.5999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LaptopSAMP1
    SetDynamicObjectMaterial(object_luxuryCarDealership[132], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[133] = CreateDynamicObject(19426, 1121.8099, -1625.3454, 16.9402, 89.1997, 1.0999, -90.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[133], 0, 4833, "airprtrunway_las", "ws_bluelino", 0xFFFFFFFF);
    object_luxuryCarDealership[134] = CreateDynamicObject(19464, 1121.2336, -1628.2679, 15.1118, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[134], 0, 10351, "beach_sfs", "ws_drysand2grass", 0xFFFFFFFF);
    object_luxuryCarDealership[135] = CreateDynamicObject(2161, 1124.6269, -1631.0633, 12.7262, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_luxuryCarDealership[136] = CreateDynamicObject(19426, 1125.3186, -1625.3149, 16.8910, 89.1997, 1.0999, -90.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[136], 0, 4833, "airprtrunway_las", "ws_bluelino", 0xFFFFFFFF);
    object_luxuryCarDealership[137] = CreateDynamicObject(19426, 1118.4405, -1625.3751, 16.9871, 89.1997, 1.0999, -90.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[137], 0, 4833, "airprtrunway_las", "ws_bluelino", 0xFFFFFFFF);
    object_luxuryCarDealership[138] = CreateDynamicObject(19361, 1139.6212, -1636.4394, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[138], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[139] = CreateDynamicObject(2894, 1123.9559, -1627.7381, 13.5179, 0.0000, 0.0000, -165.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_luxuryCarDealership[139], 0, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    // object_luxuryCarDealership[140] = CreateObject(19872, 1107.0766, -1611.5345, 11.6618, 12.5000, 0.0000, 31.7000); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[140], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[141] = CreateDynamicObject(19426, 1109.2176, -1628.3702, 17.1156, 89.1997, 58.6999, -90.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[141], 0, 4833, "airprtrunway_las", "ws_bluelino", 0xFFFFFFFF);
    object_luxuryCarDealership[142] = CreateDynamicObject(1808, 1121.6551, -1630.6456, 12.6590, 0.0000, 0.0000, 177.1000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_WATERCOOLER2
    object_luxuryCarDealership[143] = CreateDynamicObject(19426, 1107.3631, -1631.3507, 17.1410, 89.1997, 58.6999, -90.5998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[143], 0, 4833, "airprtrunway_las", "ws_bluelino", 0xFFFFFFFF);
    // object_luxuryCarDealership[144] = CreateObject(19872, 1106.1142, -1626.9599, 11.6176, 12.5000, 0.0000, 138.3000); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[144], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[145] = CreateDynamicObject(19426, 1110.9488, -1626.4487, 14.5894, 0.0000, 0.0000, -64.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[145], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[146] = CreateDynamicObject(19426, 1109.6982, -1627.4696, 14.5894, 0.0000, 0.0000, -33.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[146], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[147] = CreateDynamicObject(19464, 1096.9488, -1630.1621, 15.1555, 0.0000, 0.0000, 46.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[147], 0, 14387, "dr_gsnew", "mp_stonefloor", 0xFFFFFFFF);
    object_luxuryCarDealership[148] = CreateDynamicObject(19426, 1108.8114, -1628.8249, 14.5894, 0.0000, 0.0000, -33.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[148], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[149] = CreateDynamicObject(19426, 1107.9355, -1630.1634, 14.5894, 0.0000, 0.0000, -33.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[149], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[150] = CreateDynamicObject(19426, 1107.0533, -1631.5102, 14.5894, 0.0000, 0.0000, -33.2000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[150], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[151] = CreateDynamicObject(19464, 1094.9797, -1601.6246, 15.1415, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[151], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    // object_luxuryCarDealership[152] = CreateObject(19872, 1098.6993, -1626.9735, 11.3725, 12.5000, 0.0000, -147.4998); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[152], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[153] = CreateDynamicObject(19786, 1116.9134, -1631.0968, 15.6948, 0.0000, 0.0000, 178.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_luxuryCarDealership[153], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    // object_luxuryCarDealership[154] = CreateObject(19872, 1129.2696, -1636.8974, 16.2070, 12.5000, 0.0000, 146.3999); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[154], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[155] = CreateDynamicObject(19464, 1094.8403, -1637.0240, 15.1815, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[155], 0, 13364, "cetown3cs_t", "ws_sandstone2", 0xFFFFFFFF);
    object_luxuryCarDealership[156] = CreateDynamicObject(19361, 1139.6212, -1639.5893, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[156], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    // object_luxuryCarDealership[157] = CreateObject(19872, 1136.7041, -1636.7707, 16.2896, 12.5000, 0.0000, -159.3000); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[157], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[158] = CreateDynamicObject(19361, 1138.0284, -1641.0941, 16.8061, 0.0000, 0.0000, -89.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[158], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[159] = CreateDynamicObject(19361, 1139.6212, -1604.7574, 16.7961, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[159], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[160] = CreateDynamicObject(19786, 1102.5821, -1630.5964, 15.3845, 0.0000, 0.0000, 178.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_luxuryCarDealership[160], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[161] = CreateDynamicObject(19361, 1134.9084, -1641.1051, 16.8061, 0.0000, 0.0000, -89.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[161], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[162] = CreateDynamicObject(19361, 1131.7684, -1641.1158, 16.8061, 0.0000, 0.0000, -89.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[162], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[163] = CreateDynamicObject(19361, 1128.5981, -1641.1269, 16.8061, 0.0000, 0.0000, -89.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[163], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    object_luxuryCarDealership[164] = CreateDynamicObject(2184, 1118.3842, -1627.5704, 12.7669, 0.0000, 0.0000, -168.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_DESK_2
    object_luxuryCarDealership[165] = CreateDynamicObject(2161, 1116.0865, -1631.1075, 12.7262, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_luxuryCarDealership[166] = CreateDynamicObject(2161, 1117.4071, -1631.0915, 12.7262, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_luxuryCarDealership[167] = CreateDynamicObject(2163, 1119.5797, -1631.1135, 14.4574, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_luxuryCarDealership[168] = CreateDynamicObject(1671, 1117.8752, -1629.7353, 13.2334, 0.0000, 0.0000, -165.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_luxuryCarDealership[169] = CreateDynamicObject(19786, 1117.6273, -1607.4361, 15.3845, 0.0000, 0.0000, -0.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_luxuryCarDealership[169], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[170] = CreateDynamicObject(1281, 1102.5626, -1607.8360, 20.2329, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    object_luxuryCarDealership[171] = CreateDynamicObject(14468, 1118.1627, -1619.4510, 13.3319, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[172] = CreateDynamicObject(14468, 1111.2121, -1619.4510, 13.3319, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[173] = CreateDynamicObject(14468, 1114.4018, -1619.4510, 13.3319, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[174] = CreateDynamicObject(19464, 1120.9936, -1628.2679, 15.1118, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_luxuryCarDealership[174], 0, 14415, "carter_block_2", "mp_gs_woodpanel", 0xFFFFFFFF);
    object_luxuryCarDealership[175] = CreateDynamicObject(14468, 1108.3221, -1619.4510, 13.3319, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[176] = CreateDynamicObject(14468, 1107.6119, -1619.4510, 13.3319, 0.0000, 0.0000, 176.8999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[177] = CreateDynamicObject(2894, 1117.4879, -1627.9749, 13.5481, 0.0000, 0.0000, -165.3999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_luxuryCarDealership[177], 0, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[178] = CreateDynamicObject(1281, 1062.5826, -1630.1164, 20.2329, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    object_luxuryCarDealership[179] = CreateDynamicObject(1281, 1117.7430, -1607.8360, 20.2329, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    object_luxuryCarDealership[180] = CreateDynamicObject(1281, 1062.5826, -1607.8360, 20.2329, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    object_luxuryCarDealership[181] = CreateDynamicObject(1281, 1083.3535, -1630.1164, 20.2329, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    object_luxuryCarDealership[182] = CreateDynamicObject(2808, 1124.8033, -1619.2923, 13.3669, 0.0000, 0.0000, -90.4000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_CHAIR4
    SetDynamicObjectMaterial(object_luxuryCarDealership[182], 0, 14608, "triad_big", "silver_coins2", 0xFFFFFFFF);
    object_luxuryCarDealership[183] = CreateDynamicObject(1281, 1102.7938, -1630.1164, 20.2329, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    object_luxuryCarDealership[184] = CreateDynamicObject(1281, 1118.1236, -1630.1164, 20.2329, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parktable1
    object_luxuryCarDealership[185] = CreateDynamicObject(2637, 1126.5445, -1619.3192, 13.1395, 0.0000, 0.0000, 90.1999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE2
    object_luxuryCarDealership[186] = CreateDynamicObject(19426, 1126.2856, -1625.3259, 14.3592, 0.0000, 0.0000, -89.5000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall066
    SetDynamicObjectMaterial(object_luxuryCarDealership[186], 0, 3902, "libertyhi3", "glass2_64", 0xFFFFFFFF);
    object_luxuryCarDealership[187] = CreateDynamicObject(2184, 1114.2032, -1627.4798, 12.8496, 0.0000, -0.5999, -157.1999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE6_DESK_2
    object_luxuryCarDealership[188] = CreateDynamicObject(1811, 1117.9223, -1626.0998, 13.3706, 0.0000, 0.0000, 84.9000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_luxuryCarDealership[189] = CreateDynamicObject(1811, 1116.1040, -1626.6021, 13.3807, 0.0000, 0.0000, 118.9999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_luxuryCarDealership[190] = CreateDynamicObject(16151, 1134.2336, -1603.8872, 17.9039, 0.0000, 0.0000, 90.8999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ufo_bar
    object_luxuryCarDealership[191] = CreateDynamicObject(1511, 1135.3055, -1602.8944, 18.8917, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_SPIRIT_02
    object_luxuryCarDealership[192] = CreateDynamicObject(1488, 1135.7270, -1602.8563, 18.8778, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_SPIRIT_1
    object_luxuryCarDealership[193] = CreateDynamicObject(2894, 1113.9399, -1627.8189, 13.6380, 0.0000, 0.0000, -158.6997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_luxuryCarDealership[193], 0, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[194] = CreateDynamicObject(1811, 1113.9139, -1626.0284, 13.4307, 0.0000, 0.0000, 61.2999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    object_luxuryCarDealership[195] = CreateDynamicObject(1671, 1113.8293, -1629.8122, 13.2334, 0.0000, 0.0000, -165.1997, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //swivelchair_A
    object_luxuryCarDealership[196] = CreateDynamicObject(1215, 1139.5938, -1602.5865, 22.3050, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_luxuryCarDealership[197] = CreateDynamicObject(2163, 1114.2304, -1631.1788, 14.4574, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_luxuryCarDealership[198] = CreateDynamicObject(2163, 1112.4205, -1631.2009, 14.4574, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_luxuryCarDealership[199] = CreateDynamicObject(2161, 1114.0969, -1631.0819, 12.8261, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_luxuryCarDealership[200] = CreateDynamicObject(2161, 1112.8061, -1631.0776, 12.8261, 0.0000, 0.0000, -179.2998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    // object_luxuryCarDealership[201] = CreateObject(19872, 1100.5704, -1611.6396, 11.4342, 12.5000, 0.0000, -40.3998); //CarFixerRamp2
    // SetObjectMaterial(object_luxuryCarDealership[201], 0, 18217, "mtbfencecs_t", "steel256256", 0xFFFFFFFF);
    object_luxuryCarDealership[202] = CreateDynamicObject(19786, 1102.9089, -1607.2307, 15.3845, 0.0000, 0.0000, -0.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_luxuryCarDealership[202], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[203] = CreateDynamicObject(18647, 1134.4232, -1602.6877, 20.6541, 0.0000, 0.0000, -87.1999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RedNeonTube1
    object_luxuryCarDealership[204] = CreateDynamicObject(18647, 1136.6241, -1602.6604, 20.6541, 0.0000, 0.0000, -87.1999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RedNeonTube1
    object_luxuryCarDealership[205] = CreateDynamicObject(19284, 1139.2767, -1622.3569, 12.7459, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[206] = CreateDynamicObject(19124, 1118.5174, -1623.3164, 20.0611, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_luxuryCarDealership[207] = CreateDynamicObject(19786, 1131.5943, -1631.1120, 15.3845, 0.0000, 0.0000, 179.6000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //LCDTVBig1
    SetDynamicObjectMaterial(object_luxuryCarDealership[207], 1, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[208] = CreateDynamicObject(19124, 1118.6676, -1615.2851, 20.0611, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_luxuryCarDealership[209] = CreateDynamicObject(19124, 1115.8360, -1615.1750, 20.0611, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_luxuryCarDealership[210] = CreateDynamicObject(1215, 1127.1533, -1602.5064, 22.3150, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_luxuryCarDealership[211] = CreateDynamicObject(14468, 1083.7951, -1619.2933, 13.2720, 0.0000, 0.0000, 176.8999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[212] = CreateDynamicObject(1541, 1136.4505, -1602.8122, 18.8437, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BEER_TAPS_1
    object_luxuryCarDealership[213] = CreateDynamicObject(14468, 1079.6020, -1619.2463, 13.2720, 0.0000, 0.0000, 179.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[214] = CreateDynamicObject(14468, 1075.4218, -1619.2319, 13.2720, 0.0000, 0.0000, 179.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[215] = CreateDynamicObject(14468, 1070.9117, -1619.2160, 13.2720, 0.0000, 0.0000, 179.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[216] = CreateDynamicObject(14468, 1066.4320, -1619.2004, 13.2720, 0.0000, 0.0000, 179.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[217] = CreateDynamicObject(14468, 1061.4714, -1619.1831, 13.2720, 0.0000, 0.0000, 179.8000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flower-bush09a
    object_luxuryCarDealership[218] = CreateDynamicObject(2073, 1119.4029, -1628.4133, 17.5202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MLIGHT1
    object_luxuryCarDealership[219] = CreateDynamicObject(2073, 1122.7130, -1628.4133, 17.5202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MLIGHT1
    object_luxuryCarDealership[220] = CreateDynamicObject(2073, 1125.1030, -1628.4133, 16.9603, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MLIGHT1
    object_luxuryCarDealership[221] = CreateDynamicObject(19284, 1139.2767, -1625.6069, 12.7459, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[222] = CreateDynamicObject(2073, 1110.9835, -1628.4133, 17.5202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_MLIGHT1
    object_luxuryCarDealership[223] = CreateDynamicObject(19284, 1139.1518, -1616.0461, 12.6142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[224] = CreateDynamicObject(19284, 1139.3321, -1612.6661, 12.6142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[225] = CreateDynamicObject(19284, 1139.2519, -1608.9760, 12.6142, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[226] = CreateDynamicObject(19284, 1129.8265, -1634.3027, 17.3731, 0.0000, 0.0000, -35.4999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[227] = CreateDynamicObject(19124, 1115.7072, -1623.1961, 20.0611, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight4
    object_luxuryCarDealership[228] = CreateDynamicObject(19284, 1131.3408, -1635.3828, 17.3731, 0.0000, 0.0000, -35.4999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[229] = CreateDynamicObject(19284, 1134.9515, -1634.7170, 17.2759, -2.2000, 0.0000, -65.8999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[230] = CreateDynamicObject(19284, 1136.7933, -1633.9914, 17.2000, -2.2000, 0.0000, -65.8999, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //PointLight4
    object_luxuryCarDealership[231] = CreateDynamicObject(2894, 1126.3795, -1619.4992, 13.5679, 0.0000, 0.0000, -77.7998, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_rhymesbook
    SetDynamicObjectMaterial(object_luxuryCarDealership[231], 0, 10249, "ottos2_sfw", "ottos_pics_sfe", 0xFFFFFFFF);
    object_luxuryCarDealership[232] = CreateDynamicObject(19361, 1139.6212, -1630.1491, 16.8061, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_LUXURYCARDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall009
    SetDynamicObjectMaterial(object_luxuryCarDealership[232], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
}
