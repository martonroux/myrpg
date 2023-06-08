/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-guillaume1.tran
** File description:
** update
*/

#include "../../include/my.h"

bool text_is_hovered(sfText *text, sfRenderWindow *window, sfView *view)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f view_size = sfView_getSize(view);
    sfVector2f view_center = sfView_getCenter(view);
    sfFloatRect text_rect = sfText_getGlobalBounds(text);

    text_rect.top -= view_center.y - view_size.y / 2;
    text_rect.left -= view_center.x - view_size.x / 2;

    if (mouse_pos.x >= text_rect.left && mouse_pos.x <=
    text_rect.left + text_rect.width) {
        if (mouse_pos.y >= text_rect.top && mouse_pos.y <=
        text_rect.top + text_rect.height) {
            return true;
        }
    }
    return false;
}

bool rect_hovered(sfRectangleShape *rect, sfRenderWindow *window, sfView *view)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f view_size = sfView_getSize(view);
    sfVector2f view_center = sfView_getCenter(view);
    sfFloatRect rect_rect = sfRectangleShape_getGlobalBounds(rect);

    mouse_pos.x *= view_size.x / window_size.x;
    mouse_pos.y *= view_size.y / window_size.y;
    rect_rect.top -= view_center.y - view_size.y / 2;
    rect_rect.left -= view_center.x - view_size.x / 2;

    if (mouse_pos.x >= rect_rect.left && mouse_pos.x <=
    rect_rect.left + rect_rect.width) {
        if (mouse_pos.y >= rect_rect.top && mouse_pos.y <=
        rect_rect.top + rect_rect.height) {
            return true;
        }
    }
    return false;
}
