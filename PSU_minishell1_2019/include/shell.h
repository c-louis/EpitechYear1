/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell header
*/

#ifndef SHELL_H
#define SHELL_H

// Command handling
int exec_command(char **, char **);
int handle_command(char *, char ***, int *);

// Env Utils
char **copy_env(char **);
char *get_env(char *, char **);
void remove_env(char *, char ***);
void add_env(char *, char ***);
char *get_pwd(void);
int get_env_n_size(char *);

// Path Utils
int get_path_size(char *, int);
int get_path_count(char *);
char **get_paths(char **);

// General Utils
void *free_array(char **);
char **my_str_to_args_array(char *);
char *find_path(char **, char **);
void set_oldpwd(char **, char ***, char *);

// Buildin function
int exec_buildin(char **, char ***, int *);
int buildin_unsetenv(char **, char ***);
int buildin_cd(char **, char ***);
int buildin_env(char **, char ***);
int buildin_setenv(char **, char ***);
int buildin_exit(void);

// PWD handling
void actualize_pwd(char **, char ***, char *);

#endif
