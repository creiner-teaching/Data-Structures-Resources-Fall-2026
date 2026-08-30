-- return {
--     {
--         -- LSP/smart-language related package manager
--         "williamboman/mason.nvim",
--         config = function()
--             require("mason").setup()
--         end,
--     },
--     {
--         -- Allows mason to talk to lsp-config
--         "williamboman/mason-lspconfig.nvim",
--         dependencies = { "mason.nvim" }, -- makes sure that mason runs/installs before this
--         config = function()
--             require("mason-lspconfig").setup({
--                 ensure_installed = { 'pyright', 'lua_ls', 'bashls', 'texlab', 'powershell_es' },
--             })
--         end,
--     },
--     {
--         -- Allows lsp-config to talk to mason
--         "neovim/nvim-lspconfig",
--         dependencies = {
--             "hrsh7th/cmp-nvim-lsp",
--             { "antosha417/nvim-lsp-file-operations", config = true }, -- Extra functionality for actions between files
--             { "folke/neodev.nvim", opts = {}} -- Extra functionality for lua specifically
--         },
--         config = function()
--             -- local lspconfig = vim.lsp.config
--             local capabilities = require('cmp_nvim_lsp').default_capabilities()
            
--             capabilities.textDocument.foldingRange = {
--                 dynamicRegistration = false,
--                 lineFoldingOnly = true
--             }

--             vim.lsp.config.lua_ls.setup({
--                 capabilities = capabilities
--             })
--             vim.lsp.config.pyright.setup({
--                 capabilities = capabilities,
--                 -- params['settings'] = {
--                 --     python = {
--                 --         pythonPath = require('modules.globals').python_path
--                 --     }
--                 -- }
--             })
--             vim.lsp.config.bashls.setup({
--                 capabilities = capabilities
--             })
--             vim.lsp.config.texlab.setup({
--                 capabilities = capabilities
--             })
--             vim.lsp.config.powershell_es.setup({
--                 capabilities = capabilities,
--                 filetypes = { 'ps1', 'psm1', 'psd1', 'bat' },
--                 -- bundle_path = "~/.local/share/nvim/mason/packages/powershell-editor-services/PowerShellEditorServices"
--                 bundle_path = "~/github/PowerShellEditorServices"
--             })
--         end,
--     },
--     {
--         -- Non lsp stuff like formatters and linters
--         "WhoIsSethDaniel/mason-tool-installer.nvim",
--         dependencies = { "mason.nvim" },
--         config = function()
--             ensure_installed = { "debugpy" }
--         end,
--     },
-- }

return {
  {
    -- LSP/smart-language related package manager
    "williamboman/mason.nvim",
    config = function()
      require("mason").setup()
    end,
  },
  {
    -- Allows mason to talk to lsp-config
    "williamboman/mason-lspconfig.nvim",
    dependencies = { "mason.nvim" },
    config = function()
      require("mason-lspconfig").setup({
        ensure_installed = { "pyright", "lua_ls", "bashls", "texlab", "powershell_es" },
      })
    end,
  },
  {
    -- Core LSP configs (new API)
    "neovim/nvim-lspconfig",
    dependencies = {
      "hrsh7th/cmp-nvim-lsp",
      { "antosha417/nvim-lsp-file-operations", config = true },
      { "folke/neodev.nvim", opts = {} }, -- safe to keep
    },
    config = function()
      local mlsp = require("mason-lspconfig")

      -- capabilities
      local capabilities = require("cmp_nvim_lsp").default_capabilities()
      capabilities.textDocument.foldingRange = {
        dynamicRegistration = false,
        lineFoldingOnly = true,
      }

      -- (optional) shared on_attach
      local on_attach = function(client, bufnr)
        -- your keymaps, etc.
      end

      -- NEW STYLE: assign tables; no .setup()
      vim.lsp.config.lua_ls = {
        on_attach = on_attach,
        capabilities = capabilities,
        settings = {
          Lua = {
            diagnostics = { globals = { "vim" } },
            workspace = { checkThirdParty = false },
          },
        },
      }

      vim.lsp.config.pyright = {
        on_attach = on_attach,
        capabilities = capabilities,
      }

      vim.lsp.config.clangd = {
                cmd = {
                    "clangd",
                    "--background-index",
                    "--log=verbose"
                }
            }

      vim.lsp.config.bashls = {
        on_attach = on_attach,
        capabilities = capabilities,
      }

      vim.lsp.config.texlab = {
        on_attach = on_attach,
        capabilities = capabilities,
        filetypes = { "tex", "plaintex", "bib" },
        -- settings = { texlab = { build = { onSave = true } } },
      }

      vim.lsp.config.powershell_es = {
        on_attach = on_attach,
        capabilities = capabilities,
        filetypes = { "ps1", "psm1", "psd1" }, -- (drop 'bat': that’s not powershell)
        -- If you’re not using Mason’s PSES, set cmd/bundle_path explicitly:
        -- cmd = {
        --   "pwsh", "-NoLogo", "-NoProfile", "-Command",
        --   "/absolute/path/to/PowerShellEditorServices/Start-EditorServices.ps1",
        --   "-HostName","nvim","-HostProfileId","0","-HostVersion","1.0.0",
        --   "-BundledModulesPath","/absolute/path/to/PowerShellEditorServices",
        --   "-Stdio","-LogLevel","Normal"
        -- },
      }

      -- Enable the servers (prefer what Mason actually has)
      local installed = mlsp.get_installed_servers()
      if #installed > 0 then
        vim.lsp.enable(installed)
      else
        vim.lsp.enable({ "lua_ls", "pyright", "bashls", "texlab", "powershell_es" })
      end
    end,
  },
  {
    -- Non-LSP stuff like formatters/linters
    "WhoIsSethDaniel/mason-tool-installer.nvim",
    dependencies = { "mason.nvim" },
    config = function()
      require("mason-tool-installer").setup({
        ensure_installed = { "debugpy" },
        auto_update = false,
        run_on_start = true,
      })
    end,
  },
}
