#include <ncurses.h>
#include <ctime>
#include <cmath>
using namespace std;

void wait_ticks(int ticks) {
	clock_t start = clock();
	while ((clock() - start) < ticks)
		; //Do nothing
}

void animate_flag(int x, int y, int frame) {
	if (frame % 6 == 0 || frame < 15) {
		mvprintw(0+y,x,"                      T)))                       __,___,_                    T)))");
		mvprintw(1+y,x,"                      |                          TT  )   )                   |");
		mvprintw(2+y,x,"                     /T\\                         ||   )   )                 /T\\ ");
		mvprintw(3+y,x,"                    / L \\                        ||_-^-_-^-                / L \\ ");
	}
	else if (frame % 6 == 1) {
		mvprintw(0+y,x,"                      T)))                       ___,___,_                   T)))");
		mvprintw(1+y,x,"                      |                          TT  )    )                  |");
		mvprintw(2+y,x,"                     /T\\                         ||   )    )                /T\\ ");
		mvprintw(3+y,x,"                    / L \\                        ||-_-^-_-^                / L \\ ");
	}
	else if (frame % 6 == 2) {
		mvprintw(0+y,x,"                      T)))                       ,___,___,                   T)))");
		mvprintw(1+y,x,"                      |                          TT   )    )                 |");
		mvprintw(2+y,x,"                     /T\\                         ||    )    )               /T\\ ");
		mvprintw(3+y,x,"                    / L \\                        ||^-_-^-_-                / L \\ ");
	}
	else if (frame % 6 == 3) {
		mvprintw(0+y,x,"                      T)))                       _,___,___                   T)))");
		mvprintw(1+y,x,"                      |                          TT    )   )                 |");
		mvprintw(2+y,x,"                     /T\\                         ||)    )  )                /T\\ ");
		mvprintw(3+y,x,"                    / L \\                        ||-^-_-^-_                / L \\ ");
	}
	else if (frame % 6 == 4) {
		mvprintw(0+y,x,"                      T)))                       __,___,_                    T)))");
		mvprintw(1+y,x,"                      |                          TT )   ) )                  |");
		mvprintw(2+y,x,"                     /T\\                         ||  )   ) )                /T\\ ");
		mvprintw(3+y,x,"                    / L \\                        ||_-^-_-^-                / L \\ ");
	}
	else if (frame % 6 == 5) {
		mvprintw(0+y,x,"                      T)))                       ___,___,_                   T)))");
		mvprintw(1+y,x,"                      |                          TT  )   )                   |");
		mvprintw(2+y,x,"                     /T\\                         ||   )   )                 /T\\ ");
		mvprintw(3+y,x,"                    / L \\                        ||-_-^-_-^                / L \\ ");
	}
}

void words(int frame) {
	int x = 120-frame, y = 0;
			mvprintw(0+y,x,"__  ___  _______ .______      .__   __.  ___________    ____    ");
			mvprintw(1+y,x,"|  |/  / |   ____||   _  \\     |  \\ |  | |   ____\\   \\  /   /    ");
			mvprintw(2+y,x,"|  '  /  |  |__   |  |_)  |    |   \\|  | |  |__   \\   \\/   /     ");
			mvprintw(3+y,x,"|    <   |   __|  |      /     |  . `  | |   __|   \\_    _/      ");
			mvprintw(4+y,x,"|  .  \\  |  |____ |  |\\  \\----.|  |\\   | |  |____    |  |        ");
			mvprintw(5+y,x,"|__|\\__\\ |_______|| _| `._____||__| \\__| |_______|   |__|        ");
			mvprintw(6+y,x,"");
			mvprintw(7+y,x,"  ______     ___           _______.___________. __       _______ ");
			mvprintw(8+y,x," /      |   /   \\         /       |           ||  |     |   ____|");
			mvprintw(9+y,x,"|  ,----'  /  ^  \\       |   (----`---|  |----`|  |     |  |__   ");
			mvprintw(10+y,x,"|  |      /  /_\\  \\       \\   \\       |  |     |  |     |   __|  ");
			mvprintw(11+y,x,"|  `----./  _____  \\  .----)   |      |  |     |  `----.|  |____ ");
			mvprintw(12+y,x," \\______/__/     \\__\\ |_______/       |__|     |_______||_______|");
			mvprintw(13+y,x,"");
			mvprintw(14+y,x,"");
			mvprintw(15+y,x,"(c) 2015 William Kerney");
}

