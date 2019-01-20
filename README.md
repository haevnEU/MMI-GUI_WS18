# GUI Designer

## [Inhalt](#inhalt)

[Ziel](#ziel)<br>
[Benutzung](#benutzung)<br>
[API](#api)

## [Ziel](#ziel)
Dieses Projekt ist entstanden durch mangelnde Verfügbarkeit von UI Designer die Unabhngig von Sprachen operieren. Die verfügbaren Alternativen sind zu Kostenintensiv. <br>
Geplannt ist die Erstellung von einfügbaren code in der jeweiligen Zielsprache, mit Skripten soll jede verfügbare Sprache unterstützt werden.<br>
Dieses Projekt unterstützt simple Objekte wie Button, ListView, CheckBox, etc. komplexere Elemente werden nach und nach hinzugefügt.<br><br>
[Oben](#inhalt)
## [Benutzung](#benutzung)
### Menu
Das Menu beinhaltet Laden, Speichern, Exportieren sowie Hilfe und eine Info.<br>
Der Eintrag File besitzt die Möglichkeit zu Speichern, Laden und Alles zu löschen. <br>
Der Eintrag ... beinhaltet den Eintrag Run der ein Script ausführt und exportiert.<br>
Der Eintrag Hilfe beinhaltet ein Link zur wiki sowie Infos über das Programm sowie Qt.<br>
Laden und Speichern werden noch nicht unterstüzt.
[Oben](#inhalt)<br>
## [API](#api)
It is possible to use own scripts, all available access methods will be listed here.

1. [Print](#Print)<br>
2. [DisplayMessageBox](#DisplayMessageBox)<br>
3. [GetSceneGraphSize](#Getscenegraphsize) <br>
4. [Export](#Export)<br>
5. [GetType](#GetType)<br>
6. [GetHeight](#GetHeight) <br>
7. [GetMaxHeight](#GetMaxHeight)<br>
8. [GetMinHeight](#GetMinHeight)<br>
9. [GetWidth](#GetWidth) <br>
10. [GetMaxWidth](#GetMaxWidth) <br>
11. [GetMinWidth](#GetMinWidth) <br>
12. [GetPositionX](#GetPositionX)<br>
13. [GetPositionY](#GetPositionY)<br>
14. [GetName](#GetName) <br>
15. [GetEnabled](#GetEnabled)<br>
16. [GetTooltip](#GetTooltip)<br>
17. [Example](#example)<br>


### _[Print](#Print)_
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

### _[GetSceneGraphSize](#Getscenegraphsize)_
This method will return the ammount of existing widgets inside the scenegraph
+ Parameter:
    1. None
+ Return: Size of the scenegraph

```lua
amountOfWidgets = GetSceneGraphSize()
```

### _[DisplayMessageBox](#DisplayMessageBox)_
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

### _[Export](#Export)_
This method will export the create UI file into a language specific file. The language was determine in the execution script.
+ Parameter:
    1. String: Path to the place where the file should be saved on disk
+ Return: Nothing<br>

Windows:
```lua
Export("C:\\Users\\name\\Test.xml")
```
Unix/Max
```lua
Export("/User/name/Test.xml")
```
### _[GetType](#GetType)_
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
### _[GetHeight](#GetHeight)_
This method request the height of an element
+ Parameter:
    1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
+ Retruns
    1. Number: Height of the element 

```lua
height = GetHeight(0);
```

### _[GetMaxHeight](#GetMaxHeight)_
   This method request the maximum height of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: Maximum height of the element
   
```lua
maxHeight = GetMaxHeight(0);
```

### _[GetMinHeight](#GetMinHeight)_
   This method request the minimum height of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: Minimum height of the element
   
```lua
minHeight = GetMinHeight(0);
```

### _[GetWidth](#GetWidth)_
   This method request the width of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: width of the element
   

```lua
width = GetWidth(0);
```

### _[GetMaxWidth](#GetMaxWidth)_
   This method request the maximum width of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: maximum width of the element
   

```lua
maxWidth = GetMaxWidth(0);
```

### _[GetMinWidth](#GetMinWidth)_
   This method request the minimum width of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: minimum width of the element

```lua
minWidth = GetMinWidth(0);
```

### _[GetPositionX](#GetPositionX)_
   This method request the x coordinate of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: x coordinate of the element  

```lua
posX = GetPositionX(0);
```

### _[GetPositionY](#GetPositionY)_
   This method request the y coordinate of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Number: y coordinate of the element  

```lua
posY = GetPositionY(0);
```

### _[GetName](#GetName)_
This method request the name of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. String: name of the element  

```lua
name = GetName(0);
```

### _[GetEnabled](#GetEnabled)_
This method request the enabled state of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. Boolean: true if the the element is enabled  

```lua
enabled = GetEnabled(0);
```

### _[GetTooltip](#GetTooltip)_
This method request the width of an element
   + Parameter:
        1. Number: Index of the element in scenegraph, important nothin will returned if the value exceed the scenegraph size
    + Retruns
        1. String: tooltip of the element  

```lua
tooltip = GetTooltip(0);
```

### [Example](#example)
This file script will create a code which implements the UI inside javaFX using code behind.
```lua

TODO

```
<br>[Oben](#inhalt)<br>
