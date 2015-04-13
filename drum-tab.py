import sys
import os

notes = [ ]

def Write(text, filename):
    """Write a file with the given name and the given text."""
    output = open(filename,"w")
    output.write(text)
    output.close()

def Read(filename):
	f = open (filename, 'r' )
	text = f.read()
	return text

os.system('clear')

song_name = raw_input("Song Title: ")
tab = Read(song_name+"-tab.txt")

tab_pos = 0
block_start = 0

initial_markers = [ ]

while (tab[tab_pos] != "%"):
	if tab[tab_pos] == "\n":
		initial_markers.append(tab_pos)
	tab_pos += 1

bpm = int(tab[5:initial_markers[0]])
bpb = int(tab[initial_markers[0]+6:initial_markers[1]])

while (tab[tab_pos] != "&"):
	while (tab[tab_pos] != "|"):
		if tab[tab_pos] == "S":
			current_drum = "snare"
		elif tab[tab_pos:tab_pos+2] == "HH":
			current_drum = "hihat"
		elif tab[tab_pos] == "B":
			current_drum = "bass"
		elif tab[tab_pos] == "HT":
			current_drum = "hightom"
		elif tab[tab_pos] == "R":
			current_drum = "ride"
		tab_pos += 1

	bar_start = tab_pos
	bar = block_start

	while (True):
		if (tab[tab_pos] == "o") or (tab[tab_pos] == "x") or (tab[tab_pos] == "f"):
			beat = tab_pos - bar_start
			char = tab[tab_pos]
			new_note = {"drum": current_drum, "bar": bar, "beat": beat, "char": char}
			notes.append(new_note)
		elif tab[tab_pos] == "|":
			bar_start = tab_pos
			bar += 1
		elif tab[tab_pos:tab_pos+2] == "\n\n":
			block_start = bar - 1
		elif tab[tab_pos] == "\n":
			tab_pos += 1
			break
		tab_pos += 1

velocity = bpm
total_note = "tank 10 40\n"

for x in range(0,len(notes)):
	if notes[x]["drum"] == "bass":
		position_x = 2
	elif notes[x]["drum"] == "hihat":
		position_x = 14
	elif notes[x]["drum"] == "snare":
		position_x = 8
	elif notes[x]["drum"] == "ride":
		position_x = 21
	else:
		position_x = 22
	position_y = ((notes[x]["bar"] - 1)*bpb) + notes[x]["beat"]
	note_string = "fish 1 1 " + str(-position_y) + " " + str(position_x) + " " + str(.2) + " 0 " + str(notes[x]["drum"]) + "\n" + notes[x]["char"] + "\n"
	total_note += note_string

Write(total_note, song_name+"Visual.dat")
print '"' + song_name + '" Interpreted...'
run_now = raw_input('Run visualization of "' + song_name + '" now (y/n)? ')

if run_now == 'y' or run_now == 'yes':
	os.system('./animator < ' + song_name + 'Visual.dat')



















