#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include"BaseObject.h"
#include "commonfunc.h"
#define WITDH_MAIN_OBJECT 370
#define HEIGHT_MAIN_OBJECT 364
class MainObject :public  BaseObject {
public:
	MainObject();
	~MainObject();
	void HandleInputAction(SDL_Event event);
	void HandleMove();
	

protected:
	int x_val_;
	int y_val_;
 };


#endif // !MAIN_OBJECT_H_

