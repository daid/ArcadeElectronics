#include <SDL/SDL.h>
#include "gui.h"

typedef struct
{
    int x, y, w, h;
} keyPos_t;

keyPos_t keyPos[SDLK_LAST];

void init_keyPos();

void draw_button(int active, const char* name, int x, int y, int w, int h)
{
    char buffer[32];
    strcpy(buffer, name);
    buffer[2*w] = '\0';
    buffer[0] = toupper(buffer[0]);
    if (active)
    {
        draw_fill(x * 12, y * 12, w * 12, h * 12);
        draw_text(x * 12 + w * 12 / 2 - strlen(buffer) * 6 / 2, y * 12 + h * 6 - 3, buffer, 0);
    }else{
        draw_rect(x * 12, y * 12, w * 12, h * 12);
        draw_text(x * 12 + w * 12 / 2 - strlen(buffer) * 6 / 2, y * 12 + h * 6 - 3, buffer);
    }
}

int main(int argc, char** argv)
{
    init_gui();
    init_keyPos();
    
    while(true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            switch (event.type) 
            {
            case SDL_QUIT:
                return 0;
            }
        }
        SDL_JoystickUpdate();
        
        int keyCount;
        Uint8* keys = SDL_GetKeyState(&keyCount);
        for(int n=0; n<keyCount; n++)
        {
            if (keyPos[n].x != 0)
            {
                char buffer[64];
                strcpy(buffer, SDL_GetKeyName(SDLKey(n)));
                if (strncmp(buffer, "left ", 5) == 0)
                    strcpy(buffer, buffer + 5);
                if (strncmp(buffer, "right ", 6) == 0)
                    strcpy(buffer, buffer + 6);
                draw_button(keys[n], buffer, keyPos[n].x, keyPos[n].y, keyPos[n].w, keyPos[n].h);
            }else{
                if (keys[n])
                    draw_text(0, 0, SDL_GetKeyName(SDLKey(n)));
            }
        }
        int x, y;
        int button = SDL_GetMouseState(&x, &y);
        draw_button(button & SDL_BUTTON(1), "Left", 1, 18, 2, 2);
        draw_button(button & SDL_BUTTON(2), "Mid", 3, 18, 2, 2);
        draw_button(button & SDL_BUTTON(3), "Right", 5, 18, 2, 2);
        draw_rect(12, 20*12, 6*12, 6*12);
        draw_rect(12 + x * 6*12 / 640, 20*12 + y * 6*12 / 480, 2, 2);
        SDL_GetRelativeMouseState(&x, &y);
        draw_rect(12 + 6*12/2 + x/2, 20*12 + 6*12 / 2 + y/2, 2, 2);
        
        for(int n=0; n<SDL_NumJoysticks(); n++)
        {
            
        }
        
        gui_update();
    }
}


