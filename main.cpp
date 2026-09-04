#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <memory>
#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "HUD.h"

const int WINDOW_W = 1024;
const int WINDOW_H = 600;

int main(int argc, char* argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO)) { return 1; }

    SDL_Window* window = SDL_CreateWindow(
        "Animated Character - Inheritance", WINDOW_W, WINDOW_H, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    {
        Player player((float)WINDOW_W, (float)WINDOW_H);

        std::vector<std::unique_ptr<Enemy>> enemies;

        struct Spec { float w, h, y, speed; SDL_Color color; };
        const Spec specs[] = {
            {  80.0f,  80.0f, 100.0f, 120.0f, { 220, 100, 100, 255 } },
            {  60.0f,  60.0f, 260.0f, 220.0f, { 100, 220, 130, 255 } },
            {  40.0f,  40.0f, 420.0f, 320.0f, { 100, 170, 255, 255 } },
        };

        for (int i = 0; i < 3; ++i)
        {
            const float startX = (float)WINDOW_W + i * 200.0f;
            enemies.push_back(std::make_unique<Enemy>(
                startX, specs[i].y,
                specs[i].w, specs[i].h,
                specs[i].speed, (float)WINDOW_W,
                specs[i].color));
        }

        HUD hud;
        Uint64 lastTicks = SDL_GetTicksNS();
        bool   running = true;

        while (running)
        {
            SDL_Event ev;
            while (SDL_PollEvent(&ev))
            {
                if (ev.type == SDL_EVENT_QUIT) running = false;
                if (ev.type == SDL_EVENT_KEY_DOWN &&
                    ev.key.scancode == SDL_SCANCODE_ESCAPE) running = false;
            }

            const Uint64 now = SDL_GetTicksNS();
            const float  dt = (float)(now - lastTicks) / 1.0e9f;
            lastTicks = now;

            player.update(dt);
            for (auto& e : enemies) e->update(dt);

            hud.update(dt);

            SDL_SetRenderDrawColor(renderer, 30, 35, 45, 255);
            SDL_RenderClear(renderer);

            player.render(renderer);
            for (const auto& e : enemies) e->render(renderer);

            hud.render(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}