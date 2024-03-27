#include <gint/keyboard.h>
#include <gint/display.h>

char getkey_char(bool alpha, bool shift){
  if(!shift && !alpha){
    if(keydown(KEY_0)) return '0';
    if(keydown(KEY_1)) return '1';
    if(keydown(KEY_2)) return '2';
    if(keydown(KEY_3)) return '3';
    if(keydown(KEY_4)) return '4';
    if(keydown(KEY_5)) return '5';
    if(keydown(KEY_6)) return '6';
    if(keydown(KEY_7)) return '7';
    if(keydown(KEY_8)) return '8';
    if(keydown(KEY_9)) return '9';
    if(keydown(KEY_DOT)) return '.';
  if(keydown(KEY_MUL)) return '*';
  if(keydown(KEY_PLUS)) return '+';
  if(keydown(KEY_MINUS)) return '-';
  if(keydown(KEY_DIV)) return '/';
  if(keydown(KEY_EXE)) return '\n';
  if(keydown(KEY_ARROW)) return '\t';
  if(keydown(KEY_COMMA)) return ',';
  if(keydown(KEY_LEFTP)) return '(';
  if(keydown(KEY_RIGHTP)) return ')';
  if(keydown(KEY_POWER)) return '^';
  }
  if(shift && !alpha){
  if(keydown(KEY_MUL)) return '{';
  if(keydown(KEY_DIV)) return '}';
  if(keydown(KEY_ADD)) return '[';
  if(keydown(KEY_SUB)) return ']';
  if(keydown(KEY_DOT)) return '=';
  if(keydown(KEY_RIGHTP)) return '>';
  if(keydown(KEY_LEFTP)) return '<';
  if(keydown(KEY_MINUS)) return '~';
  }
  if(!shift && alpha){
    if(keydown(KEY_XOT)) return 'a';
    if(keydown(KEY_LOG)) return 'b';
    if(keydown(KEY_LN)) return 'c';
    if(keydown(KEY_SIN)) return 'd';
    if(keydown(KEY_COS)) return 'e';
    if(keydown(KEY_TAN)) return 'f';

    if(keydown(KEY_FRAC)) return 'g';
    if(keydown(KEY_FD)) return 'h';
    if(keydown(KEY_LEFTP)) return 'i';
    if(keydown(KEY_RIGHTP)) return 'j';
    if(keydown(KEY_COMMA)) return 'k';
    if(keydown(KEY_ARROW)) return 'l';

    if(keydown(KEY_7)) return 'm';
    if(keydown(KEY_8)) return 'n';
    if(keydown(KEY_9)) return 'o';

    if(keydown(KEY_4)) return 'p';
    if(keydown(KEY_5)) return 'q';
    if(keydown(KEY_6)) return 'r';
    if(keydown(KEY_MUL)) return 's';
    if(keydown(KEY_DIV)) return 't';

    if(keydown(KEY_1)) return 'u';
    if(keydown(KEY_2)) return 'v';
    if(keydown(KEY_3)) return 'w';
    if(keydown(KEY_ADD)) return 'x';
    if(keydown(KEY_SUB)) return 'y';

    if(keydown(KEY_0)) return 'z';
      
  }

  if(shift && alpha){
    if(keydown(KEY_XOT)) return 'A';
    if(keydown(KEY_LOG)) return 'B';
    if(keydown(KEY_LN)) return 'C';
    if(keydown(KEY_SIN)) return 'D';
    if(keydown(KEY_COS)) return 'E';
    if(keydown(KEY_TAN)) return 'F';

    if(keydown(KEY_FRAC)) return 'G';
    if(keydown(KEY_FD)) return 'H';
    if(keydown(KEY_LEFTP)) return 'I';
    if(keydown(KEY_RIGHTP)) return 'J';
    if(keydown(KEY_COMMA)) return 'K';
    if(keydown(KEY_ARROW)) return 'L';

    if(keydown(KEY_7)) return 'M';
    if(keydown(KEY_8)) return 'N';
    if(keydown(KEY_9)) return 'O';

    if(keydown(KEY_4)) return 'P';
    if(keydown(KEY_5)) return 'Q';
    if(keydown(KEY_6)) return 'R';
    if(keydown(KEY_MUL)) return 'S';
    if(keydown(KEY_DIV)) return 'T';

    if(keydown(KEY_1)) return 'U';
    if(keydown(KEY_2)) return 'V';
    if(keydown(KEY_3)) return 'W';
    if(keydown(KEY_ADD)) return 'X';
    if(keydown(KEY_SUB)) return 'Y';

    if(keydown(KEY_0)) return 'Z';
  }

  if(alpha){
    if(keydown(KEY_DOT)) return ' ';
    if(keydown(KEY_EXP)) return '"';
    if(keydown(KEY_NEG)) return '_';
  }
  return NULL;
}

