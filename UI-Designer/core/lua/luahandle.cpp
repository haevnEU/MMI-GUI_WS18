#include "luahandle.h"

#include <QDebug>


haevn::core::models::Model* haevn::core::lua::LuaHandle::s_model = nullptr;

haevn::core::lua::LuaHandle::LuaHandle(haevn::core::models::Model* t_model){
    isOpen = false;
    s_model = t_model;
    L = luaL_newstate();
    luaL_openlibs(L);
    // export lua api
    // @see readme.md
    lua_register(L, "Print", print);
    lua_register(L, "GetSceneGraphSize", getSceneGraphSize);
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

void haevn::core::lua::LuaHandle::runScript(const char* file){

    int result = luaL_loadfile(L, file);
    if(!result){
        result = lua_pcall(L, 0, LUA_MULTRET, 0);
    }
    if(result){
        qDebug() << "Result " << result;
        // TODO Handle lua error
        qDebug() << "Error occured parsing lua";
    }
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







// API which lua could call

int haevn::core::lua::LuaHandle::createMessageBox(lua_State* L){
    if(L == nullptr){
        return 0;
    }

    QMessageBox *msgBox = new QMessageBox();
    if(lua_isstring(L, -3)){
        msgBox->setText(lua_tostring(L, -3));
    }
    if(lua_isstring(L, -2)){
        msgBox->setInformativeText(lua_tostring(L, -2));
    }
    if(lua_isinteger(L, -1)){
        int input = lua_tointeger(L, -1);
        switch(input){
            case 1:
                msgBox->setStandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);
                break;
            case 2:
                msgBox->setStandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No | QMessageBox::StandardButton::Cancel);

                break;
            case 3:
                msgBox->setStandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No | QMessageBox::StandardButton::Cancel | QMessageBox::StandardButton::Close);
                break;
            default:
                msgBox->setStandardButtons(QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Cancel);
        }
    }

    int ret = msgBox->exec();
    lua_pushinteger(L, ret);
    return 1;
}

int haevn::core::lua::LuaHandle::print(lua_State* L){
    if(lua_isstring(L,-1)){
        const char* param = lua_tostring(L, -1);
        qDebug() << param;
    }else if(lua_isnumber(L, -1)){
        double param = lua_tonumber(L, -1);
        qDebug() << param;
    }else if(lua_isboolean(L, -1)){
        double param = lua_toboolean(L, -1);
        qDebug() << param;
    }

}

int haevn::core::lua::LuaHandle::getSceneGraphSize(lua_State *L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }
    int value = s_model->getScenegraph()->size();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getHeight(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->height();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getMaxHeight(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->maximumHeight();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getMinHeight(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->minimumHeight();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getWidth(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->width();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getMaxWidth(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->maximumWidth();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getMinWidth(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->minimumWidth();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getPositionX(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->pos().x();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getPositionY(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->at(idx)->pos().y();
    lua_pushinteger(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getName(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    const char* value = s_model->getScenegraph()->at(idx)->whatsThis().toStdString().data();
    lua_pushstring(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getEnabled(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    bool value = s_model->getScenegraph()->at(idx)->isEnabled();
    lua_pushboolean(L, value);
    return 1;
}

int haevn::core::lua::LuaHandle::getTooltip(lua_State* L){
    if(nullptr == L || nullptr == s_model){
        return 0;
    }

    int idx = lua_tointeger(L, -1);
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    const char* value = s_model->getScenegraph()->at(idx)->toolTip().toStdString().data();
    lua_pushstring(L, value);
    return 1;
}
