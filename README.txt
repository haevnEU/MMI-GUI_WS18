1. Projektstruktur
2. Repository
3. Resource path
-------------------------------------------------------------------------------------
1: Projektstruktur

Der namespace entspricht der verzeichnissstruktur.
Der namespace haevn existiert nicht, wird aber als root namespace verwendet

+-------------------+
|Tree structure     |
+-------------------+
|                   |
| haevn             |
|  |--core          |
|  |--|--enums      |
|  |--|--export     |
|  |--|--lua        |
|  |  |    |--src   |
|  |  |--models     |
|  |  |--visual     |
|  |--view          |
|                   |
+-------------------+

+----------------------+----------------------------+
| namespace            | Describtion                |
+----------------------+----------------------------+
|haevn                 | Root namespace             |
+----------------------+----------------------------+
|haevn::core           | Core elements              |
+----------------------+----------------------------+
|haevn::core::enums    | Enumeration                |
+----------------------+----------------------------+
|haevn::core::export   | File IO are placed here    |
+----------------------+----------------------------+
|haevn::core::lua      | Lua operation              |
+----------------------+----------------------------+
|haevn::core::lua::src | Lua source code            |
+----------------------+----------------------------+
|haevn::core::models   | Application models         |
+----------------------+----------------------------+
|haevn::core::visual   | Visual elements, no window |
+----------------------+----------------------------+
|haevn::view           | Window form files          |
+----------------------+----------------------------+

--------------------------------------------------------------------------------------
2: Repository
Das Projekt ist auch unter GitHub zu finden.
Auf GitHub befinden sich zusätzliche Informationen
 wie nutzung des Programms und der API auch ein Beispiel skript zum erstellen
 des Interfaces wird bereitgestellt
Repo: https://github.com/nimile/MMI-GUI
Wiki: https://github.com/nimile/MMI-GUI/wiki

--------------------------------------------------------------------------------------
3: Resourcepath

Der Interfacebuilder arbeitet mit dem DataLocation verzeichniss, 
dies bedeutet das der Inhalt muss in das DataLocation Verzeichniss kopiert werden.

Unter Windows: C:/Users/<USER>/AppData/Local/UI-Designer
Unter MacOS: ~/Library/Application Support/UI-Designer
Linux(not tested): ~/.local/share/UI-Designer
