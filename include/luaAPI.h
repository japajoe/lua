#ifndef LUAAPI_H
#define LUAAPI_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <string>
#include <iostream>
#include <cstring>
#include <cstdint>

typedef int (*luaFunction)(lua_State* state);

extern "C"
{
    extern void luaAPI_Call(lua_State* state, int numArgs, int numReturnValues);
    extern bool luaAPI_Close(lua_State* state);
    extern int  luaAPI_DoFile(lua_State* state, const char* filepath);
    extern int  luaAPI_DoString(lua_State* state, const char* code);
    extern void luaAPI_FreeCharPointer(char* ptr);
    extern int  luaAPI_GetArgumentCount(lua_State* state);
    extern void luaAPI_GetGlobal(lua_State* state, const char* name);
    extern void luaAPI_GetTable(lua_State* state, int stackIndex);
    extern int  luaAPI_GetTop(lua_State* state);
    extern bool luaAPI_Initialize(lua_State* state);
    extern bool luaAPI_IsFunction(lua_State* state, int stackIndex);
    extern bool luaAPI_IsNumber(lua_State* state, int stackIndex);
    extern bool luaAPI_IsString(lua_State* state, int stackIndex);
    extern bool luaAPI_IsTable(lua_State* state, int stackIndex);
    extern bool luaAPI_IsUserData(lua_State* state, int stackIndex);
    extern lua_State* luaAPI_NewState();
    extern void luaAPI_OpenLibs(lua_State* state);
    extern int  luaAPI_PCall(lua_State* state, int numArgs, int numReturnValues, int errorHandlingType);
    extern void luaAPI_Pop(lua_State* state, int stackIndex);
    extern void luaAPI_PushBool(lua_State* state, bool value);
    extern void luaAPI_PushFloat(lua_State* state, float value);
    extern void luaAPI_PushInt(lua_State* state, int value);
    extern void luaAPI_PushLightUserData(lua_State* state, void* userData);
    extern void luaAPI_PushString(lua_State* state, const char* value);
    extern void luaAPI_Register_Function(lua_State* state, luaFunction fn_ptr, const char* name);
    extern void luaAPI_SetTop(lua_State* state, int stackIndex);
    extern void luaAPI_ToFloat(lua_State* state, int stackIndex, float* number);
    extern void luaAPI_ToInt(lua_State* state, int stackIndex, int* number);
    extern char* luaAPI_ToString(lua_State* state, int stackIndex);
    extern void* luaAPI_ToUserData(lua_State* state, int stackIndex);
}

#endif
