Compiled ✅   src/checker/expand_checker.c
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:22:9: error: redeclaration of enumerator 'IN_NORMAL'
   22 |         IN_NORMAL,
      |         ^~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:22:9: note: previous definition of 'IN_NORMAL' with type 'enum e_token_state'
   22 |         IN_NORMAL,
      |         ^~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:23:9: error: redeclaration of enumerator 'IN_DOUBLE_QUOTE'
   23 |         IN_DOUBLE_QUOTE,
      |         ^~~~~~~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:23:9: note: previous definition of 'IN_DOUBLE_QUOTE' with type 'enum e_token_state'
   23 |         IN_DOUBLE_QUOTE,
      |         ^~~~~~~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:24:9: error: redeclaration of enumerator 'IN_SINGLE_QUOTE'
   24 |         IN_SINGLE_QUOTE,
      |         ^~~~~~~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:24:9: note: previous definition of 'IN_SINGLE_QUOTE' with type 'enum e_token_state'
   24 |         IN_SINGLE_QUOTE,
      |         ^~~~~~~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:25:9: error: redeclaration of enumerator 'ON_ERROR'
   25 |         ON_ERROR,
      |         ^~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:27:9: note: previous definition of 'ON_ERROR' with type 'enum e_token_state'
   27 |         ON_ERROR,
      |         ^~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:26:9: error: redeclaration of enumerator 'ON_SUCCESS'
   26 |         ON_SUCCESS,
      |         ^~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:26:9: note: previous definition of 'ON_SUCCESS' with type 'enum e_token_state'
   26 |         ON_SUCCESS,
      |         ^~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:38:25: error: conflicting types for 'push_token'; have 'int(t_expand_store *, t_shell_table *)' {aka 'int(struct s_expand_store *, struct s_shell_table *)'}
   38 | int                     push_token(t_expand_store *store, t_shell_table *shell_table);
      |                         ^~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:46:25: note: previous declaration of 'push_token' with type 'int(t_token_store *)' {aka 'int(struct s_token_store *)'}
   46 | int                     push_token(t_token_store *store);
      |                         ^~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:39:17: error: conflicting types for 'free_store'; have 'void(t_expand_store *)' {aka 'void(struct s_expand_store *)'}
   39 | void            free_store(t_expand_store *store);
      |                 ^~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:48:17: note: previous declaration of 'free_store' with type 'void(t_token_store *)' {aka 'void(struct s_token_store *)'}
   48 | void            free_store(t_token_store *store);
      |                 ^~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:40:25: error: conflicting types for 'add_buffer'; have 'int(t_expand_store *, char)' {aka 'int(struct s_expand_store *, char)'}
   40 | int                     add_buffer(t_expand_store *store, char c);
      |                         ^~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:47:25: note: previous declaration of 'add_buffer' with type 'int(t_token_store *, char)' {aka 'int(struct s_token_store *, char)'}
   47 | int                     add_buffer(t_token_store *store, char c);
      |                         ^~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:42:17: error: conflicting types for 'in_normal'; have 'void(t_shell_table *, t_expand_store *, t_expand_state *, char)' {aka 'void(struct s_shell_table *, struct s_expand_store *, enum e_expand_state *, char)'}
   42 | void            in_normal(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
      |                 ^~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:51:17: note: previous declaration of 'in_normal' with type 'void(t_token_store *, t_token_state *, char)' {aka 'void(struct s_token_store *, enum e_token_state *, char)'}
   51 | void            in_normal(t_token_store *store, t_token_state *state, char current);
      |                 ^~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:43:17: error: conflicting types for 'in_double_quote'; have 'void(t_shell_table *, t_expand_store *, t_expand_state *, char)' {aka 'void(struct s_shell_table *, struct s_expand_store *, enum e_expand_state *, char)'}
   43 | void            in_double_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
      |                 ^~~~~~~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:52:17: note: previous declaration of 'in_double_quote' with type 'void(t_token_store *, t_token_state *, char)' {aka 'void(struct s_token_store *, enum e_token_state *, char)'}
   52 | void            in_double_quote(t_token_store *store, t_token_state *state,
      |                 ^~~~~~~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:44:17: error: conflicting types for 'in_single_quote'; have 'void(t_shell_table *, t_expand_store *, t_expand_state *, char)' {aka 'void(struct s_shell_table *, struct s_expand_store *, enum e_expand_state *, char)'}
   44 | void            in_single_quote(t_shell_table *shell_table, t_expand_store *store, t_expand_state *state, char current);
      |                 ^~~~~~~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:54:17: note: previous declaration of 'in_single_quote' with type 'void(t_token_store *, t_token_state *, char)' {aka 'void(struct s_token_store *, enum e_token_state *, char)'}
   54 | void            in_single_quote(t_token_store *store, t_token_state *state,
      |                 ^~~~~~~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:45:18: error: conflicting types for 'on_success'; have 't_list *(t_expand_store *, char *)' {aka 'struct s_list *(struct s_expand_store *, char *)'}
   45 | t_list          *on_success(t_expand_store *store, char *token);
      |                  ^~~~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:58:18: note: previous declaration of 'on_success' with type 't_list *(t_token_store *, char *)' {aka 'struct s_list *(struct s_token_store *, char *)'}
   58 | t_list          *on_success(t_token_store *store, char *input);
      |                  ^~~~~~~~~~
In file included from src/checker/expand_checker.c:14:
includes/variable_expand.h:46:18: error: conflicting types for 'on_error'; have 't_list *(t_expand_store *, char *)' {aka 'struct s_list *(struct s_expand_store *, char *)'}
   46 | t_list          *on_error(t_expand_store *store, char *token);
      |                  ^~~~~~~~
In file included from includes/minishell.h:22,
                 from src/checker/expand_checker.c:13:
includes/tokenize.h:59:18: note: previous declaration of 'on_error' with type 't_list *(t_token_store *, char *)' {aka 'struct s_list *(struct s_token_store *, char *)'}
   59 | t_list          *on_error(t_token_store *store, char *input);
      |                  ^~~~~~~~
make: *** [Makefile:154: obj/checker/expand_checker.o] Error 1