void draw_menu(char menu[12][10], int language, int cursor) {
	drect(0,210,396,224, C_RGB(8,8,8));
	for (int i = 0; i<6; i++) {
		dline(i*66+66, 212, i*66+66,222, C_WHITE);
		if (cursor != 0 && i+1 == cursor) {
			drect(i*66, 212, i*66+66,224, C_WHITE);
			dtext(i*66+2, 212, C_RGB(8,8,8), menu[i*2+language]);
		} else {
			dtext(i*66+2, 212, C_WHITE, menu[i*2+language]);
		}
	}
}

void draw_project(uint16_t* project) {
	for(int i; i<DWIDTH*(DHEIGHT-10); i++) {
		gint_vram[i] = project[i];
	}
}

void save_project(uint16_t* project) {
	for(int i; i<DWIDTH*(DHEIGHT-10); i++) {
		project[i] = gint_vram[i];
	}
}

void set_color(int* color_r, int* color_g, int* color_b, int language) {
	for (float j = 0; j<40000; j++) {}
	char menu[12][10] = {
		"","",
		"","",
		"","",
		"","",
		"Cancel","Annuler",
		"Confirm","Confirm"
	};
	char texts[2][20] = {
		"RGB Selector", "Selecteur RGB"
	};
	int new_color_r = *color_r;
	int new_color_g = *color_g;
	int new_color_b = *color_b;
	int key_in_a_row = 0;
	int wait_time = 20000;
	while (1) {
		dclear(C_RGB(new_color_r, new_color_g, new_color_b));
		dtext(70,3,C_RGB(31-new_color_r, 31-new_color_g, 31-new_color_b),texts[language]);
		drect_border(29,24,129,200,C_WHITE, 3, C_BLACK);
		drect(32,197-new_color_r*170/31,126,197,C_RED);
		dtext(70,100,C_BLACK, "RED");
		dprint(75,115,C_BLACK, "%d", new_color_r);

		drect_border(145,24,245,200,C_WHITE, 3, C_BLACK);
		drect(148,197-new_color_g*170/31,242,197,C_GREEN);
		dtext(173,100,C_BLACK, "GREEN");
		dprint(190,115,C_BLACK, "%d", new_color_g);

		drect_border(261,24,361,200,C_WHITE, 3, C_BLACK);
		drect(264,197-new_color_b*170/31,358,197,C_BLUE);
		dtext(295,100,C_BLACK, "BLUE");
		dprint(308,115,C_BLACK, "%d", new_color_b);
		
		pollevent();

		draw_menu(menu, language, 0);

		if (keydown(KEY_1)){
			new_color_r--;
			key_in_a_row++;
			if (new_color_r < 0) {new_color_r = 0;}
			if (key_in_a_row<3) {
				for (float j = 0; j<wait_time; j++) {}
			}
		} else if (keydown(KEY_7)){
			new_color_r++;
			key_in_a_row++;
			if (new_color_r > 31) {new_color_r = 31;}
			if (key_in_a_row<3) {
				for (float j = 0; j<wait_time; j++) {}
			}
		} else if (keydown(KEY_2)){
			new_color_g--;
			key_in_a_row++;
			if (new_color_g < 0) {new_color_g = 0;}
			if (key_in_a_row<3) {
				for (float j = 0; j<wait_time; j++) {}
			}
		} else if (keydown(KEY_8)){
			new_color_g++;
			key_in_a_row++;
			if (new_color_g>31) {new_color_g = 31;}
			if (key_in_a_row<3) {
				for (float j = 0; j<wait_time; j++) {}
			}
		} else if (keydown(KEY_3)){
			new_color_b--;
			key_in_a_row++;
			if (new_color_b<0) {new_color_b=0;}
			if (key_in_a_row<3) {
				for (float j = 0; j<wait_time; j++) {}
			}
		} else if (keydown(KEY_9)){
			new_color_b++;
			key_in_a_row++;
			if (new_color_b>31) {new_color_b=31;}
			if (key_in_a_row<3) {
				for (float j = 0; j<wait_time; j++) {}
			}
		} else if (keydown(KEY_F5)) {
			return;
		} else if (keydown(KEY_F6)) {
			break;
		} else {
			key_in_a_row = 0;
		}
		dupdate();
		for (float j = 0; j<9000; j++) {}
	}
	*color_r = new_color_r;
	*color_g = new_color_g;
	*color_b = new_color_b;
}

