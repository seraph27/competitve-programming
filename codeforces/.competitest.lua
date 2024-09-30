-- .competitest.lua content
return {
    template_file = "/home/seraph/competitve-programming/lib/codeforces.cpp",

    -- received_contests_directory = "$(CONTEST)",
    -- received_contests_problems_path = function(task, file_extension)
    --     local problem_letter = string.match(task.name, "^%u%d?")
    --     if not problem_letter then
    --         problem_letter = task.name
    --     else
    --         problem_letter = string.lower(problem_letter)
    --     end
    --     return string.format("%s.%s",
    --         problem_letter,
    --         file_extension
    --     )
    -- end,
}
