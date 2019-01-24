# LUA UI-Designer API
It is possible to use own scripts, all available access methods will be listed here.

+ [Print](#Print)<br>
+ [DisplayMessageBox](#DisplayMessageBox)<br>
+ [GetSceneGraphSize](#Getscenegraphsize) <br>
+ [GetType](#GetType)<br>
+ [GetHeight](#GetHeight) <br>
+ [GetMaxHeight](#GetMaxHeight)<br>
+ [GetMinHeight](#GetMinHeight)<br>
+ [GetWidth](#GetWidth) <br>
+ [GetMaxWidth](#GetMaxWidth) <br>
+ [GetMinWidth](#GetMinWidth) <br>
+ [GetPositionX](#GetPositionX)<br>
+ [GetPositionY](#GetPositionY)<br>
+ [GetName](#GetName) <br>
+ [GetEnabled](#GetEnabled)<br>
+ [GetTooltip](#GetTooltip)<br>
+ [Example](#example)<br>


## _[Print](#Print)_
This method prints the parameter to the standart output stream.<br>
<br> 
+ Parameter
    1. String 
    2. Number 
+ Return: Nothing
<br>

```lua
x = 5
Print(x)
```

```lua
Print("Hello World")
```
<br>

## _[GetSceneGraphSize](#Getscenegraphsize)_
This method will return the ammount of existing widgets inside the scenegraph
+ Parameter:
    1. None
+ Return: Size of the scenegraph

```lua
amountOfWidgets = GetSceneGraphSize()
```

## _[DisplayMessageBox](#DisplayMessageBox)_
This method will create a new messagebox which is immidately displayed.
+ Parameter:
    1. String: Short info
    2. String: Body details
    3. Number: Button type
        + 1: Create Yes/No
        + 2: Create Yes/No/Cancel
        + 3: Create Yes/No/Cancel/Close
+ Return: Nothig

```lua
CreateMessageBox("Information", "Hello World", 3)
```

## _[GetType](#GetType)_
This method will receive the type of the selected object.
+ Parameter:
    1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
+ Retruns
    1. Number: Number which represent the object type

```
 0: uncat_nothing
 1: control_Button
 2: control_RadioButton  
 3: control_CheckBox
 4: input_ComboBox
 5: input_TextField
 6: input_SpinBox
 7: input_Date
 8: input_Time
 9: input_Slider
10: display_Label
11: display_ProgressBar
12: display_WebView
13: grouping_GroupBox
14: grouping_RadioButtonGroup
15: dataVisualization_ListView
16: dataVisualization_TableView
17: dataVisualization_TreeView
18: layout_Grid
19: layout_Canvas
20: layout_HBox
21: layout_VBox
```
```lua
height = GetType(0);
```
## _[GetHeight](#GetHeight)_
This method request the height of an element
+ Parameter:
    1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
+ Retruns
    1. Number: Height of the element 

```lua
height = GetHeight(0);
```

## _[GetMaxHeight](#GetMaxHeight)_
   This method request the maximum height of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: Maximum height of the element
   
```lua
maxHeight = GetMaxHeight(0);
```

## _[GetMinHeight](#GetMinHeight)_
   This method request the minimum height of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: Minimum height of the element
   
```lua
minHeight = GetMinHeight(0);
```

## _[GetWidth](#GetWidth)_
   This method request the width of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: width of the element
   

```lua
width = GetWidth(0);
```

## _[GetMaxWidth](#GetMaxWidth)_
   This method request the maximum width of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: maximum width of the element
   

```lua
maxWidth = GetMaxWidth(0);
```

## _[GetMinWidth](#GetMinWidth)_
   This method request the minimum width of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: minimum width of the element

```lua
minWidth = GetMinWidth(0);
```

## _[GetPositionX](#GetPositionX)_
   This method request the x coordinate of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: x coordinate of the element  

```lua
posX = GetPositionX(0);
```

## _[GetPositionY](#GetPositionY)_
   This method request the y coordinate of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: y coordinate of the element  

```lua
posY = GetPositionY(0);
```

## _[GetName](#GetName)_
This method request the name of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. String: name of the element  

```lua
name = GetName(0);
```

## _[GetEnabled](#GetEnabled)_
This method request the enabled state of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Boolean: true if the the element is enabled  

```lua
enabled = GetEnabled(0);
```

## _[GetTooltip](#GetTooltip)_
This method request the width of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. String: tooltip of the element  

```lua
tooltip = GetTooltip(0);
```

## [Example](#example)
This script will create a code which implements the UI inside javaFX using code behind.
```lua 
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
    return "// SpinBox is not implemented"
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
    return "// GroupBox is not implemented"
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
return result
```
