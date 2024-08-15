import re

def remove_first_two_numbers(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    modified_lines = [re.sub(r'^\d{2}\s*', '', line) for line in lines]

    with open(file_path, 'w') as file:
        file.writelines(modified_lines)

def main():
    file_path = input("Introduce la ruta del archivo: ")
    remove_first_two_numbers(file_path)
    print("Los dos primeros números han sido eliminados de cada línea.")

if __name__ == "__main__":
    main()
