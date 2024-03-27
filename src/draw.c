#include <gint/keyboard.h>
#include <gint/display.h>

#include "config.h"

void draw(uint16_t* project,int language) {
	for (float j = 0; j<30000; j++) {}
	char menu[12][10] = {
		"Pen","Dessiner",
		"Eraser","Effacer",
		"Radius+","Rayon+",
		"Radius-","Rayon-",
		"Color","Couleur",
		"Leave","Quitter"
	};
	int status = 0;
	int cursor_pos[2] = {198,112};
	int cursor_radius = 1;
	int color_r = 0;
	int color_g = 0;
	int color_b = 0;
	int key_in_a_row = 0;
	int wait_time = 19000;
	while (1) {
		pollevent();
		// FKEYS
		if (keydown(KEY_F1)) {
			if (status == 1) {status = 0;} else {status = 1;}
			for (float j = 0; j<wait_time; j++) {}
		} else if (keydown(KEY_F2)) {
			if (status == 2) {status = 0;} else {status = 2;}
			for (float j = 0; j<wait_time; j++) {}
		} else if (keydown(KEY_F3)) {
			cursor_radius++;
			for (float j = 0; j<wait_time; j++) {}
		} else if (keydown(KEY_F4)) {
			cursor_radius--;
			if (cursor_radius<1) {cursor_radius = 1;}
			for (float j = 0; j<wait_time; j++) {}
		} else if (keydown(KEY_F5)) {
			set_color(&color_r, &color_g, &color_b, language);
			for (float j = 0; j<40000; j++) {}
		} else if (keydown(KEY_F6)) {
			break;
        }
		// DPAD
		move_cursor(&cursor_pos, &key_in_a_row, wait_time);
		// DRAW
		draw_project(project);
		if (status == 1) {
			drect((cursor_pos[0]-(cursor_radius-1)/2), (cursor_pos[1]-(cursor_radius-1)/2), (cursor_pos[0]+cursor_radius/2), (cursor_pos[1]+cursor_radius/2), C_RGB(color_r, color_g, color_b));
			save_project(project);
		} else if (status == 2) {
			drect((cursor_pos[0]-(cursor_radius-1)/2), (cursor_pos[1]-(cursor_radius-1)/2), (cursor_pos[0]+cursor_radius/2), (cursor_pos[1]+cursor_radius/2), C_RGB(31,31,31));
			save_project(project);
		}
		dimage(cursor_pos[0],cursor_pos[1],&cursor);
		draw_menu(menu, language, status);
		dupdate();
		for (float j = 0; j<2000; j++) {}
	}
	return 0;
}