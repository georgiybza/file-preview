#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

// Keep in mind, https://xn--rpa.cc/irl/term.html

#define TERMINAL_WIDTH 80
#define TERMINAL_HEIGHT 24  
#define PATH_MAX 80
#define EXIT_KEY_Q 113
#define EXIT_KEY_ESC

int startx = 0;
int starty = 0;

char *choices[] = { // Contents of CWD
    /*
     * I think the logic should work like this:
     * 1. Obtain files / folders in CWD
     * 2. Print the files / folders into choices
    */
    
};


void get_and_print_cwd() {
    char *getcwd(char *buf, size_t size);
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
   }

}

int n_choices = sizeof(choices) / sizeof(char *); // Essentially, number of contents in the directory

void print_menu(WINDOW *menu_win, int highlight);

int main() {
    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();
    clear();
    noecho();
    cbreak(); /* Line buffering disabled. pass on everything */
    startx = (80 - TERMINAL_WIDTH) / 2;
    starty = (24 - TERMINAL_HEIGHT) / 2;

    menu_win = newwin(TERMINAL_HEIGHT, TERMINAL_WIDTH, startx, starty);
    keypad(menu_win, TRUE);
    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    print_menu(menu_win, highlight);
    while (1) { // Initiate character input loop
        c = wgetch(menu_win);
        switch(c) {
            case KEY_UP:
                if (highlight == 1) {
                    highlight = n_choices;
                } else {
                    --highlight;
                }
                break;
            case KEY_DOWN:
                if (highlight = n_choices) {
                    highlight = 1;
                } else {
                    ++highlight;
                }
                break;
            //case KEY_LEFT: (Go up a directory)
            //case KEY_RIGHT: (Go further in directory)
            case EXIT_KEY_Q:
                mvprintw(0, 0, "Exiting Program...");
                refresh();
                sleep(2);
                endwin();
            case 10:
                choice = highlight;
                break;

            default:
                mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                refresh();
                break;
        }
        print_menu(menu_win, highlight);
        if (choice != 0) {
            break;
        }
    }
    mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	clrtoeol();
	refresh();
	endwin();
	return 0;
}

void print_menu(WINDOW *menu_win, int highlight) { //  This is what "draws" the contents of the directory



}
