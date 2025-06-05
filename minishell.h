/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:45:07 by giomastr          #+#    #+#             */
/*   Updated: 2025/06/05 15:38:31 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

// # include "libft/libft.h"
//# include "builtin/minishell_builtin.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/wait.h>
# include <stdbool.h>

# define ERR_SYNT "Error: Syntax issues"
# define CMD_NF "Error: Command not found"
# define NODE_ERR "\033[1;92mError: could not create node\033[0m"

//******************************/
//**    	struct 		     **/
//****************************/

typedef struct s_list // env and exp management
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
	bool			isprint;
	char			*title;
	char			*value;
}	t_list;

//MAIN STRUCT
typedef struct s_mini
{
	int		exit_code;
	t_list	*env;
	char	*cmd;

}	t_mini;


// typedef struct s_cmd
// {
// 	char			**args;//matrice di input - each arg in each node
// 	int				input_fd;
// 	int				output_fd;
// 	struct s_cmd	*next;
// }	t_cmd;



//******************************/
//**    original functions   **/
//****************************/

// t_cmd	*parse_command_line(char *input);
// void		free_cmd_list(t_cmd *cmd_list);
// int		execute_pipeline(t_cmd *cmd_list, t_mini *mini);

// //-------------[main]-------------
// int		parsing(char *cmd);
// char	*find_cmd_path(char *cmd, char **env);

// //-------------[pathing]----------
// /* char    *get_env_val(char *name, char **env);
// char    **split_paths(char *path);
// char    *join_paths(char *dir, char *cmd);
// char    *find_cmd_path(char *cmd, char **env); */
// char	*path_find(char *envp[], char *command);


// //-------------[exe]--------------
// int		handle_error(char *msg, int code, char *cmd);
// void	set_redirs(int in_fd);
// int		execution_externalcmd(char **args, char **env);
// int		exec_builtin(char **args, t_mini *mini);
// int		excute_cmd(char **args, t_mini *mini);

// //-------------[signals]----------
void	sig_handler(int sig);
int		getsignal(t_mini *mini);

size_t  ft_strlcpy(char *dst, const char *src, size_t size);


//******************************/
//**  X functions  **/
//****************************/


//******************************/
//**    X functions    **/
//****************************/



//******************************/
//**     list functions      **/
//****************************/

t_list	*ft_lstnew(int value);
int		ft_lstsize(t_list *head);
void	ft_lstadd_front(t_list **head, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **head, t_list *new);
void    make_env_list(t_mini *mini, char **envp);


//******************************/
//**    utility functions    **/
//****************************/

size_t	schr(const char *s, char c);


//******************************/
//**    cleaner functions    **/
//****************************/

void	swipe_list(t_list *list);
void	ft_clean(t_mini *mini);
void	err_ex(char *s, t_mini *mini);



//******************************/
//**    parse   functions    **/
//****************************/



//******************************/
//**   BUILT-IN functions    **/
//****************************/

//-------------[env]------------
void	initenv(t_mini *mini, char *env[]);
void	env(t_mini *mini);
// int		builtin(char *cmd);
// int		pwd(void);
// int		echo(char **echo_mtx, t_mini *mini);
// int		env(char **args, t_mini *mini);
// void		setenvv(t_mini *mini, char *env[], int add);
// int		exity(char **args, t_mini *mini);
// int		unset(char **args, t_mini *mini);
// int		export(t_mini *mini);

//-------------[export]------------
void	export_command(t_mini *mini, char **args);
void	update_env(t_list **env, char *title, char *value, bool isprint);
bool	is_valid_identifier(const char *str);

// //-------------[utils]------------
void		free_mtx(char **mtx);
// int		mtx_len(char **mtx);
int		ft_strcmp(char *s1, char *s2);
// char		find_quote(char *str);

#endif
