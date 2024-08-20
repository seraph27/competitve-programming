-- .competitest.lua content
return {
    template_file = "C:/Users/rexch/OneDrive/Documents/competitve-programming/lib/mintemplate.cpp",
    received_problems_path = function(task, file_extension)
        local problem_letter = string.match(task.name, "^%u%d?")
        if not problem_letter then
            problem_letter = task.name
        else
            problem_letter = string.lower(problem_letter)
        end
        return string.format("%s/OneDrive/Documents/competitve-programming/qiita/%s.%s", vim.loop.os_homedir(), problem_letter, file_extension)
    end,
}