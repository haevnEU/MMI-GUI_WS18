#include "luahandle.h"

haevn::core::models::Model* haevn::core::lua::LuaHandle::s_model = nullptr;

haevn::core::lua::LuaHandle::LuaHandle(haevn::core::models::Model* t_model){
    s_model = t_model;
    L = luaL_newstate();
    luaL_openlibs(L);

    // The following functions will be available inside any LUA script
    // documentation inside readme.md or GitHub repo
    lua_register(L, "Print", print);
    lua_register(L, "GetSceneGraphSize", getSceneGraphSize);
    lua_register(L, "GetType", getType);
    lua_register(L, "GetHeight", getHeight);
    lua_register(L, "GetMaxHeight", getMaxHeight);
    lua_register(L, "GetMinHeight", getMinHeight);
    lua_register(L, "GetWidth", getWidth);
    lua_register(L, "GetMaxWidth", getMaxWidth);
    lua_register(L, "GetMinWidth", getMinWidth);
    lua_register(L, "GetPositionX", getPositionX);
    lua_register(L, "GetPositionY", getPositionY);
    lua_register(L, "GetName", getName);
    lua_register(L, "GetEnabled", getEnabled);
    lua_register(L, "GetTooltip", getTooltip);
    lua_register(L, "DisplayMessageBox", createMessageBox);

}

haevn::core::lua::LuaHandle::~LuaHandle(){
    lua_close(L);
}

int haevn::core::lua::LuaHandle::runScript(const char* file){

    int result = luaL_loadfile(L, file);
    // if there no error execute the script
    if(!result){
        result = lua_pcall(L, 0, LUA_MULTRET, 0);
    }
    return result;
}

double haevn::core::lua::LuaHandle::getNumber(const char* name){
    lua_getglobal(L, name);
    return lua_isnumber(L, -1) ? lua_tonumber(L, -1) : 0;
}

int haevn::core::lua::LuaHandle::getInt(const char* name){
    lua_getglobal(L, name);
    return lua_isinteger(L, -1) ? lua_tointeger(L, -1) : 0;
}

const char* haevn::core::lua::LuaHandle::getString(const char* name){
    lua_getglobal(L, name);
    return lua_isstring(L, -1) ? lua_tostring(L, -1) : nullptr;
}

bool haevn::core::lua::LuaHandle::getBool(const char* name){
    lua_getglobal(L, name);
    return lua_isboolean(L, -1) ? lua_toboolean(L, -1) : false;
}

const char* haevn::core::lua::LuaHandle::getError(){
    if(nullptr != L && lua_isstring(L, -1)){
        return lua_tostring(L, -1);
    } else {
        return "Unknown problem.";
    }
}




/*
 *
 +--------------------------------------------------+
 | Now follows the LUA UI-Designer API              |
 | For more information look inside the GitHub repo |
 +--------------------------------------------------+
 *
 */

int haevn::core::lua::LuaHandle::createMessageBox(lua_State* L){
    if(L == nullptr){
        return 0;
    }

    // Creates a messagebox
    QMessageBox *msgBox = new QMessageBox();
    // Get the text from the lua stack
    if(lua_isstring(L, -3)){
        // set the text from the messagebox
        msgBox->setText(lua_tostring(L, -3));
    }

    // Get the informative text from the lua stack
    if(lua_isstring(L, -2)){
        // set the informative text
        msgBox->setInformativeText(lua_tostring(L, -2));
    }

    // Get the buttons from the lua stack
    if(lua_isinteger(L, -1)){
        int input = lua_tointeger(L, -1);
        // Switch between different buttons
        switch(input){
            // Only Yes and No
            case 1:
                msgBox->setStandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);
                break;

            // Yes, No and Cancel
            case 2:
                msgBox->setStandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No | QMessageBox::StandardButton::Cancel);
                break;

            // Yes, No, Cancel, Close
            case 3:
                msgBox->setStandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No | QMessageBox::StandardButton::Cancel | QMessageBox::StandardButton::Close);
                break;
            // Default, if the buttons are not supported or the script commands it these buttons are used
            default:
                msgBox->setStandardButtons(QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Cancel);
        }
    }

    // Show the messagebox
    int ret = msgBox->exec();
    // Push the result to the lua stack, the script can retreive the information
    lua_pushinteger(L, ret);
    return 1;
}

// Print different variable types from the lua stack, supported are stirng, number and bool
int haevn::core::lua::LuaHandle::print(lua_State* L){
    if(lua_isstring(L,-1)){
        const char* param = lua_tostring(L, -1);
        qDebug() << param;
    }else if(lua_isnumber(L, -1)){
        double param = lua_tonumber(L, -1);
        qDebug() << param;
    }else if(lua_isboolean(L, -1)){
        bool param = lua_toboolean(L, -1);
        qDebug() << param;
    }
    return 0;
}

// Validates the parameter
// Iff s_model == nullptr and idx < 0 the function will only evaluate lua_State*
bool haevn::core::lua::LuaHandle::validate(lua_State* L, haevn::core::models::Model* s_model, int idx){

    // First test if the lua state exist
    if(nullptr == L){
        // If not return false
        return false;
    }
    // Next test if the model is a nullptr
    if(s_model == nullptr){
        // If so return false
        return false;
    }
    // Finally test if the idx is to big
    if(idx >= s_model->getScenegraph()->size()){
        // if so return false
        return false;
    }
    return true;
}

/*
 *
 +------------------------------------------------------------+
 | IMPORTANT NOTE                                             |
 |                                                            |
 | Most of the following functions have the same blueprint,   |
 | so ill avoid unnecessary work.                             |
 | Each function does the thin which it is named after.       |
 |                                                            |
 | There a couple of test before the function can be executed |
 | 1. Is theres a lua_state                                   |
 | 2. Is the model valid (not a nullptr)                      |
 | 3. Is the index valid (not less or greater than            |
 |      the size of the scenegraph)                           |
 | If any of the 3 condition is false the function will       |
 |      immediately return 0,                                 |
 |          => 0 <=> return nothing in lua                    |
 | If all of the 3 condition are true                         |
 | the corresponding functionality is executed                |
 +------------------------------------------------------------+
 *
 */

int haevn::core::lua::LuaHandle::getSceneGraphSize(lua_State *L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }
    int value = s_model->getScenegraph()->size();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getType(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }

    QWidget* item = s_model->getScenegraph()->at(idx);
    haevn::core::util::WidgetHelper helper;
    int type = helper.getType(item);
    lua_pushinteger(L, type);
    return 1;
}

int haevn::core::lua::LuaHandle::getHeight(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->height();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getMaxHeight(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->maximumHeight();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getMinHeight(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    QWidget* tmp = s_model->getScenegraph()->at(idx);
    int value = s_model->getScenegraph()->at(idx)->minimumHeight();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getWidth(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->width();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getMaxWidth(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->maximumWidth();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getMinWidth(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->minimumWidth();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getPositionX(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->pos().x();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getPositionY(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->pos().y();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getName(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    const char* value = s_model->getScenegraph()->at(idx)->whatsThis().toStdString().data();
    lua_pushstring(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getEnabled(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    bool value = s_model->getScenegraph()->at(idx)->isEnabled();
    lua_pushboolean(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getTooltip(lua_State* L){
    int idx = lua_tointeger(L, -1);
    if(!validate(L, s_model, idx)){
        return 0;
    }
    const char* value = s_model->getScenegraph()->at(idx)->toolTip().toStdString().data();
    lua_pushstring(L, value);
    return 1;
}
