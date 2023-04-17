# Bewejeweled Blitz
1st Semester Project (22L-6699)(22L-6656):

The game is played over 60 seconds, tiles are randomly generated in the beginning and user can begin playing.
Movement:

User can move the selection cursor by using arrow keys

User can select a tile by pressing enter.

Pressing any arrow key after selecting a tile will swap that tile in the direction of the arrow key (given that a tile is available in the direction of swapping)

If a match is not made, the move is reversed.

Matching Logic:

The program runs in one big loop, in the beginning of the loop it checks for elbow combinations, then 5,4,3 in a row. If it finds any combination it sets them to empty and gives a special or destroyer gem if it is an elbow or a 4 gem combination.

The program sets the rightmost tile to the special gem in case of rows and the bottom tile to special gem in case of columns.

It sets destroyer gems on the tiles where the elbow bends.

Types of Gems:

There are 5 gem types in the game, each gemtype can be matched with itself only.

Each gemtype has 2 alternate gems, a special gem (White rectangle outline) and a destroyer gem (Fully red background).

Each normal gem is given a value on a multiple of 3, so 0,3,6,9,12 are normal gems

Each special gem is given a value on a multiple of 3+1, so 1,4,7,10,13 are special gems

Each destroyer gem is given a value on the multiple of 3+2, so 2,5,8,11,14 are destroyer gems

This approach makes it easy to ensure that gems of each type can only match with their own types. i.e. a destroyer gem with value 2 can only match with other gems of values 0,1 or 2.

For this we can just divide all values by 3 to check if the gems are the same since 0/3==1/3==2/3 for integers.

Gem Explosions:

When a special gem is detected in a combination, it destroys all gems immediately adjacent to it, if another special gem or destroyer gem was adjacent then another explosion is triggered at its coordinates.

When a destroyer gem is detected in a combination, it destroys all gems in its own row and column, if another special gem or destroyer gem was in its row and column then another explosion is triggered at its coordinates.

Score:

The user is given +60 score for every single tile that is eliminated from the board, this includes tiles that are automatically generated during the beginning of the game.
