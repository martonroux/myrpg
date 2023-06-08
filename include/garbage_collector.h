/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** garbage_collector
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct garbage_collector_s {
    struct garbage_collector_s *next;
    void* ptr;
} collector_t;

int add_to_garbage_collector(void *ptr, collector_t *collector);
collector_t* create_garbage_collector(void);
int free_garbage_collector(collector_t *collector);
