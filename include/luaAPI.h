#ifndef LUAAPI_H
#define LUAAPI_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <string>

typedef int (*luaFunction)(lua_State* state);
typedef void (*luaErrorCallback)(const char* message);
typedef void (*luaWriteLineCallback)(const char* message);

class luaAPI
{
private:
    static lua_State* L;
    static std::string CreateModules();
    static bool CheckArgumentCount(lua_State* state, int numArguments);
    //Built in functions    
    static int lua_WriteLine(lua_State* state);
public:
    static bool Dispose(lua_State** state);
    static int DoFile(lua_State** state, const char* filepath);
    static int DoString(lua_State** state, const char* code);    
    static int GetArgumentCount(lua_State** state);
    static void GetGlobal(lua_State** state, const char* name);
    static int GetTop(lua_State** state);
    static bool Initialize(lua_State** state);
    static bool IsNumber(lua_State** state, int stackIndex);
    static bool IsString(lua_State** state, int stackIndex);
    static void Pop(lua_State** state, int stackIndex);
    static void PushBool(lua_State** state, bool value);
    static void PushFloat(lua_State** state, float value);
    static void PushInt(lua_State** state, int value);
    static void PushString(lua_State** state, const char* value);    
    static void RegisterFunction(lua_State** state, luaFunction fn_ptr, const char* name); 
    static void SetTop(lua_State** state, int stackIndex);
    static void ToFloat(lua_State** state, int stackIndex, float* number);
    static void ToInt(lua_State** state, int stackIndex, int* number);
    static void ToString(lua_State** state, int stackIndex, char* str);
    static luaErrorCallback onError;
    static luaWriteLineCallback onWriteLine;
};

#endif