void splash() {
	int x = 0, y = 0; //Holds offsets to draw the ASCII art
	for (int i = 0; i < 120; i++) {
		timeout(10);
		int ch = getch(); //Allow them to hit a key to skip the splash screen
		if (ch != ERR) break;

		clear();
		if (i > 60) {
			words(i);
		}
		else {
			//x = 80 / (1+i);
			//x = fabs(80 * sin(i/12.56));
			y = 30 - i;
			if (i > 30) y = 0;
			animate_flag(x,y,i);
			mvprintw(4+y,x,"                   / [O] \\                       ||                       / [O] \\ ");
			mvprintw(5+y,x,"                  /   L   \\                  _.+'||'+._                  /   L   \\ ");
			mvprintw(6+y,x,"                 |____|____|             _.+'____/\\____'+._             |____|____|");
			mvprintw(7+y,x,"                   [_]|[_]              [_]_____[||]_____[_]              [_]|[_]");
			mvprintw(8+y,x,"                  .[_]|[_].             [_]_____[||]_____[_]             .[_]|[_].");
			mvprintw(9+y,x,"          ._._._._|IIIIIII|._._._._.___.====================.___._._._._.|IIIIIII|_._._._.");
			mvprintw(10+y,x,"         /|\\._./\\|/   L   \\|/._._.\\|[_] \\/   \\II/[]\\II/   \\/ [_]|/._._.\\|/   L   \\|/\\._./|\\ ");
			mvprintw(11+y,x,"        []TTTTTTT[]==[O]==[]TTTTTTTT[_] /\\_._.II_[]_II._._/\\ [_]TTTTTTTT[]==[O]==[]TTTTTTT[]");
			mvprintw(12+y,x,"        []|._._.|[]   T   []._./\\._.[_]/  [__]/  ||  \\[__]  \\[_]._./\\._.[]   T   []|._._.|[]");
			mvprintw(13+y,x,"        []IIIIIII[]IIIIIII[]IIIIIIII[_]===[__]\\._||_./[__]===[_]IIIIIIII[]IIIIIII[]IIIIIII[]");
			mvprintw(14+y,x,"       /|--------[]-------[]--------[_]---[__]-+=II=+-[__]---[_]--------[]-------[]--------|\\ ");
			mvprintw(15+y,x,"      /|| _/T\\_  ||\\\\_I_//||  _/T\\_ [_]    \\_\\_/T\\/T\\_/_/    [_] _/T\\_  ||\\\\_I_//||  _/T\\_ ||\\ ");
			mvprintw(16+y,x,"      ||| |_O_| ,/|=/_|_\\=|\\, |_O_| [_]    |_L_LT||TJ_J_|    [_] |_O_| ,/|=/_|_\\=|\\, |_O_| ||| ");
			mvprintw(17+y,x,"      ||| |_O_| |||___|___||| |_O_| [_]____[]/|||/\\|||\\[]    [_] |_O_| |||___|___||| |_O_| ||| ");
			mvprintw(18+y,x,"      [_]\\IIIII/[_]\\IIIII/[_]\\IIIII/[_]IIII[]\\==/%%\\==/[]IIII[_]\\IIIII/[_]\\IIIII/[_]\\IIIII/[_] ");
			mvprintw(19+y,x,"      [_].\\_I_/.[_].\\_I_/.[_].\\_I_/.[_]\\II/[].\\_\\%%/_/.[]\\II/[_].\\_I_/.[_].\\_I_/.[_].\\_I_/.[_] ");
			mvprintw(20+y,x,"      L_J./   \\.L_J./   \\.L_J./   \\.L_JI  I[]./      \\.[]I  IL_J./   \\.L_J./   \\.L_J./   \\.L_J ");
			mvprintw(21+y,x,"      L_J|     |L_J|     |L_J|     |L_J|  |[]|        |[]|  |L_J|     |L_J|     |L_J|     |L_J ");
			mvprintw(22+y,x,"      L_J|_____|L_J|_____|L_J|_____|L_J|__|[]|        |[]|__|L_J|_____|L_J|_____|L_J|_____|L_J ");
		}
		refresh();
		wait_ticks(0.05 * CLOCKS_PER_SEC);
	}
	clear();
}
