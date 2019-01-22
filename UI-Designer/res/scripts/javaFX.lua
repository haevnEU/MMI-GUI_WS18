--[[
    +---------------------------------------------------------------------------------------------------------------+
    |                                                   README                                                      |
    +---------------------------------------------------------------------------------------------------------------+
    | Step 1: Modify the function                                                                                   |
    | Step 2: Modify in line731 the languageName variable                                                           |
    | Step 3: Modify the for loop from line 52                                                                      |
    | Step 4: Post you script into github iff the language didnt exist                                              |
    | Step 5: Include following credit                                                                              |
    |                                                                                                               |
    +---------------------------------------------------------------------------------------------------------------+
    | Basefile was created by Nils Milewski (haevn) Jan 14 2019,                                                    |
    | the basefile includes all required functions and variables to create a new export script                      |
    | The basefile is/was only a blueprint without language specific content,                                       |
    | The credit for implementing the logic goes to                                                                 |
    | <your name and date>                                                                                          |
    | <your name and date iff youre a contributor of the implemented file>                                          |
    | If the implemented file is used as a blueprint again,                                                         |
    | the new contributor have the same rules as the last one but have to include the last one                      |
    |                                                                                                               |
    +---------------------------------------------------------------------------------------------------------------+
    | The term contributor refers to someone who added his own content to this file                                 |
    |                                                                                                               |
    +---------------------------------------------------------------------------------------------------------------+
    | You can modify the marked places to create your own export file,                                              |
    | if you modify the build process share it inside the repo                                                      |
    | if you create a new language export script post it inside the repo                                            |
    | The name of the new script shall be the same as specified by 'languageName' in line 52,                       |
    | with a .lua extension (eg. javaFX.lua, qt.lua, cs.lua, ...)                                                   |
    |                                                                                                               |
    +---------------------------------------------------------------------------------------------------------------+
    | Longversion                                                                                                   |
    | This file is a blueprint you have to create and implement all of the following functions.                     |
    | Every function is used as an appliance rule for the build process.                                            |
    | At the bottom you have to iterate of the scenegraph using a iterative for loop.                               |
    | Inside this for loop you have to request every variable you need.                                             |
    | After youve created your object add it to a string.                                                           |
    | Finally you have to call c method Export with a string which represent your file.                             |
    | You are explicit allowed to modify this process but you have to share it inside the repo.                     |
    | You are also allowed to create your own language export script but post it inside the repo                    | 
    |                                                                                                               |
    | The name of the new script shall be the same as specified by 'languageName' in line 52,                       |
    | with a .lua extension (eg. javaFX.lua, qt.lua, cs.lua, ...)                                                   | 
    |                                                                                                               |
    | Jan 14 2019 by Nils Milewski (haevn)                                                                          |
    |                                                                                                               |
    +---------------------------------------------------------------------------------------------------------------+
 ]]
 
--[[
    +---------------------------------------------------------------------------------------------+
    | This file exports the scenegraph into a JavaFX source code.                                 |
    | This script has been tested and is readable, changing it can lead to a faulty execution.    |
    | For this reason, the modification is prohibited.                                            |
    | If there are any suggested changes please share them.                                       |   
    +---------------------------------------------------------------------------------------------+
]]
 
