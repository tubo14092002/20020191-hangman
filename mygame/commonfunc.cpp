#include "commonfunc.h"
#include "TextObject.h"
bool SDLCommonFunc::CheckRect(const int& x, const int& y,const SDL_Rect& rect) {
    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) {
        return true;
    }
    return false;
}
int SDLCommonFunc::ShowMenu(SDL_Surface* des, TTF_Font* font, Mix_Chunk * g_soundmenu) {
    g_menu = LoadImage("menu.png");
    if (g_menu == NULL) {
        return 1;
    }

    if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 1, 8192) == -1) {
        return false;
    }
    Mix_PlayChannel(-1, g_soundmenu, 0);
    
    const int kMenu_item = 2;
    SDL_Rect pos_arr[kMenu_item];
    pos_arr[0].x = 280;
    pos_arr[0].y = 300;

    pos_arr[1].x = 280;
    pos_arr[1].y = 400;

    TextObject text_menu[kMenu_item];
    text_menu[0].SetText("Play game");
    text_menu[0].SetColor(TextObject::RED_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("Exit");
    text_menu[1].SetColor(TextObject::RED_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    bool select[kMenu_item] = { 0,0 };
    int xm = 0;
    int ym = 0;

    SDL_Event m_event;
    while (true) {
        SDLCommonFunc::ApplySurface(g_menu, des, 0, 0);
        for (int i = 0; i < kMenu_item; i++) {
            text_menu[i].CreateGameText(font, des);
        }
        while (SDL_PollEvent(& m_event)) {
           switch (m_event.type)
            {
            case SDL_QUIT:
                return 1;
            /*case SDL_MOUSEMOTION:
            {
                xm = m_event.motion.x;
                ym = m_event.motion.y;
                for (int i = 0; i < kMenu_item; i++) {
                    if (CheckRect(xm, ym, text_menu[i].GetRect())) {
                        if (select[i] == false) {
                            select[i] = 1;
                            text_menu[i].SetColor(TextObject::RED_TEXT);
                        }
                    }
                    else {
                        if (select[i] == true) {
                            select[i] = 0;
                            text_menu[i].SetColor(TextObject::WHITE_TEXT);
                        }
                    }
                }
            }
            break;*/
            case SDL_MOUSEBUTTONDOWN:
            {
                xm = m_event.button.x;
                ym = m_event.button.y;
                for (int i = 0; i < kMenu_item; i++) {
                    if (CheckRect(xm, ym, text_menu[i].GetRect())) {
                        return i;
                    }
                }

            }
            break;
            case SDL_KEYDOWN:
                if (m_event.key.keysym.sym == SDLK_ESCAPE) {
                    return 1;
                }
                break;
            default:
                break;
            }
            SDL_Flip(des);
        }
        
    }
    
    return 1;
}
/*int SDLCommonFunc::BADEND(SDL_Surface* des, TTF_Font* font, std::string word) {
    g_menu = LoadImage("ending.png");
    if (g_menu == NULL) {
        return 1;
    }
    const int kMenu_item = 2;
    SDL_Rect pos_arr[kMenu_item];
    pos_arr[0].x = 280;
    pos_arr[0].y = 300;

    pos_arr[1].x = 280;
    pos_arr[1].y = 400;
    TextObject keyword;
    
    keyword.SetText(word);
    keyword.SetColor(TextObject::RED_TEXT);
    keyword.SetRect(280, 200);

    TextObject text_menu[kMenu_item];
    text_menu[0].SetText("Try again");
    text_menu[0].SetColor(TextObject::RED_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("Exit");
    text_menu[1].SetColor(TextObject::RED_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    bool select[kMenu_item] = { 0,0 };
    int xm = 0;
    int ym = 0;

    SDL_Event m_event;
    while (true) {
        SDLCommonFunc::ApplySurface(g_menu, des, 0, 0);
        for (int i = 0; i < kMenu_item; i++) {
            text_menu[i].CreateGameText(font, des);
        }
        while (SDL_PollEvent(&m_event)) {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return 1;
            case SDL_MOUSEMOTION:
            {
                xm = m_event.motion.x;
                ym = m_event.motion.y;
                for (int i = 0; i < kMenu_item; i++) {
                    if (CheckRect(xm, ym, text_menu[i].GetRect())) {
                        if (select[i] == false) {
                            select[i] = 1;
                            text_menu[i].SetColor(TextObject::RED_TEXT);
                        }
                    }
                    else {
                        if (select[i] == true) {
                            select[i] = 0;
                            text_menu[i].SetColor(TextObject::WHITE_TEXT);
                        }
                    }
                }
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
            {
                xm = m_event.button.x;
                ym = m_event.button.y;
                for (int i = 0; i < kMenu_item; i++) {
                    if (CheckRect(xm, ym, text_menu[i].GetRect())) {
                        return i;
                    }
                }

            }
            break;
            case SDL_KEYDOWN:
                if (m_event.key.keysym.sym == SDLK_ESCAPE) {
                    return 1;
                }
                break;
            default:
                break;
            }
            SDL_Flip(des);
        }

    }

    return 1;
}*/
int SDLCommonFunc::ENDING (SDL_Surface* des, TTF_Font* font, std::string word) {
    g_menu = LoadImage("ending.png");
    if (g_menu == NULL) {
        return 1;
    }
    const int kMenu_item = 2;
    SDL_Rect pos_arr[kMenu_item];
    pos_arr[0].x = 280;
    pos_arr[0].y = 300;

    pos_arr[1].x = 280;
    pos_arr[1].y = 400;
    TextObject keyword;

    keyword.SetText(word);
    keyword.SetColor(TextObject::RED_TEXT);
    keyword.SetRect(280, 200);

    TextObject text_menu[kMenu_item];
    text_menu[0].SetText("Try again");
    text_menu[0].SetColor(TextObject::RED_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("Exit");
    text_menu[1].SetColor(TextObject::RED_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    bool select[kMenu_item] = { 0,0 };
    int xm = 0;
    int ym = 0;

    SDL_Event m_event;
    while (true) {
        SDLCommonFunc::ApplySurface(g_menu, des, 0, 0);
        for (int i = 0; i < kMenu_item; i++) {
            text_menu[i].CreateGameText(font, des);
        }
        while (SDL_PollEvent(&m_event)) {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return 1;
                /* case SDL_MOUSEMOTION:
                 {
                     xm = m_event.motion.x;
                     ym = m_event.motion.y;
                     for (int i = 0; i < kMenu_item; i++) {
                         if (CheckRect(xm, ym, text_menu[i].GetRect())) {
                             if (select[i] == false) {
                                 select[i] = 1;
                                 text_menu[i].SetColor(TextObject::RED_TEXT);
                             }
                         }
                         else {
                             if (select[i] == true) {
                                 select[i] = 0;
                                 text_menu[i].SetColor(TextObject::WHITE_TEXT);
                             }
                         }
                     }
                 }
                 break;*/
            case SDL_MOUSEBUTTONDOWN:
            {
                xm = m_event.button.x;
                ym = m_event.button.y;
                for (int i = 0; i < kMenu_item; i++) {
                    if (CheckRect(xm, ym, text_menu[i].GetRect())) {
                        return i;
                    }
                }

            }
            break;
            case SDL_KEYDOWN:
                if (m_event.key.keysym.sym == SDLK_ESCAPE) {
                    return 1;
                }
                break;
            default:
                break;
            }
            SDL_Flip(des);
        }

    }

    return 1;
}

SDL_Surface* SDLCommonFunc::LoadImage(std::string file_path)
{
    SDL_Surface* load_image = NULL;
    SDL_Surface* optimize_image = NULL;
    load_image = IMG_Load(file_path.c_str());
    if (load_image != NULL)
    {
        optimize_image = SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);
        /*if (optimize_image != NULL)
        {
            UINT32 color_key = SDL_MapRGB(optimize_image->format, 255, 255,255);
            SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
        }*/
    }
    return optimize_image;
}

SDL_Surface* SDLCommonFunc::LoadImage2(std::string file_path)
{
    SDL_Surface* load_image = NULL;
    SDL_Surface* optimize_image = NULL;
    load_image = IMG_Load(file_path.c_str());
    if (load_image != NULL)
    {
        optimize_image = SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);
        if (optimize_image != NULL)
        {
            UINT32 color_key = SDL_MapRGB(optimize_image->format, 255, 0, 0);
            SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
        }
    }
    return optimize_image;
}
SDL_Rect SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);

    return offset;
}
void SDLCommonFunc::CleanUp()
{
    SDL_FreeSurface(g_screen);
    SDL_FreeSurface(g_bkground);
    
}

