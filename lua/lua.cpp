#pragma comment(lib,"lua51.lib")
#include "lua.hpp"
#include <stdio.h>

int hand=LUA_NOREF;

int init(lua_State*l)
{
    hand=luaL_ref(l,LUA_REGISTRYINDEX);
    return 0;
}

int start(lua_State*l)
{
    lua_rawgeti(l,LUA_REGISTRYINDEX,hand);
    lua_call(l,0,0);
    lua_unref(l,LUA_REGISTRYINDEX,hand);
    
    return 0;
}

int main()
{
    lua_State*l=luaL_newstate();
    luaL_openlibs(l);
    
    lua_register(l,"init",init);
    lua_register(l,"start",start);
    
    luaL_dostring(l,
        R"(
            init(function() print(4) end)
            --recive function and save it
            start()
            --and now run it
        )"
    );

    return 0;
}