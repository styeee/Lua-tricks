#include <iostream>
using namespace std;
#pragma comment(lib,"lua51")
#pragma comment(lib,"luajit")
#pragma comment(lib,"minilua")
#include "lua.hpp"

int get(lua_State*lua)
{
    const size_t n=lua_tointeger(lua,1);
    const size_t v=lua_tointeger(lua,2);
    int*a=(int*)lua_newuserdata(lua,n*4+1);

    for(size_t i=0;i<n;i++)
        a[i]=v;
    a[n]=0;

    return 1;
}

int set(lua_State*lua)
{
    int*a=(int*)lua_touserdata(lua,1);

    while(*a)
        cout<<(*(++a))<<endl;

    return 0;
}

int main()
{
    lua_State*lua=lua_open();
    luaL_openlibs(lua);

    lua_register(lua,"get",get);
    lua_register(lua,"set",set);

    luaL_dostring(lua,"a=get(5,10) set(a)");

    lua_close(lua);

    return 0;
}
