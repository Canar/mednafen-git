#ifndef __MDFN_SETTINGS_DRIVER_H
#define __MDFN_SETTINGS_DRIVER_H

#include "settings-common.h"

namespace Mednafen
{
//
// Due to how the per-module(and in the future, per-game) settings overrides work, we should
// take care not to call MDFNI_SetSetting*() unless the setting has actually changed due to a user action.
// I.E. do NOT call SetSetting*() unconditionally en-masse at emulator exit/game close to synchronize certain things like input mappings.
//
bool MDFNI_SetSetting(const char *name, const char *value, bool NetplayOverride = false);
static INLINE bool MDFNI_SetSetting(const char *name, const std::string& value, bool NetplayOverride = false) { return MDFNI_SetSetting(name, value.c_str(), NetplayOverride); }
static INLINE bool MDFNI_SetSetting(const std::string& name, const std::string& value, bool NetplayOverride = false) { return MDFNI_SetSetting(name.c_str(), value.c_str(), NetplayOverride); }

bool MDFNI_SetSettingB(const char *name, bool value);
static INLINE bool MDFNI_SetSettingB(const std::string& name, bool value) { return MDFNI_SetSettingB(name.c_str(), value); }

bool MDFNI_SetSettingUI(const char *name, uint64 value);
static INLINE bool MDFNI_SetSettingUI(const std::string& name, uint64 value) { return MDFNI_SetSettingUI(name.c_str(), value); }

void MDFNI_DumpSettingsDef(const char *path) MDFN_COLD;

const std::vector<MDFNCS>* MDFNI_GetSettings(void);
std::string MDFNI_GetSettingDefault(const char* name);
static INLINE std::string MDFNI_GetSettingDefault(const std::string& name) { return MDFNI_GetSettingDefault(name.c_str()); }

}
#endif
