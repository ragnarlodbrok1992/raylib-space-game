#ifndef H_MAIN
#define H_MAIN

#include "src/Utils.h"
#include "src/scenes/include/Scene.h"
#include "src/scenes/include/SceneMainMenu.h"
#include "src/scenes/include/SceneGame.h"
#include "src/scenes/include/SceneEditor.h"
#include "src/Console.h"
#include "src/Parser.h"
#include "src/Graphics.h"
#include "submodules/network/src/host.h"

// TEMP INCLUDES
#include <iostream>

typedef struct 
{
	SceneMainMenu* sceneMainMenu;
	SceneGame* sceneGame;
	//SceneEditor* sceneEditor; not implemented yet
	Scene* selectedScene;
	HostNetwork* network;
	Graphics* camera;
	Console* console;
}mainResources_t;

#endif /* H_MAIN */
