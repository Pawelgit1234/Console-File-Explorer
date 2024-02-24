#include "Explorer.hpp"

#include <conio.h>


int main(int argc, char* argv[])
{
	cfe::Explorer explorer;

	while (true)
	{
		switch (_getch())
		{
		case 72:
			explorer.up();
			break;
		case 80:
			explorer.down();
			break;
		case 75:
			explorer.upFolder();
			break;
		case 77:
			explorer.downFolder();
			break;
		case 'p':
			system("cls");
			std::string path;
			std::cout << "Your path: ";
			std::cin >> path;
			explorer.setPath(path);
			break;
		}
	}

	return 0;
}