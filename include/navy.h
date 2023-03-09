/*
** EPITECH PROJECT, 2023
** navy
** File description:
** dsk
*/

//--------Libraries--------//

#include <sys/types.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#ifndef MY_NAVY_
    #define MY_NAVY_

//--------Structures--------//

typedef struct my_navy_s {
    int ac;
    char **av;
    char *position_file;

    int size;
    char po1;
    char po2;
    int poi1;
    int poi2;

    int pid;
    char **ennemy_map;
    char **my_map;
    char *str;
    int my_boat;
    int ennemy_boat;
    int ordre;
} my_navy_t;

//--------Prototypes--------//

int *static_var_o(void);
int info (void);
int error (int i);
int error_position_bat(my_navy_t *navy, int i);
int boat_error(my_navy_t *navy);
int verif_pid(char *av);
void synchros(int sig, siginfo_t *siginfo, void *context);
void first_player(my_navy_t *navy);
int second_player(my_navy_t *navy);
char **map(void);
int init_map(my_navy_t *navy);
char *get_next_line(int fd);
int receiver(my_navy_t *navy, int pe, int pid);
int attack(int pid, my_navy_t *navy);
int *static_var_x(void);
int *static_var_y(void);
void get_y(int signal);
void get_x(int signal);
void confirm_y(int signal);
int error_same_position(my_navy_t *navy);
int print_all_maps(my_navy_t *navy);

#endif /* !MY_NAVY_ */
