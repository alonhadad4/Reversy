package game;
public abstract class BoardDisplayer {
	protected Board b;
	/**
	 * initializes board member.
	 * @param boa
	 */
	public BoardDisplayer(Board boa) {
		this.b = boa;
	}

	/**
	 * function displays board b.
	 * @param b
	 */
	public abstract void displayBoard(Board b);
}