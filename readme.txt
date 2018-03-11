This is the water jug puzzle solver. Given 3 jugs capacities and the goal jugs states it will print the most efficient path to reach the end goal
The water jug puzzle goes like this:

You have three jugs
                    C
           B     |      |
  A     |     |  |      |
|    |  |     |  |      |
|____|  |_____|  |______|

Lets say, for this example Jug A has capacity 3 gallons, Jug B has capacity 5 gallons, and Jug C has capacity 8 gallons.

At the start of every puzzle, the jugs A and B are empty and jug C is full, so it has 8 gallons of water.
                    C
           B     |~~~~~~|
  A     |     |  |~~~~~~|
|    |  |     |  |~~~~~~|
|____|  |_____|  |______|

The most well known challenge is to pour water from jug to jug to get to
Jug A has 0 gallons, Jug B has 4 gallons, and Jug C has 4 gallons.

                   C
           B     |      |
  A     |     |  |      |
|    |  |~~~~~|  |~~~~~~|
|____|  |_____|  |______|

The rules are:
1. When you pour water from jug to jug you must pour ALL POSSIBLE water
	ex. State 0 0 8 pouring from C to A will result in 3 0 5
2. To start any puzzle, the start state is 0 0 (Capacity of Jug C)
3. The sum of all goal jugs must equal the capacity of Jug C




How to run this program!
	-I have provided the compiled file so running this is relatively simple

The Usage is defined as:

	Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>

Note: It is important to remember that the program is designed to handle any size jugs and any goal

From the command line (LINUX IS THE BEST WAY):
Step 1: Navagate to the "jug" file
Step 2: run the command
		./waterjugpuzzle 3 5 8 0 4 4
	Note: This is the basic example, you can use any size jugs (the first three inputs) and any goal (the second three inputs). Just remember the goal MUST equal the size of Jug C
Step 3: Run more interesting examples, try it out see what you get!

From Windows:
Step 1: Open Command Prompt
Step 2: Navigate to the file
Step 3:



How the program works!
