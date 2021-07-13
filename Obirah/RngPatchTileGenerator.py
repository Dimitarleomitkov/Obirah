import sys
import random

# Count the characters on a line and the lines
if (len(sys.argv) != 3):
	print ("You need to provide width and height.");
	exit();

width = sys.argv[1];
height = sys.argv[2];

usable_tiles = ["T", "*", "~", " "];

new_file_name = "z_rngterrain.txt"
fw = open (f"{new_file_name}", "w");

for i in range (int(height)):
	for j in range (int(width)):
		fw.write (f"{random.choice(usable_tiles)} ");
	fw.write ("\n");

print ("Done");