#ifndef GUI_H
#define GUI_H

void init_gui();
void draw_text(int x, int y, const char* str, int color = 0xFFFFFF);
void draw_rect(int x, int y, int w, int h);
void draw_fill(int x, int y, int w, int h);
void gui_update();

#endif//GUI_H
