#ifndef _H_GLOBALS
#define _H_GLOBALS

#include "Utils.h"
#include "scenes/include/Scene.h"
#include "scenes/include/SceneMainMenu.h"
#include "scenes/include/SceneGame.h"
#include "scenes/include/SceneEditor.h"
#include "Console.h"
#include "Graphics.h"

class Graphics;
class Console;

typedef struct 
{
	SceneMainMenu* sceneMainMenu;
	SceneGame* sceneGame;
	SceneEditor* sceneEditor;
	Scene* selectedScene;
	Graphics* camera;
	Console* console;
} mainResources_t;

extern mainResources_t mainRes;

#endif /* _H_GLOBALS */
