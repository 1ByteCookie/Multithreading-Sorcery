#include <iostream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

struct Player
{
	std::string		Name;
	int				Health;
	int				Mana;
};

int PrintStuff(const std::string& Name, int Number = 0)
{
	std::cout << "From Thread(" << std::this_thread::get_id() << "):\t" << Name << std::endl;
	std::cout << "From Thread(" << std::this_thread::get_id() << "):\t" << Number << std::endl;

	return 0; //exit code??
}

// absolute cringe
void PrintAttributes(std::vector<Player>* Players)
{
	std::cout << "From Thread(" << std::this_thread::get_id() << "):" << std::endl;
	for (unsigned int i = 0; i < Players->size(); i++)
	{
		std::cout << "Name:" << Players->at(i).Name << std::endl
		<< "Health:" << Players->at(i).Health << std::endl
		<< "Mana:" << Players->at(i).Mana << std::endl;
	}
}

int main()
{
	std::thread Worker(PrintStuff, "EZio", 3301);
	std::this_thread::sleep_for(1s);

	std::vector<Player> Players =
	{
		{"juan deag", 100, 0},
		{"edshot machine", 100, 0},
		{"sweaty gamer", 100, 100}
	};
	
	std::thread Worker2(PrintAttributes, &Players);
	
	Worker.join();
	Worker2.join();

	return 0;
}