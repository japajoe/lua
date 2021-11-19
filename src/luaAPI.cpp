#include "luaAPI.h"
#include <iostream>
#include <cstring>
#include <cstdint>

luaErrorCallback luaAPI::onError = nullptr;
luaWriteLineCallback luaAPI::onWriteLine = nullptr;
lua_State* luaAPI::L = nullptr;

bool luaAPI::CheckArgumentCount(lua_State* state, int numArguments)
{
    if(lua_gettop(L) != numArguments)
        return false;
    return true;
}

bool luaAPI::Dispose(lua_State** state)
{
    if(L != nullptr)
    {
        lua_close(L);
        L = nullptr;
        *state = luaAPI::L;
        return true;
    }

    *state = luaAPI::L;
    return false;
}

int luaAPI::DoFile(lua_State** state, const char* filepath)
{
    int result = luaL_dofile(luaAPI::L, filepath);
    *state = luaAPI::L;
    return result;
}

int luaAPI::DoString(lua_State** state, const char* code)
{
    int result = luaL_dostring(luaAPI::L, code);
    *state = luaAPI::L;
    return result;
}

int luaAPI::GetArgumentCount(lua_State** state)
{
    int result = lua_gettop(L);
    *state = luaAPI::L;
    return result;
}

void luaAPI::GetGlobal(lua_State** state, const char* name)
{
    lua_getglobal(luaAPI::L, name);
    *state = luaAPI::L;
}

void luaAPI::GetTable(lua_State** state, int stackIndex)
{
    lua_gettable(luaAPI::L, stackIndex);
    *state = luaAPI::L;
}

int luaAPI::GetTop(lua_State** state)
{
    int result = lua_gettop(luaAPI::L);
    *state = luaAPI::L;
    return result;
}

bool luaAPI::Initialize(lua_State** state)
{
    if(L != nullptr)
        return false;

    L = luaL_newstate();    

    luaL_openlibs(L);

    lua_register(L, "writeline", lua_WriteLine);
    luaL_dostring(L, "old_print = print");
    luaL_dostring(L, "print = writeline");    

    *state = luaAPI::L;       

    return true;
}

bool luaAPI::IsFunction(lua_State** state, int stackIndex)
{
    if(lua_isfunction(luaAPI::L, stackIndex))
    {
        *state = luaAPI::L;
        return true;
    }

    *state = luaAPI::L;
    return false;
}

bool luaAPI::IsNumber(lua_State** state, int stackIndex)
{
    if(lua_isnumber(luaAPI::L, stackIndex))
    {
        *state = luaAPI::L;
        return true;
    }

    *state = luaAPI::L;
    return false;
}

bool luaAPI::IsString(lua_State** state, int stackIndex)
{
    if(lua_isstring(luaAPI::L, stackIndex))
    {
        *state = luaAPI::L;
        return true;
    }

    *state = luaAPI::L;
    return false;
}

bool luaAPI::IsTable(lua_State** state, int stackIndex)
{
    if(lua_istable(luaAPI::L, stackIndex))
    {
        *state = luaAPI::L;
        return true;
    }

    *state = luaAPI::L;
    return false;
}

int luaAPI::PCall(lua_State** state, int numArgs, int numReturnValues, int errorHandlingType)
{
    int result = lua_pcall(luaAPI::L, numArgs, numReturnValues, errorHandlingType);
    *state = luaAPI::L;
    return result;
}

void luaAPI::Pop(lua_State** state, int stackIndex)
{
    lua_pop(luaAPI::L, stackIndex);
    *state = luaAPI::L;
}

void luaAPI::PushBool(lua_State** state, bool value)
{
    lua_pushboolean(luaAPI::L, value);
    *state = luaAPI::L;
}

void luaAPI::PushFloat(lua_State** state, float value)
{
    lua_pushnumber(luaAPI::L, value);
    *state = luaAPI::L;
}

void luaAPI::PushInt(lua_State** state, int value)
{
    lua_pushnumber(luaAPI::L, value);
    *state = luaAPI::L;
}

void luaAPI::PushString(lua_State** state, const char* value)
{
    lua_pushstring(luaAPI::L, value);
    *state = luaAPI::L;
}

void luaAPI::RegisterFunction(lua_State** state, luaFunction fn_ptr, const char* name)
{
    lua_register(luaAPI::L, name, fn_ptr);
    *state = luaAPI::L;
}

void luaAPI::SetTop(lua_State** state, int stackIndex)
{
    lua_settop(luaAPI::L, stackIndex);
    *state = luaAPI::L;
}

void luaAPI::ToFloat(lua_State** state, int stackIndex, float* number)
{
    *number = (float)lua_tointeger(luaAPI::L, stackIndex);
    *state = luaAPI::L;
}

void luaAPI::ToInt(lua_State** state, int stackIndex, int* number)
{
    *number = (int)lua_tointeger(luaAPI::L, stackIndex);
    *state = luaAPI::L;
}

void luaAPI::ToString(lua_State** state, int stackIndex, char* str)
{
    std::string message = lua_tostring(luaAPI::L, stackIndex);
    memcpy(str, &message[0], message.length());
    *state = luaAPI::L;
}

int luaAPI::lua_WriteLine(lua_State* state)
{
    if(!CheckArgumentCount(luaAPI::L, 1))
        return -1;

    std::string message = lua_tostring(L, 1);

    if(luaAPI::onWriteLine != nullptr)
        luaAPI::onWriteLine(message.c_str());

    return 0;
}
