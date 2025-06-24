import os

for file in os.listdir("."):
    if file.endswith(".md") and os.path.isfile(file):
        os.remove(file)
        print(f"Deleted {file}")

print("✅ All root .md files deleted.")
