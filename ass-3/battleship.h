#include <string>
#include <fstream>
using namespace std;

class battleship
{
public:
	battleship(ifstream&);
	char fire(char, int);
	char isOver() const;
	string getGrid() const;
	int remaining() const;
private:
	static const int ROWS = 10;
	static const int COLUMNS = 10;
	char playerGrid[ROWS][COLUMNS];
	bool solutionGrid[ROWS][COLUMNS];
	int maxMoves;
	int movesMade;
};