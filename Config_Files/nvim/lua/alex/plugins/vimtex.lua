return {
    "lervag/vimtex",
    lazy = false,     -- we don't want to lazy load VimTeX
    init = function()
        vim.g.vimtex_quickfix_open_on_warning = 0
        vim.g.vimtex_quickfix_mode = 1
        vim.g.vimtex_view_method = 'zathura'
        vim.g.vimtex_view_zathura_use_xdotool = 0   -- don't try to fetch a window id
        -- vim.g.vimtex_view_zathura_options = '-l debug --fork'  -- don't block Neovim on launch
        vim.g.vimtex_context_bib = '/home/alex/Zotero/MyLibrary.bib'
        vim.g.vimtex_quickfix_mode = 1 -- suppress error reporting on save and build
        vim.g.tex_flavor = 'latex'
        -- vim.g.vimtex_view_forward_search_on_start
        vim.g.vimtex_compiler_latexmk = {
            options = {
                "--lualatex",
                "--shell-escape",
                "-verbose",
                "-file-line-error",
                "-synctex=1",
                "-interaction=nonstopmode",
            }
        }
    end
}
