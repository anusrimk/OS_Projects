if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <file_or_directory_name>"
    exit 1
fi

name="$1"

if [ ! -e "$name" ]; then
    echo "Error: '$name' does not exist."
    exit 1
fi

if [ -f "$name" ]; then
    echo "$name is a regular file."
elif [ -d "$name" ]; then
    echo "$name is a directory."
else
    echo "$name is another type of file."
fi

ls -l "$name"
