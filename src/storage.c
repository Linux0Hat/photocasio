#include <gint/keyboard.h>
#include <gint/display.h>
#include <gint/std/stdlib.h>
#include <gint/std/stdio.h>
#include "utils.h"

void storage(uint16_t *project, int language) {
    char texts[4][11] = {
        "Filename :","Fichier :",
    };
    char menu[12][10] = {
        "Save","Enreg.",
        "Load","Charger",
        "","",
        "","",
        "","",
        "Cancel","Cancel"
    };
    while (1) {
        draw_menu(menu, language, 0);
        dupdate();
        pollevent();
        char filename[32] = "/photocasio/";
        if (keydown(KEY_F1)) {
            bool validated = text_input(texts[language], language, &filename);
            if (filename != "/photocasio/" && validated) {
                // write bmp file
            }
            draw_project(project);
        } else if (keydown(KEY_F2)) {
            bool validated = text_input(texts[language], language, &filename);
            if (filename != "/photocasio/" && validated) {
                //write bmp file
            }
            draw_project(project);
        } else if (keydown(KEY_F6)) {
            return;
        }
    }
}
