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
 
-- Set this variable to your language name
languageName = ""

-- Aquire size of scenegraph
maxElements = GetSceneGraphSize();

-- iterate from 0 until last element reached
for i = 0, 1, maxElements 
do
    -- Aquire base attributes
    idx = 0
    name = GetName(idx)
    width = GetWidth(idx)
    maxWidth = GetMaxWidth(idx)
    minWidth = GetMinWidth(idx)
    height = GetHeight(idx)
    maxHeight = GetMaxHeight(idx)
    minHeight = GetMinHeight(idx)
    positionX = GetPositionX(idx)
    positionY = GetPositionY(idx)
    tooltip = GetTooltip(idx)
    visibility = GetEnabled(idx)

    -- Call specific functions and create your object using the aquired attributes

    -- Add your object
end

ExportNow(tmp, languageName)
DisplayMessageBox("Finished", "Build was successful finished", 1)


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
