#include <YSI\y_hooks>

// Global interior define
#define MAPS_GSFEXTERIOR_INTERIOR      0
#define MAPS_GSFINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// GSF points
#define GSF_INTERIOR_ENTER_COORDS        2495.3547, -1690.6273, 14.7656
#define GSF_INTERIOR_EXIT_COORDS         2495.9873, -1692.3297, 1014.7422
#define GSF_INTERIOR_ENTER_FACING        180.0
#define GSF_INTERIOR_EXIT_FACING         0.0

// Map variables
new pickup_gsfExterior[1];
new text3D_gsfExterior[1];
new vehicle_gsfExterior[16];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, GSF_INTERIOR_ENTER_COORDS)) { // GSF Entrance
            if (Spieler[playerid][pFraktion] != 6) return SendClientMessage(playerid, COLOR_RED, "Du bist kein Mitglied der Grove Street.");
            SetPlayerInterior(playerid, MAPS_GSFINTERIOR_INTERIOR);
            SetPlayerVirtualWorld(playerid, VW_GSFINTERIOR);
            SetPlayerPos(playerid, GSF_INTERIOR_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, GSF_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Vehicles
    vehicle_gsfExterior[0]  = AddStaticVehicleEx(451, 2473.2583, -1694.4656, 13.2400, 0.1565,   86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[1]  = AddStaticVehicleEx(541, 2473.2947, -1703.3059, 13.0748, 0.0540,   86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[2]  = AddStaticVehicleEx(482, 2459.6746, -1673.9707, 13.5140, 35.1171,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[3]  = AddStaticVehicleEx(492, 2460.2600, -1664.1295, 13.1713, 269.3049, 86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[4]  = AddStaticVehicleEx(411, 2480.2668, -1653.4987, 13.1263, 90.8599,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[5]  = AddStaticVehicleEx(411, 2486.9036, -1653.4114, 13.1377, 91.2914,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[6]  = AddStaticVehicleEx(480, 2502.9614, -1656.5347, 13.2613, 57.0989,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[7]  = AddStaticVehicleEx(415, 2507.0894, -1677.5730, 13.2404, 324.0849, 86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[8]  = AddStaticVehicleEx(560, 2499.1611, -1683.1373, 13.0975, 281.7965, 86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[9]  = AddStaticVehicleEx(560, 2492.1660, -1684.1700, 13.1276, 273.6986, 86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[10] = AddStaticVehicleEx(567, 2510.5535, -1687.4958, 13.4692, 47.9130,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[11] = AddStaticVehicleEx(522, 2515.7395, -1666.9268, 13.3639, 97.3516,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[12] = AddStaticVehicleEx(468, 2519.4167, -1666.5616, 14.1826, 98.1252,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[13] = AddStaticVehicleEx(468, 2519.0330, -1663.9734, 13.9064, 95.4827,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[14] = AddStaticVehicleEx(522, 2515.3694, -1664.5391, 13.2992, 96.7674,  86, 86, -1); // NEUE GROVE CARS
    vehicle_gsfExterior[15] = AddStaticVehicleEx(535, 2468.4702, -1669.6483, 13.1571, 190.2437, 86, 86, -1); // NEUE GROVE CARS

    // Pickups
    pickup_gsfExterior[0] = CreateDynamicPickup(19197, 1, GSF_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_GSFEXTERIOR_INTERIOR); // Grove Street Entrance

    // 3DTextLabels
    text3D_gsfExterior[0] = _:CreateDynamic3DTextLabel("Territorium der\n" COLOR_HEX_GREEN "GROVE STREET", COLOR_YELLOW, GSF_INTERIOR_ENTER_COORDS, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_GSFEXTERIOR_INTERIOR);
}