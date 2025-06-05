// 🩸 1. Token structure
// Each word/operator from the input line becomes a token.

typedef enum e_token_type {
    WORD,
    PIPE,
    INPUT_REDIRECT,     // <
    OUTPUT_REDIRECT,    // >
    APPEND_REDIRECT,    // >>
    HEREDOC,            // <<
    END
} t_token_type;

typedef struct s_token {
    char            *value;
    t_token_type    type;
    struct s_token  *next;
} t_token;

// You will fill this list during the tokenization phase.

// 🩸 2. Redirection structure
// You can store redirections for each command in a list or inside the command node.


typedef enum e_redirect_type {
    REDIR_INPUT,
    REDIR_OUTPUT,
    REDIR_APPEND,
    REDIR_HEREDOC
} t_redirect_type;

typedef struct s_redirect {
    t_redirect_type     type;
    char                *file;
    struct s_redirect   *next;
} t_redirect;

// 🩸 3. Command node structure
// Each command in a pipeline becomes a node in a list of commands.

typedef struct s_command {
    char            **args;         // array of arguments, first is usually the binary
    t_redirect      *redirects;     // linked list of redirections
    struct s_command *next;         // next command in pipeline (after a pipe)
} t_command;

// For example:

// echo hello > out.txt | cat -n
// You would have a list of 2 t_command nodes:

// echo hello with an OUTPUT_REDIRECT to out.txt

// cat -n with no redirection

// 🩸 4. Shell context (optional but recommended)
// To manage the whole shell state, including env, parsed commands, etc.

typedef struct s_shell {
    t_token     *tokens;     // token list
    t_command   *commands;   // parsed command list
    char        **envp;      // environment
    int         last_status; // $? value
} t_shell;

// 🩸 Extra Tips for Conversion:
// Replace your matrices (e.g. char **cmds) with dynamic lists (t_command *cmds).

// Make utility functions like:

// add_token(t_token **lst, char *val, t_token_type type)

// add_command(t_command **lst, t_command *new)

// add_redirect(t_redirect **lst, char *file, t_redirect_type type)

// Don’t forget to free everything when done!



// int is_quoted(char *s, char *to_check)
// {
//     bool    in_quote;
//     char    quote;
//     quote = 0;
//     in_quote = false;
//     while (s != to_check)
//     {
//         if ((*s == '"' || *s == '\'') && (quote == *s || quote == 0))
//         {
//             in_quote = !in_quote;
//             quote = *s;
//         }
//         if (!in_quote)
//             quote = 0;
//         s++;
//     }
//     if (*to_check == quote && in_quote)
//         return (0);
//     if (in_quote && quote == '\'')
//         return (1);
//     if (in_quote && quote == '"')
//         return (2);
//     return (0);
// }