void init_keyPos()
{
    keyPos[SDLK_ESCAPE] = {1, 1, 3, 2};
    
    keyPos[SDLK_F1] = {5, 1, 2, 2};
    keyPos[SDLK_F2] = {7, 1, 2, 2};
    keyPos[SDLK_F3] = {9, 1, 2, 2};
    keyPos[SDLK_F4] = {11, 1, 2, 2};
    keyPos[SDLK_F5] = {14, 1, 2, 2};
    keyPos[SDLK_F6] = {16, 1, 2, 2};
    keyPos[SDLK_F7] = {18, 1, 2, 2};
    keyPos[SDLK_F8] = {20, 1, 2, 2};
    keyPos[SDLK_F9] = {23, 1, 2, 2};
    keyPos[SDLK_F10] = {25, 1, 2, 2};
    keyPos[SDLK_F11] = {27, 1, 2, 2};
    keyPos[SDLK_F12] = {29, 1, 2, 2};

    keyPos[SDLK_BACKQUOTE] = {1, 4, 2, 2};
    keyPos[SDLK_1] = {3, 4, 2, 2};
    keyPos[SDLK_2] = {5, 4, 2, 2};
    keyPos[SDLK_3] = {7, 4, 2, 2};
    keyPos[SDLK_4] = {9, 4, 2, 2};
    keyPos[SDLK_5] = {11, 4, 2, 2};
    keyPos[SDLK_6] = {13, 4, 2, 2};
    keyPos[SDLK_7] = {15, 4, 2, 2};
    keyPos[SDLK_8] = {17, 4, 2, 2};
    keyPos[SDLK_9] = {19, 4, 2, 2};
    keyPos[SDLK_0] = {21, 4, 2, 2};
    keyPos[SDLK_MINUS] = {23, 4, 2, 2};
    keyPos[SDLK_EQUALS] = {25, 4, 2, 2};
    keyPos[SDLK_BACKSPACE] = {27, 4, 4, 2};

    keyPos[SDLK_TAB] = {1, 6, 3, 2};
    keyPos[SDLK_q] = {4, 6, 2, 2};
    keyPos[SDLK_w] = {6, 6, 2, 2};
    keyPos[SDLK_e] = {8, 6, 2, 2};
    keyPos[SDLK_r] = {10, 6, 2, 2};
    keyPos[SDLK_t] = {12, 6, 2, 2};
    keyPos[SDLK_y] = {14, 6, 2, 2};
    keyPos[SDLK_u] = {16, 6, 2, 2};
    keyPos[SDLK_i] = {18, 6, 2, 2};
    keyPos[SDLK_o] = {20, 6, 2, 2};
    keyPos[SDLK_p] = {22, 6, 2, 2};
    keyPos[SDLK_LEFTBRACKET] = {24, 6, 2, 2};
    keyPos[SDLK_RIGHTBRACKET] = {26, 6, 2, 2};
    keyPos[SDLK_BACKSLASH] = {28, 6, 3, 2};

    keyPos[SDLK_CAPSLOCK] = {1, 8, 4, 2};
    keyPos[SDLK_a] = {5, 8, 2, 2};
    keyPos[SDLK_s] = {7, 8, 2, 2};
    keyPos[SDLK_d] = {9, 8, 2, 2};
    keyPos[SDLK_f] = {11, 8, 2, 2};
    keyPos[SDLK_g] = {13, 8, 2, 2};
    keyPos[SDLK_h] = {15, 8, 2, 2};
    keyPos[SDLK_j] = {17, 8, 2, 2};
    keyPos[SDLK_k] = {19, 8, 2, 2};
    keyPos[SDLK_l] = {21, 8, 2, 2};
    keyPos[SDLK_SEMICOLON] = {23, 8, 2, 2};
    keyPos[SDLK_QUOTE] = {25, 8, 2, 2};
    keyPos[SDLK_RETURN] = {27, 8, 4, 2};

    keyPos[SDLK_LSHIFT] = {1, 10, 5, 2};
    keyPos[SDLK_z] = {6, 10, 2, 2};
    keyPos[SDLK_x] = {8, 10, 2, 2};
    keyPos[SDLK_c] = {10, 10, 2, 2};
    keyPos[SDLK_v] = {12, 10, 2, 2};
    keyPos[SDLK_b] = {14, 10, 2, 2};
    keyPos[SDLK_n] = {16, 10, 2, 2};
    keyPos[SDLK_m] = {18, 10, 2, 2};
    keyPos[SDLK_COMMA] = {20, 10, 2, 2};
    keyPos[SDLK_PERIOD] = {22, 10, 2, 2};
    keyPos[SDLK_SLASH] = {24, 10, 2, 2};
    keyPos[SDLK_RSHIFT] = {26, 10, 5, 2};

    keyPos[SDLK_LCTRL] = {1, 12, 3, 2};
    keyPos[SDLK_LSUPER] = {4, 12, 3, 2};
    keyPos[SDLK_LALT] = {7, 12, 3, 2};
    keyPos[SDLK_SPACE] = {10, 12, 9, 2};
    keyPos[SDLK_RALT] = {19, 12, 3, 2};
    keyPos[SDLK_RSUPER] = {22, 12, 3, 2};
    keyPos[SDLK_MENU] = {25, 12, 3, 2};
    keyPos[SDLK_RCTRL] = {28, 12, 3, 2};

    keyPos[SDLK_PRINT] = {32, 1, 2, 2};
    keyPos[SDLK_SCROLLOCK] = {34, 1, 2, 2};
    keyPos[SDLK_PAUSE] = {36, 1, 2, 2};

    keyPos[SDLK_INSERT] = {32, 4, 2, 2};
    keyPos[SDLK_HOME] = {34, 4, 2, 2};
    keyPos[SDLK_PAGEUP] = {36, 4, 2, 2};
    
    keyPos[SDLK_DELETE] = {32, 6, 2, 2};
    keyPos[SDLK_END] = {34, 6, 2, 2};
    keyPos[SDLK_PAGEDOWN] = {36, 6, 2, 2};
    
    keyPos[SDLK_UP] = {34, 10, 2, 2};
    
    keyPos[SDLK_LEFT] = {32, 12, 2, 2};
    keyPos[SDLK_DOWN] = {34, 12, 2, 2};
    keyPos[SDLK_RIGHT] = {36, 12, 2, 2};
    
    keyPos[SDLK_NUMLOCK] = {39, 4, 2, 2};
    keyPos[SDLK_KP_DIVIDE] = {41, 4, 2, 2};
    keyPos[SDLK_KP_MULTIPLY] = {43, 4, 2, 2};
    keyPos[SDLK_KP_MINUS] = {45, 4, 2, 2};

    keyPos[SDLK_KP7] = {39, 6, 2, 2};
    keyPos[SDLK_KP8] = {41, 6, 2, 2};
    keyPos[SDLK_KP9] = {43, 6, 2, 2};
    keyPos[SDLK_KP_PLUS] = {45, 6, 2, 4};

    keyPos[SDLK_KP4] = {39, 8, 2, 2};
    keyPos[SDLK_KP5] = {41, 8, 2, 2};
    keyPos[SDLK_KP6] = {43, 8, 2, 2};

    keyPos[SDLK_KP1] = {39, 10, 2, 2};
    keyPos[SDLK_KP2] = {41, 10, 2, 2};
    keyPos[SDLK_KP3] = {43, 10, 2, 2};
    keyPos[SDLK_KP_ENTER] = {45, 10, 2, 4};

    keyPos[SDLK_KP0] = {39, 12, 4, 2};
    keyPos[SDLK_KP_PERIOD] = {43, 12, 2, 2};
}
