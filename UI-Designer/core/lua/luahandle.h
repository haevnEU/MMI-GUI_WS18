#ifndef LUAHANDLE_H
#define LUAHANDLE_H

#include <Qt>
#include "core/models/model.h"

extern "C"{

    #include "core/lua/src/lua.h"
    #include "core/lua/src/lauxlib.h"
    #include "core/lua/src/lualib.h"
}

namespace haevn{
    namespace core{
        namespace lua{
            class LuaHandle{

                // public static methods
                public:
                    static LuaHandle* getInstance();

                private:

                    static int print(lua_State* L);

                    static int getSceneGraphSize(lua_State* L);

                    static int createMessageBox(lua_State* L);

                    static int getHeight(lua_State* L) ;

                    static int getMaxHeight(lua_State* L) ;

                    static int getMinHeight(lua_State* L) ;

                    static int getWidth(lua_State* L) ;

                    static int getMaxWidth(lua_State* L) ;

                    static int getMinWidth(lua_State* L) ;

                    static int getPositionX(lua_State* L);

                    static int getPositionY(lua_State* L);

                    static int getName(lua_State* L);

                    static int getEnabled(lua_State* L);

                    static int getTooltip(lua_State* L);
                // static variables
                private:
                    static LuaHandle* s_instance;

                // public methods
                public:

                    ~LuaHandle();
                    void runScript(const char* file, haevn::core::models::Model* model);

                private:

                    void closeScript(lua_State* L);
                    void open(lua_State* L);
                // private methods
                private:
                    bool isOpen;
                    ///
                    explicit LuaHandle();
                    // Either Copy ctor nor assign operate are required
                    explicit LuaHandle(LuaHandle& another){}
                    LuaHandle& operator=(const LuaHandle& another){}

            };
        }
    }
}

#endif // LUAHANDLE_H
