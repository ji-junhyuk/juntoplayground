# juntoplayground
Sincerely

```vim
set tabstop=4
set shiftwidth=4
set cindent
set number
syntax on
set backspace=2
set backspace=indent,eol,start
set showmatch 
set ruler 

map <buffer> <F2> :w<CR>
map <buffer> <F3> :!norminette -R CheckForbiddenSourceHeader *.*<CR>
map <buffer> <F4> :!gcc -Wall -Werror -Wextra *.c && ./a.out<CR>
map <buffer> <F5> :!cl *.cpp && %< <CR>
```
