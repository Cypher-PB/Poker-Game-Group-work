// poker game build to meet academic requirements 
/*
* Question statement 
*You have been asked to design a simple gambling system for your local casino. Due to the lack of funds you are expected to design a Console application.

SECTION A
For the card gambling system to work , you application needs the ability to display cards.
In this section build a program that receives two inputs from he user-- the card number and the card type-- and displayed the card on your console. This display may look like fig 1 below

  
Fig 1

SECTION B
Thanks to your colleague’s success you have a fully functional card display system . Now using your friends system designed above you are expected to expand the system to accommodate a minimum of a single player and a maximum of 4 players.
Each player should be given 3 cards each including the PC(NPC or your computer).
Your program should track which player receives which card .
The card given to each player should be displayed on screen except the PC(NPC or your computer) cards.

SECTION C
If all went well you now have a system that can share and displayed the cards shared to the user.
Now using your group mates code from above implement the combinations in poker to determine a winner .
This system matches each individuals card with the PC to create combination. This combinations determine the winner . more details can be found online or check link
 ( https://youtu.be/cNaUXwu4MzQ?si=iDB9Y_HbkQ0ZsWRa )

SECTION D
with this you have developed a fully working poker system, now a casino can’t run with one card game now can it ?
In this section you are expected to use at least two of your friends code from above to develop or implement a card game of your design or that already exist.


* 

*/

