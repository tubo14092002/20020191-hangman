#include "commonfunc.h"
#include "MainObject.h"
#include"TextObject.h"
#include"HangMan.h"
#include <cstdlib>
#include <ctime>
#include<vector>

TTF_Font* g_font_text = NULL;
TTF_Font* g_menutext = NULL;
bool Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return false;
    }
    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (g_screen == NULL)
    {
        return false;
    }
    if (TTF_Init() == -1) {
        return false;
    }
    g_font_text = TTF_OpenFont("stocky.ttf", 40);
    if (g_font_text == NULL) {
        return false;
    }
    g_menutext = TTF_OpenFont("stocky.ttf", 60);
    if (g_menutext == NULL) {
        return false;
    }
    if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 1, 8192) == -1) {
        return false;
    }
    g_win = Mix_LoadWAV("winning sound.wav");
    g_soundbg = Mix_LoadWAV("background.wav"); 
    g_scream = Mix_LoadWAV("SCREAM3.wav");
    g_hang = Mix_LoadWAV("SPLAT2.wav");
    g_laugh = Mix_LoadWAV("laughhowl1.wav");
    if (g_soundbg == NULL || g_laugh == NULL || g_scream == NULL || g_hang == NULL||g_win == NULL) {
        return false;
    }
    return true;
}

std::string ChooseWord() {
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
}

