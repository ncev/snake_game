#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main()
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
       /* Création de la fenêtre */
       SDL_Window* pWindow = nullptr;
       pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                 SDL_WINDOWPOS_UNDEFINED,
                                                                 640,
                                                                 480,
                                                                 SDL_WINDOW_SHOWN);

       if( pWindow )
       {
           int continuer = 1;
           SDL_Event event;

           while (continuer) {
               while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
               {
                   switch(event.type)
                   {
                       case SDL_QUIT: // Clic sur la croix
                           continuer = 0;
                           break;
                   }
               }
           }
       }
       else
       {
           fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
       }
       SDL_DestroyWindow(pWindow);
   }

   SDL_Quit();

    return 0;
}
