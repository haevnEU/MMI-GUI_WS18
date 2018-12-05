#include <iostream>


#include "app/app.h"
#include "app/color.h"
#include "app/tool.h"
#include "geometry/forms/basicShape.h"
#include "geometry/forms/rectangle.h"

int main(){
    app::App* app = new app::App;
    // adding a Circle
    app->state()->selectTool(app::Tool::CIRCLE);
    app->onCanvasClicked();

    // adding a Square
    app->state()->selectTool(app::Tool::SQUARE);
    app->onCanvasClicked();
    // delete the app
    delete app;
    return 0;
}
