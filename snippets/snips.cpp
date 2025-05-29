local ls = require("luasnip")
local s, t = ls.snippet, ls.text_node

return {
  all = {
    s("foo", t("bar")),  -- shows up in every file
  },
  cpp = {
    s("inc", {
      t("#include <"), t("iostream"), t(">"),
    }),
  },
}
