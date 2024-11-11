import subprocess as sp
import os

a = "./a"
b = "./b"
it = 100

for i in range(1, it + 1):
    print(f"Iteration {i}")
    
    with open("in", "w") as f:
        sp.run(["ruby", "a.rb"], stdout=f)

    with open("in", "r") as f, open("out1", "w") as o1:
        sp.run(a, stdin=f, stdout=o1)
    
    with open("in", "r") as f, open("out2", "w") as o2:
        sp.run(b, stdin=f, stdout=o2)
    
    with open("out1", "r") as o1, open("out2", "r") as o2:
        o1_content = o1.read().strip()
        o2_content = o2.read().strip()

        if o1_content != o2_content:
            print(f"Mismatch at iteration {i}. Input:")
            with open("in", "r") as f:
                print(f.read())

            print("\n--- Correct Output (out1): ---")
            print(o1_content)
            print("\n--- Wrong Output (out2): ---")
            print(o2_content)

            print("\n--- Detailed Differences: ---")
            o1_lines = o1_content.splitlines()
            o2_lines = o2_content.splitlines()

            for ln in range(max(len(o1_lines), len(o2_lines))):
                cl = o1_lines[ln] if ln < len(o1_lines) else "<No line>"
                wl = o2_lines[ln] if ln < len(o2_lines) else "<No line>"

                if cl != wl:
                    print(f"Line {ln + 1}:")
                    print(f"  Correct: {cl}")
                    print(f"  Wrong:   {wl}")
            break

os.remove("out1")
os.remove("out2")