function createButton(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new Button\n"
    ret = ret .. "Button " .. name .. " = new Button();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end

function createRadioButton(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
        ret = "// Create a new radioutton\n"
        ret = ret .. "RadioButton " .. name .. " = new RadioButton();\n"
        ret = ret .. name ..".setLayoutX("..posX..");\n"
        ret = ret .. name .. ".setLayoutY(".. posY..");\n"
        ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
        ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
        ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
        ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
        ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
        ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
        -- JavaFX convention, you can not set visibile state just disable state
        -- => If visibile == true we must set disable to false
        if true == visibility then
            ret = ret .. name .. ".setDisable(false);\n"
        else    
            ret = ret .. name .. ".setDisable(true);\n"
        end
    return ret
end

function createCheckBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new checkbox\n"
    ret = ret .. "CheckBox " .. name .. " = new CheckBox();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end



function createComboBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new combobox\n"
    ret = ret .. "ComboBox<String> " .. name .. " = new ComboBox<>();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end

function createTextField(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new TextField\n"
    ret = ret .. "TextField " .. name .. " = new TextField();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end

function createSpinBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "SpinBox"
end

function createDate(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "// Date input not implemented"
end

function createTime(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "// Time input not implemented"
end

function createSlider(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new Slider\n"
    ret = ret .. "Slider " .. name .. " = new Slider();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end


function createLabel(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new Label\n"
    ret = ret .. "Label " .. name .. " = new Label();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end

function createProgressBar(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new ProgressBar\n"
    ret = ret .. "ProgressBar " .. name .. " = new ProgressBar();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end


function createGroupBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "GroupBox"
end

function createListView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new ListView\n"
    ret = ret .. "ListView<String> " .. name .. " = new ListView<>();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end

function createTableView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new TableView\n"
    ret = ret .. "TableView<String> " .. name .. " = new TableView<>();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end

function createTreeView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    ret = "// Create a new TreeView\n"
    ret = ret .. "TreeView<String> " .. name .. " = new TreeView<>();\n"
    ret = ret .. name ..".setLayoutX("..posX..");\n"
    ret = ret .. name .. ".setLayoutY(".. posY..");\n"
    ret = ret .. name .. ".resize(".. width ..", ".. height..");\n"
    ret = ret .. name .. ".setMaxHeight(" .. maxheight .. ");\n"
    ret = ret .. name .. ".setMinHeight(" .. minHeight .. ");\n"
    ret = ret .. name .. ".setMaxWidth(" .. maxWidth .. ");\n"
    ret = ret .. name .. ".setMinWidth(" .. minWidth .. ");\n"
    ret = ret .. name .. ".setTooltip(new Tooltip(\" " .. tooltip .. "\"));\n"
    -- JavaFX convention, you can not set visibile state just disable state
    -- => If visibile == true we must set disable to false
    if true == visibility then
        ret = ret .. name .. ".setDisable(false);\n"
    else    
        ret = ret .. name .. ".setDisable(true);\n"
    end
    return ret
end

-- This variables are equivalent to the enum which the programm use
uncat_nothing = 0
control_Button = 1
control_RadioButton = 2  
control_CheckBox = 3
input_ComboBox = 4
input_TextField = 5
input_SpinBox = 6
input_Date = 7
input_Time = 8
input_Slider = 9
display_Label = 10
display_ProgressBar = 11
display_WebView = 12
grouping_GroupBox = 13
grouping_RadioButtonGroup = 14
dataVisualization_ListView = 15
dataVisualization_TableView = 16
dataVisualization_TreeView = 17
layout_Grid = 18
layout_Canvas = 19
layout_HBox = 20
layout_VBox = 21

-- Request scenegraph size
maxItems = GetSceneGraphSize() - 1
Print(maxItems)
-- Fileheader
result =           "+--------------------------------------------------+\n";
result = result .. "| Youre only a few step away from your interface.  |\n";
result = result .. "| To use this content you have to copy all content |\n";
result = result .. "| Do not copy this line                            |\n";
result = result .. "| Paste the code into your ui file                 |\n";
result = result .. "| Build your application                           |\n";
result = result .. "| Enjoy your interface.                            |\n";
result = result .. "+--------------------------------------------------+\n";
-- Iterate over the scenegraph
for idx = 0, maxItems, 1 do
    -- Get the item type
    type = GetType(idx)
    -- Test if the item is declared
    Print(type)
    if type ~= uncat_nothing then 
        -- Get basic attributes
        height = GetHeight(idx)
        maxHeight = GetMaxHeight(idx)
        minHeight = GetMinHeight(idx)
        width = GetWidth(idx)
        maxWidth = GetMaxWidth(idx)
        minWidth = GetMinWidth(idx)
        posX = GetPositionX(idx)
        posY = GetPositionY(idx)
        name = GetName(idx)
        enabled = GetEnabled(idx)
        tooltip = GetTooltip(idx)

        -- Switch between each type
        if type == control_Button then
            result = result .. createButton(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == control_CheckBox then
            result = result .. createCheckBox(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == control_RadioButton then
            result = result ..  createRadioButton(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"

        elseif type == input_ComboBox then
            result = result ..  createComboBox(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == input_Slider then
            result = result ..  createSlider(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == input_SpinBox then
            result = result ..  createSpinBox(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == input_TextField then
            result = result ..  createTextField(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == input_Date then
            result = result ..  createDate(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == input_Time then
            result = result ..  createTime(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"

        elseif type == display_Label then
            result = result ..  createLabel(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == display_ProgressBar then
            result = result ..  createProgressBar(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
            
        elseif type == dataVisualization_ListView then
            result = result ..  createListView(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == dataVisualization_TableView then
            result = result ..  createTableView(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
        elseif type == dataVisualization_TreeView then
            result = result ..  createTreeView(name, width, maxWidth, minWidth, height, maxHeight, minHeight, posX, posY, tooltip, enabled) .. "\n"
            
        end
    end
end

-- Export the result
Export(result)