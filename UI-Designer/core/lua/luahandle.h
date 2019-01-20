#ifndef LUAHANDLE_H
#define LUAHANDLE_H

#include <Qt>
#include <QMessageBox>
#include "core/models/model.h"
#include "core/export/fileio.h"

extern "C"{

    #include "core/lua/src/lua.h"
    #include "core/lua/src/lauxlib.h"
    #include "core/lua/src/lualib.h"
}

namespace haevn{
    namespace core{
        // This namespace contains everything about lua interaction
        namespace lua{
            class LuaHandle{

                private:

                    lua_State* L;

                    static haevn::core::models::Model* s_model;

                    static int print(lua_State* L);

                    static int getSceneGraphSize(lua_State* L);

                    static int createMessageBox(lua_State* L);

                    static int exportData(lua_State* L);

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

                    static int getType(lua_State* L);

                // public methods
                public:

                    /**
                     * @brief LuaHandle
                     */
                    explicit LuaHandle(haevn::core::models::Model* t_model = nullptr);


                    ~LuaHandle();
                    /**
                     * @brief runScript
                     * @param file
                     * @param model
                     */
                    int runScript(const char* file);

                    double getNumber(const char* name);
                    int getInt(const char* name);
                    const char* getString(const char* name);
                    bool getBool(const char* name);
                // private methods
                private:


                    /**
                     * @brief LuaHandle
                     * @param another
                     */
                    explicit LuaHandle(LuaHandle& another){}

                    /**
                     * @brief operator =
                     * @param another
                     * @return
                     */
                    LuaHandle& operator=(const LuaHandle& another){}

                // private methods
                private:
                    bool isOpen;

            };
        }
    }
}

#endif // LUAHANDLE_H
