import tkinter as tk
import tkinter.font as tkFont
import can

TEXT_GAME = False

window = tk.Tk()#bg="red4")

font = tkFont.Font(family="Lucida Grande", size=17)
font2 = tkFont.Font(family="Lucida Grande", size=32)

PLAYER = 0

PLAYERS = ["X","O"]

GRID = [[" ", " ", " "],[" ", " ", " "],[" ", " ", " "]]

INSTRUCTIONS = ["This is the grid. A space represents an empty cell.",
                "X represents player 1's moves, O represents player 2's.",
                "To make a move, input two digits which are coordinates:",
                "The first one represents going down, the second going across."]

INSTRUCTIONS2 = ["This is the grid. An empty cell can be clicked on.",
                "X represents player 1's moves, O represents player 2's.",
                "To make a move, click on an empty cell!"]

def instruct_player():
    for instruction in INSTRUCTIONS:
        print(instruction)


def print_to_gui(thing):
    greeting = tk.Label(text=thing, font=font)
    greeting.pack()

def print_row(row):
    print("[", end="")
    for i in range(0, len(row)):
        print(row[i], end="")
    print("]")

def print_grid(griddy):
    for i in range(0, len(griddy)):
        print_row(griddy[i])

def griddle_of_justice():
    pass


# LOGIC
def check_board_full(griddy):
    for i in range(0, len(griddy)):
        for j in range(0, len(griddy[i])):
            if griddy[i][j] == " ":
                return False
    return True

def check_row(griddy, row):
    counter = [0, 0]
    for i in range(len(griddy[0])):
        if griddy[row][i] == PLAYERS[0]:
            counter[0] += 1
        if griddy[row][i] == PLAYERS[1]:
            counter[1] += 1
    if counter[0] == len(griddy[0]):
        return 0
    if counter[1] == len(griddy[0]):
        return 1
    return 2

def check_column(griddy, col):
    counter = [0, 0]
    for i in range(len(griddy)):
        if griddy[i][col] == PLAYERS[0]:
            counter[0] += 1
        if griddy[i][col] == PLAYERS[1]:
            counter[1] += 1
    if counter[0] == len(griddy):
        return 0
    if counter[1] == len(griddy):
        return 1
    return 2

def check_diagonals(griddy):
    dim1 = len(griddy)
    dim2 = len(griddy[0])
    the_dim = min(dim1, dim2)
    counter1 = [0, 0]
    counter2 = [0, 0]
    
    for i in range(the_dim):
        if griddy[i][i] == PLAYERS[0]:
            counter1[0] += 1
        if griddy[i][i] == PLAYERS[1]:
            counter1[1] += 1
        if griddy[dim1-1-i][i] == PLAYERS[0]:
            counter2[0] += 1
        if griddy[dim1-1-i][i] == PLAYERS[1]:
            counter2[1] += 1
    if counter1[0] == the_dim or counter2[0] == the_dim:
        return 0
    if counter1[1] == the_dim or counter2[1] == the_dim:
        return 1
    return 2

def check_win_state(griddy):
    for i in range(len(griddy)):
        var = check_row(griddy, i)
        if var != 2:
            print("Congratulations, player " + str(var+1) + ", YOU WON!")
            return "end"
    for i in range(len(griddy[0])):
        var = check_column(griddy, i)
        if var != 2:
            print("Congratulations, player " + str(var+1) + ", YOU WON!")
            return "end"
    if check_diagonals(griddy) != 2:
            print("Congratulations, player " + str(var+1) + ", YOU WON!")
            return "end"
    if check_board_full(griddy):
        print("The game ended in a tie.")
        return "end"
    return "continue"

def take_input_text(griddy, player):
    print("Player " + str(player+1) + "'s turn:")
    input_boi = input()#should be a tuple, 0,2 being top right
    if griddy[int(input_boi[0])][int(input_boi[1])] == " ":
        griddy[int(input_boi[0])][int(input_boi[1])] = PLAYERS[player]#assuming player is 0 or 1
        print_grid(griddy)
        if check_win_state(griddy) == "continue":
            take_input_text(griddy, (player+1)%2)
    else:
        if check_board_full(griddy):
            check_win_state(griddy)
        else:
            print("That cell is already full!")
            print_grid(griddy)
            take_input_text(griddy, player)

ref = {}

def get_player():
    global PLAYER
    return PLAYER

def tl(player):
    global GRID
    print(ref[tl])
    gui_process_move(GRID, ref[tl], player)
    return ref[tl]

def tm(player):
    global GRID
    print(ref[tm])
    gui_process_move(GRID, ref[tm], player)
    return ref[tm]

def tr(player):
    global GRID
    print(ref[tr])
    gui_process_move(GRID, ref[tr], player)
    return ref[tr]

def ml(player):
    global GRID
    print(ref[ml])
    gui_process_move(GRID, ref[ml], player)
    return ref[ml]

def mm(player):
    global GRID
    print(ref[mm])
    gui_process_move(GRID, ref[mm], player)
    return ref[mm]

def mr(player):
    global GRID
    print(ref[mr])
    gui_process_move(GRID, ref[mr], player)
    return ref[mr]

def bl(player):
    global GRID
    print(ref[bl])
    gui_process_move(GRID, ref[bl], player)
    return ref[bl]

def bm(player):
    global GRID
    print(ref[bm])
    gui_process_move(GRID, ref[bm], player)
    return ref[bm]

def br(player):
    global GRID
    print(ref[br])
    gui_process_move(GRID, ref[br], player)
    return ref[br]

ref = {tl: "00", tm: "01", tr: "02",
       ml: "10", mm: "11", mr: "12",
       bl: "20", bm: "21", br: "22"}

