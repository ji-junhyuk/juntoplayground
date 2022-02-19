```vim
"Ubuntu
set nocompatible
filetype on
" filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'nanotech/jellybeans.vim'
Plugin 'nathanaelkane/vim-indent-guides'
Plugin 'preservim/tagbar'
Plugin 'preservim/nerdtree'
Plugin 'airblade/vim-gitgutter'
Plugin 'tpope/vim-fugitive'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'farmergreg/vim-lastplace'
Plugin 'junegunn/goyo.vim'
call vundle#end()
filetype plugin indent on

"<jellybeans>"
colorscheme jellybeans

"<NERD tree>"
nnoremap <C-n> :NERDTreeToggle<CR>

"<airline>"
nnoremap <leader>q :bn<CR>
nnoremap <leader>w :bp<CR>
let g:airline#extensions#tabline#enabled = 1

"<goyo>"
nnoremap <leader>g :Goyo<CR>

"<base>"
set tabstop=4
set shiftwidth=4 ">>, <<키로 들여/내어쓰기 할 때, 스페이스 개수"
set cindent
set number
set hidden

nnoremap <leader>t :tabnew<CR>

nnoremap <leader>bq :bp <BAR> bd #<CR>
nnoremap <leader>bl :ls<CR>

map <buffer> <F2> :w<CR>
map <buffer> <F3> :!norminette -R CheckForbiddenSourceHeader *.*<CR>
map <buffer> <F4> :!gcc -Wall -Werror -Wextra *.c && ./a.out<CR>
map <buffer> <F5> :!g++ % && ./a.out<CR>
map <buffer> <F6> :!./a.out<CR>
map <buffer> <F7> :!find . -type f -name "a.out" -print -delete<CR>
nmap <F8> :TagbarToggle<CR>
```
