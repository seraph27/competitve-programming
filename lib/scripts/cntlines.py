import os

def dfs(path):
    total_lines = 0
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(".cpp"):
                file_path = os.path.join(root, file)
                with open(file_path, 'r', encoding='utf-8') as f:
                    cnt=sum(1 for line in f)
                total_lines+=cnt
    return total_lines

path = "../competitve-programming/"
lines = dfs(path)
print(lines)
