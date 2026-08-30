-- the following lines of code install the lazy nvim plugin manager
-- this first line creates the local variable lazypath, setting it equal to the place on the computer where 
-- extra stuff will be stored (echo it!), concatenated (..) with the extra path /lazy/lazy.nvim
-- lazy is a plugin manager but it is also a plugin. 
local lazypath = vim.fn.stdpath('data') .. '/lazy/lazy.nvim'
if not vim.loop.fs_stat(lazypath) then -- if lazy not instealled yet...
    vim.fn.system({
        'git',
        'clone',
        '--filter=blob:none',
        'https://github.com/folke/lazy.nvim.git',
        '--branch=stable', --latest stable version
        lazypath,  -- clones the repo into the lazypath
    })
end
-- rtp is runtime path, it's where neovim is going to look for things
-- this line is shorthand for vim.opt.prepend(vim.opt.rtp, lazypath), ie passing self as argument
-- rtp is a dictionary
vim.opt.rtp:prepend(lazypath)

require("lazy").setup('alex.plugins', {
    change_detection = {
        notify = false,
    },
})