/**
*  ██▓███   ▒█████   ██ ▄█▀▓█████  ██▀███       ▄████  ▄▄▄       ███▄ ▄███▓▓█████  ██▀███
* ▓██░  ██▒▒██▒  ██▒ ██▄█▒ ▓█   ▀ ▓██ ▒ ██▒    ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀ ▓██ ▒ ██▒
* ▓██░ ██▓▒▒██░  ██▒▓███▄░ ▒███   ▓██ ░▄█ ▒   ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███   ▓██ ░▄█ ▒
* ▒██▄█▓▒ ▒▒██   ██░▓██ █▄ ▒▓█  ▄ ▒██▀▀█▄     ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄ ▒██▀▀█▄
* ▒██▒ ░  ░░ ████▓▒░▒██▒ █▄░▒████▒░██▓ ▒██▒   ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒░██▓ ▒██▒
* ▒▓▒░ ░  ░░ ▒░▒░▒░ ▒ ▒▒ ▓▒░░ ▒░ ░░ ▒▓ ░▒▓░    ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░░ ▒▓ ░▒▓░
* ░▒ ░       ░ ▒ ▒░ ░ ░▒ ▒░ ░ ░  ░  ░▒ ░ ▒░     ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░  ░▒ ░ ▒░
* ░░       ░ ░ ░ ▒  ░ ░░ ░    ░     ░░   ░    ░ ░   ░   ░   ▒   ░      ░      ░     ░░   ░
*              ░ ░  ░  ░      ░  ░   ░              ░       ░  ░       ░      ░  ░   ░
*
* 
                                                 .
                                      .          .
            .                .


                                                    .                            .
                                              .. .
                                              ..
     .                                                           .

                                                          .

                                                                                      .      .
                                                                                      .
                                                                               .
                                          ...........
                                  .  .,,:;;;i;iiiiii;ii;;:,........         ..
                  ..                .,;itt111iii11i1fftft11iii1iiiiiii;,
                                    .;tttttt111ii111t1i111111111tt1ttffti.
             .                     .,iiii11ttt1ii1ii;;;;;ii1t11i1t11ffttf1,..      .
                                .,:ift11ttttt1111t11iiii;;:;i1t1;;;i;1ffttt:.                      .
                              .:1LCGCCCCCLLLfftfttttt111tiii11it1iii;111tttfi,.              ..
                             .:1tC00GCCCLCCCCGCCCGCLft11f111111tti;i111iit1i11;,..
                          .  ,;i;i1fC080GCLLfffCGGCCft1tffLfCLftt11ti;ii;it111t1i:,.
                            .:::::;i1tLG0GLLfffLftCCCGCCLLLLGGftttfft11iii1iLCCfft::,
               .            .,::,::;1ii1t1i1L00fi;11itLCGGGCLLtttttttt1iiiitLCLffLL;:.
                           ..,,,,,,:;ii1i;;;:tt1t;i1tffLLLfLCCCCCffCLffftt1tttffttfi,.
            .               ...,,,,,;11i;::::11fiii1tffLLLL11LCCCGG00GLLLLLtt1tLf11;.      .
                         .    ....,;11i;:,:,i1tti1;,i1tLC0fifCti111fLCCLLLff111tf1;.
                                 ,;1i;:,,,,,;tttff:,;;1tCt;0Li;tLfii1fLLLCCLLttt1:.
                                ,:ii;,.....,,1i1tf,,:,,1titf;i08L1;;iLttfLCCGCf;..         .
                               .:t1:.     ...i1;;1,,,,,i1t;,;tLfi;;;1t1tLCCC0LL:,.
                .            .,:tt,        ..:t:;t;..,iLf1;iii;;ii;;i;it08@@0Lt,.
                             ::11.           .1;,1i;;1CGCtii;::;i;:;;;it1iLCf;..
                             ,i1.            .11.:i;if0GC1;,.,:;i::;:;;;:;iti,
                    .      ,;i1;.       .....;L1iitfL0GC1;:::,:i;,,,,:::,;1t;.
                    ..  ..;LL1i,     .,:;i111Lt1LLfLLffi;;::,,i:,...,,,,,:11:        .
                   .;111tfCCt;.   .,:;ii;;iiittft1t1i1i;;;:,,;:.........,:;;,
                   ,fLftt1;,.    ,iii;;;::;i11t:;f;,;i1L1:,,::..       ..,,,.
                   ;t;..       ,;i;::::,..,:itt,t:.,,;;fti;;,.          ....
                  .i:       .,;i;,..      :i1t:1: ,;itfLti:.     .
                  ::.  .,:;;i11:.       .itti:i;.,itftft;,.
                 ,;,. .;11t11;,.      .,1ff;:1;.,:;,.,;f:.
                 .::..iLffi,.         .;LCf;1: ,,,,..,ft..
                  ,::;LL1:            .;L0t::..,,::;;;i,     .
                  .,:1t:.             .::i1,;;,,:;ii;,. .
                 .,,;1,              . .,,;, . .:;;,.   .
                ,;;i;;,   ...,.         ..::.   .:,                                              . .
               .:;:,:::,. .::;:.           ..    ,,.
             ..;;,  ,:i1,  ,:i;,                 ,:.                   .  .
              .,.    .,i:  .,;;:.                ..                    .     .
                        .   .;i,.                                            .
                             .;.
                  .                                                         .              .
                                         .          .
                                                                             .


                                                                 .
   ..
                                        .
                                                                                      .
                              .                                 .

                    .                                          .                 .
                                                                                  .


Text Colour:


* 
* 
* 
* 
*  ██▓███  ▓█████  ██▀███   ██▀███ ▓██   ██▓    ▄▄▄▄    ██▀███   ██▓  ▄████  ██░ ██ ▄▄▄█████▓
* ▓██░  ██▒▓█   ▀ ▓██ ▒ ██▒▓██ ▒ ██▒▒██  ██▒   ▓█████▄ ▓██ ▒ ██▒▓██▒ ██▒ ▀█▒▓██░ ██▒▓  ██▒ ▓▒
* ▓██░ ██▓▒▒███   ▓██ ░▄█ ▒▓██ ░▄█ ▒ ▒██ ██░   ▒██▒ ▄██▓██ ░▄█ ▒▒██▒▒██░▄▄▄░▒██▀▀██░▒ ▓██░ ▒░
* ▒██▄█▓▒ ▒▒▓█  ▄ ▒██▀▀█▄  ▒██▀▀█▄   ░ ▐██▓░   ▒██░█▀  ▒██▀▀█▄  ░██░░▓█  ██▓░▓█ ░██ ░ ▓██▓ ░
* ▒██▒ ░  ░░▒████▒░██▓ ▒██▒░██▓ ▒██▒ ░ ██▒▓░   ░▓█  ▀█▓░██▓ ▒██▒░██░░▒▓███▀▒░▓█▒░██▓  ▒██▒ ░
* ▒▓▒░ ░  ░░░ ▒░ ░░ ▒▓ ░▒▓░░ ▒▓ ░▒▓░  ██▒▒▒    ░▒▓███▀▒░ ▒▓ ░▒▓░░▓   ░▒   ▒  ▒ ░░▒░▒  ▒ ░░
* ░▒ ░      ░ ░  ░  ░▒ ░ ▒░  ░▒ ░ ▒░▓██ ░▒░    ▒░▒   ░   ░▒ ░ ▒░ ▒ ░  ░   ░  ▒ ░▒░ ░    ░
* ░░          ░     ░░   ░   ░░   ░ ▒ ▒ ░░      ░    ░   ░░   ░  ▒ ░░ ░   ░  ░  ░░ ░  ░
*             ░  ░   ░        ░     ░ ░         ░         ░      ░        ░  ░  ░  ░
*                                   ░ ░              ░
*/
// section A
// include necesary libraries
#include "Game.h"
#include <map>
#include <iostream>

int main() {
    std::map<std::string, int> highScores;
    int npcLevel = 1;

    loadHighScores(highScores);
    loadGameState(highScores, npcLevel);

    while (true) {
        displayMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayHowToPlay();
            break;
        case 2:
            playGame(highScores, npcLevel);
            break;
        case 3:
            displayHighScores(highScores);
            break;
        case 4:
            std::cout << "Saving game state and exiting..." << std::endl;
            saveGameState(highScores, npcLevel);
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
