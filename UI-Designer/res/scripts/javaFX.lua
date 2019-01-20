
function createButton(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "Button"
end

function createRadioButton(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "RadioButton"
end

function createCheckBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "CheckBox"
end



function createComboBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "ComboBox"
end

function createTextField(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "TextField"
end

function createSpinBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "SpinBox"
end

function createDate(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "Date"
end

function createTime(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "Time"
end

function createSlider(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "Slider"
end


function createLabel(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "label"
end

function createProgressBar(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "Progressbar"
end


function createGroupBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "GroupBox"
end

function createListView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "ListView"
end

function createTableView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "TableView"
end

function createTreeView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return "TreeView"
end


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

maxItems = GetSceneGraphSize()
result = ""
for idx = 0, maxItems, 1 do
    type = GetType(idx)
    if type ~= uncat_nothing then 
        Print(type)
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
Export(result)
Print(result)