#include "Application.h"

#include <memory> // dynamiczne zarz�dzanie pami�ci�

int main(int argc, char* argv[])
{
	auto app = std::make_unique<Application>();
	app->run();
	return 0;
}