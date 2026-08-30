-- Attempt to mount laptop server
local status = pcall(function()
    os.execute('mount ~/Laptop-Server > /dev/null 2>&1')
end)
vim.g.mapleader = " "
-- vim.g.maplocalleader = "\\"
require("alex.core")
require("alex.lazy")
globals = require("modules.globals")
-- Transparency enabled by default
-- globals.toggle_transparency()

vim.api.nvim_buf_create_user_command(0, 'ToggleTransparency', function()
    globals.toggle_transparency()
end, {})

-- LaTeX omni-completion trigger
vim.cmd([[autocmd FileType tex setlocal omnifunc=v:lua.vim.lsp.omnifunc]])

vim.cmd("highlight FloatBorder guibg=NONE")

vim.filetype.add({
    extension = { jsonl = json },
})

vim.api.nvim_create_autocmd({ "BufRead", "BufNewFile" }, {
    pattern = "*.jsonl",
    callback = function()
        vim.bo.filetype = "json"
    end,
})

vim.lsp.handlers["textDocument/hover"] = function(err, result, ctx, config)
  if err or not result or not result.contents then
    return
  end

  -- inspect or modify result.contents here
  print(vim.inspect(result.contents))

  return vim.lsp.handlers.hover(err, result, ctx, vim.tbl_deep_extend("force", config or {}, {
    border = "rounded",
    max_width = 100,
    max_height = 30,
  }))
end

-- Set transparent background
-- Adjust other colors as needed
-- vim.api.nvim_set_hl(0, 'LineNr', { fg = '#5eacd3' })
-- vim.api.nvim_set_hl(0, 'Comment', { fg = '#5eacd3' })
