#include "LuaShip.h"

static const char *s_type = "Ship";

const char *LuaShip::GetType() const
{
	return s_type;
}

static int l_ship_get_label(lua_State *l)
{
	luaL_checktype(l, 1, LUA_TUSERDATA);
	lid *idp = (lid*)lua_touserdata(l, 1);
	lpair pair = LuaObject::Lookup(*idp);
	assert(strcmp(pair.type, s_type) == 0);
	Ship *s = static_cast<Ship*>(pair.o);
	lua_pushstring(l, s->GetLabel().c_str());
	return 1;
} 

static const luaL_reg s_methods[] = {
	{ "get_label", l_ship_get_label },
	{ 0, 0 }
};

static const luaL_reg s_meta[] = {
	{ 0, 0 }
};

void LuaShip::RegisterClass()
{
	CreateClass(s_type, s_methods, s_meta);
}

void LuaShip::PushToLua()
{
	LuaObject::PushToLua(s_type);
}
