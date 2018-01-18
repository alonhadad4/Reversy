public abstract class Player {
	protected char c;

	public Player(char ch) {
		this.c = ch;
	}

	public char getChar() {
		return this.c;
	}

	public abstract boolean playOneTurn(GamePlay game);

	public void makeMove(int i , int j , GamePlay game) {
		game.move(this , i , j);
	}
}