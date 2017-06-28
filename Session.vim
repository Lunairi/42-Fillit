let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/Documents/42/fillit
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 includes/fillit.h
badd +1 inprogress/grid.c
badd +1 Makefile.m4
badd +25 ~/Documents/42/fillit/inprogress/gridtest.c
badd +0 inprogress/recursive.c
argglobal
silent! argdel *
argadd inprogress/recursive.c
set stal=2
edit includes/fillit.h
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winminwidth=1 winheight=1 winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 25 - ((24 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
25
normal! 025|
tabedit Makefile.m4
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winminwidth=1 winheight=1 winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 24 - ((23 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
24
normal! 013|
tabedit inprogress/recursive.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winminwidth=1 winheight=1 winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 65 - ((64 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
65
normal! 0
tabedit inprogress/grid.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winminwidth=1 winheight=1 winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 35 - ((34 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
35
normal! 05|
tabnext 3
set stal=1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
