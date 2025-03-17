# C++ BlackJack Dealer
 
 > Authors: \<[Justin Tran](https://github.com/azntin), [Axel Guerra](https://github.com/aguer155), [Santiago Avila](https://github.com/Savil049), [Divya Vegiraju](https://github.com/dvegiraju)\>

## Project Description
Feeling bored and bold at the same time, but have no money to spend? Look no further with the C++ BlackJack Dealer! Our project is not only intriguing, but is unique to us because it's a different approach in creating a C++ developed game that differs from your average text-based adventures and rudimentary games like tic-tac-toe. We plan to develop the back-end and logic of this dealer such as dealing card and having their own card count. We will also include all the logic and rules needed for the player to successfully play the game and have a winnings/loss counter. The user will be able to input all necessary actions and features that a normal BlackJack game should have: standing, hitting, and doubling down, as well as having our own digital currency system in which the player can freely use depending on how they're feeling to amp up the excitement of the game. The output, or what the user should receive, is additonal digital currency should they win and as well as feedback in terms of tips and statistics.
## List of languages / tools:
* C++ (for back-end, logic, and random assignment)

## User Interface Specification
### Navigation Diagram
Our game will prompt the user to enter a desired username everytime they start the game. Subsequently, they will enter into the game where they'll be placed at the table and play out their hands, where the user has the choice to hit, stand, or double down as they please on the table. From the table, the user should be able to view their earnings/wallet alongside tips which will automatically be displayed upon every win/loss. From the table the user has the ability to quit the game whenever they feel like it. Upon losing or winning, the user will be prompted with their respective screen and should have the choice to replay another hand or quit entirely.
>
> ![image](https://github.com/user-attachments/assets/1108394b-27ca-4a11-a578-20e2ecfb606f)




### Screen Layouts

> <img width="406" alt="Screenshot 2025-02-10 at 5 27 26 PM" src="https://github.com/user-attachments/assets/c5bd9844-ffbb-4aa0-aa79-28166e048f8c" />

>
  * Displays the ‘Blackjack Game’ title
  * Any key on the keyboard can be pressed on to continue

<img width="312" alt="Screenshot 2025-02-10 at 5 28 09 PM" src="https://github.com/user-attachments/assets/7f6793e1-65bb-40d8-89c6-dd41c9f18388" />

>
  * Displays “Enter username: “ 
  * Player will be able to type in their username as their user input
  * Display "Hello 'username', best of luck!"
  * Prompt player to Game Commence screen

<img width="323" alt="Screenshot 2025-02-10 at 5 28 16 PM" src="https://github.com/user-attachments/assets/7eadff8a-942e-4480-8ab0-b5b4fbb960b4" />

> 
  * Display “Starting game round”
  * Display “Enter betting amount”
  * In this order, give a dealers card, players card, dealers card and then again a players card
  * Display the corresponding cards to the players hand
  * Only display the first dealer's card and keep the other card hidden
  * Prompt user to table/hand screen

<img width="319" alt="Screenshot 2025-02-10 at 5 28 23 PM" src="https://github.com/user-attachments/assets/21effcdd-8cac-4b21-be26-2064920780f4" />

>
  * Displays Dealers hand in top row (5-C, 6-S, 10-H 1-D)
  * Displays Players hand in bottom row (5-C, 6-S, 10-H 1-D)
  * Players turn
  * Prompt a question to hit, stand, or double down

<img width="320" alt="Screenshot 2025-02-10 at 5 28 29 PM" src="https://github.com/user-attachments/assets/2af8c1f2-65cd-4171-ae90-77ff392eeb77" />

>
  * If player hits and hand is under 21 display new card on the players card row
  * If player hits and hand is over 21 prompt loss screen

<img width="167" alt="Screenshot 2025-02-10 at 5 31 12 PM" src="https://github.com/user-attachments/assets/13e7331d-4716-4284-9061-2476c210568d" />

>
  * If player stands display “Dealers turn” in bottom row
    
<img width="222" alt="Screenshot 2025-02-10 at 5 28 48 PM" src="https://github.com/user-attachments/assets/28d8d960-1a38-488b-8a6f-fb62b2131448" />

>
  * If player selects double down, their bet is doubled and they receive one more card, display that new card
<img width="262" alt="Screenshot 2025-02-10 at 5 28 54 PM" src="https://github.com/user-attachments/assets/abe2b028-11d3-4de2-949f-8fbe89293878" />

>
  * Display "Dealer Won..."
  * Display “Better luck next time!"
  * Display “Do you want to play another round?”
  * If y prompt user to game commence screen
  * If n quit program 

<img width="288" alt="Screenshot 2025-02-10 at 5 28 59 PM" src="https://github.com/user-attachments/assets/a2e590ae-6bc0-4bdc-a082-c0ffaa7671f5" />

>
  * Display “Congrats you won!!”
  * Display “Total earnings: XXX”
  * Player will be able to see how much money they have won
  * Display “Do you want to play another round?(y/n)”
  * If y prompt user to game commence screen
  * If n quit program 

## Class Diagram

 Our BlackJack game consists of five main classes: Game, Player, Dealer, Deck and Card. The Game class, acting like a central controller, is where every class will be able to interact to successfully simulate a simple game of Blackjack. The Player class is the one responsible for giving the user options such as hit, stand, double down, etc. Seeing as our dealer will also have very similar functionality, it will inherit from our Player class. Of course, a game of BlackJack would be unplayable without a deck of cards, therefore, our Deck class, that consists of a vector of Card objects, will be used by our Game class to hand/deal cards to our player and dealer.
>
![image](https://github.com/user-attachments/assets/148bcded-c976-484c-aee9-5071fca4cfbe)

>
## Single Responsibility
We've removed many functions from the player class regarding the points/monetary system. The player class should and will only have functions related to the gameplay, while the points management system will be external from the player in their classes: one for the bankroll management and betting system respectively. We've also added a HandEvaluator class to diminish the load of the Game class itself to ensure the class only handles the logic of the game (i.e., handling turns, ending rounds, etc.).
>
## Open/Closed Principles
Much of these new classes are what allow us modularity and flexibility in our code. This can be seen in our RealPlayer class, where we've extended the functionality of what the player can do, and can extend their functionality as we please without altering the gameplay. This can be seen in our Betting system as well, where we can play around with funds much more leniently and potentially add additional functions like "splitting" without having to modify the original bankroll code.
>
## Liskov Substitution
Classes like RealPlayer and Dealer, though sharing much similarity in function, can stand alone from the player class without altering the overall functionality of the program. This can also be seen with the Card and Deck class of our program. These classes being able to stand alone, though derived, improve our code by instilling habits that reduce redundancies and dependencies, promoting adaptability.
>
## Interface Segregation
Interfaces such as the Bankroll, Betting, Dealer, Deck, and even Card are all fairly small and rudimentary in function. This is due to our practice in reducing redundant code and relying on inherited classes to define functions exclusive to them, further simplifying our classes and cleaning our code.
>
## Dependency Inversion
Certain modules that contain a high complexity and a large number of functions (Player class) are abstracted to reduce dependencies in their child classes. The overriding of certain functions in RealPlayer and Dealer class, not only increases the potential of further improvements and advancement within our code, but also makes it less reliant on the parent class, which, if required to change, does not have a strong impact on the inherited classes' individual practicality. 
 
 ## Screenshots
> <img width="622" alt="Screenshot 2025-03-14 at 1 46 53 PM" src="https://github.com/user-attachments/assets/f10c91c1-195b-4c51-919a-6103207ba3ee" /> 
>
 *Display title screen and prompt for users name
>
> <img width="571" alt="Screenshot 2025-03-14 at 1 47 13 PM" src="https://github.com/user-attachments/assets/13b883d6-6e68-4535-a0a1-be10089b1a24" />
>
 *After name input a balance of 1000 is added to the users account; prompt for users betting amount
>
> <img width="521" alt="Screenshot 2025-03-14 at 1 47 34 PM" src="https://github.com/user-attachments/assets/c1759f78-e35f-4658-aa96-3803c6a7d5ac" />
>
 *After betting input, display dealt cards and prompt input of game actions
>
> <img width="494" alt="Screenshot 2025-03-14 at 1 47 54 PM" src="https://github.com/user-attachments/assets/50a49532-de5d-43b1-8408-d809cd8e4a65" />
>
 *After game action input game mechanics are run 
>
> <img width="555" alt="Screenshot 2025-03-14 at 1 48 09 PM" src="https://github.com/user-attachments/assets/e120b1a1-c954-4cf8-ae53-32b92998b2ac" />
>
 *Player busted
>
> <img width="478" alt="Screenshot 2025-03-14 at 1 48 34 PM" src="https://github.com/user-attachments/assets/86af729d-2879-440e-b02e-509e482c49b2" />
>
 *Prompts user if they want to play again 
>
> <img width="502" alt="Screenshot 2025-03-14 at 1 48 41 PM" src="https://github.com/user-attachments/assets/43a13593-42f8-4231-86a5-bdf80241fc6c" />
>
 *Ending game 
>
><img width="693" alt="Screenshot 2025-03-14 at 3 44 33 PM" src="https://github.com/user-attachments/assets/7724e7b5-9235-457f-b9f9-ba3321bc677e" />
>
 *Zero memory leaks
 
 ## Installation/Usage
 1. Clone this repository:
>  
     git clone <repository-url>
     cd <repository-directory>
 >
 2. Build the executable using CMake and Make
>  
     cmake .
     make
>
 (Note: Ensure you have cmake installed on your terminal; reference https://cmake.org/download/ [1, 2, 3, 5] for more help)
 
 3. Run the executable
>     
    ./bin/playGame
>     
 ## Testing
 Our project was rigorously tested using Google Test (gtest) to ensure the reliability and correctness of core components, including Card, Deck, Dealer, and RealPlayer. The unit tests validate key functionalities such as object creation, card dealing, deck shuffling, and player actions like hitting, standing, and betting. The Card class tests cover constructors, getter functions, and proper string output formatting for different card types. The Deck class tests confirm correct initialization, deck size maintenance, and card distribution logic. The Dealer and RealPlayer tests ensure accurate hand value calculations, blackjack detection, bust scenarios, and balance management. These automated tests help maintain code integrity and prevent regressions. If a Continuous Integration (CI) pipeline is set up, the test suite runs automatically on each commit, ensuring stability before deployment.
 
