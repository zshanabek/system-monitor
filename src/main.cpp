#include <stdio.h>

#include "../includes/Graphic.hpp"

#include <iostream>

#include "../includes/monitor.hpp"
#include "../includes/Hostname.hpp"
#include "../includes/OSInfo.hpp"
#include "../includes/RAM.hpp"
#include "../includes/Datetime.hpp"
#include "../includes/CPU.hpp"
#include "../includes/Module.hpp"
#include "../includes/Network.hpp"


bool show_time = true;
bool show_cpu = true;
bool show_os = true;
bool show_host = true;
bool show_network = true;
unsigned int update = 0;

unsigned int cat = 0;

void drawcat()
{
	cat = (cat == 3) ? 0 : cat + 1;
	attron(COLOR_PAIR(1));
	rectangle(32, 0, 40, 50);
	attroff(COLOR_PAIR(1));
	std::string array[50];

	int i;
	i = 0;

	int a;
	a = 33;
	if (cat == 0)
	{
		array[0] = "  )\\._.,--....,'``.       ";
		array[1] = " /,   _.. \\   _\\  (`._ ,.";
		array[2] = "`._.-(,_..'--(,_..'`-.;.'  ";
		array[3] = "                           ";

		while(i < 4)
		{
			mvprintw(a + i, 2, array[i].c_str());
			i++;
		}
	}
	else if (cat == 1)
	{
		array[0] = "  |\\      _,,,---,,_      ";
		array[1] = "  /,`.-'`'    -.  ;-;;,_   ";
		array[2] = " |,4-  ) )-,_..;\\ (  `'-' ";
		array[3] = "'---''(_/--'  `-'\\_)      ";
		i = 0;
		while(i < 4)
		{
			mvprintw(a + i, 2, array[i].c_str());
			i++;
		}
	}
	else if (cat == 2)
	{
		array[0] = "  |\\      _,,,,--,,_      ";
		array[1] = "  /,`.-'`'    -,  ;-;,     ";
		array[2] = " |,4-  ) ),,__ ) /;  ;;    ";
		array[3] = "'---''(.'--'  (.'`.) `'    ";
		i = 0;
		while(i < 4)
		{
			mvprintw(a + i, 2, array[i].c_str());
			i++;
		}
	}
	else if (cat == 3)
	{
		array[0] = "  |\\      _,,,,--,,_      ";
		array[1] = "  /,`.-'`'    -,  \\-;,    ";
		array[2] = " |,4-  ) ),,__ ,\\ (  ;;   ";
		array[3] = "'---''(.'--'  `-'`.)`'     ";
		i = 0;
		while(i < 4)
		{
			mvprintw(a + i, 2, array[i].c_str());
			i++;
		}
	}
}

void graphical()
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
	{
		//printf("Error: %s\n", SDL_GetError());
		return ;
	}
	// Setup window
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	SDL_Window* window = SDL_CreateWindow("ft_gkrellm", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
	SDL_GLContext gl_context = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(1); // Enable vsync

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
	ImGui_ImplOpenGL2_Init();
	ImGui::StyleColorsDark();
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	Module m = Module();
	Hostname hname = Hostname();
	OSInfo os = OSInfo();
	RAM ram = RAM();
	Datetime datetime = Datetime();
	CPU cpu = CPU();
	Network net = Network();

	m.pushback(&hname);
	m.pushback(&datetime);
	m.pushback(&os);
	m.pushback(&ram);
	m.pushback(&cpu);
	m.pushback(&net);


	//bool showtime = true;

	// Main loop
	bool done = false;
	while (!done)
	{
		m.updateData();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT)
				done = true;
		}

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplSDL2_NewFrame(window);
		ImGui::NewFrame();
		m.showGraphicData();
		{
			ImGui::Begin("Settings!");                          // Create a window called "Hello, world!" and append into it.
			ImGui::Checkbox("Time", &show_time);
			ImGui::Checkbox("CPU", &show_cpu);
			ImGui::ColorEdit3("Background color", (float*)&clear_color); // Edit 3 floats representing a color
			ImGui::End();
		}


		ImGui::Render();
		glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
		SDL_GL_SwapWindow(window);
	}

	// Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void terminal()
{
	int		command;
	bool	exit = false;

	initscr();
	Module m = Module();
	Hostname hname = Hostname();
	OSInfo os = OSInfo();
	RAM ram = RAM();
	Datetime datetime = Datetime();
	CPU cpu = CPU();
	Network net = Network();

	m.pushback(&hname);
	m.pushback(&datetime);
	m.pushback(&os);
	m.pushback(&ram);
	m.pushback(&cpu);
	m.pushback(&net);
	int frametime = 1000 / 200;

	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	nodelay(stdscr, true);
	while (!exit)
	{
		clock_t time = clock();
		command = getch();
		if (27 == command)
			exit = true;
		m.updateData();
		m.showData();
		drawcat();
		refresh();
		while (clock() < time + frametime)
			;

	}

	endwin();
}


int main()
{
	std::string choice;
	std::cout << "n for ncurses\n";
	std::cout << "s for SDL\n";
	std::cout << "Enter your choice: ";
	std::getline(std::cin, choice);
	if (choice == "n")
		terminal();
	else
		graphical();
	return 0;
}
