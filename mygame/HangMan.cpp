#include "HangMan.h"
HangMan::HangMan() {
	
}
HangMan::~HangMan() {
	
}
bool HangMan::Thecharleft(std::string word, std::string guessword) {
	int a = 0;
	for (int i = 0; i < guessword.size(); i++) {

		
		if (guessword[i] == '-') {
			a++;
		}
	}
	if (a <= 1) {
		return false;
	}
	else {
		int b, c;
		for (int i = 0; i < guessword.size(); i++) {
			for (int j = i + 1; j < guessword.size(); j++) {
				if (guessword[i] == '-' && guessword[j] == '-' && word[i] != word[j]) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	
	
}
char HangMan::Work(SDL_Event  event) {
	char a = '-';
	if (event.type == SDL_KEYDOWN) {
		
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			a= 'a';
			Mix_PlayChannel(-1, g_hang, 0);
			break;
		case SDLK_b:
			a = 'b';
			Mix_PlayChannel(-1, g_hang, 0);
			break;
		case SDLK_c:
			a = 'c';
			break;
		case SDLK_d:
			a = 'd';
			break;
		case SDLK_e:
			a = 'e';
			break;
		case SDLK_f:
			a = 'f';
			break;
		case SDLK_g:
			a = 'g';
			break;
		case SDLK_h:
			a = 'h';
			break;
		case SDLK_j:
			a = 'j';
			break;
		case SDLK_k:
			a = 'k';
			break;
		case SDLK_l:
		    a = 'l';
			break;
		case SDLK_m:
			a = 'm';
			break;
		case SDLK_n:
			a = 'n';
			break;
		case SDLK_o:
			a = 'o';
			break;
		case SDLK_i:
			a = 'i';
			break;
		case SDLK_q:
			a = 'q';
			break;
		case SDLK_p:
			a = 'p';
			break;
		case SDLK_r:
			a = 'r';
			break;
		case SDLK_s:
			a = 's';
			break;
		case SDLK_t:
			a = 't';
			break;
		case SDLK_u:
			a = 'u';
			break;
		case SDLK_v:
			a = 'v';
			break;
		case SDLK_w:
			a = 'w';
			break;
		case SDLK_x:
			a = 'x';
			break;
		case SDLK_y:
			a = 'y';
			break;
		case SDLK_z:;
			a = 'z';
			break;
		default:
			a = '-';
			break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		/*switch (event.key.keysym.sym)
		{
		case SDLK_a:
			a = '-';
		default:
			break;
		}*/
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN) {

	}
	else if (event.type == SDL_MOUSEBUTTONUP) {

	}
	
	return a;
}
void HangMan::Change() {

}