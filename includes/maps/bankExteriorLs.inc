#include <YSI\y_hooks>

// Global interior define
#define MAPS_BANKEXTERIORLS_INTERIOR      0
#define MAPS_BANKINTERIORLS_INTERIOR      0

// Local drawdistance & streamdistance setting
//static Float:STREAMDISTANCE = 350.0;
//static Float:DRAWDISTANCE   = 350.0;

// Bank Exterior LS Points
#define BANKINTERIORLS_EXIT_COORDS      1415.9511, -988.9711, 1639.9802
#define BANKINTERIORLS_EXIT_FACING      270.0
#define BANKINTERIORLS_ENTER_COORDS     1462.6464, -1011.3412, 26.8438
#define BANKINTERIORLS_ENTER_FACING     180.0

// Map variables
//new object_bankExteriorLs[0];
new pickup_bankExteriorLs[1];
new text3D_bankExteriorLs[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, BANKINTERIORLS_ENTER_COORDS)) {
            if (g_iBankraubStatus == Bankraub_Aktiv)
		        if (!IsPlayerExecutive(playerid))
					return SendClientMessage(playerid, COLOR_RED, "Du kannst die Zentralbank nicht betreten, weil die Polizei aufgrund eines Überfalles die Bank gesperrt hat!");
            
            SetPlayerPosEx(playerid, BANKINTERIORLS_EXIT_COORDS, MAPS_BANKINTERIORLS_INTERIOR, VW_BANKINTERIORLS);
            SetPlayerFacingAngle(playerid, BANKINTERIORLS_EXIT_FACING);
            SetCameraBehindPlayer(playerid);

            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {    
    // Pickups
    pickup_bankExteriorLs[0] = CreateDynamicPickup(19197, 1, BANKINTERIORLS_ENTER_COORDS, VW_MAIN, MAPS_BANKEXTERIORLS_INTERIOR); // Bank interior enter 

    // 3DTextLabels
    text3D_bankExteriorLs[0] = _:CreateDynamic3DTextLabel("Zentralbank Los Santos\n" COLOR_HEX_WHITE "Gebäude betreten mit 'Enter'", COLOR_BLUE, BANKINTERIORLS_ENTER_COORDS, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BANKEXTERIORLS_INTERIOR);

    // Objects
    
}