#include "Explorer.hpp"

#include <locale>


int main(int argc, char* argv[])
{
	SetConsoleOutputCP(CP_UTF8);
	std::setlocale(LC_ALL, "Russian");
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
			explorer.upPath();
			break;
		case 77:
			explorer.downPath();
			break;
		case 'p':
			system("cls");
			std::wstring path;
			std::cout << "Your path: ";
			std::wcin >> path;
			explorer.setPath(path);
			break;
		}
	}

	return 0;
}