namespace ncurses {
#include <ncurses.h>
}
int main(void) {
ncurses::attr_t x;
//ncurses::wattr_on(ncurses::stdscr, x, NULL);	
ncurses::wattr_on(ncurses::stdscr, x, NULL);
ncurses::endwin();
return 0;

}
