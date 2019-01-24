--[[
    DO NOT REMOVE THIS HEADER
    +---------------------------------------------------------------------------------------------------------------+
    |                                                   README                                                      |
    +---------------------------------------------------------------------------------------------------------------+
    | Step 1: Modify marked function                                                                                |
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
    | You can modify the marked places to create your own export file,                                              |
    | if you create a new language export script post it inside the repo                                            |
    | with a .lua extension (eg. javaFX.lua, qt.lua, cs.lua, ...)                                                   |
    |                                                                                                               |
    | Jan 14 2019 by Nils Milewski (haevn)                                                                          |
    |                                                                                                               |
    +---------------------------------------------------------------------------------------------------------------+
 ]]
 

-- This function create a button
function createButton(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    -- Modify this content, you can remove this comment
    return ""
end

-- This function create a radiobutton
function createRadioButton(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)  
       -- Modify this content, you can remove this comment
    return ""
end

-- This function create a checkbox
function createCheckBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)   
      -- Modify this content, you can remove this comment
    return ""
end

-- This function create a combobox
function createComboBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)   
      -- Modify this content, you can remove this comment
    return ""
end

-- This function creates a textfield
function createTextField(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)   
      -- Modify this content, you can remove this comment
    return ""
end

-- This function create a spinbox
function createSpinBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)  
       -- Modify this content, you can remove this comment
    return ""
end

-- This function create a datepicker
function createDate(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)     
    -- Modify this content, you can remove this comment
    return ""
end

-- This function create a timepicker
function createTime(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)    
     -- Modify this content, you can remove this comment
    return ""
end

-- This function create a slider
function createSlider(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)    
     -- Modify this content, you can remove this comment
    return ""
end


-- This function create a Label
function createLabel(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)    
     -- Modify this content, you can remove this comment
    return ""
end

-- This function create a progressbar
function createProgressBar(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)    
     -- Modify this content, you can remove this comment
    return ""
end

-- This function create a webview
function createWebView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)  
       -- Modify this content, you can remove this comment
    return ""
end


-- This function create a groupbox
function createGroupBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)    
    -- Modify this content, you can remove this comment
    return ""
end

-- This function create a radiobutton group
function createRadioButtonGroup(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)   
      -- Modify this content, you can remove this comment
    return ""
end


-- This function create a listview
function createListView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)   
      -- Modify this content, you can remove this comment
    return ""
end

-- This function create a tableview
function createTableView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)    
     -- Modify this content, you can remove this comment
    return ""
end

-- This function create a treeview
function createTreeView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)    
     -- Modify this content, you can remove this comment
    return ""
end

--[[
Modifying the following lines may result in an undefined state.
It is therefore not allowed to modify them, should you have suggestions for changes, please share them.
]]

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
maxItems = GetSceneGraphSize()
-- Fileheader

result = ""
-- Iterate over the scenegraph
for idx = 0, maxItems, 1 do
    -- Get the item type
    type = GetType(idx)
    -- Test if the item is declared
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
return result;