##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile, don't forget to put CPPFLAGS and
## remove -Werror and backslash every src files
##

TARGET = my_rpg
SRC = main.c \
		$(wildcard src/*.c) \
		$(wildcard src/utility/*.c) \
		$(wildcard src/event/*.c) \
		$(wildcard src/utility/linked_list/*.c) \
		$(wildcard src/utility/free/*.c) \
		$(wildcard src/utility/blood_utility/*.c) \
		$(wildcard src/utility/game_struct_functions/*.c) \
		$(wildcard src/utility/entity_utility/*.c) \
		$(wildcard src/utility/chunk_utility/*.c) \
		$(wildcard src/utility/init/*.c) \
		$(wildcard src/entities/*.c) \
		$(wildcard src/entities/players/*.c) \
		$(wildcard src/entities/waves/*.c) \
		$(wildcard src/entities/weapons/*.c) \
		$(wildcard src/utility/my_functions/*.c) \
		$(wildcard src/entities/characters/*.c) \
		$(wildcard src/entities/characters/bosses/*.c) \
		$(wildcard src/entities/characters/zombies/*.c) \
		$(wildcard src/entities/characters/player/*.c) \
		$(wildcard src/entities/animations/*.c) \
		$(wildcard src/entities/chunks/*.c) \
		$(wildcard src/entities/weapons/*.c) \
		$(wildcard src/display/*.c) \
		$(wildcard src/collisions/*.c) \
		$(wildcard src/update/*.c) \
		$(wildcard src/tutorial/*.c) \
		$(wildcard src/waves/*.c) \
		$(wildcard src/utility/button/*.c) \
		$(wildcard src/weapon/*.c) \
		$(wildcard src/save/*.c)

OBJ = $(SRC:.c=.o)
CPPFLAGS = -Iinclude -g3
CSFMLFLAGS = -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all	:	$(TARGET) clean

$(TARGET)	: $(OBJ)
	$(CC) $(SRC) -o $(TARGET) $(CPPFLAGS) $(CSFMLFLAGS)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(TARGET)

re	:	fclean all
	$(RM) $(OBJ)
