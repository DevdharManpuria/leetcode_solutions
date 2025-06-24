import os
import subprocess

# Extensions and language folders
EXTS = [".py", ".cpp", ".java", ".js", ".go"]
ROOT = "."

uploaded = []

# Get list of all tracked files using git
output = subprocess.check_output(["git", "ls-files"], cwd=ROOT).decode().splitlines()

for filepath in output:
    if any(filepath.endswith(ext) for ext in EXTS):
        uploaded.append(filepath)

# Write to uploaded.txt
with open(os.path.join(ROOT, "uploaded.txt"), "w") as f:
    for file in sorted(uploaded):
        f.write(file + "\n")

print(f"✅ Rewritten uploaded.txt with {len(uploaded)} files.")
