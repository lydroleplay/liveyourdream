#include <YSI\y_hooks>

// Global interior define
#define MAPS_PAINTBALLBASEMENT_INTERIOR      1

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// Map variables

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 1775, 2209.9063, 1607.1953, 1000.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 1776, 2202.4531, 1617.0078, 1000.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 2681, 2206.7266, 1615.7734, 998.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1776, 2209.2422, 1621.2109, 1000.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 1776, 2222.3672, 1602.6406, 1000.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 1775, 2222.2031, 1606.7734, 1000.0547, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
}