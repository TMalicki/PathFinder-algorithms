# PathFinder-algorithms

**Description**
This program shows working algorithms (for now: Breadth First Search, Greedy, A*). It allows to create board inside editor mode, and than run any of available algorithms. Console window shows what algorithm will be executed and after it ends time is given.

**Instruction**
*color of nodes meaning*
- green - starting node
- red - finish node
- black - obstacle nodes
- violet - nodes in openList (not visited yet)
- gray - nodes in closedList (already visited)
- blue - best path

**Control**
- left mouse button - for add node on board (respectively - *finish node*, *start node*, obstacles nodes*), hold it while putting obstacle nodes for possibility of "drawing" on board (multi selection mode)
- right mouse button - for delete any node
- scroll mouse button - for choosing between algorithms
- E key - for return to edit mode after executed algorithm
- enter - to run algorithm

**Functionalities**:
- 2D editor for pathfinder
- breadth first search algorithm
- greedy algorithm 
- A* algorithm - possibility that it's not working well with diagonal movement (fCost not updated for closedVector Tile)

**ToDo**
- *compare* algorithms options with two algorithms working in the same time

**ToFix**
- optimize code
- display changes

  <p float="left">
  <img src="images/Greedy 1.png" alt="Image" width="300"/></div>
  <img src="images/BFS 1.png" alt="Image" width="300"/> </div>
  <img src="images/A_star 1.png" alt="Image" width="300"/></div>
  </p>
  <br>
  <br>
  <p float="left">
  <img src="images/Greedy 2.png" alt="Image" width="300"/>  </div>
  <img src="images/BFS 2.png" alt="Image" width="300"/>  </div>
  <img src="images/A_star 2.png" alt="Image" width="300"/>  </div>
  </p>
