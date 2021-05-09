#include"MainObject.h"
MainObject::MainObject() {
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
	x_val_ = 0;
	y_val_ = 0;
}
MainObject::~MainObject() {

}
void MainObject::HandleInputAction(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		MainObject* main_ = new MainObject();
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			main_ -> LoadImg("bg2.png");
			break;
		case SDLK_DOWN:
			main_->LoadImg("bkground");
			break;
		default:
			break;
		}
	}
	else if (event.type == SDLK_UP) {

	}
	else if (event.type == SDL_MOUSEBUTTONDOWN) {
		/*if (event.button.button == SDL_BUTTON_LEFT) {
			if (p_object_ != NULL) {
				SDL_FreeSurface(p_object_);
			}
			bool p_object_ = LoadImg("bg2.png");
		}*/
	}
	else if (event.type == SDL_MOUSEBUTTONUP) {

	}
}