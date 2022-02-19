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
Plugin 'vimwiki/vimwiki'
Plugin 'mhinz/vim-startify'
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

"<vimwiki>"
let wiki = {}
let wiki.path = '~/ji-junhyuk.github.io/_wiki/'
let wiki.ext = '.md'

let g:vimwiki_list = [wiki]
let g:vimwiki_conceallevel = 0

" 로컬 리더 키 설정은 취향이니 각자 마음에 드는 키로 설정한다
let maplocalleader = "\\"

"1번 위키(공개용)와 2번 위키(개인용)
let g:vimwiki_list = [
    \{
    \   'path': '~/ji-junhyuk.github.io/_wiki',
    \   'ext' : '.md',
    \   'diary_rel_path': '.',
    \},
    \{
        \   'path': '/mnt/c/Users/junto/OneDrive',
    \   'ext' : '.md',
    \   'diary_rel_path': '.',
    \},
\]

let g:startify_bookmarks = [
                        \ { 'j' : '~/juntoplayground' },
                        \ ]
let g:startify_lists = [
                        \ { 'header': ['        Bookmarks'],    'type': 'bookmarks' },
                        \ { 'header': ['        MRU'],                  'type': 'files' },
                        \ { 'header': ['        MRU'. getcwd()],'type': 'dir' },
                        \ ]
nnoremap <c-n> :Startify<CR>
function! NewTemplate()

    let l:wiki_directory = v:false

    for wiki in g:vimwiki_list
        if expand('%:p:h') . '/' == wiki.path
            let l:wiki_directory = v:true
            break
        endif
    endfor

    if !l:wiki_directory
        return
    endif

    if line("$") > 1
        return
    endif

    let l:template = []
    call add(l:template, '---')
    call add(l:template, 'layout  : wiki')
    call add(l:template, 'title   : ')
    call add(l:template, 'summary : ')
    call add(l:template, 'date    : ' . strftime('%Y-%m-%d %H:%M:%S +0900'))
    call add(l:template, 'updated : ' . strftime('%Y-%m-%d %H:%M:%S +0900'))
    call add(l:template, 'tags    : ')
    call add(l:template, 'toc     : true')
    call add(l:template, 'public  : true')
    call add(l:template, 'parent  : ')
    call add(l:template, 'latex   : false')
    call add(l:template, '---')
    call add(l:template, '* TOC')
    call add(l:template, '{:toc}')
    call add(l:template, '')
    call add(l:template, '# ')
    call setline(1, l:template)
    execute 'normal! G'
    execute 'normal! $'

    echom 'new wiki page has created'
endfunction

autocmd BufRead,BufNewFile *.md call NewTemplate()
augroup vimwikiauto
    autocmd BufWritePre *wiki/*.md call LastModified()
    autocmd BufRead,BufNewFile *wiki/*.md call NewTemplate()
augroup END
" vimwiki의 conceallevel 을 끄는 쪽이 좋다
let g:vimwiki_conceallevel = 0

" 자주 사용하는 vimwiki 명령어에 단축키를 취향대로 매핑해둔다
command! WikiIndex :VimwikiIndex
nmap <LocalLeader>ww <Plug>VimwikiIndex
nmap <LocalLeader>wi <Plug>VimwikiDiaryIndex
nmap <LocalLeader>w<LocalLeader>w <Plug>VimwikiMakeDiaryNote
nmap <LocalLeader>wt :VimwikiTable<CR>

" F4 키를 누르면 커서가 놓인 단어를 위키에서 검색한다.
nnoremap <F4> :execute "VWS /" . expand("<cword>") . "/" <Bar> :lopen<CR>

" Shift F4 키를 누르면 현재 문서를 링크한 모든 문서를 검색한다
nnoremap <S-F4> :execute "VWB" <Bar> :lopen<CR>

"<base>"
syntax on
filetype plugin on
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
