#include <Controller.h>

void Controller::run()
{
	

	BoardManager board{};

	// loop that runs on each level and manage the game.
	while (true) {

		if (!board.read_level()) { // if player finished all level.
			//end_game_announcement(WINNER);
			break;
		}
	}
}