std::string giftforyou(std::string guessedWord, std::string word) {
    int a;
    char z ;
    srand(time(0));
    do {
        a = rand() % word.length();
      
    } while (guessedWord[a] != '-');
    
    for (int i = 0; i < word.size(); i++) {
        if (word[a] == word[i]) {
            guessedWord[i] = word[i];
        }
    }
    if (guessedWord == word) {

        for (int i = 0; i < word.size(); i++) {
            if (word[a] == word[i]) {
                guessedWord[i] = '-';
            }
        }
    }
    return guessedWord;
}
int main(int arc, char* argv[])
{
   std::vector<int> loopplay;
   int c = 1; 
   
   
  for(int i = 0; i<= loopplay.size();i++){
      srand(time(0));
     
      if (Init() == false)
          return 0;

     
      std::string word = ChooseWord();
      std::string val_welcome("Welcome to thriller night!");
      std::string unknown_val_ = std::string(word.length(), '-');
      std::string point ="You point:";
      std::string trueword = "Right word is: " + word;


      int wrong = MAX_BAD_GUESS;
      int enroll = 0;
      char z = '-';

      g_bkground = SDLCommonFunc::LoadImage("truebg.png");
      if (g_bkground == NULL)
      {
          return 0;
      }
      TextObject mark_game;
      mark_game.SetColor(TextObject::RED_TEXT);

      HangMan game;
      game.SetColor(TextObject::RED_TEXT);

      HangMan truewordis;
      truewordis.SetColor(TextObject::RED_TEXT);

      MainObject human_object;
      human_object.SetRect(65, 140);
      bool ret = human_object.LoadImg("case7.png");
      if (!ret) {
          return 0;
      }
      bool check = false;

      TextObject mypoint;
      mypoint.SetColor(TextObject::RED_TEXT);
      int y = 0;

      
      Mix_PlayChannel(-1, g_soundbg, 0);
      
       bool is_quit = false;

      
       int ret_menu = SDLCommonFunc::ShowMenu(g_screen, g_menutext,g_soundbg);
       if (ret_menu == 1) {
           is_quit = true;
           break;
           }
       
      
       while (!is_quit)
       {
           while (SDL_PollEvent(&g_event))
           {
               if (g_event.type == SDL_QUIT)
               {
                   is_quit = true;
                   break;
               }

               game.GetWord(word, unknown_val_, z, enroll);
               z = game.HangMan::Work(g_event);


               if (wrong == 0||word == unknown_val_) {
                   if (g_event.type == SDL_KEYDOWN) {
                       if (g_event.key.keysym.sym == SDLK_SPACE) {
                           is_quit = true;
                           Mix_FreeChunk(g_laugh);

                       }
                   }
               }

           }

           SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
           human_object.Show(g_screen);

           point = std::to_string(wrong) + " TURN LEFT";

           game.SetText(unknown_val_);
           game.SetRect(250, 100);
           game.CreateGameText(g_font_text, g_screen);


           mark_game.SetText(val_welcome);
           mark_game.SetRect(250, 10);
           mark_game.CreateGameText(g_font_text, g_screen);




           if (z != '-') {
               do {
                   int a = 0;

                   for (int i = 0; i < word.size(); i++) {
                       
                       if (z == word[i]) {
                           unknown_val_[i] = word[i];
                           a++;
                       }
                   }
                   bool giftornot = game.HangMan::Thecharleft(word, unknown_val_);
                   if ((wrong == 5 || wrong == 3)&&giftornot==true) {
                       unknown_val_ = giftforyou(unknown_val_, word);
                        }

                   z = '-';
                   if (a == 0) {
                       wrong--;
                       Mix_PlayChannel(-1, g_hang, 0);
                       check = true;
                   }





               } while (check = false);



               if (wrong < 0)
                   wrong++;


               switch (wrong)
               {
               case 0:
                   Mix_PlayChannel(-1, g_scream, 0);
                   Mix_PlayChannel(-1, g_laugh, 0);

                  
                   mark_game.SetText(val_welcome);
                   mark_game.SetRect(250, 10);
                   mark_game.CreateGameText(g_font_text, g_screen);
                   break;

               case 1:
                   human_object.SetRect(125, 133);
                   human_object.LoadImg("case6.png");

                   break;
               case 2:
                   human_object.SetRect(125, 133);
                   human_object.LoadImg("case5.png");
                   break;
               case 3:
                   human_object.SetRect(125, 133);
                   human_object.LoadImg("case4.png");
                   break;
               case 4:
                   human_object.SetRect(125, 133);
                   human_object.LoadImg("case3.png");
                   break;
               case 5:
                   human_object.SetRect(125, 133);
                   human_object.LoadImg("case2.png");
                   break;
               case 6:
                   human_object.SetRect(125, 133);
                   human_object.LoadImg("case1.png");
                   break;

               default:
                   break;
               }


           }

           int yourpoint = wrong * 100;
           if (wrong == 0) {
               unknown_val_ = "you can't save him";
               val_welcome = "press [----space----] to quit";
               human_object.SetRect(5, 140);
               human_object.LoadImg("trueend.png");

               truewordis.SetText(trueword);
               truewordis.SetRect(370, 150);
               truewordis.CreateGameText(g_font_text, g_screen);

               point = "Your Point : " + std::to_string(yourpoint);
               
               
              
               loopplay.push_back(c);
               if (is_quit == true) {
                   SDLCommonFunc::CleanUp();
               }
              
               
           }

           if (unknown_val_ == word) {

               unknown_val_ = "You win!!!  The word is: " + word;
               val_welcome = "press [----SPACE----] to quit";
               

               truewordis.SetText(trueword);
               truewordis.SetRect(370, 150);
               truewordis.CreateGameText(g_font_text, g_screen);
               human_object.SetRect(40, 70);
               human_object.LoadImg("winnerman.png");

               truewordis.SetText(trueword);
               truewordis.SetRect(370, 150);
               truewordis.CreateGameText(g_font_text, g_screen);
               
               Mix_PlayChannel(-1,g_win, 0);
               loopplay.push_back(c);
              
               point = "Your Point : " + std::to_string(yourpoint);
               if (is_quit == true) {
                   SDLCommonFunc::CleanUp();
               }
           }
           mypoint.SetText(point);
           mypoint.SetRect(400, 450);
           mypoint.CreateGameText(g_font_text, g_screen);


           if (SDL_Flip(g_screen) == -1)
               return 0;
           
       }
       
       
   }

   SDLCommonFunc::CleanUp();
   SDL_Quit();
    

    
    return 1;
}