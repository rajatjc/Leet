import os
import shutil

# Replace these paths with your actual source and destination folder paths
source_folder = "/home/rajat/IdeaProjects/Leet/Codeforces"
destination_folder = "/home/rajat/IdeaProjects/Leet/Codeforces"

# Get a list of all items in the source folder (files and folders)
items_list = os.listdir(source_folder)

# Create folders based on the first 3 digits of the file names and move files
for item_name in items_list:
    item_path = os.path.join(source_folder, item_name)
    
    # Check if the item is a file and not a folder
    if os.path.isfile(item_path):
        if len(item_name) >= 3 and item_name[:3].isdigit():
            folder_name = item_name[:3]
            folder_path = os.path.join(destination_folder, folder_name)
            
            # Create the folder if it doesn't exist
            if not os.path.exists(folder_path):
                os.makedirs(folder_path)
            
            # Move the file to the corresponding folder
            new_item_path = os.path.join(folder_path, item_name)
            shutil.move(item_path, new_item_path)
            print(f"Moved {item_name} to {folder_name} folder.")
        else:
            print(f"Ignored {item_name} as it doesn't have a valid format.")
    else:
        print(f"Ignored {item_name} as it is a folder.")
