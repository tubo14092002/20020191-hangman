#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include <Windows.h>
#include <String>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#undef main
const int SCREEN_WIDTH = 910;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int MAX_BAD_GUESS = 7;

const std::string WORD_LIST[] = {
    "angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame",
        "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house",
        "island", "jewel",
        "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun",
        "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth",
        "town", "train", "tray", "tree", "trousers",
        "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm" };

const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(std::string);

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Surface* g_menu = NULL;
static SDL_Event g_event;

static Mix_Chunk* g_soundbg;
static Mix_Chunk* g_hang;
static Mix_Chunk* g_laugh;
static Mix_Chunk* g_scream;
static Mix_Chunk* g_win;
static char char_val; 
namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	SDL_Surface* LoadImage2(std::string file_path);

	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);

    int ShowMenu(SDL_Surface* des, TTF_Font* font, Mix_Chunk* g_soundmenu);
    int ENDING(SDL_Surface* des, TTF_Font* font, std::string word);
    int BADEND(SDL_Surface* des, TTF_Font* font, std::string word);

    bool CheckRect(const int& x,const int& y,const SDL_Rect& rect);
	void CleanUp();
}
#endif // !COMMON_FUNCTION_H_

 