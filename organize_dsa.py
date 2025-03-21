import os
import shutil
import re

def create_directory(path):
    if not os.path.exists(path):
        os.makedirs(path)
        print(f"Created directory: {path}")

def move_file(source, destination):
    if os.path.exists(source):
        dirname = os.path.dirname(destination)
        if not os.path.exists(dirname):
            os.makedirs(dirname)
        
        if os.path.exists(destination):
            base, ext = os.path.splitext(destination)
            counter = 1
            new_destination = f"{base}_{counter}{ext}"
            while os.path.exists(new_destination):
                counter += 1
                new_destination = f"{base}_{counter}{ext}"
            destination = new_destination
            
        shutil.copy2(source, destination)
        print(f"Copied: {source} -> {destination}")
    else:
        print(f"Source file does not exist: {source}")

def organize_dsa_content():
    # Create topic directories
    topics = {
        "BST": ["69 BST", "70 bst", "71 bst", "72 bst", "73 bst"],
        "Tree_Algorithms": ["68 Morris Traversal Flatten a Binary tree to Linked List"],
        "Heap": ["74 heap", "75 heap", "76 heap", "77 heap"],
        "HashMap": ["78 hashmap"],
        "Trie": ["79  trie"],
        "Graph": ["lec 84", "lec 85", "lec 86", "lec 87", "lec 88", "lec 89", "lec 90", 
                  "lec 91", "lec 92", "lec 93", "lec 94", "lec 95", "lec 96", "lec 97", "lec 98"]
    }
    
    # Create organized directory structure
    base_dir = "DSA_Organized"
    create_directory(base_dir)
    
    # Create topic directories
    for topic in topics.keys():
        create_directory(os.path.join(base_dir, topic))
    
    # Copy files to organized structure
    for topic, folders in topics.items():
        for folder in folders:
            if os.path.exists(folder):
                lecture_number = re.search(r'\d+', folder).group(0)
                lecture_dir = os.path.join(base_dir, topic, f"Lecture_{lecture_number}")
                
                # List files in the source directory
                if os.path.isdir(folder):
                    for file in os.listdir(folder):
                        source_path = os.path.join(folder, file)
                        if os.path.isfile(source_path):
                            dest_path = os.path.join(lecture_dir, file)
                            move_file(source_path, dest_path)
    
    # Handle standalone files
    standalone_files = ["find_similarities_two_array.cpp", "maxm_repeating_no.cpp", "1.cpp"]
    misc_dir = os.path.join(base_dir, "Misc")
    create_directory(misc_dir)
    
    for file in standalone_files:
        if os.path.exists(file):
            dest_path = os.path.join(misc_dir, file)
            move_file(file, dest_path)
    
    print("Organization complete!")

if __name__ == "__main__":
    organize_dsa_content() 