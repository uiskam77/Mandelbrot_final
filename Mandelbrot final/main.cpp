#include "Application.h"

#include <memory> // dynamiczne zarz¹dzanie pamiêci¹

int main(int argc, char* argv[])
{
	auto app = std::make_unique<Application>();
	app->run();
	return 0;
}