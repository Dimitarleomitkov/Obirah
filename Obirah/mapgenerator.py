import sys

# Count the characters on a line and the lines
n_symbols = 0;
n_lines = 0;

fr = open (f"{sys.argv[1]}", "r");
for symbol in fr.readline():
	n_symbols += 1;
n_symbols = int(n_symbols / 2);

fr = open (f"{sys.argv[1]}", "r");
for line in fr:
	n_lines += 1;


def notation_to_obj(tile_obj):
	if (tile_obj == " "):
		return "EMPTY"
	elif (tile_obj == "O"):
		return "PLAYER"
	elif (tile_obj == "N"):
		return "EMPTY"
	elif (tile_obj == "X"):
		return "ENEMY"
	elif (tile_obj == "D"):
		return "DOOR"
	elif (tile_obj == "G"):
		return "GATE"
	elif (tile_obj == "T"):
		return "TREE"
	elif (tile_obj == "*"):
		return "BUSH"
	elif (tile_obj == "H"):
		return "ROAD"
	elif (tile_obj == "|"):
		return "WALL"
	elif (tile_obj == "_"):
		return "DOWNWALL"
	elif (tile_obj == "?"):
		return "UNKNOWN"

new_file_name = "GeneratedMap.cpp"
fw = open (f"{new_file_name}", "w");
fr = open (f"{sys.argv[1]}", "r");
row = 0;
column = 0;
tile_obj = " ";

fw.write (f"\t// Despawn the NPCs\n\tgamespace.despawn_npcs ();\n\n\t// Clear all tiles\n\tgamespace.clear_tiles ();\n\n");
fw.write (f"\t// Set the height and width for the level\n");
fw.write (f"\tgamespace.set_map_width ({n_symbols});\n");
fw.write (f"\tgamespace.set_map_height ({n_lines});\n\n");
fw.write (f"\t// Make a working copy of the width and height for this function\n");
fw.write (f"\tuint8_t map_width = gamespace.get_map_width ();\n");
fw.write (f"\tuint8_t map_height = gamespace.get_map_height ();\n\n");
fw.write (f"\t// Create the map\n");
fw.write (f"\tuint16_t* dummy_map_tiles = new uint16_t[map_width * map_height];\n\n");

for i in range (n_symbols * n_lines):
	tile_obj = fr.read(1);
	# Get rid of the space
	fr.read(1);
	# Write down the function
	fw.write (f"\tdummy_map_tiles[{row} * {n_symbols} + {column}] = {notation_to_obj(tile_obj)};\n");
	column += 1;
	if (column % n_symbols == 0):
		row += 1;
		column = 0;


fw.write (f"\t// NPCs\n\n\n");
fw.write (f"\t// Enemies\n\n\n");

fw.write (f"\t// Set the map in the gamespace\n");
fw.write (f"\tgamespace.set_map_tiles (map_width * map_height, dummy_map_tiles);\n");

print ("Created a file with the commands for the map.");