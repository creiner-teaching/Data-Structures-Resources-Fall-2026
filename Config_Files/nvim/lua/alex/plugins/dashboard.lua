function disable_indent_guide()
    vim.cmd('IBLDisable')
end

function enable_indent_guide()
    vim.cmd('IBLEnable')
end

function on_buf_leave()
--    local buftype = vim.api.nvim_buf_get_option(0, 'buftype')
   local filetype = vim.api.nvim_buf_get_option(0, 'filetype')

--    print("buftype is " .. buftype .. " and filetype is " .. filetype)
    pcall(function()
        if filetype ~= 'TelescopePrompt' and filetype ~= 'dashboard' and filetype ~= neo-tree then
            enable_indent_guide()
        end
    end)
end

return {
    'nvimdev/dashboard-nvim',
    event = 'VimEnter',
    config = function()
        require('dashboard').setup {
            theme = 'hyper',
            config = {
                week_header = {
                    enable = true,
                },
                -- 'groups' are literally just colors as far as I can tell
                shortcut = {}
                    -- {
                    --     icon_hl = '@variable',
                    --     desc = 'Local Files',
                    --     group = '@property',
                    --     action = 'Telescope find_files',
                    --     key = 't',
                    -- },
                    -- -- Change this to a relative path that always leads to vault
                    -- {
                    --     desc = 'App Files',
                    --     group = 'Label',
                    --     action = nav_app_files,
                    --     key = 'f',
                    -- },
                    -- {
                    --     desc = 'App Config Files',
                    --     group = 'Label',
                    --     action = nav_app_config,
                    --     key = 'a',
                    -- },
                    -- {
                    --     desc = 'Models',
                    --     group = 'Label',
                    --     action = nav_models,
                    --     key = 'm',
                    -- },
                    -- {
                    --     desc = 'Config Files',
                    --     group = 'DiagnosticHint',
                    --     action = nav_configs,
                    --     key = 'c',
                    -- },
                -- },
            },
        }
        vim.api.nvim_create_augroup('DashboardIndentGuide', { clear = true })
        vim.api.nvim_create_autocmd('FileType', {
            pattern = 'dashboard',
            callback = disable_indent_guide,
            group = 'DashboardIndentGuide'
        })
        vim.api.nvim_create_autocmd('BufLeave', {
            pattern = '*',
            callback = on_buf_leave,
            group = 'DashboardIndentGuide'
        })
    end,
    dependencies = { {'nvim-tree/nvim-web-devicons'} }
}
