set guioptions-=T
set number
set nobackup
set cursorline
set clipboard+=unnamed
set clipboard=unnamedplus
set smartindent



augroup templateGroup
autocmd!
autocmd BufNewFile *.cpp :0r ~/template/t.cpp
augroup END




