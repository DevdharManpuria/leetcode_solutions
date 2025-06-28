import os
import re
import subprocess
import shutil

def create_files(problem_str):
    # Step 1: Extract number and title
    match = re.match(r"(\d+)[\.\s-]*(.+)", problem_str.strip())
    if not match:
        print("❌ Invalid input format. Use: '1 Two Sum' or '2099. Some Problem'")
        return

    number = int(match.group(1))
    title = match.group(2)

    # Step 2: Format number to 4-digit string
    number_str = f"{number:04d}"

    # Step 3: Convert title to kebab-case
    kebab_title = re.sub(r'[^a-z0-9]+', '-', title.lower()).strip('-')
    filename_base = f"{number_str}-{kebab_title}"

    # Step 4: Folder names and extensions
    folders = {
        "cpp": "cpp",
        "java": "java",
        "python": "python",
        "go": "go"
    }
    extensions = {
        "cpp": ".cpp",
        "java": ".java",
        "python": ".py",
        "go": ".go"
    }

    # Step 5: Create and collect file paths
    created_files = []
    for lang in folders:
        folder = folders[lang]
        ext = extensions[lang]
        os.makedirs(folder, exist_ok=True)
        file_path = os.path.join(folder, filename_base + ext)
        open(file_path, "w").close()  # Create empty file
        created_files.append(file_path)

    # Step 6: Open files using VS Code
    code_path = shutil.which("code")
    if code_path:
        subprocess.Popen([code_path] + created_files)
    else:
        print("❌ 'code' command not found. Make sure VS Code CLI is added to PATH.")

    # Step 7: Print result
    print("\n✅ Created and opened files:")
    for file in created_files:
        print("  -", file)

# Run the script
if __name__ == "__main__":
    input_str = input("Enter problem title (e.g. '1 Two Sum' or '2099. Some Problem'): ")
    create_files(input_str)
