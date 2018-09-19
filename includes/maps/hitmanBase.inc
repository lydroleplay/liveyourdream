#include <YSI\y_hooks>

// Global interior define
#define MAPS_HITMANBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Hitman base points
#define HITMANBASE_SPAWN_POINT          -688.0314, 934.2285, 13.6328
#define HITMANBASE_SPAWN_POINT_FACING   0.0
#define HITMANBASE_ENTER_COORDS         -688.1488, 944.2652, 13.6328
#define HITMANBASE_EXIT_COORDS          -688.1279, 942.9332, 13.6328
#define HITMANBASE_ENTER_FACING         0.0
#define HITMANBASE_EXIT_FACING          180.0
#define HITMANBASE_FSKIN_POINT          -685.0497, 941.4647, 13.6328
#define HITMANBASE_AD_POINT             -691.1993, 941.8145, 13.6328
#define HITMANBASE_WEAPONS_DEPOT_POINT  -690.8252, 936.8415, 13.6328

// Map variables
new object_hitmanBase[81];
new pickup_hitmanBase[4];
new text3D_hitmanBase[3];
new vehicle_hitmanBase[15];

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 11664, -685.0939, 941.9140, 13.1406, 0.10);
    RemoveBuildingForPlayer(playerid, 700, -700.6560, 984.1409, 11.5546, 0.10);
    RemoveBuildingForPlayer(playerid, 11492, -681.8750, 965.8909, 11.1250, 0.10);
    RemoveBuildingForPlayer(playerid, 11654, -681.8750, 965.8909, 11.1250, 0.10);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 1.0, HITMANBASE_ENTER_COORDS)) { // Hitman Entrance
            if (Spieler[playerid][pFraktion] != 14) return SendClientMessage(playerid, COLOR_RED, "Die Tür ist zu.");
            SetPlayerPos(playerid, HITMANBASE_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, HITMANBASE_EXIT_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
        else if (IsPlayerInRangeOfPoint(playerid, 1.0, HITMANBASE_EXIT_COORDS)) { // Hitman Exit
            SetPlayerPos(playerid, HITMANBASE_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, HITMANBASE_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Vehicles
    vehicle_hitmanBase[0] = AddStaticVehicle(473, -661.7864, 876.6932, -0.1803, 225.1089, -1, -1); // hitman
    vehicle_hitmanBase[1] = AddStaticVehicle(411, -706.7307, 968.9254, 12.1815, 221.3496, -1, -1); // hitman
    vehicle_hitmanBase[2] = AddStaticVehicle(451, -697.4601, 969.0258, 12.0166, 222.7610, -1, -1); // hitman
    vehicle_hitmanBase[3] = AddStaticVehicle(411, -702.3138, 969.1326, 12.1175, 225.6084, -1, -1); // hitman
    vehicle_hitmanBase[4] = AddStaticVehicle(475, -692.5334, 968.9919, 12.0395, 221.4761, -1, -1); // hitman
    vehicle_hitmanBase[5] = AddStaticVehicle(560, -671.3557, 968.9650, 11.8342, 134.5210, -1, -1); // hitman
    vehicle_hitmanBase[6] = AddStaticVehicle(429, -675.9988, 969.0268, 11.8136, 131.0158, -1, -1); // hitman
    vehicle_hitmanBase[7] = AddStaticVehicle(480, -681.2371, 969.0425, 11.9076, 126.3826, -1, -1); // hitman
    vehicle_hitmanBase[8] = AddStaticVehicle(560, -666.7589, 968.7836, 11.8359, 138.1186, -1, -1); // hitman
    vehicle_hitmanBase[9] = AddStaticVehicle(487, -678.1942, 982.1398, 12.5393, 142.0905, -1, -1); // hitman
    vehicle_hitmanBase[10] = AddStaticVehicle(487, -692.9394, 981.9201, 12.5917, 128.8131, -1, -1); // hitman
    vehicle_hitmanBase[11] = AddStaticVehicle(522, -673.2268, 944.0676, 11.7050, 33.1575, -1, -1); // hitman
    vehicle_hitmanBase[12] = AddStaticVehicle(522, -671.4668, 944.9990, 11.6994, 31.5224, -1, -1); // hitman
    vehicle_hitmanBase[13] = AddStaticVehicle(522, -669.8409, 945.7893, 11.7045, 31.1202, -1, -1); // hitman
    vehicle_hitmanBase[14] = AddStaticVehicle(482, -700.3405, 945.9280, 12.4658, 359.9060, -1, -1); // hitman

    // Pickups
    pickup_hitmanBase[0] = CreateDynamicPickup(1239,  1, HITMANBASE_AD_POINT, VW_MAIN, MAPS_HITMANBASE_INTERIOR); // Hitman ad point
    pickup_hitmanBase[1] = CreateDynamicPickup(1240,  1, HITMANBASE_SPAWN_POINT, VW_MAIN, MAPS_HITMANBASE_INTERIOR); // Hitman spawn point
    pickup_hitmanBase[2] = CreateDynamicPickup(1275,  1, HITMANBASE_FSKIN_POINT, VW_MAIN, MAPS_HITMANBASE_INTERIOR); // Hitman fskin point
    pickup_hitmanBase[3] = CreateDynamicPickup(1254,  1, HITMANBASE_WEAPONS_DEPOT_POINT, VW_MAIN, MAPS_HITMANBASE_INTERIOR); // Hitman weapons depot point

    // 3DTextLabels
    text3D_hitmanBase[0] = _:CreateDynamic3DTextLabel("Hitman - Waffenlager\n" COLOR_HEX_WHITE "Tippe /Waffenlager", COLOR_YELLOW, HITMANBASE_WEAPONS_DEPOT_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_HITMANBASE_INTERIOR);
    text3D_hitmanBase[1] = _:CreateDynamic3DTextLabel("Hitman Spawn\n" COLOR_HEX_WHITE "Tippe /Hitmanwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, HITMANBASE_SPAWN_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_HITMANBASE_INTERIOR);
    text3D_hitmanBase[2] = _:CreateDynamic3DTextLabel("Hitman Werbung\n" COLOR_HEX_WHITE "Tippe /HWerbung", COLOR_YELLOW, HITMANBASE_AD_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_HITMANBASE_INTERIOR);

    // Objects
    object_hitmanBase[0] = CreateDynamicObject(18725, -688.0507, 931.2374, 21.9440, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smoke30lit
    object_hitmanBase[1] = CreateDynamicObject(18766, -686.2122, 981.3712, 10.9069, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hitmanBase[1], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_hitmanBase[2] = CreateDynamicObject(1569, -688.8781, 943.5983, 12.4347, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    object_hitmanBase[3] = CreateDynamicObject(19793, -687.8665, 931.6829, 12.6785, 0.0000, 0.0000, -30.7999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FireWoodLog1
    object_hitmanBase[4] = CreateDynamicObject(19793, -688.2985, 931.4981, 12.6785, 0.0000, 0.0000, 22.5998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FireWoodLog1
    object_hitmanBase[5] = CreateDynamicObject(19793, -688.3344, 931.5631, 12.7775, 0.0000, 22.7999, 118.9999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FireWoodLog1
    object_hitmanBase[6] = CreateDynamicObject(19793, -687.9428, 931.6024, 12.7658, 0.0000, -28.8999, 77.3999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FireWoodLog1
    object_hitmanBase[7] = CreateDynamicObject(3660, -673.8778, 972.6137, 12.9572, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_hitmanBase[8] = CreateDynamicObject(18689, -688.0911, 931.2349, 11.0094, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fire_bike
    object_hitmanBase[9] = CreateDynamicObject(3660, -698.5529, 972.6137, 12.9572, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_hitmanBase[10] = CreateDynamicObject(19367, -691.1024, 931.8176, 13.3229, 0.0000, 0.0000, 90.0998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall015
    SetDynamicObjectMaterial(object_hitmanBase[10], 0, 3820, "boxhses_sfsx", "LAcreamwall1", 0x00000000);
    object_hitmanBase[11] = CreateDynamicObject(19367, -690.4118, 931.8184, 13.3229, 0.0000, 0.0000, 90.0998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall015
    SetDynamicObjectMaterial(object_hitmanBase[11], 0, 3820, "boxhses_sfsx", "LAcreamwall1", 0x00000000);
    object_hitmanBase[12] = CreateDynamicObject(18766, -681.2116, 981.5526, 10.9083, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hitmanBase[12], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_hitmanBase[13] = CreateDynamicObject(19367, -684.9215, 931.8178, 13.3229, 0.0000, 0.0000, 90.0998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall015
    SetDynamicObjectMaterial(object_hitmanBase[13], 0, 3820, "boxhses_sfsx", "LAcreamwall1", 0x00000000);
    object_hitmanBase[14] = CreateDynamicObject(1507, -688.8579, 931.8526, 10.2749, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT09
    SetDynamicObjectMaterial(object_hitmanBase[14], 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
    object_hitmanBase[15] = CreateDynamicObject(18766, -686.2122, 976.3519, 10.9083, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hitmanBase[15], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0x00000000);
    object_hitmanBase[16] = CreateDynamicObject(18766, -676.2119, 981.5526, 10.9083, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hitmanBase[16], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_hitmanBase[17] = CreateDynamicObject(19367, -685.7318, 931.8261, 13.3229, 0.0000, 0.0000, 90.0998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall015
    SetDynamicObjectMaterial(object_hitmanBase[17], 0, 3820, "boxhses_sfsx", "LAcreamwall1", 0x00000000);
    object_hitmanBase[18] = CreateDynamicObject(19173, -685.1915, 931.9282, 14.0633, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    object_hitmanBase[19] = CreateDynamicObject(18766, -691.2114, 981.5526, 10.9083, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hitmanBase[19], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_hitmanBase[20] = CreateDynamicObject(18766, -696.2113, 981.5526, 10.9083, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_hitmanBase[20], 0, 6522, "cuntclub_law2", "helipad_grey1", 0x00000000);
    object_hitmanBase[21] = CreateDynamicObject(1215, -688.6389, 971.1738, 11.4146, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_hitmanBase[22] = CreateDynamicObject(19464, -688.6007, 974.2938, 8.8620, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[22], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[23] = CreateDynamicObject(19464, -683.8208, 974.2938, 8.8620, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[23], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[24] = CreateDynamicObject(19464, -683.8208, 980.2299, 8.8620, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[24], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[25] = CreateDynamicObject(2637, -692.0416, 936.8259, 13.0277, 0.0000, 0.0000, 89.8999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_PIZZA_TABLE2
    object_hitmanBase[26] = CreateDynamicObject(19464, -688.6007, 980.2299, 8.8620, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[26], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[27] = CreateDynamicObject(2041, -691.8009, 936.0573, 12.8071, 0.0000, 0.0000, 118.8000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M2
    object_hitmanBase[28] = CreateDynamicObject(19464, -683.8208, 983.5109, 8.8611, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[28], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[29] = CreateDynamicObject(2042, -692.2265, 936.3225, 12.7059, 0.0000, 0.0000, -31.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //AMMO_BOX_M3
    object_hitmanBase[30] = CreateDynamicObject(19464, -688.6007, 983.5109, 8.8611, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[30], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[31] = CreateDynamicObject(19464, -676.6301, 986.4301, 8.8620, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[31], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[32] = CreateDynamicObject(19464, -682.5662, 986.4301, 8.8620, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[32], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[33] = CreateDynamicObject(19464, -688.5029, 986.4301, 8.8620, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[33], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[34] = CreateDynamicObject(355, -692.4832, 937.2055, 13.8521, -5.4998, -46.7000, 93.0998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ak47
    object_hitmanBase[35] = CreateDynamicObject(19464, -694.4409, 986.4301, 8.8620, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[35], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[36] = CreateDynamicObject(19464, -698.6613, 983.3347, 8.8631, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[36], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[37] = CreateDynamicObject(358, -691.7609, 936.2122, 13.5059, -102.5998, -18.9999, 43.0998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    object_hitmanBase[38] = CreateDynamicObject(348, -691.9713, 936.9804, 13.5066, -87.2996, 0.0000, 99.3000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //desert_eagle
    object_hitmanBase[39] = CreateDynamicObject(358, -691.3602, 936.0521, 12.9102, 3.5000, -67.8000, -104.5998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    object_hitmanBase[40] = CreateDynamicObject(19464, -695.8211, 986.4312, 8.8631, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[40], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[41] = CreateDynamicObject(358, -691.3648, 936.3510, 12.9146, 3.5000, -67.8000, -104.5998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sniper
    object_hitmanBase[42] = CreateDynamicObject(1580, -692.3463, 936.1787, 13.4236, 0.0000, 0.0000, 127.4999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //drug_red
    object_hitmanBase[43] = CreateDynamicObject(19464, -698.6605, 979.5130, 8.8620, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[43], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[44] = CreateDynamicObject(3016, -691.7150, 937.4298, 12.7826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_ammobox_nonbrk
    object_hitmanBase[45] = CreateDynamicObject(3016, -691.7150, 937.8098, 12.7826, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_ammobox_nonbrk
    object_hitmanBase[46] = CreateDynamicObject(3016, -691.7564, 937.6425, 13.0326, 0.0000, 0.0000, 21.9999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //cr_ammobox_nonbrk
    object_hitmanBase[47] = CreateDynamicObject(19464, -695.8200, 976.4227, 8.8631, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[47], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[48] = CreateDynamicObject(19172, -692.6787, 937.0132, 14.9329, 0.0000, 0.0000, 89.8999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_hitmanBase[48], 0, "> Waffenlager <", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_hitmanBase[48], 1, 19297, "matlights", "invisible", 0x00000000);
    object_hitmanBase[49] = CreateDynamicObject(19464, -691.6973, 976.4218, 8.8620, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[49], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[50] = CreateDynamicObject(19464, -673.7694, 979.5130, 8.8620, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[50], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[51] = CreateDynamicObject(19583, -691.7089, 937.3128, 13.4652, 0.0000, 0.0000, -112.5998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MarcosKnife1
    object_hitmanBase[52] = CreateDynamicObject(19583, -691.6173, 937.4686, 13.4715, -4.6999, 0.0000, -30.3999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MarcosKnife1
    object_hitmanBase[53] = CreateDynamicObject(19464, -673.7683, 983.5847, 8.8610, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[53], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[54] = CreateDynamicObject(19583, -691.6353, 937.5656, 13.7889, 84.6996, 0.0000, -160.3999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MarcosKnife1
    object_hitmanBase[55] = CreateDynamicObject(19464, -680.7473, 976.4218, 8.8620, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[55], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[56] = CreateDynamicObject(19464, -676.6165, 976.4207, 8.8610, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_hitmanBase[56], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_hitmanBase[57] = CreateDynamicObject(3934, -678.8662, 981.5756, 11.4063, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_hitmanBase[58] = CreateDynamicObject(3934, -693.8261, 981.5756, 11.4063, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_hitmanBase[59] = CreateDynamicObject(1215, -685.6461, 947.5772, 11.3141, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_hitmanBase[60] = CreateDynamicObject(1215, -683.8181, 971.1738, 11.4146, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_hitmanBase[61] = CreateDynamicObject(2612, -691.0189, 931.9404, 13.9791, 0.0000, 0.0000, -179.8999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_NB2
    SetDynamicObjectMaterial(object_hitmanBase[61], 3, 2577, "cj_sex", "CJ_PAINTING9", 0x00000000);
    object_hitmanBase[62] = CreateDynamicObject(1215, -690.5767, 947.5772, 11.3141, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_hitmanBase[63] = CreateDynamicObject(18725, -677.2910, 940.0383, 21.9440, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //smoke30lit
    object_hitmanBase[64] = CreateDynamicObject(1569, -687.5875, 943.5983, 12.4347, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    SetDynamicObjectMaterial(object_hitmanBase[64], 0, 9514, "711_sfw", "rebrckwall_128", 0xFFA0522D);
    object_hitmanBase[65] = CreateDynamicObject(1344, -704.1834, 943.3751, 12.1260, 0.0000, 0.0000, 179.3999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dumpster2
    object_hitmanBase[66] = CreateDynamicObject(1569, -688.7088, 943.5983, 12.4347, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    SetDynamicObjectMaterial(object_hitmanBase[66], 0, 9514, "711_sfw", "rebrckwall_128", 0xFFA0522D);
    object_hitmanBase[67] = CreateDynamicObject(19922, -684.8546, 942.6381, 12.6083, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_hitmanBase[68] = CreateDynamicObject(2704, -685.8656, 942.7929, 13.4069, 90.0000, 0.0000, -130.1000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOODIE_3
    object_hitmanBase[69] = CreateDynamicObject(2689, -684.2174, 942.7969, 13.4269, 90.0000, 0.0000, 131.1999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOODIE_2
    object_hitmanBase[70] = CreateDynamicObject(2706, -685.2702, 942.9849, 13.4669, 90.0000, 0.0000, -167.7998, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_HOODIE_05
    object_hitmanBase[71] = CreateDynamicObject(2386, -684.8323, 942.3375, 13.5010, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_SWEATER_F_1
    object_hitmanBase[72] = CreateDynamicObject(2052, -685.3104, 942.2427, 13.4128, 0.0000, 0.0000, -44.2000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_TOMMY_HAT
    object_hitmanBase[73] = CreateDynamicObject(2374, -684.4403, 943.1920, 14.3058, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Tshirt
    object_hitmanBase[74] = CreateDynamicObject(2378, -685.6311, 943.1632, 14.2882, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_jean_light
    object_hitmanBase[75] = CreateDynamicObject(19922, -682.4341, 942.1879, 13.3283, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_hitmanBase[76] = CreateDynamicObject(19922, -682.4341, 942.1879, 13.9683, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MKTable1
    object_hitmanBase[77] = CreateDynamicObject(18645, -683.7974, 941.9016, 14.8443, 0.0000, -26.0000, -154.4999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet1
    object_hitmanBase[78] = CreateDynamicObject(18645, -683.8043, 942.5077, 14.8423, 0.0000, -26.0000, 138.5000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MotorcycleHelmet1
    object_hitmanBase[79] = CreateDynamicObject(18941, -683.7777, 941.7648, 14.1852, -17.8999, -89.3999, -31.5999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CapBack3
    SetDynamicObjectMaterial(object_hitmanBase[79], 0, -1, "none", "none", 0xFFFF0000);
    object_hitmanBase[80] = CreateDynamicObject(19515, -683.8163, 942.4082, 14.3428, 0.0000, -90.0000, 99.0999, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SWATAgrey
}
