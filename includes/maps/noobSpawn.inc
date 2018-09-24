#include <YSI\y_hooks>

// Global interior define
#define MAPS_NOOBSPAWN_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Noob spawn in LS points
#define NOOBSPAWN_STARTBONUS_POINT   809.3212, -1339.9855, 13.5408
#define NOOBSPAWN_SERVERINFO_POINT   817.4735, -1345.8376, 13.5269

// Map variables
new object_noobSpawn[65];
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

    // Actors
    actor_noobSpawn[0] = CreateDynamicActor(150, 809.7925, -1338.9929, 13.5400, 255.5065, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR); // Greeting woman
    ApplyDynamicActorAnimation(actor_noobSpawn[0], "PED", "endchat_03", 4.0, 1, 0, 0, 0, 0);
    actor_noobSpawn[1] = CreateDynamicActor(141, 816.6170, -1345.5221, 13.5283, 271.2476, .worldid = VW_MAIN, .interiorid = MAPS_NOOBSPAWN_INTERIOR); // Information woman

	// Objects
    object_noobSpawn[0] = CreateDynamicObject(970, 825.3814, -1337.3884, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[0], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[1] = CreateDynamicObject(970, 821.2515, -1337.3884, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[1], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[2] = CreateDynamicObject(970, 813.6513, -1337.3884, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[2], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[3] = CreateDynamicObject(19121, 815.8870, -1337.3857, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[4] = CreateDynamicObject(19452, 808.5363, -1339.5000, 11.0361, 89.8000, -24.6000, -1.2999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall092
    SetDynamicObjectMaterial(object_noobSpawn[4], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    object_noobSpawn[5] = CreateDynamicObject(19121, 818.9970, -1337.3857, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[6] = CreateDynamicObject(970, 807.4481, -1346.5837, 13.0527, -0.0996, -0.1999, -90.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[6], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[7] = CreateDynamicObject(970, 807.4406, -1350.7430, 13.0670, -0.0996, -0.1999, -90.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[7], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[8] = CreateDynamicObject(970, 807.4334, -1354.9045, 13.0818, -0.0996, -0.1999, -90.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[8], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[9] = CreateDynamicObject(970, 807.4602, -1339.4532, 13.0277, -0.0996, -0.1999, -90.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[9], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[10] = CreateDynamicObject(19121, 807.4464, -1341.6861, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[11] = CreateDynamicObject(19121, 807.4464, -1344.3664, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[12] = CreateDynamicObject(19121, 807.5366, -1357.0367, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[13] = CreateDynamicObject(1280, 811.2056, -1356.6291, 12.9231, 0.0000, 0.0000, -89.4999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    SetDynamicObjectMaterial(object_noobSpawn[13], 1, 14668, "711c", "gun_ceiling1128", 0xFFFFFFFF);
    object_noobSpawn[14] = CreateDynamicObject(1360, 849.4369, -1378.2752, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[14], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[14], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[15] = CreateDynamicObject(1360, 853.4190, -1382.0546, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[15], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[15], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[16] = CreateDynamicObject(1360, 857.0679, -1385.5168, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[16], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[16], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[17] = CreateDynamicObject(19172, 808.7720, -1339.1927, 14.1365, 0.0000, -0.2000, 64.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[17], 0,"Forum: www.lyd-roleplay.de", 90, "Arial", 16, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[18] = CreateDynamicObject(19172, 808.7848, -1339.1671, 14.7067, 0.0000, -0.2000, 64.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[18], 0,"Unsere Plattformen:", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[19] = CreateDynamicObject(19172, 808.7589, -1339.2186, 13.7064, 0.0000, -0.2000, 64.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[19], 0,"Teamspeak: ts.lyd-roleplay.de", 90, "Arial", 16, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[20] = CreateDynamicObject(19172, 808.7546, -1339.2282, 13.9264, 0.0000, -0.2000, 64.0998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[20], 0,"UCP: www.ucp.lyd-roleplay.de", 90, "Arial", 16, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[21] = CreateDynamicObject(19172, 808.3779, -1355.2445, 14.7985, 0.0000, -0.2000, 129.9998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[21], 0,"Willkommen auf LyD!", 90, "Arial", 22, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[22] = CreateDynamicObject(19172, 808.4025, -1355.2229, 14.1688, -0.7999, -0.2000, 129.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[22], 0,"Fuer Cheatermeldungen - benutze /Admin", 90, "Arial", 14, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[23] = CreateDynamicObject(19172, 808.4042, -1355.2202, 13.9488, -0.7999, -0.2000, 129.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[23], 0,"Fuer die Orientierung - benutze /Navi", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[24] = CreateDynamicObject(1280, 813.2362, -1337.6838, 12.9231, 0.0000, 0.0000, 90.1001, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    SetDynamicObjectMaterial(object_noobSpawn[24], 1, 14668, "711c", "gun_ceiling1128", 0xFFFFFFFF);
    object_noobSpawn[25] = CreateDynamicObject(1280, 822.0169, -1337.6694, 12.9231, 0.0000, 0.0000, 90.1001, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    SetDynamicObjectMaterial(object_noobSpawn[25], 1, 14668, "711c", "gun_ceiling1128", 0xFFFFFFFF);
    object_noobSpawn[26] = CreateDynamicObject(19172, 808.4005, -1355.2257, 14.3988, -0.7999, -0.2000, 129.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[26], 0,"Fuer Fragen - benutze /Sup", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[27] = CreateDynamicObject(970, 809.5009, -1337.3884, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[27], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[28] = CreateDynamicObject(1360, 845.0623, -1374.1252, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[28], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[28], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[29] = CreateDynamicObject(1360, 839.3535, -1368.7060, -0.7429, 0.0000, 0.0000, 46.5000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[29], 0, 2951, "a51_labdoor", "washapartwall1_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[29], 2, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[30] = CreateDynamicObject(1375, 815.3081, -1359.7972, 0.1385, -0.2998, 1.0000, 47.6996, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tramstop_SF
    object_noobSpawn[31] = CreateDynamicObject(640, 841.4866, -1341.9995, 6.7670, 0.0000, 0.0000, 23.7999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_noobSpawn[31], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[32] = CreateDynamicObject(1360, 814.6018, -1346.1185, -0.8320, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[33] = CreateDynamicObject(1375, 796.9146, -1342.7358, 0.0697, 0.0000, 0.3998, 51.7000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tramstop_SF
    object_noobSpawn[34] = CreateDynamicObject(1360, 820.2686, -1351.2290, -0.8920, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[35] = CreateDynamicObject(1360, 808.6868, -1340.8188, -0.7421, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[36] = CreateDynamicObject(1360, 802.9547, -1335.6457, -0.7421, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[37] = CreateDynamicObject(1360, 796.7241, -1330.2165, -0.7421, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[38] = CreateDynamicObject(1360, 789.8045, -1323.9852, -0.7421, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    object_noobSpawn[39] = CreateDynamicObject(1233, 816.4837, -1332.9117, 14.0256, 0.0000, 0.0000, 179.8000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //noparkingsign1
    object_noobSpawn[40] = CreateDynamicObject(1375, 825.1723, -1368.7724, -0.1176, -0.2998, 1.0000, 47.6996, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tramstop_SF
    object_noobSpawn[41] = CreateDynamicObject(967, 816.3640, -1346.6331, 12.5152, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebox01
    SetDynamicObjectMaterial(object_noobSpawn[41], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[41], 1, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_noobSpawn[42] = CreateDynamicObject(2942, 827.1663, -1355.6239, 13.1646, 0.0000, 0.0000, -90.6998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_atm1
    object_noobSpawn[43] = CreateDynamicObject(3802, 826.8685, -1352.6462, 17.5550, 0.0996, 1.5999, 179.1999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[43], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[43], 3, 16093, "a51_ext", "stormdrain2_nt", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[43], 5, 16093, "a51_ext", "BLOCK2", 0xFFFFFFFF);
    object_noobSpawn[44] = CreateDynamicObject(19358, 808.4810, -1355.4625, 14.1331, 0.0000, -0.8999, 39.7999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall006
    SetDynamicObjectMaterial(object_noobSpawn[44], 0, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    object_noobSpawn[45] = CreateDynamicObject(3802, 814.8411, -1356.4261, 17.5310, 0.0000, 0.0000, 91.4998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[45], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    object_noobSpawn[46] = CreateDynamicObject(1360, 834.5607, -1364.2596, -0.8920, 0.0000, 0.0000, 47.2000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_BUSH_PROP3
    SetDynamicObjectMaterial(object_noobSpawn[46], 1, 16322, "a51_stores", "metalic128", 0xFFFFFFFF);
    object_noobSpawn[47] = CreateDynamicObject(3802, 817.3513, -1339.9890, 17.6177, 0.8999, 2.0999, -90.1996, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[47], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    object_noobSpawn[48] = CreateDynamicObject(3802, 810.1104, -1347.7403, 17.5069, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[48], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    object_noobSpawn[49] = CreateDynamicObject(3802, 823.1591, -1356.1816, 17.5062, -0.5000, 0.4999, 89.3000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sfx_plant03
    SetDynamicObjectMaterial(object_noobSpawn[49], 1, 16093, "a51_ext", "block2_high", 0xFFFFFFFF);
    object_noobSpawn[50] = CreateDynamicObject(640, 839.3153, -1337.0770, 6.7670, 0.0000, 0.0000, 23.7999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_noobSpawn[50], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[51] = CreateDynamicObject(19172, 808.4059, -1355.2174, 13.7188, -0.7999, -0.2000, 129.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[51], 0,"Fuer eine Uebersicht - benutze /Help", 90, "Arial", 15, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[52] = CreateDynamicObject(19172, 808.3779, -1355.2445, 14.7985, 0.0000, -0.2000, 129.9998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_noobSpawn[52], 0,"Willkommen auf LyD!", 90, "Arial", 22, 1, 0xFFFFFFFF, 0x0, 0);
    object_noobSpawn[53] = CreateDynamicObject(967, 816.3640, -1345.1729, 12.5152, 0.0000, 0.0000, -179.1999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebox01
    SetDynamicObjectMaterial(object_noobSpawn[53], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_noobSpawn[53], 1, 10765, "airportgnd_sfse", "ws_whiteplaster_top", 0xFFFFFFFF);
    object_noobSpawn[54] = CreateDynamicObject(1239, 817.0948, -1345.2106, 13.5363, 0.0000, 0.0000, -93.3999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //info
    object_noobSpawn[55] = CreateDynamicObject(1375, 832.9511, -1375.8508, -0.3194, -0.6998, 1.0000, 47.6996, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tramstop_SF
    object_noobSpawn[56] = CreateDynamicObject(970, 825.4514, -1344.5699, 13.0036, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencesmallb
    SetDynamicObjectMaterial(object_noobSpawn[56], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[57] = CreateDynamicObject(19121, 823.2172, -1344.5666, 13.0712, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BollardLight1
    object_noobSpawn[58] = CreateDynamicObject(1286, 813.7977, -1356.6202, 13.1358, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newstandnew4
    object_noobSpawn[59] = CreateDynamicObject(1286, 813.3776, -1356.6202, 13.1358, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newstandnew4
    object_noobSpawn[60] = CreateDynamicObject(1286, 817.6781, -1356.6202, 13.1358, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newstandnew4
    object_noobSpawn[61] = CreateDynamicObject(1286, 818.0985, -1356.6202, 13.1358, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newstandnew4
    object_noobSpawn[62] = CreateDynamicObject(640, 843.6531, -1346.9138, 6.7670, 0.0000, 0.0000, 23.7999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    SetDynamicObjectMaterial(object_noobSpawn[62], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0xFFFFFFFF);
    object_noobSpawn[63] = CreateDynamicObject(1340, 826.0897, -1348.7567, 13.5705, 0.0000, 0.0000, 179.7998, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //chillidogcart
    object_noobSpawn[64] = CreateDynamicObject(1239, 815.6415, -1346.5881, 13.5363, 0.0000, 0.0000, -93.3999, VW_MAIN, MAPS_NOOBSPAWN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //info
}
