#ifndef LUAHANDLE_H
#define LUAHANDLE_H

/*
 * Important note, the LUA UI-Designer API is documented inside the
 * GitHub repo.
 * https://github.com/nimile/MMI-GUI/blob/master/LUA_UI-Designer_API.md
 */

/******************************************************************************
* Copyright (C) 1994-2018 Lua.org, PUC-Rio.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

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

                    /// Internal usage
                    lua_State* L;

                    /// Internal usage
                    static haevn::core::models::Model* s_model;

                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int print(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getSceneGraphSize(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int createMessageBox(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int exportData(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getHeight(lua_State* L) ;


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getMaxHeight(lua_State* L) ;


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getMinHeight(lua_State* L) ;


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getWidth(lua_State* L) ;


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getMaxWidth(lua_State* L) ;


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getMinWidth(lua_State* L) ;


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getPositionX(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getPositionY(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getName(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getEnabled(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getTooltip(lua_State* L);


                    /**
                     * @brief Internal usage, par of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
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

                    void setConfig(const char* name, const char* value);

                    const char* getError();
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
