/*Реализовать игру в 21 */
#include <iostream>
#include <time.h>

using namespace std;
class TwentyOne
{
public:
	char kard[4][9] = { {'6','7','8','9','10','V','D','K','T'},{ '6','7','8','9','10','V','D','K','T' },{ '6','7','8','9','10','V','D','K','T' },{ '6','7','8','9','10','V','D','K','T' } };
	int score_kard[9] = { 6,7,8,9,10,2,3,4,11 };
	void put_kard_pc();
	void put_kard_gamer();
 };
void TwentyOne::put_kard_pc()
{
	srand(time(0));
	int kard;
	int score;
	int mast;
	mast = rand() % 4;
	kard = rand() % 9;

}
