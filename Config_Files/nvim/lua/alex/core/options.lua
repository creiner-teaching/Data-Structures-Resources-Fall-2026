local opt = vim.opt

--vim.o.timeout = true
--vim.o.timeoutlen = 500

-- Don't show mode since it's shown already by lualine
opt.showmode = false

-- adds line numbers and makes them relative
opt.nu = true
opt.relativenumber = true

-- splits windows down and right instead of up and left
opt.splitbelow = true
opt.splitright = true

-- makes tabs not terrible
opt.tabstop = 4 -- how many spaces = 1 tab
opt.softtabstop = 4 --idk
opt.shiftwidth = 4 -- how many spaces to tab when using the built in line tab >> and detab << commands
opt.expandtab = true --idk

opt.wrap = false -- disabled word wrapping because it misbehaves when moving up or down when on a wrapped line. will have to install an external word wrap that works correctly

-- properly syncs the system clipboard with neovim
-- doesn't seem to be working?
opt.clipboard='unnamedplus'

opt.undofile = true

-- makes screen start moving as soon as cursor goes past middle of monitor
opt.scrolloff = 0

-- does the auto indentation when starting/ending code blocks, line breaking etc (this rocks)
opt.smartindent = true

opt.breakindent = true

-- makes it easier to go right when in virtual block mode (ctrl+v from insert mode)
opt.virtualedit = 'block'

opt.conceallevel = 2

-- splits window when in that find and replace mode from %s/<find>/<replace>
opt.inccommand = 'split'

-- makes searches case insensitive unless there is a combination of upper and loser case symbols, at which point it becomes case insensitive
opt.ignorecase = true
opt.smartcase = true

-- enables mouse (I think on by default so this is redundant)
vim.cmd("set mouse=a")

-- ignores casing when typing neovim commands so that you can more easily autocomplete
opt.ignorecase = true

-- turns on less conservative color choices
opt.termguicolors = true
opt.background = 'dark' -- makes colors that can be dark or light default to dark

opt.backspace = "indent,eol,start" -- allow backspace on indent, end of line or insert mode start position


