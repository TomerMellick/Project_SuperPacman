 1.     Project - SUPERPACMAN
 2.Written By: Tomer Mellick , Hod Vaknin
 Login:       tomermel     , hodva
 ID:          315399956    , 211441027
 
 3.. Description: this is a SUPERPACMAN game with level editor and scoreboard

 4.
	main- the main file from which the program runs

	GameEditor - see readme ex4 -- INCLUDES --- SubWindow - Grid\Tools SubWindow - MainWindow - StaticWindow - Button - 
	GameMenu - the object that handles the main menu 
	MenuButton - an object that describes the buttons in the menu 
	ScoreBoard - a singleton class that handles the reading and writing and displaying of the scoreboard 
	Score - a struct that is used by ScoreBoard 

	Board - adds the playtime data on top of Map
	CharMatrix - used by Board, Game, Map to describe A map state
	Map - holds all the properties of the current level 
	Charecter - Base class for all the moving object in-game 
	Ghost - inherits from Charecter describe the ghosts in-game
	Pacman - inherits from Charecter and describes the Pacman in-game 
	Result  - a struct used by Game and Round to hold the results of the game
	Game - the main class that handles all the game sub-procedures 
	Round - the current round of the Game
	SubWindowData - struct that holds the dimensions of the data in Round 
	 

	
	 
	
	
	

5. 	
	Data structures  - vectors - used for various purposes
			- hash-map - create a hash map that assign hashable object to an object
                                                        used to assign the char that was eaten to the correct  function, sound, and score
			- tuple - generic class that contains X  values with deferents types, used instead of creating exactly the same struct (not generic)


6. 
	Algorithems- BFS - used to find the best route for the ghosts to hunt the pacman 

7. 	Design - 
		 the GameMenu  has all the options you can use before the actual game using MenuButtons
 	
		by pressing a button 		
		game - play all the levels in files 
		scoreboard  - shows the top 10 scores 
		help - shows the help screen 
		editor  - allows you to edit a level and add it to the level list 
		
		Game -init a Round for each level is based on EX2 as its backend engine and SFML to render it to screen it uses inheritance and polymorphism to handle all the objects 
		the animation is smoothed and rendered based on the clock and movement speed  
		
		 
		
		


8.    	
	Known Bugs  -
	       
	       not all types of special gifts are available in the editor 


9.   	non 
	


 		
	  
	