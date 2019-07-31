#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"

using namespace std;

void sdl_loop_event(int* continuer, Game* game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
    {
        switch(event.type)
        {
            case SDL_QUIT: // Clic sur la croix
                *continuer = 0;
                break;
        }
    }
    game->mainLoop(event);
}

int main()
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    {
       /* Création de la fenêtre */
       SDL_Window* pWindow = nullptr;
       pWindow = SDL_CreateWindow("snake",SDL_WINDOWPOS_UNDEFINED,
                                                                 SDL_WINDOWPOS_UNDEFINED,
                                                                 625,
                                                                 475,
                                                                 SDL_WINDOW_SHOWN);

       SDL_Renderer* renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
       Game* game = new Game(renderer);

       if(pWindow)
       {
           int continuer = 1;
           while (continuer) {
               sdl_loop_event(&continuer, game);
           }
       }
       else
       {
           fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
       }
       SDL_DestroyWindow(pWindow);
       delete game;
   }

   SDL_Quit();
   TTF_Quit();

    return 0;
}
