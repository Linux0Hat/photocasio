
#include <gint/display.h>
#include <gint/keyboard.h>
#include <ctype.h>
#include <string.h>

#include "draw.h"
#include "text.h"
#include "utils.h"
#include "config.h"


int main(void) {
	int language = statup_screen();
	help(language);
	uint16_t project[DWIDTH*(DHEIGHT-10)] = {};
	for (int i; i<DWIDTH*(DHEIGHT-10);i++) {
		project[i] = C_RGB(31,31,31);
	}
	while (1) {
		dclear(C_WHITE);
		draw_project(project);
		char menu[12][10] = {
			"Draw","Dessiner",
			"Write","Ecrire",
			"Images","Images",
			"Storage","Memoire",
			"Help","Aide",
			"Leave","Quitter"
		};
		draw_menu(menu, language, 0);
		dupdate();
		pollevent();
		if (keydown(KEY_F1)) {
			draw(project, language);
			for (float j = 0; j<40000; j++) {}
		} else if (keydown(KEY_F2)) {
			write(project, language);
			for (float j = 0; j<40000; j++) {}
		} else if (keydown(KEY_F3)) {
		} else if (keydown(KEY_F4)) {
		} else if (keydown(KEY_F5)) {
			help(language);
		} else if (keydown(KEY_F6)) {
			if (quit(language)) {
				return 1;
			}
			for (float j = 0; j<40000; j++) {}
		}
		for (float j = 0; j<8000; j++) {}
	}
}

int statup_screen() {
	int language;
	int brightness_text = 13;
	int brightness_status_cycle = 0;
	while (1) {
		if (brightness_text == 31) {
			brightness_status_cycle = 0;
		}
		if (brightness_text == 13) {
			brightness_status_cycle = 1;
		}
		if (brightness_status_cycle == 1) {
			brightness_text++;
		} else {
			brightness_text--;
		}
		dclear(C_RGB(8,8,8));
		dtext(155,100, C_RGB(31,31,31), "PhotoCasio");
		dtext(155,115, C_RGB(31,31,31), "by Linux_Hat");
		dtext(88,185, C_RGB(brightness_text,brightness_text,brightness_text), "Press F1 to start in English");
		dtext(53,200, C_RGB(brightness_text,brightness_text,brightness_text), "Pressez F2 pour commencer en Francais");
		dtext(2,214, C_RGB(31,31,31), "V1.0");
		dimage(115,96,&logo);
		dupdate();
		pollevent();
		if (keydown(KEY_F1)) {
			language = 0;
			break;
		}
		if (keydown(KEY_F2)) {
			language = 1;
			break;
		}
		for (float j = 0; j<8000; j++) {}
	}
	// ANIMATION
	for (int i; i<24; i++) {
		dclear(C_RGB(8,8,8));
		dtext(155,100, C_RGB(31-i,31-i,31-i), "PhotoCasio");
		dtext(155,115, C_RGB(31-i,31-i,31-i), "by Linux_Hat");
		dtext(88,185+i*2, C_RGB(brightness_text,brightness_text,brightness_text), "Press F1 to start in English");
		dtext(53,200+i*2, C_RGB(brightness_text,brightness_text,brightness_text), "Pressez F2 pour commencer en Francais");
		dtext(2-i*1.5,214, C_RGB(31,31,31), "V1.0");
		dimage(115 + i*3,96,&logo);
		dupdate();
		for (float j = 0; j<10000; j++) {}
	}
	for (float j = 0; j<300000; j++) {}
	return language;
}

void help(int language) {
	char texts[][40] = {
		"Help","Aide",
		"Press F1 for drawing.","Pressez F1 pour dessiner.",
		"Press F2 for writing.","Pressez F2 pour ecrire.",
		"Press F3 for images.","Pressez F3 pour les images.",
		"Press F4 for load/save your project.","Pressez F4 pour load/save votre projet.",
		"Press F5 for see this page.", "Pressez F5 pour voir cette page.",
		"Press F6 for leave.", "Pressez F6 pour quitter.",
		"EXE next","EXE suivant"
	};
	int brightness_text = 13;
	int brightness_status_cycle = 0;
	while (1) {
		if (brightness_text == 31) {
			brightness_status_cycle = 0;
		}
		if (brightness_text == 13) {
			brightness_status_cycle = 1;
		}
		if (brightness_status_cycle == 1) {
			brightness_text++;
		} else {
			brightness_text--;
		}
		dclear(C_RGB(8,8,8));
		dprint(30, 40, C_WHITE, "%s :", texts[language]);
		dtext(40,60, C_WHITE, texts[1*2+language]);
		dtext(40,80, C_WHITE, texts[2*2+language]);
		dtext(40,100, C_WHITE, texts[3*2+language]);
		dtext(40,120, C_WHITE, texts[4*2+language]);
		dtext(40,140, C_WHITE, texts[5*2+language]);
		dtext(40,160, C_WHITE, texts[6*2+language]);
		dtext(300,200, C_RGB(brightness_text,brightness_text,brightness_text), texts[7*2+language]);
		dupdate();
		pollevent();
		if (keydown(KEY_EXE)) {
			break;
		}
		for (float j = 0; j<10000; j++) {}
	}
}

int quit(int language) {
	for (float j = 0; j<30000; j++) {}
	char texts[6][30] = {
		"Are you sure to leave ?", "Etes vous sur de quitter ?",
		"F1) Yes", "F1) Oui",
		"F6) No", "F6) Non"
	};
	for (int i = 0; i<100; i++) {
		dclear(C_RGB(8,8,8));
		dtext(90,70,C_WHITE,texts[language]);
		dtext(110,100,C_WHITE,texts[1*2+language]);
		dtext(210,100,C_WHITE,texts[2*2+language]);
		drect_border(148, 200, 248, 215, C_RGB(8,8,8),1, C_WHITE);
		drect(148, 200, 248-i, 215, C_WHITE);
		dupdate();
		pollevent();
		if (keydown(KEY_F1)) {
			return 1;
		}
		if (keydown(KEY_F6)) {
			return 0;
		}
		for (float j = 0; j<13000; j++) {}
	}
	return 0;
} 