---
paths:
  - "src/**/*.c"
---

# C Code Guidelines

### Code Style

- Use snake_case for variable and function names.
- Limit lines to a maximum of 80 characters.
- Your project must be written in accordance with the Norminette.
- All heap-allocated memory must be properly freed when necessary. Memory leaks will not be tolerated.

### Allowable External Functions

以下の関数のみ使用可能。それ以外の外部関数は使用禁止。

#### readline
- `char *readline(const char *prompt)` — プロンプトを表示し、ユーザ入力を返す
- `void rl_clear_history(void)` — 履歴リストを全削除
- `void rl_on_new_line(void)` — カーソルが新しい行に移動したことを通知
- `void rl_replace_line(const char *text, int clear_undo)` — 現在の入力行を置換
- `void rl_redisplay(void)` — プロンプトと入力行を再描画
- `void add_history(const char *string)` — 履歴リストに追加

#### stdio / stdlib
- `int printf(const char *format, ...)` — フォーマット出力
- `void *malloc(size_t size)` — メモリ確保
- `void free(void *ptr)` — メモリ解放

#### I/O
- `ssize_t write(int fd, const void *buf, size_t count)` — ファイルディスクリプタへ書き込み
- `int access(const char *pathname, int mode)` — ファイルのアクセス権確認
- `int open(const char *pathname, int flags, ...)` — ファイルを開く
- `ssize_t read(int fd, void *buf, size_t count)` — ファイルディスクリプタから読み込み
- `int close(int fd)` — ファイルディスクリプタを閉じる

#### プロセス制御
- `pid_t fork(void)` — 子プロセスを生成
- `pid_t wait(int *wstatus)` — 子プロセスの終了を待つ
- `pid_t waitpid(pid_t pid, int *wstatus, int options)` — 指定子プロセスの終了を待つ
- `pid_t wait3(int *wstatus, int options, struct rusage *rusage)` — リソース使用情報付きwait
- `pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage)` — リソース使用情報付きwaitpid

#### シグナル
- `sighandler_t signal(int signum, sighandler_t handler)` — シグナルハンドラを設定
- `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)` — シグナルアクションを設定
- `int sigemptyset(sigset_t *set)` — シグナルセットを空にする
- `int sigaddset(sigset_t *set, int signum)` — シグナルセットにシグナルを追加
- `int kill(pid_t pid, int sig)` — プロセスにシグナルを送信

#### プロセス終了・実行
- `void exit(int status)` — プロセスを終了
- `int execve(const char *pathname, char *const argv[], char *const envp[])` — プログラムを実行

#### ファイルシステム
- `char *getcwd(char *buf, size_t size)` — カレントディレクトリを取得
- `int chdir(const char *path)` — カレントディレクトリを変更
- `int stat(const char *pathname, struct stat *statbuf)` — ファイル情報を取得
- `int lstat(const char *pathname, struct stat *statbuf)` — シンボリックリンク情報を取得
- `int fstat(int fd, struct stat *statbuf)` — fdからファイル情報を取得
- `int unlink(const char *pathname)` — ファイルを削除

#### パイプ・ファイルディスクリプタ
- `int dup(int oldfd)` — ファイルディスクリプタを複製
- `int dup2(int oldfd, int newfd)` — ファイルディスクリプタを指定番号に複製
- `int pipe(int pipefd[2])` — パイプを作成

#### ディレクトリ操作
- `DIR *opendir(const char *name)` — ディレクトリを開く
- `struct dirent *readdir(DIR *dirp)` — ディレクトリエントリを読む
- `int closedir(DIR *dirp)` — ディレクトリを閉じる

#### エラー処理
- `char *strerror(int errnum)` — エラー番号に対応する文字列を返す
- `void perror(const char *s)` — エラーメッセージを出力

#### ターミナル
- `int isatty(int fd)` — fdが端末か判定
- `char *ttyname(int fd)` — 端末名を返す
- `int ttyslot(void)` — 端末スロット番号を返す
- `int ioctl(int fd, unsigned long request, ...)` — デバイス制御

#### 環境変数
- `char *getenv(const char *name)` — 環境変数の値を取得

#### termios
- `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p)` — 端末属性を設定
- `int tcgetattr(int fd, struct termios *termios_p)` — 端末属性を取得

#### termcap
- `int tgetent(char *bp, const char *name)` — termcapエントリを取得
- `int tgetflag(const char *id)` — ブール型ケーパビリティを取得
- `int tgetnum(const char *id)` — 数値型ケーパビリティを取得
- `char *tgetstr(const char *id, char **area)` — 文字列型ケーパビリティを取得
- `char *tgoto(const char *cap, int col, int row)` — カーソル移動文字列を生成
- `int tputs(const char *str, int affcnt, int (*putc)(int))` — ケーパビリティ文字列を出力
