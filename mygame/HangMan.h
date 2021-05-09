#ifndef HANG_MAN_H_
#define HANG_MAM_H_
#include "TextObject.h"
 
class HangMan : public  TextObject
{
public:
	HangMan();
	~HangMan();
	char Work(SDL_Event event);
	void GetWord(std::string &text, std::string &text2, char& x, int& y) { str_val_ = text; str_val2_ = text2; char_val_ = x; enroll_val_ = y; }

	void ChangeWord(const std::string& str_val, std::string& str_val2_, char& char_val_, int& enroll_val_);
	void Change();
	
	void Char(SDL_Event event);
	bool Thecharleft(std::string word, std::string guessword);
protected:
	std::string  my_val_;
	std::string str_val2_;
    char char_val_;
	unsigned int enroll_val_;

};

#endif // !HANG_MAN_H_
