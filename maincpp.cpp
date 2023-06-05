
#include"Initial_pos.h"
#include"Ai.h"
void firstboard();
void intro();
void setwind();
void creditpage();
void blackwind();

bool board1= true, board2=false, board3=false;
bool player_wants_toplay = false;
bool playfriend=false, creditbool=false, exitbut = false, quit=false,settingsmenu= false;
bool blackwon = false, whitewon = false;
sf::Sound wrong;
sf::Sound Checks;
sf::Sound startmenu;
sf::Sound checkmate;
sf::Sound move;
sf::Sound check;
int main()
{
    //all the sounds needed will be defined globally
    // Check sound
    sf::SoundBuffer kish;
    kish.loadFromFile("Sound\\Check.mp3");
    Checks.setBuffer(kish);

    // wrong move sound
    sf::SoundBuffer wrongmove;
    wrongmove.loadFromFile("Sound\\Wrong move.mp3");
    wrong.setBuffer(wrongmove);
    //intro sound
    sf::SoundBuffer intso;
    intso.loadFromFile("Sound\\intro.wav");
    startmenu.setBuffer(intso);
    //checkmate sound
    sf::SoundBuffer mate;
    mate.loadFromFile("Sound\\check-mate.mp3");
    checkmate.setBuffer(mate);
    //moves
    sf::SoundBuffer moving;
    moving.loadFromFile("Sound\\Move.mp3");
    move.setBuffer(moving);
    ///////////////////////////////////////////
    while (!player_wants_toplay) {
        intro();
        if (playfriend) {
            break;
        }
        if (creditbool) {
            creditbool = false;
            creditpage();
        }
        if (settingsmenu) {
            settingsmenu = false;
            setwind();
        }
        if (exitbut) {
            return 0;
        }
        if (quit) {
            return 0;
        }


    }
    startmenu.play();
    firstboard();

    if (blackwon) {
        blackwind();
        std::cout << "black won";
    }
    else if(whitewon) {
        blackwind();
        std::cout << "white won";
    }
    
    return 0;
}
void firstboard() {
    sf::Vector2u v1(800, 800);
    sf::RenderWindow window(sf::VideoMode(v1), "Chess");
    //THE Board
    sf::Texture board;
    sf::Sprite x;
    if (board1) {
        board.loadFromFile("Images\\Chess-board.png");

    }
    else if (board2) {
        board.loadFromFile("Images\\black-white.png");
        sf::Vector2f sc(0.67, 0.67);
        x.setScale(sc);
    }
    else {
        board.loadFromFile("Images\\Brown.png");
        sf::Vector2f sc(0.67, 0.67);
        x.setScale(sc);
    }
    
    x.setTexture(board);
    window.draw(x);

    //BLACK PIECES

    //Black bishop1 && bishop2
    sf::Texture B_Bishop;
    B_Bishop.loadFromFile("Images\\b_bishop.png");
    sf::Sprite black_bishop1;
    sf::Sprite black_bishop2;
    black_bishop1.setTexture(B_Bishop);
    black_bishop1.setPosition(b_bishop1_pos);
    black_bishop1.setScale(piece_scale);
    black_bishop2.setTexture(B_Bishop);
    black_bishop2.setPosition(b_bishop2_pos);
    black_bishop2.setScale(piece_scale);
    window.draw(black_bishop1);
    window.draw(black_bishop2);


    //Black rook1 && rook2
    sf::Texture B_Rook;
    B_Rook.loadFromFile("Images\\b_rook.png");
    sf::Sprite black_rook1;
    sf::Sprite black_rook2;
    black_rook1.setTexture(B_Rook);
    black_rook1.setPosition(b_rook1_pos);
    black_rook1.setScale(piece_scale);
    black_rook2.setTexture(B_Rook);
    black_rook2.setPosition(b_rook2_pos);
    black_rook2.setScale(piece_scale);
    window.draw(black_rook1);
    window.draw(black_rook2);

    //Black knight1 && knight2
    sf::Texture B_Knight;
    B_Knight.loadFromFile("Images\\b_knight.png");
    sf::Sprite black_knight1;
    sf::Sprite black_knight2;
    black_knight1.setTexture(B_Knight);
    black_knight1.setPosition(b_knight1_pos);
    black_knight1.setScale(piece_scale);
    black_knight2.setTexture(B_Knight);
    black_knight2.setPosition(b_knight2_pos);
    black_knight2.setScale(piece_scale);
    window.draw(black_knight1);
    window.draw(black_knight2);

    //Black queen
    sf::Texture B_Queen;
    B_Queen.loadFromFile("Images\\b_queen.png");
    sf::Sprite black_queen;
    black_queen.setTexture(B_Queen);
    black_queen.setPosition(b_queen_pos);
    black_queen.setScale(piece_scale);
    window.draw(black_queen);

    //Black king
    sf::Texture B_King;
    B_King.loadFromFile("Images\\b_king.png");
    sf::Sprite black_king;
    black_king.setTexture(B_King);
    black_king.setPosition(b_king_pos);
    black_king.setScale(piece_scale);
    window.draw(black_king);

    //Black pawns
    sf::Texture B_Pawn;
    B_Pawn.loadFromFile("Images\\b_pawn.png");
    sf::Sprite black_pawn1;
    black_pawn1.setTexture(B_Pawn);
    black_pawn1.setPosition(b_pawn1_pos);
    black_pawn1.setScale(piece_scale);
    sf::Sprite black_pawn2;
    black_pawn2.setTexture(B_Pawn);
    black_pawn2.setPosition(b_pawn2_pos);
    black_pawn2.setScale(piece_scale);
    sf::Sprite black_pawn3;
    black_pawn3.setTexture(B_Pawn);
    black_pawn3.setPosition(b_pawn3_pos);
    black_pawn3.setScale(piece_scale);
    sf::Sprite black_pawn4;
    black_pawn4.setTexture(B_Pawn);
    black_pawn4.setPosition(b_pawn4_pos);
    black_pawn4.setScale(piece_scale);
    sf::Sprite black_pawn5;
    black_pawn5.setTexture(B_Pawn);
    black_pawn5.setPosition(b_pawn5_pos);
    black_pawn5.setScale(piece_scale);
    sf::Sprite black_pawn6;
    black_pawn6.setTexture(B_Pawn);
    black_pawn6.setPosition(b_pawn6_pos);
    black_pawn6.setScale(piece_scale);
    sf::Sprite black_pawn7;
    black_pawn7.setTexture(B_Pawn);
    black_pawn7.setPosition(b_pawn7_pos);
    black_pawn7.setScale(piece_scale);
    sf::Sprite black_pawn8;
    black_pawn8.setTexture(B_Pawn);
    black_pawn8.setPosition(b_pawn8_pos);
    black_pawn8.setScale(piece_scale);
    window.draw(black_pawn1);
    window.draw(black_pawn2);
    window.draw(black_pawn3);
    window.draw(black_pawn4);
    window.draw(black_pawn5);
    window.draw(black_pawn6);
    window.draw(black_pawn7);
    window.draw(black_pawn8);

    //WHITE PIECES

    //Black bishop1 && bishop2
    sf::Texture W_Bishop;
    W_Bishop.loadFromFile("Images\\w_bishop.png");
    sf::Sprite white_bishop1;
    sf::Sprite white_bishop2;
    white_bishop1.setTexture(W_Bishop);
    white_bishop1.setPosition(w_bishop1_pos);
    white_bishop1.setScale(piece_scale);
    white_bishop2.setTexture(W_Bishop);
    white_bishop2.setPosition(w_bishop2_pos);
    white_bishop2.setScale(piece_scale);
    window.draw(white_bishop1);
    window.draw(white_bishop2);


    //Black rook1 && rook2
    sf::Texture W_Rook;
    W_Rook.loadFromFile("Images\\w_rook.png");
    sf::Sprite white_rook1;
    sf::Sprite white_rook2;
    white_rook1.setTexture(W_Rook);
    white_rook1.setPosition(w_rook1_pos);
    white_rook1.setScale(piece_scale);
    white_rook2.setTexture(W_Rook);
    white_rook2.setPosition(w_rook2_pos);
    white_rook2.setScale(piece_scale);
    window.draw(white_rook1);
    window.draw(white_rook2);

    //Black knight1 && knight2
    sf::Texture W_Knight;
    W_Knight.loadFromFile("Images\\w_knight.png");
    sf::Sprite white_knight1;
    sf::Sprite white_knight2;
    white_knight1.setTexture(W_Knight);
    white_knight1.setPosition(w_knight1_pos);
    white_knight1.setScale(piece_scale);
    white_knight2.setTexture(W_Knight);
    white_knight2.setPosition(w_knight2_pos);
    white_knight2.setScale(piece_scale);
    window.draw(white_knight1);
    window.draw(white_knight2);

    //Black queen
    sf::Texture W_Queen;
    W_Queen.loadFromFile("Images\\w_queen.png");
    sf::Sprite white_queen;
    white_queen.setTexture(W_Queen);
    white_queen.setPosition(w_queen_pos);
    white_queen.setScale(piece_scale);
    window.draw(white_queen);

    //Black king
    sf::Texture W_King;
    W_King.loadFromFile("Images\\w_king.png");
    sf::Sprite white_king;
    white_king.setTexture(W_King);
    white_king.setPosition(w_king_pos);
    white_king.setScale(piece_scale);
    window.draw(white_king);

    //Black pawns
    sf::Texture W_Pawn;
    W_Pawn.loadFromFile("Images\\w_pawn.png");
    sf::Sprite white_pawn1;
    white_pawn1.setTexture(W_Pawn);
    white_pawn1.setPosition(w_pawn1_pos);
    white_pawn1.setScale(piece_scale);
    sf::Sprite white_pawn2;
    white_pawn2.setTexture(W_Pawn);
    white_pawn2.setPosition(w_pawn2_pos);
    white_pawn2.setScale(piece_scale);
    sf::Sprite white_pawn3;
    white_pawn3.setTexture(W_Pawn);
    white_pawn3.setPosition(w_pawn3_pos);
    white_pawn3.setScale(piece_scale);
    sf::Sprite white_pawn4;
    white_pawn4.setTexture(W_Pawn);
    white_pawn4.setPosition(w_pawn4_pos);
    white_pawn4.setScale(piece_scale);
    sf::Sprite white_pawn5;
    white_pawn5.setTexture(W_Pawn);
    white_pawn5.setPosition(w_pawn5_pos);
    white_pawn5.setScale(piece_scale);
    sf::Sprite white_pawn6;
    white_pawn6.setTexture(W_Pawn);
    white_pawn6.setPosition(w_pawn6_pos);
    white_pawn6.setScale(piece_scale);
    sf::Sprite white_pawn7;
    white_pawn7.setTexture(W_Pawn);
    white_pawn7.setPosition(w_pawn7_pos);
    white_pawn7.setScale(piece_scale);
    sf::Sprite white_pawn8;
    white_pawn8.setTexture(W_Pawn);
    white_pawn8.setPosition(w_pawn8_pos);
    white_pawn8.setScale(piece_scale);
    window.draw(white_pawn1);
    window.draw(white_pawn2);
    window.draw(white_pawn3);
    window.draw(white_pawn4);
    window.draw(white_pawn5);
    window.draw(white_pawn6);
    window.draw(white_pawn7);
    window.draw(white_pawn8);
    window.display();
    /*HERE we initialized the board with all the pieces in their initial position*/















    /*sf::Clock clock; // starts the clock
    sf::RenderWindow window(sf::VideoMode(v1), "Chess");

    sf::Time elapsed1 = clock.getElapsedTime();
    std::cout << elapsed1.asSeconds() << std::endl;
    clock.restart();
    sf::Time elapsed2 = clock.getElapsedTime();
    std::cout << elapsed2.asMilliseconds() << std::endl;*/













    bool isDragging = false;
    // Create a variable to store the sprite being dragged
    sf::Sprite* draggedSprite = nullptr;
    // Create a variable to store the position of the mouse when dragging starts
    sf::Vector2i dragStartMousePos;
    // Create a variable to store the position of the sprite when dragging starts
    sf::Vector2f dragStartSpritePos;
    sf::Sprite temppiece;
    sf::Vector2f temp;


    // Run the program as long as the window is open
    int count = 0;
    bool moved = false;
    while (window.isOpen())
    {
        sf::Vector2f test;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Check if the mouse is over a piece
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f sit(mousePos.x, mousePos.y);
                    for (auto& sprite : std::vector<sf::Sprite>{ white_pawn1,white_pawn2,white_pawn3,white_pawn4,white_pawn5,white_pawn6,white_pawn7,white_pawn8,white_rook1,white_rook2,white_bishop1,white_bishop2,white_knight1,white_knight2,white_queen,white_king,black_pawn1,black_pawn2,black_pawn3,black_pawn4,black_pawn5,black_pawn6,black_pawn7,black_pawn8,black_rook1,black_rook2,black_bishop1,black_bishop2,black_knight1,black_knight2,black_queen,black_king })
                    {
                        if (sprite.getGlobalBounds().contains(sit))
                        {
                            // Start dragging the piece
                            isDragging = true;
                            draggedSprite = &sprite;
                            temppiece = sprite;
                            dragStartMousePos = mousePos;
                            dragStartSpritePos = sprite.getPosition();
                            break;
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (isDragging)
                {
                    // Update the position of the dragged piece
                    sf::Vector2i finalpos= sf::Mouse::getPosition(window);
                    sf::Vector2f dest(finalpos.x, finalpos.y);
                    int x1=dragStartSpritePos.x, x2=finalpos.x, y1= dragStartSpritePos.y, y2=finalpos.y;
                    if (islegal(y1, x1, y2, x2)) {
                        move.play();
                        ///////////////////////////////////////////////////////////////
                        if (shortwhite) {
                            sf::Vector2f shor(505,705);
                            white_rook2.setPosition(shor);
                            shortwhite = false;
                        }
                        else if (longwhite) {
                            sf::Vector2f shor(305, 705);
                            white_rook1.setPosition(shor);
                            longwhite = false;
                        }
                        else if (shortblack) {
                            sf::Vector2f shor(505,5);
                            black_rook2.setPosition(shor);
                            shortblack = false;
                        }
                        else if (longblack) {
                            sf::Vector2f shor(305,5);
                            black_rook1.setPosition(shor);
                            longblack = false;
                        }
                        /// <summary>
                        /// /////////
                        /// </summary>
                        dest.x = x2 - (x2 % 100) + 5;
                        dest.y = y2 - (y2 % 100) + 5;
                        std::cout << "start pos x:" << dragStartSpritePos.x << "   start pos y:" << dragStartSpritePos.y;
                        std::cout << "\n";
                        temppiece.setPosition(dest);
                        std::cout << "end pos x:" <<dest.x << "   end pos y:" << dest.y;
                        std::cout << "\n";
                        temp = dest;
                        
                            switch (Board[y2 / 100][x2 / 100])
                            {
                            case 1:
                                white_pawn1.setPosition(dest);
                                break;
                            case 2:
                                white_pawn2.setPosition(dest);
                                break;
                            case 3:
                                white_pawn3.setPosition(dest);
                                break;
                            case 4:
                                white_pawn4.setPosition(dest);
                                break;
                            case 5:
                                white_pawn5.setPosition(dest);
                                break;
                            case 6:
                                white_pawn6.setPosition(dest);
                                break;
                            case 7:
                                white_pawn7.setPosition(dest);
                                break;
                            case 8:
                                white_pawn8.setPosition(dest);
                                break;
                            case 9:
                                white_rook1.setPosition(dest);
                                break;
                            case 10:
                                white_knight1.setPosition(dest);
                                break;
                            case 11:
                                white_bishop1.setPosition(dest);
                                break;
                            case 12:
                                white_king.setPosition(dest);
                                break;
                            case 13:
                                white_queen.setPosition(dest);
                                break;
                            case 14:
                                white_bishop2.setPosition(dest);
                                break;
                            case 15:
                                white_knight2.setPosition(dest);
                                break;
                            case 16:
                                white_rook2.setPosition(dest);
                                break;
                            case -1:
                                black_pawn1.setPosition(dest);
                                break;
                            case -2:
                                black_pawn2.setPosition(dest);
                                break;
                            case -3:
                                black_pawn3.setPosition(dest);
                                break;
                            case -4:
                                black_pawn4.setPosition(dest);
                                break;
                            case -5:
                                black_pawn5.setPosition(dest);
                                break;
                            case -6:
                                black_pawn6.setPosition(dest);
                                break;
                            case -7:
                                black_pawn7.setPosition(dest);
                                break;
                            case -8:
                                black_pawn8.setPosition(dest);
                                break;
                            case -9:
                                black_rook1.setPosition(dest);
                                break;
                            case -10:
                                black_knight1.setPosition(dest);
                                break;
                            case -11:
                                black_bishop1.setPosition(dest);
                                break;
                            case -12:
                                black_king.setPosition(dest);
                                break;
                            case -13:
                                black_queen.setPosition(dest);
                                break;
                            case -14:
                                black_bishop2.setPosition(dest);
                                break;
                            case -15:
                                black_knight2.setPosition(dest);
                                break;
                            case -16:
                                black_rook2.setPosition(dest);
                                break;
                            default:
                                break;
                            }
                            if (abs(Board[y2 / 100][x2 / 100]) / 100 != 0) {
                                if (Board[y2 / 100][x2 / 100] > 0) {
                                    int x = abs(Board[y2 / 100][x2 / 100])/100;
                                    int remain = abs(Board[y2 / 100][x2 / 100]) % 100;
                                    if (x == 1) {
                                        if (remain == 9) {
                                            white_pawn1.setTexture(W_Rook);
                                        }
                                        else if (remain == 10) {
                                            white_pawn1.setTexture(W_Knight);
                                        }
                                        else if (remain == 11) {
                                            white_pawn1.setTexture(W_Bishop);
                                        }
                                        else if (remain == 13) {
                                            white_pawn1.setTexture(W_Queen);
                                        }
                                        white_pawn1.setPosition(dest);
                                    }
                                    else if (x == 2) {
                                        if (remain == 9) {
                                            white_pawn2.setTexture(W_Rook);
                                        }
                                        else if (remain == 10) {
                                            white_pawn2.setTexture(W_Knight);
                                        }
                                        else if (remain == 11) {
                                            white_pawn2.setTexture(W_Bishop);
                                        }
                                        else if (remain == 13) {
                                            white_pawn2.setTexture(W_Queen);
                                        }
                                        white_pawn2.setPosition(dest);
                                    }
                                    else if (x == 3) {
                                        if (remain == 9) {
                                            white_pawn3.setTexture(W_Rook);
                                        }
                                        else if (remain == 10) {
                                            white_pawn3.setTexture(W_Knight);
                                        }
                                        else if (remain == 11) {
                                            white_pawn3.setTexture(W_Bishop);
                                        }
                                        else if (remain == 13) {
                                            white_pawn3.setTexture(W_Queen);
                                        }
                                        white_pawn3.setPosition(dest);
                                    }
                                    else if (x == 4) {
                                        if (remain == 9) {
                                            white_pawn4.setTexture(W_Rook);
                                        }
                                        else if (remain == 10) {
                                            white_pawn4.setTexture(W_Knight);
                                        }
                                        else if (remain == 11) {
                                            white_pawn4.setTexture(W_Bishop);
                                        }
                                        else if (remain == 13) {
                                            white_pawn4.setTexture(W_Queen);
                                        }
                                        white_pawn4.setPosition(dest);
                                    }
                                    else if (x == 5) {
                                        if (remain == 9) {
                                            white_pawn5.setTexture(W_Rook);
                                        }
                                        else if (remain == 10) {
                                            white_pawn5.setTexture(W_Knight);
                                        }
                                        else if (remain == 11) {
                                            white_pawn5.setTexture(W_Bishop);
                                        }
                                        else if (remain == 13) {
                                            white_pawn5.setTexture(W_Queen);
                                        }
                                        white_pawn5.setPosition(dest);
                                    }
                                    else if (x == 6) {
                                        if (remain == 9) {
                                            white_pawn6.setTexture(W_Rook);
                                        }
                                        else if (remain == 10) {
                                            white_pawn6.setTexture(W_Knight);
                                        }
                                        else if (remain == 11) {
                                            white_pawn6.setTexture(W_Bishop);
                                        }
                                        else if (remain == 13) {
                                            white_pawn6.setTexture(W_Queen);
                                        }
                                        white_pawn6.setPosition(dest);
                                    }
                                    else if (x == 7) {
                                        if (remain == 9) {
                                            white_pawn7.setTexture(W_Rook);
                                        }
                                        else if (remain == 10) {
                                            white_pawn7.setTexture(W_Knight);
                                        }
                                        else if (remain == 11) {
                                            white_pawn7.setTexture(W_Bishop);
                                        }
                                        else if (remain == 13) {
                                            white_pawn7.setTexture(W_Queen);
                                        }
                                        white_pawn7.setPosition(dest);
                                    }
                                    else if (x == 8) {
                                    if (remain == 9) {
                                        white_pawn8.setTexture(W_Rook);
                                    }
                                    else if (remain == 10) {
                                        white_pawn8.setTexture(W_Knight);
                                    }
                                    else if (remain == 11) {
                                        white_pawn8.setTexture(W_Bishop);
                                    }
                                    else if (remain == 13) {
                                        white_pawn8.setTexture(W_Queen);
                                    }
                                    white_pawn8.setPosition(dest);
                                    }
                                }
                                else {
                                int x = abs(Board[y2 / 100][x2 / 100]) / 100;
                                int remain = abs(Board[y2 / 100][x2 / 100]) % 100;
                                if (x == 1) {
                                    if (remain == 9) {
                                        black_pawn1.setTexture(B_Rook);
                                    }
                                    else if (remain == 10) {
                                        black_pawn1.setTexture(B_Knight);
                                    }
                                    else if (remain == 11) {
                                        black_pawn1.setTexture(B_Bishop);
                                    }
                                    else if (remain == 13) {
                                        black_pawn1.setTexture(B_Queen);
                                    }
                                    black_pawn1.setPosition(dest);
                                }
                                else if (x == 2) {
                                    if (remain == 9) {
                                        black_pawn2.setTexture(B_Rook);
                                    }
                                    else if (remain == 10) {
                                        black_pawn2.setTexture(B_Knight);
                                    }
                                    else if (remain == 11) {
                                        black_pawn2.setTexture(B_Bishop);
                                    }
                                    else if (remain == 13) {
                                        black_pawn2.setTexture(B_Queen);
                                    }
                                    black_pawn2.setPosition(dest);
                                }
                                else if (x == 3) {
                                    if (remain == 9) {
                                        black_pawn3.setTexture(B_Rook);
                                    }
                                    else if (remain == 10) {
                                        black_pawn3.setTexture(B_Knight);
                                    }
                                    else if (remain == 11) {
                                        black_pawn3.setTexture(B_Bishop);
                                    }
                                    else if (remain == 13) {
                                        black_pawn3.setTexture(B_Queen);
                                    }
                                    black_pawn3.setPosition(dest);
                                }
                                else if (x == 4) {
                                    if (remain == 9) {
                                        black_pawn4.setTexture(B_Rook);
                                    }
                                    else if (remain == 10) {
                                        black_pawn4.setTexture(B_Knight);
                                    }
                                    else if (remain == 11) {
                                        black_pawn4.setTexture(B_Bishop);
                                    }
                                    else if (remain == 13) {
                                        black_pawn4.setTexture(B_Queen);
                                    }
                                    black_pawn4.setPosition(dest);
                                }
                                else if (x == 5) {
                                    if (remain == 9) {
                                        black_pawn5.setTexture(B_Rook);
                                    }
                                    else if (remain == 10) {
                                        black_pawn5.setTexture(B_Knight);
                                    }
                                    else if (remain == 11) {
                                        black_pawn5.setTexture(B_Bishop);
                                    }
                                    else if (remain == 13) {
                                        black_pawn5.setTexture(B_Queen);
                                    }
                                    black_pawn5.setPosition(dest);
                                }
                                else if (x == 6) {
                                    if (remain == 9) {
                                        black_pawn6.setTexture(B_Rook);
                                    }
                                    else if (remain == 10) {
                                        black_pawn6.setTexture(B_Knight);
                                    }
                                    else if (remain == 11) {
                                        black_pawn6.setTexture(B_Bishop);
                                    }
                                    else if (remain == 13) {
                                        black_pawn6.setTexture(B_Queen);
                                    }
                                    black_pawn6.setPosition(dest);
                                }
                                else if (x == 7) {
                                    if (remain == 9) {
                                        black_pawn7.setTexture(B_Rook);
                                    }
                                    else if (remain == 10) {
                                        black_pawn7.setTexture(B_Knight);
                                    }
                                    else if (remain == 11) {
                                        black_pawn7.setTexture(B_Bishop);
                                    }
                                    else if (remain == 13) {
                                        black_pawn7.setTexture(B_Queen);
                                    }
                                    black_pawn7.setPosition(dest);
                                }
                                else if (x == 8) {
                                    if (remain == 9) {
                                        black_pawn8.setTexture(B_Rook);
                                    }
                                    else if (remain == 10) {
                                        black_pawn8.setTexture(B_Knight);
                                    }
                                    else if (remain == 11) {
                                        black_pawn8.setTexture(B_Bishop);
                                    }
                                    else if (remain == 13) {
                                        black_pawn8.setTexture(B_Queen);
                                    }
                                    black_pawn8.setPosition(dest);
                                }

                                }
                            }
                        
                        if (CheckMate()) {
                            if (whitetomove) {
                                blackwon = true;
                            }
                            else {
                                whitewon = true;
                            }
                        }
                        else if (KingInDanger()) {
                             Checks.play();
                        }
                        //if (blacktomove == true) {
                        //    blacktomove = false;
                        //    whitetomove = true;
                        //}
                        //else {
                        //    whitetomove = false;
                        //    blacktomove = true;
                        //}
                    }
                    else {
                    wrong.play();
                    }


                    isDragging = false;
                }
            }
            window.clear();
            window.draw(x);
            if (alive[1]) {
                window.draw(white_pawn1);
            }
            if (alive[2]) {
                window.draw(white_pawn2);
            }
            if (alive[3]) {
                window.draw(white_pawn3);
            }
            if (alive[4]) {
                window.draw(white_pawn4);
            }
            if (alive[5]) {
                window.draw(white_pawn5);
            }
            if (alive[6]) {
                window.draw(white_pawn6);
            }
            if (alive[7]) {
                window.draw(white_pawn7);
            }
            if (alive[8]) {
                window.draw(white_pawn8);
            }
            if (alive[9]) {
                window.draw(white_rook1);
            }
            if (alive[10]) {
                window.draw(white_knight1);
            }
            if (alive[11]) {
                window.draw(white_bishop1);
            }
            if (alive[13]) {
                window.draw(white_queen);
            }
            if (alive[14]) {
                window.draw(white_bishop2);
            }
            if (alive[15]) {
                window.draw(white_knight2);
            }
            if (alive[16]) {
                window.draw(white_rook2);
            }
            window.draw(white_king);

            if (alive[17]) {
                window.draw(black_pawn1);
            }
            if (alive[18]) {
                window.draw(black_pawn2);
            }
            if (alive[19]) {
                window.draw(black_pawn3);
            }
            if (alive[20]) {
                window.draw(black_pawn4);
            }
            if (alive[21]) {
                window.draw(black_pawn5);
            }
            if (alive[22]) {
                window.draw(black_pawn6);
            }
            if (alive[23]) {
                window.draw(black_pawn7);
            }
            if (alive[24]) {
                window.draw(black_pawn8);
            }
            if (alive[25]) {
                window.draw(black_rook1);
            }
            if (alive[26]) {
                window.draw(black_knight1);
            }
            if (alive[27]) {
                window.draw(black_bishop1);
            }
            if (alive[29]) {
                window.draw(black_queen);
            }
            if (alive[30]) {
                window.draw(black_bishop2);
            }
            if (alive[31]) {
                window.draw(black_knight2);
            }
            if (alive[32]) {
                window.draw(black_rook2);
            }
            window.draw(black_king);














            window.display();

        }
        if (blackwon || whitewon) {
            checkmate.play();
            sf::Time delayTime = sf::milliseconds(2000);
            sf::sleep(delayTime);
            break;
        }
    }
    return;
}
void intro() {
    //column 1
    sf::Sprite col1; 
    sf::Texture column1;
    column1.loadFromFile("images\\subbb\\Asset 13@2x.png");
    col1.setTexture(column1);
    //column 2
    sf::Sprite col2;
    sf::Texture column2;
    column2.loadFromFile("images\\Chess\\2x\\Asset 2@2x.png");
    col2.setTexture(column2);
    //background
    sf::Sprite background;
    sf::Texture back;
    back.loadFromFile("images\\subbb\\Asset 17@4x.png");
    background.setTexture(back);
    sf::Vector2f backpos(-1210, 0);
    background.setPosition(backpos);
    //title chess master
    sf::Sprite title;
    sf::Texture tit;
    tit.loadFromFile("images\\subbb\\title.png");
    title.setTexture(tit);
    //playfriend button
    sf::Sprite playfriend;
    sf::Texture friendd;
    friendd.loadFromFile("images\\Chess\\1x\\Asset 7.png");
    playfriend.setTexture(friendd);
    //playbot button
    sf::Sprite playbot;
    sf::Texture bot;
    bot.loadFromFile("images\\Chess\\1x\\Asset 8.png");
    playbot.setTexture(bot);
    //Credit Button
    sf::Sprite credit;
    sf::Texture cre;
    cre.loadFromFile("images\\Chess\\1x\\Asset 5.png");
    credit.setTexture(cre);
    //exit button
    sf::Sprite exit;
    sf::Texture exitt;
    exitt.loadFromFile("images\\Chess\\1x\\Asset 4.png");
    exit.setTexture(exitt);
    //settings button
    sf::Sprite settings;
    sf::Texture set;
    set.loadFromFile("images\\Chess\\1x\\Asset 6.png");
    settings.setTexture(set);
    ///////now we draw all that
    sf::Vector2u v1(800, 800);
    sf::RenderWindow window(sf::VideoMode(v1), "Menu");
    //background
    window.draw(background);
    //column 1&&2
    sf::Vector2f colm1(5, 50);
    col1.setPosition(colm1);
    window.draw(col1);

    sf::Vector2f colm2(540, 50);
    col2.setPosition(colm2);
    window.draw(col2);
    //Title
    sf::Vector2f titlepos(245, 50);
    title.setPosition(titlepos);
    window.draw(title);
    //Buttons
    sf::Vector2f friendpos(245, 150);
    playfriend.setPosition(friendpos);
    window.draw(playfriend);

    sf::Vector2f botpos(245, 250);
    playbot.setPosition(botpos);
    window.draw(playbot);

    sf::Vector2f creditpos(310, 420);
    credit.setPosition(creditpos);
    window.draw(credit);

    sf::Vector2f settingspos(310, 520);
    settings.setPosition(settingspos);
    window.draw(settings);

    sf::Vector2f exitpos(310, 620);
    exit.setPosition(exitpos);
    window.draw(exit);


    
















    window.display();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                quit = true;
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f sit(mousePos.x, mousePos.y);
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (playfriend.getGlobalBounds().contains(sit)) {
                        player_wants_toplay = true;
                        window.close();
                    }
                    else if (exit.getGlobalBounds().contains(sit)) {
                        exitbut = true;
                        window.close();
                    }
                    else if (settings.getGlobalBounds().contains(sit)) {
                        settingsmenu = true;
                        window.close();
                    }
                    else if (credit.getGlobalBounds().contains(sit)) {
                        creditbool = true;
                        window.close();
                    }
                }

            }



































            window.draw(background);
            window.draw(playfriend);
            window.draw(playbot);
            window.draw(credit);
            window.draw(settings);
            window.draw(exit);
            window.draw(col1);
            window.draw(col2);
            window.draw(title);
            window.display();
        }
    }
    

}
void setwind() {
    sf::Vector2u v1(800, 800);
    sf::RenderWindow window(sf::VideoMode(v1), "Settings");
    //background
    sf::Sprite backg;
    sf::Texture background;
    background.loadFromFile("images\\setback.png");
    backg.setTexture(background);
    window.draw(backg);
    //backbutton
    sf::Sprite back;
    sf::Texture backbut;
    sf::Vector2f butpos(20, 20);
    sf::Vector2f scaback(0.7, 0.7);
    backbut.loadFromFile("images\\unnamed.png");
    back.setScale(scaback);
    back.setTexture(backbut);
    back.setPosition(butpos);
    window.draw(back);
    //choose options
    sf::Sprite miniboards;
    sf::Texture minis;
    sf::Vector2f choosepos(80, 250);
    sf::Vector2f scachoose(0.5,0.5);
    minis.loadFromFile("images\\choose.png");
    miniboards.setTexture(minis);
    miniboards.setPosition(choosepos);
    miniboards.setScale(scachoose);
    window.draw(miniboards);
    //miniboards
    sf::Sprite miniboard1;
    sf::Texture mini1;
    sf::Vector2f b1pos(170, 310);
    sf::Vector2f scab1(0.14, 0.14);
    mini1.loadFromFile("images\\Chess-board.png");
    miniboard1.setTexture(mini1);
    miniboard1.setPosition(b1pos);
    miniboard1.setScale(scab1);
    window.draw(miniboard1);
    //mini2
    sf::Sprite miniboard2;
    sf::Texture mini2;
    sf::Vector2f b2pos(320, 310);
    sf::Vector2f scab2(0.095, 0.095);
    mini2.loadFromFile("images\\black-white.png");
    miniboard2.setTexture(mini2);
    miniboard2.setPosition(b2pos);
    miniboard2.setScale(scab2);
    window.draw(miniboard2);
    //mini3
    sf::Sprite miniboard3;
    sf::Texture mini3;
    sf::Vector2f b3pos(470, 310);
    sf::Vector2f scab3(0.095, 0.095);
    mini3.loadFromFile("images\\Brown.png");
    miniboard3.setTexture(mini3);
    miniboard3.setPosition(b3pos);
    miniboard3.setScale(scab3);
    window.draw(miniboard3);













    
    
    window.display();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                quit = true;
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f sit(mousePos.x, mousePos.y);
                    if (back.getGlobalBounds().contains(sit)) {
                        window.close();
                    }
                    else if (miniboard1.getGlobalBounds().contains(sit)) {
                        board1 = true; board2 = false; board3 = false;
                    }
                    else if (miniboard2.getGlobalBounds().contains(sit)) {
                        board1 = false; board2 = true; board3 = false;    
                    }
                    else if (miniboard3.getGlobalBounds().contains(sit)) {
                        board1 = false; board2 = false; board3 = true;  
                    }
                }
            }
        }
    }
    return;

}
void creditpage() {
    sf::Vector2u v1(800, 800);
    sf::RenderWindow window(sf::VideoMode(v1), "Credit");
    //background
    sf::Sprite backg;
    sf::Texture background;
    background.loadFromFile("images\\setback.png");
    backg.setTexture(background);
    window.draw(backg);
    //backbutton
    sf::Sprite back;
    sf::Texture backbut;
    sf::Vector2f butpos(20, 20);
    sf::Vector2f scaback(0.7, 0.7);
    backbut.loadFromFile("images\\unnamed.png");
    back.setScale(scaback);
    back.setTexture(backbut);
    back.setPosition(butpos);
    window.draw(back);
    //Data
    sf::Sprite miniboards;
    sf::Texture minis;
    sf::Vector2f choosepos(120, 280);
    sf::Vector2f scachoose(1, 1);
    minis.loadFromFile("images\\credit.png");
    miniboards.setTexture(minis);
    miniboards.setPosition(choosepos);
    miniboards.setScale(scachoose);
    window.draw(miniboards);


    window.display();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                quit = true;
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f sit(mousePos.x, mousePos.y);
                    if (back.getGlobalBounds().contains(sit)) {
                        window.close();
                    }
                }
            }
        }
    }
    return;

}
void blackwind() {
    sf::Vector2u v1(800, 800);
    sf::RenderWindow window(sf::VideoMode(v1), "Credit");
    //background
    sf::Sprite backg;
    sf::Texture background;
    background.loadFromFile("images\\setback.png");
    backg.setTexture(background);
    window.draw(backg);
    //backbutton
    sf::Sprite back;
    sf::Texture backbut;
    sf::Vector2f butpos(20, 20);
    sf::Vector2f scaback(0.7, 0.7);
    backbut.loadFromFile("images\\unnamed.png");
    back.setScale(scaback);
    back.setTexture(backbut);
    back.setPosition(butpos);
    window.draw(back);
    //Data
    sf::Sprite miniboards;
    sf::Texture minis;
    sf::Vector2f choosepos(120, 280);
    sf::Vector2f scachoose(1.2, 1.2);
    if (blackwon) {
        minis.loadFromFile("images\\Bwin.png");
    }
    else {
        minis.loadFromFile("images\\Wwin.png");
    }
    miniboards.setTexture(minis);
    miniboards.setPosition(choosepos);
    miniboards.setScale(scachoose);
    window.draw(miniboards);


    window.display();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                quit = true;
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f sit(mousePos.x, mousePos.y);
                    if (back.getGlobalBounds().contains(sit)) {
                        window.close();
                    }
                }
            }
        }
    }
    return;

}