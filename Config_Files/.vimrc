syntax enable       " do syntax highlighting based on file type
filetype plugin indent on " detect file type, search plugins for language rules, indent code accordingly

set number          " show line numbers
set ruler
set wrap            " wrap lines that go past the edge of the terminal
set encoding=utf-8  " use UTF-8 as default text encoding
set wildmenu        " allow better command line autocompletion while in vim
set lazyredraw      " performance optimization to redraw the screen less often
set showmatch       " show matching brackets when inserting a new bracket

" Make cursor shape indicate the current mode in most modern terminals: 
" Normal mode -> block cursor 
" Insert mode -> thin vertical cursor 
" Replace mode -> underline cursor
if exists('&t_SI')
    let &t_SI = "\<Esc>[6 q" 
    let &t_SR = "\<Esc>[4 q" 
    let &t_EI = "\<Esc>[2 q" 
endif

set tabstop=4       " tabs in a file are shown to be 4 spaces wide
set expandtab       " convert new tab key-presses to spaces
set shiftwidth=4    " (auto)indenting shifts over 4 spaces
set softtabstop=4   " remove up to 4 spaces when backspacing after a tab

set mouse=a         " enable mouse
set clipboard=unnamedplus   " sync with system clipboard

set autoindent      " copy indent from current line when starting a new line
set smartindent     " better autoindent rules for programming

set incsearch       " search as each character is typed
set hlsearch        " highlight matches during search

set t_vb=           " turn off the screen flash (visual bell) effect

colorscheme torte
