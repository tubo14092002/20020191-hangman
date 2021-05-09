#include "TextObject.h"


TextObject::TextObject() {
	
}
TextObject::~TextObject() {
	;
}
void TextObject::SetColor(const int& type) {
	if (type == RED_TEXT) {
		SDL_Color color = { 140,11,17 };
		text_color_ = color;
	}
	else if (type == WHITE_TEXT) {
		SDL_Color color = { 255,255,255 };
		text_color_ = color;
	}
	else {
		SDL_Color color = { 0,0,0 };
		text_color_ = color;
	}
}

/*void TextObject::ChangeWord(const std::string& str_val_, std::string& str_val2_, char& char_val_, int& enroll_val_) {
	std::string a = str_val_;
	std::string b = str_val2_;
	int c = a.size();
	for (int i = 0; i < a.size(); i++) {
		if (char_val_ == a[i]) {
			b[i] = char_val_;
			c--;
		}
	} 
	
	if (c == a.size()) {
		enroll_val_++;
	}
	else
	{
		str_val2_ = b;
	}
}*/

void TextObject::CreateGameText(TTF_Font* font, SDL_Surface* des) {
	p_object_ = TTF_RenderText_Solid(font, str_val_.c_str(), text_color_);
	Show(des);

}