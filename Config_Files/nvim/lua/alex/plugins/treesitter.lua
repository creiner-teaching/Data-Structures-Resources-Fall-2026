-- return {}

return {
    {
        "nvim-treesitter/nvim-treesitter",
        dependencies = { "windwp/nvim-ts-autotag" },
        config = function()
            -- Pull just the configs the table, and then from that run the setup function
            require("nvim-treesitter.configs").setup({
                ensure_installed = {"c", "lua", "vim", "vimdoc", "query", "python", "markdown", "markdown_inline", "cpp"},
                sync_install = false,
                -- auto_install = true,
                highlight = {
                    enable = true,
                    disable = {"latex"}
                },
                indent = { enable = true },
                autotag = { enable = true },
            })
        end,
    },
    {
        "nvim-treesitter/nvim-treesitter-textobjects",
    },
}
