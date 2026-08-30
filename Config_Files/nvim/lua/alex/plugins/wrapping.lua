-- for decent word wrapping
return {
    'andrewferrier/wrapping.nvim',
    config = function()
        require('wrapping').setup({
            opts = {
                create_keymaps = false,
            }
        })
    end,
}
