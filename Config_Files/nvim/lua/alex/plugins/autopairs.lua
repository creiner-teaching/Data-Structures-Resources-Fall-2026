return {
    "windwp/nvim-autopairs",
    dependencies = {
        "hrsh7th/nvim-cmp",
    },
    config = function()
        local npairs = require('nvim-autopairs')
        npairs.setup({
            check_ts = true,
            ts_config = {
                lua = { "string" }, --???
            },

        })
        local cmp_autopairs = require("nvim-autopairs.completion.cmp")
        local cmp = require("cmp")
        cmp.event:on("confirm_done", cmp_autopairs.on_confirm_done())

        local Rule = require('nvim-autopairs.rule')
        npairs.add_rules({
            Rule('$', '$', {'tex', 'latex'}),
            Rule("`", "'", {'tex', 'latex'}),
            Rule("\\[", "\\]", {'tex', 'latex'})
        })
    end
}