reverse = {"00": tl, "01": tm, "02": tr,
           "10": ml, "11": mm, "12": mr,
           "20": bl, "21": bm, "22": br}

list_btns = []

def nums(k, j):
    return f"{k}{j}"

def set_up_gui(reverse):
    global list_btns, label1, label2, PLAYER
    for i in range(0, 6):
        window.columnconfigure(i, weight=1, minsize=0)
        window.rowconfigure(i, weight=1, minsize=75)

        if i < 3:
            list_btns.append([])

        if i >= 2 and i < 5:
            for j in range(0, 3):
              #if j > 0:
                frame = tk.Frame(
                    master=window,
                    relief=tk.RAISED,
                    #borderwidth=1
                )
                frame.grid(row=i, column=j, padx=15, pady=15)
                
                k = i-2
                key = f"{k}{j}"
                
                #print(str(k) + " " + str(j))
                #button = tk.Button(
                list_btns[i-2].append(tk.Button(
                    text=f"{GRID[k][j]}", width=15, height=5,
                    bg="pink",
                    fg="IndianRed1",
                    master=frame,
                    font=font2,
                    command=lambda key=key: reverse[key](get_player())
                ))
                #print(button)
                #print("argh")
                #button.bind(f"<Button-{k}-{j}>", reverse[f"{k}{j}"]())

                #list_btns[i-2].append(button)
                
                #button['text'] = "HEnLo"
                #label = tk.Label(bg="red4", fg="pink", font=font, text="HI!")
                #label.pack()
                
                #button.pack()
                list_btns[i-2][j].pack()

    label1 = tk.Label(bg="red4", fg="pink", font=font, text=INSTRUCTIONS2[0]+"\n"
                                                           +INSTRUCTIONS2[1]+"\n"
                                                           +INSTRUCTIONS2[2])
    label1.grid(row=0, column=0, columnspan=3, sticky="n")

    label2 = tk.Label(bg="red4", fg="pink", font=font2, text="HI!")
    label2.grid(row=6, column=0, columnspan=3)

def check_win_state(griddy):
    global list_btns, label1, label2
    for i in range(len(griddy)):
        var = check_row(griddy, i)
        if var != 2:
            label2['text'] = "Congratulations, player " + str(var+1) + ", YOU WON!"
            return "end"
    for i in range(len(griddy[0])):
        var = check_column(griddy, i)
        if var != 2:
            label2['text'] = "Congratulations, player " + str(var+1) + ", YOU WON!"
            return "end"
    var = check_diagonals(griddy)
    if var != 2:
        label2['text'] = "Congratulations, player " + str(var+1) + ", YOU WON!"
        return "end"
    if check_board_full(griddy):
        label2['text'] = "The game ended in a tie."
        return "end"
    return "continue"

def end_game():
    global list_btns
    for i in range(0, len(list_btns)):
        for j in range(0, len(list_btns[i])):
            list_btns[i][j]['state'] = tk.DISABLED

def gui_process_move(griddy, input_boi, player):
    global list_btns, label1, label2, PLAYER
    #player = 0
    #print(input_boi)
    
    print("Player " + str(player+1) + "'s turn:")
    #input_boi = input()
    
    if griddy[int(input_boi[0])][int(input_boi[1])] == " ":
        griddy[int(input_boi[0])][int(input_boi[1])] = PLAYERS[player]#assuming player is 0 or 1
        print_grid(griddy)
        #print(list_btns)
        #print(PLAYERS[player])
        #print("AAAAA")
        list_btns[int(input_boi[0])][int(input_boi[1])]['text'] = PLAYERS[player]
        if check_win_state(griddy) == "continue":
            PLAYER = (player+1)%2
        else:
            end_game()
    else:
        if check_board_full(griddy):
            if check_win_state(griddy) == "end":
                end_game()
        else:
            print("That cell is already full!")
            #print_grid(griddy)
            #gui_process_move(griddy, input_boi, player)
            PLAYER = player




if TEXT_GAME:
    instruct_player()
    print_grid(GRID)
    take_input_text(GRID, 0)
else:
    set_up_gui(reverse)

    #
        
    window.mainloop()




'''
print_to_gui("Hello world")
print_to_gui("Hello world2")

button = tk.Button(
    text="Click me!",
    width=15,
    height=5,
    bg="pink",
    fg="purple",
)
button.pack(side=tk.LEFT)

button2 = tk.Button(
    text="Click me!",
    width=15,
    height=5,
    bg="pink",
    fg="purple",
)
button2.pack(side=tk.LEFT)

button3 = tk.Button(
    text="Click me!",
    width=15,
    height=5,
    bg="pink",
    fg="purple",
)
button3.pack(side=tk.LEFT)


frame_a = tk.Frame()
frame_b = tk.Frame()'''

'''
label_a = tk.Label(master=frame_a, text="I'm in Frame A", bg="red")
label_a.pack()

label_b = tk.Label(master=frame_b, text="I'm in Frame B", bg="pink")
label_b.pack()
'''

'''
label = tk.Label(
    text="Hello, Tkinter",
    fg="white",
    bg="black",
    width=10,
    height=10,
    master=frame_a
)
label.pack()
'''
'''
frame_a.pack()
frame_b.pack()

frame1 = tk.Frame(master=window, width=100, bg="red")
frame1.pack(side=tk.LEFT)

frame2 = tk.Frame(master=window, width=100, bg="yellow")
frame2.pack(side=tk.LEFT)

frame3 = tk.Frame(master=window, width=100, bg="blue")
frame3.pack(side=tk.LEFT)'''



