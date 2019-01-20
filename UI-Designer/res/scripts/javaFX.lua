
function createButton(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createRadioButton(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createCheckBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end



function createComboBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createTextField(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createSpinBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createDate(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createTime(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createSlider(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end



function createLabel(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createProgressBar(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createWebView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end



function createGroupBox(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createRadioButtonGroup(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end



function createListView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createTableView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

function createTreeView(name, width, maxwidth, minwidth, height, maxheight, mineight, x, y, tooltip, visibility)
    return ""
end

maxItems = GetSceneGraphSize()
Export("BLA " .. maxItems)
for idx = 0, maxItems, 1
do
    type = GetType(idx)
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
    
end
