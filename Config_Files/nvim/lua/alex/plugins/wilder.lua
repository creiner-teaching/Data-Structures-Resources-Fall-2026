local function get_hl_color(hlgroup, attr)
    local color = vim.api.nvim_get_hl(0, { name = hlgroup })[attr]
    return string.format("#%06x", color)
end

return {
    "gelguy/wilder.nvim",
    dependencies = {"romgrk/fzy-lua-native"},
    config = function()
        vim.cmd.colorscheme(require('modules.globals').default_color)
        local wilder = require('wilder')
        wilder.setup( { modes = { ":", "/", "?" } } )
        wilder.set_option('use_python_remote_plugin', 0)

        -- Enable fuzzy finding
        wilder.set_option("pipeline", {
            wilder.branch(
                wilder.cmdline_pipeline({
                    fuzzy = 1,
                    fuzzy_filter = wilder.lua_fzy_filter(),
                }),
                wilder.vim_search_pipeline()
            )
        })

        local background = vim.o.background
        local is_dark = background == "dark"

        local text_color = is_dark and get_hl_color("Normal", "fg") or get_hl_color("Normal", "bg")
        local mauve_color = get_hl_color("Identifier", "fg")

        local text_highlight = wilder.make_hl("WilderText", { { a = 1 }, { a = 1 }, { foreground = text_color } })
        local mauve_highlight = wilder.make_hl("WilderMauve", { { a = 1 }, { a = 1 }, { foreground = mauve_color } })

        wilder.set_option(
            "renderer",
            wilder.popupmenu_renderer(wilder.popupmenu_border_theme({
                highlighter = wilder.basic_highlighter(),
                highlights = {
                    default = text_highlight,
                    border = mauve_highlight,
                    accent = mauve_highlight
                },
                pumplend = 5,
                min_width = "50%",
                min_height = "25%",
                max_height = "25%",
                border = "rounded",
                left = { " ", wilder.popupmenu_devicons() },
                right = { " ", wilder.popupmenu_scrollbar() },
            }))
        )
    end
}
