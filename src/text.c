#include <gint/keyboard.h>
#include <gint/display.h>

#include "config.h"

void write(uint16_t* project, int language) {
	for (float j = 0; j<30000; j++) {}
	char menu[12][10] = {
		"Write", "Ecrire",
		"Color", "Couleur",
		"Font", "Police",
		"", "",
		"", "",
		"Leave", "Quitter"
	};
	char texts[2][25] = {
		"Input your text :", "Entrez votre texte :",
	};
	int cursor_pos[2] = {198,112};
	int color_r = 0;
	int color_g = 0;
	int color_b = 0;
	int key_in_a_row = 0;
	int wait_time = 19000;
	font_t default_font = *dfont_default();
	font_t fonts[4] = {
		default_font,
		roboto_font,
		anton_font,
		dosis_font
	};
	int font_id = 0;
	while (1) {
		dclear(C_WHITE);
		draw_project(project);
		draw_menu(menu, language, 0);
		pollevent();
		if (keydown(KEY_F1)){
			char text[27] = "";
			bool validated = text_input(texts[language], language, text);
			if (text != "" && validated) {
				char menu[12][10] = {
					"", "",
					"", "",
					"", "",
					"", "",
					"Cancel", "Annuler",
					"Place", "Placer"
				};
				while (1) {
					pollevent();
					// DPAD
					move_cursor(&cursor_pos, &key_in_a_row, wait_time);
					draw_project(project);
					dfont(&fonts[font_id]);
					dtext(cursor_pos[0], cursor_pos[1], C_RGB(color_r, color_g, color_b), text);
					dfont(dfont_default());
					if (keydown(KEY_F5)) {
						break;
					} else if (keydown(KEY_F6)) {
						save_project(project);
						break;
					}
					draw_menu(menu, language, 0);
					dupdate();
					for (float j = 0; j<2000; j++) {}
				}
			}
			for (float j = 0; j<30000; j++) {}
		} else if (keydown(KEY_F2)) {
			set_color(&color_r, &color_g, &color_b, language);
			for (float j = 0; j<30000; j++) {}
		} else if (keydown(KEY_F3)) {
			change_font(fonts, &font_id, language);
			for (float j = 0; j<40000; j++) {}
		} else if (keydown(KEY_F6)) {
			break;
		}
		dupdate();
	}
}

void change_font(font_t fonts[], int *font_id, int language) {
	int selector = *font_id;
	char menu[12][10] = {
		"", "",
		"", "",
		"", "",
		"", "",
		"Cancel", "Annuler",
		"Confirm", "Confirm."
	};
	int cursor_x = 0;
	int cursor_status_cycle = 0;
	while (1) {
		int height = 10;
		if (cursor_x == 10) {
			cursor_status_cycle = 0;
		}
		if (cursor_x == 0) {
			cursor_status_cycle = 1;
		}
		if (cursor_status_cycle == 1) {
			cursor_x++;
		} else {
			cursor_x--;
		}
		pollevent();
		if (keydown(KEY_UP) && selector>0) {
			selector--;
			for (float j = 0; j < 28000; j++) {};
		} else if (keydown(KEY_DOWN) && selector<sizeof(fonts)-1) {
			selector++;
			for (float j = 0; j < 28000; j++) {};
		} else if (keydown(KEY_F5)) {
			break;
		} else if (keydown(KEY_F6)) {
			*font_id = selector;
			break;
		}
		dclear(C_WHITE);
		for (int i = 0; i < sizeof(fonts); i++){
			dfont(&fonts[i]);
			dtext(50, height, C_BLACK, "AaBbCcDdEeFfGgHhIiJj0123456789&#@!/*+-");
			if (i == selector) {
				dimage(5 + cursor_x, height, &cursor_arrow);
			}
			height += fonts[i].line_height/2 + 10;
		}
		dfont(dfont_default());
		draw_menu(menu, language, 0);
		dupdate();
		for (float j = 0; j < 7000; j++) {};
	}
}