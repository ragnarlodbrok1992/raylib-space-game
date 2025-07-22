#include "Graphics.h"
#include "raylib.h"



void Graphics::init_camera()
{
    InitWindow(screenWidth, screenHeight, "RayLib Space Game");

    SetTargetFPS(60);
    this->cameraProperties.offset.x = GetScreenWidth() / 2.0f;
    this->cameraProperties.offset.y = GetScreenHeight() / 2.0f;
    this->cameraProperties.target.x = 0.0f;
    this->cameraProperties.target.y = 0.0f;
    this->cameraProperties.rotation = 0.0f;
    this->cameraProperties.zoom = 1.0f;
}

void Graphics::set_scene(SceneEnum selectedScene)
{
    this->selectedScene = selectedScene;
    switch (this->selectedScene)
    {
    case SceneEnum::MAINMENU:
        change_scene(sceneMainMenu);
        break;
    case SceneEnum::GAMESCENE:
        change_scene(sceneGame);
        break;
    }
}

void Graphics::change_scene(Scene* scene)
{
    renderScene = scene;
    scene->prepare_scene();
}

void Graphics::register_scene(SceneGame* sceneGame)
{
    this->sceneGame = sceneGame;
}

void Graphics::register_scene(SceneMainMenu* sceneMainMenu)
{
    this->sceneMainMenu = sceneMainMenu;
}

void Graphics::register_console(Console* console)
{
    this->console = console;
}

bool Graphics::is_key_pressed(uint16_t key)
{
    return IsKeyPressed(KeyboardKey(key));
}

void Graphics::render()
{
	this->zoom += 0.01f * GetMouseWheelMove(); // Adjust zoom with mouse wheel
	if (this->zoom < this->minZoom) this->zoom = this->minZoom; // Prevent zooming out too much
    // Frame begins here
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (this->selectedScene == SceneEnum::GAMESCENE)
    {
        calculate_player_camera(sceneGame->get_player_position(),
            sceneGame->get_player_velocity());

        BeginMode2D(this->cameraProperties);
    }
    renderScene->render();
    EndMode2D();
	renderScene->render_cursor();
    console->render();

    EndDrawing();
}

void Graphics::close_window()
{
   CloseWindow();
}
bool Graphics::should_window_close()
{
    return WindowShouldClose();
}

void Graphics::calculate_player_camera(Vector2 playerPosition, Vector2 playerVelocityVector)
{
    this->cameraProperties.offset.x = GetScreenWidth() / 2.0f;
    this->cameraProperties.offset.y = GetScreenHeight() / 2.0f;
    float playerVelocity = VectorLength(playerVelocityVector);
    this->cameraProperties.target = playerPosition;
    if (((GetScreenWidth() / 3) < abs(playerVelocityVector.x * speedToOffsetFactor)))
    {
        if (0 < playerVelocityVector.x)
        {
            this->cameraProperties.offset.x -= GetScreenWidth() / 3;
        }
        else
        {
            this->cameraProperties.offset.x += GetScreenWidth() / 3;
        }
    }
    else
    {
        this->cameraProperties.offset.x -= playerVelocityVector.x * speedToOffsetFactor;
    }

    if (((GetScreenHeight() / 3) < abs(playerVelocityVector.y * speedToOffsetFactor)))
    {
        if (0 < playerVelocityVector.y)
        {
            this->cameraProperties.offset.y -= GetScreenHeight() / 3;
        }
        else
        {
            this->cameraProperties.offset.y += GetScreenHeight() / 3;
        }
    }
    else
    {
        this->cameraProperties.offset.y -= playerVelocityVector.y * speedToOffsetFactor;
    }

    if (playerVelocity < fullZoomMaxVelocity)
    {
        this->cameraProperties.zoom = maxZoom;
    }
    else if (playerVelocity < firstRange)
    {
        this->cameraProperties.zoom = maxZoom - (playerVelocity - fullZoomMaxVelocity) / (firstRangeAdd / (maxZoom - firstRangeZoom));
    }
    else
    {
        this->cameraProperties.zoom = firstRangeZoom - (playerVelocity - firstRange) / (secondRangeAdd / firstRangeZoom - secondRangeZoom);
    }
    if (this->cameraProperties.zoom < 0.5f)
    {
        this->cameraProperties.zoom = 0.5f;
    }
    this->cameraProperties.zoom *= this->zoom; // Apply zoom factor from Graphics class
}
