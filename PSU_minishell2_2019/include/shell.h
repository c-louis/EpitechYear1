/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell header
*/

#ifndef SHELL_H
#define SHELL_H

typedef struct s_cmd {
    char **cmd;
    int *action;
} cmd_t;

// Command redirection function
int redirect_right(cmd_t *list, char ***env, int *end, int index);
int redirect_left(cmd_t *list, char ***env, int *end, int index);
int shell_pipe(cmd_t *list, char ***env, int *end, int index);

// Command handling
cmd_t *parse_command(char *cmd);
int exec_command(char **, char **, int, int);
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
void free_array(char **);
char **my_str_to_args_array(char *);
char *find_path(char **, char **);
void set_oldpwd(char ***, char *);

// Buildin function
int exec_buildin(char **, char ***, int *);
int buildin_unsetenv(char **, char ***);
int buildin_cd(char **, char ***);
int buildin_env(char ***);
int buildin_setenv(char **, char ***);
int buildin_exit(void);

// PWD handling
void actualize_pwd(char ***, char *);

// Multiple command handling and preprocess
char **preprocess(char *, char ***);
void handle_status(int status, char *);
int check_execution(char *path, char *arg);

// Memory utils
void free_2(void *v1, void *v2);
void free_cmd(cmd_t *cmd);

// Complex command checker
int is_redirection(char c);
int is_pipe(char c);
int is_pipe_redirection(char c);
int is_space(char c);
int is_complex_command(char *cmd);
int raise_error(char **cmd);

// Simple command execution
int exec_single_command(char *cmd , char ***env, int *end, int wait);

// Complex command sanitize
char *sanitalize_complex_command(char *cmd);

// Preprocessing function
char **get_command_list(char *cmd, int cmd_c);
char *set_all_environment(char *cmd, char ***env);

#endif
