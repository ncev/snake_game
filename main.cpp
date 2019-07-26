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
    } else {

    }

    return 0;
}
