return {
    --"nvim-tree/nvim-tree.lua",
    --dependencies = "nvim-tree/nvim-web-devicons",
    --config = function()
    --    local nvimtree = require("nvim-tree")

    --    vim.g.loaded_netrw = 1
    --    vim.g.loaded_netrwPlugin = 1

    --    nvimtree.setup({
    --        view = {
    --            width = 35,
    --            relativenumber = true,
    --        },
    --        renderer = {
    --            indent_markers = {
    --                enable = true,
    --            },
    --            icons = {
    --                glyphs = {
    --                    folder = {
    --                        arrow_closed = "󰁕",
    --                        arrow_open = "󰁆",
    --                    },
    --                },
    --            }
    --        },
    --        -- actions = {
    --        --     open_file = {
    --        --         window_picker = {
    --        --             enable = false,
    --        --         },
    --        --     },
    --        -- },
    --        --
    --    })
    --end

    {
        "nvim-neo-tree/neo-tree.nvim",
        branch = "v3.x",
        dependencies = {
            "nvim-lua/plenary.nvim",
            "nvim-tree/nvim-web-devicons",
            "MunifTanjim/nui.nvim",
            "3rd/image.nvim",
            "stevearc/dressing.nvim",
        },
        config = function()
            local neotree = require('neo-tree')
            require('neo-tree').setup({
                window = {
                    mappings = {
                        ["P"] = { "toggle_preview", config = { use_image_nvim = true } },
                    }
                }
            })
        end,
     },
}

