#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ncurses.h>
#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

#define MENU_WIDTH 40
#define MENU_HEIGHT 15
#define EXIT_KEY_Q 'q'
#define EXIT_KEY_ESC 27
#define ENTER_KEY 10

int startx = 0;
int starty = 0;

std::vector<std::string> choices;
int n_choices = 0;

std::vector<std::string> get_directory_contents(const fs::path &dir) {
    std::vector<std::string> entries;
    for (auto const& dir_entry : fs::directory_iterator(dir)) {
        entries.push_back(dir_entry.path().filename().string());
    }
    return entries;
}

void print_menu(WINDOW *menu_win, int highlight) {
    int x = 2, y = 2;
    box(menu_win, 0, 0);
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
        }
        ++y;
    }
    wrefresh(menu_win);
}

int main() {
    choices = get_directory_contents(fs::current_path());
    n_choices = static_cast<int>(choices.size());

    if (n_choices == 0) {
        choices.push_back("(empty directory)");
        n_choices = 1;
    }

    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    startx = (80 - MENU_WIDTH) / 2;
    starty = (24 - MENU_HEIGHT) / 2;

    menu_win = newwin(MENU_HEIGHT, MENU_WIDTH, starty, startx);
    keypad(menu_win, TRUE);

    mvprintw(0, 0, "CWD: %s", fs::current_path().c_str());
    mvprintw(1, 0, "Use arrow keys to navigate, Enter to select, q to quit");
    refresh();
    print_menu(menu_win, highlight);

    while (1) {
        c = wgetch(menu_win);
        switch (c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case EXIT_KEY_Q:
            case EXIT_KEY_ESC:
                endwin();
                return 0;
            case ENTER_KEY:
                choice = highlight;
                break;
            default:
                break;
        }
        print_menu(menu_win, highlight);
        if (choice != 0)
            break;
    }

    endwin();
    printf("You chose: %s\n", choices[choice - 1].c_str());
    return 0;
}