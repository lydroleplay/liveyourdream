#include <a_samp>
#include <sampcac>

public OnRconCommand(cmd[]) {
    return 0;
}

public CAC_OnPlayerKick(player_id, reason_id) {
    return CallRemoteFunction("AC_OnPlayerKick", "ii", player_id, reason_id);
}

public CAC_OnCheatDetect(player_id, cheat_id, opt1, opt2) {
    return CallRemoteFunction("AC_OnCheatDetect", "iiii", player_id, cheat_id, opt1, opt2);
}

public CAC_OnGameResourceMismatch(player_id, model_id, component_type, checksum) {
    return CallRemoteFunction("AC_OnGameResourceMismatch", "iiii", player_id, model_id, component_type, checksum);
}
