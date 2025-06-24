import os
import re

# Folder names by language
LANG_FOLDERS = ["java", "python", "cpp", "javascript", "go"]

def pad_number(filename):
    match = re.match(r"(\d+)-(.*)", filename)
    if match:
        num, rest = match.groups()
        padded_num = num.zfill(4)  # Pad to 4 digits
        return f"{padded_num}-{rest}"
    return filename  # If doesn't match pattern, return as-is

def rename_files():
    for folder in LANG_FOLDERS:
        if not os.path.exists(folder):
            continue
        for file in os.listdir(folder):
            old_path = os.path.join(folder, file)
            if not os.path.isfile(old_path):
                continue
            new_name = pad_number(file)
            new_path = os.path.join(folder, new_name)
            if old_path != new_path:
                print(f"Renaming: {file} -> {new_name}")
                os.rename(old_path, new_path)

if __name__ == "__main__":
    rename_files()
    print("✅ All filenames padded!")
