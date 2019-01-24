#ifndef LUAHANDLE_H
#define LUAHANDLE_H

/*
+------------------------------------------------------------------------+
| Important                                                              |
| The LUA UI Designer API is not documented here because                 |
| it can not be called by the C / C ++ SOURCE code.                      |
| However, the LUA UI Designer API is stored on GitHub.                  |
| https://github.com/nimile/MMI-GUI/blob/master/LUA_UI-Designer_API.md   |
+------------------------------------------------------------------------+
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
 *****************************************************************************/

#include <Qt>
#include <QDebug>
#include <QMessageBox>

#include "core/models/model.h"
#include "core/export/fileio.h"
#include "core/util/widgethelper.h"
#include "core/enums/enumerations.h"

// Include LUA C api
extern "C"{
    #include "core/lua/src/lua.h"
    #include "core/lua/src/lauxlib.h"
    #include "core/lua/src/lualib.h"
}

namespace haevn{
    namespace core{
        // This namespace contains everything about lua interaction
        namespace lua{

            /**
             * @brief This class handle the LUA interaction,
             * it also provides the LUA UI-Designer API.
             *
             * Important
             * The LUA UI Designer API is not documented here because it can not be called by the C / C ++ SOURCE code.
             * However, the LUA UI Designer API is stored on GitHub.
             * https://github.com/nimile/MMI-GUI/blob/master/LUA_UI-Designer_API.md
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 15, 2019
             */
            class LuaHandle{

                private:

                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This variable is a core element of execution lua scripts.
                     *  It will opened inside the constructor and closed inside the destructor
                     */
                    lua_State* L;


                    /**
                     * @brief This method tests if all three condidions are valid.
                     * @details This method has an internal usage,
                     * it will return if the lua_State is not a nullptr
                     * if the idx is negative the index will not be considered as valid,
                     * that mean the index and s_model are not a part of the test.
                     * Otherwise the index is also tested against the s_models scenegraphsize
                     */
                    static bool validate(lua_State* L, haevn::core::models::Model* s_model = nullptr, int idx = -1);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This variable is used to store the application model
                     */
                    static haevn::core::models::Model* s_model;

                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int print(lua_State* L);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getSceneGraphSize(lua_State* L);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int createMessageBox(lua_State* L);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getHeight(lua_State* L) ;


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getMaxHeight(lua_State* L) ;


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getMinHeight(lua_State* L) ;


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getWidth(lua_State* L) ;


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getMaxWidth(lua_State* L) ;


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getMinWidth(lua_State* L) ;


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getPositionX(lua_State* L);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getPositionY(lua_State* L);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getName(lua_State* L);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getEnabled(lua_State* L);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
                     * @details This method is documented inside the GitHub repo
                     */
                    static int getTooltip(lua_State* L);


                    /**
                     * @brief Internal usage, part of LUA UI-Designer API.
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
                      * @brief This method executes a script.
                      * @details This method will execute a lua script.
                      * The script must be specified by the file variable
                      * @param file const char* this param is the path including the script name
                      * @return result of the script
                      */
                    int runScript(const char* file);

                    /**
                     * @brief This method gets an double element from the lua stack
                     * @details This method tests if the lua stack contains an element named
                     * after "name" if therese one element it will pop this from the lua stack.
                     * @param name const char* name of the element
                     * @return double value from name
                     */
                    double getNumber(const char* name);

                    /**
                     * @brief This method gets an int element from the lua stack
                     * @details This method tests if the lua stack contains an element named
                     * after "name" if therese one element it will pop this from the lua stack.
                     * @param name const char* name of the element
                     * @return int value from name
                     */
                    int getInt(const char* name);

                    /**
                     * @brief This method gets an string element from the lua stack
                     * @details This method tests if the lua stack contains an element named
                     * after "name" if therese one element it will pop this from the lua stack.
                     * @param name const char* name of the element
                     * @return const char* value from name
                     */
                    const char* getString(const char* name);

                    /**
                     * @brief This method gets an bool element from the lua stack
                     * @details This method tests if the lua stack contains an element named
                     * after "name" if therese one element it will pop this from the lua stack.
                     * @param name const char* name of the element
                     * @return bool value from name
                     */
                    bool getBool(const char* name);

                    // !TODO
                    /**
                     * @brief This method will be implemented in a future release
                     */
                    void setConfig(const char* name, const char* value);

                    /**
                     * @brief This method gets the last error message.
                     * @details This method will return the last error message.
                     * @return const char* Error text
                     */
                    const char* getError();
            };
        }
    }
}

#endif // LUAHANDLE_H
