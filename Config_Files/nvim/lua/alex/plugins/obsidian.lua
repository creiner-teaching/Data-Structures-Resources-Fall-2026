return {}

-- _G.obsidian_path = "~/Documents/Means of Production"

-- return {
--     "epwalsh/obsidian.nvim",
--     lazy = false,
--     version = "*",  -- recommended, use latest release instead of latest commit
--     ft = "markdown",
--     -- Replace the above line with this if you only want to load obsidian.nvim for markdown files in your vault:
--     -- event = {
--     --   -- If you want to use the home shortcut '~' here you need to call 'vim.fn.expand'.
--     --   -- E.g. "BufReadPre " .. vim.fn.expand "~" .. "/my-vault/**.md"
--     --   "BufReadPre path/to/my-vault/**.md",
--     --   "BufNewFile path/to/my-vault/**.md",
--     -- },
--     dependencies = {
--         -- Required.
--         "nvim-lua/plenary.nvim",
--     },
--     config = function()
--        require("obsidian").setup({
--             workspaces = {
--                 {
--                     name = "personal",
--                     path = obsidian_path,
--                 },
--             },
--             completion = {
--                 nvim_cmp = true,
--                 min_chars = 2,
--             }
--         })
--     end
-- }


-- -- fix autocompletion hotkey
-- -- fix cd hotkey not working when in file tree
