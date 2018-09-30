#include <YSI\y_hooks>

// Global interior define
#define MAPS_TRIADSEXTERIOR_INTERIOR      0
#define MAPS_TRIADSINTERIOR_INTERIOR      6

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// Triads points
#define TRIADS_INTERIOR_ENTER_COORDS        893.6498, -1636.3358, 14.9297
#define TRIADS_INTERIOR_EXIT_COORDS         774.1301, -49.8932, 1000.5859
#define TRIADS_INTERIOR_ENTER_FACING        0.0
#define TRIADS_INTERIOR_EXIT_FACING         180.0

// Map variables
new pickup_triadsExterior[1];
new text3D_triadsExterior[1];
new vehicle_triadsExterior[17];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, TRIADS_INTERIOR_ENTER_COORDS)) { // Triads Entrance
            if (Spieler[playerid][pFraktion] != 21) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Triaden.");
            SetPlayerInterior(playerid, MAPS_TRIADSINTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_TRIADSINTERIOR);
            SetPlayerPos(playerid, TRIADS_INTERIOR_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, TRIADS_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Vehicles
    vehicle_triadsExterior[0] =  AddStaticVehicleEx(409, 896.7750, -1655.9691, 13.3472, 178.9410, 79, 79, -1); // StretchT
    vehicle_triadsExterior[1] =  AddStaticVehicleEx(411, 892.4311, -1657.7754, 13.2748, 179.8933, 79, 79, -1); // InfernusT1
    vehicle_triadsExterior[2] =  AddStaticVehicleEx(411, 888.1113, -1657.7825, 13.2755, 179.9628, 79, 79, -1); // InfernusT2
    vehicle_triadsExterior[3] =  AddStaticVehicleEx(541, 883.5677, -1657.7855, 13.1728, 178.9484, 79, 79, -1); // BulletT
    vehicle_triadsExterior[4] =  AddStaticVehicleEx(480, 878.9016, -1657.8204, 13.3216, 179.2057, 79, 79, -1); // CometT
    vehicle_triadsExterior[5] =  AddStaticVehicleEx(451, 874.6393, -1657.8138, 13.2544, 179.5383, 79, 79, -1); // TurismoT
    vehicle_triadsExterior[6] =  AddStaticVehicleEx(415, 869.9275, -1657.7087, 13.3188, 178.4672, 79, 79, -1); // CheetahT
    vehicle_triadsExterior[7] =  AddStaticVehicleEx(580, 874.5012, -1669.2662, 13.3443, 359.8367, 79, 79, -1); // StaffordT2
    vehicle_triadsExterior[8] =  AddStaticVehicleEx(580, 870.1223, -1669.1895, 13.3452, 359.2371, 79, 79, -1); // StaffordT1
    vehicle_triadsExterior[9] =  AddStaticVehicleEx(579, 878.9442, -1669.2207, 13.4791, 358.5986, 79, 79, -1); // HuntleyT1
    vehicle_triadsExterior[10] = AddStaticVehicleEx(579, 883.5723, -1669.1840, 13.4787, 359.2401, 79, 79, -1); // HuntleyT2
    vehicle_triadsExterior[11] = AddStaticVehicleEx(560, 887.9981, -1669.5670, 13.2528, 358.5898, 79, 79, -1); // SultanT1
    vehicle_triadsExterior[12] = AddStaticVehicleEx(560, 892.7249, -1669.5676, 13.2584, 0.4935,   79, 79, -1); // SultanT2
    vehicle_triadsExterior[13] = AddStaticVehicleEx(522, 887.2391, -1646.5526, 13.1130, 178.2078, 79, 79, -1); // NRGT2
    vehicle_triadsExterior[14] = AddStaticVehicleEx(522, 888.6750, -1646.6385, 13.1120, 178.2306, 79, 79, -1); // NRGT1
    vehicle_triadsExterior[15] = AddStaticVehicleEx(468, 895.8872, -1646.4558, 13.2155, 175.7712, 79, 79, -1); // Sanchez2
    vehicle_triadsExterior[16] = AddStaticVehicleEx(468, 897.2885, -1646.4406, 13.2156, 177.4924, 79, 79, -1); // Sanchez1

    // Pickups
    pickup_triadsExterior[0] = CreateDynamicPickup(19197, 1, TRIADS_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_TRIADSEXTERIOR_INTERIOR); // Triads Entrance

    // 3DTextLabels
    text3D_triadsExterior[0] = _:CreateDynamic3DTextLabel("Territorium der\n" COLOR_HEX_BLUE "TRIADEN", COLOR_YELLOW, TRIADS_INTERIOR_ENTER_COORDS, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TRIADSEXTERIOR_INTERIOR);
    // Actors

    // Objects
}
