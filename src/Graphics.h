#pragma once
#include <math.h>
#include "Utils.h"
#include "scenes/include/Scene.h"
#include "scenes/include/SceneEditor.h"
#include "scenes/include/SceneGame.h"
#include "scenes/include/SceneMainMenu.h"
#include "Console.h"

class Graphics
{
public:
	void calculate_player_camera(Vector2 playerPosition, Vector2 playerVelocityVector);
	void render();
	void close_window();
	bool should_window_close();
	void set_scene(SceneEnum selectedScene);
	void register_scene(SceneGame* sceneGame);
	void register_scene(SceneMainMenu* sceneMainMenu);
	void register_console(Console* console);

	bool is_key_pressed(uint16_t key);
	Graphics() { init_camera(); }
	~Graphics() {}

private:
	SceneEnum selectedScene;
	SceneGame* sceneGame;
	SceneMainMenu* sceneMainMenu;
	Scene* renderScene;
	Console* console;
	Cursor cursor;
	void init_camera();
	void change_scene(Scene*);
	float zoom = 1.0f;
	const float minZoom = 0.04f; // Minimum zoom to prevent too much zoom out
	const float maxZoom = 2.0f;
	const float fullZoomMaxVelocity = 40.0f;
	const float firstRangeAdd = 100.0f;
	const float firstRange = fullZoomMaxVelocity + firstRangeAdd;
	const float firstRangeZoom = 1.0f;
	const float secondRangeAdd = 300.0f;
	const float secondRangeZoom = 0.5f;
	const float speedToOffsetFactor = 2.0f;
};