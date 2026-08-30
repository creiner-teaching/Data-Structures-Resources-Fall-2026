return {
    {
        'nvim-telescope/telescope.nvim',
        dependencies = {
            'nvim-lua/plenary.nvim',
            { "nvim-telescope/telescope-fzf-native.nvim", build = "make" },
            "nvim-tree/nvim-web-devicons",
            "folke/todo-comments.nvim",
            'nvim-lua/popup.nvim',
            'nvim-telescope/telescope-media-files.nvim',
        },
        config = function()
            local telescope = require("telescope")
            local actions = require("telescope.actions")
            
            telescope.load_extension('media_files')
            telescope.setup({
                defaults = {
                    path_display = { "smart" },
                },
                extensions = {
                    media_files = {
                        -- filetypes whitelist
                        -- defaults to {png, jpg, mp4, webm, pdf}
                        filetypes = {'png', 'webm', 'gif', 'mp4', 'png', 'pdf', 'jpg', 'jpeg'}
                    } 
                },
            })
            telescope.load_extension("fzf")
        end,
    },
    -- Plugin that makes other neovim UI search stuff to be telescope
    {
        'nvim-telescope/telescope-ui-select.nvim',
        config = function()
            require("telescope").setup({
                extensions = {
                    ['ui-select'] = {
                        require('telescope.themes').get_dropdown {
                        }
                    }
                }
            })
            require('telescope').load_extension('ui-select')
        end
    },
}
