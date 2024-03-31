#pragma once
char getkey_char(bool alpha, bool shift);
void draw_menu(char menu[12][10], int language, int cursor);
void draw_project(uint16_t* project);
void save_project(uint16_t* project);
void set_color(int* color_r, int* color_g, int* color_b, int language);
bool text_input(char title[27], int language, char *text);
void move_cursor(int *cursor_pos, int *key_in_a_row, int wait_time);