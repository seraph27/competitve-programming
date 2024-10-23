import subprocess, os

a, b, iters = "./a", "./b", 100

for i in range(1, iters + 1):
    print(f"Iter {i}")
    subprocess.run(["ruby", "a.rb"], stdout=open("in", "w"))
    
    # Run a and b, capturing outputs
    out1 = subprocess.run(a, stdin=open("in"), capture_output=True, text=True).stdout.strip()
    out2 = subprocess.run(b, stdin=open("in"), capture_output=True, text=True).stdout.strip()
    
    # Compare outputs
    if out1 != out2:
        print(f"Mismatch at iter {i}. Input:\n{open('in').read()}")
        print("\n--- Correct (out1): ---\n", out1)
        print("\n--- Wrong (out2): ---\n", out2)
        print("\n--- Differences: ---")
        for ln, (l1, l2) in enumerate(zip(out1.splitlines(), out2.splitlines()), 1):
            if l1 != l2:
                print(f"Line {ln}:\n  Correct: {l1}\n  Wrong:   {l2}")
        break

os.remove("in")
