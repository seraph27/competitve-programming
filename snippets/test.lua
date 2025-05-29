-- ~/competitve-programming/snippets/test.lua
local ls = require("luasnip")
local s  = ls.snippet
local t  = ls.text_node

return {
  -- “all” makes it available in every filetype
  all = {
    s("foo", t("Hello → foo expanded!")),
  },
}
