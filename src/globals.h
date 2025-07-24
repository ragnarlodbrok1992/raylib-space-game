#pragma once

#ifndef _H_GLOBALS
#define _H_GLOBALS

class Graphics;
class Console;
class SceneGame;
class Scene;
class SceneMainMenu;
class SceneEditor;
class Cursor;
class Parser;

typedef struct 
{
	SceneMainMenu* sceneMainMenu;
	SceneGame* sceneGame;
	SceneEditor* sceneEditor;
	Scene* selectedScene;
	Graphics* camera;
	Console* console;
	Cursor* cursor;
  Parser* parser;
} mainResources_t;

extern mainResources_t mainRes;

#endif /* _H_GLOBALS */
