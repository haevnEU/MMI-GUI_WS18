#include "luahandle.h"

#include <QDebug>

static haevn::core::models::Model* s_model = nullptr;
haevn::core::lua::LuaHandle* haevn::core::lua::LuaHandle::s_instance = nullptr;
haevn::core::lua::LuaHandle* haevn::core::lua::LuaHandle::getInstance(){
    if(s_instance == nullptr){
        s_instance = new LuaHandle();
    }
    return s_instance;
}


haevn::core::lua::LuaHandle::LuaHandle(){
    isOpen = false;
}

haevn::core::lua::LuaHandle::~LuaHandle(){

}

void haevn::core::lua::LuaHandle::open(lua_State* L){
    if(isOpen){
        return;
    }
    luaL_openlibs(L);

    lua_register(L, "PRINT", print);
    lua_register(L, "SIZE", getSceneGraphSize);
    lua_register(L, "HEIGHT", getHeight);
    lua_register(L, "MAX_HEIGHT", getMaxHeight);
    lua_register(L, "MIN_HEIGHT", getMinHeight);
    lua_register(L, "WIDTH", getWidth);
    lua_register(L, "MAX_WIDTH", getMaxWidth);
    lua_register(L, "MIN_WIDTH", getMinWidth);
    lua_register(L, "POSITION_X", getPositionX);
    lua_register(L, "POSITION_Y", getPositionY);
    lua_register(L, "NAME", getName);
    lua_register(L, "ENABLED", getEnabled);
    lua_register(L, "TOOLTIP", getTooltip);
    lua_register(L, "MESSAGE_BOX", createMessageBox);
    isOpen = true;
}

void haevn::core::lua::LuaHandle::closeScript(lua_State* L){
    lua_close(L);
    isOpen = false;
}

void haevn::core::lua::LuaHandle::runScript(const char* file, haevn::core::models::Model* model){

    lua_State* L = luaL_newstate();
    open(L);
    s_model = model;
    int result = luaL_loadfile(L, file);
    if(!result){
        result = lua_pcall(L, 0, LUA_MULTRET, 0);
    }
    if(result){
        // TODO Handle lua error
    }
    closeScript(L);
}

int haevn::core::lua::LuaHandle::createMessageBox(lua_State* L){
    if(L == nullptr){
        return 0;
    }
}

int haevn::core::lua::LuaHandle::print(lua_State* L){
    if(lua_isstring(L,-1)){
        const char* param = lua_tostring(L, -1);
        qDebug() << param;
    }else if(lua_isnumber(L, -1)){
        int param = lua_tonumber(L, -1);
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
    qDebug() << "idx " << idx;
    int value = s_model->getScenegraph()->takeAt(idx)->height();
    qDebug() << "value " << value;
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
    if(idx >= s_model->getScenegraph()->size()){
        return 0;
    }
    int value = s_model->getScenegraph()->takeAt(idx)->maximumHeight();
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
    int value = s_model->getScenegraph()->takeAt(idx)->minimumHeight();
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
    int value = s_model->getScenegraph()->takeAt(idx)->width();
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
    int value = s_model->getScenegraph()->takeAt(idx)->maximumWidth();
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
    int value = s_model->getScenegraph()->takeAt(idx)->minimumWidth();
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
    int value = s_model->getScenegraph()->takeAt(idx)->pos().x();
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
    int value = s_model->getScenegraph()->takeAt(idx)->pos().y();
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
    return 1;
}

int haevn::core::lua::LuaHandle::getEnabled(lua_State* L){

    return 0;
}

int haevn::core::lua::LuaHandle::getTooltip(lua_State* L){

    return 0;
}
