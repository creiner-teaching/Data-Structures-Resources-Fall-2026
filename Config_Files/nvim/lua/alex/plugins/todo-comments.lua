-- Add todom comments by making a comment, typing TODO (or another a keyword), and finish with a colon :
-- TODO:
-- HACK:
-- BUG:
-- PERF:
-- NOTE: 
-- FIX: 
-- WARNING: 
return {
    {
        "folke/todo-comments.nvim",
        dependencies = { "nvim-lua/plenary.nvim" },
        config = function()
            local todo_comments = require("todo-comments")

            vim.keymap.set("n", "]t", function()
                todo_comments.jump_next()
            end, { desc = "Next todo comment" })

            vim.keymap.set("n", "[t", function()
                todo_comments.jump_prev()
            end, { desc = "Previous todo comment" })

            todo_comments.setup()
        end,
    }
}
