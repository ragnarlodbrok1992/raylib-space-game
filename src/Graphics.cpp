#include "Graphics.h"
#include "toRaylibConversion.h"
#include "raylib.h"


Camera2D cameraProperties;

void Graphics::init_camera()
{
    InitWindow(screenWidth, screenHeight, "RayLib Space Game");

    SetTargetFPS(60);
    cameraProperties.offset.x = GetScreenWidth() / 2.0f;
    cameraProperties.offset.y = GetScreenHeight() / 2.0f;
    cameraProperties.target.x = 0.0f;
    cameraProperties.target.y = 0.0f;
    cameraProperties.rotation = 0.0f;
    cameraProperties.zoom = 1.0f;
}

void Graphics::set_scene(SceneEnum selectedScene)
{
    this->selectedScene = selectedScene;
    switch (this->selectedScene)
    {
    case SceneEnum::MAINMENU:
        renderScene = sceneMainMenu;
        break;
    case SceneEnum::GAMESCENE:
        renderScene = sceneGame;
        break;
    }
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
    // Frame begins here
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (this->selectedScene == SceneEnum::GAMESCENE)
    {
        calculate_player_camera(sceneGame->get_player_position(),
            sceneGame->get_player_velocity());

        BeginMode2D(cameraProperties);
    }
    renderScene->render();
    EndMode2D();
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

void Graphics::calculate_player_camera(rVector2 playerPosition, rVector2 playerVelocityVector)
{
    cameraProperties.offset.x = GetScreenWidth() / 2.0f;
    cameraProperties.offset.y = GetScreenHeight() / 2.0f;
    float playerVelocity = VectorLength(playerVelocityVector);
    cameraProperties.target = convert(playerPosition);
    if (((GetScreenWidth() / 3) < abs(playerVelocityVector.x * speedToOffsetFactor)))
    {
        if (0 < playerVelocityVector.x)
        {
            cameraProperties.offset.x -= GetScreenWidth() / 3;
        }
        else
        {
            cameraProperties.offset.x += GetScreenWidth() / 3;
        }
    }
    else
    {
        cameraProperties.offset.x -= playerVelocityVector.x * speedToOffsetFactor;
    }

    if (((GetScreenHeight() / 3) < abs(playerVelocityVector.y * speedToOffsetFactor)))
    {
        if (0 < playerVelocityVector.y)
        {
            cameraProperties.offset.y -= GetScreenHeight() / 3;
        }
        else
        {
            cameraProperties.offset.y += GetScreenHeight() / 3;
        }
    }
    else
    {
        cameraProperties.offset.y -= playerVelocityVector.y * speedToOffsetFactor;
    }

    if (playerVelocity < fullZoomMaxVelocity)
    {
        cameraProperties.zoom = maxZoom;
    }
    else if (playerVelocity < firstRange)
    {
        cameraProperties.zoom = maxZoom - (playerVelocity - fullZoomMaxVelocity) / (firstRangeAdd / (maxZoom - firstRangeZoom));
    }
    else
    {
        cameraProperties.zoom = firstRangeZoom - (playerVelocity - firstRange) / (secondRangeAdd / firstRangeZoom - secondRangeZoom);
    }
    if (cameraProperties.zoom < 0.5f)
    {
        cameraProperties.zoom = 0.5f;
    }
}
