package game;
public abstract class Player {
	protected char c;

	/**
	 * initializes char member.
	 * @param ch
	 */
	public Player(char ch) {
		this.c = ch;
	}

	/**
	 * @return char of player.
	 */
	public char getChar() {
		return this.c;
	}

	/**
	 * the functions makes a move given in parameters x,y or read from user.
	 * @param game , game play
	 * @param x , x coordinate of move
	 * @param y , y coordinate of move
	 * @return true if a legal move was played, false otherwise.
	 */
	public abstract boolean playOneTurn(GamePlay game,int x, int y);

	/**
	 * the function makes the move (i,j) in the game.
	 * @param i , x coordinate of move
	 * @param j , y coordinate of move
	 * @param game
	 */
	public void makeMove(int i , int j , GamePlay game) {
		game.move(this , i , j);
	}
}