#ifndef LUAPROXY_H
#define LUAPROXY_H

#include "luaAPI.h"

typedef void* lua_State_Ptr;

extern "C"
{
    extern bool luaAPI_Dispose(lua_State_Ptr state);    
    extern int luaAPI_DoFile(lua_State_Ptr state, const char* filepath);
    extern int luaAPI_DoString(lua_State_Ptr state, const char* code);    
    extern int luaAPI_GetArgumentCount(lua_State_Ptr state);
    extern void luaAPI_GetGlobal(lua_State_Ptr state, const char* name);
    extern int luaAPI_GetTop(lua_State_Ptr state);
    extern bool luaAPI_Initialize(lua_State_Ptr state);    
    extern bool luaAPI_IsNumber(lua_State_Ptr state, int stackIndex);
    extern bool luaAPI_IsString(lua_State_Ptr state, int stackIndex);
    extern bool luaAPI_IsTable(lua_State_Ptr state, int stackIndex);
    extern void luaAPI_Register_Error_Callback(luaErrorCallback callback);
    extern void luaAPI_Register_Function(lua_State_Ptr state, luaFunction fn_ptr, const char* name);
    extern void luaAPI_Register_WriteLine_Callback(luaWriteLineCallback callback);   
    extern void luaAPI_Pop(lua_State_Ptr state, int stackIndex);
    extern void luaAPI_PushBool(lua_State_Ptr state, bool value);
    extern void luaAPI_PushFloat(lua_State_Ptr state, float value);
    extern void luaAPI_PushInt(lua_State_Ptr state, int value);
    extern void luaAPI_PushString(lua_State_Ptr state, const char* value);    
    extern void luaAPI_SetTop(lua_State_Ptr state, int stackIndex);
    extern void luaAPI_ToFloat(lua_State_Ptr state, int stackIndex, float* number);
    extern void luaAPI_ToInt(lua_State_Ptr state, int stackIndex, int* number);
    extern void luaAPI_ToString(lua_State_Ptr state, int stackIndex, char* str);    
}

#endif
