#RoadRace

## CpS 209 Project Proposal
By Zach Palmer, Jonathan Pridgeon, and Jacob Brazeal

### High Concept

This game is a race to build a road from the edge of a map (the playing field) to the center. To overcome the varied terrain of the map and the underhanded skullduggery of opponents, the players must harvest commodities from the side of their road and use them to build or buy bridges, walls, guns, and other useful tools. At higher levels of the game, players may use fleets of dragons to assault other roads and will face increasing challenges from the game itself, including the spontaneous spawning of wild animals and fierce tornadoes and earthquakes. Details

### Game Field

The game playing field is a grid of squares. Each square has a specific terrain (e.g., river, cliff, forrest, plain, etc.) and may contain resources like wood, gold, or horses. At higher levels, squares may also randomly spawn dangers like floods and forest fires. Each square is either unowned or owned by the player who has built a road through it. Ownership of squares may change. Each player starts owning a square in one of the four corners of the grid, from which the main road would be built. The goal is to reach the center square first.

### Gameplay

There are no turns. Players race to build roads and collect necessary resources. In some cases detours and side roads will be necessary to reach vital resources. If a player’s road is cut off from the base (either by a natural disaster or the assault of another player), the detached road is assigned to the next player to connect it to his own. Certain squares generate commodities at set intervals (e.g., forests yield wood which can ultimately be used to construct bridges). Players can launch assaults by purchasing dragons and unleashing them on other corners of the world (although results can be unpredictable.)

### Levels

Difficulty is primarily determined by the difficulty of the terrain. We will pre-design up to 5 levels of difficulty and in subsequent levels let the server auto-generate a grid of squares.

### Scoring

The score for the game is the time, milliseconds, required to win. We will maintain a local list of personal high scores in 1, 2, 3, and 4- person mode at each level of the game, as well as a list on the server of high scores at each level for 2, 3, and 4-person mode.

### Features

*C Version*

-Different levels of difficulty in initial configuration of world

-Record Best Times

-Help Screen

-Runs on the VM

-User Manipulates World

-Cheat Mode

*B Version*

-Multiplayer networking (up to 4 players)

-Hazard squares

-Game Save/Load

*A Version*

-Cross Platform compatibility (Linux/Mac/Windows)

-Animation and sounds

-Server auto-generates events in grid (user reacts to game)

*Bonus:*

-Randomly generated initial configuration of world.

-Ability to assault other players’ roads with dragons.
