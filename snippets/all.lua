--- ~/.config/nvim/snippets/cpp.lua
local ls = require("luasnip")
local s, t, i = ls.snippet, ls.text_node, ls.insert_node

return {
  cpp = {
    s("inc", {
      t("#include <"), i(1, "iostream"), t(">"),
    }),
  },
}
