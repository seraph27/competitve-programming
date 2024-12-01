import subprocess
import os

a_exec = "./a"
b_exec = "./b"
iter = 100

for i in range(1, iter + 1):
    print(f"Iteration {i}")
    # Run the Ruby script and redirect output to 'in' file
    with open("in", "w") as infile:
        subprocess.run(["ruby", "a.rb"], stdout=infile)
    
    # Execute a_exec and b_exec and capture their outputs
    with open("in", "r") as infile, open("out1", "w") as outfile1:
        subprocess.run(a_exec, stdin=infile, stdout=outfile1)
    
    with open("in", "r") as infile, open("out2", "w") as outfile2:
        subprocess.run(b_exec, stdin=infile, stdout=outfile2)
    
    # Compare outputs using diff-like behavior in Python
    with open("out1", "r") as file1, open("out2", "r") as file2:
        out1_content = file1.read().strip()
        out2_content = file2.read().strip()

        if out1_content != out2_content:
            print(f"Mismatch found at iteration {i}. Input:")
            with open("in", "r") as infile:
                print(infile.read())

            # Print the difference between the correct output (out1) and the wrong output (out2)
            print("\n--- Correct Output (out1): ---")
            print(out1_content)
            print("\n--- Wrong Output (out2): ---")
            print(out2_content)

            # Display a detailed difference line by line
            print("\n--- Detailed Differences: ---")
            out1_lines = out1_content.splitlines()
            out2_lines = out2_content.splitlines()

            for line in range(max(len(out1_lines), len(out2_lines))):
                correct_line = out1_lines[line] if line < len(out1_lines) else "<No line>"
                wrong_line = out2_lines[line] if line < len(out2_lines) else "<No line>"

                if correct_line != wrong_line:
                    print(f"Line {line + 1}:")
                    print(f"  Correct: {correct_line}")
                    print(f"  Wrong:   {wrong_line}")
            
            break

# Clean up the files
