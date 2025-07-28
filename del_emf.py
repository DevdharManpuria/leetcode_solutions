import os

def del_emf(folder):
    empty_files = []

    for root, dirs, files in os.walk(folder):
        for file in files:
            full_path = os.path.join(root, file)
            if os.path.isfile(full_path) and os.path.getsize(full_path) == 0:
                empty_files.append(full_path)

    if not empty_files:
        print("✅ No empty files found.")
        return

    print("\n⚠️ Empty files found:")
    for file in empty_files:
        print(f" - {file}")

    choice = input("\n🗑️ Do you want to delete ALL these files? (y/n): ").strip().lower()
    if choice == 'y':
        for file in empty_files:
            try:
                os.remove(file)
                print(f"✅ Deleted: {file}")
            except Exception as e:
                print(f"❌ Failed to delete {file}: {e}")
    else:
        print("❎ No files were deleted.")

if __name__ == "__main__":
    current_dir = os.getcwd()
    print(f"📁 Scanning current folder: {current_dir}")
    del_emf(current_dir)