int text_input(char title[27], int language, char *text) {
  char texts[4][25] = {
		"Confirm : EXE", "Confirmer : EXE", 
		"Cancel : AC/ON", "Annuler : AC/ON"
	}; 
  bool alpha = true;
  bool shift = false;
  while (1) {
    pollevent();
    char key = getkey_char(alpha, shift);
    if (key && strlen(text) < 26) {
      text[strlen(text)] = key;
    } else if (keydown(KEY_DEL) && strlen(text) > 0) {
      text[strlen(text)-1] = '\0';
    } else if (keydown(KEY_ACON)) {
      return 0;
    } else if (keydown(KEY_EXE)) {
      return 1;
    }else if (keydown(KEY_ALPHA)) {
      alpha = !alpha;
    } else if (keydown(KEY_SHIFT)) {
      shift = !shift;
    }
    drect_border(73, 77, 323, 155, C_RGB(31,28,28), 3, C_BLACK);
    dtext(78, 88, C_BLACK, title);
    drect_border(78, 102, 318, 118, C_RGB(31,31,31), 1, C_BLACK);
    dtext(78, 125, C_BLACK, texts[language]);
    dtext(78, 140, C_BLACK, texts[1*2+language]);
    dtext(82, 105, C_BLACK, text);
    if (alpha) {
      dtext(282, 125, C_BLACK, "Alpha");
    }
    if (shift) {
      dtext(282, 140, C_BLACK, "Shift");
    }
    dupdate();
    for (float j = 0; j<21000; j++) {}
  }
}

void move_cursor(int *cursor_pos, int *key_in_a_row, int wait_time) {
    if (keydown(KEY_DOWN)) {
        cursor_pos[1]++;
        (*key_in_a_row)++;
        if (cursor_pos[1] > DHEIGHT - 10) {
            cursor_pos[1] = DHEIGHT - 10;
        }
    } else if (keydown(KEY_UP)) {
        cursor_pos[1]--;
        (*key_in_a_row)++;
        if (cursor_pos[1] < 0) {
            cursor_pos[1] = 0;
        }
    } else if (keydown(KEY_RIGHT)) {
        cursor_pos[0]++;
        (*key_in_a_row)++;
        if (cursor_pos[0] > DWIDTH) {
            cursor_pos[0] = DWIDTH;
        }
    } else if (keydown(KEY_LEFT)) {
        cursor_pos[0]--;
        (*key_in_a_row)++;
        if (cursor_pos[0] < 0) {
            cursor_pos[0] = 0;
        }
    } else {
        *key_in_a_row = 0;
    }

    if (*key_in_a_row < 7) {
        for (float j = 0; j < wait_time; j++) {}
    }
}