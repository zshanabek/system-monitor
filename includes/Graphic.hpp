#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP
# include <iostream>
# include <string>
# include "IMonitorDisplay.hpp"

#include "../includes/imgui.h"
#include "../includes/imgui_impl_sdl.h"
#include "../includes/imgui_impl_opengl2.h"
# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2.framework/Headers/SDL_opengl.h"
# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"

extern bool show_time;
extern bool show_cpu;
extern bool show_os;
extern bool show_host;
extern bool show_network;
extern unsigned int update;


class Graphic : public IMonitorDisplay
{
	public:
		Graphic ();
		~Graphic ();
		Graphic (Graphic const & copy);
		Graphic & operator=(Graphic const & copy);

		virtual void showGraphicData();
	private:

};

#endif