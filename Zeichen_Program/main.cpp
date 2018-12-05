#include <iostream>


#include "app/app.h"
#include "app/color.h"
#include "app/tool.h"
#include "geometry/forms/basicShape.h"
#include "geometry/forms/rectangle.h"

int main()
{
    app::App* app = new app::App;
    app->state()->selectHeight(50.0);
    app->state()->selectWidth(50.0);
    app->state()->selectPosition(10,10);
    // adding a  geometry::forms::Circle C
    app->state()->selectTool(app::Tool::CIRCLE);
    app->onCanvasClicked();


    app->state()->selectHeight(25.0);
    app->state()->selectWidth(30.0);
    app->state()->selectPosition(90,90);
    // adding a Square
    app->state()->selectTool(app::Tool::SQUARE);
    app->onCanvasClicked();
    // delete the app
    delete app;
    return 0;
}
