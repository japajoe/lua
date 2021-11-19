#include "luaProxy.h"
#include <iostream>

extern "C" bool luaAPI_Dispose(lua_State_Ptr state)
{
    return luaAPI::Dispose((lua_State**)state);
}

extern "C" int luaAPI_DoFile(lua_State_Ptr state, const char* filepath)
{
    int result = luaAPI::DoFile((lua_State**)state, filepath);
    return result;
}

extern "C" int luaAPI_DoString(lua_State_Ptr state, const char* code)
{
    int result = luaAPI::DoString((lua_State**)state, code);
    return result;
}

extern "C" int luaAPI_GetArgumentCount(lua_State_Ptr state)
{
    return luaAPI::GetArgumentCount((lua_State**)state);
}

extern "C" void luaAPI_GetGlobal(lua_State_Ptr state, const char* name)
{
    luaAPI::GetGlobal((lua_State**)state, name);
}

extern "C" void luaAPI_GetTable(lua_State_Ptr state, int stackIndex)
{
    luaAPI::GetTable((lua_State**)state, stackIndex);
}

extern "C" int luaAPI_GetTop(lua_State_Ptr state)
{
    int result = luaAPI::GetTop((lua_State**)state);
    return result;    
}

extern "C" bool luaAPI_Initialize(lua_State_Ptr state)
{
    bool result = luaAPI::Initialize((lua_State**)state);
    return result;
}

extern "C" bool luaAPI_IsFunction(lua_State_Ptr state, int stackIndex)
{
    bool result = luaAPI::IsFunction((lua_State**)state, stackIndex);
    return result;
}

extern "C" bool luaAPI_IsNumber(lua_State_Ptr state, int stackIndex)
{
    bool result = luaAPI::IsNumber((lua_State**)state, stackIndex);
    return result;
}

extern "C" bool luaAPI_IsString(lua_State_Ptr state, int stackIndex)
{
    bool result = luaAPI::IsString((lua_State**)state, stackIndex);
    return result;
}

extern "C" bool luaAPI_IsTable(lua_State_Ptr state, int stackIndex)
{
    bool result = luaAPI::IsTable((lua_State**)state, stackIndex);
    return result;
}

extern "C" int luaAPI_PCall(lua_State_Ptr state, int numArgs, int numReturnValues, int errorHandlingType)
{
    int result = luaAPI::PCall((lua_State**)state, numArgs, numReturnValues, errorHandlingType);
    return result;
}

extern "C" void luaAPI_Pop(lua_State_Ptr state, int stackIndex)
{
    luaAPI::Pop((lua_State**)state, stackIndex);
}

extern "C" void luaAPI_PushBool(lua_State_Ptr state, bool value)
{
    luaAPI::PushBool((lua_State**)state, value);
}

extern "C" void luaAPI_PushFloat(lua_State_Ptr state, float value)
{
    luaAPI::PushFloat((lua_State**)state, value);
}

extern "C" void luaAPI_PushInt(lua_State_Ptr state, int value)
{
    luaAPI::PushInt((lua_State**)state, value);
}

extern "C" void luaAPI_PushString(lua_State_Ptr state, const char* value)
{
    luaAPI::PushString((lua_State**)state, value);
}

extern "C" void luaAPI_Register_Error_Callback(luaErrorCallback callback)
{
    luaAPI::onError = callback;
}

extern "C" void luaAPI_Register_Function(lua_State_Ptr state, luaFunction fn_ptr, const char* name)
{
    luaAPI::RegisterFunction((lua_State**)state, fn_ptr, name);
}

extern "C" void luaAPI_Register_WriteLine_Callback(luaWriteLineCallback callback)
{
    luaAPI::onWriteLine = callback;
}

extern "C" void luaAPI_SetTop(lua_State_Ptr state, int stackIndex)
{
    luaAPI::SetTop((lua_State**)state, stackIndex);
}

extern "C" void luaAPI_ToFloat(lua_State_Ptr state, int stackIndex, float* number)
{
    luaAPI::ToFloat((lua_State**)state, stackIndex, number);
}

extern "C" void luaAPI_ToInt(lua_State_Ptr state, int stackIndex, int* number)
{
    luaAPI::ToInt((lua_State**)state, stackIndex, number);
}

extern "C" void luaAPI_ToString(lua_State_Ptr state, int stackIndex, char* str)
{
    luaAPI::ToString((lua_State**)state, stackIndex, str);
}
