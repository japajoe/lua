#include "luaAPI.h"

extern "C" void luaAPI_Call(lua_State* state, int numArgs, int numReturnValues)
{
    lua_call(state, numArgs, numReturnValues);    
}

extern "C" bool luaAPI_Close(lua_State* state)
{
    if(state != nullptr)
    {
        lua_close(state);
        return true;
    }
    return false;
}

extern "C" int luaAPI_DoFile(lua_State* state, const char* filepath)
{
    return luaL_dofile(state, filepath);    
}

extern "C" int luaAPI_DoString(lua_State* state, const char* code)
{
    return luaL_dostring(state, code);    
}

extern "C" void luaAPI_FreeCharPointer(char* ptr)
{
    delete[] ptr;
}

extern "C" int luaAPI_GetArgumentCount(lua_State* state)
{
    return lua_gettop(state);    
}

extern "C" void luaAPI_GetGlobal(lua_State* state, const char* name)
{
    lua_getglobal(state, name);    
}

extern "C" void luaAPI_GetTable(lua_State* state, int stackIndex)
{
    lua_gettable(state, stackIndex);    
}

extern "C" int luaAPI_GetTop(lua_State* state)
{
    return lua_gettop(state);    
}

extern "C" bool luaAPI_IsFunction(lua_State* state, int stackIndex)
{
    if(lua_isfunction(state, stackIndex))
    {        
        return true;
    }
    
    return false;
}

extern "C" bool luaAPI_IsNumber(lua_State* state, int stackIndex)
{
    if(lua_isnumber(state, stackIndex))
    {        
        return true;
    }
    
    return false;
}

extern "C" bool luaAPI_IsString(lua_State* state, int stackIndex)
{
    if(lua_isstring(state, stackIndex))
    {        
        return true;
    }
    
    return false;
}

extern "C" bool luaAPI_IsTable(lua_State* state, int stackIndex)
{
    if(lua_istable(state, stackIndex))
    {        
        return true;
    }
    
    return false;
}

extern "C" lua_State* luaAPI_NewState()
{
    return luaL_newstate();
}

extern "C" void luaAPI_OpenLibs(lua_State* state)
{
    luaL_openlibs(state);
}

extern "C" int luaAPI_PCall(lua_State* state, int numArgs, int numReturnValues, int errorHandlingType)
{    
    return lua_pcall(state, numArgs, numReturnValues, errorHandlingType);    
}

extern "C" void luaAPI_Pop(lua_State* state, int stackIndex)
{
    lua_pop(state, stackIndex);    
}

extern "C" void luaAPI_PushBool(lua_State* state, bool value)
{
    lua_pushboolean(state, value);    
}

extern "C" void luaAPI_PushFloat(lua_State* state, float value)
{
    lua_pushnumber(state, value);    
}

extern "C" void luaAPI_PushInt(lua_State* state, int value)
{
    lua_pushnumber(state, value);    
}

extern "C" void luaAPI_PushString(lua_State* state, const char* value)
{
    lua_pushstring(state, value);    
}

extern "C" void luaAPI_Register_Function(lua_State* state, luaFunction fn_ptr, const char* name)
{
    lua_register(state, name, fn_ptr);    
}

extern "C" void luaAPI_SetTop(lua_State* state, int stackIndex)
{
    lua_settop(state, stackIndex);    
}

extern "C" void luaAPI_ToFloat(lua_State* state, int stackIndex, float* number)
{
    *number = (float)lua_tointeger(state, stackIndex);    
}

extern "C" void luaAPI_ToInt(lua_State* state, int stackIndex, int* number)
{
    *number = (int)lua_tointeger(state, stackIndex);    
}

extern "C" char* luaAPI_ToString(lua_State* state, int stackIndex)
{
    std::string message = lua_tostring(state, stackIndex);
    char* str = new char[message.size()+1];
    memcpy(str, &message[0], message.size());
    str[message.size()] = '\0';
    return str;
}