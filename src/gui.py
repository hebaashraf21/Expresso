import tkinter as tk
from tkinter import font
import os

def compile_code():
    # Get the input from the text box
    code = input_text.get("1.0", "end-1c")
    
    # Write the input code to a temporary file
    with open("temp_input.txt", "w") as f:
        f.write(code)
    
    # Run the compiler
    os.system("test.exe temp_input.txt")

    # Read the errors, symbol table, and quadruples from the generated files
    with open("quads.txt", "r") as f:
        quadruples = f.read()

    with open("symbol_table.txt", "r") as f:
        symbol_table = f.read()

    with open("errors.txt", "r") as f:
        errors = f.read()    

    quadruples_text.delete("1.0", "end")
    quadruples_text.insert("end", quadruples)

    symbol_table_text.delete("1.0", "end")
    symbol_table_text.insert("end", symbol_table)

    errors_text.delete("1.0", "end")
    errors_text.insert("end", errors)

    # Delete the temporary input file
    os.remove("temp_input.txt")

# Create the main window
root = tk.Tk()
root.title("Compiler GUI")
root.configure(bg="white")  # Set background color to white

# Set custom font
custom_font = font.Font(family="Helvetica", size=12)

# Create a blue banner with the label "expresso" in white
banner_label = tk.Label(root, text="Expresso", font=("Helvetica", 20, "bold"), fg="white", bg="#007bff", width=50, pady=10)
banner_label.pack(fill=tk.X)

# Create a frame for the left part of the window
left_frame = tk.Frame(root, bg="white")
left_frame.pack(side=tk.LEFT, fill=tk.BOTH, padx=10)

# Create a label for the input text box
source_label = tk.Label(left_frame, text="Source Code:", font=custom_font, bg="white")
source_label.pack()

# Create input text box with black border
input_text = tk.Text(left_frame, height=20, width=50, font=custom_font, bd=2, relief="solid")
input_text.pack()

# Create compile button
compile_button = tk.Button(left_frame, text="Compile", command=compile_code, font=custom_font, bg="#007bff", fg="white")
compile_button.pack(pady=10)

# Create a frame for the errors text box
errors_frame = tk.Frame(left_frame, bg="white", bd=2, relief="solid")
errors_frame.pack(fill=tk.BOTH, expand=True, pady=10)

errors_label = tk.Label(errors_frame, text="Errors:", font=custom_font, bg="white")
errors_label.pack()

errors_text = tk.Text(errors_frame, height=3, width=50, font=custom_font, bd=0, relief="solid")
errors_text.pack(fill=tk.BOTH, expand=True)

# Create a frame for the right part of the window
right_frame = tk.Frame(root, bg="white")
right_frame.pack(side=tk.LEFT, fill=tk.BOTH, padx=10)

# Create output text boxes with black border in the right frame
quadruples_label = tk.Label(right_frame, text="Quadruples:", font=custom_font, bg="white")
quadruples_label.pack()

# Create a frame for the quadruples text box
quadruples_frame = tk.Frame(right_frame, bd=2, relief="solid")
quadruples_frame.pack(fill=tk.BOTH, expand=True, pady=10)

quadruples_text = tk.Text(quadruples_frame, height=5, width=50, font=custom_font, bd=0, relief="solid")
quadruples_text.pack(fill=tk.BOTH, expand=True)

symbol_table_label = tk.Label(right_frame, text="Symbol Table:", font=custom_font, bg="white")
symbol_table_label.pack()

# Create a frame for the symbol table text box
symbol_table_frame = tk.Frame(right_frame, bd=2, relief="solid")
symbol_table_frame.pack(fill=tk.BOTH, expand=True, pady=10)

symbol_table_text = tk.Text(symbol_table_frame, height=5, width=50, font=custom_font, bd=0, relief="solid")
symbol_table_text.pack(fill=tk.BOTH, expand=True)

# Start the GUI event loop
root.mainloop()
