/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** linked_list
*/

#pragma once

typedef struct linked_list_s {
    void *head;
    void *data;
    struct linked_list_s *prev;
    struct linked_list_s *next;
} linked_list_t;
