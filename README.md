# Homework-5

Run the program like this: `.\HW5.exe 5` for 5 moves

Running the program without a number of moves will run until a team is eliminated
- Chance for a double jump if you do this, as the moves are random
- Look for a "--->" in "output.txt", this means a multi jump occurred

Rename the "checkerBoard-DoubleJump.txt" file to "checkerBoard.txt" to see double jumping

## Description of output file
- ->? means it considered a single hop
- -->? means it considered a single jump
- --->? means it considered a multi jump
- Each of these without the "?" means that it's the choice it took
- The board is also displayed after every move

### WARNING
- Sometimes the game can get stuck if you run it without a maximum number of moves
- This is because it always moves the top left most piece, and may get stuck moving
that single piece around the board forever
- Ctrl + C will kill the program if this happens
