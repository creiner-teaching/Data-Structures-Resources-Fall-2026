-- TODO: I don't think I'm actually using this anymore
function carriage_return()
    cmp.mapping.abort()
    vim.api.nvim_input('<CR>')
end

return {
    {
        'hrsh7th/cmp-nvim-lsp',
    },
    {
        "micangl/cmp-vimtex"
    },
    {
        'L3MON4D3/LuaSnip',
        dependencies = {
            'saadparwaiz1/cmp_luasnip',
            -- 'rafamadriz/friendly-snippets',
            'hrsh7th/cmp-omni',
            'hrsh7th/cmp-buffer',
            'hrsh7th/cmp-path',
            'hrsh7th/cmp-cmdline',
            'onsails/lspkind.nvim' -- vs-code like pictograms?
        },

    },
    {
        'hrsh7th/nvim-cmp',
        config = function()
            local cmp = require("cmp")
            local luasnip = require("luasnip")
            -- require('luasnip.loaders.from_vscode').lazy_load()
            luasnip.add_snippets("tex", require('snippets.latex_snippets'))
            cmp.setup({
                snippet = {
                    expand = function(args)
                        require('luasnip').lsp_expand(args.body)
                    end,
                },
                window = {
                    completion = cmp.config.window.bordered(),
                    documentation = cmp.config.window.bordered(),
                },
                mapping = cmp.mapping.preset.insert({
                    ['<C-k>'] = cmp.mapping.scroll_docs(-4),
                    ['<C-j>'] = cmp.mapping.scroll_docs(4),
                    ['<C-Space>'] = cmp.mapping.close(),
                    ['<C-e>'] = cmp.mapping.abort(),
                    -- tab through suggestions or when a snippet is active, tab to next arg 
                    ['<Tab>'] = cmp.mapping(function(fallback)
                        if cmp.visible() then
                            cmp.confirm({ select = true })
                        elseif luasnip.expand_or_locally_jumpable() then
                            luasnip.expand_or_jump()
                        else
                            fallback()
                        end
                    end, { 'i', 's' }),
                    -- Tab backwards through suggestions or when a snippet is active, tab to the next argument
                    ['<S-Tab>'] = cmp.mapping(function(fallback)
                        if cmp.visible() then
                            cmp.select_prev_item()
                        elseif luasnip.locally_jumpable(-1) then
                            luasnip.jump(-1)
                        else
                            fallback()
                        end
                    end, { 'i', 's' }),
                }),
                sources = cmp.config.sources({
                    { name = 'omni' }, -- Omni completions for LaTeX
                    { name = 'nvim_lsp' },
                    { name = 'luasnip'},
                    { name = 'buffer' },
                    { name = 'path' },
                    { name = 'vimtex' },
                }),
                require('cmp_vimtex').setup()
            })
        end,
    },
}
