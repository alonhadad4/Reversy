package game;
public abstract class BoardDisplayer {
	protected Board b;
	public BoardDisplayer(Board boa) {
		this.b = boa;
	}

	public abstract void displayBoard(Board b);
}